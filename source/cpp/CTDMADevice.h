
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

//! D�finit une classe de communication TDMA
class QTPLUSSHARED_EXPORT CTDMADevice : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur avec param�tres
    CTDMADevice(QIODevice* pDevice, PTDMASerial tSeriaNumber, int iMaxBytesPerSecond, bool bIsMaster = false);

    //! Destructeur
    virtual ~CTDMADevice();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne le num�ro de s�rie de cette entit�
    PTDMASerial getSerialNumber() const;

    //! Retourne les num�ros de s�rie des abonn�s
    QVector<PTDMASerial> getAllUserSerialNumbers() const;

    //!
    virtual bool isSequential() const;

    //!
    virtual qint64 bytesAvailable() const;

    //!
    virtual qint64 bytesToWrite() const;

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //! Lecture
    QByteArray readFromSerial(quint16 uiSerialNumber);

    //! A r�impl�menter pour mettre sous tension le module d'�mission
    //! Retourne le temps en millisecondes de mise sous tension
    virtual int powerOn();

    //! A r�impl�menter pour mettre hors tension le module d'�mission
    virtual void powerOff();

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

private slots:

    //! Appel� sur timer, l'intervalle de temps d"pend du mode ma�tre/esclave
    void onTimeout();

    //!
    void onReadyRead();

    //-------------------------------------------------------------------------------------------------
    // Classes imbriqu�es
    //-------------------------------------------------------------------------------------------------

private:

#pragma pack (push, 1)

    // D�finit les octets envoy�s par le ma�tre pour donner l'ordre � un esclave de parler
    typedef struct tag_TMasterData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        PTDMASlot       ucSlot;
    } TMasterData_SlaveSpeak;

    // D�finit l'ent�te envoy�e par l'esclave en r�ponse � l'ordre de parler
    typedef struct tag_TSlaveData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        unsigned char   ucNumBytes;
    } TSlaveData_SlaveSpeak;

    // D�finit les octets envoy�s par le ma�tre pour donner son slot � un esclave
    typedef struct tag_TMasterData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        unsigned char   ucMaxBytesPerSlot;
        PTDMAAction     ucActionEcho;
    } TMasterData_SetSlot;

    // D�finit les octets envoy�s par l'esclave en accus� r�ception du slot
    typedef struct tag_TSlaveData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        PTDMAAction     ucActionEcho;
    } TSlaveData_SetSlot;

    // D�finit les octets envoy�s par l'esclave pour une demande d'abonnement au r�seau
    typedef struct tag_TSlaveData_Anyone
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMAAction     ucActionEcho;
    } TSlaveData_Anyone;

#pragma pack (pop)

    //! Actions possibles ma�tre/esclave
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

    //! Donn�es d'un client abonn� ou en demande d'abonnement
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

        PTDMASerial m_tSerialNumber;    // Num�ro de s�rie du client
        PTDMASlot   m_tSlot;            // Slot temporel allou� au client
        QDateTime   m_tLastSpeakTime;   // Horodatage de la derni�re �mission re�ue de ce client
        QByteArray  m_baData;           // Donn�es entrantes pour ce client
    };

    //-------------------------------------------------------------------------------------------------
    // M�thodes prot�g�es
    //-------------------------------------------------------------------------------------------------

private:

    //! Lecture de donn�es
    virtual qint64 readData(char * data, qint64 maxSize);

    //! Ecriture de donn�es
    virtual qint64 writeData(const char * data, qint64 maxSize);

    //! G�re les donn�es lues sur le p�riph�rique d'entr�e
    int processInput(const QByteArray& baData);

    //! G�re les donn�es lues sur le p�riph�rique d'entr�e pour le ma�tre
    int processInput_Master(const QByteArray& baData);

    //! G�re les donn�es lues sur le p�riph�rique d'entr�e pour l'esclave
    int processInput_Slave(const QByteArray& baData);

    //! G�re le message d'�mission de l'esclave par le ma�tre
    void handleSlaveSpeak_Master(const TSlaveData_SlaveSpeak* pSpeak, const QByteArray& baData);

    //! G�re une nouvelle demande d'abonnement par le ma�tre
    void handleNewUser_Master(const TSlaveData_Anyone* pAnyone);

    //! G�re le retour d'assignation de slot par le ma�tre
    void handleSetSlot_Master(const TSlaveData_SetSlot* pSetSlot);

    //! G�re l'�mission de donn�es par l'esclave
    void handleSpeak_Slave(const TMasterData_SlaveSpeak* pSpeak);

    //! G�re la r�ception d'assignation de slot par l'esclave
    void handleSetSlot_Slave(const TMasterData_SetSlot* pSetSlot);

    //! G�re la demande d'identification par l'esclave
    void handleAnyone_Slave();

    //! G�re la demande de remise � z�ro des compteurs par l'esclave
    void handleReset_Slave();

    //! Le ma�tre envoi un ordre d'�mission de don�nes aux esclaves
    void sendSpeak();

    //! Le ma�tre assigne un slot � un nouvel abonn�
    void sendSetSlot();

    //! Le ma�tre envoi un signal de demande d'identification
    void sendAnyone();

    //! Le ma�tre demande une remise � z�ro des compteurs des esclaves
    void sendReset();

    //! Retourne un num�ro de slot libre
    PTDMASlot getFreeSlot() const;

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

private:

    bool                       m_bIsMaster;                 // Cette entit� est-elle ma�tre?
    bool                       m_bAntennaPowered;           // Le module de comm est activ�?
    PTDMASerial                m_tSeriaNumber;              // Num�ro de s�rie de cette entit�
    PTDMASlot                  m_tSlot;                     // Slot allou� par le ma�tre
    int                        m_iMaxBytesPerSecond;        // Inutilis� pour l'instant
    int                        m_iMaxBytesPerSlot;          // Donn� par le ma�tre
    int                        m_iNumFramesBeforeIdent;     // Pour l'esclave
    int                        m_iNumBytesToIgnore;         // Pour l'esclave
    QIODevice*                 m_pDevice;                   // Device d'entr�e/sortie des donn�es
    QTimer                     m_tTimer;
    QDateTime                  m_tLastInputTime;            // Pour le ma�tre
    QDateTime                  m_tLastSpeakTime;            // Pour l'esclave, sert � MST/MHT antenne
    QDateTime                  m_tPowerOnTime;              // Heure � laquelle le module de comm a �t� mis sous tension
    QByteArray                 m_baOutput;                  // Buffer de donn�es de sortie
    QByteArray                 m_baInput;                   // Buffer de donn�es d'entr�e
    QByteArray                 m_baRawInput;                // Buffer de donn�es d'entr�e brutes
    QVector<CClient>           m_vNewUsers;                 // Clients en attente d'un slot
    QMap<PTDMASlot, CClient>   m_mRegisteredUsers;          // Clients abonn�s

    static PTDMASlot           s_ucBadSlot;                 // Constante indiquant un mauvais num�ro de slot
    static PTDMASlot           s_ucFirstSlot;               // Constante indiquant le 1er num�ro de slot possible
    static PTDMASlot           s_ucLastSlot;                // Constante indiquant le dernier num�ro de slot possible
};
