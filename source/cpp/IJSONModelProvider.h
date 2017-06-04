
#pragma once

// Qt
#include <QObject>

// Application
#include "CXMLNode.h"

//-------------------------------------------------------------------------------------------------

//! Defines a JSON model provider
class IJSONModelProvider : public QObject
{
public:

    //! Returns the model
    virtual CXMLNode modelItems(int iStartIndex, int iCount) const = 0;

    //! Gets the total number of items
    virtual int modelItemCount() const = 0;
};
