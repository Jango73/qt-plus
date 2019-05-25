
// Application
#include "CSocketStream.h"

//-------------------------------------------------------------------------------------------------

#define MAX_PENDING_BYTES   (2048 * 2048)

//-------------------------------------------------------------------------------------------------

/*!
    \class CSocketStream
    \inmodule qt-plus
    \brief A socket stream.

    This stream acts like a serial stream but through sockets. The class will do its best to maintain connection.

    \sa CStreamFactory
*/

/*!
    \fn CClientData* CSocketStream::CClientData::getFromSocket(QTcpSocket* pSocket)

    Returns the data associated with \a pSocket.
*/

/*!
    \fn void CSocketStream::CClientData::deleteFromSocket(QTcpSocket* pSocket)

    Deletes the data associated with \a pSocket.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CSocketStream. \br\br
    \a sName is a TCP/IP connection name like "127.0.0.1", "0.0.0.0:5555"
    \a sParameters are unused for this class.
*/
CSocketStream::CSocketStream(const QString& sName, const QMap<QString, QString>& sParameters)
    : CConnectedStream(sName)
    , m_tMutex(QMutex::Recursive)
    , m_iPort(0)
    , m_pLocalServer(nullptr)
    , m_pServer(nullptr)
{
    Q_UNUSED(sParameters);

	// On détermine d'après l'adresse IP si on est serveur ou client
	if (sName.contains("0.0.0.0"))
	{
		// On récupère le numéro de port
		QStringList sNameList = sName.split(":");
		int iPort = 0;

		if (sNameList.count() > 1)
		{
			iPort = sNameList[1].toInt();
		}

		// Ecoute du port spécifié
		bindTo(iPort);
	}
	else
	{
		// Connexion à l'adresse spécifiée
		connectTo(sName);
	}

	// Gestion des évènements
	connect(&m_tSendTimer, SIGNAL(timeout()), this, SLOT(onSendOutput()));

	// On se place en mode ouvert en lecture/écriture dans la classe QIODevice
	QIODevice::open(QIODevice::ReadWrite);

	m_tSendTimer.start(20);
}

//-------------------------------------------------------------------------------------------------

