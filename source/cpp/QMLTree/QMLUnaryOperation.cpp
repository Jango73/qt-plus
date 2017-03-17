
// Application
#include "QMLUnaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::QMLUnaryOperation(const QPoint& pPosition, QMLItem* pExpression, EUnaryOperator eOperator, bool bIsPostFix)
    : QMLItem(pPosition)
    , m_pExpression(pExpression)
    , m_eOperator(eOperator)
    , m_bIsPostFix(bIsPostFix)
{
}

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::~QMLUnaryOperation()
{
    if (m_pExpression != NULL)
        delete m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLUnaryOperation::expression() const
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
    }

    return "??";
}

//-------------------------------------------------------------------------------------------------

void QMLUnaryOperation::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_bIsPostFix == false)
    {
        dumpNoIndentNoNewLine(stream, QString("%1 ").arg(operatorToString(m_eOperator)));

        if (m_pExpression != nullptr)
        {
            m_pExpression->toQML(stream, pContext, this, iIdent);

            if (m_eOperator == uoCase)
            {
                dumpNoIndentNoNewLine(stream, ":");
            }
        }
    }
    else
    {
        if (m_pExpression != nullptr)
        {
            m_pExpression->toQML(stream, pContext, this, iIdent);

            if (m_eOperator == uoCase)
            {
                dumpNoIndentNoNewLine(stream, ":");
            }
        }

        dumpNoIndentNoNewLine(stream, QString("%1 ").arg(operatorToString(m_eOperator)));
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLUnaryOperation::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xExpression("Expression");

    xNode.attributes()["Operator"] = operatorToString(m_eOperator);

    if (m_pExpression != nullptr)
        xExpression.nodes() << m_pExpression->toXMLNode(pContext, this);

    xNode.nodes() << xExpression;

    return xNode;
}
