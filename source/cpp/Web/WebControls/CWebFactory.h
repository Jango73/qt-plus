
#pragma once

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>

// Application
#include "../../CSingleton.h"
#include "../../CXMLNode.h"
#include "../../CFactory.h"
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a factory of web controls
class QTPLUSSHARED_EXPORT CWebFactory : public CSingleton<CWebFactory>, public CFactory<CWebControl>
{
    friend class CSingleton<CWebFactory>;

public:

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

protected:

    //! Default constructor
    CWebFactory();

    //! Destructor
    virtual ~CWebFactory();
};
