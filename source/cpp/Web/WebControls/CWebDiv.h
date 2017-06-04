
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

    //! Constructeur par défaut
    CWebDiv();

    //! Constructeur avec paramètres
    CWebDiv(const QString& sName, const QString& sCaption);

    //! Destructeur
    virtual ~CWebDiv();
};
