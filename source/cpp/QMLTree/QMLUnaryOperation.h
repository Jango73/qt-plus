
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLUnaryOperation : public QMLEntity
{
    Q_OBJECT

public:

    enum EUnaryOperator
    {
        uoNone,
        uoReturn,
        uoBreak,
        uoCase,
        uoContinue,
        uoIncrement,
        uoDecrement,
        uoMinus,
        uoNot,
        uoTypeof,
        uoNew
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with type and name
    QMLUnaryOperation(const QPoint& pPosition, QMLEntity* pExpression, EUnaryOperator eOperator, bool bIsPostFix = false);

    //! Destructor
    virtual ~QMLUnaryOperation();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* expression() const;

    //!
    EUnaryOperator oper() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QString operatorToString(EUnaryOperator eOperator) const;

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

    QMLEntity*      m_pExpression;
    EUnaryOperator  m_eOperator;
    bool            m_bIsPostFix;
};
