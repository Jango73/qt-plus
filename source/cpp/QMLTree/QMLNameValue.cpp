
// Application
#include "QMLNameValue.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLNameValue
    \inmodule qt-plus
    \brief .
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLNameValue. \br\br
    \a pPosition is the position of the token in the file \br
*/
QMLNameValue::QMLNameValue(const QPoint& pPosition)
    : QMLEntity(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLNameValue with \a sName and \a sValue.
*/
QMLNameValue::QMLNameValue(const QPoint& pPosition, const QString& sName, const QVariant& sValue)
    : QMLEntity(pPosition, sValue)
    , m_sName(sName)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLNameValue.
*/
QMLNameValue::~QMLNameValue()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's name to \a sName.
*/
void QMLNameValue::setName(const QString& sName)
{
    m_sName = sName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's value.
*/
QString QMLNameValue::name() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLNameValue::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    if (m_sName.isEmpty() == false)
    {
        xNode.attributes()["Name"] = m_sName;
    }

    return xNode;
}
