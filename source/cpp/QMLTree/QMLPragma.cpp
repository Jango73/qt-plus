
// Qt
#include <QDir>

// Application
#include "QMLPragma.h"

//-------------------------------------------------------------------------------------------------

QMLPragma::QMLPragma(const QPoint& pPosition, QMLEntity* pStatement)
    : QMLEntity(pPosition)
    , m_pStatement(pStatement)
{
    if (m_pStatement != nullptr) m_pStatement->setParent(this);
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

QMLEntity* QMLPragma::statement() const
{
    return m_pStatement;
}

//-------------------------------------------------------------------------------------------------

QMap<QString, QMLEntity*> QMLPragma::members()
{
    QMap<QString, QMLEntity*> vReturnValue;

    vReturnValue["statement"] = m_pStatement;

    return vReturnValue;
}

//-------------------------------------------------------------------------------------------------

void QMLPragma::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    stream << "pragma ";

    if (m_pStatement != nullptr)
    {
        formatter.incIndentation();
        m_pStatement->toQML(stream, formatter, this);
        formatter.decIndentation();
    }

    stream << " ";
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLPragma::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);
    CXMLNode xStatement("Statement");

    if (m_pStatement != nullptr)
        xStatement.nodes() << m_pStatement->toXMLNode(pContext, this);

    xNode.nodes() << xStatement;

    return xNode;
}
