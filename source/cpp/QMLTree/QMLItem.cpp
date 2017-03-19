
// Application
#include "QMLItem.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLItem
    \inmodule qt-plus
    \brief The base item for a QML tree.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLItem. \br\br
    \a pPosition is the position of the token in the file
*/
QMLItem::QMLItem(const QPoint& pPosition)
    : m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_bIsParenthesized(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLItem with \a value.
*/
QMLItem::QMLItem(const QPoint& pPosition, const QVariant& value)
    : m_vValue(value)
    , m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_bIsParenthesized(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLItem.
*/
QMLItem::~QMLItem()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's value to \a value.
*/
void QMLItem::setValue(const QVariant& value)
{
    m_vValue = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's position to \a point.
*/
void QMLItem::setPosition(const QPoint& point)
{
    m_pPosition = point;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's origin to \a pItem.
*/
void QMLItem::setOrigin(QMLItem* pItem)
{
    m_pOrigin = pItem;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's isParenthesized flag to \a bValue.
*/
void QMLItem::setIsParenthesized(bool bValue)
{
    m_bIsParenthesized = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's position in the file.
*/
QPoint QMLItem::position() const
{
    return m_pPosition;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's origin.
*/
QMLItem* QMLItem::origin() const
{
    return m_pOrigin;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's value.
*/
QVariant QMLItem::value() const
{
    return m_vValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's isParenthesized flag.
*/
bool QMLItem::isParenthesized() const
{
    return m_bIsParenthesized;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item as a string.
*/
QString QMLItem::toString() const
{
    return m_vValue.toString();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a map of class members.
*/
QMap<QString, QMLItem*> QMLItem::members()
{
    return QMap<QString, QMLItem*>();
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLItem::solveOrigins(QMLTreeContext* pContext, QMLItem* pParent)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLItem*> QMLItem::getDeclaredVariables()
{
    QMap<QString, QMLItem*> mReturnValue;

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLItem* QMLItem::findNamedItem(const QString& sName)
{
    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLItem::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    QString sValue;

    switch (m_vValue.type())
    {
        case QVariant::Int :
            sValue = m_vValue.toString();
            break;

        case QVariant::Double :
            sValue = m_vValue.toString();
            break;

        case QVariant::Bool :
            sValue = m_vValue.toBool() ? "true" : "false";
            break;

        case QVariant::String :
            sValue = QString("\"%1\"").arg(m_vValue.toString());
    }

    if (sValue.isEmpty() == false)
    {
        dumpNoIndentNoNewLine(stream, sValue);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLItem::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode(metaObject()->className());
    QString sValue = m_vValue.value<QString>();

    if (sValue.isEmpty() == false)
    {
        xNode.attributes()["Value"] = sValue;
    }

    return xNode;
}
