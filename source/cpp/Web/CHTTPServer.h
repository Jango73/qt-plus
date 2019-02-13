
#pragma once

#include "../qtplus_global.h"

// Qt
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QRunnable>
#include <QMutex>

// Application
#include "CWebContext.h"

//-------------------------------------------------------------------------------------------------

// New line as output in web page
#define HTML_NL                         "\r\n"

// First token in a HTTP header

#define HTTP_HEADER                     "HTTP/1.1 "

#define HTTP_GET                        "GET"
#define HTTP_POST                       "POST"

// Possible error codes of a HTTP server

#define HTTP_200_OK                     "200 Ok"

#define HTTP_201_CREATED                "201 Created"
#define HTTP_202_ACCEPTED               "202 Accepted"
#define HTTP_203_NA_INFORMATION         "203 Non-Authoritative Information"
#define HTTP_204_NO_CONTENT             "204 No Content"
#define HTTP_205_RESET_CONTENT          "205 Reset Content"
#define HTTP_206_PARTIAL_CONTENT        "206 Partial Content"

#define HTTP_400_BAD_REQUEST            "400 Bad Request"
#define HTTP_401_UNAUTHORIZED           "401 Unauthorized"
#define HTTP_402_PAYMENT_REQUIRED       "402 Payment Required"
#define HTTP_403_FORBIDDEN              "403 Forbidden"
#define HTTP_404_NOT_FOUND              "404 Not Found"
#define HTTP_405_METHOD_NOT_ALLOWED     "405 Method Not Allowed"
#define HTTP_406_NOT_ACCEPTABLE         "406 Not Acceptable"
#define HTTP_407_PROXY_AUTH_REQUIRED    "407 Proxy Authentication Required"
#define HTTP_408_REQUEST_TIMEOUT        "408 Request Timeout"
#define HTTP_409_CONFLICT               "409 Conflict"
#define HTTP_410_GONE                   "410 Gone"

#define HTTP_500_INTERNAL_SERVER_ERROR  "500 Internal Server Error"
#define HTTP_501_NOT_IMPLEMENTED        "501 Not Implemented"
#define HTTP_502_BAD_GATEWAY            "502 Bad Gateway"
#define HTTP_503_SERVICE_UNAVAILABLE    "503 Service Unavailable"
#define HTTP_504_GATEWAY_TIMEOUT        "504 Gateway Timeout"
#define HTTP_505_HTTP_VERSION_NS        "505 HTTP Version Not Supported"

// Important tokens in a HTTP header

#define Token_Host                      "Host:"
#define Token_Connection                "Connection:"
#define Token_ContentType               "Content-Type:"
#define Token_ContentLength             "Content-Length:"
#define Token_ContentDisposition        "Content-Disposition:"
#define Token_boundary                  "boundary"
#define Token_name                      "name"

// MIME type tokens

#define MIME_Content_PlainText          "text/plain"
#define MIME_Content_HTML               "text/html"
#define MIME_Content_CSS                "text/css"
#define MIME_Content_URLForm            "application/x-www-form-urlencoded"
#define MIME_Content_Javascript         "application/javascript"
#define MIME_Content_Stream             "application/octet-stream"
#define MIME_Content_PDF                "application/pdf"
#define MIME_Content_XHTML              "application/xhtml+xml"
#define MIME_Content_JSON               "application/json"
#define MIME_Content_XML                "application/xml"
#define MIME_Content_ZIP                "application/zip"
#define MIME_Content_GIF                "image/gif"
#define MIME_Content_JPG                "image/jpg"
#define MIME_Content_PNG                "image/png"
#define MIME_Content_MultiPart          "multipart"
#define MIME_Content_MultiPart_FormData "multipart/form-data"
#define MIME_Content_Custom             "custom"

//-------------------------------------------------------------------------------------------------

//! Defines a HTTP server
class QTPLUSSHARED_EXPORT CHTTPServer : public QTcpServer
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CHTTPServer(quint16 port, QObject* parent = 0);

    //! Destructor
    virtual ~CHTTPServer();

    //-------------------------------------------------------------------------------------------------
    // Public control methods
    //-------------------------------------------------------------------------------------------------

    //! Activates or deactivates flood protection (activated by default)
    void useFloodProtection(bool bUse);

    //!  Adds a folder to the list of authorized folders
    void addAuthorizedFolder(QString sFolderName);

    //! Pauses the server. When paused, the server will not serve any request
    void pause();

    //! Resumes the server. When not paused, the server will serve requests
    void resume();

    //! Locks access to data
    bool lock();

    //! Unlocks access to data
    void unlock();

    //! To be overridden by subclasses in order to feed content to the client
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME);

    //! To be overridden by subclasses in order to react after sending data to the client
    virtual void handleSocketBytesWritten(QTcpSocket* pSocket, qint64 iBytes);

    //! To be overridden by subclasses in order to react after reading data from the client
    virtual void handleSocketBytesRead(QTcpSocket* pSocket);

    //! To be overridden by subclasses in order to react after a client disconnection
    virtual void handleSocketDisconnection(QTcpSocket* pSocket);

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //! Encodes a string to URL format (replaces some ASCII characters with their %XX couterparts)
    static QString encodeURLParameters(QString sText);

    //! Decodes a string from URL format (replaces the %XX with their ASCII couterparts)
    static QString decodeURLParameters(QString sText);

    static QString cleanIP(const QString& sText);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    QStringList getHeaderTokens(QByteArray baData);

    //! Returns the request's excpected byte count
    int getExpectedBytes(QStringList lTokens);

    //! Handles a client request
    void processRequest(QTcpSocket* pSocket);

    //! Sends to the client a requested file if found
    bool getResponseFile(const CWebContext& tContext, QTcpSocket* pSocket);

    //! Gets some dynamic content (i.e generated)
    //! Returns true if the connection must remain keep-alive
    bool getResponseDynamicContent(const CWebContext& tContext, QTcpSocket* pSocket);

    //! Returns the header of a HTTP request parsed from sText
    QString getRequestHeader(const QString& sText);

    //! Splits up the URL path and arguments
    void getRequestPathAndArgs(const QStringList& lTokens, QStringList& lPath, QMap<QString, QString>& mArguments);

    //! Gets the post content from a request header
    void getRequestPostContent(const QString& sText, QByteArray& baContent);

    //! Returns the value associated with a token
    QString getTokenValue(const QStringList& lTokens, QString sTokenName);

    //!
    QString getSubTokenValue(const QStringList& lTokens, QString sTokenName, QString sSubTokenName);

    //! Returns the content type associated with a file extension
    QString getContentTypeByExtension(const QString& sExtension) const;

    //! Logs an incoming HTTP request
    void LogRequest(QString sIP, QString sText);

    //-------------------------------------------------------------------------------------------------
    // Protected slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onNewConnection();
    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketBytesWritten(qint64 iBytes);

    //-------------------------------------------------------------------------------------------------
    // Inner classes
    //-------------------------------------------------------------------------------------------------

