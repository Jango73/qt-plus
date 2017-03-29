
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

void QMLOnExpression::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != nullptr)
    {
        // m_pName->toQML(stream, pContext, this, iIdent + 1);
        stream << m_pName->toString();
    }

    stream << " on ";

    if (m_pTarget != nullptr)
    {
        m_pTarget->toQML(stream, pContext, this, iIdent + 1);
    }

    if (pParent != nullptr)
    {
        stream << " { ";
    }

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            pEntity->toQML(stream, pContext, this, pParent != NULL ? iIdent + 1 : iIdent);
        }
    }

    if (pParent != nullptr)
    {
        stream << " } ";
    }
}
