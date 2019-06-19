
// Qt
#include <QCoreApplication>
#include <QFile>

// Application
#include "CHTTPRequestProcessor.h"
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

// #define DEBUG_RECORD_REQUESTS

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CHTTPRequestProcessor
*/
CHTTPRequestProcessor::CHTTPRequestProcessor(CHTTPServer* pServer, qintptr iSocketDescriptor)
    : m_bStop(false)
    , m_bHeaderRead(false)
    , m_iExpectedBytes(0)
    , m_iSocketDescriptor(iSocketDescriptor)
    , m_mMutex(QMutex::Recursive)
    , m_pServer(pServer)
    , m_pSocket(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CHTTPRequestProcessor.
*/
CHTTPRequestProcessor::~CHTTPRequestProcessor()
{
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QVariant>& CHTTPRequestProcessor::userData()
{
    return m_mUserData;
}

//-------------------------------------------------------------------------------------------------

void CHTTPRequestProcessor::run()
{
    m_pSocket = new QTcpSocket();

    if (m_pSocket->setSocketDescriptor(m_iSocketDescriptor))
    {
        QString sIPAddress = CHTTPServer::cleanIP(m_pSocket->peerAddress().toString());

        m_pSocket->setReadBufferSize(1024 * 20);

        // Connect signals
        connect(m_pSocket, &QTcpSocket::readyRead, this, &CHTTPRequestProcessor::onSocketReadyRead, Qt::DirectConnection);
        connect(m_pSocket, &QTcpSocket::bytesWritten, this, &CHTTPRequestProcessor::onSocketBytesWritten);
        connect(m_pSocket, &QTcpSocket::disconnected, this, &CHTTPRequestProcessor::onSocketDisconnected);

        while (m_bStop == false)
        {
            msleep(10);
            QCoreApplication::processEvents();
        }

        m_pSocket->disconnect();
    }

    m_pSocket->deleteLater();
}

//-------------------------------------------------------------------------------------------------

void CHTTPRequestProcessor::stopMe()
{
    m_bStop = true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles a socket disconnection. \br\br
    Calls the handleSocketDisconnection() method.
*/
void CHTTPRequestProcessor::onSocketDisconnected()
{
    CWebContext tContext(m_pSocket, m_mUserData);

    // Call the socket disconnected handler
    m_pServer->handleSocketDisconnection(tContext);

    stopMe();
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles data reading when a socket emits the readyRead signal. \br\br
    Calls the handleSocketBytesRead() method.
*/
void CHTTPRequestProcessor::onSocketReadyRead()
{
    QString sIPAddress = CHTTPServer::cleanIP(m_pSocket->peerAddress().toString());

    // If the connection is rejected, free socket
    if (m_pServer->monitors()[sIPAddress].shouldBeBlocked())
    {
        stopMe();
        return;
    }

    // Is the socket valid?
    if (m_pSocket != nullptr)
    {
        // If the server is disabled, free socket and its client data
        if (m_pServer->disabled())
        {
            stopMe();
            return;
        }

        // Is the socket in connected state?
        if (m_pSocket->state() == QTcpSocket::ConnectedState)
        {
            // Read all available data
            QByteArray baData = m_pSocket->readAll();

            // Add incoming bytes to buffer
            m_baBuffer.append(baData);

            // Did we read the header yet?
            if (m_bHeaderRead == false)
            {
                // Get the header tokens
                QStringList lTokens = getHeaderTokens(baData);

                m_bHeaderRead = true;
                m_iExpectedBytes = getHeaderLength(baData) + getExpectedBytes(lTokens);

                // Get the content type
                QString sContentType = getTokenValue(lTokens, Token_ContentType);

                if (sContentType.startsWith(MIME_Content_MultiPart))
                {
                    m_sMultipartBoundary = getSubTokenValue(lTokens, Token_ContentType, Token_boundary);
                }
            }

            // Decrease expected bytes
            m_iExpectedBytes -= baData.count();

            if (m_sMultipartBoundary.isEmpty() == false)
            {
                QString sText = QString(baData);
                QString sClosingBoundary = QString("--%1--").arg(m_sMultipartBoundary);

                if (sText.contains(sClosingBoundary))
                {
                    // Mark header as not read
                    m_bHeaderRead = false;

                    // Execute the client request
                    if (m_pServer->monitors()[sIPAddress].shouldBeBlocked() == false)
                    {
                        processRequest();
                    }
                }
            }
            else
            if (m_iExpectedBytes <= 0)
            {
                // Mark header as not read
                m_bHeaderRead = false;

                // Execute the client request
                if (m_pServer->monitors()[sIPAddress].shouldBeBlocked() == false)
                {
                    processRequest();
                }
            }
        }
        else
        {
            CWebContext tContext(m_pSocket, m_mUserData);

            // Call the bytes read handler
            m_pServer->handleSocketBytesRead(tContext, 0);

            // Get back user data in case it was modified
            m_mUserData = tContext.m_mUserData;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles the bytesWritten signal of a socket. \br\br
    \a iBytes contains the number of written bytes. \br\br
    Calls the handleSocketBytesWritten() method.
*/
void CHTTPRequestProcessor::onSocketBytesWritten(qint64 iBytes)
{
    CWebContext tContext(m_pSocket, m_mUserData);

    // Call the bytes written handler
    m_pServer->handleSocketBytesWritten(tContext, iBytes);

    // Get back user data in case it was modified
    m_mUserData = tContext.m_mUserData;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the length of a HTTP header. \br\br
    \a baData contains the header.
*/
int CHTTPRequestProcessor::getHeaderLength(QByteArray baData)
{
    QStringList lReturnValue;
    QString sText(baData);

    // Get the header
    QString sHeader = getRequestHeader(sText);

    return sHeader.count();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the tokens in a HTTP header. \br\br
    \a baData contains the header.
*/
QStringList CHTTPRequestProcessor::getHeaderTokens(QByteArray baData)
{
    QStringList lReturnValue;
    QString sText(baData);

    // Get the header
    QString sHeader = getRequestHeader(sText);

    // Split the string
    lReturnValue = sHeader.split(QRegExp("[\r\n][\r\n]*"));

    return lReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of expected bytes to follow a HTTP header. \br\br
    \a lTokens contains the header tokens.
*/
int CHTTPRequestProcessor::getExpectedBytes(QStringList lTokens)
{
    int iExpectedBytes = 0;

    if (lTokens.count() > 0)
    {
        if (lTokens[0].startsWith(HTTP_POST))
        {
            // Get the content type
            QString sContentType = getTokenValue(lTokens, Token_ContentType);

            // Get the content length
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
void CHTTPRequestProcessor::processRequest()
{
    QString sIPAddress = CHTTPServer::cleanIP(m_pSocket->peerAddress().toString());

    // Log the request
    m_pServer->LogRequest(sIPAddress, QString(m_baBuffer));

    // Tell the server a request processing is starting
    m_pServer->requestStart(sIPAddress);

#ifdef DEBUG_RECORD_REQUESTS
    QFile outFile(QString("Request_%1.txt").arg(QString::number(m_iRequestCount)));
    if (outFile.open(QFile::WriteOnly))
    {
        outFile.write(m_baBuffer);
        outFile.close();
    }
#endif

    bool bKeepAlive = false;

    QString sText(m_baBuffer);
    QStringList lTokens = getHeaderTokens(m_baBuffer);

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
            CWebContext tContext(
                        m_pSocket,
                        sIPAddress,
                        sHost,
                        lPath,
                        mArguments,
                        m_mUserData
                        );

            if (sContentType.startsWith(MIME_Content_URLForm))
            {
                QStringList lArgs = QString(baPostContent).split("&");

                for (QString sArg : lArgs)
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
                if (m_sMultipartBoundary.isEmpty() == false)
                {
                    QString sActualBoundary = QString("--%1").arg(m_sMultipartBoundary);
                    QString sContent = QString(baPostContent);
                    QStringList lParts = sContent.split(sActualBoundary);

                    if (lParts.count() > 0)
                    {
                        int iIndex = 0;

                        for (QString sPart : lParts)
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

            // If a file exists for the requested path, return it
            // Else return generated content
            if (getResponseFile(tContext, m_pSocket) == true)
            {
            }
            else
            {
                bForceKeepAlive = getResponseDynamicContent(tContext, m_pSocket);
            }

            // Get back user data in case it was modified
            m_mUserData = tContext.m_mUserData;
        }
        else
        {
        }
    }
    else
    {
        qWarning() << QString("CHTTPRequestProcessor::processRequest() : No token to read");
    }

    // Clear the input buffers of the socket
    m_baBuffer.clear();
    m_sMultipartBoundary.clear();

    // If the socket is still connected...
    if (m_pSocket->state() == QAbstractSocket::ConnectedState)
    {
        // Flush the socket's output
        m_pSocket->flush();

        // In case we don't have a keep-alive connection, free the socket and its user data
        if (bKeepAlive == false && bForceKeepAlive == false)
        {
            stopMe();
        }
    }
    else
    {
        qWarning() << QString("CHTTPRequestProcessor::processRequest() : Socket is not in connected state");
    }

    // Tell the server a request processing is ending
    m_pServer->requestEnd(sIPAddress);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the header of a HTTP request parsed from \a sText.
*/
QString CHTTPRequestProcessor::getRequestHeader(const QString& sText)
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
void CHTTPRequestProcessor::getRequestPathAndArgs(const QStringList& lTokens, QStringList& lPath, QMap<QString, QString>& mArguments)
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

                for (QString sArg : lArgs)
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
void CHTTPRequestProcessor::getRequestPostContent(const QString& sText, QByteArray& baContent)
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
QString CHTTPRequestProcessor::getTokenValue(const QStringList& lTokens, QString sTokenName)
{
    QString sReturnValue;

    for (QString sToken : lTokens)
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
QString CHTTPRequestProcessor::getSubTokenValue(const QStringList& lTokens, QString sTokenName, QString sSubTokenName)
{
    QString sReturnValue;

    for (QString sToken : lTokens)
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

        for (QString sSubToken : lSubTokens)
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
    Returns \c true if safe access to data is OK (data is locked).
*/
bool CHTTPRequestProcessor::lock()
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
void CHTTPRequestProcessor::unlock()
{
    m_mMutex.unlock();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the resource identified by the \c m_lPath member of \a tContext was written to \a pSocket.
*/
bool CHTTPRequestProcessor::getResponseFile(CWebContext& tContext, QTcpSocket* pSocket)
{
    // Process only if the socket is in connected state
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        if (tContext.m_lPath.count() > 0)
        {
            bool bAuthorized = false;

            // Check access right to the directory
            for (QString sAuthorizedFolder : m_pServer->authorizedFolders())
            {
                if (sAuthorizedFolder == tContext.m_lPath[0])
                {
                    bAuthorized = true;
                    break;
                }
            }

            // Create the file name on disk
            QString sFileName = QCoreApplication::applicationDirPath();

            for (QString sPathName : tContext.m_lPath)
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
                        QString sType = m_pServer->getContentTypeByExtension(sFileName.split(".").last());

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
                    baHTML.append("<html>" HTML_NL);
                    baHTML.append("<body>" HTML_NL);
                    baHTML.append(QString("%1").arg(HTTP_403_FORBIDDEN));
                    baHTML.append("</body>" HTML_NL);
                    baHTML.append("</html>" HTML_NL);

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
bool CHTTPRequestProcessor::getResponseDynamicContent(CWebContext& tContext, QTcpSocket* pSocket)
{
    QString sHead;
    QString sBody;
    QString sCustomResponse;
    QString sCustomResponseMIME;

    // Call the getContent method of the server
    m_pServer->getContent(tContext, sHead, sBody, sCustomResponse, sCustomResponseMIME);

    // Process only if the socket is in connected state
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        // In case the custom response is not empty, send it as-is to the client
        if (sCustomResponse.isEmpty() == false && sCustomResponseMIME == MIME_Content_Custom)
        {
            QByteArray baData;

            baData.append(HTTP_HEADER);
            baData.append(HTTP_200_OK);
            baData.append(sCustomResponse.toUtf8());

            pSocket->write(baData);

            return true;
        }
        // Else if the xml response is not empty, send it to the client
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
        // Else the HTML content of sHead and sBody are returned to the client
        else
        {
            // Streaming de la page

            QByteArray baHTML;
            QByteArray baData;

            baHTML.append("<!doctype html>" HTML_NL);
            baHTML.append("<html>" HTML_NL);
            baHTML.append("<head>" HTML_NL);
            baHTML.append(sHead.toUtf8());
            baHTML.append("</head>" HTML_NL);
            baHTML.append("<body>" HTML_NL);
            baHTML.append(sBody.toUtf8());
            baHTML.append("</body>" HTML_NL);
            baHTML.append("</html>" HTML_NL);

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
