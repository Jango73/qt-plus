
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLEntity.h"
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLFunctionCall : public QMLEntity
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with name, parameters and content
    QMLFunctionCall(const QPoint& pPosition, QMLEntity* pName, QMLComplexEntity *pArguments);

    //! Destructor
    virtual ~QMLFunctionCall();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* name() const;

    //!
    QMLComplexEntity* arguments();

    //!
    const QMLComplexEntity* arguments() const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLEntity*          m_pName;
    QMLComplexEntity*   m_pArguments;
};
