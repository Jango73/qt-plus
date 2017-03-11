
// Application
#include "QMLArray.h"

//-------------------------------------------------------------------------------------------------

QMLArray::QMLArray()
{
}

//-------------------------------------------------------------------------------------------------

QMLArray::~QMLArray()
{
}

//-------------------------------------------------------------------------------------------------

void QMLArray::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLArray]"));

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

void QMLArray::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(stream);
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);
    Q_UNUSED(iIdent);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLArray::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    return xNode;
}
