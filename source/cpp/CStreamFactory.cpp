
// Application
#include "CStreamFactory.h"
#include "CSocketStream.h"
#include "CSerialStream.h"

//-------------------------------------------------------------------------------------------------

CStreamFactory::CStreamFactory()
{
}

//-------------------------------------------------------------------------------------------------

CStreamFactory::~CStreamFactory()
{
}

//-------------------------------------------------------------------------------------------------

CConnectedStream* CStreamFactory::instanciateStream(const QString& sName, const QMap<QString, QString>& sParameters)
{
	if (sName.startsWith("/dev/tty") || sName.startsWith("COM"))
	{
        return new CSerialStream(sName, sParameters);
	}
	else
	{
		return new CSocketStream(sName, sParameters);
	}
}
