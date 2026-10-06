
#pragma once

#include "qtplus_global.h"

// Qt
#include <QMap>
#include <QString>

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CJoystickReader
{

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with device index (/dev/input/jsN on Linux)
    CJoystickReader(unsigned int uiDeviceIndex);

    //! Destructor
    virtual ~CJoystickReader();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Defines the dead zone applied around axis center (0.0 to 1.0)
    void setDeadZone(double dValue) { m_dDeadZone = dValue; }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns true when the device handle is open
    bool connected() const { return m_bConnected; }

    //! Returns the device index
    unsigned int deviceIndex() const { return m_uiDeviceIndex; }

    //! Returns the human readable device name, empty when unknown
    QString deviceName() const { return m_sDeviceName; }

    //! Returns the normalized axis states in range [-1.0, 1.0]
    QMap<unsigned int, double>& axisStates() { return m_mAxisStates; }

    //! Returns the button states
    QMap<unsigned int, bool>& buttonStates() { return m_mButtonStates; }

    //! Returns the dead zone applied around axis center
    double deadZone() const { return m_dDeadZone; }

    //! Returns the operating system file name for the given device index
    static QString deviceFileName(unsigned int uiDeviceIndex);

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Opens the device when needed and reads all pending input events
    void update();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    //! Opens the device handle, keeps previous state on failure
    void openDevice();

    //! Closes the device handle
    void closeDevice();

    //! Reads all pending input events without blocking
    void readPendingEvents();

    unsigned int            m_uiDeviceIndex;
    int                     m_iDeviceHandle;
    bool                    m_bConnected;
    bool                    m_bAccessNotified;
    double                  m_dDeadZone;
    QString                 m_sDeviceName;
    QMap<unsigned int, double> m_mAxisStates;
    QMap<unsigned int, bool>   m_mButtonStates;
};
