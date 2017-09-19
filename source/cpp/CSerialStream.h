
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QObject>
#include <QMap>
#include <QString>
#include <QTimer>
#include <QMutex>
#include <QSerialPort>

// Application
#include "CConnectedStream.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CSerialStream : public CConnectedStream
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with parameters
    CSerialStream(const QString& sName, const QMap<QString, QString>& sParameters);

    //! Destructor
    virtual ~CSerialStream();

    //-------------------------------------------------------------------------------------------------
    // QIODevice methods
    //-------------------------------------------------------------------------------------------------

    virtual qint64 readData(char* data, qint64 maxSize) Q_DECL_OVERRIDE;
    virtual qint64 writeData(const char* data, qint64 maxSize) Q_DECL_OVERRIDE;
    virtual qint64 bytesAvailable() const Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    //!
    void onPortReadyRead();

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    QMutex          m_tMutex;
    QSerialPort     m_tPort;
};
