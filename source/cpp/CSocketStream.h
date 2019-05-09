
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

// Defines an endpoint for a stream using a socket
class QTPLUSSHARED_EXPORT CSocketStream : public CConnectedStream
{
	Q_OBJECT

public:

	//-------------------------------------------------------------------------------------------------
    // Constructors and destructor
	//-------------------------------------------------------------------------------------------------

    //! Constructor with parameters
    //! sName = "0.0.0.0:pppp" The stream serves port pppp
    //! sName = "n.n.n.n:pppp" The stream is client of server at n.n.n.n:pppp
    CSocketStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//! Destructeur
    virtual ~CSocketStream() Q_DECL_OVERRIDE;

	//-------------------------------------------------------------------------------------------------
	// Getters
	//-------------------------------------------------------------------------------------------------

    //! Returns the stream's name
    QString getName() const;

    //! Returns true if there is at least one connection
    bool hasConnections() const;

	//-------------------------------------------------------------------------------------------------
    // QIODevice methods
	//-------------------------------------------------------------------------------------------------

    virtual qint64 readData(char* data, qint64 maxSize) Q_DECL_OVERRIDE;
    virtual qint64 writeData(const char* data, qint64 maxSize) Q_DECL_OVERRIDE;
    virtual qint64 bytesAvailable() const Q_DECL_OVERRIDE;

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
    // Protected methods
	//-------------------------------------------------------------------------------------------------

protected:

    //! Starts server mode
    void bindTo(int iPort);

    //! Starts client mode
    bool connectTo(QString sURL);

	//!
	void sendOutputForSocket(QTcpSocket* pSocket);

	//-------------------------------------------------------------------------------------------------
    // Inner classes
    //-------------------------------------------------------------------------------------------------

protected:

    //! This class associates user data to a QTcpSocket
    //! The pointer to this class is stored in QTcpSocket properties
	class CClientData
	{
	public:

		#define PROP_DATA "Data"

		CClientData(QTcpSocket* pSocket)
			: m_iBytesToWrite(0)
		{
            pSocket->setProperty(PROP_DATA, qulonglong(this));
		}

		//!
		static CClientData* getFromSocket(QTcpSocket* pSocket)
		{
            return reinterpret_cast<CClientData*>(pSocket->property(PROP_DATA).toULongLong());
		}

		//!
		static void deleteFromSocket(QTcpSocket* pSocket)
		{
			CClientData* pData = getFromSocket(pSocket);

			if (pData != nullptr)
			{
				delete pData;
			}

            pSocket->setProperty(PROP_DATA, qulonglong(0));
		}

		QByteArray	m_baOutput;
		qint64		m_iBytesToWrite;
	};

	//-------------------------------------------------------------------------------------------------
    // Properties
	//-------------------------------------------------------------------------------------------------

protected:

	QMutex					m_tMutex;
	QTimer					m_tSendTimer;
	QString					m_sHost;
	int						m_iPort;
	QTcpServer*				m_pLocalServer;
	QTcpSocket*				m_pServer;
	QVector<QTcpSocket*>	m_vClients;
};
