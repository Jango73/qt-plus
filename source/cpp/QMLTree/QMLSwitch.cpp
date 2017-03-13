
// Application
#include "QMLSwitch.h"

//-------------------------------------------------------------------------------------------------

QMLSwitch::QMLSwitch(const QPoint& pPosition, QMLItem* pExpression, QMLComplexItem* pCases)
    : QMLItem(pPosition)
    , m_pExpression(pExpression)
    , m_pCases(pCases)
{
}

//-------------------------------------------------------------------------------------------------

QMLSwitch::~QMLSwitch()
{
    if (m_pExpression != nullptr)
        delete m_pExpression;
    if (m_pCases != nullptr)
        delete m_pCases;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLSwitch::expression() const
{
    return m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLSwitch::cases() const
{
    return m_pCases;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLSwitch::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["expression"] = m_pExpression;
    vReturnValue["cases"] = m_pCases;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLSwitch::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLIf]"));

    if (m_pExpression != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Expression :"));
        dumpOpenBlock(stream, iIdent);
        m_pExpression->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pCases != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Cases :"));
        dumpOpenBlock(stream, iIdent);
        m_pCases->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLSwitch::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xExpression("Expression");
    CXMLNode xCases("Cases");

    if (m_pExpression != nullptr)
        xExpression.nodes() << m_pExpression->toXMLNode(pContext, this);

    if (m_pCases != nullptr)
        xCases.nodes() << m_pCases->toXMLNode(pContext, this);

    xNode.nodes() << xExpression;
    xNode.nodes() << xCases;

    return xNode;
}
