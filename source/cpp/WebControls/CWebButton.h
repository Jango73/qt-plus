
#ifndef CWEBBUTTON_H
#define CWEBBUTTON_H

// Application
#include "CWebControl.h"

class QTPLUSSHARED_EXPORT CWebButton : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur par défaut
    CWebButton();

    //! Constructeur avec paramètres
    CWebButton(const QString& sName, const QString& sCaption, const QString& sParam="");

    //! Destructeur
    virtual ~CWebButton();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Méthodes héritées
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody) const;

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam);

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject);

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:
};

#endif // CWEBBUTTON_H
