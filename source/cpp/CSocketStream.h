
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QObject>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QMutex>

// Application
#include "CConnectedStream.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CSocketStream : public CConnectedStream
{
	Q_OBJECT

public:

	//-------------------------------------------------------------------------------------------------
	// Constructeurs et destructeur
	//-------------------------------------------------------------------------------------------------

	//! Constructeur avec paramètres
	//! sName = "0.0.0.0:pppp" Le flux sera serveur sur le port pppp
	//! sName = "n.n.n.n:pppp" Le flux sera client de l'adresse n.n.n.n:pppp
	CSocketStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//! Destructeur
	virtual ~CSocketStream();

	//-------------------------------------------------------------------------------------------------
	// Getters
	//-------------------------------------------------------------------------------------------------

	// Retourne le nom utilisé à la création de l'objet
	QString getName() const { return m_sName; }

	//-------------------------------------------------------------------------------------------------
	// Méthodes de contrôle
	//-------------------------------------------------------------------------------------------------

	//! Appelée en interne pour démarrer en mode serveur
	void bindTo(int iPort);

	//! Appelée en interne pour démarrer en mode client
	bool connectTo(QString sURL);

	//! Retourne vrai si des connexions existent
	bool hasConnections() const { return m_vClients.count() > 0; }

	//-------------------------------------------------------------------------------------------------
	// Méthodes héritées
	//-------------------------------------------------------------------------------------------------

	//! Lecture de données
	virtual qint64 readData(char* data, qint64 maxSize);

	//! Ecriture de données
	virtual qint64 writeData(const char* data, qint64 maxSize);

	//!
	virtual qint64 bytesAvailable() const;

	//-------------------------------------------------------------------------------------------------
	// Slots
	//-------------------------------------------------------------------------------------------------

protected slots:

	void onReconnect();
	void onNewConnection();
	void onSocketDisconnected();
	void onSocketReadyRead();
	void onSocketBytesWritten(qint64 iBytes);
	void onSendOutput();

	//-------------------------------------------------------------------------------------------------
	// Méthodes protégées
	//-------------------------------------------------------------------------------------------------

protected:

	//!
	void sendOutputForSocket(QTcpSocket* pSocket);

	//-------------------------------------------------------------------------------------------------
	// Classes imbriquées
	//-------------------------------------------------------------------------------------------------

protected:

	//! Cette classe utilitaire sert à associer des données utilisateur à une socket
	//! Le pointeur vers cette classe est stocké dans les propriétés de QTcpSocket
	class CClientData
	{
	public:

		#define PROP_DATA "Data"

		CClientData(QTcpSocket* pSocket)
			: m_iBytesToWrite(0)
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

			if (pData != NULL)
			{
				delete pData;
			}

			pSocket->setProperty(PROP_DATA, (qulonglong) 0);
		}

		QByteArray	m_baOutput;
		qint64		m_iBytesToWrite;
	};

	//-------------------------------------------------------------------------------------------------
	// Propriétés
	//-------------------------------------------------------------------------------------------------

protected:

	QMutex					m_tMutex;
	QString					m_sName;
	QTimer					m_tSendTimer;
	QString					m_sHost;
	int						m_iPort;
	QTcpServer*				m_pLocalServer;
	QTcpSocket*				m_pServer;
	QVector<QTcpSocket*>	m_vClients;
};
