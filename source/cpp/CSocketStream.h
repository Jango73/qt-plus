
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

	//! Constructeur avec param�tres
	//! sName = "0.0.0.0:pppp" Le flux sera serveur sur le port pppp
	//! sName = "n.n.n.n:pppp" Le flux sera client de l'adresse n.n.n.n:pppp
	CSocketStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//! Destructeur
	virtual ~CSocketStream();

	//-------------------------------------------------------------------------------------------------
	// Getters
	//-------------------------------------------------------------------------------------------------

	// Retourne le nom utilis� � la cr�ation de l'objet
	QString getName() const { return m_sName; }

	//-------------------------------------------------------------------------------------------------
	// M�thodes de contr�le
	//-------------------------------------------------------------------------------------------------

	//! Appel�e en interne pour d�marrer en mode serveur
	void bindTo(int iPort);

	//! Appel�e en interne pour d�marrer en mode client
	bool connectTo(QString sURL);

	//! Retourne vrai si des connexions existent
	bool hasConnections() const { return m_vClients.count() > 0; }

	//-------------------------------------------------------------------------------------------------
	// M�thodes h�rit�es
	//-------------------------------------------------------------------------------------------------

	//! Lecture de donn�es
	virtual qint64 readData(char* data, qint64 maxSize);

	//! Ecriture de donn�es
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
	// M�thodes prot�g�es
	//-------------------------------------------------------------------------------------------------

protected:

	//!
	void sendOutputForSocket(QTcpSocket* pSocket);

	//-------------------------------------------------------------------------------------------------
	// Classes imbriqu�es
	//-------------------------------------------------------------------------------------------------

protected:

	//! Cette classe utilitaire sert � associer des donn�es utilisateur � une socket
	//! Le pointeur vers cette classe est stock� dans les propri�t�s de QTcpSocket
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
	// Propri�t�s
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
