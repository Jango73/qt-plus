
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTcpSocket>

//-------------------------------------------------------------------------------------------------

//! Définit un contexte de serveur HTTP
class QTPLUSSHARED_EXPORT CWebContext
{
public:

	//-------------------------------------------------------------------------------------------------
	// Constructeurs et destructeur
	//-------------------------------------------------------------------------------------------------

    //! Constructeur par défaut
    CWebContext();

	//! Constructeur
    CWebContext(QTcpSocket* pSocket, QString sPeer, QString sHost, QStringList lPath, QMap<QString, QString> mArguments);

	//! Destructeur
	virtual ~CWebContext();

	//-------------------------------------------------------------------------------------------------
	// Propriétés
	//-------------------------------------------------------------------------------------------------

public:

    QTcpSocket*				m_pSocket;
    QString					m_sPeer;
	QString					m_sHost;
	QStringList				m_lPath;
	QMap<QString, QString>	m_mArguments;
	QByteArray				m_baPostContent;
};
