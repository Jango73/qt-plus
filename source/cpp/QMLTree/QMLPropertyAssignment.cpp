
// Application
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::QMLPropertyAssignment(const QPoint& pPosition, QMLEntity* pName, QMLEntity* pContent)
    : QMLPropertyDeclaration(pPosition, NULL, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::~QMLPropertyAssignment()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLPropertyAssignment::getDeclaredSymbols()
{
    return QMap<QString, QMLEntity*>();
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAssignment::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent, "");
        m_pName->toQML(stream, pContext, this, iIdent + 1);

        dumpNoIndentNoNewLine(stream, ": ");
        m_pContent->toQML(stream, pContext, this, iIdent + 1);

        dumpNewLine(stream);
    }
}
