
// Application
#include "CJoystickReader.h"
#include "CLogger.h"

#ifndef WIN32
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/joystick.h>
#endif

//-------------------------------------------------------------------------------------------------

/*!
    \class CJoystickReader
    \inmodule qt-plus
    \brief Non blocking reader for a local joystick device.

    Linux implementation reads the joystick API (/dev/input/jsN).
    On other platforms the reader stays disconnected.
    Axis values are normalized to [-1.0, 1.0] with a dead zone around center.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Returns the operating system file name for \a uiDeviceIndex. \br\br
    Linux joystick API file (/dev/input/jsN), placeholder text on Windows.
*/
QString CJoystickReader::deviceFileName(unsigned int uiDeviceIndex)
{
#ifdef WIN32
    Q_UNUSED(uiDeviceIndex)
    return QString();
#else
    return QString("/dev/input/js%1").arg(uiDeviceIndex);
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Opens the device handle, keeps previous state on failure. \br\br
    Only logs on connectivity transitions to avoid log flooding.
*/
void CJoystickReader::openDevice()
{
#ifdef WIN32
    return;
#else
    if (m_iDeviceHandle >= 0)
    {
        return;
    }

    QString sFileName = deviceFileName(m_uiDeviceIndex);

    int iHandle = ::open(sFileName.toLocal8Bit().constData(), O_RDONLY | O_NONBLOCK);

    if (iHandle < 0)
    {
        m_bConnected = false;

        if (m_bAccessNotified == false)
        {
            m_bAccessNotified = true;
            LOG_DEBUG(QString("CJoystickReader : no joystick on %1 (%2)").arg(sFileName).arg(QString(strerror(errno))));
        }

        return;
    }

    char cAxisCount = 0;
    char cButtonCount = 0;

    if (::ioctl(iHandle, JSIOCGAXES, &cAxisCount) < 0)
    {
        cAxisCount = 0;
    }

    if (::ioctl(iHandle, JSIOCGBUTTONS, &cButtonCount) < 0)
    {
        cButtonCount = 0;
    }

    char sName[128];
    sName[0] = 0;

    if (::ioctl(iHandle, JSIOCGNAME(sizeof(sName)), sName) >= 0)
    {
        m_sDeviceName = QString(sName);
    }
    else
    {
        m_sDeviceName.clear();
    }

    m_mAxisStates.clear();
    m_mButtonStates.clear();

    for (int iIndex = 0; iIndex < int(cAxisCount); iIndex++)
    {
        m_mAxisStates[static_cast<unsigned int>(iIndex)] = 0.0;
    }

    for (int iIndex = 0; iIndex < int(cButtonCount); iIndex++)
    {
        m_mButtonStates[static_cast<unsigned int>(iIndex)] = false;
    }

    m_iDeviceHandle = iHandle;
    m_bConnected = true;
    m_bAccessNotified = false;

    LOG_DEBUG(QString("CJoystickReader : opened %1 (%2)").arg(sFileName).arg(m_sDeviceName));
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Closes the device handle.
*/
void CJoystickReader::closeDevice()
{
#ifdef WIN32
    return;
#else
    if (m_iDeviceHandle >= 0)
    {
        ::close(m_iDeviceHandle);
        m_iDeviceHandle = -1;
    }

    if (m_bConnected == true)
    {
        LOG_DEBUG(QString("CJoystickReader : closed %1").arg(deviceFileName(m_uiDeviceIndex)));
    }

    m_bConnected = false;
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Reads all pending input events without blocking. \br\br
    A read error other than empty queue closes the device; the next update
    reopens it, which covers unplug and replug of the same index.
*/
void CJoystickReader::readPendingEvents()
{
#ifdef WIN32
    return;
#else
    if (m_iDeviceHandle < 0)
    {
        return;
    }

    struct js_event tEvent;

    while (true)
    {
        ssize_t iReadSize = ::read(m_iDeviceHandle, &tEvent, sizeof(tEvent));

        if (iReadSize != ssize_t(sizeof(tEvent)))
        {
            if (iReadSize < 0 && (errno == EAGAIN || errno == EINTR))
            {
                break;
            }

            closeDevice();
            break;
        }

        unsigned int uiEventType = static_cast<unsigned int>(tEvent.type & ~JS_EVENT_INIT);

        if (uiEventType == static_cast<unsigned int>(JS_EVENT_AXIS))
        {
            double dNormalized = double(tEvent.value) / double(0x7FFF);

            if (dNormalized > 1.0)
            {
                dNormalized = 1.0;
            }

            if (dNormalized < -1.0)
            {
                dNormalized = -1.0;
            }

            if (dNormalized > -m_dDeadZone && dNormalized < m_dDeadZone)
            {
                dNormalized = 0.0;
            }

            m_mAxisStates[static_cast<unsigned int>(tEvent.number)] = dNormalized;
        }
        else if (uiEventType == static_cast<unsigned int>(JS_EVENT_BUTTON))
        {
            m_mButtonStates[static_cast<unsigned int>(tEvent.number)] = (tEvent.value != 0);
        }
    }
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CJoystickReader. \br\br
    \a uiDeviceIndex is the joystick index, mapped to /dev/input/jsN on Linux.
*/
CJoystickReader::CJoystickReader(unsigned int uiDeviceIndex)
    : m_uiDeviceIndex(uiDeviceIndex)
    , m_iDeviceHandle(-1)
    , m_bConnected(false)
    , m_bAccessNotified(false)
    , m_dDeadZone(0.1)
{
    openDevice();
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CJoystickReader.
*/
CJoystickReader::~CJoystickReader()
{
    closeDevice();
}

//-------------------------------------------------------------------------------------------------

/*!
    Opens the device when needed and reads all pending input events.
*/
void CJoystickReader::update()
{
    if (m_bConnected == false)
    {
        openDevice();
    }

    if (m_bConnected == true)
    {
        readPendingEvents();
    }
}
