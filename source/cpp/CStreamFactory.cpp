
// Application
#include "CStreamFactory.h"
#include "CSocketStream.h"
#include "CSerialStream.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CStreamFactory
    \inmodule qt-plus
    \brief A factory which can instanciate a connected stream based on it's name.

    Any name starting with /dev/tty or COM will instanciate a CSerialStream.
    Otherwise, a CSocketStream will be instanciated.

    \sa CSerialStream
    \sa CSocketStream
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CStreamFactory.
*/
CStreamFactory::CStreamFactory()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CStreamFactory.
*/
CStreamFactory::~CStreamFactory()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CConnectedStream derived class based on parameters: \br\br
    \a sName is a connection name like "127.0.0.1", "0.0.0.0:5555", "/dev/ttyS1", "COM2", etc...
    \a sParameters are additional parameters for serial connections.
*/
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
