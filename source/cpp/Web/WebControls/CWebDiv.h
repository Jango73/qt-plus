
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a web div element
class QTPLUSSHARED_EXPORT CWebDiv : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Instantiates a new CWebDiv
    static CWebControl* instantiator();

    //! Default constructor
    CWebDiv();

    //! Constructor
    CWebDiv(const QString& sName, const QString& sCaption);

    //! Destructor
    virtual ~CWebDiv();
};
