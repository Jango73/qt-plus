
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

//! Defines a binary expression
class QTPLUSSHARED_EXPORT QMLBinaryOperation : public QMLEntity
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
        boShiftRight,
        boAddAssign,
        boSubAssign,
        boMulAssign,
        boDivAssign
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor with type and name
    QMLBinaryOperation(const QPoint& pPosition, QMLEntity *pLeft, QMLEntity* pRight, EOperator eOperator);

    //! Constructor with type, name and content
    QMLBinaryOperation(const QPoint& pPosition, QMLType *pType, QMLEntity* pName, QMLEntity *pContent);

    //! Destructor
    virtual ~QMLBinaryOperation();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QMLEntity* left() const;

    //!
    QMLEntity* right() const;

    //!
    EOperator oper() const;

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QString operatorToString(EOperator eOperator) const;

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

    QMLEntity*  m_pLeft;
    QMLEntity*  m_pRight;
    EOperator   m_eOperator;
};
