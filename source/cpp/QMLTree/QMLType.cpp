
// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

QMLType::QMLType(const QPoint& pPosition)
    : QMLItem(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLType::QMLType(const QPoint& pPosition, QVariant::Type type)
    : QMLItem(pPosition)
    , m_vType(type)
{
}

//-------------------------------------------------------------------------------------------------

QMLType::~QMLType()
{
}

//-------------------------------------------------------------------------------------------------

void QMLType::setType(QVariant::Type type)
{
    m_vType = type;
}

//-------------------------------------------------------------------------------------------------

QVariant::Type QMLType::type() const
{
    return m_vType;
}

//-------------------------------------------------------------------------------------------------

QString QMLType::toString() const
{
    return typeToString(m_vType);
}

//-------------------------------------------------------------------------------------------------

void QMLType::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLType]"));
    dumpIndented(stream, iIdent, QString("Type : %1").arg(typeToString(m_vType)));
}

//-------------------------------------------------------------------------------------------------

void QMLType::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, typeToString(m_vType));
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLType::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    xNode.attributes()["Type"] = typeToString(m_vType);

    return xNode;
}

//-------------------------------------------------------------------------------------------------

QString QMLType::typeToString(QVariant::Type eType)
{
    switch (eType)
    {
        case QVariant::Invalid:
            return "var";
        case QVariant::Bool:
            return "bool";
        case QVariant::Int:
            return "int";
        case QVariant::Double:
            return "real";
        case QVariant::String:
            return "string";
        case QVariant::Color:
            return "color";
        case QVariant::Font:
            return "font";
    }

    return "";
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QMLType from a \a pItem.
*/
QMLType* QMLType::fromQMLItem(QMLItem* pItem)
{
    if (pItem != nullptr)
    {
        if (pItem->value().toString().toLower() == "var") return new QMLType(QPoint(), QVariant::Invalid);
        if (pItem->value().toString().toLower() == "variant") return new QMLType(QPoint(), QVariant::Invalid);
        if (pItem->value().toString().toLower() == "bool") return new QMLType(QPoint(), QVariant::Bool);
        if (pItem->value().toString().toLower() == "int") return new QMLType(QPoint(), QVariant::Int);
        if (pItem->value().toString().toLower() == "real") return new QMLType(QPoint(), QVariant::Double);
        if (pItem->value().toString().toLower() == "string") return new QMLType(QPoint(), QVariant::String);
        if (pItem->value().toString().toLower() == "color") return new QMLType(QPoint(), QVariant::Color);
        if (pItem->value().toString().toLower() == "font") return new QMLType(QPoint(), QVariant::Font);
    }

    return new QMLType(QPoint(), QVariant::Invalid);
}
