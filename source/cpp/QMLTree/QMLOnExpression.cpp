
// Application
#include "QMLOnExpression.h"

//-------------------------------------------------------------------------------------------------

QMLOnExpression::QMLOnExpression(const QPoint& pPosition, QMLEntity* pTarget, QMLEntity* pName, QMLComplexEntity* pContents)
    : QMLComplexEntity(pPosition, pName)
    , m_pTarget(pTarget)
{
    if (pContents != nullptr)
    {
        m_vContents = pContents->grabContents();

        delete pContents;
    }

    if (m_pTarget != nullptr) m_pTarget->setParent(this);
}

//-------------------------------------------------------------------------------------------------

QMLOnExpression::~QMLOnExpression()
{
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLOnExpression::members()
{
    QMap<QString, QMLEntity*> vReturnValue = QMLComplexEntity::members();

    vReturnValue["target"] = m_pTarget;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLOnExpression::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    formatter.processFragment(stream, QMLFormatter::qffBeforePropertyName);

    if (m_pName != nullptr)
    {
        stream << m_pName->toSimpleString();
    }

    stream << " on ";

    if (m_pTarget != nullptr)
    {
        m_pTarget->toQML(stream, formatter, this);
    }

    if (pParent != nullptr)
    {
        stream << " { ";
        formatter.processFragment(stream, QMLFormatter::qffBeforeItemContent);
    }

    for (QMLEntity* pEntity : m_vContents)
    {
        if (pEntity != nullptr)
        {
            pEntity->toQML(stream, formatter, this);
        }
    }

    if (pParent != nullptr)
    {
        formatter.processFragment(stream, QMLFormatter::qffAfterItemContent);
        stream << "} ";
    }
}
