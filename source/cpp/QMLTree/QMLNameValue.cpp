
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
    Constructs a QMLNameValue.
*/
QMLNameValue::QMLNameValue(const QPoint& pPosition)
    : QMLItem(pPosition)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLNameValue with \a sName and \a sValue.
*/
QMLNameValue::QMLNameValue(const QPoint& pPosition, const QString& sName, const QVariant& sValue)
    : QMLItem(pPosition, sValue)
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
    Dumps the item to \a stream using \a iIdent for indentation.
*/
void QMLNameValue::dump(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, QString("[QMLNameValue]"));
    dumpIndented(stream, iIdent, QString("Name : %1").arg(m_sName));

    QMLItem::dump(stream, iIdent);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLNameValue::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    if (m_sName.isEmpty() == false)
    {
        xNode.attributes()["Name"] = m_sName;
    }

    return xNode;
}
