
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

    //! Constructeur
    CXMLNodable();

    //! Destructeur
    virtual ~CXMLNodable();

    //! Dump du contenu dans un flux
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent);
};
