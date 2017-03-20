
// Application
#include "QMLPropertyAlias.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAlias::QMLPropertyAlias(const QPoint& pPosition, QMLItem* pName, QMLItem* pContent)
    : QMLPropertyAssignment(pPosition, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAlias::~QMLPropertyAlias()
{
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAlias::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        dumpIndentedNoNewLine(stream, iIdent, "property alias ");

        dumpNoIndentNoNewLine(stream, "");
        m_pName->toQML(stream, pContext, this, iIdent + 1);

        dumpNoIndentNoNewLine(stream, ": ");
        m_pContent->toQML(stream, pContext, this, iIdent + 1);

        dumpNewLine(stream);
    }
}
