
// Application
#include "QMLArrayAccess.h"

//-------------------------------------------------------------------------------------------------

QMLArrayAccess::QMLArrayAccess(const QPoint& pPosition, QMLEntity* pLeft)
    : QMLComplexEntity(pPosition)
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
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLArrayAccess::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLEntity* pParent, int iIdent)
{
    Q_UNUSED(pParent);

    if (m_pLeft != nullptr)
    {
        m_pLeft->toQML(stream, pContext, this, iIdent + 1);
    }

    foreach (QMLEntity* pEntity, m_vContents)
    {
        dumpNoIndentNoNewLine(stream, "[");
        pEntity->toQML(stream, pContext, this, iIdent + 1);
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
