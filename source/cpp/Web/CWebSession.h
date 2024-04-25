
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
#include "../Macros.h"

//-------------------------------------------------------------------------------------------------

class CHTTPServer;

typedef QMap<QString, QVariant> UserDataMap;

//-------------------------------------------------------------------------------------------------

//! Defines a web session
class QTPLUSSHARED_EXPORT CWebSession : public QObject
{
    Q_OBJECT

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

    //! The remote IP address
    Q_FAST_PROPERTY(QString, s, remoteIP, RemoteIP)

    //! Last request time
    Q_FAST_PROPERTY(QDateTime, m, lastRequestTime, LastRequestTime)

    //! User data
    Q_FAST_PROPERTY(UserDataMap, m, userData, UserData)

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CWebSession(CHTTPServer* pServer);

    //! Destructor
    virtual ~CWebSession() override;

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Public control methods
    //-------------------------------------------------------------------------------------------------

    //! Locks access to data
    bool lock();

    //! Unlocks access to data
    void unlock();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMutex          m_mMutex;                   // Data protection
    CHTTPServer*    m_pServer;                  // The parent server
};
