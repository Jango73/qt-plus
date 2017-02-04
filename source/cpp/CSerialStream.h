
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QObject>
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
	// Constructeurs et destructeur
	//-------------------------------------------------------------------------------------------------

	//! Constructeur avec param�tres
    CSerialStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//! Destructeur
    virtual ~CSerialStream();

	//-------------------------------------------------------------------------------------------------
	// M�thodes de contr�le
	//-------------------------------------------------------------------------------------------------

	//-------------------------------------------------------------------------------------------------
	// M�thodes h�rit�es
	//-------------------------------------------------------------------------------------------------

	//! Lecture de donn�es
	virtual qint64 readData(char* data, qint64 maxSize);

	//! Ecriture de donn�es
	virtual qint64 writeData(const char* data, qint64 maxSize);

	//!
	virtual qint64 bytesAvailable() const;

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

    QMutex			m_tMutex;
    QSerialPort     m_tPort;
};
