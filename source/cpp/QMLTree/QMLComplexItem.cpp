
// Application
#include "QMLComplexItem.h"

//-------------------------------------------------------------------------------------------------

QMLComplexItem::QMLComplexItem(const QPoint& pPosition, QMLItem* pName)
    : QMLItem(pPosition)
    , m_pName(pName)
    , m_bIsArray(false)
    , m_bIsObject(false)
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

void QMLComplexItem::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_vContents.count() == 0)
    {
        if (m_bIsArray)
        {
            dumpNoIndentNoNewLine(stream, "[]");
        }
    }
    else if (m_vContents.count() == 1)
    {
        if (m_bIsArray)
            dumpNoIndentNoNewLine(stream, "[");
        else if (m_bIsObject)
            dumpNoIndentNoNewLine(stream, "{");

        if (m_vContents[0] != nullptr)
        {
            m_vContents[0]->toQML(stream, pContext, this, iIdent);
        }

        if (m_bIsArray)
            dumpNoIndentNoNewLine(stream, "]");
        else if (m_bIsObject)
            dumpNoIndentNoNewLine(stream, "}");
    }
    else
    {
        if (m_pName != nullptr)
        {
            dumpIndentedNoNewLine(stream, iIdent, "");
            m_pName->toQML(stream, pContext, this, iIdent);
            dumpNewLine(stream);
        }

        if (pParent != nullptr)
        {
            if (m_bIsArray)
                dumpOpenArray(stream, iIdent);
            else
                dumpOpenBlock(stream, iIdent);
        }

        int iCount = 0;

        foreach (QMLItem* pItem, m_vContents)
        {
            if (pItem != nullptr)
            {
                if (iCount > 0 && (m_bIsObject || m_bIsArgumentList))
                {
                    dumpNoIndentNoNewLine(stream, ", ");
                }

                pItem->toQML(stream, pContext, this, pParent != NULL ? iIdent + 1 : iIdent);

                iCount++;
            }
        }

        if (pParent != nullptr)
        {
            if (m_bIsArray)
                dumpCloseArray(stream, iIdent);
            else
                dumpCloseBlock(stream, iIdent);
        }
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
