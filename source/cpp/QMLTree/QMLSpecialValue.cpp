
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

QString QMLSpecialValue::toString() const
{
    switch (m_eValue)
    {
        case svNull:
            return "null";
        case svUndefined:
            return "undefined";
    }

    return QMLEntity::toString();
}

//-------------------------------------------------------------------------------------------------

void QMLSpecialValue::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    stream << toString();
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLSpecialValue::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    xNode.attributes()["Value"] = toString();

    return xNode;
}
