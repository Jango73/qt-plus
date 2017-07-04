
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a for var in var loop
class QTPLUSSHARED_EXPORT QMLForIn : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with condition, then and else
    QMLForIn(const QPoint& pPosition, QMLEntity* pVariable, QMLEntity* pExpression, QMLEntity* pContent);

    //! Destructor
    virtual ~QMLForIn();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* variable() const;

    //!
    QMLEntity* expression() const;

    //!
    QMLEntity* content() const;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, const QMLEntity* pParent = nullptr, int iIdent = 0) const Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*  m_pVariable;
    QMLEntity*  m_pExpression;
    QMLEntity*  m_pContent;
};
