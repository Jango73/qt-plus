
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
Timeline sample:

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

//! Defines a TDMA (Time Division for Multiple Access) class
class QTPLUSSHARED_EXPORT CTDMADevice : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Parametered constructor
    CTDMADevice(QIODevice* pDevice, PTDMASerial tSeriaNumber, int iMaxBytesPerSecond, bool bIsMaster = false);

    //! Destructor
    virtual ~CTDMADevice();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns this entity's serial number
    PTDMASerial getSerialNumber() const;

    //! Returns all registered devices' serial numbers
    QVector<PTDMASerial> getAllUserSerialNumbers() const;

    //!
    virtual bool isSequential() const Q_DECL_OVERRIDE;

    //!
    virtual qint64 bytesAvailable() const Q_DECL_OVERRIDE;

    //!
    virtual qint64 bytesToWrite() const Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Read
    QByteArray readFromSerial(quint16 uiSerialNumber);

    //! Meant to be implemented by subclasses when it is time to turn on any comm device, like an antenna
    //! Returns a power on time in milliseconds
    virtual int powerOn();

    //! Meant to be implemented by subclasses when it is time to turn off any comm device, like an antenna
    virtual void powerOff();

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

private slots:

    //! Called by a timer, the interval depends on the master/slave mode
    void onTimeout();

    //!
    void onReadyRead();

    //-------------------------------------------------------------------------------------------------
    // Classes imbriquées
    //-------------------------------------------------------------------------------------------------

private:

#pragma pack (push, 1)

    //! Defines the data sent by the master to order a slave to speak
    typedef struct tag_TMasterData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        PTDMASlot       ucSlot;
    } TMasterData_SlaveSpeak;

    //! Defines the header sent by a slave in response to a speak order
    typedef struct tag_TSlaveData_SlaveSpeak
    {
        PTDMAAction     ucAction;
        unsigned char   ucNumBytes;
    } TSlaveData_SlaveSpeak;

    //! Defines the data sent by the master to assign a slave's slot
    typedef struct tag_TMasterData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        unsigned char   ucMaxBytesPerSlot;
        PTDMAAction     ucActionEcho;
    } TMasterData_SetSlot;

    //! Defines the date sent by a slave to acknowledge a slot assignment
    typedef struct tag_TSlaveData_SetSlot
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMASlot       ucSlot;
        PTDMAAction     ucActionEcho;
    } TSlaveData_SetSlot;

    //! Defines the data sent by a slave when asking for registration on the network
    typedef struct tag_TSlaveData_Anyone
    {
        PTDMAAction     ucAction;
        PTDMASerial     uiSerialNumber;
        PTDMAAction     ucActionEcho;
    } TSlaveData_Anyone;

#pragma pack (pop)

    //! Possible actions for master and slaves
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

    //! Data for a registered client
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
    // Protected methods
    //-------------------------------------------------------------------------------------------------

private:

    //! Read data
    virtual qint64 readData(char * data, qint64 maxSize) Q_DECL_OVERRIDE;

    //! Write data
    virtual qint64 writeData(const char * data, qint64 maxSize) Q_DECL_OVERRIDE;

    //! Handles incoming data
    int processInput(const QByteArray& baData);

    //! Handles incoming data for a master
    int processInput_Master(const QByteArray& baData);

    //! Handles incoming data for a slave
    int processInput_Slave(const QByteArray& baData);

    //! Handles a slave speak message
    void handleSlaveSpeak_Master(const TSlaveData_SlaveSpeak* pSpeak, const QByteArray& baData);

    //! Handles a register request
    void handleNewUser_Master(const TSlaveData_Anyone* pAnyone);

    //! Handles slot assignment acknowledge
    void handleSetSlot_Master(const TSlaveData_SetSlot* pSetSlot);

    //! Handles slave speak order
    void handleSpeak_Slave(const TMasterData_SlaveSpeak* pSpeak);

    //! Handles slot assignement given by master
    void handleSetSlot_Slave(const TMasterData_SetSlot* pSetSlot);

    //! Handles identification request by a slave
    void handleAnyone_Slave();

    //! Gère la demande de remise à zéro des compteurs par l'esclave
    void handleReset_Slave();

    //! Master sends a speak order to slaves
    void sendSpeak();

    //! Master assigns a slot to a slave
    void sendSetSlot();

    //! Master send a signal for any unidentified slave to identify itself
    //! Slaves may jam each other, in which case master signals a jam and slaves compute random delay for next speak
    void sendAnyone();

    //! Master orders slaves to reset their timers
    void sendReset();

    //! Returns a free slot
    PTDMASlot getFreeSlot() const;

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

private:

    bool                       m_bIsMaster;                 // Is this entity a master?
    bool                       m_bAntennaPowered;           // Is the comm module activated?
    PTDMASerial                m_tSeriaNumber;              // Serial number for this entity
    PTDMASlot                  m_tSlot;                     // Allocated slot
    int                        m_iMaxBytesPerSecond;        // Unused
    int                        m_iMaxBytesPerSlot;          // Given by master
    int                        m_iNumFramesBeforeIdent;     // For slave
    int                        m_iNumBytesToIgnore;         // For slave
    QIODevice*                 m_pDevice;                   // IO device for data
    QTimer                     m_tTimer;
    QDateTime                  m_tLastInputTime;            // For master
    QDateTime                  m_tLastSpeakTime;            // For slave, used to power on and off
    QDateTime                  m_tPowerOnTime;              // Time at which comm module was powered on
    QByteArray                 m_baOutput;                  // Output data buffer
    QByteArray                 m_baInput;                   // Input data buffer
    QByteArray                 m_baRawInput;                // Raw input data buffer
    QVector<CClient>           m_vNewUsers;                 // Slaves waiting for a slot
    QMap<PTDMASlot, CClient>   m_mRegisteredUsers;          // Registered slaves

    static PTDMASlot           s_ucBadSlot;                 // Constant for a bad slot number
    static PTDMASlot           s_ucFirstSlot;               // Constant for the first possible slot
    static PTDMASlot           s_ucLastSlot;                // Constant for the last possible slot
};
