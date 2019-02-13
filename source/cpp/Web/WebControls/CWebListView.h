
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "CWebModelControl.h"

//-------------------------------------------------------------------------------------------------

//! Defines a web list view
class QTPLUSSHARED_EXPORT CWebListView : public CWebModelControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Instantiates a new CWebListView
    static CWebControl* instantiator();

    //! Default constructor
    CWebListView();

    //! Constructor with parameters
    CWebListView(const QString& sName, const QString& sCaption, IJSONModelProvider* pModelProvider = nullptr);

    //! Destructor
    virtual ~CWebListView();

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    void setModel();

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootControl) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sUpdateFunction;
    qint32      m_iItemsPerPage;
    qint32      m_iCurrentPage;
};
