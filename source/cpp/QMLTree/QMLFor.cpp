
// Application
#include "QMLFor.h"

//-------------------------------------------------------------------------------------------------

QMLFor::QMLFor(const QPoint& pPosition, QMLItem* pInitialization, QMLItem* pCondition, QMLItem* pIncrementation, QMLItem* pContent)
    : QMLItem(pPosition)
    , m_pInitialization(pInitialization)
    , m_pCondition(pCondition)
    , m_pIncrementation(pIncrementation)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLFor::~QMLFor()
{
    if (m_pInitialization != nullptr)
        delete m_pInitialization;
    if (m_pCondition != nullptr)
        delete m_pCondition;
    if (m_pIncrementation != nullptr)
        delete m_pIncrementation;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFor::initialization() const
{
    return m_pInitialization;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFor::condition() const
{
    return m_pCondition;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFor::incrementation() const
{
    return m_pIncrementation;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFor::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLFor::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["initialization"] = m_pInitialization;
    vReturnValue["condition"] = m_pCondition;
    vReturnValue["incrementation"] = m_pIncrementation;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLFor::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLIf]"));

    if (m_pInitialization != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Initialization :"));
        dumpOpenBlock(stream, iIdent);
        m_pInitialization->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pCondition != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Condition :"));
        dumpOpenBlock(stream, iIdent);
        m_pCondition->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pIncrementation != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Incrementation :"));
        dumpOpenBlock(stream, iIdent);
        m_pIncrementation->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pContent != nullptr)
    {
        dumpIndented(stream, iIdent, QString("Content :"));
        dumpOpenBlock(stream, iIdent);
        m_pContent->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFor::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xInitialization("Initialization");
    CXMLNode xCondition("Condition");
    CXMLNode xIncrementation("Incrementation");
    CXMLNode xContent("Content");

    if (m_pInitialization != nullptr)
        xInitialization.nodes() << m_pInitialization->toXMLNode(pContext, this);

    if (m_pCondition != nullptr)
        xCondition.nodes() << m_pCondition->toXMLNode(pContext, this);

    if (m_pIncrementation != nullptr)
        xIncrementation.nodes() << m_pIncrementation->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xInitialization;
    xNode.nodes() << xCondition;
    xNode.nodes() << xIncrementation;
    xNode.nodes() << xContent;

    return xNode;
}
