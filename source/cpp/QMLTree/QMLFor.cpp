
// Application
#include "QMLFor.h"

//-------------------------------------------------------------------------------------------------

QMLFor::QMLFor(QMLItem* pInitialization, QMLItem* pCondition, QMLItem* pIncrementation, QMLItem* pContent)
    : m_pInitialization(pInitialization)
    , m_pCondition(pCondition)
    , m_pIncrementation(pIncrementation)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLFor::~QMLFor()
{
    if (m_pInitialization != NULL)
        delete m_pInitialization;
    if (m_pCondition != NULL)
        delete m_pCondition;
    if (m_pIncrementation != NULL)
        delete m_pIncrementation;
    if (m_pContent != NULL)
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

void QMLFor::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLIf]"));

    if (m_pInitialization != NULL)
    {
        dumpIndented(stream, iIdent, QString("Initialization :"));
        dumpOpenBlock(stream, iIdent);
        m_pInitialization->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pCondition != NULL)
    {
        dumpIndented(stream, iIdent, QString("Condition :"));
        dumpOpenBlock(stream, iIdent);
        m_pCondition->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pIncrementation != NULL)
    {
        dumpIndented(stream, iIdent, QString("Incrementation :"));
        dumpOpenBlock(stream, iIdent);
        m_pIncrementation->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pContent != NULL)
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

    if (m_pInitialization != NULL)
        xInitialization.nodes() << m_pInitialization->toXMLNode(pContext, this);

    if (m_pCondition != NULL)
        xCondition.nodes() << m_pCondition->toXMLNode(pContext, this);

    if (m_pIncrementation != NULL)
        xIncrementation.nodes() << m_pIncrementation->toXMLNode(pContext, this);

    if (m_pContent != NULL)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xInitialization;
    xNode.nodes() << xCondition;
    xNode.nodes() << xIncrementation;
    xNode.nodes() << xContent;

    return xNode;
}
