
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines a property declaration
class QTPLUSSHARED_EXPORT QMLBinaryOperation : public QMLItem
{
    Q_OBJECT

public:

    enum EOperator
    {
        boNone,
        boAssign,
        boAdd,
        boSub,
        boMul,
        boDiv,
        boMod,
        boAnd,
        boOr,
        boXor,
        boLogicAnd,
        boLogicOr,
        boEquals,
        boEqualsCheck,
        boNotEquals,
        boNotEqualsCheck,
        boLower,
        boLowerOrEquals,
        boGreater,
        boGreaterOrEquals,
        boShiftLeft,
        boShiftRight
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with type and name
    QMLBinaryOperation(const QPoint& pPosition, QMLItem *pLeft, QMLItem* pRight, EOperator eOperator);

    //! Constructor with type, name and content
    QMLBinaryOperation(const QPoint& pPosition, QMLType *pType, QMLItem* pName, QMLItem *pContent);

    //! Destructor
    virtual ~QMLBinaryOperation();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLItem* left() const;

    //!
    QMLItem* right() const;

    //!
    EOperator oper() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QString operatorToString(EOperator eOperator) const;

    //-------------------------------------------------------------------------------------------------
    // Overridden methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual QMap<QString, QMLItem*> getDeclaredVariables() Q_DECL_OVERRIDE;

    //!
    virtual void toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent = NULL, int iIdent = 0) Q_DECL_OVERRIDE;

    //!
    virtual CXMLNode toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMLItem*    m_pLeft;
    QMLItem*    m_pRight;
    EOperator   m_eOperator;
};
