
// Std
#include <sstream>

// Application
#include "CRemoteControl.h"

//-------------------------------------------------------------------------------------------------
// Logging macros

#define LOG_DEBUG(a)
// #define LOG_DEBUG(a) echo(QString("(%1) DEBUG : %2\n").arg(m_sSelfIP).arg(a))

#define LOG_ERROR(a) echo(QString("(%1) ERROR : %2\n").arg(m_sSelfIP).arg(a))

#define LOG_INFO(a) echo(QString("(%1) INFO : %2\n").arg(m_sSelfIP).arg(a))

//-------------------------------------------------------------------------------------------------

#define PROP_SOCKET     "Socket"
#define PROP_DATA       "Data"
#define CONF_FILE       "rmc.conf.xml"
#define SOCKET_NAME(a)  (a->peerAddress().toString() + ":" + QString::number(a->peerPort()))

//-------------------------------------------------------------------------------------------------
// Static properties

const int CRemoteControl::s_iDefaultPort = 8419;
const int CRemoteControl::s_iDefaultTimeout = 3000;
const int CRemoteControl::s_iDefaultMaxWaitingTime = 5000;

//-------------------------------------------------------------------------------------------------

CConnectionData::CConnectionData(CRemoteControlUser* pUser, bool bIsServer)
    : m_pUser(pUser)
    , m_sWorkingDirectory(QDir::currentPath())
    , m_tContext(bIsServer)
{
}

//-------------------------------------------------------------------------------------------------

CConnectionData::~CConnectionData()
{
}

//-------------------------------------------------------------------------------------------------
// Server constructor

