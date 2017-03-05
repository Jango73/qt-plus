
// Qt
#include <QDateTime>
#include <QCoreApplication>
#include <QFile>

// Application
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

// #define DEBUG_RECORD_REQUESTS

//-------------------------------------------------------------------------------------------------

/*!
    \class CHTTPServer
    \inmodule qt-plus
    \brief A simple HTTP server that can serve files and dynamic content.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CHTTPServer with a binding port equal to \a port. \br\br
    \a parent is the owner of this object.
*/
CHTTPServer::CHTTPServer(quint16 port, QObject* parent)
    : QTcpServer(parent)
    , m_iRequestCount(0)
    , m_bDisabled(false)
{
    // Remplissage du tableau des types MIME

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

    // Ecoute du port

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

    pSocket->setReadBufferSize(20000);

    // Création des données utilisateurs
    // Pas besoin de stocker la valeur de retour, elle est placée dans les propriétés de la socket
    new CClientData(pSocket);

    // Connexion des signaux
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(pSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketBytesWritten(qint64)));
    connect(pSocket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
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
    // Récupération de l'objet émetteur du signal
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    // Est-ce que la socket est valide?
    if (pSocket != NULL)
    {
        // Si le serveur est désactivé, on libére la socket et les données utilisateur associées
        if (m_bDisabled)
        {
            CClientData::deleteFromSocket(pSocket);
            pSocket->disconnect();
            pSocket->deleteLater();
            return;
        }

        // Récupération des données utilisateurs associées à la socket
        CClientData* pData = CClientData::getFromSocket(pSocket);

        if (pData != NULL)
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
                        // L'entête n'a pas été lue
                        pData->m_bHeaderRead = false;

                        // On exécute la requête du client
                        processRequest(pSocket);
                    }
                }
                else
                if (pData->m_iExpectedBytes <= 0)
                {
                    // L'entête n'a pas été lue
                    pData->m_bHeaderRead = false;

                    // On exécute la requête du client
                    processRequest(pSocket);
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

    // Log de la requête
    LogRequest(pSocket->peerAddress().toString(), QString(pData->m_baBuffer));

#ifdef DEBUG_RECORD_REQUESTS
    QFile outFile(QString("Request_%1.txt").arg(QString::number(m_iRequestCount)));
    if (outFile.open(QFile::WriteOnly))
    {
        outFile.write(pData->m_baBuffer);
        outFile.close();
    }
#endif

    if (pData != NULL)
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
            // Pour l'instant, seul GET et POST son traités
            if (lTokens[0].startsWith(HTTP_GET) || lTokens[0].startsWith(HTTP_POST))
            {
                // GET Example :
                //-----------------------------------------------------------
                // GET /drivers HTTP/1.1
                // Host: 127.0.0.1:9991
                // Connection: keep-alive
                // Cache-Control: max-age=0
                // Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
                // User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.153 Safari/537.36
                // Referer: http://127.0.0.1:9991/drivers
                // Accept-Encoding: gzip,deflate,sdch
                // Accept-Language: fr-FR,fr;q=0.8,en-US;q=0.6,en;q=0.4
                //-----------------------------------------------------------

                // POST Example :
                //-----------------------------
                // POST /drivers HTTP/1.1
                // Host: 127.0.0.1:9991
                // Connection: keep-alive
                // Cache-Control: max-age=0
                // Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
                // User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.153 Safari/537.36
                // Referer: http://127.0.0.1:9991/drivers
                // Accept-Encoding: gzip,deflate,sdch
                // Accept-Language: fr-FR,fr;q=0.8,en-US;q=0.6,en;q=0.4
                // Content-Type: application/x-www-form-urlencoded
                // Content-Length: 30
                // username=zurfyx&pass=password
                //-----------------------------------------------------------

                // form-data Example:
                //-----------------------------
                // POST /?action=upload HTTP/1.1
                // Host: 127.0.0.1:5050
                // User-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0
                // Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
                // Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;q=0.3
                // Accept-Encoding: gzip, deflate
                // Referer: http://127.0.0.1:5050/
                // Content-Length: 2178
                // Content-Type: multipart/form-data; boundary=---------------------------107122896830180
                // Connection: keep-alive
                // Pragma: no-cache
                // Cache-Control: no-cache
                //
                // -----------------------------107122896830180
                // Content-Disposition: form-data; name="upload_file"; filename="DrawRectangle.xml"
                // Content-Type: text/xml
                //
                // <?xml version="1.0" encoding="UTF-8"?>
                // <Node Name="Unnamed" UseReferences="0" UseThread="0" Class="QNodeGroup">
                //  <Position X="0" Y="0"/>
                //  <Size X="3164" Y="1488"/>
                // </Node>
                //
                // -----------------------------107122896830180--
                //

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
                CWebContext tContext(pSocket, pSocket->peerAddress().toString(), sHost, lPath, mArguments);

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

    m_iRequestCount++;
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
    Returns \c true if the resource identified by the \c m_lPath member of \a tContext was written to \a pSocket.
*/
bool CHTTPServer::getResponseFile(const CWebContext& tContext, QTcpSocket* pSocket)
{
    // On ne traite que si la socket est en état connecté
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        if (tContext.m_lPath.count() > 0)
        {
            bool bAuthorized = false;

            // Vérification du droit d'accès au répertoire
            foreach (QString sAuthorizedFolder, m_vAuthorizedFolders)
            {
                if (sAuthorizedFolder == tContext.m_lPath[0])
                {
                    bAuthorized = true;
                    break;
                }
            }

            // Composition du nom de fichier sur disque
            QString sFileName = QCoreApplication::applicationDirPath();

            foreach (QString sPathName, tContext.m_lPath)
            {
                sFileName += "/" + sPathName;
            }

            // Est-ce que le fichier existe sur disque?
            if (QFile::exists(sFileName))
            {
                // Est-ce que son accès est autorisé
                if (bAuthorized)
                {
                    QFile tFile(sFileName);

                    // On ouvre le fichier est on l'envoie après un header de réponse HTTP
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
                    // On envoie au client une réponse d'erreur : accès interdit
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
    QString sXMLResponse;
    QString sCustomResponse;

    // Appel de la méthode virtuelle pour remplir la page
    getContent(tContext, sHead, sBody, sXMLResponse, sCustomResponse);

    // On ne traite que si la socket est en état connecté
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        // Au cas où la réponse customisée est non-vide, on l'envoie tel quel au client
        if (sCustomResponse.isEmpty() == false)
        {
            QByteArray baData;

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(sCustomResponse);

            pSocket->write(baData);

            return true;
        }
        // Sinon, si la réponse au format XML est non-vide, c'est elle qu'on envoie au client
        else if (sXMLResponse.isEmpty() == false)
        {
            QByteArray baData;

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(HTML_NL);
            baData.append(QString("%1 %2; charset=\"utf-8\"").arg(Token_ContentType).arg(MIME_Content_XML));
            baData.append(HTML_NL);
            baData.append(QString("%1 %2").arg(Token_ContentLength).arg(sXMLResponse.size()));
            baData.append(HTML_NL);
            baData.append(HTML_NL);
            baData.append(sXMLResponse);

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
    If \a xmlResponse is filled, it will override \a sHead and \a sBody and will be sent as is. \br
    If \a sCustomResponse is filled, it will override \a sHead, \a sBody and \a xmlResponse and will be sent as is.
*/
void CHTTPServer::getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse, QString& sCustomResponse)
{
    Q_UNUSED(tContext);
    Q_UNUSED(sHead);
    Q_UNUSED(sBody);
    Q_UNUSED(xmlResponse);
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
    Logs a request. \br\br
    \a sIP contains the IP that sent the request. \br
    \a sText contains the request line.
*/
void CHTTPServer::LogRequest(QString sIP, QString sText)
{
    // Récupération des tokens
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
