
// Qt
#include <QDebug>

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
*/
void QMLIdentifier::solveOrigins(QMLTreeContext* pContext)
{
    if (m_vValue.toString().isEmpty() == false)
    {
        QMLEntity* pParent = dynamic_cast<QMLEntity*>(parent());

        if (pParent != nullptr)
        {
            // qDebug() << "QMLIdentifier::solveOrigins() : calling pParent->findSymbolDeclaration";

            m_pOrigin = pParent->findSymbolDeclaration(m_vValue.toString());

            if (m_pOrigin == this)
            {
                m_pOrigin = nullptr;
            }
        }
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
