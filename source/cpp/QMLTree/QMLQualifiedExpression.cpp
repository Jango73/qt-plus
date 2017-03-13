
// Application
#include "QMLQualifiedExpression.h"

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::QMLQualifiedExpression(const QPoint& pPosition)
    : QMLComplexItem(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::~QMLQualifiedExpression()
{
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    bool putDot = false;

    foreach (QMLItem* pItem, m_vContents)
    {
        if (putDot == true)
        {
            dumpNoIndentNoNewLine(stream, ".");
        }

        if (pItem != NULL)
        {
            pItem->toQML(stream, pContext, this, iIdent);
        }

        putDot = true;
    }
}
