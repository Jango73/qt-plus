
// Application
#include "QMLType.h"

//-------------------------------------------------------------------------------------------------

QMLType::QMLType(const QPoint& pPosition)
    : QMLEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLType::QMLType(const QPoint& pPosition, QVariant::Type type)
    : QMLEntity(pPosition)
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

void QMLType::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpNoIndentNoNewLine(stream, typeToString(m_vType));
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLType::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

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
        case QVARIANT_VARIANT:
            return "variant";
    }

    return "";
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QMLType from a \a pEntity.
*/
QMLType* QMLType::fromQMLEntity(QMLEntity* pEntity)
{
    if (pEntity != nullptr)
    {
        QString sType = pEntity->value().toString().toLower();

        if (sType == "var") return new QMLType(QPoint(), QVariant::Invalid);
        if (sType == "variant") return new QMLType(QPoint(), (QVariant::Type) QVARIANT_VARIANT);
        if (sType == "bool") return new QMLType(QPoint(), QVariant::Bool);
        if (sType == "int") return new QMLType(QPoint(), QVariant::Int);
        if (sType == "real") return new QMLType(QPoint(), QVariant::Double);
        if (sType == "string") return new QMLType(QPoint(), QVariant::String);
        if (sType == "color") return new QMLType(QPoint(), QVariant::Color);
        if (sType == "font") return new QMLType(QPoint(), QVariant::Font);
    }

    return new QMLType(QPoint(), QVariant::Invalid);
}
