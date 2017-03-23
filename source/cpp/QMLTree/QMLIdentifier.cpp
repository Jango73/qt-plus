
// Application
#include "QMLIdentifier.h"

//-------------------------------------------------------------------------------------------------

QMLIdentifier::QMLIdentifier(const QPoint& pPosition)
    : QMLEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLIdentifier::QMLIdentifier(const QPoint& pPosition, const QString& value)
    : QMLEntity(pPosition, value)
{
}

//-------------------------------------------------------------------------------------------------

QMLIdentifier::~QMLIdentifier()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLIdentifier::solveOrigins(QMLTreeContext* pContext, QMLEntity* pParent)
{
    if (m_vValue.toString().isEmpty() == false)
    {
        m_pOrigin = pParent->findNamedItem(m_vValue.toString());
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLIdentifier::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, m_vValue.toString());
}
