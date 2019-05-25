
// Qt
#include <QDebug>

// Application
#include "QMLItem.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLItem::QMLItem(const QPoint& pPosition, QMLEntity* pName)
    : QMLComplexEntity(pPosition, pName)
    , m_bIsSingleton(false)
{
    m_iUsageCount = 1;
}

//-------------------------------------------------------------------------------------------------

QMLItem::~QMLItem()
{
}

//-------------------------------------------------------------------------------------------------

QString QMLItem::id() const
{
    return m_sID;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the is singleton flag.
*/
bool QMLItem::isSingleton() const
{
    return m_bIsSingleton;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLItem::unusedProperties()
{
    QMap<QString, QMLEntity*> mReturnValue;

    if (m_bIsSingleton == false)
    {
        for (QString sKey : m_mPropertyList.keys())
        {
            if (m_mPropertyList[sKey]->usageCount() == 0)
            {
                mReturnValue[sKey] = m_mPropertyList[sKey];
            }
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLItem::markAsSingleton()
{
    m_bIsSingleton = true;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds all symbols in the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLItem::solveSymbols(QMLTreeContext* pContext)
{
    QMLComplexEntity::solveSymbols(pContext);

    for (QMLEntity* pEntity : m_vContents)
    {
        QMLPropertyDeclaration* pDeclaration = dynamic_cast<QMLPropertyDeclaration*>(pEntity);
        QMLPropertyAssignment* pAssignment = dynamic_cast<QMLPropertyAssignment*>(pEntity);

        if (pDeclaration != nullptr && pAssignment == nullptr)
        {
            if (pDeclaration->name() != nullptr)
            {
                QString sName = pDeclaration->name()->toString();

                m_mPropertyList[sName] = pDeclaration->name();
            }
        }
        else
        {
            pEntity->solveReferences(pContext);
        }
    }

    m_mPropertyList["id"] = this;

    for (QMLEntity* pEntity : m_vContents)
    {
        QMLPropertyAssignment* pAssignment = dynamic_cast<QMLPropertyAssignment*>(pEntity);

        if (pAssignment != nullptr)
        {
            QMLIdentifier* pIdentifier = dynamic_cast<QMLIdentifier*>(pAssignment->name());

            if (pIdentifier != nullptr && pIdentifier->toString() == "id")
            {
                QMLIdentifier* pValue = dynamic_cast<QMLIdentifier*>(pAssignment->content());

                if (pValue != nullptr)
                {
                    m_sID = pValue->toString();
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLItem::solveReferences(QMLTreeContext* pContext)
{
    QMLComplexEntity::solveReferences(pContext);

    for (QMLEntity* pEntity : m_vContents)
    {
        pEntity->solveReferences(pContext);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLEntity* QMLItem::findSymbolDeclaration(const QString& sName)
{
    QStringList lQualifiedName = QMLEntity::qualifiedNameAsList(sName);

    if (lQualifiedName.count() > 0)
    {
        if (lQualifiedName[0] == id())
        {
            if (lQualifiedName.count() > 1)
            {
                lQualifiedName.removeAt(0);
            }
            else
            {
                return this;
            }
        }

        if (lQualifiedName.count() == 1)
        {
            if (m_mPropertyList.contains(lQualifiedName[0]))
            {
                return m_mPropertyList[lQualifiedName[0]];
            }
        }

        return QMLComplexEntity::findSymbolDeclaration(QMLEntity::listAsQualifiedName(lQualifiedName));
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLEntity* QMLItem::findSymbolDeclarationDescending(QStringList& lQualifiedName)
{
    if (lQualifiedName.count() > 0)
    {
        if (lQualifiedName[0] == id())
        {
            if (lQualifiedName.count() > 1)
            {
                lQualifiedName.removeAt(0);
            }
            else
            {
                return this;
            }
        }

        if (lQualifiedName.count() == 1)
        {
            if (m_mPropertyList.contains(lQualifiedName[0]))
            {
                return m_mPropertyList[lQualifiedName[0]];
            }
        }
    }

    return QMLComplexEntity::findSymbolDeclarationDescending(lQualifiedName);
}

//-------------------------------------------------------------------------------------------------

void QMLItem::removeUnreferencedSymbols(QMLTreeContext* pContext)
{
    QMLComplexEntity::removeUnreferencedSymbols(pContext);

    for (int index = 0; index < m_vContents.count(); index++)
    {
        QMLPropertyDeclaration* pDeclaration = dynamic_cast<QMLPropertyDeclaration*>(m_vContents[index]);
        QMLPropertyAssignment* pAssignment = dynamic_cast<QMLPropertyAssignment*>(m_vContents[index]);

        if (pDeclaration != nullptr && pAssignment == nullptr)
        {
            if (pDeclaration->name() != nullptr && pDeclaration->name()->usageCount() == 0)
            {
                m_vContents.removeAt(index);
                index--;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLItem::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexEntity::toXMLNode(pContext, pParent);
    CXMLNode xPropertyList("PropertyList");

    for (QString sKey : m_mPropertyList.keys())
    {
        CXMLNode xProperty("Property");
        xProperty.attributes()["Name"] = sKey;
        xPropertyList << xProperty;
    }

    xNode.nodes() << xPropertyList;

    return xNode;
}
