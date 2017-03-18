
// Application
#include "QMLVariableDeclaration.h"

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

void QMLVariableDeclaration::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, "var ");

    QMLComplexItem::toQML(stream, pContext, this, iIdent);
}
