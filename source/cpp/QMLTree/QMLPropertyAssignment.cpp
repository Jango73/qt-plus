
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

void QMLPropertyAssignment::toQML(QTextStream& stream, const QMLEntity* pParent, int iIdent) const
{
    Q_UNUSED(pParent);

    if (m_pName != nullptr && m_pContent != nullptr)
    {
        m_pName->toQML(stream, this, iIdent + 1);

        stream << ": ";

        m_pContent->toQML(stream, this, iIdent + 1);
    }
}
