
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

void QMLOnExpression::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    if (m_pName != nullptr)
    {
        // m_pName->toQML(stream, this, iIdent + 1);
        stream << m_pName->toString();
    }

    stream << " on ";

    if (m_pTarget != nullptr)
    {
        m_pTarget->toQML(stream, this, iIdent + 1);
    }

    if (pParent != nullptr)
    {
        stream << " { ";
    }

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            pEntity->toQML(stream, this, pParent != nullptr ? iIdent + 1 : iIdent);
        }
    }

    if (pParent != nullptr)
    {
        stream << " } ";
    }
}
