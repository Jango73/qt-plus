
// Application
#include "QMLPropertyAlias.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAlias::QMLPropertyAlias(QMLItem* pName, QMLItem* pContent)
    : QMLPropertyAssignment(pName, pContent)
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
