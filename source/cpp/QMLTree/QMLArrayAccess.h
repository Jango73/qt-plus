
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLArrayAccess : public QMLComplexEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with condition, then and else
    QMLArrayAccess(const QPoint& pPosition, QMLEntity* pLeft);

    //! Destructor
    virtual ~QMLArrayAccess();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* left() const;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QMap<QString, QMLEntity*> getDeclaredVariables() Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*  m_pLeft;
};
