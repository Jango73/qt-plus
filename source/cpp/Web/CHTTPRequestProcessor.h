
#pragma once

#include "../qtplus_global.h"

// Qt
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include <QThread>
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

// Internal values
#define INVALID_RESPONSE_STRING         "VOID"

class CHTTPServer;

//-------------------------------------------------------------------------------------------------

//! Defines a HTTP request processor
class QTPLUSSHARED_EXPORT CHTTPRequestProcessor : public QThread
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CHTTPRequestProcessor(CHTTPServer* pServer, qintptr iSocketDescriptor);

    //! Destructor
    virtual ~CHTTPRequestProcessor() override;

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMap<QString, QVariant>& userData();

    //-------------------------------------------------------------------------------------------------
    // Public control methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void run() Q_DECL_OVERRIDE;

    //!
    void stopMe();

    //! Locks access to data
    bool lock();

    //! Unlocks access to data
    void unlock();

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    int getHeaderLength(QByteArray baData);

    //!
    QStringList getHeaderTokens(QByteArray baData);

    //! Returns the request's excpected byte count
    int getExpectedBytes(QStringList lTokens);

    //! Handles a client request
    void processRequest();

    //! Sends to the client a requested file if found
    bool getResponseFile(CWebContext& tContext, QTcpSocket* pSocket);

    //! Gets some dynamic content (i.e generated)
    //! Returns true if the connection must remain keep-alive
    bool getResponseDynamicContent(CWebContext& tContext, QTcpSocket* pSocket);

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

    //-------------------------------------------------------------------------------------------------
    // Protected slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onSocketDisconnected();
    void onSocketReadyRead();
    void onSocketBytesWritten(qint64 iBytes);

public:

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    bool                    m_bStop;                    // When true, thread must stop
    bool                    m_bHeaderRead;              // When true, we have HTTP header data
    int                     m_iExpectedBytes;           // Number of bytes we are expecting
    qintptr                 m_iSocketDescriptor;
    QMutex                  m_mMutex;                   // Data protection
    CHTTPServer*            m_pServer;                  // The parent server
    QTcpSocket*             m_pSocket;                  // The socket we're serving
    QString                 m_sMultipartBoundary;       // The boundary marker for multi-part content
    QByteArray              m_baBuffer;                 // A buffer for incoming socket data
    QMap<QString, QVariant> m_mUserData;                // A data map for users
};
