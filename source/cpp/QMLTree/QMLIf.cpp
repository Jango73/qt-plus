
// Application
#include "QMLIf.h"
#include "QMLComplexItem.h"

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

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLItem*> QMLIf::getDeclaredVariables()
{
    QMap<QString, QMLItem*> mReturnValue;

    if (m_pThen != nullptr)
    {
        QMap<QString, QMLItem*> thenVariables = m_pThen->getDeclaredVariables();

        foreach (QString sKey, thenVariables.keys())
        {
            mReturnValue[sKey] = thenVariables[sKey];
        }
    }

    if (m_pElse != nullptr)
    {
        QMap<QString, QMLItem*> elseVariables = m_pElse->getDeclaredVariables();

        foreach (QString sKey, elseVariables.keys())
        {
            if (mReturnValue.contains(sKey) == false)
            {
                mReturnValue[sKey] = elseVariables[sKey];
            }
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLIf::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, "if (");

    if (m_pCondition != nullptr)
    {
        m_pCondition->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, ")");

    m_pThen->toQML(stream, pContext, this, iIdent + 1);

    if (m_pElse != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent, "else ");
        m_pElse->toQML(stream, pContext, this, iIdent + 1);
    }
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
