
// Application
#include "QMLQualifiedExpression.h"

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::QMLQualifiedExpression(const QPoint& pPosition)
    : QMLComplexEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::~QMLQualifiedExpression()
{
}

//-------------------------------------------------------------------------------------------------

QString QMLQualifiedExpression::toString() const
{
    QString sReturnValue;

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (sReturnValue.isEmpty() == false)
        {
            sReturnValue += ".";
        }

        if (pEntity != nullptr)
        {
            sReturnValue += pEntity->toString();
        }
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLQualifiedExpression::solveReferences(QMLTreeContext* pContext)
{
    QString sName = toString();

    if (sName.isEmpty() == false)
    {
        QMLEntity* pParent = dynamic_cast<QMLEntity*>(parent());

        if (pParent != nullptr)
        {
            m_pOrigin = pParent->findSymbolDeclaration(sName);

            if (m_pOrigin == this)
            {
                m_pOrigin = nullptr;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::solveSymbolUsages(QMLTreeContext* pContext)
{
    if (m_pOrigin != nullptr)
    {
        m_pOrigin->incUsageCount();
    }
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, "(");
    }

    dumpNoIndentNoNewLine(stream, toString());

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, ")");
    }
}
