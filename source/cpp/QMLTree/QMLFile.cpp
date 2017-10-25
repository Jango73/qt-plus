
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

    return xNode;
}
