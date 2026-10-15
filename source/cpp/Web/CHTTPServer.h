
#pragma once

#include "../qtplus_global.h"

// Qt
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QRecursiveMutex>
#include <QTimer>
#include <QSslConfiguration>
#include <QSslCertificate>
#include <QSslKey>

// Application
#include "CHTTPRequestProcessor.h"
#include "CWebSession.h"

//-------------------------------------------------------------------------------------------------

#define DEFAULT_HTTP_PORT   80
#define DEFAULT_HTTPS_PORT  443

//-------------------------------------------------------------------------------------------------

//! Defines a HTTP server
class QTPLUSSHARED_EXPORT CHTTPServer : public QTcpServer
{
    Q_OBJECT

    //-------------------------------------------------------------------------------------------------
    // Inner classes
    //-------------------------------------------------------------------------------------------------

public:

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

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CHTTPServer(quint16 uiPort = DEFAULT_HTTP_PORT, QObject* parent = nullptr);

    //! Destructor
    virtual ~CHTTPServer() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    bool disabled() const;

    //!
    const QVector<QString>& authorizedFolders() const;

    //!
    const QMap<QString, CRequestMonitor>& monitors() const;

    //!
    CWebSession* sessionByIP(const QString& sIP);

    //!
    CWebSession* sessionBySocket(QTcpSocket* pSocket);

    //!
    bool isHttpsEnabled() const;

    //!
    quint16 httpsPort() const;

    //!
    QSslConfiguration sslConfiguration() const;

    //-------------------------------------------------------------------------------------------------
    // Public control methods
    //-------------------------------------------------------------------------------------------------

    //! Activates or deactivates flood protection (activated by default)
    void useFloodProtection(bool bUse);

    //! Enables HTTPS on a second port using PEM files (key + certificate). HTTP keeps working. Returns false on error
    bool enableHttps(const QString& sCertPath, const QString& sKeyPath, quint16 uiHttpsPort = DEFAULT_HTTPS_PORT);

    //! Enables HTTPS from in-memory certificate and key. HTTP keeps working. Returns false on error
    bool enableHttps(const QSslCertificate& certificate, const QSslKey& privateKey, quint16 uiHttpsPort = DEFAULT_HTTPS_PORT);

    //! Disables HTTPS (HTTP keeps working)
    void disableHttps();

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

    //! Checks if an IP is blacklisted
    bool passBlackListing(QString sIPAddress);

    //!
    void requestStart(QString sIPAddress);

    //!
    void requestEnd(QString sIPAddress);

    //! Returns the content type associated with a file extension
    QString getContentTypeByExtension(const QString& sExtension) const;

    //! Logs an incoming HTTP request
    void LogRequest(QString sIP, QString sText);

    //! To be overridden by subclasses in order to feed content to the client
    virtual void getContent(CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME);

    //! To be overridden by subclasses in order to react after sending data to the client
    virtual void handleSocketBytesWritten(CWebContext& tContext, qint64 iBytes);

    //! To be overridden by subclasses in order to react after reading data from the client
    virtual void handleSocketBytesRead(CWebContext& tContext, qint64 iBytes);

    //! To be overridden by subclasses in order to react after a client disconnection
    virtual void handleSocketDisconnection(CWebContext& tContext);

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //! Encodes a string to URL format (replaces some ASCII characters with their %XX couterparts)
    static QString encodeURLParameters(QString sText);

    //! Decodes a string from URL format (replaces the %XX with their ASCII couterparts)
    static QString decodeURLParameters(QString sText);

    //! Returns a clean IP address from sText
    static QString cleanIP(const QString& sText);

    //! Returns a clean IP address from a socket
    static QString IPFromSocket(QTcpSocket* pSocket);

    //-------------------------------------------------------------------------------------------------
    // Protected methods
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    virtual void incomingConnection(qintptr iSocketDescriptor) Q_DECL_OVERRIDE;

    //! Creates a request processor for a socket descriptor (secure = TLS upgrade in processor)
    void createProcessor(qintptr iSocketDescriptor, bool bSecure);

    //! Internal TCP listener forwarding raw descriptors to the parent as HTTPS
    class CHttpsListener : public QTcpServer
    {
    public:
        explicit CHttpsListener(CHTTPServer* pParent = nullptr)
            : QTcpServer(pParent)
            , m_pParent(pParent)
        {
        }

    protected:
        void incomingConnection(qintptr iSocketDescriptor) Q_DECL_OVERRIDE;

    private:
        CHTTPServer* m_pParent;
    };

    //-------------------------------------------------------------------------------------------------
    // Protected slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onThreadFinished();
    void onMaintenance();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QRecursiveMutex                 m_mMutex;                       // Data protection
    int                             m_iRequestCount;                // Total request count
    int                             m_iMaxRequestPerSeconds;        // Maximum requests per second for a given IP
    int                             m_iMaximumSessionAliveSeconds;  //
    int                             m_iMaintenanceTimerSeconds;     // Seconds between maintenance processing
    bool                            m_bDisabled;                    // Tells if the server should ignore requests
    bool                            m_bUseFloodProtection;
    QVector<QString>                m_vAuthorizedFolders;           // Tells which folders users can access
    QMap<QString, QString>          m_vExtensionToContentType;      // Used to convert a file extension to a MIME type
    QVector<CHTTPRequestProcessor*> m_vProcessors;
    QMap<QString, CWebSession*>     m_mSessions;                    // Sessions
    QMap<QString, CRequestMonitor>  m_mMonitors;                    // Anti-flooding monitors
    QStringList                     m_lStaticIPBlackList;
    QStringList                     m_lDynamicIPBlackList;
    QTimer                          m_tMaintenanceTimer;
    QSslConfiguration               m_sslConfiguration;             // Active TLS config (if HTTPS enabled)
    CHttpsListener*                 m_pHttpsServer;                 // Second listener for HTTPS (null = disabled)
    quint16                         m_uiHttpsPort;                  // HTTPS port (0 = disabled)
};
