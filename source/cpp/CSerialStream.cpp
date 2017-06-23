
// Application
#include "CSerialStream.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CSerialStream
    \inmodule qt-plus
    \brief A socket stream.

    This is a wrapper of QSerialPort, used by CStreamFactory.

    \sa CStreamFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CSerialStream. \br\br
    \a sName is a serial connection name like "/dev/ttyS1" or "COM2" \br
    \a sParameters are additional parameters for serial ports. See STREAM_PARAM_* in CSerialStream.h.
*/
CSerialStream::CSerialStream(const QString& sName, const QMap<QString, QString>& sParameters)
    : CConnectedStream(sName)
    , m_tMutex(QMutex::Recursive)
    , m_tPort(this)
{
    if (sParameters.contains(STREAM_PARAM_BAUD))
    {
        qint32 rate = sParameters[STREAM_PARAM_BAUD].toInt();
        m_tPort.setBaudRate(rate);
    }

    if (sParameters.contains(STREAM_PARAM_DATABITS))
    {
        QSerialPort::DataBits bits = QSerialPort::Data8;

        if (sParameters[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_5)
        {
            bits = QSerialPort::Data5;
        }
        else if (sParameters[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_6)
        {
            bits = QSerialPort::Data6;
        }
        else if (sParameters[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_7)
        {
            bits = QSerialPort::Data7;
        }

        m_tPort.setDataBits(bits);
    }

    if (sParameters.contains(STREAM_PARAM_STOP))
    {
        QSerialPort::StopBits bits = QSerialPort::OneStop;

        if (sParameters[STREAM_PARAM_STOP] == STREAM_PARAM_STOP_1_5)
        {
            bits = QSerialPort::OneAndHalfStop;
        }
        else if (sParameters[STREAM_PARAM_STOP] == STREAM_PARAM_STOP_2)
        {
            bits = QSerialPort::TwoStop;
        }

        m_tPort.setStopBits(bits);
    }

    if (sParameters.contains(STREAM_PARAM_PARITY))
    {
        QSerialPort::Parity parity = QSerialPort::NoParity;

        if (sParameters[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_EVEN)
        {
            parity = QSerialPort::EvenParity;
        }
        else if (sParameters[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_ODD)
        {
            parity = QSerialPort::OddParity;
        }
        else if (sParameters[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_SPACE)
        {
            parity = QSerialPort::SpaceParity;
        }

        m_tPort.setParity(parity);
    }

    connect(&m_tPort, SIGNAL(readyRead()), this, SLOT(onPortReadyRead()));
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CSerialStream.
*/
CSerialStream::~CSerialStream()
{
	QIODevice::close();
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::bytesAvailable. \br\br
    Returns available bytes in device.
*/
qint64 CSerialStream::bytesAvailable() const
{
    return m_tPort.bytesAvailable();
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::readData. \br\br
    Returns number of bytes read to \a data, limited by \a maxSize
*/
qint64 CSerialStream::readData(char* data, qint64 maxSize)
{
    return m_tPort.read(data, maxSize);
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::writeData. \br\br
    Returns number of bytes written to \a data, limited by \a maxSize
*/
qint64 CSerialStream::writeData(const char* data, qint64 maxSize)
{
    return m_tPort.write(data, maxSize);
}

//-------------------------------------------------------------------------------------------------

/*!
    This slot is called when bytes are available on QSerialPort.
*/
void CSerialStream::onPortReadyRead()
{
    if (m_iMinBytesForReadyRead == 0 || bytesAvailable() >= m_iMinBytesForReadyRead)
    {
        emit readyRead();
    }
}
