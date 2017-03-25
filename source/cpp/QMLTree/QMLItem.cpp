
// Qt
#include <QDebug>

// Application
#include "QMLItem.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

QMLItem::QMLItem(const QPoint& pPosition, QMLEntity* pName)
    : QMLComplexEntity(pPosition, pName)
{
    m_mPropertyList["id"] = this;
}

//-------------------------------------------------------------------------------------------------

QMLItem::~QMLItem()
{
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLItem::unusedProperties()
{
    QMap<QString, QMLEntity*> mReturnValue;

    foreach (QString sKey, m_mPropertyList.keys())
    {
        if (m_mPropertyList[sKey]->usageCount() == 0)
        {
            mReturnValue[sKey] = m_mPropertyList[sKey];
        }
    }

    return mReturnValue;
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

            pDeclaration->content()->solveOrigins(pContext);
        }
        else
        {
            pEntity->solveOrigins(pContext);
        }
    }
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
