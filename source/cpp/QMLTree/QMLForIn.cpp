
// Application
#include "QMLForIn.h"
#include "QMLComplexItem.h"

//-------------------------------------------------------------------------------------------------

QMLForIn::QMLForIn(const QPoint& pPosition, QMLItem* pVariable, QMLItem* pExpression, QMLItem* pContent)
    : QMLItem(pPosition)
    , m_pVariable(pVariable)
    , m_pExpression(pExpression)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLForIn::~QMLForIn()
{
    if (m_pVariable != nullptr)
        delete m_pVariable;
    if (m_pExpression != nullptr)
        delete m_pExpression;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLForIn::variable() const
{
    return m_pVariable;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLForIn::expression() const
{
    return m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLForIn::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLForIn::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["variable"] = m_pVariable;
    vReturnValue["expression"] = m_pExpression;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLForIn::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, "for (");

    if (m_pVariable != nullptr)
    {
        m_pVariable->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, " in ");

    if (m_pExpression != nullptr)
    {
        m_pExpression->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, ")");
    dumpNewLine(stream);

    dumpIndented(stream, iIdent, "{");

    QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(m_pContent);

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
    else if (m_pContent != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent + 1, "");
        m_pContent->toQML(stream, pContext, this, iIdent + 1);
        dumpNewLine(stream);
    }

    dumpIndented(stream, iIdent, "}");
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLForIn::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xVariable("Variable");
    CXMLNode xExpression("Expression");
    CXMLNode xContent("Content");

    if (m_pVariable != nullptr)
        xVariable.nodes() << m_pVariable->toXMLNode(pContext, this);

    if (m_pExpression != nullptr)
        xExpression.nodes() << m_pExpression->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xVariable;
    xNode.nodes() << xExpression;
    xNode.nodes() << xContent;

    return xNode;
}
