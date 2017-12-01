
// Application
#include "QMLQualifiedExpression.h"
#include "QMLIdentifier.h"

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

    QMLComplexEntity::solveReferences(pContext);
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::solveSymbolUsages(QMLTreeContext* pContext)
{
    if (m_pOrigin != nullptr)
    {
        m_pOrigin->incUsageCount();
    }

    QMLComplexEntity::solveSymbolUsages(pContext);
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (QMLComplexEntity::isContainer(pParent))
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforeQualifiedExpression);
    }

    if (m_bIsParenthesized)
    {
        stream << "(";
    }

    bool putDot = false;

    foreach (QMLEntity* pItem, m_vContents)
    {
        if (putDot == true)
        {
            stream << ".";
        }

        if (pItem != nullptr)
        {
            pItem->toQML(stream, formatter, this);
        }

        putDot = true;
    }

    if (m_bIsParenthesized)
    {
        stream << ")";
    }
}
