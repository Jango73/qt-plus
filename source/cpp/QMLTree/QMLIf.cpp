
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
    dumpNewLine(stream);

    dumpIndented(stream, iIdent, "{");

    QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(m_pThen);

    if (pComplex != nullptr)
    {
        foreach (QMLItem* pItem, pComplex->contents())
        {
            if (pItem != nullptr)
            {
                dumpIndentedNoNewLine(stream, iIdent + 1, "");
                pItem->toQML(stream, pContext, this, iIdent + 1);
                dumpNewLine(stream);
            }
        }
    }
    else if (m_pThen != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent + 1, "");
        m_pThen->toQML(stream, pContext, this, iIdent + 1);
        dumpNewLine(stream);
    }

    dumpIndented(stream, iIdent, "}");

    if (m_pElse != nullptr)
    {
        dumpIndented(stream, iIdent, "else {");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(m_pElse);

        if (pComplex != nullptr)
        {
            foreach (QMLItem* pItem, pComplex->contents())
            {
                if (pItem != nullptr)
                {
                    dumpIndentedNoNewLine(stream, iIdent + 1, "");
                    pItem->toQML(stream, pContext, this, iIdent + 1);
                    dumpNewLine(stream);
                }
            }
        }
        else if (m_pElse != nullptr)
        {
            dumpIndentedNoNewLine(stream, iIdent + 1, "");
            m_pElse->toQML(stream, pContext, this, iIdent + 1);
            dumpNewLine(stream);
        }

        dumpIndented(stream, iIdent, "}");
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
