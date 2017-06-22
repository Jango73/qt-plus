
#pragma once

#include <QMap>
#include <QByteArray>

#include "SingleChannelDevice.h"

class SingleChannelDeviceRelay : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    SingleChannelDeviceRelay();

    //! Destructor
    virtual ~SingleChannelDeviceRelay();

    //-------------------------------------------------------------------------------------------------
    // Public control methods
    //-------------------------------------------------------------------------------------------------

    //!
    void addDevice(SingleChannelDevice* pDevice);

    //! Read data
    qint64 readData(SingleChannelDevice* pCaller, char * data, qint64 maxSize);

    //! Write data
    qint64 writeData(SingleChannelDevice* pCaller, const char * data, qint64 maxSize);

    //-------------------------------------------------------------------------------------------------
    // Signals
    //-------------------------------------------------------------------------------------------------

signals:

    void readyRead(SingleChannelDevice* pDevice);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

private:

    QMap<SingleChannelDevice*, QByteArray>      m_mDevices;
};
