
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Application
#include "CSingleton.h"
#include "CConnectedStream.h"

// Defines a factory that can instantiate a stream endpoint of the following types:
// - Serial (RS232)
// - Socket
// The returned object depends on the contents of sName instanciateStream
class QTPLUSSHARED_EXPORT CStreamFactory : public CSingleton<CStreamFactory>
{
	friend class CSingleton<CStreamFactory>;

public:

	//-------------------------------------------------------------------------------------------------
    // Control methods
	//-------------------------------------------------------------------------------------------------

	//!
	CConnectedStream* instanciateStream(const QString& sName, const QMap<QString, QString>& sParameters);

	//-------------------------------------------------------------------------------------------------
    // Constructors and destructor
	//-------------------------------------------------------------------------------------------------

protected:

	//! Constructeur avec paramètres
    CStreamFactory();

	//! Destructeur
    virtual ~CStreamFactory() Q_DECL_OVERRIDE;
};
