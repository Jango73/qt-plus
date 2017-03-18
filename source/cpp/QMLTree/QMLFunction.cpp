
// Qt
#include <QDebug>

// Application
#include "QMLFunction.h"

//-------------------------------------------------------------------------------------------------

QMLFunction::QMLFunction(const QPoint& pPosition, QMLItem* pName, QMLComplexItem *pParameters, QMLComplexItem *pContent)
    : QMLItem(pPosition)
    , m_pName(pName)
    , m_pParameters(pParameters)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLFunction::~QMLFunction()
{
    if (m_pName != NULL)
        delete m_pName;
    if (m_pParameters != NULL)
        delete m_pParameters;
    if (m_pContent != NULL)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFunction::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem* QMLFunction::parameters() const
{
    return m_pParameters;
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem* QMLFunction::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLFunction::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["name"] = m_pName;
    vReturnValue["parameters"] = m_pParameters;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLFunction::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpIndentedNoNewLine(stream, iIdent, "function ");

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, "(");

    if (m_pParameters != nullptr)
    {
        m_pParameters->toQML(stream, pContext, nullptr, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, ")");
    dumpNewLine(stream);

    dumpIndented(stream, iIdent, "{");

    if (m_pContent != nullptr)
    {
        foreach (QMLItem* pItem, m_pContent->contents())
        {
            if (pItem != nullptr)
            {
                dumpIndentedNoNewLine(stream, iIdent + 1, "");
                pItem->toQML(stream, pContext, this, iIdent + 1);
                dumpNewLine(stream);
            }
        }
    }

    dumpIndented(stream, iIdent, "}");
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFunction::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xParameters("Parameters");
    CXMLNode xContent("Content");

    if (m_pName != NULL)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pParameters != NULL)
        xParameters.nodes() << m_pParameters->toXMLNode(pContext, this);

    if (m_pContent != NULL)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xName;
    xNode.nodes() << xParameters;
    xNode.nodes() << xContent;

    return xNode;
}
