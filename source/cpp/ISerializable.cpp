
// Application
#include "ISerializable.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CObjectTracker
    \inmodule qt-plus
    \brief A tracker of instantiated objects. Helps checking validity of deserialized pointers.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Adds the object pointed by \a pObject.
*/
void CObjectTracker::append(QObject* pObject)
{
	if (pObject != NULL)
	{
		m_vInstances.append(pObject);
	}
}

//-------------------------------------------------------------------------------------------------

/*!
    Removes the object pointed by \a pObject.
*/
void CObjectTracker::remove(QObject* pObject)
{
	m_vInstances.remove(m_vInstances.indexOf(pObject));
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the object pointed by \a pObject is valid (exists in the tracker's list).
*/
bool CObjectTracker::exists(QObject* pObject) const
{
	return m_vInstances.contains(pObject);
}
