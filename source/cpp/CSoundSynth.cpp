
// Qt
#include <QDebug>

// Application
#include "CSoundSynth.h"

const int DataSampleRateHz  = 44100;

//-------------------------------------------------------------------------------------------------

/*!
    \class CSoundSynth
    \inmodule qt-plus
    \brief A real-time sound generation class.

    Base class for sound synths, the synthesize must be overridden
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CSoundSynth.
*/
CSoundSynth::CSoundSynth()
    : m_tGenerator(this)
    , m_tDevice(QAudioDeviceInfo::defaultOutputDevice())
{
    m_tFormat.setSampleRate(DataSampleRateHz);
    m_tFormat.setChannelCount(1);
    m_tFormat.setSampleSize(16);
    m_tFormat.setCodec("audio/pcm");
    m_tFormat.setByteOrder(QAudioFormat::LittleEndian);
    m_tFormat.setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());

    if (!info.isFormatSupported(m_tFormat))
    {
        qWarning() << "Default format not supported - trying to use nearest";
        m_tFormat = info.nearestFormat(m_tFormat);
    }

    open(QIODevice::ReadOnly);

    m_tAudioOutput = new QAudioOutput(m_tDevice, m_tFormat, this);
    m_tAudioOutput->start(this);

    m_tGenerator.start();
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CSoundSynth.
*/
CSoundSynth::~CSoundSynth()
{
    close();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns generated sound data for position in \a pos.
*/
QByteArray CSoundSynth::synthesize(qint64 pos)
{
    Q_UNUSED(pos);

    return QByteArray();
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::readData. \br\br
    Returns number of bytes read to \a data, limited by \a len
*/
qint64 CSoundSynth::readData(char* data, qint64 len)
{
    qint64 iRemaining = len;
    char* pCurrentData = data;

    if (m_lBuffers.count() == 0)
    {
        m_lBuffers << m_tGenerator.getBuffers();
    }

    while (true)
    {
        if (iRemaining == 0) break;
        if (m_lBuffers.count() == 0) break;

        if (iRemaining >= m_lBuffers[0].count())
        {
            memcpy(pCurrentData, m_lBuffers[0].constData(), m_lBuffers[0].count());
            pCurrentData += m_lBuffers[0].count();
            iRemaining -= m_lBuffers[0].count();
            m_lBuffers.removeAt(0);
        }
        else
        {
            memcpy(pCurrentData, m_lBuffers[0].constData(), iRemaining);
            m_lBuffers[0].remove(0, iRemaining);
            iRemaining = 0;
            pCurrentData += iRemaining;
        }
    }

    return len - iRemaining;
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::writeData. \br\br
    Returns 0. \a data and \a len are ignored.
*/
qint64 CSoundSynth::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);

    return 0;
}

//-------------------------------------------------------------------------------------------------

/*!
    Overrides QIODevice::bytesAvailable. \br\br
    Returns available bytes in device.
*/
qint64 CSoundSynth::bytesAvailable() const
{
    qint64 total = 0;

    for (QByteArray baData : m_lBuffers)
    {
        total += baData.count();
    }

    return total + QIODevice::bytesAvailable();
}

//-------------------------------------------------------------------------------------------------

CSoundSynth::CSoundSynthGenerator::CSoundSynthGenerator(CSoundSynth* pSynth)
    : m_tMutex(QMutex::Recursive)
    , m_pSynth(pSynth)
    , m_iPosition(0)
    , m_bRun(true)
{
}

//-------------------------------------------------------------------------------------------------

CSoundSynth::CSoundSynthGenerator::~CSoundSynthGenerator()
{
    stopMe();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the audio buffers.
*/
QList<QByteArray> CSoundSynth::CSoundSynthGenerator::getBuffers()
{
    QList<QByteArray> baReturnValue;

    if (m_tMutex.tryLock(200))
    {
        for (QByteArray baBuffer : m_lBuffers)
        {
            baReturnValue << baBuffer;
        }

        m_lBuffers.clear();

        m_tMutex.unlock();
    }
    else
    {
        qWarning() << "Unable to lock audio mutex";
    }

    return baReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Stops the synthesize thread.
*/
void CSoundSynth::CSoundSynthGenerator::stopMe()
{
    m_bRun = false;
    wait();
}

//-------------------------------------------------------------------------------------------------

void CSoundSynth::CSoundSynthGenerator::run()
{
    if (m_pSynth != nullptr)
    {
        while (m_bRun)
        {
            if (m_tMutex.tryLock(200))
            {
                int iBufferCount = m_lBuffers.count();
                m_tMutex.unlock();

                if (iBufferCount < 3)
                {
                    QByteArray baNewData = m_pSynth->synthesize(m_iPosition);

                    if (m_tMutex.tryLock(200))
                    {
                        m_lBuffers << baNewData;
                        m_iPosition += m_lBuffers.last().count();
                        m_tMutex.unlock();
                    }
                    else
                    {
                        qWarning() << "Unable to lock audio mutex";
                    }
                }
            }
            else
            {
                qWarning() << "Unable to lock audio mutex";
            }

            msleep(50);
        }
    }
}
