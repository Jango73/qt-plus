
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

void QMLPropertyAlias::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLPropertyAlias]"));

    QMLPropertyAssignment::dump(stream, iIdent);
}
