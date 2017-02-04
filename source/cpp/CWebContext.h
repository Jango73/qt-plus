
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTcpSocket>

//-------------------------------------------------------------------------------------------------

//! D�finit un contexte de serveur HTTP
class QTPLUSSHARED_EXPORT CWebContext
{
public:

	//-------------------------------------------------------------------------------------------------
	// Constructeurs et destructeur
	//-------------------------------------------------------------------------------------------------

    //! Constructeur par d�faut
    CWebContext();

	//! Constructeur
    CWebContext(QTcpSocket* pSocket, QString sPeer, QString sHost, QStringList lPath, QMap<QString, QString> mArguments);

	//! Destructeur
	virtual ~CWebContext();

	//-------------------------------------------------------------------------------------------------
	// Propri�t�s
	//-------------------------------------------------------------------------------------------------

public:

    QTcpSocket*				m_pSocket;
    QString					m_sPeer;
	QString					m_sHost;
	QStringList				m_lPath;
	QMap<QString, QString>	m_mArguments;
	QByteArray				m_baPostContent;
};
