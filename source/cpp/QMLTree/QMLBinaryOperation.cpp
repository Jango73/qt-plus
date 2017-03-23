
// Application
#include "QMLBinaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLBinaryOperation::QMLBinaryOperation(const QPoint& pPosition, QMLEntity* pLeft, QMLEntity* pRight, EOperator eOperator)
    : QMLEntity(pPosition)
    , m_pLeft(pLeft)
    , m_pRight(pRight)
    , m_eOperator(eOperator)
{
    if (m_pLeft != nullptr) m_pLeft->setParent(this);
    if (m_pRight != nullptr) m_pRight->setParent(this);
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

QMLEntity* QMLBinaryOperation::left() const
{
    return m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLBinaryOperation::right() const
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
        case boMod:
            return "%";
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

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLEntity*> QMLBinaryOperation::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue;

    QMap<QString, QMLEntity*> leftVariables = m_pLeft->getDeclaredSymbols();
    QMap<QString, QMLEntity*> rightVariables = m_pLeft->getDeclaredSymbols();

    foreach (QString sKey, leftVariables.keys())
    {
        mReturnValue[sKey] = leftVariables[sKey];
    }

    foreach (QString sKey, rightVariables.keys())
    {
        if (mReturnValue.contains(sKey) == false)
        {
            mReturnValue[sKey] = rightVariables[sKey];
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLBinaryOperation::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, "(");
    }

    if (m_pLeft != nullptr)
    {
        m_pLeft->toQML(stream, pContext, this, iIdent);
    }

    dumpNoIndentNoNewLine(stream, QString(" %1 ").arg(operatorToString(m_eOperator)));

    if (m_pRight != nullptr)
    {
        m_pRight->toQML(stream, pContext, this, iIdent);
    }

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, ")");
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLBinaryOperation::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
