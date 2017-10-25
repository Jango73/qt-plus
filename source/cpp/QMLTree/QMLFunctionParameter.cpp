
// Qt
#include <QDebug>

// Application
#include "QMLFunctionParameter.h"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFunctionParameter. \br\br
    \a pPosition is the position of the token in the file \br
*/
QMLFunctionParameter::QMLFunctionParameter(const QPoint& pPosition, QMLType* pType, QMLEntity* pName)
    : QMLPropertyDeclaration(pPosition, pType, pName)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLVariableDeclaration.
*/
QMLFunctionParameter::~QMLFunctionParameter()
{
}

//-------------------------------------------------------------------------------------------------

void QMLFunctionParameter::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pType != nullptr && m_pType->type() != QVariant::Invalid)
    {
        m_pType->toQML(stream, formatter, this);

        stream << " ";
    }

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, formatter, this);
    }
}
