
// Application
#include "QMLIf.h"
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

QMLIf::QMLIf(const QPoint& pPosition, QMLEntity* pCondition, QMLEntity* pThen, QMLEntity* pElse)
    : QMLEntity(pPosition)
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

QMLEntity* QMLIf::condition() const
{
    return m_pCondition;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLIf::then() const
{
    return m_pThen;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLIf::Else() const
{
    return m_pElse;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLIf::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["condition"] = m_pCondition;
    vReturnValue["then"] = m_pThen;
    vReturnValue["else"] = m_pElse;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLIf::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (previousSibling() == nullptr)
        formatter.processFragment(stream, QMLFormatter::qffBeforeIfNoPreviousSibling);
    else
        formatter.processFragment(stream, QMLFormatter::qffBeforeIf);

    stream << "if (";

    if (m_pCondition != nullptr)
    {
        m_pCondition->toQML(stream, formatter, this);
    }

    stream << ") ";

    formatter.processFragment(stream, QMLFormatter::qffAfterIf);

    m_pThen->toQML(stream, formatter, this);

    if (m_pElse != nullptr)
    {
        stream << " else ";

        m_pElse->toQML(stream, formatter, this);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLIf::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
