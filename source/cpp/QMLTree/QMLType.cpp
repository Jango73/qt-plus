
// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

QMLType::QMLType()
{
}

//-------------------------------------------------------------------------------------------------

QMLType::QMLType(QVariant::Type type)
    : m_vType(type)
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

QString QMLType::typeToString(QVariant::Type eType) const
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
