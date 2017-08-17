
// Qt
#include <QRegExp>

// Application
#include "CMJPEGClient.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CMJPEGClient
    \inmodule qt-plus
    \brief A client for MJPEG streams.
*/

/*!
    \fn void CMJPEGClient::newImage()

    This signal is emitted when an new image is ready.
*/

//-------------------------------------------------------------------------------------------------

#define HTTP_HEADER			"http/1.1"
#define HTTP_BOUNDARY		"boundary="
#define HTTP_CONTENT_TYPE	"content-type"
#define HTTP_CONTENT_LENGTH	"content-length"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CMJPEGClient with default parameters.
*/
CMJPEGClient::CMJPEGClient()
    : m_pClient(this)
    , m_bKeepAlive(false)
    , m_bReadingImage(false)
{
    connect(&m_pClient, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(&m_pClient, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CMJPEGClient.
*/
CMJPEGClient::~CMJPEGClient()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Opens the MJPEG stream at \a sURL. \br\br
    \a bKeepAlive forces the client to reconnect in case of connection loss.
*/
void CMJPEGClient::openURL(const QString& sURL, bool bKeepAlive)
{
    QRegExp tExp(QString("http://(.*):([0-9]*)(.*)"));

    if (tExp.indexIn(sURL) != -1)
    {
        m_sIP = tExp.cap(1);
        m_iPort = tExp.cap(2).toInt();
        m_sResource = tExp.cap(3);

        m_bKeepAlive = bKeepAlive;

        onDoConnection();
    }
    else
    {
        qWarning() << QString("CMJPEGClient::openURL() : Could not parse URL");
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Closes the stream.
*/
void CMJPEGClient::closeURL()
{
    m_bKeepAlive = false;
    m_pClient.disconnectFromHost();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a reference to the current image.
*/
const QImage& CMJPEGClient::getImage() const
{
    return m_Image;
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles connection to the server.
*/
void CMJPEGClient::onDoConnection()
{
    // qDebug() << QString("CMJPEGClient::onDoConnection() : connecting to %1:%2").arg(m_sIP).arg(m_iPort);

    QHostAddress address(m_sIP);

    m_pClient.connectToHost(address, m_iPort);

    // Attente de connexion au serveur HTTP
    if (m_pClient.waitForConnected(20000))
    {
        QString sGet = QString("GET %1\r\n").arg(m_sResource);

        // qDebug() << QString("CMJPEGClient::onDoConnection() : getting %1").arg(sGet);

        // Envoi d'un GET au serveur HTTP
        m_pClient.write(sGet.toLatin1());
    }
    else
    {
        qWarning() << "CMJPEGClient::onDoConnection() : Unable to connect, retrying in 2 seconds";

        // On retente la connexion dans deux secondes
        QTimer::singleShot(2000, this, SLOT(onDoConnection()));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles disconnection from the server. Triggers onDoConnection() if the keep alive flag was set to \c true.
*/
void CMJPEGClient::onDisconnected()
{
    // Si une connexion permanente est demandée, tentative de reconnexion au serveur HTTP
    if (m_bKeepAlive)
    {
        QTimer::singleShot(2000, this, SLOT(onDoConnection()));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles incoming data from the server.
*/
void CMJPEGClient::onReadyRead()
{
#define MAX_BYTES_READ 2000000

    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(QObject::sender());

    // Test d'intégrité de la socket
    if (pSocket != nullptr)
    {
        // Est-on en état connecté?
        if (pSocket->state() == QTcpSocket::ConnectedState)
        {
            // On boucle tant qu'il existe des données entrantes
            while (pSocket->bytesAvailable() > 0)
            {
                // Cas où on ne lit pas une image
                if (m_bReadingImage == false)
                {
                    // On lit une ligne dans la socket et on prépare le marqueur
                    QString sLine = pSocket->readLine().toLower();
                    QStringList vTokens = QString(sLine).split(" ", QString::SkipEmptyParts);
                    QString sMarker = QString("--%1").arg(m_sBoundary);

                    // Il y a quelque chose à analyser?
                    if (vTokens.count() > 0)
                    {
                        // Cas du header HTTP
                        if (vTokens[0] == HTTP_HEADER)
                        {
                            QString sHeader = vTokens[0];
                        }
                        // Cas du descripteur de contenu HTTP
                        else if (vTokens[0].startsWith(HTTP_CONTENT_TYPE))
                        {
                            if (m_sBoundary == "")
                            {
                                for (int iIndex = 1; iIndex < vTokens.count(); iIndex++)
                                {
                                    if (vTokens[iIndex].contains(HTTP_BOUNDARY))
                                    {
                                        int iBoundaryIndex = vTokens[iIndex].indexOf(HTTP_BOUNDARY) + QString(HTTP_BOUNDARY).length();
                                        m_sBoundary = vTokens[iIndex].mid(iBoundaryIndex);
                                        break;
                                    }
                                }
                            }
                        }
                        // Cas du marqueur, on ne fait rien
                        else if (vTokens[0] == sMarker)
                        {
                        }
                        // Cas de la longueur du contenu
                        else if (vTokens[0].startsWith(HTTP_CONTENT_LENGTH))
                        {
                            QString sExp = QString("%1:[ ]*([0-9]*)").arg(HTTP_CONTENT_LENGTH);
                            QRegExp tExp(sExp);

                            if (tExp.indexIn(sLine) != -1)
                            {
                                m_iImageRemainToRead = tExp.cap(1).toInt();
                            }

                            m_bReadingImage = true;

                            sLine = pSocket->readLine();
                        }
                    }
                }
                else
                {
                    QByteArray baData = pSocket->read(m_iImageRemainToRead);

                    if (baData.count() > 0)
                    {
                        m_iImageRemainToRead -= baData.count();
                        m_baIncomingData.append(baData);
                    }

                    if (m_iImageRemainToRead <= 0)
                    {
                        m_bReadingImage = false;

                        if (m_Image.loadFromData(m_baIncomingData, "JPG"))
                        {
                            m_Image = m_Image.convertToFormat(QImage::Format_RGB888);
                        }

                        m_baIncomingData.clear();

                        emit newImage();
                    }
                }
            }
        }
    }
}