/*!
    Starts socket in server mode, binding to port number in \a iPort.
*/
void CSocketStream::bindTo(int iPort)
{
	m_pLocalServer = new QTcpServer(this);

	connect(m_pLocalServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

	m_sHost = "0.0.0.0";
	m_iPort = iPort;

	if (m_pLocalServer->listen(QHostAddress::Any, (quint16) m_iPort))
	{
		m_pLocalServer->setMaxPendingConnections(10);
	}
	else
	{
		// LOG_ERROR(m_pLocalServer->errorString());
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    Starts socket in client mode, connecting to address in \a sURL. \br\br
    Always returns \c true.
*/
bool CSocketStream::connectTo(QString sURL)
{
	QStringList lTokens = sURL.split(":");

	// Lecture de l'hôte

	if (lTokens.count() > 0)
	{
		m_sHost = lTokens[0];
	}

	// Lecture du port

	if (lTokens.count() > 1)
	{
		m_iPort = lTokens[1].toInt();
	}

	QTimer::singleShot(1, this, SLOT(onReconnect()));

	return true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CSocketStream.
*/
CSocketStream::~CSocketStream()
{
	// Destruction de tous les clients actifs
    for (QTcpSocket* pClient : m_vClients)
	{
		CClientData::deleteFromSocket(pClient);
		pClient->close();
		pClient->deleteLater();
	}

	// Destruction de la socket serveur
	if (m_pServer != nullptr)
	{
		CClientData::deleteFromSocket(m_pServer);
		m_pServer->close();
		m_pServer->deleteLater();
	}

	// Fermeture du serveur
	if (m_pLocalServer != nullptr)
	{
		m_pLocalServer->close();
		delete m_pLocalServer;
	}

	QIODevice::close();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the stream's name.
*/
QString CSocketStream::getName() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns true if there is at least one connection.
*/
bool CSocketStream::hasConnections() const
{
    return m_vClients.count() > 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when a connection attempt must be made.
*/
void CSocketStream::onReconnect()
{
	if (m_pServer != nullptr)
	{
		CClientData::deleteFromSocket(m_pServer);
		m_pServer->deleteLater();
		m_pServer = nullptr;
	}

	// Création de la socket client
	m_pServer = new QTcpSocket(this);

	// Création de l'objet CClientData associé à la socket
	new CClientData(m_pServer);

	// Connexion des signaux
	connect(m_pServer, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
	connect(m_pServer, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketBytesWritten(qint64)));
	connect(m_pServer, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));

	// Connexion au serveur
	m_pServer->connectToHost(m_sHost, m_iPort);

	if (m_pServer->waitForConnected(1000) == false)
	{
		QTimer::singleShot(2000, this, SLOT(onReconnect()));

		// LOG_WARNING(QString("CSocketStream::onReconnect() : failed to connect to %1").arg(m_sHost));
	}
	else
	{
		emit connected();
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when there is an incoming connection.
*/
void CSocketStream::onNewConnection()
{
	// Récupération socket entrante
	QTcpSocket* pSocket = m_pLocalServer->nextPendingConnection();

	// Ajout de la socket au vecteur
	m_vClients.append(pSocket);

	// Création de l'objet CClientData associé à la socket
	new CClientData(pSocket);

	// Connexion des signaux
	connect(pSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
	connect(pSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(onSocketBytesWritten(qint64)));
	connect(pSocket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when a socket has been disconnected.
*/
void CSocketStream::onSocketDisconnected()
{
	QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

	if (pSocket == m_pServer)
	{
		QTimer::singleShot(2000, this, SLOT(onReconnect()));

		emit disconnected();
	}
	else
	{
		// Retrait de la socket du vecteur

		for (int iIndex = 0; iIndex < m_vClients.count(); iIndex++)
		{
			if (m_vClients[iIndex] == pSocket)
			{
				CClientData::deleteFromSocket(pSocket);
				m_vClients[iIndex]->deleteLater();
				m_vClients.remove(iIndex);
				break;
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when there is data available on a socket.
*/
void CSocketStream::onSocketReadyRead()
{
	int iBytesAvailable = 0;

	if (m_pServer != nullptr)
	{
		iBytesAvailable = m_pServer->bytesAvailable();
	}
	else
	{
		if (hasConnections())
		{
			iBytesAvailable = m_vClients[0]->bytesAvailable();
		}
	}

	if (m_iMinBytesForReadyRead == 0 || iBytesAvailable >= m_iMinBytesForReadyRead)
	{
		emit readyRead();
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when \a iBytes have been written on a socket.
*/
void CSocketStream::onSocketBytesWritten(qint64 iBytes)
{
	QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

	CClientData* pData = CClientData::getFromSocket(pSocket);

	if (pData != nullptr)
	{
		pData->m_iBytesToWrite -= iBytes;
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when output must be sent on a socket.
*/
void CSocketStream::onSendOutput()
{
	QMutexLocker locker(&m_tMutex);

    for (QTcpSocket* pClient : m_vClients)
	{
		sendOutputForSocket(pClient);
	}

	if (m_pServer != nullptr)
	{
		sendOutputForSocket(m_pServer);
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    Sends output data to \a pSocket.
*/
void CSocketStream::sendOutputForSocket(QTcpSocket* pSocket)
{
	CClientData* pData = CClientData::getFromSocket(pSocket);

	if (pData->m_baOutput.count() > 0)
	{
		// Est-ce que la socket est prête?
		if (pSocket->state() == QTcpSocket::ConnectedState)
		{
			// Est-ce que la socket a un buffer de sortie suffisament petit?
			if (pData->m_iBytesToWrite < MAX_PENDING_BYTES)
			{
				// Ecriture des données
				pSocket->write(pData->m_baOutput);

				// Incrémentation du nombre d'octet en attente de partir
				pData->m_iBytesToWrite += pData->m_baOutput.count();

				// Rinçage du flux
				pSocket->flush();
			}
		}

		// Effacement du buffer
		pData->m_baOutput.clear();
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::bytesAvailable. \br\br
    Returns available bytes in device.
*/
qint64 CSocketStream::bytesAvailable() const
{
    qint64 uiBytes = 0;

    if (m_pServer != nullptr)
    {
        uiBytes = m_pServer->bytesAvailable();
    }
    else
    {
        if (hasConnections())
        {
            uiBytes = m_vClients[0]->bytesAvailable();
        }
    }

    return uiBytes + QIODevice::bytesAvailable();
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::readData. \br\br
    Returns number of bytes read to \a data, limited by \a maxSize
*/
qint64 CSocketStream::readData(char* data, qint64 maxSize)
{
	if (m_pServer != nullptr)
	{
		return m_pServer->read(data, maxSize);
	}
	else
	{
		if (hasConnections())
		{
			return m_vClients[0]->read(data, maxSize);
		}
	}

	return 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::writeData. \br\br
    Returns number of bytes written to \a data, limited by \a maxSize
*/
qint64 CSocketStream::writeData(const char* data, qint64 maxSize)
{
	QMutexLocker locker(&m_tMutex);

	if (m_pServer != nullptr)
	{
		CClientData* pData = CClientData::getFromSocket(m_pServer);

		if (pData->m_baOutput.count() + maxSize < MAX_PENDING_BYTES * 2)
		{
			pData->m_baOutput.append(data, maxSize);
		}
	}
	else
	{
		if (hasConnections())
		{
            for (QTcpSocket* pClient : m_vClients)
			{
				if (pClient->state() == QAbstractSocket::ConnectedState)
				{
					CClientData* pData = CClientData::getFromSocket(pClient);

					if (pData->m_baOutput.count() + maxSize < MAX_PENDING_BYTES * 2)
					{
						pData->m_baOutput.append(data, maxSize);
					}
				}
			}
		}
	}

	return maxSize;
}
