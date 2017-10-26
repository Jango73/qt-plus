
// Qt
#include <QDebug>

// Application
#include "QMLEntity.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLEntity
    \inmodule qt-plus
    \brief The base entity for a QML tree.
*/

//-------------------------------------------------------------------------------------------------

QMLFormatter::QMLFormatter()
    : m_iIndentation(0)
{
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::incIndentation()
{
    m_iIndentation++;
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::decIndentation()
{
    m_iIndentation--;

    if (m_iIndentation < 0)
        m_iIndentation = 0;
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::writeNewLine(QTextStream& stream)
{
    stream << "\r\n";

    for (int i = 0; i < m_iIndentation * 4; i++)
    {
        stream << " ";
    }
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::writeDoubleNewLine(QTextStream& stream)
{
    stream << "\r\n";
    writeNewLine(stream);
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::processFragment(QTextStream& stream, EQMLFormatterFragment fragment)
{
    switch (fragment)
    {
        case qffBeforeImport:
            writeNewLine(stream);
            break;

        case qffBeforeItemName:
        case qffBeforeFunction:
        case qffBeforeFor:
        case qffBeforeWhile:
        case qffBeforeSwitch:
        case qffBeforeIf:
            writeDoubleNewLine(stream);
            break;

        case qffBeforeItemContent:
            incIndentation();
            break;

        case qffAfterItemContent:
            decIndentation();
            writeNewLine(stream);
            break;

        case qffBeforePropertyName:
        case qffBeforeVariableDeclaration:
        case qffBeforeFunctionCall:
        case qffBeforeTopLevelBinaryOp:
        case qffBeforeTopLevelUnaryOp:
        case qffBeforeQualifiedExpression:
            writeNewLine(stream);
            break;
    }
}

//-------------------------------------------------------------------------------------------------

QList<QMLEntity*> QMLEntity::s_vEntities;
int QMLEntity::s_iCreatedEntities = 0;
int QMLEntity::s_iDeletedEntities = 0;

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLEntity. \br\br
    \a pPosition is the position of the token in the file.
*/
QMLEntity::QMLEntity(const QPoint& pPosition)
    : m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_iUsageCount(0)
    , m_bIsParenthesized(false)
{
#ifdef TRACK_ENTITIES
    s_iCreatedEntities++;
    s_vEntities << this;
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLEntity with \a value.
*/
QMLEntity::QMLEntity(const QPoint& pPosition, const QVariant& value)
    : m_vValue(value)
    , m_pPosition(pPosition)
    , m_pOrigin(nullptr)
    , m_iUsageCount(0)
    , m_bIsParenthesized(false)
{
#ifdef TRACK_ENTITIES
    s_iCreatedEntities++;
    s_vEntities << this;
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLEntity.
*/
QMLEntity::~QMLEntity()
{
#ifdef TRACK_ENTITIES
    s_iDeletedEntities++;
    s_vEntities.removeAll(this);
#endif
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's value to \a value.
*/
void QMLEntity::setValue(const QVariant& value)
{
    m_vValue = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's position to \a point.
*/
void QMLEntity::setPosition(const QPoint& point)
{
    m_pPosition = point;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's origin to \a pEntity.
*/
void QMLEntity::setOrigin(QMLEntity* pEntity)
{
    m_pOrigin = pEntity;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's isParenthesized flag to \a bValue.
*/
void QMLEntity::setIsParenthesized(bool bValue)
{
    m_bIsParenthesized = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's position in the file. \br\br
    The x component is the column (from 0).\br
    The y component is the line (from 0).
*/
QPoint QMLEntity::position() const
{
    return m_pPosition;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's origin, i.e where it was declared.
*/
QMLEntity* QMLEntity::origin() const
{
    return m_pOrigin;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's usage count.
*/
int QMLEntity::usageCount() const
{
    return m_iUsageCount;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's value.
*/
QVariant QMLEntity::value() const
{
    return m_vValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's isParenthesized flag.
*/
bool QMLEntity::isParenthesized() const
{
    return m_bIsParenthesized;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity as a string.
*/
QString QMLEntity::toString() const
{
    QString sText;
    QTextStream stream(&sText);
    QMLFormatter formatter;
    toQML(stream, formatter);
    return sText;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity as a simple string.
*/
QString QMLEntity::toSimpleString() const
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
    Returns a clone of this entity.
*/
QMLEntity* QMLEntity::clone() const
{
    QMLEntity* pEntity = new QMLEntity(m_pPosition);

    pEntity->m_vValue               = m_vValue;
    pEntity->m_pPosition            = m_pPosition;
    pEntity->m_pOrigin              = m_pOrigin;
    pEntity->m_iUsageCount          = m_iUsageCount;
    pEntity->m_bIsParenthesized     = m_bIsParenthesized;

    return pEntity;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds all symbols in the entity. \br\br
    \a pContext is the context of this entity. \br
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
*/
void QMLEntity::solveSymbols(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->setParent(this);
            mMembers[sMemberKey]->solveSymbols(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the entity. \br\br
    \a pContext is the context of this entity. \br
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
*/
void QMLEntity::solveReferences(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->solveReferences(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Checks how many times each symbol is used. \br\br
    \a pContext is the context of this item.
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
*/
void QMLEntity::solveSymbolUsages(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->solveSymbolUsages(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
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
    Returns the entity named \a sName, for identifier resolution. \br\br
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
*/
QMLEntity* QMLEntity::findSymbolDeclaration(const QString& sName)
{
    QMLEntity* pParent = dynamic_cast<QMLEntity*>(parent());

    if (pParent != nullptr)
    {
        return pParent->findSymbolDeclaration(sName);
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity named \a lQualifiedName, for identifier resolution. \br\br
    This is used by the parser for symbol resolution, there is no need to call it from anywhere else.
*/
QMLEntity* QMLEntity::findSymbolDeclarationDescending(QStringList& lQualifiedName)
{
    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Removes all unreferenced declarations in this entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLEntity::removeUnreferencedSymbols(QMLTreeContext* pContext)
{
    QMap<QString, QMLEntity*> mMembers = members();

    foreach (QString sMemberKey, mMembers.keys())
    {
        if (mMembers[sMemberKey] != nullptr)
        {
            mMembers[sMemberKey]->removeUnreferencedSymbols(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the entity as QML to \a stream using \a iIdent for indentation. \br\br
    \a pParent is the caller of this method.
*/
void QMLEntity::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
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
        stream << sValue;
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

    xNode.attributes()["Position"] = QString("<%1, %2>").arg(m_pPosition.x()).arg(m_pPosition.y());

    if (sValue.isEmpty() == false)
    {
        xNode.attributes()["Value"] = sValue;
    }

    if (m_bIsParenthesized)
    {
        xNode.attributes()["IsParenthesized"] = "true";
    }

    if (parent() == nullptr)
    {
        xNode.attributes()["Parent"] = "NULL";
    }

    if (m_pOrigin != nullptr)
    {
        xNode.attributes()["Origin"] = QString("(Class: %1, Address: %2)")
                .arg(m_pOrigin->metaObject()->className())
                .arg((qulonglong) m_pOrigin);
    }

    if (m_iUsageCount > 0)
    {
        xNode.attributes()["UsageCount"] = QString::number(m_iUsageCount);
    }

    xNode.attributes()["Details"] = QString("(Class: %1, Address: %2)")
            .arg(metaObject()->className())
            .arg((qulonglong) this);

    return xNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string list with each dot-separated component of \a sName.
*/
QStringList QMLEntity::qualifiedNameAsList(const QString& sName)
{
    return sName.split(".");
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string composed of each string in \a sNameList, separated with a dot.
*/
QString QMLEntity::listAsQualifiedName(const QStringList& sNameList)
{
    QString sReturnValue;

    foreach (QString sName, sNameList)
    {
        if (sReturnValue.isEmpty() == false)
        {
            sReturnValue += ".";
        }

        sReturnValue += sName;
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns number of created QMLEntity objects.
*/
int QMLEntity::entityCount()
{
    return s_vEntities.count();
}

/*!
    Returns number of created QMLEntity objects.
*/
int QMLEntity::createdEntities()
{
    return s_iCreatedEntities;
}

/*!
    Returns number of deleted QMLEntity objects.
*/
int QMLEntity::deletedEntities()
{
    return s_iDeletedEntities;
}

/*!
    Returns created QMLEntity objects.
*/
QList<QMLEntity*>& QMLEntity::entities()
{
    return s_vEntities;
}
