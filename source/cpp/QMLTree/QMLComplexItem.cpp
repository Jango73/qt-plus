
// Application
#include "QMLComplexItem.h"

//-------------------------------------------------------------------------------------------------

QMLComplexItem::QMLComplexItem(const QPoint& pPosition, QMLItem* pName)
    : QMLItem(pPosition)
    , m_pName(pName)
{
}

//-------------------------------------------------------------------------------------------------

QMLComplexItem::~QMLComplexItem()
{
    if (m_pName != NULL)
        delete m_pName;

    foreach (QMLItem* pItem, m_vContents)
    {
        if (pItem != NULL)
        {
            delete pItem;
        }
    }
}

//-------------------------------------------------------------------------------------------------

void QMLComplexItem::setName(QMLItem* pName)
{
    if (m_pName != NULL)
        delete m_pName;

    m_pName = pName;
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
    }
    else if (m_vContents.count() == 1)
    {
        if (m_vContents[0] != nullptr)
        {
            m_vContents[0]->toQML(stream, pContext, this, iIdent);
        }
    }
    else
    {
        if (m_pName != NULL)
        {
            dumpIndentedNoNewLine(stream, iIdent, "");
            m_pName->toQML(stream, pContext, this, iIdent);
            dumpNewLine(stream);
        }

        if (pParent != NULL)
            dumpOpenBlock(stream, iIdent);

        foreach (QMLItem* pItem, m_vContents)
        {
            if (pItem != NULL)
            {
                pItem->toQML(stream, pContext, this, pParent != NULL ? iIdent + 1 : iIdent);
            }
        }

        if (pParent != NULL)
            dumpCloseBlock(stream, iIdent);
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLComplexItem::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);

    if (m_pName != NULL)
    {
        xNode.attributes()["Name"] = m_pName->value().toString();
    }

    foreach (QMLItem* pItem, m_vContents)
    {
        if (pItem != NULL)
        {
            CXMLNode xChild = pItem->toXMLNode(pContext, this);
            xNode.nodes() << xChild;
        }
    }

    return xNode;
}
