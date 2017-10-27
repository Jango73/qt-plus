
// Qt
#include <QDebug>

// Application
#include "QMLFile.h"
#include "QMLPragma.h"
#include "QMLIdentifier.h"
#include "QMLItem.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class QMLFile
    \inmodule qt-plus
    \brief A QML file.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFile with \a sFileName. \br\br
    \a pPosition is the position of the token in the file \br
    \a pContext if the parser.
*/
QMLFile::QMLFile(const QPoint& pPosition, QMLTreeContext* pContext, const QString& sFileName)
    : QMLComplexEntity(pPosition)
    , m_sFileName(sFileName)
    , m_bParsed(false)
    , m_bIsSingleton(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a QMLFile as copy of \a target. Does nothing, exists only to make containers happy.
*/
QMLFile::QMLFile(const QMLFile& target)
    : QMLComplexEntity(target.position())
    , m_bParsed(false)
    , m_bIsSingleton(false)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a QMLFile.
*/
QMLFile::~QMLFile()
{
    foreach (QMLComment* pComment, m_vComments)
    {
        delete pComment;
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the parsed flag to \a bValue.
*/
void QMLFile::setParsed(bool bValue)
{
    m_bParsed = bValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file's name.
*/
QString QMLFile::fileName() const
{
    return m_sFileName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file's comments.
*/
QVector<QMLComment*>& QMLFile::comments()
{
    return m_vComments;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the parsed flag.
*/
bool QMLFile::parsed() const
{
    return m_bParsed;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the is singleton flag.
*/
bool QMLFile::isSingleton() const
{
    return m_bIsSingleton;
}

//-------------------------------------------------------------------------------------------------

/*!
    Inserts comments stored in m_vComments where they should reside in the entity tree.
*/
void QMLFile::solveComments()
{
    for (int index = 0; index < m_vComments.count(); index++)
    {
        QMLComment* pComment = m_vComments[index];

        if (pComment->type() == QMLComment::ctMultiLine || pComment->type() == QMLComment::ctMultiLineDoc)
        {
            QMLEntity* pTarget = locateEntityAtOrAfterLine(pComment->position());

            if (pTarget != nullptr)
            {
                QMLComplexEntity* pComplexParent = dynamic_cast<QMLComplexEntity*>(pTarget->parent());

                if (pComplexParent != nullptr)
                {
                    int entityIndex = pComplexParent->contents().indexOf(pTarget);

                    if (entityIndex != -1)
                    {
                        pComplexParent->contents().insert(entityIndex, pComment);
                        m_vComments.removeAt(index);
                        index--;
                    }
                    else
                    {
                        qWarning() << QString("QMLFile::solveComments() : no valid index for comment at line %1").arg(pComment->position().y() + 1);
                    }
                }
                else
                {
                    qWarning() << QString("QMLFile::solveComments() : no parent entity found for comment at line %1").arg(pComment->position().y() + 1);
                }
            }
            else
            {
                qWarning() << QString("QMLFile::solveComments() : no entity found for comment at line %1").arg(pComment->position().y() + 1);
            }
        }
        else
        {
            QMLEntity* pTarget = locateEntityAtOrAfterLine(pComment->position());

            if (pTarget != nullptr)
            {
                QMLComplexEntity* pComplexParent = dynamic_cast<QMLComplexEntity*>(pTarget->parent());

                if (pComplexParent != nullptr)
                {
                    int entityIndex = pComplexParent->contents().indexOf(pTarget);

                    if (entityIndex != -1)
                    {
                        if (pComment->type() == QMLComment::ctSingleLine)
                        {
                            pComplexParent->contents().insert(entityIndex, pComment);
                        }
                        else
                        {
                            pComplexParent->contents().insert(entityIndex + 1, pComment);
                        }

                        m_vComments.removeAt(index);
                        index--;
                    }
                    else
                    {
                        qWarning() << QString("QMLFile::solveComments() : no valid index for comment at line %1").arg(pComment->position().y() + 1);
                    }
                }
                else
                {
                    qWarning() << QString("QMLFile::solveComments() : no parent entity found for comment at line %1").arg(pComment->position().y() + 1);
                }
            }
            else
            {
                qWarning() << QString("QMLFile::solveComments() : no entity found for comment at line %1").arg(pComment->position().y() + 1);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Locates an entity at a line specified by \a pPosition (the y component).
*/
QMLEntity* QMLFile::locateEntityAtOrAfterLine(const QPoint& pPosition)
{
    return locateEntityAtOrAfterLine_Recurse(this, pPosition);
}

//-------------------------------------------------------------------------------------------------

/*!
    Recursive part of locateEntityAtOrAfterLine. \br\br
    \a pEntity is the current entity to process. \br
    \a pPosition is the line to check (the y component).
*/
QMLEntity* QMLFile::locateEntityAtOrAfterLine_Recurse(QMLEntity* pEntity, const QPoint& pPosition)
{
    // Continue only if the current entity is not a comment
    if (dynamic_cast<QMLComment*>(pEntity) == nullptr)
    {
        // If the line of the current entity is greater or equal to the specified line, return the current entity.
        // if (dynamic_cast<QMLComplexEntity*>(pEntity) != nullptr && pEntity->position().y() >= pPosition.y())
        if (pEntity->position().y() >= pPosition.y())
        {
            return pEntity;
        }

        // Look in the members of the current entity, if any
        QMap<QString, QMLEntity*> mMembers = pEntity->members();

        foreach (QString sMemberKey, mMembers.keys())
        {
            QMLEntity* pChildEntity = mMembers[sMemberKey];

            if (pChildEntity != nullptr)
            {
                QMLEntity* pFoundEntity = locateEntityAtOrAfterLine_Recurse(pChildEntity, pPosition);

                if (pFoundEntity != nullptr)
                    return pFoundEntity;
            }
        }

        // Look in the children of the current entity, if it is a QMLComplexEntity
        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pEntity);

        if (pComplex != nullptr)
        {
            foreach (QMLEntity* pChildEntity, pComplex->contents())
            {
                QMLEntity* pFoundEntity = locateEntityAtOrAfterLine_Recurse(pChildEntity, pPosition);

                if (pFoundEntity != nullptr)
                    return pFoundEntity;
            }
        }
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
*/
void QMLFile::solveReferences(QMLTreeContext* pContext)
{
    QMLComplexEntity::solveReferences(pContext);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        QMLPragma* pPragma = dynamic_cast<QMLPragma*>(pEntity);

        if (pPragma != nullptr)
        {
            QMLIdentifier* pIdentifier = dynamic_cast<QMLIdentifier*>(pPragma->statement());

            if (pIdentifier != nullptr && pIdentifier->value().toString().toLower() == "singleton")
            {
                m_bIsSingleton = true;
            }
        }
        else
        {
            if (m_bIsSingleton)
            {
                QMLItem* pItem = dynamic_cast<QMLItem*>(pEntity);

                if (pItem != nullptr)
                {
                    pItem->markAsSingleton();
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution. \br\br
*/
QMLEntity* QMLFile::findSymbolDeclaration(const QString& sName)
{
    QStringList sQualified = QMLEntity::qualifiedNameAsList(sName);

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            QMLEntity* pFoundEntity = pEntity->findSymbolDeclarationDescending(sQualified);

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
    Returns a CXMLNode representation of this item. \br\br
    \a pContext is a user defined context. \br
    \a pParent is the caller of this method.
*/
CXMLNode QMLFile::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexEntity::toXMLNode(pContext, pParent);

    xNode.attributes()["FileName"] = m_sFileName;
    xNode.attributes()["Parsed"] = m_bParsed ? "true" : "false";

    if (m_bIsSingleton)
    {
        xNode.attributes()["Singleton"] = "true";
    }

    foreach (QMLComment* pComment, m_vComments)
    {
        xNode << pComment->toXMLNode(pContext, this);
    }

    return xNode;
}