public:

    //! This utility class associated custom data with a socket
    //! The pointer to this class is stored in QTcpSocket's properties
    class CClientData
    {
    public:

#define PROP_DATA "Data"

        //!
        CClientData(QTcpSocket* pSocket)
            : m_bHeaderRead(false)
            , m_iExpectedBytes(0)
        {
            pSocket->setProperty(PROP_DATA, (qulonglong) this);
        }

        //!
        static CClientData* getFromSocket(QTcpSocket* pSocket)
        {
            return (CClientData*) pSocket->property(PROP_DATA).toULongLong();
        }

        //!
        static void deleteFromSocket(QTcpSocket* pSocket)
        {
            CClientData* pData = getFromSocket(pSocket);

            if (pData != nullptr)
            {
                delete pData;
            }
        }

        bool                    m_bHeaderRead;
        QString                 m_sMultipartBoundary;
        int                     m_iExpectedBytes;
        QByteArray              m_baBuffer;
        QMap<QString, QVariant> m_vUserData;
    };

    //! This class executes requests in threaded mode
    class CRequestProcessor : public QRunnable
    {
    public:

        CRequestProcessor(CHTTPServer* pServer, QTcpSocket* pSocket)
            : m_pServer(pServer)
            , m_pSocket(pSocket)
        {
        }

        virtual void run() Q_DECL_OVERRIDE
        {
            m_pServer->processRequest(m_pSocket);
        }

    protected:

        CHTTPServer*    m_pServer;
        QTcpSocket*     m_pSocket;
    };

    //! This class monitors request to detect flood attacks
    class CRequestMonitor
    {
    public:

        CRequestMonitor()
            : m_dSampleStartTime(QDateTime::currentDateTime())
            , m_iSampleRequestCount(0)
            , m_iSimultaneousRequestCount(0)
            , m_bFlooding(false)
        {
        }

        void reset()
        {
            m_dSampleStartTime = QDateTime::currentDateTime();
            m_iSampleRequestCount = 0;
            m_iSimultaneousRequestCount = 0;
            m_bFlooding = false;
        }

        void processIn()
        {
            const int iSampleMillis = 4000;

            m_iSampleRequestCount++;
            m_iSimultaneousRequestCount++;

            QDateTime dNow = QDateTime::currentDateTime();

            if (m_dSampleStartTime.msecsTo(dNow) > iSampleMillis)
            {
                if (m_iSampleRequestCount > (15 * (iSampleMillis / 1000)))
                {
                    m_bFlooding = true;
                }

                m_dSampleStartTime = dNow;
                m_iSampleRequestCount = 0;
            }

            if (m_iSimultaneousRequestCount > 15)
            {
                m_bFlooding = true;
            }
        }

        void processOut()
        {
            m_iSimultaneousRequestCount--;
        }

        bool shouldBeBlocked() const
        {
            return m_bFlooding;
        }

    protected:

        QDateTime   m_dSampleStartTime;
        int         m_iSampleRequestCount;
        int         m_iSimultaneousRequestCount;
        bool        m_bFlooding;
    };

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMutex                          m_mMutex;                   // Data protection
    int                             m_iRequestCount;            // Total request count
    int                             m_iMaxRequestPerSeconds;    //
    bool                            m_bDisabled;                // Tells if the server should ignore requests
    bool                            m_bUseFloodProtection;
    QVector<QString>                m_vAuthorizedFolders;       // Tells which folders users can access
    QMap<QString, QString>          m_vExtensionToContentType;  // Used to converta file extension to a MIME type
    QThreadPool                     m_pProcessors;              // Threaded request processors
    QMap<QString, CRequestMonitor>  m_mMonitors;                // Anti-flooding monitor
    QStringList                     m_lStaticIPBlackList;
    QStringList                     m_lDynamicIPBlackList;
};
