
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines an if expression
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
    virtual void toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent = nullptr) const Q_DECL_OVERRIDE;

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
