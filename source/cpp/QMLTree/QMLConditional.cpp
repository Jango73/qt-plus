
// Application
#include "QMLConditional.h"

//-------------------------------------------------------------------------------------------------

QMLConditional::QMLConditional(QMLItem* pCondition, QMLItem* pThen, QMLItem* pElse)
    : QMLIf(pCondition, pThen, pElse)
{
}

//-------------------------------------------------------------------------------------------------

QMLConditional::~QMLConditional()
{
}

//-------------------------------------------------------------------------------------------------

void QMLConditional::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLConditional]"));

    QMLIf::dump(stream, iIdent);
}
