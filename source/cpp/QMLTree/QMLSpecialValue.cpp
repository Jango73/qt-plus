
// Application
#include "QMLSpecialValue.h"

//-------------------------------------------------------------------------------------------------

QMLSpecialValue::QMLSpecialValue(const QPoint& pPosition)
    : QMLEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

QMLSpecialValue::QMLSpecialValue(const QPoint& pPosition, ESpecialValue value)
    : QMLEntity(pPosition)
    , m_eValue(value)
{
}

//-------------------------------------------------------------------------------------------------

QMLSpecialValue::~QMLSpecialValue()
{
}

//-------------------------------------------------------------------------------------------------

void QMLSpecialValue::setSpecialValue(ESpecialValue value)
{
    m_eValue = value;
}

//-------------------------------------------------------------------------------------------------

QMLSpecialValue::ESpecialValue QMLSpecialValue::specialValue() const
{
    return m_eValue;
}

//-------------------------------------------------------------------------------------------------

void QMLSpecialValue::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    switch (m_eValue)
    {
        case svNull:
            stream << "null";
            break;
        case svUndefined:
            stream << "undefined";
            break;
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLSpecialValue::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    xNode.attributes()["Value"] = toString();

    return xNode;
}
