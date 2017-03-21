
// Qt
#include <QDebug>

// Application
#include "QMLFunctionParameter.h"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFunctionParameter. \br\br
    \a pPosition is the position of the token in the file \br
*/
QMLFunctionParameter::QMLFunctionParameter(const QPoint& pPosition, QMLType* pType, QMLItem* pName)
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

void QMLFunctionParameter::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pType != nullptr && m_pType->type() != QVariant::Invalid)
    {
        m_pType->toQML(stream, pContext, this, iIdent + 1);

        dumpNoIndentNoNewLine(stream, " ");
    }

    if (m_pName != nullptr)
    {
        m_pName->toQML(stream, pContext, this, iIdent + 1);
    }
}
