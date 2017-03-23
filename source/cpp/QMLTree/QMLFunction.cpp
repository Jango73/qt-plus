
// Qt
#include <QDebug>

// Application
#include "QMLFunction.h"
#include "QMLVariableDeclaration.h"
#include "QMLBinaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLFunction::QMLFunction(const QPoint& pPosition, QMLItem* pName, QMLItem* pParameters, QMLItem* pContent)
    : QMLItem(pPosition)
    , m_pName(pName)
    , m_pParameters(pParameters)
    , m_pContent(pContent)
    , m_bIsSignal(false)
{
}

//-------------------------------------------------------------------------------------------------

QMLFunction::~QMLFunction()
{
    if (m_pName != nullptr)
        delete m_pName;
    if (m_pParameters != nullptr)
        delete m_pParameters;
    if (m_pContent != nullptr)
        delete m_pContent;
}

//-------------------------------------------------------------------------------------------------

void QMLFunction::setIsSignal(bool bValue)
{
    m_bIsSignal = bValue;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFunction::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFunction::parameters() const
{
    return m_pParameters;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLFunction::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

bool QMLFunction::isSignal() const
{
    return m_bIsSignal;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item as a string.
*/
QString QMLFunction::toString() const
{
    if (m_pName != nullptr)
        return m_pName->toString();

    return "";
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
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLFunction::solveOrigins(QMLTreeContext* pContext, QMLItem* pParent)
{
    if (m_pContent != nullptr)
    {
        m_mVariables = m_pContent->getDeclaredVariables();
        m_pContent->solveOrigins(pContext, this);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLItem* QMLFunction::findNamedItem(const QString& sName)
{
    return nullptr;
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

    if (m_bIsSignal)
    {
        dumpIndentedNoNewLine(stream, iIdent, "signal ");
    }
    else
    {
        dumpIndentedNoNewLine(stream, iIdent, "function ");
    }

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, "(");

    if (m_pParameters != nullptr)
    {
        m_pParameters->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNoIndentNoNewLine(stream, ")");

    if (m_bIsSignal == false)
    {
        if (m_pContent != nullptr)
        {
            m_pContent->toQML(stream, pContext, this, iIdent + 1);
        }
    }
    else
    {
        dumpNewLine(stream);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFunction::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xParameters("Parameters");
    CXMLNode xContent("Content");

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pParameters != nullptr)
        xParameters.nodes() << m_pParameters->toXMLNode(pContext, this);

    if (m_pContent != nullptr)
        xContent.nodes() << m_pContent->toXMLNode(pContext, this);

    xNode.nodes() << xName;
    xNode.nodes() << xParameters;
    xNode.nodes() << xContent;

    return xNode;
}
