
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

    //! Constructeur par d�faut
    CWebButton();

    //! Constructeur avec param�tres
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
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // M�thodes h�rit�es
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
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:
};

#endif // CWEBBUTTON_H
