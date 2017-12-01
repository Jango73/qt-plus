
// Application
#include "QMLUnaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::QMLUnaryOperation(const QPoint& pPosition, QMLEntity* pExpression, EUnaryOperator eOperator, bool bIsPostFix)
    : QMLEntity(pPosition)
    , m_pExpression(pExpression)
    , m_eOperator(eOperator)
    , m_bIsPostFix(bIsPostFix)
{
    if (m_pExpression != nullptr) m_pExpression->setParent(this);
}

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::~QMLUnaryOperation()
{
    if (m_pExpression != nullptr)
        delete m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLUnaryOperation::expression() const
{
    return m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::EUnaryOperator QMLUnaryOperation::oper() const
{
    return m_eOperator;
}

//-------------------------------------------------------------------------------------------------

QString QMLUnaryOperation::operatorToString(EUnaryOperator eOperator) const
{
    switch (eOperator)
    {
        case uoReturn:
            return "return";
        case uoBreak:
            return "break";
        case uoCase:
            return "case";
        case uoContinue:
            return "continue";
        case uoIncrement:
            return "++";
        case uoDecrement:
            return "--";
        case uoMinus:
            return "-";
        case uoNot:
            return "!";
        case uoNotNot:
            return "!!";
        case uoTypeof:
            return "typeof";
        case uoNew:
            return "new";
    }

    return "??";
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLUnaryOperation::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["expression"] = m_pExpression;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLUnaryOperation::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (QMLComplexEntity::isContainer(pParent))
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforeTopLevelUnaryOp);
    }

    if (m_bIsParenthesized)
    {
        stream << "(";
    }

    if (m_bIsPostFix == false)
    {
        stream << QString("%1 ").arg(operatorToString(m_eOperator));

        if (m_pExpression != nullptr)
        {
            m_pExpression->toQML(stream, formatter, this);

            if (m_eOperator == uoCase)
            {
                stream << ":";
            }
        }
    }
    else
    {
        if (m_pExpression != nullptr)
        {
            m_pExpression->toQML(stream, formatter, this);

            if (m_eOperator == uoCase)
            {
                stream << ":";

                formatter.writeNewLine(stream);
            }
        }

        stream << QString("%1 ").arg(operatorToString(m_eOperator));
    }

    if (m_bIsParenthesized)
    {
        stream << ")";
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLUnaryOperation::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xExpression("Expression");

    xNode.attributes()["Operator"] = operatorToString(m_eOperator);

    if (m_pExpression != nullptr)
        xExpression.nodes() << m_pExpression->toXMLNode(pContext, this);

    xNode.nodes() << xExpression;

    return xNode;
}
