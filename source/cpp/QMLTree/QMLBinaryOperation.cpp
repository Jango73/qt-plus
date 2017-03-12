
// Application
#include "QMLBinaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLBinaryOperation::QMLBinaryOperation(const QPoint& pPosition, QMLItem* pLeft, QMLItem* pRight, EOperator eOperator)
    : QMLItem(pPosition)
    , m_pLeft(pLeft)
    , m_pRight(pRight)
    , m_eOperator(eOperator)
{
}

//-------------------------------------------------------------------------------------------------

QMLBinaryOperation::~QMLBinaryOperation()
{
    if (m_pLeft != NULL)
        delete m_pLeft;
    if (m_pRight != NULL)
        delete m_pRight;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLBinaryOperation::left() const
{
    return m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLBinaryOperation::right() const
{
    return m_pRight;
}

//-------------------------------------------------------------------------------------------------

QMLBinaryOperation::EOperator QMLBinaryOperation::oper() const
{
    return m_eOperator;
}

//-------------------------------------------------------------------------------------------------

QString QMLBinaryOperation::operatorToString(EOperator eOperator) const
{
    switch (eOperator)
    {
        case boAssign:
            return "=";
        case boAdd:
            return "+";
        case boSub:
            return "-";
        case boMul:
            return "*";
        case boDiv:
            return "/";
        case boAnd:
            return "&";
        case boOr:
            return "|";
        case boXor:
            return "^";
        case boLogicAnd:
            return "&&";
        case boLogicOr:
            return "||";
        case boEquals:
            return "==";
        case boEqualsCheck:
            return "===";
        case boNotEquals:
            return "!=";
        case boNotEqualsCheck:
            return "!==";
        case boLower:
            return "<";
        case boLowerOrEquals:
            return "<=";
        case boGreater:
            return ">";
        case boGreaterOrEquals:
            return ">=";
    }

    return "??";
}

//-------------------------------------------------------------------------------------------------

void QMLBinaryOperation::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLBinaryOperation]"));
    dumpIndented(stream, iIdent, QString("Operator : %1").arg(operatorToString(m_eOperator)));

    if (m_pLeft != NULL)
    {
        dumpIndented(stream, iIdent, QString("Left :"));
        dumpOpenBlock(stream, iIdent);
        m_pLeft->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pRight != NULL)
    {
        dumpIndented(stream, iIdent, QString("Right :"));
        dumpOpenBlock(stream, iIdent);
        m_pRight->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

void QMLBinaryOperation::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pLeft != NULL)
    {
        m_pLeft->toQML(stream, pContext, this, iIdent);
    }

    dumpNoIndentNoNewLine(stream, QString(" %1 ").arg(operatorToString(m_eOperator)));

    if (m_pRight != NULL)
    {
        m_pRight->toQML(stream, pContext, this, iIdent);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLBinaryOperation::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xLeft("Left");
    CXMLNode xRight("Right");

    xNode.attributes()["Operator"] = operatorToString(m_eOperator);

    if (m_pLeft != NULL)
        xLeft.nodes() << m_pLeft->toXMLNode(pContext, this);

    if (m_pRight != NULL)
        xRight.nodes() << m_pRight->toXMLNode(pContext, this);

    xNode.nodes() << xLeft;
    xNode.nodes() << xRight;

    return xNode;
}
