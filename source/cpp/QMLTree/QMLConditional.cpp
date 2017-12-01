
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

void QMLConditional::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pCondition != nullptr && m_pThen != nullptr && m_pElse != nullptr)
    {
        if (m_bIsParenthesized)
        {
            stream << "(";
        }

        m_pCondition->toQML(stream, formatter, this);
        stream <<  " ? ";
        m_pThen->toQML(stream, formatter, this);
        stream << " : ";
        m_pElse->toQML(stream, formatter, this);

        if (m_bIsParenthesized)
        {
            stream << ")";
        }
    }
}
