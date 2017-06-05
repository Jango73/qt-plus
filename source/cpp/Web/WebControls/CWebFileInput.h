
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CWebFileInput : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur par défaut
    CWebFileInput();

    //! Constructeur avec paramètres
    CWebFileInput(const QString& sName, const QString& sCaption);

    //! Destructeur
    virtual ~CWebFileInput();

    //-------------------------------------------------------------------------------------------------
    // Méthodes héritées
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody) Q_DECL_OVERRIDE;

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;
};
