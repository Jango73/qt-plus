
// Application
#include "QMLFunctionCall.h"

//-------------------------------------------------------------------------------------------------

QMLFunctionCall::QMLFunctionCall(const QPoint& pPosition, QMLEntity* pName, QMLComplexEntity* pArguments)
    : QMLEntity(pPosition)
    , m_pName(pName)
    , m_pArguments(pArguments)
{
    if (m_pName != nullptr) m_pName->setParent(this);
    if (m_pArguments != nullptr) m_pArguments->setParent(this);
}

//-------------------------------------------------------------------------------------------------

QMLFunctionCall::~QMLFunctionCall()
{
    if (m_pName != nullptr)
        delete m_pName;

    if (m_pArguments != nullptr)
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

QMap<QString, QMLEntity*> QMLFunctionCall::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["name"] = m_pName;
    vReturnValue["arguments"] = m_pArguments;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLFunctionCall::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (QMLComplexEntity::isContainer(pParent))
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforeFunctionCall);
    }

    if (m_pName != nullptr)
        m_pName->toQML(stream, formatter, this);

    stream << "(";

    if (m_pArguments != nullptr)
    {
        bool putDot = false;

        for (QMLEntity* pEntity : m_pArguments->contents())
        {
            if (putDot == true)
            {
                stream << ", ";
            }

            if (pEntity != nullptr)
            {
                pEntity->toQML(stream, formatter, this);
            }

            putDot = true;
        }
    }

    stream << ")";

    formatter.processFragment(stream, QMLFormatter::qffAfterFunctionCall);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLFunctionCall::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xName("Name");
    CXMLNode xArguments("Arguments");

    if (m_pName != nullptr)
        xName.nodes() << m_pName->toXMLNode(pContext, this);

    if (m_pArguments != nullptr)
        xArguments.nodes() << m_pArguments->toXMLNode(pContext, this);

    xNode.nodes() << xName;
    xNode.nodes() << xArguments;

    return xNode;
}
