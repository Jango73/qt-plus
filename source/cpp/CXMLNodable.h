
#pragma once

#include "qtplus_global.h"

// Library
#include "CXMLNode.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CXMLNodableContext
{
public:

    CXMLNodableContext()
    {
    }
};

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CXMLNodable
{
public:

    //! Constructor
    CXMLNodable();

    //! Destructor
    virtual ~CXMLNodable();

    //! Serializes this object to a xml node
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent);
};
