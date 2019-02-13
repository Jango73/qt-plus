
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a web label
class QTPLUSSHARED_EXPORT CWebLabel : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Instantiates a new CWebLabel
    static CWebControl* instantiator();

    //! Default constructor
    CWebLabel();

    //! Constructor
    CWebLabel(const QString& sName, const QString& sCaption);

    //! Destructor
    virtual ~CWebLabel();
};
