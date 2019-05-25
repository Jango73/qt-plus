
// Qt
#include <QDebug>
#include <QMetaEnum>

// Application
#include "QMLFormatter.h"

//-------------------------------------------------------------------------------------------------

QMLFormatter::QMLFormatter()
    : m_iIndentation(0)
{
}

//-------------------------------------------------------------------------------------------------

QMLFormatter::~QMLFormatter()
{
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::incIndentation()
{
    m_iIndentation++;
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::decIndentation()
{
    m_iIndentation--;

    if (m_iIndentation < 0)
        m_iIndentation = 0;
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::writeNewLine(QTextStream& stream)
{
    stream << "\r\n";

    for (int i = 0; i < m_iIndentation * 4; i++)
    {
        stream << " ";
    }
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::writeDoubleNewLine(QTextStream& stream)
{
    stream << "\r\n";
    writeNewLine(stream);
}

//-------------------------------------------------------------------------------------------------

void QMLFormatter::processFragment(QTextStream& stream, EQMLFormatterFragment fragment)
{
    QMetaEnum fragmentEnum = QMetaEnum::fromType<EQMLFormatterFragment>();
    QString sFragment = QString(fragmentEnum.valueToKey(fragment)).remove("qff");

    QVector<CXMLNode> vFragments = m_xGrammar.getNodesByTagName(FORMATTER_TOKEN_FRAGMENT);

    for (CXMLNode xFragment : vFragments)
    {
        QString sNames = processMacros(xFragment.attributes()[FORMATTER_TOKEN_NAMES]);
        QStringList lNames = sNames.split(",");

        if (lNames.contains(sFragment))
        {
            QVector<CXMLNode> vActions = xFragment.getNodesByTagName(FORMATTER_TOKEN_ACTION);

            for (CXMLNode xAction : vActions)
            {
                QString sType = processMacros(xAction.attributes()[FORMATTER_TOKEN_TYPE]);

                if (sType == FORMATTER_ACTION_NEW_LINE)
                {
                    writeNewLine(stream);
                }
                else if (sType == FORMATTER_ACTION_DOUBLE_NEW_LINE)
                {
                    writeDoubleNewLine(stream);
                }
                else if (sType == FORMATTER_ACTION_INDENTATION_INC)
                {
                    incIndentation();
                }
                else if (sType == FORMATTER_ACTION_INDENTATION_DEC)
                {
                    decIndentation();
                }
            }
        }
    }
}
