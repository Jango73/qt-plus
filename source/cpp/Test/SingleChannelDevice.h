
#pragma once

#include <QVector>
#include <QIODevice>
#include <QByteArray>

class SingleChannelDeviceRelay;

class SingleChannelDevice : public QIODevice
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    SingleChannelDevice(QString sName, SingleChannelDeviceRelay* pRelay);

    //! Destructor
    virtual ~SingleChannelDevice();

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //! Read data
    virtual qint64 readData(char * data, qint64 maxSize) Q_DECL_OVERRIDE;

    //! Write data
    virtual qint64 writeData(const char * data, qint64 maxSize) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    void onReadyRead(SingleChannelDevice* pDevice);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

private:

    QString                     m_sName;
    SingleChannelDeviceRelay*   m_pRelay;
};
