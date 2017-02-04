
// Application
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::QMLPropertyAssignment(QMLItem* pName, QMLItem* pContent)
    : QMLPropertyDeclaration(NULL, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::~QMLPropertyAssignment()
{
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAssignment::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLPropertyAssignment]"));

    QMLPropertyDeclaration::dump(stream, iIdent);
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
