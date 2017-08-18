
#pragma once

// Qt
#include <QVector>
#include <QMutex>
#include <QWaitCondition>

// Application
#include "qtplus_global.h"

// Commenter la ligne suivante en mode release
#define FULL_MUTEX_TRACE

class QTPLUSSHARED_EXPORT CTracableMutex
{
public:

	//! Default constructor
	CTracableMutex();

	//! Constructeur avec paramètres
	CTracableMutex(QMutex::RecursionMode eMode, QString sName = "");

	//! Constructeur de copie
	CTracableMutex(const CTracableMutex&);

	//! Destructor
	~CTracableMutex();

	//! Opérateur de copie
	CTracableMutex& operator =(const CTracableMutex&);

	//! Enregistrement d'une thread
	static void registerThread(int iThreadID, QString sName);

	//! Vérouillage du mutex, retourne true si le mutex a été pris
    bool lock(QString sName = "");

	//! Dévérouillage du mutex
	void unlock();

	QMutex				m_tMutex;
	QString				m_sName;

	static QMap<int, QString> m_vThreadNames;

#ifdef FULL_MUTEX_TRACE
	QVector<QString>	m_sLockNames;
#endif
};
