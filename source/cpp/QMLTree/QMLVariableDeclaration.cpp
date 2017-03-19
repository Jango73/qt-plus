
// Qt
#include <QDebug>

// Application
#include "QMLVariableDeclaration.h"
#include "QMLIdentifier.h"
#include "QMLBinaryOperation.h"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLVariableDeclaration. \br\br
    \a pPosition is the position of the token in the file \br
*/
QMLVariableDeclaration::QMLVariableDeclaration(const QPoint& pPosition)
    : QMLComplexItem(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLVariableDeclaration as copy of \a target. Does nothing, exists only to make containers happy.
*/
QMLVariableDeclaration::QMLVariableDeclaration(const QMLVariableDeclaration& target)
    : QMLComplexItem(target.position())
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLVariableDeclaration.
*/
QMLVariableDeclaration::~QMLVariableDeclaration()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLItem*> QMLVariableDeclaration::getDeclaredVariables()
{
    QMap<QString, QMLItem*> mReturnValue;

    foreach (QMLItem* pVariable, m_vContents)
    {
        QMLIdentifier* pIdentifier = dynamic_cast<QMLIdentifier*>(pVariable);

        if (pIdentifier == nullptr)
        {
            QMLBinaryOperation* pAssign = dynamic_cast<QMLBinaryOperation*>(pVariable);

            if (pAssign != nullptr)
            {
                pIdentifier = dynamic_cast<QMLIdentifier*>(pAssign->left());
            }
        }

        if (pIdentifier != nullptr)
        {
            mReturnValue[pIdentifier->value().toString()] = pIdentifier;
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLVariableDeclaration::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, "var ");

    QMLComplexItem::toQML(stream, pContext, this, iIdent);
}
