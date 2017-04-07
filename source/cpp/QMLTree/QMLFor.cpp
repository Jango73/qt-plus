
// Application
#include "QMLFor.h"
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

QMLFor::QMLFor(const QPoint& pPosition, QMLEntity* pInitialization, QMLEntity* pCondition, QMLEntity* pIncrementation, QMLEntity* pContent)
    : QMLEntity(pPosition)
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

QMLEntity* QMLFor::initialization() const
{
    return m_pInitialization;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFor::condition() const
{
    return m_pCondition;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFor::incrementation() const
{
    return m_pIncrementation;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLFor::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLFor::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["initialization"] = m_pInitialization;
    vReturnValue["condition"] = m_pCondition;
    vReturnValue["incrementation"] = m_pIncrementation;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLFor::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    stream << "for (";

    if (m_pInitialization != nullptr)
    {
        m_pInitialization->toQML(stream, this, iIdent + 1);
    }

    stream << "; ";

    if (m_pCondition != nullptr)
    {
        m_pCondition->toQML(stream, this, iIdent + 1);
    }

    stream << "; ";

    if (m_pIncrementation != nullptr)
    {
        m_pIncrementation->toQML(stream, this, iIdent + 1);
    }

    stream << ")";
    stream << "\n";

    if (m_pContent != nullptr)
    {
        m_pContent->toQML(stream, this, iIdent + 1);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFor::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
