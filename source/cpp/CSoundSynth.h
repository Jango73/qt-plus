
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QAudioOutput>
#include <QByteArray>
#include <QIODevice>
#include <QThread>
#include <QMutex>

// Application
#include "CInterpolator.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CSoundSynth : public QIODevice
{
    Q_OBJECT

    friend class CSoundSynthGenerator;

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CSoundSynth();

    //! Destructor
    virtual ~CSoundSynth() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Override of QIODevice::readData
    virtual qint64 readData(char* data, qint64 len) Q_DECL_OVERRIDE;

    //! Override of QIODevice::writeData
    virtual qint64 writeData(const char *data, qint64 len) Q_DECL_OVERRIDE;

    //! Override of QIODevice::bytesAvailable
    virtual qint64 bytesAvailable() const Q_DECL_OVERRIDE;

    //! Method to implement when overriding this class
    virtual QByteArray synthesize(qint64 pos);

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    //-------------------------------------------------------------------------------------------------
    // Inner classes
    //-------------------------------------------------------------------------------------------------

protected:

    class CSoundSynthGenerator : public QThread
    {
    public:

        //-------------------------------------------------------------------------------------------------
        // Constructors and destructor
        //-------------------------------------------------------------------------------------------------

        CSoundSynthGenerator(CSoundSynth* pSynth);

        virtual ~CSoundSynthGenerator() Q_DECL_OVERRIDE;

        //-------------------------------------------------------------------------------------------------
        // Getters
        //-------------------------------------------------------------------------------------------------

        //! Returns the generated audio buffers if any
        QList<QByteArray> getBuffers();

        //-------------------------------------------------------------------------------------------------
        // Control methods
        //-------------------------------------------------------------------------------------------------

        //! Stops the thread
        void stopMe();

        //! The main thread method
        virtual void run() Q_DECL_OVERRIDE;

        //-------------------------------------------------------------------------------------------------
        // Properties
        //-------------------------------------------------------------------------------------------------

    protected:

        QMutex                  m_tMutex;       // For data protection
        CSoundSynth*            m_pSynth;       // The master of this class
        QList<QByteArray>       m_lBuffers;     // The generated buffers
        qint64                  m_iPosition;    // The current position in samples
        bool                    m_bRun;         // Running flag
    };

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    CSoundSynthGenerator    m_tGenerator;       // The thread that generates audio
    QAudioDeviceInfo        m_tDevice;          // The output device
    QAudioOutput*           m_tAudioOutput;     // The audio output
    QAudioFormat            m_tFormat;          // The audio format
    QList<QByteArray>       m_lBuffers;         // The buffers comming from CSoundSynthGenerator
};
