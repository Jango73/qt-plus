
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a for loop
class QTPLUSSHARED_EXPORT QMLFor : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with condition, then and else
    QMLFor(const QPoint& pPosition, QMLEntity* pInitialization, QMLEntity* pCondition, QMLEntity* pIncrementation, QMLEntity* pContent);

    //! Destructor
    virtual ~QMLFor();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setIsWhile(bool bValue);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* initialization() const;

    //!
    QMLEntity* condition() const;

    //!
    QMLEntity* incrementation() const;

    //!
    QMLEntity* content() const;

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

    QMLEntity*  m_pInitialization;
    QMLEntity*  m_pCondition;
    QMLEntity*  m_pIncrementation;
    QMLEntity*  m_pContent;
    bool        m_bIsWhile;
};
