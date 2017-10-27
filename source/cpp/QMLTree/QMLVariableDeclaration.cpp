
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
    : QMLComplexEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLVariableDeclaration as copy of \a target. Does nothing, exists only to make containers happy.
*/
QMLVariableDeclaration::QMLVariableDeclaration(const QMLVariableDeclaration& target)
    : QMLComplexEntity(target.position())
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
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLVariableDeclaration::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue;

    foreach (QMLEntity* pVariable, m_vContents)
    {
        QMLIdentifier* pIdentifier = dynamic_cast<QMLIdentifier*>(pVariable);

        if (pIdentifier == nullptr)
        {
            QMLBinaryOperation* pBynaryOp = dynamic_cast<QMLBinaryOperation*>(pVariable);

            if (pBynaryOp != nullptr)
            {
                pIdentifier = dynamic_cast<QMLIdentifier*>(pBynaryOp->left());

                if (pBynaryOp->right() != nullptr)
                {
                    QMap<QString, QMLEntity*> rightVariables = pBynaryOp->right()->getDeclaredSymbols();

                    foreach (QString sKey, rightVariables.keys())
                    {
                        if (mReturnValue.contains(sKey) == false)
                        {
                            mReturnValue[sKey] = rightVariables[sKey];
                        }
                    }
                }
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

void QMLVariableDeclaration::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (QMLEntity::isFor(pParent) == false)
        formatter.processFragment(stream, QMLFormatter::qffBeforeVariableDeclaration);

    stream << "var ";

    QMLComplexEntity::toQML(stream, formatter, this);
}
