
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CWebDiv : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur par d�faut
    CWebDiv();

    //! Constructeur avec param�tres
    CWebDiv(const QString& sName, const QString& sCaption);

    //! Destructeur
    virtual ~CWebDiv();
};
