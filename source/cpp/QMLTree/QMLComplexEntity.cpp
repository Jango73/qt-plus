
// Qt
#include <QDebug>

// Application
#include "QMLComplexEntity.h"
#include "QMLItem.h"
#include "QMLComment.h"
#include "QMLFunction.h"
#include "QMLPropertyAssignment.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLComplexEntity
    \inmodule qt-plus
    \brief The base entity for a QML tree.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLComplexEntity. \br\br
    \a pPosition is the position of the token in the file.
    \a pName is the name of the entity.
*/
QMLComplexEntity::QMLComplexEntity(const QPoint& pPosition, QMLEntity* pName)
    : QMLEntity(pPosition)
    , m_pName(pName)
    , m_bIsArray(false)
    , m_bIsObject(false)
    , m_bIsBlock(false)
    , m_bIsArgumentList(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLComplexEntity.
*/
QMLComplexEntity::~QMLComplexEntity()
{
    if (m_pName != nullptr)
    {
        delete m_pName;
    }

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            delete pEntity;
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's name to \a pName.
*/
void QMLComplexEntity::setName(QMLEntity* pName)
{
    if (m_pName != nullptr)
        delete m_pName;

    m_pName = pName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's 'is array' flag \a bValue.
*/
void QMLComplexEntity::setIsArray(bool bValue)
{
    m_bIsArray = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's 'is object' flag \a bValue.
*/
void QMLComplexEntity::setIsObject(bool bValue)
{
    m_bIsObject = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's 'is block' flag \a bValue.
*/
void QMLComplexEntity::setIsBlock(bool bValue)
{
    m_bIsBlock = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the entity's 'is argument list' flag \a bValue.
*/
void QMLComplexEntity::setIsArgumentList(bool bValue)
{
    m_bIsArgumentList = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's name.
*/
QMLEntity* QMLComplexEntity::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's contents.
*/
QVector<QMLEntity*>& QMLComplexEntity::contents()
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the entity's contents.
*/
const QVector<QMLEntity*>& QMLComplexEntity::contents() const
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the entity is named.
*/
bool QMLComplexEntity::isNamed() const
{
    return (m_pName != nullptr && m_pName->toString().isEmpty() == false);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value of the entity's 'is array' flag.
*/
bool QMLComplexEntity::isArray() const
{
    return m_bIsArray;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value of the entity's 'is object' flag.
*/
bool QMLComplexEntity::isObject() const
{
    return m_bIsObject;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value of the entity's 'is block' flag.
*/
bool QMLComplexEntity::isBlock() const
{
    return m_bIsBlock;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the value of the entity's 'is argument list' flag.
*/
bool QMLComplexEntity::isArgumentList() const
{
    return m_bIsArgumentList;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a map of class members.
*/
QMap<QString, QMLEntity*> QMLComplexEntity::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["name"] = m_pName;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a vector of the entity's contents. They are unlinked from this entity.
*/
QVector<QMLEntity*> QMLComplexEntity::grabContents()
{
    QVector<QMLEntity*> vReturnValue;
    foreach (QMLEntity* pEntity, m_vContents)
    {
        vReturnValue << pEntity;
    }
    m_vContents.clear();
    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

static bool compareEntities(QMLEntity*& entity1, QMLEntity*& entity2)
{
    QMLPropertyAssignment* pAssign1 = dynamic_cast<QMLPropertyAssignment*>(entity1);
    QMLPropertyAssignment* pAssign2 = dynamic_cast<QMLPropertyAssignment*>(entity2);
    QMLPropertyDeclaration* pDeclaration1 = dynamic_cast<QMLPropertyDeclaration*>(entity1);
    QMLPropertyDeclaration* pDeclaration2 = dynamic_cast<QMLPropertyDeclaration*>(entity2);

    // Check id property
    if (pAssign1 != nullptr && pAssign1->name() != nullptr && pAssign1->name()->toString() == "id")
        return true;

    if (pAssign2 != nullptr && pAssign2->name() != nullptr && pAssign2->name()->toString() == "id")
        return false;

    // Check object name property
    if (pAssign1 != nullptr && pAssign1->name() != nullptr && pAssign1->name()->toString() == "objectName")
        return true;

    if (pAssign2 != nullptr && pAssign2->name() != nullptr && pAssign2->name()->toString() == "objectName")
        return false;

    // Check width property
    if (pAssign1 != nullptr && pAssign1->name() != nullptr && pAssign1->name()->toString() == "width")
        return true;

    if (pAssign2 != nullptr && pAssign2->name() != nullptr && pAssign2->name()->toString() == "width")
        return false;

    // Check height property
    if (pAssign1 != nullptr && pAssign1->name() != nullptr && pAssign1->name()->toString() == "height")
        return true;

    if (pAssign2 != nullptr && pAssign2->name() != nullptr && pAssign2->name()->toString() == "height")
        return false;

    // Check property assignement
    if (pAssign1 != nullptr && pAssign2 == nullptr)
        return true;

    if (pAssign2 != nullptr && pAssign1 == nullptr)
        return false;

    // Check property declaration
    if (pDeclaration1 != nullptr && pDeclaration2 == nullptr)
        return true;

    if (pDeclaration2 != nullptr && pDeclaration1 == nullptr)
        return false;

    // Check class name
    QString sClass1 = entity1->metaObject()->className();
    QString sClass2 = entity2->metaObject()->className();

    int iClassCompare = strcmp(sClass1.toLatin1().constData(), sClass2.toLatin1().constData());

    if (iClassCompare == 0)
    {
        // Check function names
        QMLFunction* pFunction1 = dynamic_cast<QMLFunction*>(entity1);
        QMLFunction* pFunction2 = dynamic_cast<QMLFunction*>(entity2);

        if (pFunction1 != nullptr && pFunction2 != nullptr && pFunction1->name() != nullptr && pFunction2->name() != nullptr)
        {
            int iNameCompare = strcmp(
                        pFunction1->name()->toString().toLatin1().constData(),
                        pFunction2->name()->toString().toLatin1().constData()
                        );

            return iNameCompare < 0;
        }

        // Check property declaration names
        if (pDeclaration1 != nullptr && pDeclaration2 != nullptr && pDeclaration1->name() != nullptr && pDeclaration2->name() != nullptr)
        {
            int iNameCompare = strcmp(
                        pDeclaration1->name()->toString().toLatin1().constData(),
                        pDeclaration2->name()->toString().toLatin1().constData()
                        );

            return iNameCompare < 0;
        }
    }

    return iClassCompare > 0;
}

/*!
    Sorts contents of entity.
*/
void QMLComplexEntity::sortContents()
{
    QMLEntity::sortContents();

    // TODO : item orders must not change
    /*
    if (dynamic_cast<QMLItem*>(this) != nullptr)
    {
        QVector<QMLEntity*> vContentsCopy;

        foreach (QMLEntity* pEntity, m_vContents)
            vContentsCopy << pEntity;

        qSort(m_vContents.begin(), m_vContents.end(), compareEntities);

        // Put comments in correct order
        for (int index = 0; index < m_vContents.count(); index++)
        {
            QMLComment* pComment = dynamic_cast<QMLComment*>(vContentsCopy[index]);

            if (pComment != nullptr && pComment->attachedTo() != nullptr)
            {
                int from = m_vContents.indexOf(pComment);
                int to = m_vContents.indexOf(pComment->attachedTo());

                if (from != -1 && to != -1)
                    m_vContents.move(from, to);
            }
        }
    }

    foreach (QMLEntity* pChild, m_vContents)
    {
        pChild->sortContents();
    }
    */
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds all symbols in the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLComplexEntity::solveSymbols(QMLTreeContext* pContext)
{
    QMLEntity::solveSymbols(pContext);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        pEntity->setParent(this);
        pEntity->solveSymbols(pContext);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLComplexEntity::solveReferences(QMLTreeContext* pContext)
{
    QMLEntity::solveReferences(pContext);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        pEntity->solveReferences(pContext);
    }
}

//-------------------------------------------------------------------------------------------------

void QMLComplexEntity::solveSymbolUsages(QMLTreeContext* pContext)
{
    QMLEntity::solveSymbolUsages(pContext);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            pEntity->solveSymbolUsages(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared symbols.
*/
QMap<QString, QMLEntity*> QMLComplexEntity::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue = QMLEntity::getDeclaredSymbols();

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            QMap<QString, QMLEntity*> itemSymbols = pEntity->getDeclaredSymbols();

            foreach (QString sKey, itemSymbols.keys())
            {
                if (mReturnValue.contains(sKey) == false)
                {
                    mReturnValue[sKey] = itemSymbols[sKey];
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
QMLEntity* QMLComplexEntity::findSymbolDeclarationDescending(QStringList& lQualifiedName)
{
    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            QMLEntity* pFoundEntity = pEntity->findSymbolDeclarationDescending(lQualifiedName);

            if (pFoundEntity != nullptr)
            {
                return pFoundEntity;
            }
        }
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Removes all unreferenced declarations in this entity. \br\br
    \a pContext is the context of this entity. \br
*/
void QMLComplexEntity::removeUnreferencedSymbols(QMLTreeContext* pContext)
{
    QMLEntity::removeUnreferencedSymbols(pContext);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            pEntity->removeUnreferencedSymbols(pContext);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the entity as QML to \a stream using \a iIdent for indentation. \br\br
    \a pParent is the caller of this method.
*/
void QMLComplexEntity::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    if (m_bIsArray && m_vContents.count() == 0)
    {
        stream << "[]";
    }
    else
    {
        if (isNamed())
        {
            if (QMLEntity::isPropertyAssignment(pParent) == false && m_bIsArgumentList == false)
                formatter.processFragment(stream, QMLFormatter::qffBeforeItemName);

            m_pName->toQML(stream, formatter, this);

            if (QMLEntity::isPropertyAssignment(pParent) == false && m_bIsArgumentList == false)
                formatter.processFragment(stream, QMLFormatter::qffAfterItemName);
        }

        if (m_bIsArray)
        {
            stream << "[";
            formatter.processFragment(stream, QMLFormatter::qffBeforeItemContent);
        }
        else if (m_bIsObject || m_bIsBlock || isNamed())
        {
            stream << " {";
            formatter.processFragment(stream, QMLFormatter::qffBeforeItemContent);
        }

        if (m_bIsParenthesized)
        {
            stream << "(";
        }

        int iCount = 0;

        foreach (QMLEntity* pEntity, m_vContents)
        {
            if (pEntity != nullptr)
            {
                if (m_bIsArray || m_bIsObject || m_bIsArgumentList)
                {
                    if (iCount > 0)
                    {
                        stream << ", ";
                    }
                }

                pEntity->toQML(stream, formatter, this);

                iCount++;
            }
        }

        if (m_bIsParenthesized)
        {
            stream << ")";
        }

        if (m_bIsArray)
        {
            formatter.processFragment(stream, QMLFormatter::qffAfterItemContent);
            stream << "]";
        }
        else if (m_bIsObject || m_bIsBlock || isNamed())
        {
            formatter.processFragment(stream, QMLFormatter::qffAfterItemContent);
            stream << "}";
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLComplexEntity::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    if (m_pName != nullptr)
    {
        xNode.attributes()["Name"] = m_pName->toString();
    }

    if (m_bIsArray)
        xNode.attributes()["IsArray"] = "true";

    if (m_bIsObject)
        xNode.attributes()["IsObject"] = "true";

    if (m_bIsBlock)
        xNode.attributes()["IsBlock"] = "true";

    if (m_bIsArgumentList)
        xNode.attributes()["IsArgumentList"] = "true";

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            CXMLNode xChild = pEntity->toXMLNode(pContext, this);
            xNode.nodes() << xChild;
        }
    }

    return xNode;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QMLComplexEntity built using \a pEntity.
*/
QMLComplexEntity* QMLComplexEntity::fromEntity(QMLEntity* pEntity)
{
    QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pEntity);

    if (pComplex == nullptr)
    {
        if (pEntity != nullptr)
        {
            pComplex = new QMLComplexEntity(pEntity->position());
            pComplex->contents() << pEntity;
        }
        else
        {
            pComplex = new QMLComplexEntity(QPoint());
        }
    }

    return pComplex;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a QMLComplexEntity built using \a pEntity, and marked as 'block'.
*/
QMLComplexEntity* QMLComplexEntity::makeBlock(QMLEntity* pEntity)
{
    QMLComplexEntity* pComplex = fromEntity(pEntity);

    pComplex->setIsBlock(true);

    return pComplex;
}
