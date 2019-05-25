
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
    \a pParent is the caller of this method.
*/
void QMLArrayAccess::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    if (m_pLeft != nullptr)
    {
        formatter.incIndentation();
        m_pLeft->toQML(stream, formatter, this);
        formatter.decIndentation();
    }

    for (QMLEntity* pEntity : m_vContents)
    {
        stream << " [ ";

        formatter.incIndentation();
        pEntity->toQML(stream, formatter, this);
        formatter.decIndentation();

        stream << " ] ";
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
