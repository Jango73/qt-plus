
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a web file input control
class QTPLUSSHARED_EXPORT CWebFileInput : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Instantiates a new CWebFileInput
    static CWebControl* instantiator();

    //! Default constructor
    CWebFileInput();

    //! Constructor
    CWebFileInput(const QString& sName, const QString& sCaption);

    //! Destructor
    virtual ~CWebFileInput();

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody) Q_DECL_OVERRIDE;

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;
};
