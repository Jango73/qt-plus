
// Application
#include "QMLFunctionCall.h"

//-------------------------------------------------------------------------------------------------

QMLFunctionCall::QMLFunctionCall(const QPoint& pPosition, QMLEntity* pName, QMLComplexEntity *pArguments)
    : QMLEntity(pPosition)
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

QMLEntity* QMLFunctionCall::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLComplexEntity* QMLFunctionCall::arguments()
{
    return m_pArguments;
}

//-------------------------------------------------------------------------------------------------

const QMLComplexEntity* QMLFunctionCall::arguments() const
{
    return m_pArguments;
}

//-------------------------------------------------------------------------------------------------

void QMLFunctionCall::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != NULL)
        m_pName->toQML(stream, pContext, this, iIdent);

    dumpNoIndentNoNewLine(stream, "(");

    if (m_pArguments != NULL)
    {
        bool putDot = false;

        foreach (QMLEntity* pItem, m_pArguments->contents())
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
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
