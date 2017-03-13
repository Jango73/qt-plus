
// Application
#include "QMLUnaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLUnaryOperation::QMLUnaryOperation(const QPoint& pPosition, QMLItem* pExpression, EUnaryOperator eOperator)
    : QMLItem(pPosition)
    , m_pExpression(pExpression)
    , m_eOperator(eOperator)
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
        case uoBreak:
            return "break";
        case uoCase:
            return "case";
        case uoReturn:
            return "return";
    }

    return "??";
}

//-------------------------------------------------------------------------------------------------

void QMLUnaryOperation::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

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
