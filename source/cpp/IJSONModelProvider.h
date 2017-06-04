
#pragma once

// Qt
#include <QString>

// Application
#include "CXMLNode.h"

//-------------------------------------------------------------------------------------------------

//! Defines a JSON model provider
class IJSONModelProvider
{
public:

    //! Returns the model
    virtual CXMLNode getModel(int iStartIndex, int iCount) const = 0;
};
