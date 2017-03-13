
// Application
#include "QMLFunctionCall.h"

//-------------------------------------------------------------------------------------------------

QMLFunctionCall::QMLFunctionCall(const QPoint& pPosition, QMLItem* pName, QMLComplexItem *pArguments)
    : QMLItem(pPosition)
    , m_pName(pName)
    , m_pArguments(pArguments)
{
}

//-------------------------------------------------------------------------------------------------

QMLFunctionCall::~QMLFunctionCall()
{
    if (m_pName != NULL)
        delete m_pName;

    if (m_pArguments != NULL)
        delete m_pArguments;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFunctionCall::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem* QMLFunctionCall::arguments()
{
    return m_pArguments;
}

//-------------------------------------------------------------------------------------------------

const QMLComplexItem* QMLFunctionCall::arguments() const
{
    return m_pArguments;
}

//-------------------------------------------------------------------------------------------------

void QMLFunctionCall::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != NULL)
        m_pName->toQML(stream, pContext, this, iIdent);

    dumpNoIndentNoNewLine(stream, "(");

    if (m_pArguments != NULL)
    {
        bool putDot = false;

        foreach (QMLItem* pItem, m_pArguments->contents())
        {
            if (putDot == true)
            {
                dumpNoIndentNoNewLine(stream, ", ");
            }

            if (pItem != NULL)
            {
                pItem->toQML(stream, pContext, this, iIdent);
            }

            putDot = true;
        }
    }

    dumpNoIndentNoNewLine(stream, ")");
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFunctionCall::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xArguments("Arguments");

    if (m_pName != NULL)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pArguments != NULL)
        xArguments.nodes() << m_pArguments->toXMLNode(pContext, this);

    xNode.nodes() << xName;
    xNode.nodes() << xArguments;

    return xNode;
}
