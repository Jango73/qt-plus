
// Application
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::QMLPropertyAssignment(const QPoint& pPosition, QMLItem* pName, QMLItem* pContent)
    : QMLPropertyDeclaration(pPosition, NULL, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::~QMLPropertyAssignment()
{
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAssignment::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != NULL && m_pContent != NULL)
    {
        dumpIndentedNoNewLine(stream, iIdent, "");
        m_pName->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, " ");

        dumpNoIndentNoNewLine(stream, ": ");
        m_pContent->toQML(stream, pContext, this, iIdent + 1);

        dumpNewLine(stream);
    }
}
