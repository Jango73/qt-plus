
#ifndef CWEBFILEINPUT_H
#define CWEBFILEINPUT_H

// Application
#include "CWebControl.h"

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
    virtual void addHTML(QString& sHead, QString& sBody) const;

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam);
};

#endif // CWEBFILEINPUT_H
