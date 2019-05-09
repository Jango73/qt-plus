
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QImage>

//-------------------------------------------------------------------------------------------------

//! Defines a MJPEG client
class QTPLUSSHARED_EXPORT CMJPEGClient : public QObject
{
    Q_OBJECT

public:

    //-----------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-----------------------------------------------------------------------------------------------

    //! Constructor
    CMJPEGClient();

    //! Destructor
    virtual ~CMJPEGClient();

    //-----------------------------------------------------------------------------------------------
    // Control methods
    //-----------------------------------------------------------------------------------------------

    //! Open a video URL and starts reading
    void openURL(const QString& sURL, bool bKeepAlive = true);

    //! Closees the URL
    void closeURL();

    //! Returns the current image
    const QImage& getImage() const;

    //-----------------------------------------------------------------------------------------------
    // Protected slots
    //-----------------------------------------------------------------------------------------------

protected slots:

    //!
    void onDoConnection();

    //!
    void onReadyRead();

    //!
    void onDisconnected();

    //-----------------------------------------------------------------------------------------------
    // Signaux
    //-----------------------------------------------------------------------------------------------

signals:

    //! This signal is emitted when a new image is available
    void newImage();

    //-----------------------------------------------------------------------------------------------
    // Propriétés
    //-----------------------------------------------------------------------------------------------

protected:

    QString		m_sIP;					// IP address of the server to which we connect
    QString     m_sResource;            // Name of the video resource (may be empty)
    QTcpSocket	m_pClient;				// Socket for the connection
    QImage		m_Image;				// LAst received image if any
    QString		m_sBoundary;			// HTTP boundary marker
    QByteArray	m_baIncomingData;		// Raw incoming data from socket
    int			m_iPort;				// Port du serveur auquel on se connecte
    int			m_iImageRemainToRead;	// Conteur indiquant combien d'octets il reste à lire pour une image
    bool		m_bKeepAlive;           // Si ce flag est vrai, le client tentera des connexions au serveur continuellement
    bool		m_bReadingImage;		// Flag indiquant si on est en train de lire une image (sinon un header ou une marque de limite)
};
