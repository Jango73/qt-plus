
// Application
#include "QMLIf.h"

//-------------------------------------------------------------------------------------------------

QMLIf::QMLIf(QMLItem* pCondition, QMLItem* pThen, QMLItem* pElse)
    : m_pCondition(pCondition)
    , m_pThen(pThen)
    , m_pElse(pElse)
{
}

//-------------------------------------------------------------------------------------------------

QMLIf::~QMLIf()
{
    if (m_pCondition != NULL)
        delete m_pCondition;
    if (m_pThen != NULL)
        delete m_pThen;
    if (m_pElse != NULL)
        delete m_pElse;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLIf::condition() const
{
    return m_pCondition;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLIf::then() const
{
    return m_pThen;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLIf::Else() const
{
    return m_pElse;
}

//-------------------------------------------------------------------------------------------------

void QMLIf::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLIf]"));

    if (m_pCondition != NULL)
    {
        dumpIndented(stream, iIdent, QString("Condition :"));
        dumpOpenBlock(stream, iIdent);
        m_pCondition->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pThen != NULL)
    {
        dumpIndented(stream, iIdent, QString("Then :"));
        dumpOpenBlock(stream, iIdent);
        m_pThen->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pElse != NULL)
    {
        dumpIndented(stream, iIdent, QString("Else :"));
        dumpOpenBlock(stream, iIdent);
        m_pElse->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLIf::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xCondition("Condition");
    CXMLNode xThen("Then");
    CXMLNode xElse("Else");

    if (m_pCondition != NULL)
        xCondition.nodes() << m_pCondition->toXMLNode(pContext, this);

    if (m_pThen != NULL)
        xThen.nodes() << m_pThen->toXMLNode(pContext, this);

    if (m_pElse != NULL)
        xElse.nodes() << m_pElse->toXMLNode(pContext, this);

    xNode.nodes() << xCondition;
    xNode.nodes() << xThen;
    xNode.nodes() << xElse;

    return xNode;
}
