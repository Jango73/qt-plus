
// Application
#include "QMLComplexItem.h"

//-------------------------------------------------------------------------------------------------

QMLComplexItem::QMLComplexItem(const QPoint& pPosition, QMLItem* pName)
    : QMLItem(pPosition)
    , m_pName(pName)
    , m_bIsArray(false)
    , m_bIsObject(false)
    , m_bIsBlock(false)
    , m_bIsArgumentList(false)
{
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem::~QMLComplexItem()
{
    if (m_pName != nullptr)
        delete m_pName;

    foreach (QMLItem* pItem, m_vContents)
    {
        if (pItem != nullptr)
        {
            delete pItem;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setName(QMLItem* pName)
{
    if (m_pName != nullptr)
        delete m_pName;

    m_pName = pName;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setIsArray(bool bValue)
{
    m_bIsArray = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setIsObject(bool bValue)
{
    m_bIsObject = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setIsBlock(bool bValue)
{
    m_bIsBlock = bValue;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setIsArgumentList(bool bValue)
{
    m_bIsArgumentList = bValue;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLComplexItem::name() const
{
    return m_pName;
}

//-------------------------------------------------------------------------------------------------

QVector<QMLItem*>& QMLComplexItem::contents()
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexItem::isNamed() const
{
    return (m_pName != nullptr && m_pName->value().toString().isEmpty() == false);
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexItem::isArray() const
{
    return m_bIsArray;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexItem::isObject() const
{
    return m_bIsObject;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexItem::isBlock() const
{
    return m_bIsBlock;
}

//-------------------------------------------------------------------------------------------------

bool QMLComplexItem::isArgumentList() const
{
    return m_bIsArgumentList;
}

//-------------------------------------------------------------------------------------------------

const QVector<QMLItem*>& QMLComplexItem::contents() const
{
    return m_vContents;
}

//-------------------------------------------------------------------------------------------------

QString QMLComplexItem::toString() const
{
    QString sReturnValue;

    foreach (QMLItem* pItem, m_vContents)
    {
        if (pItem != nullptr)
        {
            if (sReturnValue.isEmpty())
            {
                sReturnValue += ", ";
            }

            sReturnValue += pItem->toString();
        }
    }

    return sReturnValue;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLComplexItem::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["name"] = m_pName;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

QVector<QMLItem*> QMLComplexItem::grabContents()
{
    QVector<QMLItem*> vReturnValue = m_vContents;
    m_vContents.clear();
    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Finds the origin of the item. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLComplexItem::solveOrigins(QMLTreeContext* pContext, QMLItem* pParent)
{
    foreach(QMLItem* pItem, m_vContents)
    {
        pItem->solveOrigins(pContext, this);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLItem*> QMLComplexItem::getDeclaredVariables()
{
    QMap<QString, QMLItem*> mReturnValue;

    foreach(QMLItem* pItem, m_vContents)
    {
        QMap<QString, QMLItem*> itemVariables = pItem->getDeclaredVariables();

        foreach (QString sKey, itemVariables.keys())
        {
            if (mReturnValue.contains(sKey) == false)
            {
                mReturnValue[sKey] = itemVariables[sKey];
            }
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the item named \a sName, for identifier resolution.
*/
QMLItem* QMLComplexItem::findNamedItem(const QString& sName)
{
    return nullptr;
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
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

        foreach (QMLItem* pItem, m_vContents)
        {
            if (pItem != nullptr)
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

                pItem->toQML(stream, pContext, this, pParent != nullptr ? iIdent + 1 : iIdent);

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

CXMLNode QMLComplexItem::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

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

    foreach (QMLItem* pItem, m_vContents)
    {
        if (pItem != nullptr)
        {
            CXMLNode xChild = pItem->toXMLNode(pContext, this);
            xNode.nodes() << xChild;
        }
    }

    return xNode;
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem* QMLComplexItem::fromItem(QMLItem* pItem)
{
    QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>(pItem);

    if (pComplex == nullptr)
    {
        pComplex = new QMLComplexItem(pItem->position());
        pComplex->contents() << pItem;
    }

    return pComplex;
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem* QMLComplexItem::makeBlock(QMLItem* pItem)
{
    QMLComplexItem* pComplex = fromItem(pItem);

    pComplex->setIsBlock(true);

    return pComplex;
}
