
// Application
#include "QMLPropertyDeclaration.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLEntity* pName)
    : QMLEntity(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(nullptr)
    , m_eModifiers(mNone)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::QMLPropertyDeclaration(const QPoint& pPosition, QMLType* pType, QMLEntity* pName, QMLEntity* pContent)
    : QMLEntity(pPosition)
    , m_pType(pType)
    , m_pName(pName)
    , m_pContent(pContent)
    , m_eModifiers(mNone)
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

void QMLPropertyDeclaration::setModifiers(EModifier eModifiers)
{
    m_eModifiers = eModifiers;
}

//-------------------------------------------------------------------------------------------------

QMLType* QMLPropertyDeclaration::type() const
{
    return m_pType;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLPropertyDeclaration::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLPropertyDeclaration::content()
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

const QMLEntity* QMLPropertyDeclaration::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMLPropertyDeclaration::EModifier QMLPropertyDeclaration::modifiers() const
{
    return m_eModifiers;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLPropertyDeclaration::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["type"] = m_pType;
    vReturnValue["name"] = m_pName;
    vReturnValue["content"] = m_pContent;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyDeclaration::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pType != nullptr && m_pName != nullptr)
    {
        if (m_eModifiers == mReadonly)
        {
            dumpIndentedNoNewLine(stream, iIdent, "readonly ");
        }
        else if (m_eModifiers == mDefault)
        {
            dumpIndentedNoNewLine(stream, iIdent, "default ");
        }
        else
        {
            dumpIndentedNoNewLine(stream, iIdent, "");
        }

        dumpNoIndentNoNewLine(stream, "property ");
        m_pType->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");
        m_pName->toQML(stream, pContext, this, iIdent + 1);

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
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xType("Type");
    CXMLNode xName("Name");
    CXMLNode xContent("Content");

    xNode.attributes()["Modifiers"] = QString::number((int) m_eModifiers);

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
