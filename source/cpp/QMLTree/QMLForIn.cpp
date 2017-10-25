
// Application
#include "QMLForIn.h"
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

QMLForIn::QMLForIn(const QPoint& pPosition, QMLEntity* pVariable, QMLEntity* pExpression, QMLEntity* pContent)
    : QMLEntity(pPosition)
    , m_pVariable(pVariable)
    , m_pExpression(pExpression)
    , m_pContent(pContent)
{
    if (m_pVariable != nullptr) m_pVariable->setParent(this);
    if (m_pExpression != nullptr) m_pExpression->setParent(this);
    if (m_pContent != nullptr) m_pContent->setParent(this);
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

QMLEntity* QMLForIn::variable() const
{
    return m_pVariable;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLForIn::expression() const
{
    return m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLForIn::content() const
{
    return m_pContent;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLForIn::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

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
void QMLForIn::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    formatter.processFragment(stream, QMLFormatter::qffBeforeFor);

    stream << "for (";

    if (m_pVariable != nullptr)
    {
        m_pVariable->toQML(stream, formatter, this);
    }

    stream << " in ";

    if (m_pExpression != nullptr)
    {
        m_pExpression->toQML(stream, formatter, this);
    }

    stream << ")";

    formatter.processFragment(stream, QMLFormatter::qffAfterFor);

    m_pContent->toQML(stream, formatter, this);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLForIn::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
