
// Application
#include "QMLArrayAccess.h"

//-------------------------------------------------------------------------------------------------

QMLArrayAccess::QMLArrayAccess(const QPoint& pPosition, QMLEntity* pLeft)
    : QMLComplexEntity(pPosition)
    , m_pLeft(pLeft)
{
    if (m_pLeft != nullptr) m_pLeft->setParent(this);
}

//-------------------------------------------------------------------------------------------------

QMLArrayAccess::~QMLArrayAccess()
{
    if (m_pLeft != nullptr)
        delete m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLArrayAccess::left() const
{
    return m_pLeft;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLArrayAccess::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["left"] = m_pLeft;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a list of all declared variables.
*/
QMap<QString, QMLEntity*> QMLArrayAccess::getDeclaredSymbols()
{
    QMap<QString, QMLEntity*> mReturnValue;

    if (m_pLeft != nullptr)
    {
        QMap<QString, QMLEntity*> leftVariables = m_pLeft->getDeclaredSymbols();

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
void QMLArrayAccess::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    if (m_pLeft != nullptr)
    {
        m_pLeft->toQML(stream, pContext, this, iIdent + 1);
    }

    foreach(QMLEntity* pItem, m_vContents)
    {
        dumpNoIndentNoNewLine(stream, "[");
        pItem->toQML(stream, pContext, this, iIdent + 1);
        dumpNoIndentNoNewLine(stream, "]");
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLArrayAccess::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLComplexEntity::toXMLNode(pContext, pParent);
    CXMLNode xLeft("Left");

    if (m_pLeft != nullptr)
        xLeft.nodes() << m_pLeft->toXMLNode(pContext, this);

    xNode.nodes() << xLeft;

    return xNode;
}
