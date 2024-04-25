
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTcpSocket>

// Application
#include "CWebSession.h"

//-------------------------------------------------------------------------------------------------

//! Defines a HTTP server context
class QTPLUSSHARED_EXPORT CWebContext
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CWebContext();

    //! Parametered constructor
    CWebContext(
            QTcpSocket* pSocket,
            QMap<QString, QVariant> mUserData,
            CWebSession* pSession = nullptr
            );

    //! Copy constructor
    CWebContext(const CWebContext& target);

    //! Destructor
    virtual ~CWebContext();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    bool pathValid() const { return not (m_lPath.count() == 0 || m_lPath[0].isEmpty()); }

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    QString cleanIP(const QString& sText);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

public:

    QTcpSocket*                 m_pSocket;              //! The web socket
    CWebSession*                m_pSession;             //! The web session : may be NULL
    QString                     m_sPeer;                //! The IP of the client
    QString                     m_sHost;                //! The IP of the host
    QStringList                 m_lPath;                //! The path to the required resource
    QMap<QString, QString>      m_mArguments;           //! The arguments in the URL
    QMap<QString, QString>      m_mArgumentMIMEs;       //! The MIME type of the arguments in the URL (if any)
    QMap<QString, QVariant>     m_mUserData;            //! A map for user data
    QString                     m_sContentType;         //! The requested content type
    QByteArray                  m_baPostContent;        //! The contents of the POST data (if any)
};
