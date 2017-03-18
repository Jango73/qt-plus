
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

//-------------------------------------------------------------------------------------------------

void QMLConditional::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pCondition != nullptr && m_pThen != nullptr && m_pElse != nullptr)
    {
        if (m_bIsParenthesized)
        {
            dumpNoIndentNoNewLine(stream, "(");
        }

        m_pCondition->toQML(stream, pContext, this, iIdent);
        dumpNoIndentNoNewLine(stream, " ? ");
        m_pThen->toQML(stream, pContext, this, iIdent);
        dumpNoIndentNoNewLine(stream, " : ");
        m_pElse->toQML(stream, pContext, this, iIdent);

        if (m_bIsParenthesized)
        {
            dumpNoIndentNoNewLine(stream, ")");
        }
    }
}
