
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

QMap<QString, QMLEntity*> QMLItem::unusedProperties()
{
    QMap<QString, QMLEntity*> mReturnValue;

    if (m_bIsSingleton == false)
    {
        foreach (QString sKey, m_mPropertyList.keys())
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
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
*/
void QMLItem::solveOrigins(QMLTreeContext* pContext)
{
    QMLComplexEntity::solveOrigins(pContext);

    // Get declared symbols
    foreach (QMLEntity* pEntity, m_vContents)
    {
        pEntity->setParent(this);

        QMLPropertyDeclaration* pDeclaration = dynamic_cast<QMLPropertyDeclaration*>(pEntity);
        QMLPropertyAssignment* pAssignment = dynamic_cast<QMLPropertyAssignment*>(pEntity);

        if (pDeclaration != nullptr && pAssignment == nullptr)
        {
            if (pDeclaration->name() != nullptr)
            {
                QString sName = pDeclaration->name()->toString();

                m_mPropertyList[sName] = pDeclaration;
            }

            if (pDeclaration->content() != nullptr)
            {
                pDeclaration->content()->solveOrigins(pContext);
            }
        }
        else
        {
            pEntity->solveOrigins(pContext);
        }
    }

    m_mPropertyList["id"] = this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLEntity* QMLItem::findSymbolDeclaration(const QString& sName)
{
    QMLIdentifier* pFoundEntity = dynamic_cast<QMLIdentifier*>(m_pName);

    if (pFoundEntity != nullptr)
    {
        if (pFoundEntity->value().toString() == sName)
        {
            return pFoundEntity;
        }
    }

    if (m_mPropertyList.contains(sName))
    {
        return m_mPropertyList[sName];
    }

    return QMLComplexEntity::findSymbolDeclaration(sName);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLItem::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexEntity::toXMLNode(pContext, pParent);
    CXMLNode xPropertyList("PropertyList");

    foreach (QString sKey, m_mPropertyList.keys())
    {
        CXMLNode xProperty("Property");
        xProperty.attributes()["Name"] = sKey;
        xPropertyList << xProperty;
    }

    xNode.nodes() << xPropertyList;

    return xNode;
}
