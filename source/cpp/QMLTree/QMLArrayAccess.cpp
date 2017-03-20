
// Application
#include "QMLArrayAccess.h"

//-------------------------------------------------------------------------------------------------

QMLArrayAccess::QMLArrayAccess(const QPoint& pPosition, QMLItem* pLeft)
    : QMLComplexItem(pPosition)
    , m_pLeft(pLeft)
{
}

//-------------------------------------------------------------------------------------------------

QMLArrayAccess::~QMLArrayAccess()
{
    if (m_pLeft != nullptr)
        delete m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLArrayAccess::left() const
{
    return m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLArrayAccess::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["left"] = m_pLeft;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLItem*> QMLArrayAccess::getDeclaredVariables()
{
    QMap<QString, QMLItem*> mReturnValue;

    if (m_pLeft != nullptr)
    {
        QMap<QString, QMLItem*> leftVariables = m_pLeft->getDeclaredVariables();

        foreach (QString sKey, leftVariables.keys())
        {
            mReturnValue[sKey] = leftVariables[sKey];
        }
    }

    return mReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLArrayAccess::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pLeft != nullptr)
    {
        m_pLeft->toQML(stream, pContext, this, iIdent + 1);
    }

    foreach(QMLItem* pItem, m_vContents)
    {
        dumpNoIndentNoNewLine(stream, "[");
        pItem->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, "]");
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLArrayAccess::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexItem::toXMLNode(pContext, pParent);
    CXMLNode xLeft("Left");

    if (m_pLeft != nullptr)
        xLeft.nodes() << m_pLeft->toXMLNode(pContext, this);

    xNode.nodes() << xLeft;

    return xNode;
}
