
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

//! Defines a TDMA (Time Division for Multiple Access) class
class QTPLUSSHARED_EXPORT CTDMADevice : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Parametered constructor
    CTDMADevice(QIODevice* pDevice, PTDMASerial tSeriaNumber, int iMaxBytesPerSecond = 0, bool bIsMaster = false);

    //! Destructor
    virtual ~CTDMADevice() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Sets the serial number
    void setSerialNumber(PTDMASerial tSerialNumber);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns this entity's serial number
    PTDMASerial serialNumber() const;

    //! Returns all registered devices' serial numbers
    QVector<PTDMASerial> getAllUserSerialNumbers() const;

    //!
    virtual bool isSequential() const Q_DECL_OVERRIDE;

    //!
    virtual qint64 bytesAvailable() const Q_DECL_OVERRIDE;

    //!
    virtual qint64 bytesToWrite() const Q_DECL_OVERRIDE;

    //!
    QDateTime now() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    qint64 bytesAvailableFromSerial(quint16 uiSerialNumber);

    //! Read
    QByteArray readFromSerial(quint16 uiSerialNumber);

    //! Meant to be implemented by subclasses when it is time to turn on any comm device, like an antenna
    //! Returns an estimated power on time in milliseconds
    virtual int powerOn();

    //! Meant to be implemented by subclasses when it is time to turn off any comm device, like an antenna
    virtual void powerOff();

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    //! Called by a timer, the interval depends on the master/slave mode
    void onTimeout();

    //! Called by a timer, the interval depends on the master/slave mode
    void onMaintenanceTimeout();

    //!
    void onReadyRead();

    //-------------------------------------------------------------------------------------------------
    // Classes imbriquées
    //-------------------------------------------------------------------------------------------------

protected:

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

    //! Defines the data sent by the master to order a slave to speak
    typedef struct tag_TMasterData_MasterSpeak
    {
        PTDMAAction     ucAction;
        unsigned char   ucNumBytes;
    } TMasterData_MasterSpeak;

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
            , m_tLastOrderSpeakTime(QDateTime::currentDateTime())
            , m_tLastSpeakTime(QDateTime::currentDateTime())
            , m_iScore(0)
        {
        }

        CClient(PTDMASerial tSerialNumber, PTDMASlot ucSlot = CTDMADevice::s_ucBadSlot)
            : m_tSerialNumber(tSerialNumber)
            , m_tSlot(ucSlot)
            , m_tLastOrderSpeakTime(QDateTime::currentDateTime())
            , m_tLastSpeakTime(QDateTime::currentDateTime())
            , m_iScore(0)
        {
        }

        void incScore()
        {
            m_iScore += 2;

            if (m_iScore > m_iMaxScore)
            {
                m_iScore = m_iMaxScore;
            }
        }

        void decScore()
        {
            m_iScore--;

            if (m_iScore < 0)
            {
                m_iScore = 0;
            }
        }

        PTDMASerial m_tSerialNumber;        // Serial number
        PTDMASlot   m_tSlot;                // Assigned temporal slot
        QDateTime   m_tLastOrderSpeakTime;  // Time at which client was ordered to speak
        QDateTime   m_tLastSpeakTime;       // Time at which client last spoke
        QByteArray  m_baData;               // Incoming payload
        qint32      m_iScore;               // Speak score

        static const qint32 m_iMaxScore = 10;
    };

    //-------------------------------------------------------------------------------------------------
    // Protected methods
    //-------------------------------------------------------------------------------------------------

protected:

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

    //!
    void handleMasterSpeak_Slave(const TMasterData_MasterSpeak* pSpeak, const QByteArray& baData);

    //! Handles a register request
    void handleNewUser_Master(const TSlaveData_Anyone* pAnyone);

    //! Handles slot assignment acknowledge
    void handleSetSlot_Master(const TSlaveData_SetSlot* pSetSlot);

    //!
    void handleSpeak_Master();

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

protected:

    bool                       m_bIsMaster;                 // Is this entity a master?
    bool                       m_bAntennaPowered;           // Is the comm module activated?
    PTDMASerial                m_tSeriaNumber;              // Serial number for this entity
    PTDMASlot                  m_tSlot;                     // Allocated slot
    int                        m_iMaxBytesPerSecond;        // Unused
    int                        m_iMaxBytesPerSlot;          // Given by master
    int                        m_iNumFramesBeforeIdent;     // For slave
    QIODevice*                 m_pDevice;                   // IO device for data
    QTimer                     m_tTimer;
    QTimer                     m_tMaintenanceTimer;
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
