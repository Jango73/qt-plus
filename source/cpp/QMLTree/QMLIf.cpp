
// Application
#include "QMLIf.h"

//-------------------------------------------------------------------------------------------------

QMLIf::QMLIf(const QPoint& pPosition, QMLItem* pCondition, QMLItem* pThen, QMLItem* pElse)
    : QMLItem(pPosition)
    , m_pCondition(pCondition)
    , m_pThen(pThen)
    , m_pElse(pElse)
{
}

//-------------------------------------------------------------------------------------------------

QMLIf::~QMLIf()
{
    if (m_pCondition != nullptr)
        delete m_pCondition;
    if (m_pThen != nullptr)
        delete m_pThen;
    if (m_pElse != nullptr)
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

QMap<QString, QMLItem*> QMLIf::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["condition"] = m_pCondition;
    vReturnValue["then"] = m_pThen;
    vReturnValue["else"] = m_pElse;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLIf::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xCondition("Condition");
    CXMLNode xThen("Then");
    CXMLNode xElse("Else");

    if (m_pCondition != nullptr)
        xCondition.nodes() << m_pCondition->toXMLNode(pContext, this);

    if (m_pThen != nullptr)
        xThen.nodes() << m_pThen->toXMLNode(pContext, this);

    if (m_pElse != nullptr)
        xElse.nodes() << m_pElse->toXMLNode(pContext, this);

    xNode.nodes() << xCondition;
    xNode.nodes() << xThen;
    xNode.nodes() << xElse;

    return xNode;
}
