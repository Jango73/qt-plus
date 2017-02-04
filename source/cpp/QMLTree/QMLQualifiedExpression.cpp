
// Application
#include "QMLQualifiedExpression.h"

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::QMLQualifiedExpression()
{
}

//-------------------------------------------------------------------------------------------------

QMLQualifiedExpression::~QMLQualifiedExpression()
{
}

//-------------------------------------------------------------------------------------------------

void QMLQualifiedExpression::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLQualifiedExpression]"));

    QMLComplexItem::dump(stream, iIdent);
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
