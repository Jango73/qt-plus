
// Application
#include "QMLSwitch.h"
#include "QMLUnaryOperation.h"

//-------------------------------------------------------------------------------------------------

QMLSwitch::QMLSwitch(const QPoint& pPosition, QMLEntity* pExpression, QMLComplexEntity* pCases)
    : QMLEntity(pPosition)
    , m_pExpression(pExpression)
    , m_pCases(pCases)
{
    if (m_pExpression != nullptr) m_pExpression->setParent(this);
    if (m_pCases != nullptr) m_pCases->setParent(this);
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

QMLEntity* QMLSwitch::expression() const
{
    return m_pExpression;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLSwitch::cases() const
{
    return m_pCases;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLSwitch::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

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
void QMLSwitch::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (previousSibling() == nullptr)
        formatter.processFragment(stream, QMLFormatter::qffBeforeSwitchNoPreviousSibling);
    else
        formatter.processFragment(stream, QMLFormatter::qffBeforeSwitch);

    stream << "switch (";

    if (m_pExpression != nullptr)
    {
        m_pExpression->toQML(stream, formatter, this);
    }

    stream << ")";

    formatter.processFragment(stream, QMLFormatter::qffAfterSwitch);

    if (m_pCases != nullptr)
    {
        m_pCases->toQML(stream, formatter, this);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLSwitch::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
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
