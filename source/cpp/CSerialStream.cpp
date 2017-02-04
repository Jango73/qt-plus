
// Qt
#include <QDebug>

// Application
#include "CSerialStream.h"

//-------------------------------------------------------------------------------------------------

CSerialStream::CSerialStream(const QString& sName, const QMap<QString, QString>& sParamMap)
    : CConnectedStream(sName)
    , m_tMutex(QMutex::Recursive)
    , m_tPort(this)
{
    if (sParamMap.contains(STREAM_PARAM_BAUD))
    {
        qint32 rate = sParamMap[STREAM_PARAM_BAUD].toInt();
        m_tPort.setBaudRate(rate);
    }

    if (sParamMap.contains(STREAM_PARAM_DATABITS))
    {
        QSerialPort::DataBits bits = QSerialPort::Data8;

        if (sParamMap[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_5)
        {
            bits = QSerialPort::Data5;
        }
        else if (sParamMap[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_6)
        {
            bits = QSerialPort::Data6;
        }
        else if (sParamMap[STREAM_PARAM_DATABITS] == STREAM_PARAM_DATA_7)
        {
            bits = QSerialPort::Data7;
        }

        m_tPort.setDataBits(bits);
    }

    if (sParamMap.contains(STREAM_PARAM_STOP))
    {
        QSerialPort::StopBits bits = QSerialPort::OneStop;

        if (sParamMap[STREAM_PARAM_STOP] == STREAM_PARAM_STOP_1_5)
        {
            bits = QSerialPort::OneAndHalfStop;
        }
        else if (sParamMap[STREAM_PARAM_STOP] == STREAM_PARAM_STOP_2)
        {
            bits = QSerialPort::TwoStop;
        }

        m_tPort.setStopBits(bits);
    }

    if (sParamMap.contains(STREAM_PARAM_PARITY))
    {
        QSerialPort::Parity parity = QSerialPort::NoParity;

        if (sParamMap[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_EVEN)
        {
            parity = QSerialPort::EvenParity;
        }
        else if (sParamMap[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_ODD)
        {
            parity = QSerialPort::OddParity;
        }
        else if (sParamMap[STREAM_PARAM_PARITY] == STREAM_PARAM_PARITY_SPACE)
        {
            parity = QSerialPort::SpaceParity;
        }

        m_tPort.setParity(parity);
    }

    connect(&m_tPort, SIGNAL(readyRead()), this, SLOT(onPortReadyRead()));
}

//-------------------------------------------------------------------------------------------------

CSerialStream::~CSerialStream()
{
	QIODevice::close();
}

//-------------------------------------------------------------------------------------------------

qint64 CSerialStream::bytesAvailable() const
{
    return m_tPort.bytesAvailable();
}

//-------------------------------------------------------------------------------------------------

//! Lecture de données
qint64 CSerialStream::readData(char* data, qint64 maxSize)
{
    return m_tPort.read(data, maxSize);
}

//-------------------------------------------------------------------------------------------------

//! Ecriture de données
qint64 CSerialStream::writeData(const char* data, qint64 maxSize)
{
    return m_tPort.write(data, maxSize);
}

//-------------------------------------------------------------------------------------------------

void CSerialStream::onPortReadyRead()
{
    if (m_iMinBytesForReadyRead == 0 || bytesAvailable() >= m_iMinBytesForReadyRead)
    {
        emit readyRead();
    }
}
