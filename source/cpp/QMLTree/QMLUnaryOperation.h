
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QObject>

// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

//! Defines an unary expression
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
        uoNotNot,
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

    //! Returns all members
    virtual QMap<QString, QMLEntity*> members() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //!
    QString operatorToString(EUnaryOperator eOperator) const;

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

    QMLEntity*      m_pExpression;
    EUnaryOperator  m_eOperator;
    bool            m_bIsPostFix;
};
