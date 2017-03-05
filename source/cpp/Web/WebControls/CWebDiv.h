
#ifndef CWEBDIV_H
#define CWEBDIV_H

// Application
#include "CWebControl.h"

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

#endif // CWEBDIV_H
