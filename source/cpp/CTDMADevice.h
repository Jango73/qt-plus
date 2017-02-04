
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>
#include <QVector>
#include <QMap>
#include <QIODevice>
#include <QTimer>
#include <QDateTime>
#include <QByteArray>

//-------------------------------------------------------------------------------------------------

typedef quint8  PTDMASlot;
typedef quint8  PTDMAAction;
typedef quint16 PTDMASerial;

/*-------------------------------------------------------------------------------------------------
Exemple de timeline du fonctionnement de la classe:

Master     Msg Anyone                 Msg reset   Msg Anyone            Msg SetSlot

---------------|-------------|----JAM-----|-----------|----------|-----------|-----------|-------->
Slave 1                 Resp Anyone                          Resp Anyone             Resp SetSlot
Slave 2                 Resp Anyone

Master     Msg Speak                  Msg Anyone             Msg SetSlot             Msg Speak
            Slot 1                                                                     Slot 1
>--------------|-------------|------------|-----------|----------|-----------|-----------|-------->
Slave 1                  Resp speak
Slave 2                                           Resp Anyone            Resp SetSlot

Master                  Msg Speak                Msg Anyone             Msg Speak
                          Slot 2                                          Slot 1
>--------------|-------------|------------|-----------|----------------------|-----------|-------->
Slave 1    Resp speak                                                                Resp speak
Slave 2                               Resp speak

-------------------------------------------------------------------------------------------------*/

//! Définit une classe de communication TDMA
class QTPLUSSHARED_EXPORT CTDMADevice : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur avec paramètres
    CTDMADevice(QIODevice* pDevice, PTDMASerial tSeriaNumber, int iMaxBytesPerSecond, bool bIsMaster = false);

    //! Destructeur
    virtual ~CTDMADevice();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne le numéro de série de cette entité
    PTDMASerial getSerialNumber() const;

    //! Retourne les numéros de série des abonnés
    QVector<PTDMASerial> getAllUserSerialNumbers() const;

    //!
    virtual bool isSequential() const;

    //!
    virtual qint64 bytesAvailable() const;

    //!
    virtual qint64 bytesToWrite() const;

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //! Lecture
    QByteArray readFromSerial(quint16 uiSerialNumber);

    //! A réimplémenter pour mettre sous tension le module d'émission
    //! Retourne le temps en millisecondes de mise sous tension
    virtual int powerOn();

    //! A réimplémenter pour mettre hors tension le module d'émission
    virtual void powerOff();

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

private slots:

    //! Appelé sur timer, l'intervalle de temps d"pend du mode maître/esclave
    void onTimeout();

    //!
    void onReadyRead();

    //-------------------------------------------------------------------------------------------------
    // Classes imbriquées
    //-------------------------------------------------------------------------------------------------

private:

#pragma pack (push, 1)

    // Définit les octets envoyés par le maître pour donner l'ordre à un esclave de parler
    typedef struct tag_TMasterData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        PTDMASlot       ucSlot;
    } TMasterData_SlaveSpeak;

    // Définit l'entête envoyée par l'esclave en réponse à l'ordre de parler
    typedef struct tag_TSlaveData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        unsigned char   ucNumBytes;
    } TSlaveData_SlaveSpeak;

    // Définit les octets envoyés par le maître pour donner son slot à un esclave
    typedef struct tag_TMasterData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        unsigned char   ucMaxBytesPerSlot;
        PTDMAAction     ucActionEcho;
    } TMasterData_SetSlot;

    // Définit les octets envoyés par l'esclave en accusé réception du slot
    typedef struct tag_TSlaveData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        PTDMAAction     ucActionEcho;
    } TSlaveData_SetSlot;

    // Définit les octets envoyés par l'esclave pour une demande d'abonnement au réseau
    typedef struct tag_TSlaveData_Anyone
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMAAction     ucActionEcho;
    } TSlaveData_Anyone;

