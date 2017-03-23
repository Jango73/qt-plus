
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLIf : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with condition, then and else
    QMLIf(const QPoint& pPosition, QMLEntity* pCondition, QMLEntity* pThen, QMLEntity* pElse);

    //! Destructor
    virtual ~QMLIf();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* condition() const;

    //!
    QMLEntity* then() const;

    //!
    QMLEntity* Else() const;

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

    QMLEntity*  m_pCondition;
    QMLEntity*  m_pThen;
    QMLEntity*  m_pElse;
};
