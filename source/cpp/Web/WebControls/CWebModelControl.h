
#pragma once

// Application
#include "../../IJSONModelProvider.h"
#include "CWebControl.h"

//! Defines a control that uses a JSON model for data
class QTPLUSSHARED_EXPORT CWebModelControl : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Factory instanciator
    static CWebControl* instantiator();

    //! Default constructor
    CWebModelControl();

    //! Constructor with parameters
    CWebModelControl(const QString& sName, const QString& sCaption, IJSONModelProvider* pModelProvider = nullptr);

    //! Destructor
    virtual ~CWebModelControl();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootControl) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    CSerialReferencable<IJSONModelProvider>     m_pModelProvider;
};
