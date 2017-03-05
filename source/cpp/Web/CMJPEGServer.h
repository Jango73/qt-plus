
#pragma once

#include "../qtplus_global.h"

// Qt
#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QTimer>
#include <QFile>

// Application
#include "CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

class CMJPEGServer;

class CMJPEGThread : public QThread
{
    Q_OBJECT

    friend class CMJPEGServer;

public:

    //! Constructeur
    CMJPEGThread(CMJPEGServer* pParent);

    //! Destructeur
    virtual ~CMJPEGThread();

    virtual void run();

protected:

    CMJPEGServer*	m_pParent;
    bool			m_bRun;
};

class QTPLUSSHARED_EXPORT CMJPEGServer : public CHTTPServer
{
    Q_OBJECT

    friend class CMJPEGThread;

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par défaut
    CMJPEGServer(int iPort);

    //! Constructeur pour sortie sur fichier
    CMJPEGServer(QString sFileName);

    //! Destructeur
    virtual ~CMJPEGServer();

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //!
    void send(const QByteArray& baData);

    //!
    void sendRaw(const QByteArray& baData, int iWidth, int iHeight);

    //!
    void sendImage(const QImage& image);

    //!
    bool hasConnections() const;

    //!
    void flush();

    //!
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse, QString& sCustomResponse);

    //!
    virtual void handleSocketBytesWritten(QTcpSocket* pSocket, qint64 iBytes);

    //!
    virtual void handleSocketDisconnection(QTcpSocket* pSocket);

    //-------------------------------------------------------------------------------------------------
    // Méthodes statiques
    //-------------------------------------------------------------------------------------------------

    //!
    static void saveMJPEG(const QVector<QImage>& vImages, QString sFileName);

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onTimeout();

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

protected:

    //!
    void processOutputImages();

    //!
    static QString getHeader();

    //!
    static QString getImageDescriptor(int iSize);

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    QTimer					m_tTimer;
    QMutex					m_tMutex;
    QString					m_sFileName;
    QFile*					m_pOutputFile;
    QVector<QByteArray>		m_vOutput;
    QVector<QImage>			m_vOutputImages;
    QVector<QTcpSocket*>	m_vSockets;
    CMJPEGThread*			m_pThread;
    int						m_iCompressionRate;
};
