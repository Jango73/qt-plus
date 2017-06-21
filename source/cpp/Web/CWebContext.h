
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
    CWebContext(QTcpSocket* pSocket, QString sPeer, QString sHost, QStringList lPath, QMap<QString, QString> mArguments);

    //! Copy constructor
    CWebContext(const CWebContext& target);

    //! Destructor
    virtual ~CWebContext();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

public:

    QTcpSocket*             m_pSocket;
    QString                 m_sPeer;
    QString                 m_sHost;
    QStringList             m_lPath;
    QMap<QString, QString>  m_mArguments;
    QByteArray              m_baPostContent;
};
