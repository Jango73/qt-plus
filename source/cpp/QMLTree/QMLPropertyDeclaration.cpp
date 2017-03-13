
// Application
#include "QMLPropertyDeclaration.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLItem* pName)
    : QMLItem(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLItem* pName, QMLItem* pContent)
    : QMLItem(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::~QMLPropertyDeclaration()
{
    if (m_pType != nullptr)
        delete m_pType;
    if (m_pName != nullptr)
        delete m_pName;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMLType* QMLPropertyDeclaration::type() const
{
    return m_pType;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLPropertyDeclaration::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLPropertyDeclaration::content()
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

const QMLItem* QMLPropertyDeclaration::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLPropertyDeclaration::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["type"] = m_pType;
    vReturnValue["name"] = m_pName;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyDeclaration::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pType != nullptr && m_pName != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent, "property ");
        m_pType->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");
        m_pName->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");

        if (m_pContent != nullptr)
        {
            dumpNoIndentNoNewLine(stream, ": ");
            m_pContent->toQML(stream, pContext, this, iIdent + 1);
        }

        dumpNewLine(stream);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLPropertyDeclaration::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xType("Type");
    CXMLNode xName("Name");
    CXMLNode xContent("Content");

    if (m_pType != nullptr)
        xType.nodes() << m_pType->toXMLNode(pContext, this);

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xType;
    xNode.nodes() << xName;
    xNode.nodes() << xContent;

    return xNode;
}
