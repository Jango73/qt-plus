
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a web button
class QTPLUSSHARED_EXPORT CWebButton : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Default constructor
    CWebButton();

    //! Constructor
    CWebButton(const QString& sName, const QString& sCaption, const QString& sParam="");

    //! Destructor
    virtual ~CWebButton();

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody) Q_DECL_OVERRIDE;

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:
};