#pragma pack (pop)

    //! Actions possibles maître/esclave
    enum EAction
    {
        aMasterSpeak        = 0x01,
        aSlaveSpeak         = 0x02,
        aSlaveSpeakResponse = 0x03,
        aSetSlot            = 0xFB,
        aSetSlotResponse    = 0xFC,
        aAnyone             = 0xFD,
        aAnyoneResponse     = 0xFE,
        aReset              = 0xFF
    };

    class CClient;
    friend class CClient;

    //! Données d'un client abonné ou en demande d'abonnement
    class CClient
    {
    public:

        CClient()
            : m_tSerialNumber(0)
            , m_tSlot(CTDMADevice::s_ucBadSlot)
            , m_tLastSpeakTime(QDateTime::currentDateTime())
        {
        }

        CClient(PTDMASerial tSerialNumber, PTDMASlot ucSlot = CTDMADevice::s_ucBadSlot)
            : m_tSerialNumber(tSerialNumber)
            , m_tSlot(ucSlot)
            , m_tLastSpeakTime(QDateTime::currentDateTime())
        {
        }

        PTDMASerial m_tSerialNumber;    // Numéro de série du client
        PTDMASlot   m_tSlot;            // Slot temporel alloué au client
        QDateTime   m_tLastSpeakTime;   // Horodatage de la dernière émission reçue de ce client
        QByteArray  m_baData;           // Données entrantes pour ce client
    };

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

private:

    //! Lecture de données
    virtual qint64 readData(char * data, qint64 maxSize);

    //! Ecriture de données
    virtual qint64 writeData(const char * data, qint64 maxSize);

    //! Gère les données lues sur le périphérique d'entrée
    int processInput(const QByteArray& baData);

    //! Gère les données lues sur le périphérique d'entrée pour le maître
    int processInput_Master(const QByteArray& baData);

    //! Gère les données lues sur le périphérique d'entrée pour l'esclave
    int processInput_Slave(const QByteArray& baData);

    //! Gère le message d'émission de l'esclave par le maître
    void handleSlaveSpeak_Master(const TSlaveData_SlaveSpeak* pSpeak, const QByteArray& baData);

    //! Gère une nouvelle demande d'abonnement par le maître
    void handleNewUser_Master(const TSlaveData_Anyone* pAnyone);

    //! Gère le retour d'assignation de slot par le maître
    void handleSetSlot_Master(const TSlaveData_SetSlot* pSetSlot);

    //! Gère l'émission de données par l'esclave
    void handleSpeak_Slave(const TMasterData_SlaveSpeak* pSpeak);

    //! Gère la réception d'assignation de slot par l'esclave
    void handleSetSlot_Slave(const TMasterData_SetSlot* pSetSlot);

    //! Gère la demande d'identification par l'esclave
    void handleAnyone_Slave();

    //! Gère la demande de remise à zéro des compteurs par l'esclave
    void handleReset_Slave();

    //! Le maître envoi un ordre d'émission de donénes aux esclaves
    void sendSpeak();

    //! Le maître assigne un slot à un nouvel abonné
    void sendSetSlot();

    //! Le maître envoi un signal de demande d'identification
    void sendAnyone();

    //! Le maître demande une remise à zéro des compteurs des esclaves
    void sendReset();

    //! Retourne un numéro de slot libre
    PTDMASlot getFreeSlot() const;

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

private:

    bool                       m_bIsMaster;                 // Cette entité est-elle maître?
    bool                       m_bAntennaPowered;           // Le module de comm est activé?
    PTDMASerial                m_tSeriaNumber;              // Numéro de série de cette entité
    PTDMASlot                  m_tSlot;                     // Slot alloué par le maître
    int                        m_iMaxBytesPerSecond;        // Inutilisé pour l'instant
    int                        m_iMaxBytesPerSlot;          // Donné par le maître
    int                        m_iNumFramesBeforeIdent;     // Pour l'esclave
    int                        m_iNumBytesToIgnore;         // Pour l'esclave
    QIODevice*                 m_pDevice;                   // Device d'entrée/sortie des données
    QTimer                     m_tTimer;
    QDateTime                  m_tLastInputTime;            // Pour le maître
    QDateTime                  m_tLastSpeakTime;            // Pour l'esclave, sert à MST/MHT antenne
    QDateTime                  m_tPowerOnTime;              // Heure à laquelle le module de comm a été mis sous tension
    QByteArray                 m_baOutput;                  // Buffer de données de sortie
    QByteArray                 m_baInput;                   // Buffer de données d'entrée
    QByteArray                 m_baRawInput;                // Buffer de données d'entrée brutes
    QVector<CClient>           m_vNewUsers;                 // Clients en attente d'un slot
    QMap<PTDMASlot, CClient>   m_mRegisteredUsers;          // Clients abonnés

    static PTDMASlot           s_ucBadSlot;                 // Constante indiquant un mauvais numéro de slot
    static PTDMASlot           s_ucFirstSlot;               // Constante indiquant le 1er numéro de slot possible
    static PTDMASlot           s_ucLastSlot;                // Constante indiquant le dernier numéro de slot possible
};
