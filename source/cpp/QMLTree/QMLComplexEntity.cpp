
// Qt
#include <QDebug>

// Application
#include "QMLComplexEntity.h"

//-------------------------------------------------------------------------------------------------

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

void QMLComplexEntity::setName(QMLEntity* pName)
{
    if (m_pName != nullptr)
        delete m_pName;

    m_pName = pName;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexEntity::setIsArray(bool bValue)
{
    m_bIsArray = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexEntity::setIsObject(bool bValue)
{
    m_bIsObject = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexEntity::setIsBlock(bool bValue)
{
    m_bIsBlock = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexEntity::setIsArgumentList(bool bValue)
{
    m_bIsArgumentList = bValue;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLComplexEntity::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QVector<QMLEntity*>& QMLComplexEntity::contents()
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexEntity::isNamed() const
{
    return (m_pName != nullptr && m_pName->value().toString().isEmpty() == false);
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexEntity::isArray() const
{
    return m_bIsArray;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexEntity::isObject() const
{
    return m_bIsObject;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexEntity::isBlock() const
{
    return m_bIsBlock;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexEntity::isArgumentList() const
{
    return m_bIsArgumentList;
}

//-------------------------------------------------------------------------------------------------

const QVector<QMLEntity*>& QMLComplexEntity::contents() const
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

QString QMLComplexEntity::toString() const
{
    if (m_pName != nullptr)
    {
        return m_pName->toString();
    }

    QString sReturnValue;

    foreach (QMLEntity* pEntity, m_vContents)
    {
        if (pEntity != nullptr)
        {
            if (sReturnValue.isEmpty() == false)
            {
                sReturnValue += ", ";
            }

            sReturnValue += pEntity->toString();
        }
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLComplexEntity::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["name"] = m_pName;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

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

void QMLComplexEntity::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_bIsArray && m_vContents.count() == 0)
    {
        dumpIndentedNoNewLine(stream, iIdent, "[]");
    }
    else
    {
        if (isNamed())
        {
            dumpIndentedNoNewLine(stream, iIdent, "");
            m_pName->toQML(stream, pContext, this, iIdent);
        }

        if (m_bIsArray)
            dumpOpenArray(stream, iIdent - 1);
        else if (m_bIsObject || m_bIsBlock || isNamed())
            dumpOpenBlock(stream, iIdent - 1);

        if (m_bIsParenthesized)
        {
            dumpNoIndentNoNewLine(stream, "(");
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
                        dumpNoIndentNoNewLine(stream, ", ");
                    }
                }

                if (m_bIsBlock)
                {
                    dumpIndentedNoNewLine(stream, iIdent, "");
                }

                pEntity->toQML(stream, pContext, this, pParent != nullptr ? iIdent + 1 : iIdent);

                if (m_bIsBlock)
                {
                    dumpNewLine(stream);
                }

                iCount++;
            }
        }

        if (m_bIsParenthesized)
        {
            dumpNoIndentNoNewLine(stream, ")");
        }

        if (m_bIsArray)
            dumpCloseArray(stream, iIdent);
        else if (m_bIsObject || m_bIsBlock || isNamed())
            dumpCloseBlock(stream, iIdent);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLComplexEntity::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    if (m_pName != nullptr)
    {
        xNode.attributes()["Name"] = m_pName->value().toString();
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

QMLComplexEntity* QMLComplexEntity::fromEntity(QMLEntity* pEntity)
{
    QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>(pEntity);

    if (pComplex == nullptr)
    {
        pComplex = new QMLComplexEntity(pEntity->position());
        pComplex->contents() << pEntity;
    }

    return pComplex;
}

//-------------------------------------------------------------------------------------------------

QMLComplexEntity* QMLComplexEntity::makeBlock(QMLEntity* pEntity)
{
    QMLComplexEntity* pComplex = fromEntity(pEntity);

    pComplex->setIsBlock(true);

    return pComplex;
}
