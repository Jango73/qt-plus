
// Qt
#include <QDebug>

// Application
#include "QMLComment.h"
#include "QMLTreeContext.h"

//-------------------------------------------------------------------------------------------------

QMLComment::QMLComment(const QPoint& pPosition, const QString& sText, ECommentType eType)
    : QMLEntity(pPosition, sText)
    , m_pAttachedTo(nullptr)
    , m_eType(eType)
    , m_bDeadCode(false)
{
    QMLTreeContext context;

    checkForCode();
}

//-------------------------------------------------------------------------------------------------

QMLComment::~QMLComment()
{
}

//-------------------------------------------------------------------------------------------------

void QMLComment::setAttachedTo(QMLEntity* pAttachedTo)
{
    m_pAttachedTo = pAttachedTo;
}

//-------------------------------------------------------------------------------------------------

QMLEntity* QMLComment::attachedTo() const
{
    return m_pAttachedTo;
}

//-------------------------------------------------------------------------------------------------

QMLComment::ECommentType QMLComment::type() const
{
    return m_eType;
}

//-------------------------------------------------------------------------------------------------

bool QMLComment::deadCode() const
{
    return m_bDeadCode;
}

//-------------------------------------------------------------------------------------------------

void QMLComment::writeMultiLineComment(QTextStream& stream, QMLFormatter& formatter, const QString& sText) const
{
    QStringList lLines = sText.split("\n");

    for (QString sLine : lLines)
    {
        formatter.writeNewLine(stream);
        stream << sLine.trimmed();
    }
}

//-------------------------------------------------------------------------------------------------

void QMLComment::checkForCode()
{
    int iScore = 0;

    QString sToken = m_vValue.toString().trimmed();

    for (QString sKeyword : QMLTreeContext::operators())
    {
        if (sToken.contains(sKeyword))
        {
            iScore++;
        }
    }

    if (iScore > 4)
    {
        m_bDeadCode = true;
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
        case ctSingleLine:
        {
            QMLComment* pPreviousComment = dynamic_cast<QMLComment*>(previousSibling());

            if (pPreviousComment != nullptr && pPreviousComment->type() == ctSingleLine)
                formatter.writeNewLine(stream);
            else
                formatter.writeDoubleNewLine(stream);

            stream << "// ";
            stream << m_vValue.toString();
            break;
        }

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

    xNode.attributes()["Type"] = QString::number(int(m_eType));

    return xNode;
}
