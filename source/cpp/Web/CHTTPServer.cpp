
// Qt
#include <QCoreApplication>
#include <QFile>

// Application
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CHTTPServer
    \inmodule qt-plus
    \brief A basic HTTP server that can serve files and dynamic content.

    \section1 How it works
    This server listens to and processes HTTP requests on a specified port. \br
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

        virtual void getContent(CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME)
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
CHTTPServer::CHTTPServer(quint16 uiPort, QObject* parent)
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
    if (uiPort > 0)
    {
        if (!listen(QHostAddress::Any, uiPort))
        {
            qWarning() << QString("CHTTPServer::CHTTPServer() : bind to %1 failed").arg(uiPort);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CHTTPServer.
*/
CHTTPServer::~CHTTPServer()
{
    // Kill threads
    for (CHTTPRequestProcessor* pProcessor : m_vProcessors)
    {
        pProcessor->stopMe();
        pProcessor->deleteLater();
    }

    // Close the server
    close();
}

//-------------------------------------------------------------------------------------------------

bool CHTTPServer::disabled() const
{
    return m_bDisabled;
}

//-------------------------------------------------------------------------------------------------

const QVector<QString>& CHTTPServer::authorizedFolders() const
{
    return m_vAuthorizedFolders;
}

//-------------------------------------------------------------------------------------------------

const QMap<QString, CHTTPServer::CRequestMonitor>& CHTTPServer::monitors() const
{
    return m_mMonitors;
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

bool CHTTPServer::passBlackListing(QString sIPAddress)
{
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
        qWarning() << QString("Blacklisting %1").arg(sIPAddress);

        // Blacklist and reject this connection
        m_lDynamicIPBlackList << sIPAddress;

        bRejected = true;
    }

    return !bRejected;
}

//-------------------------------------------------------------------------------------------------

void CHTTPServer::requestStart(QString sIPAddress)
{
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
}

//-------------------------------------------------------------------------------------------------

void CHTTPServer::requestEnd(QString sIPAddress)
{
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
    Logs a request. \br\br
    \a sIP contains the IP that sent the request. \br
    \a sText contains the request line.
*/
void CHTTPServer::LogRequest(QString sIP, QString sText)
{
    if (lock())
    {
        // Read tokens
        QStringList lTokens = sText.split(QRegExp("[ \n][ \n]*"));

        if (lTokens.count() > 2)
        {
            qDebug() << QString("%1 : %2 : %3 : %4")
                        .arg(sIP)
                        .arg(lTokens[0])
                    .arg(lTokens[1])
                    .arg(lTokens[2]);
        }

        unlock();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    This method returns dynamic content. It is meant to be overridden by subclasses. \br\br
    \a tContext contains contextual information for the content generator (the associated socket, resource path, arguments, ...) \br
    \a sHead can be filled with the HTML page header. \br
    \a sBody can be filled with the HTML page body. \br
    If \a sCustomResponse and \a sCustomResponseMIME are filled, it will override \a sHead and \a sBody and will be sent as is.
*/
void CHTTPServer::getContent(CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME)
{
    Q_UNUSED(tContext);
    Q_UNUSED(sHead);
    Q_UNUSED(sBody);
    Q_UNUSED(sCustomResponse);
    Q_UNUSED(sCustomResponseMIME);
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react to a socket being disconnected. \br\br
    \a tContext contains contextual information (socket, ...) \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketDisconnection(CWebContext& tContext)
{
    Q_UNUSED(tContext);
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react when bytes have been written to a socket. \br\br
    \a tContext contains contextual information (socket, ...) \br\br
    \a iBytes contains the number of bytes written. \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketBytesWritten(CWebContext& tContext, qint64 iBytes)
{
    Q_UNUSED(tContext);
    Q_UNUSED(iBytes);
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react when bytes are ready to be read from a socket. \br\br
    \a tContext contains contextual information (socket, ...) \br\br
    \a iBytes contains the number of bytes read. \br\br
    The default implementation does nothing.
*/
void CHTTPServer::handleSocketBytesRead(CWebContext& tContext, qint64 iBytes)
{
    Q_UNUSED(tContext);
    Q_UNUSED(iBytes);
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
    QRegExp tRegExp_ipv4(".*([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}).*");

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
    Handles incoming connections.
*/
void CHTTPServer::incomingConnection(qintptr socketDescriptor)
{
//    bool bPassBlacklisting = true;

//    QString sIPAddress = cleanIP(pSocket->peerAddress().toString());
//    bPassBlacklisting = passBlackListing(sIPAddress);

//    if (bPassBlacklisting)
    {
        CHTTPRequestProcessor* pProcessor = new CHTTPRequestProcessor(this, socketDescriptor);
        m_vProcessors << pProcessor;
        connect(pProcessor, &QThread::finished, this, &CHTTPServer::onThreadFinished);
        pProcessor->start();
    }
}

//-------------------------------------------------------------------------------------------------

void CHTTPServer::onThreadFinished()
{
    CHTTPRequestProcessor* pSender = dynamic_cast<CHTTPRequestProcessor*>(sender());

    if (pSender != nullptr)
    {
        m_vProcessors.removeAll(pSender);
        pSender->deleteLater();
    }
}