CRemoteControl::CRemoteControl(int iPort, bool bROKE)
    : m_Timer(this)
    , m_pClient(nullptr)
    , m_sIP("0.0.0.0")
    , m_sSelfIP("0.0.0.0")
    , m_sRMC("RMC: ")
    , m_eEncryption(RMC_ENCRYPTION_NONE)
    , m_bConnectedToServer(false)
    , m_bDoShell(false)
    , m_iConnectTimeoutMS(3000)
    , m_iMaxWaitingTimeMS(0)
    , m_iTransactionResult(0)
{
    LOG_DEBUG(QString("CRemoteControl::CRemoteControl(%1)").arg(iPort));

    if (bROKE)
    {
        LOG_DEBUG(QString("... using ROKE encryption"));
        m_eEncryption = RMC_ENCRYPTION_ROKE;
    }

    // Security
    readConfiguration();
    initSecurity();
    initUsers();

    // Events
    connect(&m_Timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(this, SIGNAL(newConnection()), this, SLOT(onServerConnection()));

    // Startup socket listener
    if (listen(QHostAddress::Any, quint16(iPort)))
    {
        setMaxPendingConnections(10);

        LOG_INFO(QString("Listening to %1:%2").arg(m_sIP).arg(serverPort()));
    }
    else
    {
        LOG_ERROR(errorString());
    }

    // Get own IP address
    QList<QHostAddress> sList = QNetworkInterface::allAddresses();
    if (sList.count() > 0)
        m_sSelfIP = sList[0].toString();

    // Start the timer that deals with commands and transfers
    m_Timer.start(5);
}

//-------------------------------------------------------------------------------------------------
// Client constructor

CRemoteControl::CRemoteControl(const QString& sIP, int iPort, int iConnectTimeoutMS, int iMaxWaitingTimeMS, bool bDoShell)
    : m_Timer(this)
    , m_pClient(nullptr)
    , m_sIP(sIP)
    , m_sSelfIP("0.0.0.0")
    , m_sRMC("RMC: ")
    , m_eEncryption(RMC_ENCRYPTION_UNDEF)
    , m_bConnectedToServer(false)
    , m_bDoShell(bDoShell)
    , m_iConnectTimeoutMS(iConnectTimeoutMS)
    , m_iMaxWaitingTimeMS(iMaxWaitingTimeMS)
    , m_iTransactionResult(0)
{
    LOG_DEBUG(QString("CRemoteControl::CRemoteControl(%1, %2)").arg(sIP).arg(iPort));

    // Security
    readConfiguration();
    initSecurity();
    initUsers(true);

    // Create connection to server
    m_pClient = new QTcpSocket(this);
    newConnectionData(m_pClient, false);

    // Events
    connect(&m_Timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(m_pClient, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    connect(m_pClient, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    connect(m_pClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));

    // Connect to server
    m_pClient->connectToHost(sIP, quint16(iPort));

    LOG_DEBUG(QString("CRemoteControl::CRemoteControl() : waitForConnected(%1)").arg(m_iConnectTimeoutMS));

    if (m_pClient->waitForConnected(m_iConnectTimeoutMS))
    {
        m_bConnectedToServer = true;
    }
    else
    {
        QString sError = QString("Unable to connect to %1.\n").arg(sIP);

        LOG_ERROR(sError);
    }

    // Get own IP address
    QList<QHostAddress> sList = QNetworkInterface::allAddresses();
    if (sList.count() > 0)
        m_sSelfIP = sList[0].toString();

    // Start the timer that deals with commands and transfers
    m_Timer.start(5);

    // If we are in shell mode, ask for the current directory
    if (m_bDoShell && m_bConnectedToServer)
    {
        sendRequest(m_pClient, RMC_REQUEST_PWD, "");
    }
}

//-------------------------------------------------------------------------------------------------

CRemoteControl::~CRemoteControl()
{
    if (m_pClient != nullptr)
    {
        if (m_bConnectedToServer)
        {
            m_pClient->flush();
        }

        discardConnectionData(m_pClient);
        m_pClient->deleteLater();
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::readConfiguration()
{
    m_tConfiguration = CXMLNode::loadXMLFromFile(CONF_FILE);
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::initSecurity()
{
    CXMLNode tFilesNode = m_tConfiguration.getNodeByTagName("Files");

    QVector<CXMLNode> vFiles = tFilesNode.getNodesByTagName("ProhibitedFile");

    for (CXMLNode tFile : vFiles)
    {
        QString sPath = tFile.attributes()["path"];

        LOG_DEBUG(QString("Access to %1 is prohibited").arg(sPath));

        m_vProhibitedFiles << sPath;
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::initUsers(bool bSilent)
{
    bool bGotGuestUser = false;

    CXMLNode tUsersNode = m_tConfiguration.getNodeByTagName("Users");

    QVector<CXMLNode> vUsers = tUsersNode.getNodesByTagName("User");

    for (CXMLNode tNode : vUsers)
    {
        QString sLogin = tNode.attributes()["login"];
        QString sPassword = tNode.attributes()["password"];
        QString sPrivileges = tNode.attributes()["privileges"];

        if (!bSilent)
            LOG_INFO(QString("Registered user : %1 (Privileges: %2)").arg(sLogin).arg(sPrivileges));

        m_vUsers.append(CRemoteControlUser(
                            sLogin,
                            sPassword,
                            sPrivileges.toInt()
                            ));

        if (sLogin == "guest")
            bGotGuestUser = true;
    }

    if (bGotGuestUser == false)
    {
        if (!bSilent)
            LOG_INFO(QString("Registered user : guest (Privileges: %2)").arg(EP_FileRead));

        // Add the guest user (default)
        m_vUsers.prepend(CRemoteControlUser("guest", "guest", EP_FileRead));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::setLoginPassword(QString sLogin, QString sPassword)
{
    LOG_DEBUG(QString("CRemoteControl::setLoginPassword(%1, %2)").arg(sLogin).arg(sPassword));

    if (m_bConnectedToServer)
    {
        if (!sLogin.isEmpty())
        {
            LOG_DEBUG(QString("CRemoteControl::setLoginPassword() : sendLogin"));

            sendLogin(m_pClient, sLogin, sPassword);
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::fillMessageHeader(pRMC_Header pHeader, ERMCMessage eMessage, quint32 ulLength)
{
    pHeader->ulType = eMessage;
    pHeader->ulLength = ulLength;
    pHeader->ulEncryption = RMC_ENCRYPTION_NONE;
    pHeader->ulChecksum = 0;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onNextCommand()
{
    if (m_bDoShell && m_bConnectedToServer)
    {
        // Print a prompt
        if (m_bDoShell) echo("\n" + m_sRMC + m_sRemotePwd + "\n" + m_sRMC + "==>");

        // Read a command from console
        QString sText = readCommand();

        if (sText != "")
        {
            if (sText == "?" || sText == "help")
            {
                echo("\n");
                echo("Available commands\n");
                echo("  cd   : change directory on remote host\n");
                echo("  quit : terminate session\n");
                echo("\n");

                QTimer::singleShot(10, this, SLOT(onNextCommand()));
            }
            else
                if (sText == "quit")
                {
                    emit transactionTerminated(0);
                }
                else if (sText.toLower().startsWith("cd"))
                {
                    QString sTargetDirectory = sText.remove("cd ").trimmed();

                    RMC_ChangeDirectory tChange;

                    fillMessageHeader(pRMC_Header(&tChange), RMC_CHANGE_DIRECTORY, sizeof(RMC_ChangeDirectory));

#ifdef WIN32
                    strcpy_s(tChange.cTargetDirectory, sizeof(tChange.cTargetDirectory), sTargetDirectory.toLatin1().data());
#else
                    strcpy(tChange.cTargetDirectory, sTargetDirectory.toLatin1().data());
#endif

                    sendMessage(m_pClient, pRMC_Header(&tChange));
                }
                else
                {
                    // Send an execute message to server
                    RMC_Execute tExec;

                    fillMessageHeader(pRMC_Header(&tExec), RMC_EXECUTE, sizeof(RMC_Execute));

                    tExec.bDetached = false;

#ifdef WIN32
                    strcpy_s(tExec.cText, sizeof(tExec.cText), sText.toLatin1().data());
#else
                    strcpy(tExec.cText, sText.toLatin1().data());
#endif
                    sendMessage(m_pClient, pRMC_Header(&tExec));
                }
        }
        else
        {
            // Call this method from idle in 10 ms
            QTimer::singleShot(10, this, SLOT(onNextCommand()));
        }
    }
}

//-------------------------------------------------------------------------------------------------

QString CRemoteControl::readCommand()
{
    LOG_DEBUG(QString("CRemoteControl::readCommand()"));

    QString sCommand;
    QTextStream stream(stdin);
    sCommand = stream.readLine();

    return sCommand;
}

//-------------------------------------------------------------------------------------------------

pRMC_Header CRemoteControl::encryptMessage(QTcpSocket* pSocket, pRMC_Header pMessage)
{
    LOG_DEBUG(QString("CRemoteControl::encryptMessage(%1, %2, %3)")
              .arg(pMessage->ulType)
              .arg(pMessage->ulLength)
              .arg(pMessage->ulEncryption)
              );

    if (
            m_eEncryption == RMC_ENCRYPTION_UNDEF ||
            m_eEncryption == RMC_ENCRYPTION_NONE ||
            pMessage->ulType == RMC_SECURE_CONTEXT
            )
    {
        LOG_DEBUG(QString("... returning message without encryption"));

        return pMessage;
    }

    CConnectionData* pData = getConnectionData(pSocket);

    if (pData != nullptr)
    {
        char* pBytes = reinterpret_cast<char*>(pMessage) + sizeof(RMC_Header);
        int iCount = int(pMessage->ulLength - sizeof(RMC_Header));

        QByteArray baData = QByteArray(pBytes, iCount);
        baData = pData->secureContext().encrypt(baData);

        memcpy(
                    pBytes,
                    baData.constData(),
                    size_t(iCount)
                    );

        pMessage->ulEncryption = RMC_ENCRYPTION_ROKE;
    }
    else
    {
        LOG_ERROR(QString("... no key to encrypt message"));
    }

    return pMessage;
}

//-------------------------------------------------------------------------------------------------

pRMC_Header CRemoteControl::decryptMessage(QTcpSocket* pSocket, pRMC_Header pMessage)
{
    LOG_DEBUG(QString("CRemoteControl::decryptMessage(%1, %2, %3)")
              .arg(pMessage->ulType)
              .arg(pMessage->ulLength)
              .arg(pMessage->ulEncryption)
              );

    if (pMessage->ulEncryption == RMC_ENCRYPTION_NONE)
    {
        LOG_DEBUG(QString("... returning message without encryption"));

        return pMessage;
    }

    CConnectionData* pData = getConnectionData(pSocket);

    if (pData != nullptr)
    {
        char* pBytes = reinterpret_cast<char*>(pMessage) + sizeof(RMC_Header);
        int iCount = int(pMessage->ulLength - sizeof(RMC_Header));

        QByteArray baData = QByteArray(pBytes, iCount);
        baData = pData->secureContext().decrypt(baData);

        memcpy(
                    pBytes,
                    baData.constData(),
                    size_t(iCount)
                    );

        pMessage->ulEncryption = RMC_ENCRYPTION_NONE;
    }
    else
    {
        LOG_ERROR(QString("... no key to decrypt message"));
    }

    return pMessage;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::readMessage(QTcpSocket* pSocket)
{
    if (m_vIncomingData.contains(pSocket) && m_vIncomingData[pSocket].count() >= int(sizeof(RMC_Header)))
    {
        LOG_DEBUG(QString("CRemoteControl::readMessage() : Socket has incoming data"));

        pRMC_Header pOriginalHeader = pRMC_Header(m_vIncomingData[pSocket].data());

        if (m_vIncomingData[pSocket].count() >= int(pOriginalHeader->ulLength))
        {
            pRMC_Header pDecryptedHeader = decryptMessage(pSocket, pOriginalHeader);

            LOG_DEBUG(QString("... pDecryptedHeader %1, %2, %3")
                      .arg(pDecryptedHeader->ulType)
                      .arg(pDecryptedHeader->ulLength)
                      .arg(pDecryptedHeader->ulEncryption)
                      );

            // Switch on message type and call appropriate handler

            switch (pDecryptedHeader->ulType)
            {
            case RMC_LOGIN:                 handleLogin             (pSocket, pDecryptedHeader); break;
            case RMC_SECURE_CONTEXT:        handleSecureContext     (pSocket, pDecryptedHeader); break;
            case RMC_EXECUTE:               handleExecute           (pSocket, pDecryptedHeader); break;
            case RMC_CHANGE_DIRECTORY:      handleChangeDirectory   (pSocket, pDecryptedHeader); break;
            case RMC_RESPONSE:              handleResponse          (pSocket, pDecryptedHeader); break;
            case RMC_EXECUTE_FINISHED:      handleExecuteFinished   (pSocket, pDecryptedHeader); break;
            case RMC_GET_FILE:              handleGetFile           (pSocket, pDecryptedHeader); break;
            case RMC_FILE_TRANSFER:         handleFileTransfer      (pSocket, pDecryptedHeader); break;
            case RMC_FILE_CHUNK:            handleFileChunk         (pSocket, pDecryptedHeader); break;
            case RMC_FILE_RECEIVED:         handleFileReceived      (pSocket, pDecryptedHeader); break;
            case RMC_FILE_INFO:             handleFileInfo          (pSocket, pDecryptedHeader); break;
            case RMC_PROGRAM_WORKING_DIR:   handleProgramWorkingDir (pSocket, pDecryptedHeader); break;
            case RMC_REQUEST:               handleRequest           (pSocket, pDecryptedHeader); break;
            case RMC_MERGE_FILE:            handleMergeFile         (pSocket, pDecryptedHeader); break;

            default:
                LOG_DEBUG(QString("... unknown message : %1").arg(pDecryptedHeader->ulType));
                break;
            }

            int bytesToRemove = int(pOriginalHeader->ulLength);

            LOG_DEBUG(QString("... remove %1 bytes from incoming data").arg(bytesToRemove));

            m_vIncomingData[pSocket].remove(0, bytesToRemove);

            return true;
        }

        return false;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

QVector<QString> CRemoteControl::getFileListFromSourceName(const QString& sSourceName)
{
    LOG_DEBUG(QString("CRemoteControl::getFileListFromSourceName(%1)").arg(sSourceName));

    // Create a list of file names
    QVector<QString> vFiles;

    // Do we have a wildcard character?
    if (sSourceName.contains('*'))
    {
        QFileInfo tFileInfo(sSourceName);
        QStringList sFilters;
        sFilters.append(tFileInfo.fileName());
        QDir tDirectory = tFileInfo.dir();

        LOG_DEBUG(QString("... listing files in %1")
                  .arg(tDirectory.path())
                  );

        // List all files matching the wildcard expression
        QStringList sFiles = tDirectory.entryList(sFilters);

        for (QString sFile : sFiles)
        {
            if (sFile != "." && sFile != "..")
            {
                vFiles.append(QString("%1/%2").arg(tDirectory.path()).arg(sFile));
            }
        }
    }
    else
    {
        vFiles.append(sSourceName);
    }

    return vFiles;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendCommand(const QString& sCommand, bool bDetached, bool bRightNow)
{
    if (m_pClient != nullptr)
    {
        if (bRightNow)
        {
            doSendCommand(sCommand, bDetached);
        }
        else
        {
            // Just add command to command list, sent later
            m_vCommands.append(CProcessInfo(sCommand, bDetached));
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::doSendCommand(const QString& sCommand, bool bDetached)
{
    // Send an execute message to server
    RMC_Execute tExec;

    fillMessageHeader(pRMC_Header(&tExec), RMC_EXECUTE, sizeof(RMC_Execute));

    tExec.bDetached = bDetached;

#ifdef WIN32
    strcpy_s(tExec.cText, sizeof(tExec.cText), sCommand.toLatin1().data());
#else
    strcpy(tExec.cText, sCommand.toLatin1().data());
#endif
    sendMessage(m_pClient, pRMC_Header(&tExec));
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::sendShutdown()
{
    LOG_DEBUG(QString("CRemoteControl::sendShutdown()"));

    // Are we in client mode?
    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        sendRequest(m_pClient, RMC_REQUEST_SHUTDOWN, "");
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::getRemoteFileCRC(const QString& sTargetName)
{
    LOG_DEBUG(QString("CRemoteControl::getRemoteFileCRC(%1)").arg(sTargetName));

    // Are we in client mode?
    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        // Create a new file transfer object
        CFileTransferData* pTransfer = new CFileTransferData(m_pClient, sTargetName, sTargetName, 0, false);

        pTransfer->setEchoFileCRC(true);

        // Add the file transfer object to list of transfers
        m_vFileTransfers.append(pTransfer);

        sendRequest(m_pClient, RMC_REQUEST_FILEINFO, sTargetName);
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::getRights()
{
    LOG_DEBUG(QString("CRemoteControl::getRights()"));

    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        LOG_DEBUG(QString("... sendRequest(RMC_REQUEST_GETRIGHTS)"));

        sendRequest(m_pClient, RMC_REQUEST_GETRIGHTS, "");
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::getFile(const QString& sSourceName, const QString& sTargetName, bool bKeepNewest, bool bCompCRC)
{
    Q_UNUSED(bKeepNewest);
    Q_UNUSED(bCompCRC);

    LOG_DEBUG(
                QString("CRemoteControl::getFile(%1, %2, %3, %4)")
                .arg(sSourceName)
                .arg(sTargetName)
                .arg(bKeepNewest)
                .arg(bCompCRC)
                );

    // Are we in client mode?
    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        // Send a get file message to server
        RMC_GetFile tGet;

        fillMessageHeader(pRMC_Header(&tGet), RMC_GET_FILE, sizeof(RMC_GetFile));

#ifdef WIN32
        strcpy_s(tGet.cSourceName, sizeof(tGet.cSourceName), sSourceName.toStdString().c_str());
        strcpy_s(tGet.cTargetName, sizeof(tGet.cTargetName), sTargetName.toStdString().c_str());
#else
        strcpy(tGet.cSourceName, sSourceName.toStdString().c_str());
        strcpy(tGet.cTargetName, sTargetName.toStdString().c_str());
#endif

        sendMessage(m_pClient, pRMC_Header(&tGet));

        echo(QString("GET %1 => %2.\n").arg(sSourceName).arg(sTargetName));
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::putFile(const QString& sSourceName, const QString& sTargetName, bool bKeepNewest, bool bCompCRC)
{
    Q_UNUSED(bKeepNewest);

    LOG_DEBUG(
                QString("CRemoteControl::putFile(%1, %2, %3, %4)")
                .arg(sSourceName)
                .arg(sTargetName)
                .arg(bKeepNewest)
                .arg(bCompCRC)
                );

    bool bIsWildCard = sSourceName.contains('*');

    // Are we in client mode?
    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        QVector<QString> vSourceFiles = getFileListFromSourceName(sSourceName);

        if (vSourceFiles.count() > 0)
        {
            // Loop through each file name
            for (QString sFullSourceName : vSourceFiles)
            {
                QFile tFile(sFullSourceName);

                // Does file exist?
                if (tFile.exists())
                {
                    QString sFullTargetName = sTargetName;

                    if (bIsWildCard)
                    {
                        QFileInfo tSourceInfo(sFullSourceName);
                        sFullTargetName = QString("%1/%2").arg(sTargetName).arg(tSourceInfo.fileName());
                    }

                    // Create a new file transfer object
                    CFileTransferData* pTransfer = new CFileTransferData(
                                m_pClient,
                                sFullSourceName,
                                sFullTargetName,
                                quint32(tFile.size()),
                                true
                                );

                    pTransfer->setSourceFileCRC(getFileCRC(tFile));
                    pTransfer->setCompCRC(bCompCRC);

                    LOG_DEBUG(
                                QString("CRemoteControl::putFile() : appending transfer ID %1, %2 => %3")
                                .arg(pTransfer->getTransferID())
                                .arg(sFullSourceName)
                                .arg(sFullTargetName)
                                );

                    // Add new file transfer object to list of transfers
                    m_vFileTransfers.append(pTransfer);

                    LOG_INFO(QString("PUT %1 => %2.").arg(sFullSourceName).arg(sFullTargetName));
                }
                else
                {
                    LOG_ERROR(QString("File not found : %1").arg(sFullSourceName));

                    return false;
                }
            }

            return true;
        }
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::mergeFile(const QString& sSourceName, const QString& sTargetName)
{
    LOG_DEBUG(
                QString("CRemoteControl::mergeFile(%1, %2)")
                .arg(sSourceName)
                .arg(sTargetName)
                );

    // Send a merge file message to server
    RMC_MergeFile tMerge;

    fillMessageHeader(pRMC_Header(&tMerge), RMC_MERGE_FILE, sizeof(RMC_MergeFile));

    tMerge.iType = RMC_MERGETYPE_INI;

#ifdef WIN32
    strcpy_s(tMerge.cSourceName, sizeof(tMerge.cSourceName), sSourceName.toStdString().c_str());
    strcpy_s(tMerge.cTargetName, sizeof(tMerge.cTargetName), sTargetName.toStdString().c_str());
#else
    strcpy(tMerge.cSourceName, sSourceName.toStdString().c_str());
    strcpy(tMerge.cTargetName, sTargetName.toStdString().c_str());
#endif

    sendMessage(m_pClient, pRMC_Header(&tMerge));

    echo(QString("MERGE %1 => %2.\n").arg(sSourceName).arg(sTargetName));

    return true;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::waitForResponse()
{
    if (m_pClient != nullptr)
    {
        // TODO
    }
}

//-------------------------------------------------------------------------------------------------

quint32 CRemoteControl::getFileCRC(QFile& tFile)
{
    quint32 ulCRC = 0;

    if (!tFile.isOpen())
    {
        tFile.open(QIODevice::ReadOnly);
    }

    if (tFile.isOpen())
    {
        while (!tFile.atEnd())
        {
            quint32 ulData;
            qint64 iSize = tFile.read(reinterpret_cast<char*>(&ulData), sizeof(quint32));

            if (iSize != sizeof(quint32)) break;

            ulCRC += ulData;
        }

        tFile.close();
    }

    return ulCRC;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendProcessOutput(QProcess* pProcess, bool bFinished, qint32 iExitCode)
{
    LOG_DEBUG(QString("CRemoteControl::sendProcessOutput(%1)").arg(bFinished));

    if (pProcess != nullptr)
    {
        QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(reinterpret_cast<QObject*>(pProcess->property(PROP_SOCKET).toULongLong()));

        if (pSocket != nullptr)
        {
            QByteArray tArray = pProcess->readAllStandardOutput();

            // Is there text on standard output?
            while (tArray.count() > 0)
            {
                qint32 iSize = tArray.count();
                if (iSize > MAX_DATA_SIZE - 1) iSize = MAX_DATA_SIZE - 1;

                // Send the text
                LOG_DEBUG(QString("CRemoteControl::sendProcessOutput() : sending %1 bytes").arg(iSize));

                RMC_Response tResponse;

                fillMessageHeader(pRMC_Header(&tResponse), RMC_RESPONSE, sizeof(RMC_Response));

                tResponse.ulDataSize = quint32(iSize);
                memset(tResponse.cData, 0, sizeof(tResponse.cData));
                memcpy(tResponse.cData, tArray.data(), quint32(iSize));

                sendMessage(pSocket, pRMC_Header(&tResponse));

                tArray.remove(0, iSize + 1);
            }

            if (bFinished)
            {
                LOG_DEBUG(QString("CRemoteControl::sendProcessOutput() : sending RMC_EXECUTE_FINISHED"));

                sendExecuteFinished(pSocket, 0, iExitCode);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::echo(QString sText)
{
    QTextStream stream(stdout);
    stream << sText;
    stream.flush();
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::sendMessage(QTcpSocket* pSocket, pRMC_Header pMessage)
{
    LOG_DEBUG(QString("CRemoteControl::sendMessage()"));

    if (pSocket->state() != QTcpSocket::ConnectedState)
    {
        LOG_DEBUG(QString("... pSocket->state() != QTcpSocket::ConnectedState, returning"));

        return false;
    }

    CConnectionData* pData = getConnectionData(pSocket);

    if (pData != nullptr)
    {
        LOG_DEBUG(QString("... Type and length : %1, %2")
                  .arg(pMessage->ulType)
                  .arg(pMessage->ulLength)
                  );

        pMessage = encryptMessage(pSocket, pMessage);

        LOG_DEBUG(QString("... sending message"));

        pSocket->write(reinterpret_cast<char*>(pMessage), pMessage->ulLength);
        pSocket->waitForBytesWritten();

        return true;
    }

    LOG_DEBUG(QString("No data found for socket, returning false"));

    return false;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendText(QTcpSocket* pSocket, const QString& sText)
{
    LOG_DEBUG(QString("CRemoteControl::sendText(%1)").arg(sText));

    char szBuffer [MAX_DATA_SIZE];

#ifdef WIN32
    strcpy_s(szBuffer, sizeof(szBuffer), sText.toStdString().c_str());
#else
    strcpy(szBuffer, sText.toStdString().c_str());
#endif

    if (strlen(szBuffer) < MAX_DATA_SIZE)
    {
        RMC_Response tResponse;

        fillMessageHeader(pRMC_Header(&tResponse), RMC_RESPONSE, sizeof(RMC_Response));

        tResponse.ulDataSize = quint32(strlen(szBuffer) + 1);
        tResponse.tHeader.ulLength = (sizeof(tResponse) - sizeof(tResponse.cData)) + tResponse.ulDataSize;

        memcpy(tResponse.cData, szBuffer, strlen(szBuffer) + 1);

        sendMessage(pSocket, pRMC_Header(&tResponse));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendLogin(QTcpSocket* pSocket, QString sLogin, QString sPassword)
{
    LOG_DEBUG(QString("CRemoteControl::sendLogin(%1, %2)").arg(sLogin).arg(sPassword));

    QString sEncPassword = CRemoteControlUser::encoded(sPassword);

    LOG_DEBUG(QString("... encoded password = %1").arg(sEncPassword));

    RMC_Login tLogin;

    fillMessageHeader(pRMC_Header(&tLogin), RMC_LOGIN, sizeof(RMC_Login));

#ifdef WIN32
    strcpy_s(tLogin.cLogin, sizeof(tLogin.cLogin), sLogin.toLatin1().constData());
    strcpy_s(tLogin.cPassword, sizeof(tLogin.cPassword), sEncPassword.toLatin1().constData());
#else
    strcpy(tLogin.cLogin, sLogin.toLatin1().constData());
    strcpy(tLogin.cPassword, sEncPassword.toLatin1().constData());
#endif

    sendMessage(pSocket, pRMC_Header(&tLogin));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendExecuteFinished(QTcpSocket* pSocket, qint32 iProcess, qint32 iErrorCode)
{
    LOG_DEBUG(QString("CRemoteControl::sendExecuteFinished(%1)").arg(SOCKET_NAME(pSocket)));

    RMC_ExecuteFinished tExecFinished;

    fillMessageHeader(pRMC_Header(&tExecFinished), RMC_EXECUTE_FINISHED, sizeof(RMC_ExecuteFinished));

    tExecFinished.iProcess = iProcess;
    tExecFinished.iErrorCode = iErrorCode;

    sendMessage(pSocket, pRMC_Header(&tExecFinished));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendFileReceived(QTcpSocket* pSocket, quint32 ulTransferID, qint32 iError, quint32 ulCRC)
{
    RMC_FileReceived tReceived;

    fillMessageHeader(pRMC_Header(&tReceived), RMC_FILE_RECEIVED, sizeof(RMC_FileReceived));

    tReceived.ulTransferID		= ulTransferID;
    tReceived.iError			= iError;
    tReceived.ulCRC				= ulCRC;

    sendMessage(pSocket, pRMC_Header(&tReceived));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendRequest(QTcpSocket* pSocket, qint32 lRequest, QString sParam)
{
    RMC_Request tRequest;

    fillMessageHeader(pRMC_Header(&tRequest), RMC_REQUEST, sizeof(RMC_Request));

    tRequest.lRequest = lRequest;

#ifdef WIN32
    strcpy_s(tRequest.ucParam, sizeof(tRequest.ucParam), sParam.toLatin1().data());
#else
    strcpy(tRequest.ucParam, sParam.toLatin1().data());
#endif

    sendMessage(pSocket, pRMC_Header(&tRequest));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendFileInfo(QTcpSocket* pSocket, QString sName, quint32 ulCRC)
{
    RMC_FileInfo tInfo;

    fillMessageHeader(pRMC_Header(&tInfo), RMC_FILE_INFO, sizeof(RMC_FileInfo));

    tInfo.ulCRC = ulCRC;

#ifdef WIN32
    strcpy_s(tInfo.cName, sizeof(tInfo.cName), sName.toLatin1().data());
#else
    strcpy(tInfo.cName, sName.toLatin1().data());
#endif

    sendMessage(pSocket, pRMC_Header(&tInfo));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendPwd(QTcpSocket* pSocket)
{
    CConnectionData* pData = getConnectionData(pSocket);

    RMC_ProgramWorkingDir tInfo;

    fillMessageHeader(pRMC_Header(&tInfo), RMC_PROGRAM_WORKING_DIR, sizeof(RMC_ProgramWorkingDir));

    QString sPath = pData->workingDirectory();

    LOG_DEBUG(QString("CRemoteControl::sendPwd() : path = %1").arg(sPath));

#ifdef WIN32
    strcpy_s(tInfo.cPath, sizeof(tInfo.cPath), sPath.toLatin1().data());
#else
    strcpy(tInfo.cPath, sPath.toLatin1().data());
#endif

    sendMessage(pSocket, pRMC_Header(&tInfo));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onTimer()
{
    m_Timer.stop();

    // Check each registered file transfer
    for (int Index = 0; Index < m_vFileTransfers.count(); Index++)
    {
        CFileTransferData* pTransfer = m_vFileTransfers[Index];

        // Is it an outgoing file transfer?
        if (pTransfer->getOut())
        {
            QTcpSocket* pSocket = pTransfer->getSocket();

            if (pSocket->isOpen())
            {
                bool bOKToProcess = true;

                // Do we have to compare CRCs?
                if (pTransfer->getCompCRC() == true)
                {
                    if (pTransfer->getGotFileInfo() == false)
                    {
                        bOKToProcess = false;

                        if (pTransfer->getFileInfoSent() == false)
                        {
                            pTransfer->setFileInfoSent(true);

                            LOG_DEBUG(QString("CRemoteControl::onTimer() : sending file info request for ID %1").arg(pTransfer->getTransferID()));

                            sendRequest(pSocket, RMC_REQUEST_FILEINFO, pTransfer->getTargetName());
                        }
                    }
                    else
                    {
                        if (pTransfer->getSourceFileCRC() == pTransfer->getTargetFileCRC())
                        {
                            LOG_DEBUG(QString("CRemoteControl::onTimer() : same CRC for %1, skipping").arg(pTransfer->getSourceName()));

                            echo(QString("CRC check : skipping %1\n").arg(pTransfer->getSourceName()));

                            pTransfer->setDone(true);
                            checkConnectionTransfers(pSocket);

                            m_Timer.start();
                            return;
                        }
                    }
                }

                if (pTransfer->getDone() == false && bOKToProcess)
                {
                    // Open file
                    QFile tFileToRead(pTransfer->getSourceName());

                    if (tFileToRead.open(QIODevice::ReadOnly))
                    {
                        // Send 20 chunks of data
                        for (qint32 Index = 0; Index < 20; Index++)
                        {
                            // Compute bytes to send
                            quint32 ulBytesToSend = MAX_DATA_SIZE;

                            if (ulBytesToSend > tFileToRead.size() - qint64(pTransfer->getOffsetInFile()))
                            {
                                ulBytesToSend = quint32(tFileToRead.size() - qint64(pTransfer->getOffsetInFile()));
                            }

                            if (ulBytesToSend > 0)
                            {
                                // Seek to current position in file
                                tFileToRead.seek(pTransfer->getOffsetInFile());

                                // Read data
                                QByteArray aBytes = tFileToRead.read(ulBytesToSend);

                                // Update current offset in file
                                pTransfer->setOffsetInFile(pTransfer->getOffsetInFile() + quint32(aBytes.count()));

                                // Send chunk to client
                                RMC_FileChunk tChunk;

                                fillMessageHeader(pRMC_Header(&tChunk), RMC_FILE_CHUNK, sizeof(RMC_FileChunk));

                                tChunk.ulTransferID     = pTransfer->getTransferID();
                                tChunk.ulOffsetInFile   = pTransfer->getOffsetInFile();
                                tChunk.ulFileSize       = pTransfer->getFileSize();
                                tChunk.ulCRC            = pTransfer->getSourceFileCRC();
                                tChunk.cIsLastChunk     = pTransfer->getOffsetInFile() >= tFileToRead.size();
                                tChunk.ulDataSize       = quint32(aBytes.count());

#ifdef WIN32
                                strcpy_s(tChunk.cSourceName, sizeof(tChunk.cSourceName), pTransfer->getSourceName().toLatin1().constData());
                                strcpy_s(tChunk.cTargetName, sizeof(tChunk.cTargetName), pTransfer->getTargetName().toLatin1().constData());
#else
                                strcpy(tChunk.cSourceName, pTransfer->getSourceName().toLatin1().constData());
                                strcpy(tChunk.cTargetName, pTransfer->getTargetName().toLatin1().constData());
#endif

                                memcpy(tChunk.cData, aBytes.data(), size_t(aBytes.count()));

                                LOG_DEBUG(
                                            QString("CRemoteControl::onTimer() : transfering chunk at offset %1 for transfer ID %2, size %3")
                                            .arg(pTransfer->getOffsetInFile())
                                            .arg(pTransfer->getTransferID())
                                            .arg(aBytes.count())
                                            );

                                sendMessage(pSocket, pRMC_Header(&tChunk));

                                // Remove transfer from list if chunk is the last one

                                if (tChunk.cIsLastChunk)
                                {
                                    pTransfer->setDone(true);
                                    checkConnectionTransfers(pSocket);

                                    // Close file
                                    tFileToRead.close();

                                    m_Timer.start();
                                    return;
                                }
                            }
                            else
                            {
                                LOG_DEBUG(QString("CRemoteControl::onTimer() : no data for transfer ID %1").arg(pTransfer->getTransferID()));

                                pTransfer->setDone(true);
                                checkConnectionTransfers(pSocket);

                                m_Timer.start();
                                return;
                            }
                        }

                        // Close file
                        tFileToRead.close();
                    }
                    else	// if (tFileToRead.open(QIODevice::ReadOnly))
                    {
                        LOG_ERROR(QString("CRemoteControl::onTimer() : could not open file %1").arg(pTransfer->getSourceName()));

                        sendText(pTransfer->getSocket(), QString(tr("Could not open file %1\n")).arg(pTransfer->getSourceName()));

                        pTransfer->setDone(true);
                        checkConnectionTransfers(pSocket);

                        m_Timer.start();
                        return;
                    }
                }
            }
            else	// if (pSocket->isOpen())
            {
                pTransfer->setDone(true);
                checkConnectionTransfers(pSocket);

                m_Timer.start();
                return;
            }
        }
        else // Incoming transfer
        {
            QTcpSocket* pSocket = pTransfer->getSocket();

            if (pSocket != nullptr)
            {
                if (m_iMaxWaitingTimeMS > 0)
                {
                    if (pTransfer->getLastIncomingMessageTime().msecsTo(QDateTime::currentDateTime()) > m_iMaxWaitingTimeMS)
                    {
                        LOG_DEBUG(QString("CRemoteControl::onTimer() : waiting time elapsed for transfer ID %1").arg(pTransfer->getTransferID()));

                        pTransfer->setDone(true);
                        checkConnectionTransfers(pSocket);

                        m_Timer.start();
                        return;
                    }
                }

                if (pSocket->isOpen())
                {
                    if (pTransfer->getEchoFileCRC())
                    {
                        if (pTransfer->getGotFileInfo() == true)
                        {
                            echo(QString("%1").arg(pTransfer->getTargetFileCRC()));

                            pTransfer->setDone(true);
                            checkConnectionTransfers(pSocket);

                            m_Timer.start();
                            return;
                        }
                    }
                }
                else
                {
                    pTransfer->setDone(true);
                    checkConnectionTransfers(pSocket);

                    m_Timer.start();
                    return;
                }
            }
        }
    }

    // Are we in client mode?
    if (m_pClient != nullptr && m_bConnectedToServer)
    {
        if (m_eEncryption != RMC_ENCRYPTION_UNDEF)
        {
            // Loop through one command
            // for (qint32 Index = 0; Index < m_vCommands.count(); Index++)
            qint32 Index = 0;
            if (m_vCommands.count() > 0)
            {
                LOG_DEBUG(QString("CRemoteControl::onTimer() : sending RMC_EXECUTE"));

                CProcessInfo tCommand = m_vCommands[Index];

                doSendCommand(tCommand.m_sCommand, tCommand.m_bDetached);

                m_vCommands.remove(Index);

                m_Timer.start();
                return;
            }
        }
    }

    // Read incoming messages for each socket
    for (QTcpSocket* pSocket : m_vSockets)
        while (readMessage(pSocket)) {}

    // Read incoming messages for the client socket if any
    if (m_pClient != nullptr)
        while (readMessage(m_pClient)) {}

    m_Timer.start();
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::checkConnectionTransfers(QTcpSocket* pSocket, bool bIsDisconnected)
{
    LOG_DEBUG(QString("CRemoteControl::checkConnectionTransfers() : cleaning transfers for %1").arg(SOCKET_NAME(pSocket)));

    // Check if transfers are done and if so, remove them
    for (int Index = 0; Index < m_vFileTransfers.count(); Index++)
    {
        CFileTransferData* pTransfer = m_vFileTransfers[Index];

        if (pTransfer->getDone() == true || (pTransfer->getSocket() == pSocket && bIsDisconnected))
        {
            LOG_DEBUG(QString("CRemoteControl::checkConnectionTransfers() : removing transfer ID %1").arg(pTransfer->getTransferID()));

            m_vFileTransfers.remove(m_vFileTransfers.indexOf(pTransfer));
            delete pTransfer;

            Index--;
        }
    }

    int iTransferForSocketCount = 0;

    for (int Index = 0; Index < m_vFileTransfers.count(); Index++)
    {
        CFileTransferData* pTransfer = m_vFileTransfers[Index];

        if (pTransfer->getSocket() == pSocket) iTransferForSocketCount++;
    }

    LOG_DEBUG(QString("CRemoteControl::checkConnectionTransfers() : remaining transfers : this socket %1, global %2")
              .arg(iTransferForSocketCount)
              .arg( m_vFileTransfers.count())
              );

    // If socket has no pending transfer, tell it we are done with execution
    if (iTransferForSocketCount == 0)
    {
        if (!bIsDisconnected) sendExecuteFinished(pSocket, 0, 0);
    }

    // If all transfers are done, emit the transactionTerminated signal
    if (m_vFileTransfers.count() == 0)
    {
        QTimer::singleShot(1000, this, SLOT(onDoEmitTransactionTerminated()));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onDoEmitTransactionTerminated()
{
    emit transactionTerminated(m_iTransactionResult);
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onServerConnection()
{
    LOG_DEBUG("CRemoteControl::onServerConnection()");

    // Get incoming socket and store it
    QTcpSocket* pSocket = nextPendingConnection();

    LOG_DEBUG(QString("CRemoteControl::onServerConnection() : adding socket %1").arg(SOCKET_NAME(pSocket)));

    newConnectionData(pSocket, true);

    // Add this socket to our socket list
    m_vSockets.append(pSocket);

    // Connect read and disconnect signals from the socket to this class' slots
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));

    // Send secure context
    sendSecureContext(pSocket);
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::sendSecureContext(QTcpSocket* pSocket)
{
    if (m_eEncryption == RMC_ENCRYPTION_ROKE)
    {
        CConnectionData* pData = getConnectionData(pSocket);

        if (pData != nullptr)
        {
            LOG_DEBUG("CRemoteControl::sendSecureContext()");

            RMC_Secure_Context tContext;

            fillMessageHeader(pRMC_Header(&tContext), RMC_SECURE_CONTEXT, sizeof(RMC_Secure_Context));

            QByteArray baData = pData->secureContext().contextData();

            memcpy(tContext.cData, baData.constData(), size_t(baData.count()));

            tContext.tHeader.ulLength = quint32((sizeof(tContext) - sizeof(tContext.cData)) + quint64(baData.count()));

            sendMessage(pSocket, pRMC_Header(&tContext));
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onSocketConnected()
{
    LOG_DEBUG("CRemoteControl::onSocketConnected()");

    m_bConnectedToServer = true;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onSocketDisconnected()
{
    LOG_DEBUG("CRemoteControl::onSocketDisconnected()");

    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    m_bConnectedToServer = false;

    // Check if any transfer is associated to this socket
    checkConnectionTransfers(pSocket, true);

    // Remove the socket from our socket list
    if (m_vSockets.contains(pSocket))
    {
        LOG_DEBUG(
                    QString("CRemoteControl::onSocketDisconnected() : removing socket %1")
                    .arg(SOCKET_NAME(pSocket))
                    );

        m_vSockets.removeAll(pSocket);
    }

    // Remove any incoming data associated to this socket
    if (m_vIncomingData.contains(pSocket))
    {
        LOG_DEBUG(
                    QString("CRemoteControl::onSocketDisconnected() : removing incoming data for %1")
                    .arg(SOCKET_NAME(pSocket))
                    );

        m_vIncomingData.remove(pSocket);
    }

    // Delete the socket
    pSocket->deleteLater();

    // Emit the transactionTerminated signal
    QTimer::singleShot(1000, this, SLOT(onDoEmitTransactionTerminated()));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onSocketReadyRead()
{
    LOG_DEBUG(QString("CRemoteControl::onSocketReadyRead()"));

    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    if (pSocket != nullptr)
    {
        LOG_DEBUG(QString("CRemoteControl::onSocketReadyRead() %1")
                  .arg(pSocket->peerAddress().toString()));

        if (pSocket->state() == QTcpSocket::ConnectedState)
        {
            LOG_DEBUG(QString("... state is QTcpSocket::ConnectedState"));

            // Add data to the buffer of this socket
            m_vIncomingData[pSocket].append(pSocket->read(pSocket->bytesAvailable()));
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleLogin(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    LOG_DEBUG("CRemoteControl::handleLogin()");

    pRMC_Login pLogin = pRMC_Login(pHeader);

    if (pLogin != nullptr)
    {
        LOG_DEBUG(QString("... Login, password = %1, %2")
                  .arg(QString(pLogin->cLogin))
                  .arg(QString(pLogin->cPassword))
                  );

        QString sLogin(pLogin->cLogin);
        QString sPassword(pLogin->cPassword);

        // Check login and password against all registered users
        for (int Index = 0; Index < m_vUsers.count(); Index++)
        {
            LOG_DEBUG(QString("... checking against %1 ...").arg(m_vUsers[Index].login()));

            if (m_vUsers[Index].login() == sLogin && m_vUsers[Index].encodedPassword() == sPassword)
            {
                // Tell the client it is logged in
                sendText(pSocket, QString(tr("Logged in as %1\n")).arg(sLogin));

                CConnectionData* pData = getConnectionData(pSocket);

                if (pData != nullptr)
                    pData->setUser(&(m_vUsers[Index]));

                LOG_DEBUG(QString("... passed"));

                return;
            }

            LOG_DEBUG(QString("... failed"));
        }

        // Tell the client we could not identify it
        sendText(pSocket, tr("Wrong login or password, try again\n"));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleSecureContext(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    // Only the client must handle this

    if (m_pClient != nullptr)
    {
        pRMC_Secure_Context pContextData = pRMC_Secure_Context(pHeader);

        LOG_DEBUG("CRemoteControl::handleSecureContext()");

        CConnectionData* pData = getConnectionData(pSocket);

        if (pData != nullptr)
        {
            m_eEncryption = RMC_ENCRYPTION_ROKE;

            QByteArray baData = QByteArray(pContextData->cData, int(size_t(pContextData->tHeader.ulLength) - sizeof(RMC_Header)));
            pData->secureContext().setContextData(baData);
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleExecute(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    LOG_DEBUG("CRemoteControl::handleExecute()");

    CConnectionData* pData = getConnectionData(pSocket);

    // Check for execution privilege
    if (!(getPrivilegesForSocket(pSocket) & EP_Execute))
    {
        sendText(pSocket, QString(tr("No privilege for execution.")));
        sendExecuteFinished(pSocket, 0, 1);
        return;
    }

    pRMC_Execute pExec = pRMC_Execute(pHeader);

    if (fileAccessOK(QString(pExec->cText)) == false)
    {
        sendText(pSocket, QString(tr("Access denied.")));
        sendExecuteFinished(pSocket, 0, 1);
        return;
    }

    LOG_DEBUG(
                QString("CRemoteControl::handleExecute() : RMC_EXECUTE : exec: %1")
                .arg(QString(pExec->cText))
                );

    // Add a cmd /c in case of execution under Windows
    QString sFullCommand = "";

#ifdef LINUX
    sFullCommand = QString(pExec->cText);
#else
    sFullCommand = QString("cmd /c %1").arg(pExec->cText);
#endif

    // Check some command privileges

    if (sFullCommand.toLower().contains("del") || sFullCommand.contains("rm") || sFullCommand.contains("mv"))
    {
        if (!(getPrivilegesForSocket(pSocket) & EP_FileDelete))
        {
            sendText(pSocket, QString(tr("No privilege for file delete.")));
            sendExecuteFinished(pSocket, 0, 1);
            return;
        }
    }

    if (sFullCommand.toLower().contains("shutdown"))
    {
        if (!(getPrivilegesForSocket(pSocket) & EP_Shutdown))
        {
            sendText(pSocket, QString(tr("No privilege for shutdown.")));
            sendExecuteFinished(pSocket, 0, 1);
            return;
        }
    }

    LOG_INFO(QString("Execute : %1\n").arg(sFullCommand));

    // Start the process
    QProcess* pProcess = new QProcess(this);

    pProcess->setProperty(PROP_SOCKET, qulonglong(pSocket));
    pProcess->setProcessChannelMode(QProcess::MergedChannels);
    pProcess->setWorkingDirectory(pData->workingDirectory());

    if (pExec->bDetached)
    {
        pProcess->startDetached(sFullCommand);

        onProcessFinished(0, QProcess::NormalExit);
    }
    else
    {
        connect(pProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(onProcessReadyRead()));
        connect(pProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(onProcessFinished(int, QProcess::ExitStatus)));
        connect(pProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));

        LOG_DEBUG(QString("CRemoteControl::handleExecute() : Launching process..."));

        pProcess->start(sFullCommand);
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleChangeDirectory(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    CConnectionData* pData = getConnectionData(pSocket);

    pRMC_ChangeDirectory pChange = pRMC_ChangeDirectory(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleChangeDirectory(%1)").arg(pChange->cTargetDirectory));

    LOG_INFO(QString("CD : %1\n").arg(pChange->cTargetDirectory));

    // Store the app's working directory
    QString sCurrentDir = QDir::currentPath();

    if (QDir::setCurrent(pData->workingDirectory()) == false)
    {
        sendText(pSocket, tr("Internal error"));
    }
    else
    {
        // Try to change the current directory
        if (QDir::setCurrent(pChange->cTargetDirectory) == false)
        {
            sendText(pSocket, tr("No such directory"));
        }
        else
        {
            pData->setWorkingDirectory(QDir::currentPath());
        }

        QDir::setCurrent(sCurrentDir);

        // Tell the client about the current directory
        sendPwd(pSocket);
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleResponse(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    Q_UNUSED(pSocket);

    pRMC_Response pResponse = pRMC_Response(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleResponse() : got %1 bytes").arg(pResponse->ulDataSize));

    // Write the response on standard output
    if (pResponse->ulDataSize > 0)
    {
        echo(QString(pResponse->cData));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleExecuteFinished(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    Q_UNUSED(pSocket);

    LOG_DEBUG("CRemoteControl::handleExecuteFinished()");

    pRMC_ExecuteFinished pFinished = pRMC_ExecuteFinished(pHeader);

    // Emit the transactionTerminated signal
    if (m_bDoShell == false)
    {
        m_iTransactionResult = pFinished->iErrorCode;

        QTimer::singleShot(1000, this, SLOT(onDoEmitTransactionTerminated()));
    }
    else
    {
        QTimer::singleShot(10, this, SLOT(onNextCommand()));
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleGetFile(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    // Check file read privileges
    if (!(getPrivilegesForSocket(pSocket) & EP_FileRead)) return;

    pRMC_GetFile pGet = pRMC_GetFile(pHeader);

    QString sSourceName(pGet->cSourceName);
    QString sTargetName(pGet->cTargetName);

    LOG_DEBUG(
                QString("CRemoteControl::handleGetFile() : %1 to %2")
                .arg(sSourceName)
                .arg(sTargetName)
                );

    // Is there a wildcard in the source name?
    bool bIsWildCard = sSourceName.contains('*');

    // Get the list of files or single file described by sSourceName
    QVector<QString> vFiles = getFileListFromSourceName(sSourceName);

    bool bFileNotFoundSent = false;
    int iFileCount = 0;

    // Loop through each file name
    for (QString sFileName : vFiles)
    {
        QFile tFile(sFileName);

        if (fileAccessOK(QString(sFileName)))
        {
            // Does file exist?
            if (tFile.exists())
            {
                iFileCount++;

                QString sFullTargetName = sTargetName;

                if (bIsWildCard)
                {
                    QFileInfo tSourceInfo(sFileName);
                    sFullTargetName = QString("%1/%2").arg(sTargetName).arg(tSourceInfo.fileName());
                }

                CFileTransferData* pTransfer = new CFileTransferData(
                            pSocket,
                            sFileName,
                            sFullTargetName,
                            quint32(tFile.size()),
                            true
                            );

                LOG_DEBUG(
                            QString("CRemoteControl::handleGetFile() : adding transfer ID %1, %2 => %3")
                            .arg(pTransfer->getTransferID())
                            .arg(sFileName)
                            .arg(sFullTargetName)
                            );

                // Add the file transfer object to list of transfers
                m_vFileTransfers.append(pTransfer);

                LOG_INFO(QString("Accepted GET %1 => %2.").arg(sFileName).arg(sFullTargetName));

                // Tell the client about the new transfer

                LOG_DEBUG(
                            QString("CRemoteControl::handleGetFile() : sending RMC_FileTransfer to %1")
                            .arg(SOCKET_NAME(pSocket))
                            );

                RMC_FileTransfer tChunk;

                fillMessageHeader(pRMC_Header(&tChunk), RMC_FILE_TRANSFER, sizeof(RMC_FileTransfer));

                tChunk.ulTransferID = pTransfer->getTransferID();
                tChunk.ulFileSize   = pTransfer->getFileSize();

#ifdef WIN32
                strcpy_s(tChunk.cSourceName, sizeof(tChunk.cSourceName), pTransfer->getSourceName().toLatin1().constData());
                strcpy_s(tChunk.cTargetName, sizeof(tChunk.cTargetName), pTransfer->getTargetName().toLatin1().constData());
#else
                strcpy(tChunk.cSourceName, pTransfer->getSourceName().toLatin1().constData());
                strcpy(tChunk.cTargetName, pTransfer->getTargetName().toLatin1().constData());
#endif

                sendMessage(pSocket, pRMC_Header(&tChunk));
            }
            else
            {
                // File not found already sent?
                if (bFileNotFoundSent == false)
                {
                    bFileNotFoundSent = true;

                    // Send a file not found text
                    sendText(pSocket, QString(tr("File not found : %1\n")).arg(tFile.fileName()));
                    sendExecuteFinished(pSocket, 0, 1);
                }
            }
        }
    }

    if (iFileCount == 0)
    {
        sendText(pSocket, tr("File set empty\n"));
        sendExecuteFinished(pSocket, 0, 1);
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleFileTransfer(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    pRMC_FileTransfer pFileTransfer = pRMC_FileTransfer(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleFileTransfer() : (%1)").arg(pFileTransfer->ulTransferID));

    LOG_INFO(QString("Accepted transfer %1 => %2.").arg(pFileTransfer->cSourceName).arg(pFileTransfer->cTargetName));

    RMC_FileChunk tChunk; memset(&tChunk, 0, sizeof(RMC_FileChunk));

    tChunk.ulTransferID     = pFileTransfer->ulTransferID;
    tChunk.ulFileSize       = pFileTransfer->ulFileSize;
    tChunk.ulOffsetInFile   = 0;
    tChunk.ulDataSize       = 0;
    memcpy(tChunk.cSourceName, pFileTransfer->cSourceName, sizeof(tChunk.cSourceName));
    memcpy(tChunk.cTargetName, pFileTransfer->cTargetName, sizeof(tChunk.cTargetName));

    handleFileChunk(pSocket, pRMC_Header(&tChunk));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleFileChunk(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    // Check file creation privileges
    if (!(getPrivilegesForSocket(pSocket) & EP_FileWrite)) return;

    pRMC_FileChunk pChunk = pRMC_FileChunk(pHeader);

    // LOG_DEBUG(QString("CRemoteControl::handleFileChunk() : (%1)").arg(pChunk->iOffsetInFile));

    // Search for existing file transfer object using message ID
    CFileTransferData* pTransfer = nullptr;

    for (QVector<CFileTransferData*>::iterator it = m_vFileTransfers.begin(); it != m_vFileTransfers.end(); it++)
    {
        CFileTransferData* pIterTransfer = *it;

        if (pIterTransfer->getTransferID() == pChunk->ulTransferID)
        {
            pTransfer = pIterTransfer;
            break;
        }
    }

    // File transfer object exists?
    if (pTransfer == nullptr)
    {
        // No, this is the start of transfer, create a new file transfer object
        QString sSourceName = QString(pChunk->cSourceName);
        QString sTargetName = QString(pChunk->cTargetName);

        pTransfer = new CFileTransferData(m_pClient, sSourceName, sTargetName, pChunk->ulFileSize, pChunk->ulTransferID, false);

        LOG_DEBUG(
                    QString("CRemoteControl::handleFileChunk() : appending transfer ID %1, %2 => %3")
                    .arg(pTransfer->getTransferID())
                    .arg(sSourceName)
                    .arg(sTargetName)
                    );

        m_vFileTransfers.append(pTransfer);

        pTransfer->setFile(new QFile(pTransfer->getTargetName()));

        // If the target file exists, delete it
        if (pTransfer->getFile()->exists())
        {
            LOG_DEBUG(
                        QString("CRemoteControl::handleFileChunk() : deleting file %1")
                        .arg(pTransfer->getTargetName())
                        );

            if (pTransfer->getFile()->remove() == false)
            {
                LOG_DEBUG(
                            QString("CRemoteControl::handleFileChunk() : error while deleting file %1")
                            .arg(pTransfer->getTargetName())
                            );

                // Return error to caller
                sendText(pSocket, QString(tr("Could not delete file %1\n")).arg(pTransfer->getTargetName()));

                // Tell caller the file transfer is finished
                sendExecuteFinished(pSocket, 0, 1);

                return;
            }
        }

        // Get some info about the target dir
        QFileInfo tInfo(pTransfer->getTargetName());
        QDir tDir = tInfo.absoluteDir();

        // Create the target directory if needed
        if (tDir.exists() == false) tDir.mkpath(tDir.path());

        // Open the file
        int iTries = 0;

        while (!pTransfer->getFile()->isOpen())
        {
            LOG_DEBUG(
                        QString("Creating file %1")
                        .arg(pTransfer->getTargetName())
                        );

            pTransfer->getFile()->open(QIODevice::WriteOnly);

            iTries++;
            if (iTries > FILE_OPEN_TRIES) break;
        }
    }

    // Record the last message time
    pTransfer->setLastIncomingMessageTime(QDateTime::currentDateTime());

    // Is the file open?
    if (pTransfer->getFile()->isOpen())
    {
        //LOG_DEBUG(
        //	QString("CRemoteControl::onSocketReadyRead() : RMC_FILE_CHUNK : writing %1 bytes to file %2")
        //	.arg(pChunk->iDataSize)
        //	.arg(pTransfer->getTargetName())
        //);

        // Yes, write chunk to it
        if (pChunk->ulDataSize > 0)
        {
            pTransfer->getFile()->write(pChunk->cData, pChunk->ulDataSize);
            // pTransfer->getFile()->flush();
        }
    }
    else
    {
        // No, log an error
        LOG_ERROR(
                    QString("CRemoteControl::handleFileChunk() : file %1 is not open")
                    .arg(pTransfer->getTargetName())
                    );

        // Return error to caller
        sendText(pSocket, QString(tr("File %1 is not open\n")).arg(pTransfer->getTargetName()));

        // Tell caller the file transfer is finished
        sendExecuteFinished(pSocket, 0, 1);
    }

    // Is this the last chunk for the file?
    if (pChunk->cIsLastChunk)
    {
        if (pTransfer->getFile()->isOpen()) pTransfer->getFile()->close();

        // Check file size
        if (pTransfer->getFile()->size() != pChunk->ulFileSize)
        {
            pTransfer->getFile()->remove();

            LOG_ERROR(
                        QString("CRemoteControl::handleFileChunk() : file size incorrect after last chunk for file %1")
                        .arg(pTransfer->getTargetName())
                        );

            LOG_ERROR(
                        QString("Expected %1, got %2")
                        .arg(pChunk->ulFileSize)
                        .arg(pTransfer->getFile()->size())
                        );

            sendText(pSocket, QString(tr("File size incorrect after last chunk for file %1\n")).arg(pTransfer->getTargetName()));
        }

        // Tell the sender the transfer is finished

        LOG_DEBUG(
                    QString("CRemoteControl::handleFileChunk() : sending message RMC_FILE_RECEIVED")
                    );

        // Tell the sender the transfer is finished
        sendFileReceived(pSocket, pTransfer->getTransferID(), 0, 0);

        // Remove the associated file transfer object
        LOG_DEBUG(
                    QString("CRemoteControl::handleFileChunk() : removing transfer ID %1")
                    .arg(pTransfer->getTransferID())
                    );

        m_vFileTransfers.remove(m_vFileTransfers.indexOf(pTransfer));
        delete pTransfer;

        LOG_DEBUG(
                    QString("CRemoteControl::handleFileChunk() : remaining transfers : %1")
                    .arg(m_vFileTransfers.count())
                    );

        if (m_vFileTransfers.count() == 0)
        {
            QTimer::singleShot(1000, this, SLOT(onDoEmitTransactionTerminated()));
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleFileReceived(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    Q_UNUSED(pSocket);

    pRMC_FileReceived pReceived = pRMC_FileReceived(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleFileReceived() : ulTransferID = %1").arg(pReceived->ulTransferID));

    for (QVector<CFileTransferData*>::iterator it = m_vFileTransfers.begin(); it != m_vFileTransfers.end(); it++)
    {
        CFileTransferData* pIterTransfer = *it;

        if (pIterTransfer->getTransferID() == pReceived->ulTransferID)
        {
            LOG_DEBUG(QString("CRemoteControl::handleFileReceived() : removing file transfer ID %1").arg(pIterTransfer->getTransferID()));

            m_vFileTransfers.remove(m_vFileTransfers.indexOf(pIterTransfer));
            delete pIterTransfer;

            if (m_vFileTransfers.count() == 0 || pReceived->iError != 0)
            {
                m_iTransactionResult = pReceived->iError;

                QTimer::singleShot(1000, this, SLOT(onDoEmitTransactionTerminated()));
            }

            return;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleFileInfo(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    Q_UNUSED(pSocket);

    pRMC_FileInfo pInfo = pRMC_FileInfo(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleFileInfo() : cName = %1").arg(pInfo->cName));
    LOG_DEBUG(QString("CRemoteControl::handleFileInfo() : ulCRC = %1").arg(pInfo->ulCRC));

    // Some file information came in, find the concerned file transfer and assign
    for (int Index = 0; Index < m_vFileTransfers.count(); Index++)
    {
        CFileTransferData* pTransfer = m_vFileTransfers[Index];

        if (pTransfer->getTargetName() == QString(pInfo->cName))
        {
            LOG_DEBUG(QString("Info set for %1 (CRC %2)").arg(pTransfer->getTargetName()).arg(pInfo->ulCRC));

            pTransfer->setTargetFileCRC(pInfo->ulCRC);
            pTransfer->setGotFileInfo(true);

            return;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleProgramWorkingDir(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    Q_UNUSED(pSocket);

    pRMC_ProgramWorkingDir pInfo = pRMC_ProgramWorkingDir(pHeader);

    m_sRemotePwd = QString(pInfo->cPath);

    LOG_DEBUG(QString("CRemoteControl::handleProgramWorkingDir() : cPath = %1").arg(m_sRemotePwd));

    QTimer::singleShot(10, this, SLOT(onNextCommand()));
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleRequest(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    pRMC_Request pRequest = pRMC_Request(pHeader);

    LOG_DEBUG(QString("CRemoteControl::handleRequest() : lRequest = %1").arg(pRequest->lRequest));

    // Switch on the request type
    switch (pRequest->lRequest)
    {
    case RMC_REQUEST_FILEINFO:
    {
        QString sFileName(pRequest->ucParam);

        LOG_INFO(QString("Serving file info for %1").arg(sFileName));

        QFile tFile(sFileName);

        // Does file exist?
        if (tFile.exists())
        {
            sendFileInfo(pSocket, sFileName, getFileCRC(tFile));
        }
        else
        {
            sendFileInfo(pSocket, sFileName, 0);
        }
    }
        break;

    case RMC_REQUEST_PWD:
    {
        sendPwd(pSocket);
    }
        break;

    case RMC_REQUEST_SHUTDOWN:
    {
        if (getPrivilegesForSocket(pSocket) & EP_Shutdown)
        {
            // Tell the sender we are shutting down
            sendText(pSocket, QString(tr("Shutting down in two seconds...\n")));
            sendExecuteFinished(pSocket, 0, 0);

            QTimer::singleShot(2000, this, SLOT(onDoEmitShutdown()));
        }
        else
        {
            // Tell the sender that no such thing will be done
            sendText(pSocket, QString(tr("Cannot comply...\n")));
            sendExecuteFinished(pSocket, 0, 0);
        }
    }
        break;

    case RMC_REQUEST_GETRIGHTS:
    {
        int iRights = getPrivilegesForSocket(pSocket);

        sendText(pSocket, QString(tr("Your privileges:\n")));

        if (iRights & EP_FileRead) sendText(pSocket, QString(tr("- File read\n")));
        if (iRights & EP_FileWrite) sendText(pSocket, QString(tr("- File write\n")));
        if (iRights & EP_FileDelete) sendText(pSocket, QString(tr("- File delete\n")));
        if (iRights & EP_Execute) sendText(pSocket, QString(tr("- Execution\n")));
        if (iRights & EP_Shutdown) sendText(pSocket, QString(tr("- Shut down\n")));

        sendExecuteFinished(pSocket, 0, 0);
    }
        break;
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onDoEmitShutdown()
{
    emit shutdown();
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::handleMergeFile(QTcpSocket* pSocket, RMC_Header* pHeader)
{
    // Check file read privileges
    if (!(getPrivilegesForSocket(pSocket) & EP_FileWrite)) return;

    pRMC_MergeFile pMerge = pRMC_MergeFile(pHeader);

    QString sSourceName(pMerge->cSourceName);
    QString sTargetName(pMerge->cTargetName);

    LOG_DEBUG(
                QString("CRemoteControl::handleMergeFile() : %1 to %2")
                .arg(sSourceName)
                .arg(sTargetName)
                );

    if (pMerge->iType == RMC_MERGETYPE_INI)
    {
        QSettings tSettings1(sSourceName, QSettings::IniFormat);
        QSettings tSettings2(sTargetName, QSettings::IniFormat);

        for (QString sKey1 : tSettings1.allKeys())
        {
            if (tSettings2.allKeys().contains(sKey1) == false)
            {
                tSettings2.setValue(sKey1, tSettings1.value(sKey1));
            }
        }

        sendText(pSocket, tr("Merge done."));
    }

    sendExecuteFinished(pSocket, 0, 0);
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onProcessReadyRead()
{
    QProcess* pProcess = dynamic_cast<QProcess*>(QObject::sender());

    if (pProcess != nullptr)
    {
        sendProcessOutput(pProcess, false, 0);
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);

    LOG_DEBUG(QString("CRemoteControl::onProcessFinished() : exitCode = %1").arg(exitCode));

    QProcess* pProcess = dynamic_cast<QProcess*>(QObject::sender());

    if (pProcess != nullptr)
    {
        sendProcessOutput(pProcess, true, exitCode);

        delete pProcess;
    }
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::onProcessError(QProcess::ProcessError Error)
{
    Q_UNUSED(Error);

    LOG_DEBUG(QString("CRemoteControl::onProcessError() : Error = %1").arg(Error));

    QProcess* pProcess = dynamic_cast<QProcess*>(QObject::sender());

    if (pProcess != nullptr)
    {
        sendProcessOutput(pProcess, true, -1);
    }
}

//-------------------------------------------------------------------------------------------------

int CRemoteControl::getPrivilegesForSocket(QTcpSocket* pSocket)
{
    // If in client mode, access all
    if (m_pClient != nullptr)
        return 0xFFFF;

    CConnectionData* pData = getConnectionData(pSocket);

    if (pData == nullptr || pData->user() == nullptr)
        return m_vUsers[0].privileges();

    return pData->user()->privileges();
}

//-------------------------------------------------------------------------------------------------

bool CRemoteControl::fileAccessOK(QString sFileName)
{
    for (QString sName : m_vProhibitedFiles)
    {
        if (sFileName.toLower().contains(sName.toLower())) return false;
    }

    return true;
}

//-------------------------------------------------------------------------------------------------

CConnectionData* CRemoteControl::newConnectionData(QTcpSocket* pSocket, bool bIsServer)
{
    // Assign the default user to this socket
    CConnectionData* pData = new CConnectionData(&(m_vUsers[0]), bIsServer);

    pSocket->setProperty(PROP_DATA, qulonglong(pData));

    return pData;
}

//-------------------------------------------------------------------------------------------------

CConnectionData* CRemoteControl::getConnectionData(QTcpSocket* pSocket)
{
    CConnectionData* pData = dynamic_cast<CConnectionData*>(reinterpret_cast<QObject*>(pSocket->property(PROP_DATA).toULongLong()));

    return pData;
}

//-------------------------------------------------------------------------------------------------

void CRemoteControl::discardConnectionData(QTcpSocket* pSocket)
{
    CConnectionData* pData = dynamic_cast<CConnectionData*>(reinterpret_cast<QObject*>(pSocket->property(PROP_DATA).toULongLong()));

    if (pData != nullptr)
    {
        delete pData;
    }
}
