
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

void QMLQualifiedExpression::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, "(");
    }

    bool putDot = false;

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (putDot == true)
        {
            dumpNoIndentNoNewLine(stream, ".");
        }

        if (pEntity != nullptr)
        {
            pEntity->toQML(stream, pContext, this, iIdent);
        }

        putDot = true;
    }

    if (m_bIsParenthesized)
    {
        dumpNoIndentNoNewLine(stream, ")");
    }
}
