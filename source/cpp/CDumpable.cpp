
// Application
#include "CDumpable.h"

//-------------------------------------------------------------------------------------------------

bool CDumpable::m_bJavaStyle = false;

//-------------------------------------------------------------------------------------------------

CDumpable::CDumpable()
{
}

//-------------------------------------------------------------------------------------------------

CDumpable::~CDumpable()
{
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dump(QTextStream& stream, int iIdent)
{
    Q_UNUSED(stream)
    Q_UNUSED(iIdent)
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpOpenBlock(QTextStream& stream, int iIdent)
{
    if (m_bJavaStyle)
    {
        dumpNoIndentNoNewLine(stream, " {");
        dumpNewLine(stream);
    }
    else
    {
        dumpNewLine(stream);
        dumpIndented(stream, iIdent, "{");
    }
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpCloseBlock(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, "}");
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpOpenArray(QTextStream& stream, int iIdent)
{
    if (m_bJavaStyle)
    {
        dumpNoIndentNoNewLine(stream, " [");
        dumpNewLine(stream);
    }
    else
    {
        dumpNewLine(stream);
        dumpIndented(stream, iIdent, "[");
    }
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpCloseArray(QTextStream& stream, int iIdent)
{
    dumpIndented(stream, iIdent, "]");
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpNoIndentNoNewLine(QTextStream& stream, QString sText)
{
    stream << sText;
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpNewLine(QTextStream& stream)
{
    stream << "\r\n";
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpIndentedNoNewLine(QTextStream& stream, int iIdent, QString sText)
{
    for (int i = 0; i < iIdent * 4; i++)
    {
        stream << " ";
    }

    stream << sText;
}

//-------------------------------------------------------------------------------------------------

void CDumpable::dumpIndented(QTextStream& stream, int iIdent, QString sText)
{
    dumpIndentedNoNewLine(stream, iIdent, sText);
    dumpNewLine(stream);
}
