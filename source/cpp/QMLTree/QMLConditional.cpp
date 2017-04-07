
// Application
#include "QMLConditional.h"

//-------------------------------------------------------------------------------------------------

QMLConditional::QMLConditional(const QPoint& pPosition, QMLEntity* pCondition, QMLEntity* pThen, QMLEntity* pElse)
    : QMLIf(pPosition, pCondition, pThen, pElse)
{
}

//-------------------------------------------------------------------------------------------------

QMLConditional::~QMLConditional()
{
}

//-------------------------------------------------------------------------------------------------

void QMLConditional::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    if (m_pCondition != nullptr && m_pThen != nullptr && m_pElse != nullptr)
    {
        if (m_bIsParenthesized)
        {
            stream << " ( ";
        }

        m_pCondition->toQML(stream, this, iIdent);
        stream <<  " ? ";
        m_pThen->toQML(stream, this, iIdent);
        stream << " : ";
        m_pElse->toQML(stream, this, iIdent);

        if (m_bIsParenthesized)
        {
            stream << " ) ";
        }
    }
}
