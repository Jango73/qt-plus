
// Qt
#include <QDebug>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLEntity
    \inmodule unis-lib
    \brief The base item for a QML tree.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLItem. \br\br
    \a pPosition is the position of the token in the file
*/
QMLEntity::QMLEntity(const QPoint& pPosition)
    : m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_iUsageCount(0)
    , m_bIsParenthesized(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLItem with \a value.
*/
QMLEntity::QMLEntity(const QPoint& pPosition, const QVariant& value)
    : m_vValue(value)
    , m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_iUsageCount(0)
    , m_bIsParenthesized(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLItem.
*/
QMLEntity::~QMLEntity()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's value to \a value.
*/
void QMLEntity::setValue(const QVariant& value)
{
    m_vValue = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's position to \a point.
*/
void QMLEntity::setPosition(const QPoint& point)
{
    m_pPosition = point;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's origin to \a pEntity.
*/
void QMLEntity::setOrigin(QMLEntity* pEntity)
{
    m_pOrigin = pEntity;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the item's isParenthesized flag to \a bValue.
*/
void QMLEntity::setIsParenthesized(bool bValue)
{
    m_bIsParenthesized = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's position in the file.
*/
QPoint QMLEntity::position() const
{
    return m_pPosition;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's origin.
*/
QMLEntity* QMLEntity::origin() const
{
    return m_pOrigin;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's usage count.
*/
int QMLEntity::usageCount() const
{
    return m_iUsageCount;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's value.
*/
QVariant QMLEntity::value() const
{
    return m_vValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item's isParenthesized flag.
*/
bool QMLEntity::isParenthesized() const
{
    return m_bIsParenthesized;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item as a string.
*/
QString QMLEntity::toString() const
{
    return m_vValue.toString();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a map of class members.
*/
QMap<QString, QMLEntity*> QMLEntity::members()
{
    return QMap<QString, QMLEntity*>();
}

//-------------------------------------------------------------------------------------------------

/*!
    Increments the usage count for this object.
*/
void QMLEntity::incUsageCount()
{
    m_iUsageCount++;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
*/
void QMLEntity::solveOrigins(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->setParent(this);
            mMembers[sMemberKey]->solveOrigins(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLEntity::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue;

    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            QMap<QString, QMLEntity*> memberSymbols = mMembers[sMemberKey]->getDeclaredSymbols();

            foreach (QString sSymbolKey, memberSymbols.keys())
            {
                if (mReturnValue.contains(sSymbolKey) == false)
                {
                    mReturnValue[sSymbolKey] = memberSymbols[sSymbolKey];
                }
            }
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution. \br\br
*/
QMLEntity* QMLEntity::findSymbolDeclaration(const QString& sName)
{
    QMLEntity* pParent = dynamic_cast<QMLEntity*>(parent());

    if (pParent != nullptr)
    {
        // qDebug() << "QMLEntity::findSymbolDeclaration() : returning parent " << pParent->metaObject()->className();

        return pParent->findSymbolDeclaration(sName);
    }

    // qDebug() << "QMLEntity::findSymbolDeclaration() : returning null";

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Checks how many times each symbol is used. \br\br
    \a pContext is the context of this item.
*/
void QMLEntity::checkSymbolUsages(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->checkSymbolUsages(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLEntity::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
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
        case QVariant::Color :
        case QVariant::Point :
        case QVariant::PointF :
        case QVariant::Font :
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
CXMLNode QMLEntity::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode(metaObject()->className());
    QString sValue = m_vValue.value<QString>();

    if (sValue.isEmpty() == false)
    {
        xNode.attributes()["Value"] = sValue;
    }

    if (m_bIsParenthesized)
    {
        xNode.attributes()["IsParenthesized"] = "true";
    }

    if (m_pOrigin != nullptr)
    {
        xNode.attributes()["Origin"] = m_pOrigin->metaObject()->className();
    }

    if (m_iUsageCount > 0)
    {
        xNode.attributes()["UsageCount"] = QString::number(m_iUsageCount);
    }

    return xNode;
}
