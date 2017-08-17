
// Qt
#include <QCoreApplication>
#include <QFile>

// Application
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

// #define DEBUG_RECORD_REQUESTS
#define THREADED_SERVER

//-------------------------------------------------------------------------------------------------

/*!
    \class CHTTPServer
    \inmodule qt-plus
    \brief A basic HTTP server that can serve files and dynamic content.

    \section1 How it works
    This server listens to and processes HTTP requests on a given port. \br
    When asked for a resource, the first thing it does is check if it exists on disk. If it does
    not, the server executes its getContent() which may be overridden in order to
    return some HTML content to the client. \br
    The disk access will be limited to cetrain folders, which are specified using the addAuthorizedFolder()
    method. \br
    There is a flood protection mechanism which can be disabled with the useFloodProtection() method.

    \section1 Sample
    The following will create a HTTP server that listens on port 8080 and greets clients with "Hello world!"
    \code
    class MyHTTPServer : public CHTTPServer
    {
        MyHTTPServer() : CHTTPServer(8080)
        {
            addAuthorizedFolder("c:\mywebfolder");
        }

        virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME)
        {
            sBody = "<div>Hello world!</div>";
        }
    }
    \endcode
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CHTTPServer with a binding port equal to \a port. \br\br
    \a parent is the owner of this object.
*/
CHTTPServer::CHTTPServer(quint16 port, QObject* parent)
    : QTcpServer(parent)
    , m_mMutex(QMutex::Recursive)
    , m_iRequestCount(0)
    , m_iMaxRequestPerSeconds(15)
    , m_bDisabled(false)
    , m_bUseFloodProtection(true)
{
    // Fill MIME array

    m_vExtensionToContentType["txt"]	= MIME_Content_PlainText;
    m_vExtensionToContentType["log"]	= MIME_Content_PlainText;
    m_vExtensionToContentType["html"]	= MIME_Content_HTML;
    m_vExtensionToContentType["css"]	= MIME_Content_CSS;
    m_vExtensionToContentType["js"]		= MIME_Content_Javascript;
    m_vExtensionToContentType["pdf"]	= MIME_Content_PDF;
    m_vExtensionToContentType["xhtml"]	= MIME_Content_XHTML;
    m_vExtensionToContentType["json"]	= MIME_Content_JSON;
    m_vExtensionToContentType["xml"]	= MIME_Content_XML;
    m_vExtensionToContentType["zip"]	= MIME_Content_ZIP;
    m_vExtensionToContentType["gif"]	= MIME_Content_GIF;
    m_vExtensionToContentType["jpg"]	= MIME_Content_JPG;
    m_vExtensionToContentType["jpeg"]	= MIME_Content_JPG;
    m_vExtensionToContentType["png"]	= MIME_Content_PNG;

    // Fill static IP black list

    m_lStaticIPBlackList << "0.0.0.0";
    m_lStaticIPBlackList << "10.0.0.0";
    m_lStaticIPBlackList << "127.0.0.0";
    m_lStaticIPBlackList << "224.0.0.0";
    m_lStaticIPBlackList << "240.0.0.0";
    m_lStaticIPBlackList << "169.254.0.0";
    m_lStaticIPBlackList << "172.16.0.0";
    m_lStaticIPBlackList << "192.0.2.0";
    m_lStaticIPBlackList << "192.168.0.0";

    // Listen

    if (port > 0)
    {
        if (listen(QHostAddress::Any, port))
        {
            connect(this, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        }
        else
        {
            qWarning() << QString("CHTTPServer::CHTTPServer() : bind to %1 failed").arg(port);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CHTTPServer.
*/
CHTTPServer::~CHTTPServer()
{
    // Fermeture du serveur
    close();
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles incoming connections.
*/
void CHTTPServer::onNewConnection()
{
    // Récupération socket entrante
    QTcpSocket* pSocket = nextPendingConnection();
    QString sIPAddress = cleanIP(pSocket->peerAddress().toString());
    bool bRejected = false;

    // Check static black list
    if (m_lStaticIPBlackList.contains(sIPAddress))
    {
        bRejected = true;
    }
    // Check dynamic black list
    else if (m_lDynamicIPBlackList.contains(sIPAddress))
    {
        bRejected = true;
    }
    // Check monitors
    else if (m_mMonitors[sIPAddress].shouldBeBlocked())
    {
        qDebug() << QString("Blacklisting %1").arg(sIPAddress);

        // Blacklist and reject this connection
        m_lDynamicIPBlackList << sIPAddress;

        bRejected = true;
    }

    if (bRejected)
    {
        // Reject this connection
        pSocket->disconnect();
        pSocket->deleteLater();
    }
    else
    {
        pSocket->setReadBufferSize(1024 * 20);

        // Create custom client data
        // No need to store the pointer, it is sotred in the socket's properties
        new CClientData(pSocket);

        // Connexion des signaux
        connect(pSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
        connect(pSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketBytesWritten(qint64)));
        connect(pSocket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles a socket disconnection. \br\br
    Calls the handleSocketDisconnection() method.
*/
void CHTTPServer::onSocketDisconnected()
{
    // Récupération de l'objet émetteur du signal
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    // Appel du gestionnaire implémenté (ou non) par les sous-classes
    handleSocketDisconnection(pSocket);

    // Destruction des données utilisateur associées à la socket
    CClientData::deleteFromSocket(pSocket);

    // La socket est détruite en temps voulu par Qt
    pSocket->deleteLater();
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles data reading when a socket emits the readyRead signal. \br\br
    Calls the handleSocketBytesRead() method.
*/
void CHTTPServer::onSocketReadyRead()
{
    // Get the emitting socket
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());
    QString sIPAddress = cleanIP(pSocket->peerAddress().toString());

    // If the connection is rejected, free socket and its client data
    if (m_mMonitors[sIPAddress].shouldBeBlocked())
    {
        CClientData::deleteFromSocket(pSocket);
        pSocket->disconnect();
        pSocket->deleteLater();
        return;
    }

    // Is the socket valid?
    if (pSocket != nullptr)
    {
        // If the server is disabled, free socket and its client data
        if (m_bDisabled)
        {
            CClientData::deleteFromSocket(pSocket);
            pSocket->disconnect();
            pSocket->deleteLater();
            return;
        }

        // Get the client data from the socket
        CClientData* pData = CClientData::getFromSocket(pSocket);
        QString sIPAddress = cleanIP(pSocket->peerAddress().toString());

        if (pData != nullptr)
        {
            // Si la socket est en état connecté
            if (pSocket->state() == QTcpSocket::ConnectedState)
            {
                // Lecture de toutes les données disponibles
                QByteArray baData = pSocket->readAll();

                // Ajout des octets arrivant au buffer
                pData->m_baBuffer.append(baData);

                // Est-ce que l'entête a été lue?
                if (pData->m_bHeaderRead == false)
                {
                    QStringList lTokens = getHeaderTokens(baData);

                    pData->m_bHeaderRead = true;
                    pData->m_iExpectedBytes = getExpectedBytes(lTokens);

                    // Récupération du type de contenu
                    QString sContentType = getTokenValue(lTokens, Token_ContentType);

                    if (sContentType.startsWith(MIME_Content_MultiPart))
                    {
                        pData->m_sMultipartBoundary = getSubTokenValue(lTokens, Token_ContentType, Token_boundary);
                    }
                }

                // Décrémentation du nombre d'octets attendus
                pData->m_iExpectedBytes -= baData.count();

                if (pData->m_sMultipartBoundary.isEmpty() == false)
                {
                    QString sText = QString(baData);
                    QString sClosingBoundary = QString("--%1--").arg(pData->m_sMultipartBoundary);

                    if (sText.contains(sClosingBoundary))
                    {
                        // Mark header as not read
                        pData->m_bHeaderRead = false;

                        // Execute the client request
                        if (m_mMonitors[sIPAddress].shouldBeBlocked() == false)
                        {
#ifdef THREADED_SERVER
                            CRequestProcessor* pProcessor = new CRequestProcessor(this, pSocket);
                            pProcessor->setAutoDelete(true);
                            m_pProcessors.start(pProcessor);
#else
                            processRequest(pSocket);
#endif
                        }
                    }
                }
                else
                if (pData->m_iExpectedBytes <= 0)
                {
                    // L'entête n'a pas été lue
                    pData->m_bHeaderRead = false;

                    // Execute the client request
                    if (m_mMonitors[sIPAddress].shouldBeBlocked() == false)
                    {
#ifdef THREADED_SERVER
                        CRequestProcessor* pProcessor = new CRequestProcessor(this, pSocket);
                        pProcessor->setAutoDelete(true);
                        m_pProcessors.start(pProcessor);
#else
                        processRequest(pSocket);
#endif
                    }
                }
            }
            else
            {
                // Appel du gestionnaire implémenté (ou non) par les sous-classes
                handleSocketBytesRead(pSocket);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles the bytesWritten signal of a socket. \br\br
    \a iBytes contains the number of written bytes. \br\br
    Calls the handleSocketBytesWritten() method.
*/
void CHTTPServer::onSocketBytesWritten(qint64 iBytes)
{
    // Récupération de l'objet émetteur du signal
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    // Appel du gestionnaire implémenté (ou non) par les sous-classes
    handleSocketBytesWritten(pSocket, iBytes);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the tokens in a HTTP header. \br\br
    \a baData contains the header.
*/
QStringList CHTTPServer::getHeaderTokens(QByteArray baData)
{
    QStringList lReturnValue;
    QString sText(baData);

    // Récupération du header
    QString sHeader = getRequestHeader(sText);

    // Récupération des tokens du header HTTP
    lReturnValue = sHeader.split(QRegExp("[\r\n][\r\n]*"));

    return lReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of expected bytes to follow a HTTP header. \br\br
    \a lTokens contains the header tokens.
*/
int CHTTPServer::getExpectedBytes(QStringList lTokens)
{
    int iExpectedBytes = 0;

    if (lTokens.count() > 0)
    {
        if (lTokens[0].startsWith(HTTP_POST))
        {
            // Récupération du type de contenu
            QString sContentType = getTokenValue(lTokens, Token_ContentType);

            // Récupération du type de contenu
            QString sContentLength = getTokenValue(lTokens, Token_ContentLength);

            if (sContentLength.isEmpty() == false)
            {
                iExpectedBytes = sContentLength.toInt();
            }
        }
    }

    return iExpectedBytes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Processes a request from \a pSocket.
*/
void CHTTPServer::processRequest(QTcpSocket* pSocket)
{
    CClientData* pData = CClientData::getFromSocket(pSocket);
    QString sIPAddress = cleanIP(pSocket->peerAddress().toString());

    // Log the request
    LogRequest(sIPAddress, QString(pData->m_baBuffer));

    if (lock())
    {
        // Increment total request count
        m_iRequestCount++;

        if (m_bUseFloodProtection)
        {
            // Process request monitors
            m_mMonitors[sIPAddress].processIn();
        }

        unlock();
    }

#ifdef DEBUG_RECORD_REQUESTS
    QFile outFile(QString("Request_%1.txt").arg(QString::number(m_iRequestCount)));
    if (outFile.open(QFile::WriteOnly))
    {
        outFile.write(pData->m_baBuffer);
        outFile.close();
    }
#endif

    if (pData != nullptr)
    {
        bool bKeepAlive = false;

        QString sText(pData->m_baBuffer);
        QStringList lTokens = getHeaderTokens(pData->m_baBuffer);

        QStringList lPath;						// Client requested path (route)
        QMap<QString, QString> mArguments;		// Arguments coming from the URI
        QString sHost;							// Host name (ie this server)
        QString sContentType;					// Content type in case of a POST
        QByteArray baPostContent;				// Content in case of a POST
        bool bForceKeepAlive = false;

        // Process if we get at least one token
        if (lTokens.count() > 0)
        {
            // For now, only GET and POST are processed
            if (lTokens[0].startsWith(HTTP_GET) || lTokens[0].startsWith(HTTP_POST))
            {
                // Do we have more than one token?
                if (lTokens.count() > 1)
                {
                    // Get the request path (route) and arguments
                    getRequestPathAndArgs(lTokens, lPath, mArguments);

                    // Get the host name
                    sHost = getTokenValue(lTokens, Token_Host);

                    // Check if client request a keep-alive connection
                    QString sKeepAlive = getTokenValue(lTokens, Token_Connection);

                    if (sKeepAlive.toLower() == "keep-alive")
                    {
                        bKeepAlive = true;
                    }

                    // Get the content type and content
                    sContentType = getTokenValue(lTokens, Token_ContentType);

                    if (sContentType.isEmpty() == false)
                    {
                        getRequestPostContent(sText, baPostContent);
                    }
                }

                // Create a web context in order for subclasses to generate content
                CWebContext tContext(pSocket, sIPAddress, sHost, lPath, mArguments);

                if (sContentType.startsWith(MIME_Content_URLForm))
                {
                    QStringList lArgs = QString(baPostContent).split("&");

                    foreach(QString sArg, lArgs)
                    {
                        QStringList lCurrentArg = sArg.split("=");

                        if (lCurrentArg.count() > 1)
                        {
                            tContext.m_mArguments[lCurrentArg[0]] = lCurrentArg[1];
                        }
                    }
                }
                else if (sContentType.startsWith(MIME_Content_MultiPart))
                {
                    if (pData->m_sMultipartBoundary.isEmpty() == false)
                    {
                        QString sActualBoundary = QString("--%1").arg(pData->m_sMultipartBoundary);
                        QString sContent = QString(baPostContent);
                        QStringList lParts = sContent.split(sActualBoundary);

                        if (lParts.count() > 0)
                        {
                            int iIndex = 0;

                            foreach (QString sPart, lParts)
                            {
                                if (sPart.startsWith("--") == false)
                                {
#ifdef DEBUG_RECORD_REQUESTS
                                    QFile outFile(QString("Part_%1.txt").arg(QString::number(iIndex)));
                                    if (outFile.open(QFile::WriteOnly))
                                    {
                                        outFile.write(sPart.toLatin1());
                                        outFile.close();
                                    }
#endif

                                    if (sContentType.startsWith(MIME_Content_MultiPart_FormData))
                                    {
                                        // Get the part's tokens
                                        QStringList lPartTokens = sPart.split(QRegExp("[\r\n][\r\n]*"));

                                        // Get the part's content type and name
                                        QString sPartContentType = getTokenValue(lPartTokens, Token_ContentType);
                                        QString sName = getSubTokenValue(lPartTokens, Token_ContentDisposition, Token_name);

                                        if (sName.isEmpty() == false)
                                        {
                                            QByteArray baPartData;
                                            getRequestPostContent(sPart, baPartData);

#ifdef DEBUG_RECORD_REQUESTS
                                            QFile outFile(QString("Content_%1.txt").arg(sName));
                                            if (outFile.open(QFile::WriteOnly))
                                            {
                                                outFile.write(baPartData);
                                                outFile.close();
                                            }
#endif

                                            tContext.m_mArguments[sName] = QString(baPartData);
                                        }
                                    }
                                }

                                iIndex++;
                            }
                        }
                    }
                }

                // Assign the POST content to the context
                tContext.m_baPostContent = baPostContent;

                // If a file exists for the requested route, return it
                // Else return dynamic content
                if (getResponseFile(tContext, pSocket) == true)
                {
                }
                else
                {
                    bForceKeepAlive = getResponseDynamicContent(tContext, pSocket);
                }
            }
            else
            {
            }
        }
        else
        {
            qWarning() << QString("CHTTPServer::processRequest() : No token to read");
        }

        // Clear the input buffer in the sockect's associated data
        pData->m_baBuffer.clear();
        pData->m_sMultipartBoundary.clear();

        // If the socket is still connected...
        if (pSocket->state() == QAbstractSocket::ConnectedState)
        {
            // Flush the socket's output
            pSocket->flush();

            // In case we don't have a keep-alive connection, free the socket and its user data
            if (bKeepAlive == false && bForceKeepAlive == false)
            {
                CClientData::deleteFromSocket(pSocket);
                pSocket->disconnect();
                pSocket->deleteLater();
            }
        }
        else
        {
            qWarning() << QString("CHTTPServer::processRequest() : Socket is not in connected state");
        }
    }

    if (lock())
    {
        if (m_bUseFloodProtection)
        {
            // Process request monitors
            m_mMonitors[sIPAddress].processOut();
        }

        unlock();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the header of a HTTP request parsed from \a sText.
*/
QString CHTTPServer::getRequestHeader(const QString& sText)
{
    // In order to locate the header's termination, we look for a double new line, ie either "\n\n" or "\r\n\r\n"

    int iPos = sText.indexOf("\n\n");

    if (iPos > 0)
    {
        iPos += 2;
    }
    else
    {
        iPos = sText.indexOf("\r\n\r\n");

        if (iPos > 0)
        {
            iPos += 4;
        }
    }

    if (iPos > 0)
    {
        return sText.left(iPos);
    }

    return sText;
}

//-------------------------------------------------------------------------------------------------

/*!
    Parses the requested resource and arguments. \br\br
    \a lTokens contains the request tokens. \br
    \a lPath will be filled the requested resource. \br
    \a mArguments will be filled with the requested arguments.
*/
void CHTTPServer::getRequestPathAndArgs(const QStringList& lTokens, QStringList& lPath, QMap<QString, QString>& mArguments)
{
    // The path immediately follows the GET or POST token

    if (lTokens.count() > 0)
    {
        QStringList lGetAndPath = lTokens[0].split(" ");

        if (lGetAndPath.count() > 1)
        {
            QStringList lPathAndArgs = lGetAndPath[1].split("?");

            // Split the path and get its components

            if (lPathAndArgs.count() > 0)
            {
                lPath = lPathAndArgs[0].split("/", QString::SkipEmptyParts);
            }

            if (lPathAndArgs.count() > 1)
            {
                // Get the arguments

                QStringList lArgs = lPathAndArgs[1].split("&");

                foreach(QString sArg, lArgs)
                {
                    QStringList lCurrentArg = sArg.split("=");

                    if (lCurrentArg.count() > 1)
                    {
                        mArguments[lCurrentArg[0]] = lCurrentArg[1];
                    }
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Gets the post content from a request header. \br\br
    \a sText contains the request. \br
    \a baContent will be filled the post content.
*/
void CHTTPServer::getRequestPostContent(const QString& sText, QByteArray& baContent)
{
    // In order to locate the POST content's termination, we look for a double new line, ie either "\n\n" or "\r\n\r\n"

    // if (sText.contains(Token_ContentLength))
    {
        int iPos = sText.indexOf("\n\n");

        if (iPos > 0)
        {
            iPos += 2;
        }
        else
        {
            iPos = sText.indexOf("\r\n\r\n");

            if (iPos > 0)
            {
                iPos += 4;
            }
        }

        if (iPos > 0)
        {
            QString sContent = sText.mid(iPos);
            baContent = sContent.toLatin1();
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value associated with a token. \br\br
    \a lTokens contains the token list. \br
    \a sTokenName contains the name of the value to return.
*/
QString CHTTPServer::getTokenValue(const QStringList& lTokens, QString sTokenName)
{
    QString sReturnValue;

    foreach (QString sToken, lTokens)
    {
        if (sToken.startsWith(sTokenName))
        {
            QStringList split = sToken.split(sTokenName, QString::SkipEmptyParts);

            if (split.count() > 0)
            {
                sReturnValue = split[0];
            }
        }
    }

    return sReturnValue.trimmed();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value associated with a sub-token. \br\br
    \a lTokens contains the token list. \br
    \a sTokenName. \br
    \a sSubTokenName contains the name of the value to return.
*/
QString CHTTPServer::getSubTokenValue(const QStringList& lTokens, QString sTokenName, QString sSubTokenName)
{
    QString sReturnValue;

    foreach (QString sToken, lTokens)
    {
        if (sToken.startsWith(sTokenName))
        {
            QStringList split = sToken.split(sTokenName, QString::SkipEmptyParts);

            if (split.count() > 0)
            {
                sReturnValue = split[0];
                break;
            }
        }
    }

    if (sReturnValue.isEmpty() == false)
    {
        QStringList lSubTokens = sReturnValue.split(";", QString::SkipEmptyParts);

        foreach (QString sSubToken, lSubTokens)
        {
            sSubToken = sSubToken.trimmed();

            if (sSubToken.startsWith(sSubTokenName))
            {
                QStringList lSubTokenNameValue = sSubToken.split("=", QString::SkipEmptyParts);

                if (lSubTokenNameValue.count() > 1)
                {
                    sReturnValue = lSubTokenNameValue[1];
                    break;
                }
            }
        }
    }

    sReturnValue = sReturnValue.trimmed();

    if (sReturnValue.startsWith("\"") && sReturnValue.endsWith("\""))
    {
        sReturnValue = sReturnValue.mid(1);
        sReturnValue.chop(1);
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the content type associated with a file extension. \br\br
    \a sExtention contains the extension.
*/
QString CHTTPServer::getContentTypeByExtension(const QString& sExtention) const
{
    QString sLowerExtention = sExtention.toLower();

    if (m_vExtensionToContentType.contains(sLowerExtention))
    {
        return m_vExtensionToContentType[sLowerExtention];
    }

    return MIME_Content_Stream;
}

//-------------------------------------------------------------------------------------------------

/*!
    Activates or deactivates flood protection according to \a bUse.
*/
void CHTTPServer::useFloodProtection(bool bUse)
{
    m_bUseFloodProtection = bUse;
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a folder to the list of authorized folders. \br\br
    \a sFolderName contains the name of the folder to add.
*/
void CHTTPServer::addAuthorizedFolder(QString sFolderName)
{
    if (m_vAuthorizedFolders.contains(sFolderName) == false)
    {
        m_vAuthorizedFolders.append(sFolderName);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Pauses the server. \br\br
    When paused, the server will not serve any request.
*/
void CHTTPServer::pause()
{
    m_bDisabled = true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Resumes the server. \br\br
    When not paused, the server will serve requests.
*/
void CHTTPServer::resume()
{
    m_bDisabled = false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if safe access to data is OK (data is locked).
*/
bool CHTTPServer::lock()
{
    if (m_mMutex.tryLock(2000))
    {
        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Unlocks access to data.
*/
void CHTTPServer::unlock()
{
    m_mMutex.unlock();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the resource identified by the \c m_lPath member of \a tContext was written to \a pSocket.
*/
bool CHTTPServer::getResponseFile(const CWebContext& tContext, QTcpSocket* pSocket)
{
    // Process only if the socket is in connected state
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        if (tContext.m_lPath.count() > 0)
        {
            bool bAuthorized = false;

            // Check access right to the directory
            foreach (QString sAuthorizedFolder, m_vAuthorizedFolders)
            {
                if (sAuthorizedFolder == tContext.m_lPath[0])
                {
                    bAuthorized = true;
                    break;
                }
            }

            // Create the file name on disk
            QString sFileName = QCoreApplication::applicationDirPath();

            foreach (QString sPathName, tContext.m_lPath)
            {
                sFileName += "/" + sPathName;
            }

            // Does the file exist on disk?
            if (QFile::exists(sFileName))
            {
                // Is the access authorized?
                if (bAuthorized)
                {
                    QFile tFile(sFileName);

                    // Open the file for reading and send it
                    if (tFile.open(QIODevice::ReadOnly))
                    {
                        QString sType = getContentTypeByExtension(sFileName.split(".").last());

                        QByteArray baData;

                        baData.append(HTTP_HEADER);
                        baData.append(HTTP_200_OK);
                        baData.append(HTML_NL);
                        baData.append(Token_ContentType);
                        baData.append(" ");
                        baData.append(sType.toLatin1());
                        baData.append("; charset=\"utf-8\"");
                        baData.append(HTML_NL);
                        baData.append(Token_ContentLength);
                        baData.append(QString(" %1").arg(tFile.size()).toLatin1());
                        baData.append(HTML_NL);
                        baData.append(HTML_NL);
                        baData.append(tFile.readAll());

                        pSocket->write(baData);

                        tFile.close();

                        return true;
                    }
                }
                else
                {
                    // Send a FORBIDDEN response to the client
                    QByteArray baHTML;
                    QByteArray baData;

                    baHTML.append("<!doctype html>\r\n");
                    baHTML.append("<html>"HTML_NL);
                    baHTML.append("<body>"HTML_NL);
                    baHTML.append(QString("%1").arg(HTTP_403_FORBIDDEN));
                    baHTML.append("</body>"HTML_NL);
                    baHTML.append("</html>"HTML_NL);

                    baData.append(HTTP_HEADER);
                    baData.append(HTTP_403_FORBIDDEN);
                    baData.append(HTML_NL);
                    baData.append(Token_ContentType);
                    baData.append(" ");
                    baData.append(MIME_Content_HTML);
                    baData.append("; charset=\"utf-8\"");
                    baData.append(HTML_NL);
                    baData.append(Token_ContentLength);
                    baData.append(QString(" %1").arg(baHTML.count()));
                    baData.append(HTML_NL);
                    baData.append(HTML_NL);
                    baData.append(baHTML);

                    pSocket->write(baData);

                    return true;
                }
            }
        }
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if dynamic content was generated and sent to \a pSocket. \br\br
    \a tContext contains contextual information for the content generator.
*/
bool CHTTPServer::getResponseDynamicContent(const CWebContext& tContext, QTcpSocket* pSocket)
{
    QString sHead;
    QString sBody;
    QString sCustomResponse;
    QString sCustomResponseMIME;

    // Appel de la méthode virtuelle pour remplir la page
    getContent(tContext, sHead, sBody, sCustomResponse, sCustomResponseMIME);

    // On ne traite que si la socket est en état connecté
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        // Au cas où la réponse customisée est non-vide, on l'envoie tel quel au client
        if (sCustomResponse.isEmpty() == false && sCustomResponseMIME == MIME_Content_Custom)
        {
            QByteArray baData;

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(sCustomResponse);

            pSocket->write(baData);

            return true;
        }
        // Sinon, si la réponse au format XML est non-vide, c'est elle qu'on envoie au client
        else if (sCustomResponse.isEmpty() == false)
        {
            QByteArray baData;
            QByteArray utf8Response = sCustomResponse.toUtf8();

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(HTML_NL);
            baData.append(QString("%1 %2; charset=\"utf-8\"").arg(Token_ContentType).arg(sCustomResponseMIME));
            baData.append(HTML_NL);
            baData.append(QString("%1 %2").arg(Token_ContentLength).arg(utf8Response.count()));
            baData.append(HTML_NL);
            baData.append(HTML_NL);
            baData.append(utf8Response);

            pSocket->write(baData);
        }
        // Sinon, les contenus HTML de sHead et sBody sont retournés au client
        else
        {
            // Streaming de la page

            QByteArray baHTML;
            QByteArray baData;

            baHTML.append("<!doctype html>"HTML_NL);
            baHTML.append("<html>"HTML_NL);
            baHTML.append("<head>"HTML_NL);
            baHTML.append(sHead);
            baHTML.append("</head>"HTML_NL);
            baHTML.append("<body>"HTML_NL);
            baHTML.append(sBody);
            baHTML.append("</body>"HTML_NL);
            baHTML.append("</html>"HTML_NL);

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(HTML_NL);
            baData.append(QString("%1 %2; charset=\"utf-8\"").arg(Token_ContentType).arg(MIME_Content_HTML));
            baData.append(HTML_NL);
            baData.append(QString("%1 %2").arg(Token_ContentLength).arg(baHTML.count()));
            baData.append(HTML_NL);
            baData.append(HTML_NL);
            baData.append(baHTML);

            pSocket->write(baData);
        }
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

/*!
    This method returns dynamic content. It is meant to be overridden by subclasses. \br\br
    \a tContext contains contextual information for the content generator (the associated socket, resource path, arguments, ...) \br
    \a sHead can be filled with the HTML page header. \br
    \a sBody can be filled with the HTML page body. \br
    If \a sCustomResponse and \a sCustomResponseMIME are filled, it will override \a sHead and \a sBody and will be sent as is.
*/
void CHTTPServer::getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME)
{
    Q_UNUSED(tContext);
    Q_UNUSED(sHead);
    Q_UNUSED(sBody);
    Q_UNUSED(sCustomResponse);

    // Cette méthode est à implémenter par une sous-classe pour générer du contenu dynamique
    // Soit en remplissant sCustomResponse par du texte quelconque
    // Soit en en remplissant xmlResponse par du contenu XML
    // Soit en remplissant sHead et sBody par du contenu HTML
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react to a socket being disconnected. \br\br
    \a pSocket contains the disconnected socket. \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketDisconnection(QTcpSocket* pSocket)
{
    Q_UNUSED(pSocket);

    // Cette méthode peut être implémentée par une sous-classe pour réagir
    // lors de la déconnexion d'un client
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react when bytes have been written to a socket. \br\br
    \a pSocket contains the socket. \br
    \a iBytes contains the number of bytes written. \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketBytesWritten(QTcpSocket* pSocket, qint64 iBytes)
{
    Q_UNUSED(pSocket);
    Q_UNUSED(iBytes);

    // Cette méthode peut être implémentée par une sous-classe pour réagir
    // lorsque des octets sont envoyés à un client
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react when bytes are ready to be read from a socket. \br\br
    \a pSocket contains the socket. \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketBytesRead(QTcpSocket* pSocket)
{
    Q_UNUSED(pSocket);

    // Cette méthode peut être implémentée par une sous-classe pour réagir
    // lorsque des octets sont envoyés à un client
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string where ASCII entities are replaced with their URL couterpart. \br\br
    \a sText contains the text to process.
    \note Exemple: ' ' becomes '%20', '?' becomes '%3F'
*/
QString CHTTPServer::encodeURLParameters(QString sText)
{
    return sText
        .replace(" ", "%20")
        .replace("\r", "%0A")
        .replace("\n", "%0D")
        .replace("?", "%3F")
        .replace("*", "%2A")
        .replace("\"", "%22");
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string where URL entities are replaced with their ASCII couterpart. \br\br
    \a sText contains the text to process.
    \note Exemple: '%20' becomes ' ', '%3F' becomes '?'
*/
QString CHTTPServer::decodeURLParameters(QString sText)
{
    return sText
            .replace("%20", " ")
            .replace("%0A", "\r")
            .replace("%0D", "\n")
            .replace("%3F", "?")
            .replace("%2A", "*")
            .replace("%22", "\"");
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the IP address in \a sText stripped out of any garbage
*/
QString CHTTPServer::cleanIP(const QString& sText)
{
    QString sReturnValue = sText;
    QRegExp tRegExp_ipv6("([A-Fa-f0-9]{1,4}::?){1,7}[A-Fa-f0-9]{1,4}");
    QRegExp tRegExp_ipv4(".*([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}).*");

    if (tRegExp_ipv6.indexIn(sText) != -1)
    {
        sReturnValue = tRegExp_ipv6.cap(0);
    }
    else if (tRegExp_ipv4.indexIn(sText) != -1)
    {
        sReturnValue = tRegExp_ipv4.cap(1);
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Logs a request. \br\br
    \a sIP contains the IP that sent the request. \br
    \a sText contains the request line.
*/
void CHTTPServer::LogRequest(QString sIP, QString sText)
{
    // Read tokens
    QStringList lTokens = sText.split(QRegExp("[ \n][ \n]*"));

    if (lTokens.count() > 1)
    {
        qDebug() << QString("%1 : %2 : %3")
                    .arg(sIP)
                    .arg(lTokens[0])
                .arg(lTokens[1]);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    \fn CHTTPServer::CClientData::CClientData(QTcpSocket* pSocket)

    Constructs a CClientData using \a pSocket.
*/

/*!
    \fn CClientData* CHTTPServer::CClientData::getFromSocket(QTcpSocket* pSocket)

    Returns the CClientData object that has been attached to \a pSocket.
*/

/*!
    \fn void CHTTPServer::CClientData::deleteFromSocket(QTcpSocket* pSocket)

    Deletes the CClientData object that has been attached to \a pSocket.
*/
