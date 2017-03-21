
// Qt
#include <QDebug>
#include <QDir>

// Application
#include "QMLPragma.h"

//-------------------------------------------------------------------------------------------------

QMLPragma::QMLPragma(const QPoint& pPosition, QMLItem* pStatement)
    : QMLItem(pPosition)
    , m_pStatement(pStatement)
{
}

//-------------------------------------------------------------------------------------------------

QMLPragma::~QMLPragma()
{
    if (m_pStatement != nullptr)
    {
        delete m_pStatement;
    }
}

//-------------------------------------------------------------------------------------------------

QMLItem* QMLPragma::statement() const
{
    return m_pStatement;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLItem*> QMLPragma::members()
{
    QMap<QString, QMLItem*> vReturnValue;

    vReturnValue["statement"] = m_pStatement;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLPragma::toQML(QTextStream& stream, QMLTreeContext* pContext, QMLItem* pParent, int iIdent)
{
    Q_UNUSED(pContext);
    Q_UNUSED(pParent);

    dumpIndentedNoNewLine(stream, iIdent, "pragma ");

    if (m_pStatement != nullptr)
    {
        m_pStatement->toQML(stream, pContext, this, iIdent + 1);
    }

    dumpNewLine(stream);
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLPragma::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLItem::toXMLNode(pContext, pParent);
    CXMLNode xStatement("Statement");

    if (m_pStatement != nullptr)
        xStatement.nodes() << m_pStatement->toXMLNode(pContext, this);

    xNode.nodes() << xStatement;

    return xNode;
}
