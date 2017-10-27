
// Application
#include "QMLComment.h"

//-------------------------------------------------------------------------------------------------

QMLComment::QMLComment(const QPoint& pPosition, const QString& sText, ECommentType eType)
    : QMLEntity(pPosition, sText)
    , m_eType(eType)
{
}

//-------------------------------------------------------------------------------------------------

QMLComment::~QMLComment()
{
}

//-------------------------------------------------------------------------------------------------

QMLComment::ECommentType QMLComment::type() const
{
    return m_eType;
}

//-------------------------------------------------------------------------------------------------

void QMLComment::writeMultiLineComment(QTextStream& stream, QMLFormatter& formatter, const QString& sText) const
{
    QStringList lLines = sText.split("\n");

    foreach (QString sLine, lLines)
    {
        formatter.writeNewLine(stream);
        stream << sLine.trimmed();
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Dumps the item to \a stream using \a iIdent for indentation. \br\br
    \a pContext is the context of this item. \br
    \a pParent is the caller of this method.
*/
void QMLComment::toQML(QTextStream& stream, QMLFormatter& formatter, const QMLEntity* pParent) const
{
    Q_UNUSED(pParent);

    switch (m_eType)
    {
        case ctSingleLineAtEnd:
            stream << "    // ";
            stream << m_vValue.toString();
            break;

        case ctSingleLine:
            formatter.writeDoubleNewLine(stream);
            stream << "// ";
            stream << m_vValue.toString();
            break;

        case ctMultiLine:
            formatter.writeDoubleNewLine(stream);

            stream << "/*";
            formatter.incIndentation();
            writeMultiLineComment(stream, formatter, m_vValue.toString());
            formatter.decIndentation();
            formatter.writeNewLine(stream);
            stream << "*/";
            break;

        case ctMultiLineDoc:
            formatter.writeDoubleNewLine(stream);

            stream << "/*!";
            formatter.incIndentation();
            writeMultiLineComment(stream, formatter, m_vValue.toString());
            formatter.decIndentation();
            formatter.writeNewLine(stream);
            stream << "*/";
            break;
    }
}

//-------------------------------------------------------------------------------------------------

CXMLNode QMLComment::toXMLNode(CXMLNodableContext* pContext, CXMLNodable* pParent)
{
    CXMLNode xNode = QMLEntity::toXMLNode(pContext, pParent);

    xNode.attributes()["Type"] = QString::number((int) m_eType);

    return xNode;
}
