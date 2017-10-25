
// Application
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::QMLPropertyAssignment(const QPoint& pPosition, QMLEntity* pName, QMLEntity* pContent)
    : QMLPropertyDeclaration(pPosition, nullptr, pName, pContent)
{
}

//-------------------------------------------------------------------------------------------------

QMLPropertyAssignment::~QMLPropertyAssignment()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLPropertyAssignment::getDeclaredSymbols()
{
    return QMap<QString, QMLEntity*>();
}

//-------------------------------------------------------------------------------------------------

void QMLPropertyAssignment::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        formatter.processFragment(stream, QMLFormatter::qffBeforePropertyName);
        m_pName->toQML(stream, formatter, this);
        formatter.processFragment(stream, QMLFormatter::qffAfterPropertyName);

        stream << ": ";

        formatter.processFragment(stream, QMLFormatter::qffBeforePropertyContent);
        m_pContent->toQML(stream, formatter, this);
        formatter.processFragment(stream, QMLFormatter::qffAfterPropertyContent);
    }
}
