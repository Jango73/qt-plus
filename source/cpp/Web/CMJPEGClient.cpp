
// Qt
#include <QRegularExpression>

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
    QRegularExpression tExp(QString("http://(.*):([0-9]*)(.*)"));
    QRegularExpressionMatch match = tExp.match(sURL);
    if (match.hasMatch())
    {
        m_sIP = match.captured(1);
        m_iPort = match.captured(2).toInt();
        m_sResource = match.captured(3);

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

    // Waiting for connection to HTTP server
    if (m_pClient.waitForConnected(20000))
    {
        QString sGet = QString("GET %1\r\n").arg(m_sResource);

        // qDebug() << QString("CMJPEGClient::onDoConnection() : getting %1").arg(sGet);

        // Sending a GET request to the HTTP server
        m_pClient.write(sGet.toLatin1());
    }
    else
    {
        qWarning() << "CMJPEGClient::onDoConnection() : Unable to connect, retrying in 2 seconds";

        // Retrying connection in two seconds
        QTimer::singleShot(2000, this, SLOT(onDoConnection()));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles disconnection from the server. Triggers onDoConnection() if the keep alive flag was set to \c true.
*/
void CMJPEGClient::onDisconnected()
{
    // If a persistent connection is requested, attempt to reconnect to HTTP server
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

    // Socket integrity check
    if (pSocket != nullptr)
    {
        // Are we in connected state?
        if (pSocket->state() == QTcpSocket::ConnectedState)
        {
            // Loop while there is incoming data
            while (pSocket->bytesAvailable() > 0)
            {
                // Case where we are not reading an image
                if (m_bReadingImage == false)
                {
                    // Read a line from the socket and prepare the marker
                    QString sLine = pSocket->readLine().toLower();
                    QStringList vTokens = QString(sLine).split(" ", Qt::SkipEmptyParts);
                    QString sMarker = QString("--%1").arg(m_sBoundary);

                    // Is there something to analyze?
                    if (vTokens.count() > 0)
                    {
                        // HTTP header case
                        if (vTokens[0] == HTTP_HEADER)
                        {
                            QString sHeader = vTokens[0];
                        }
                        // HTTP content descriptor case
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
                        // Marker case, do nothing
                        else if (vTokens[0] == sMarker)
                        {
                        }
                        // Content length case
                        else if (vTokens[0].startsWith(HTTP_CONTENT_LENGTH))
                        {
                            QString sExp = QString("%1:[ ]*([0-9]*)").arg(HTTP_CONTENT_LENGTH);
                            QRegularExpression tExp(sExp);
                            QRegularExpressionMatch match = tExp.match(sLine);
                            if (match.hasMatch())
                            {
                                m_iImageRemainToRead = match.captured(1).toInt();
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
