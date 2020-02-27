
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTcpSocket>

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
            QMap<QString, QVariant> mUserData
            );

    //! Parametered constructor
    CWebContext(
            QTcpSocket* pSocket,
            QString sPeer,
            QString sHost
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
    // Properties
    //-------------------------------------------------------------------------------------------------

public:

    QTcpSocket*                 m_pSocket;
    QString                     m_sPeer;                //! The IP of the client
    QString                     m_sHost;                //! The IP of the host
    QStringList                 m_lPath;                //! The path to the required resource
    QMap<QString, QString>      m_mArguments;           //! The arguments in the URL
    QMap<QString, QString>      m_mArgumentMIMEs;       //! The MIME type of the arguments in the URL (if any)
    QMap<QString, QVariant>     m_mUserData;
    QString                     m_sContentType;
    QByteArray                  m_baPostContent;        //! The contents of the POST data (if any)
};
