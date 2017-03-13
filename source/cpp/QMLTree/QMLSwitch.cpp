
// Application
#include "QMLSwitch.h"
#include "QMLUnaryOperation.h"

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

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLSwitch::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, "switch (");

    if (m_pExpression != nullptr)
    {
        m_pExpression->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, ")");
    dumpNewLine(stream);

    dumpIndented(stream, iIdent, "{");

    if (m_pCases != nullptr)
    {
        foreach (QMLItem* pItem, m_pCases->contents())
        {
            if (pItem != nullptr)
            {
                QMLUnaryOperation* pUnary = dynamic_cast<QMLUnaryOperation*>(pItem);

                if (pUnary != nullptr && pUnary->oper() == QMLUnaryOperation::uoCase)
                {
                    dumpIndentedNoNewLine(stream, iIdent + 1, "");
                    pItem->toQML(stream, pContext, this, iIdent + 1);
                    dumpNewLine(stream);
                }
                else
                {
                    dumpIndentedNoNewLine(stream, iIdent + 2, "");
                    pItem->toQML(stream, pContext, this, iIdent + 2);
                    dumpNewLine(stream);
                }
            }
        }
    }

    dumpIndented(stream, iIdent, "}");
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
