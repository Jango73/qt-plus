
// Application
#include "CConnectedStream.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CConnectedStream
    \inmodule qt-plus
    \brief A base class for all streams that are based on a connection.
*/

/*!
    \fn void CConnectedStream::connected()

    This signal is emitted when stream is connected to its target.
*/

/*!
    \fn void CConnectedStream::disconnected()

    This signal is emitted when stream is disconnected from its target.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CConnectedStream.
*/
CConnectedStream::CConnectedStream()
    : m_iMinBytesForReadyRead(0)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CConnectedStream named \a name.
*/
CConnectedStream::CConnectedStream(const QString& name)
    : m_sName(name)
    , m_iMinBytesForReadyRead(0)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CConnectedStream.
*/
CConnectedStream::~CConnectedStream()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the minimum amount of incoming bytes before triggering the readyRead signal to \a iMinBytes.
*/
void CConnectedStream::setMinBytesForReadyRead(int iMinBytes)
{
    m_iMinBytesForReadyRead = iMinBytes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the stream's name.
*/
QString CConnectedStream::name() const
{
    return m_sName;
}
