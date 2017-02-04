
// Application
#include "QMLPropertyDeclaration.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(QMLType* pType, QMLItem* pName)
    : m_pType(pType)
    , m_pName(pName)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(QMLType* pType, QMLItem* pName, QMLItem* pContent)
    : m_pType(pType)
    , m_pName(pName)
    , m_pContent(pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::~QMLPropertyDeclaration()
{
    if (m_pType != NULL)
        delete m_pType;
    if (m_pName != NULL)
        delete m_pName;
    if (m_pContent != NULL)
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

void QMLPropertyDeclaration::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLPropertyDeclaration]"));

    if (m_pType != NULL)
    {
        dumpIndented(stream, iIdent, QString("Type :"));
        dumpOpenBlock(stream, iIdent);
        m_pType->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pName != NULL)
    {
        dumpIndented(stream, iIdent, QString("Name :"));
        dumpOpenBlock(stream, iIdent);
        m_pName->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    if (m_pContent != NULL)
    {
        dumpIndented(stream, iIdent, QString("Content :"));
        dumpOpenBlock(stream, iIdent);
        m_pContent->dump(stream, iIdent + 1);
        dumpCloseBlock(stream, iIdent);
    }

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyDeclaration::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pType != NULL && m_pName != NULL)
    {
        dumpIndentedNoNewLine(stream, iIdent, "property ");
        m_pType->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");
        m_pName->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");

        if (m_pContent != NULL)
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

    if (m_pType != NULL)
        xType.nodes() << m_pType->toXMLNode(pContext, this);

    if (m_pName != NULL)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pContent != NULL)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xType;
    xNode.nodes() << xName;
    xNode.nodes() << xContent;

    return xNode;
}
