
// Application
#include "CXMLNodable.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CXMLNodable
    \inmodule qt-plus
    \brief This class defines an object that can be turned into a CXMLNode. Useless by itself, meant to be overridden.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CXMLNodable.
*/
CXMLNodable::CXMLNodable()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CXMLNodable.
*/
CXMLNodable::~CXMLNodable()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item (meant to be overridden). \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode CXMLNodable::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    return CXMLNode();
}
