
#pragma once

#include "qtplus_global.h"

// Qt
#include <QObject>
#include <QTimer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QImage>

class QTPLUSSHARED_EXPORT CMJPEGClient : public QObject
{
    Q_OBJECT

public:

    // Ctor
    CMJPEGClient();

    // Dtor
    virtual ~CMJPEGClient();

    //-----------------------------------------------------------------------------------------------
    // Impl�mentation de IVideoProvider
    //-----------------------------------------------------------------------------------------------

    //! Ouvre et d�marre la lecture vid�o de l'URL
    void openURL(const QString& sURL, bool bKeepAlive = true);

    //! Ferme et arr�te la lecture vid�o de l'URL
    void closeURL();

    //! Retourne une r�f�rence vers l'image en cours
    const QImage& getImage() const;

    //-----------------------------------------------------------------------------------------------
    // Slots prot�g�s
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

    //!
    void newImage();

    //-----------------------------------------------------------------------------------------------
    // Propri�t�s
    //-----------------------------------------------------------------------------------------------

protected:

    QString		m_sIP;					// Adress IP du serveur auquel on se connecte
    QString     m_sResource;
    QTcpSocket	m_pClient;				// Socket vers le serveur
    QImage		m_Image;				// Image courante remont�e par le serveur
    QString		m_sBoundary;			// Indicateur HTTP de limite entre deux images
    QByteArray	m_baIncomingData;		// Buffer d'entr�e brut de la socket
    int			m_iPort;				// Port du serveur auquel on se connecte
    int			m_iImageRemainToRead;	// Conteur indiquant combien d'octets il reste � lire pour une image
    bool		m_bKeepAlive;           // Si ce flag est vrai, le client tentera des connexions au serveur continuellement
    bool		m_bReadingImage;		// Flag indiquant si on est en train de lire une image (sinon un header ou une marque de limite)
};
