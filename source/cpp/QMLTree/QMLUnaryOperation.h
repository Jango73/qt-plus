
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLUnaryOperation : public QMLItem
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
        uoTypeof
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with type and name
    QMLUnaryOperation(const QPoint& pPosition, QMLItem* pExpression, EUnaryOperator eOperator, bool bIsPostFix = false);

    //! Destructor
    virtual ~QMLUnaryOperation();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLItem* expression() const;

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
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLItem*        m_pExpression;
    EUnaryOperator  m_eOperator;
    bool            m_bIsPostFix;
};
