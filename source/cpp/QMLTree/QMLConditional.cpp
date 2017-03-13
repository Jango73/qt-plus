
// Application
#include "QMLConditional.h"

//-------------------------------------------------------------------------------------------------

QMLConditional::QMLConditional(const QPoint& pPosition, QMLItem* pCondition, QMLItem* pThen, QMLItem* pElse)
    : QMLIf(pPosition, pCondition, pThen, pElse)
{
}

//-------------------------------------------------------------------------------------------------

QMLConditional::~QMLConditional()
{
}
