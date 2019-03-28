
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QCoreApplication>
#include <QStringList>
#include <QTextStream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFileInfo>
#include <QSettings>
#include <QProcess>
#include <QVector>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QFile>
#include <QDir>

#include "CRemoteControlData.h"
#include "CRemoteControlUser.h"
#include "../CSecureContext.h"
#include "../CXMLNode.h"

class QTPLUSSHARED_EXPORT CConnectionData : public QObject
{
    Q_OBJECT

public:

    CConnectionData(CRemoteControlUser* pUser, bool bIsServer);

    ~CConnectionData();

    void setUser(CRemoteControlUser* value) { m_pUser = value; }
    void setWorkingDirectory(const QString& value) { m_sWorkingDirectory = value; }

    CRemoteControlUser* user() { return m_pUser; }
    QString workingDirectory() { return m_sWorkingDirectory; }

    CSecureContext& secureContext() { return m_tContext; }
    const CSecureContext& secureContext() const { return m_tContext; }

protected:

    CRemoteControlUser*	m_pUser;
    QString				m_sWorkingDirectory;
    CSecureContext      m_tContext;
};

class QTPLUSSHARED_EXPORT CRemoteControl : public QTcpServer
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    // Server constructor
    CRemoteControl(quint16 iPort, bool bROKE = true);

    // Client constructor
    CRemoteControl(const QString& sIP, quint16 iPort, int iConnectTimeoutMS, int iMaxWaitingTimeMS, bool bDoShell);

    // Destructor
    ~CRemoteControl();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    bool getClientConnected() { return m_bClientConnected; }

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Sends a login and password to the server
    void setLoginPassword(QString sLogin, QString sPassword);

    //! Sends a command ti the server
    void sendCommand(const QString& sCommand, bool bDetached);

    //! Sends a privilege request to the server
    bool getRights();

    //! Sends a shutdown command to the server
    bool sendShutdown();

    //! Gets a file from the server
    bool getFile(const QString& sourceName, const QString& targetName, bool bKeepNewest, bool bCompCRC);

    //! Puts a file on the server
    bool putFile(const QString& sourceName, const QString& targetName, bool bKeepNewest, bool bCompCRC);

    //!
    bool mergeFile(const QString& sourceName, const QString& targetName);

    //! Gets the CRC of a file on the server
    bool getRemoteFileCRC(const QString& targetName);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //! Reads configuration file
    void readConfiguration();

    //! Initializes the security members
    void initSecurity();

    //! Initializes the registered users
    void initUsers();

    //! Sends a secure context to a client
    void sendSecureContext(QTcpSocket* pSocket);

    //! Fills the header of a message with specified values
    void fillMessageHeader(pRMC_Header pHeader, ERMCMessage eMessage, quint32 ulLength);

    //! Reads a command from the console
    QString readCommand();

    //! Encrypts a message using the socket's secure context
    pRMC_Header encryptMessage(QTcpSocket* pSocket, pRMC_Header pDecryptedMessage);

    //! Decrypts a message using the socket's secure context
    pRMC_Header decryptMessage(QTcpSocket* pSocket, pRMC_Header pEncryptedMessage);

    bool readMessage(QTcpSocket* pSocket);
    QVector<QString> getFileListFromSourceName(const QString& sSourceName);
    void checkConnectionTransfers(QTcpSocket* pSocket, bool bIsDisconnected = false);
    int getPrivilegesForSocket(QTcpSocket* pSocket);
    quint32 getFileCRC(QFile& tFile);
    void sendProcessOutput(QProcess* pProcess, bool bFinished, int iExitCode);
    void echo(QString sText);
    CConnectionData* newConnectionData(QTcpSocket* pSocket, bool bIsServer);
    CConnectionData* getConnectionData(QTcpSocket* pSocket);
    bool fileAccessOK(QString sFileName);

    void handleLogin(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleSecureContext(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleExecute(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleChangeDirectory(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleResponse(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleExecuteFinished(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleGetFile(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleFileTransfer(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleFileChunk(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleFileReceived(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleFileInfo(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleProgramWorkingDir(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleRequest(QTcpSocket* pSocket, RMC_Header* pHeader);
    void handleMergeFile(QTcpSocket* pSocket, RMC_Header* pHeader);

    bool sendMessage(QTcpSocket* pSocket, pRMC_Header pMessage);
    void sendText(QTcpSocket* pSocket, const QString& sText);
    void sendLogin(QTcpSocket* pSocket, QString sLogin, QString sPassword);
    void sendExecuteFinished(QTcpSocket* pSocket, qint32 iProcess, qint32 iErrorCode);
    void sendFileReceived(QTcpSocket* pSocket, quint32 ulTransferID, qint32 iError, quint32 ulCRC);
    void sendRequest(QTcpSocket* pSocket, qint32 lRequest, QString sParam);
    void sendFileInfo(QTcpSocket* pSocket, QString sName, quint32 ulCRC);
    void sendPwd(QTcpSocket* pSocket);

    // Used to store a command that will be sent to server
    class CProcessInfo
    {
    public:

        CProcessInfo()
            : m_sCommand("")
            , m_bDetached(false)
        {
        }

        CProcessInfo(QString sCommand, bool bDetached)
            : m_sCommand(sCommand)
            , m_bDetached(bDetached)
        {
        }

        QString	m_sCommand;
        bool	m_bDetached;
    };

signals:

    void transactionTerminated(int iError);
    void shutdown();

protected slots:

    void onTimer();
    void onServerConnection();
    void onSocketConnected();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onProcessReadyRead();
    void onProcessFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onProcessError(QProcess::ProcessError Error);
    void onDoEmitTransactionTerminated();
    void onDoEmitShutdown();
    void nextCommand();

protected:

    CXMLNode                        m_tConfiguration;
    QTimer                          m_Timer;
    QVector<CRemoteControlUser>     m_vUsers;
    QTcpSocket*                     m_pClient;
    QVector<QTcpSocket*>            m_vSockets;
    QVector<CFileTransferData*>     m_vFileTransfers;
    QVector<CProcessInfo>           m_vCommands;
    QMap<QTcpSocket*, QByteArray>   m_vIncomingData;
    QVector<QString>                m_vProhibitedFiles;
    QString                         m_sIP;
    QString                         m_sSelfIP;
    QString                         m_sRMC;
    QString                         m_sRemotePwd;
    ERMCEncyption                   m_eEncryption;
    bool                            m_bClientConnected;
    bool                            m_bDoShell;
    int                             m_iConnectTimeoutMS;
    int                             m_iMaxWaitingTimeMS;
    int                             m_iTransactionResult;
};
