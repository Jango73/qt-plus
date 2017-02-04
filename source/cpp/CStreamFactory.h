
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Application
#include "CSingleton.h"
#include "CConnectedStream.h"

class QTPLUSSHARED_EXPORT CStreamFactory : public CSingleton<CStreamFactory>
{
	friend class CSingleton<CStreamFactory>;

public:

	//-------------------------------------------------------------------------------------------------
	// Méthodes de contrôle
	//-------------------------------------------------------------------------------------------------

	//!
	CConnectedStream* instanciateStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//-------------------------------------------------------------------------------------------------
	// Constructeurs et destructeur
	//-------------------------------------------------------------------------------------------------

protected:

	//! Constructeur avec paramètres
    CStreamFactory();

	//! Destructeur
    virtual ~CStreamFactory();
};
