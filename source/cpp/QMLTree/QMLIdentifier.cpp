
// Application
#include "QMLIdentifier.h"

//-------------------------------------------------------------------------------------------------

QMLIdentifier::QMLIdentifier(const QPoint& pPosition)
    : QMLItem(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLIdentifier::QMLIdentifier(const QPoint& pPosition, const QString& value)
    : QMLItem(pPosition, value)
{
}

//-------------------------------------------------------------------------------------------------

QMLIdentifier::~QMLIdentifier()
{
}

//-------------------------------------------------------------------------------------------------

void QMLIdentifier::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLIdentifier]"));

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

void QMLIdentifier::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, m_vValue.toString());
}