
// Application
#include "CHTMLGenerator.h"

//-------------------------------------------------------------------------------------------------

static QString boolToString(bool bValue)
{
    return bValue ? "True" : "False";
}

//-------------------------------------------------------------------------------------------------

CHTMLGenerator::CHTMLGenerator(int iPort) : CHTTPServer(iPort)
{
}

//-------------------------------------------------------------------------------------------------

CHTMLGenerator::~CHTMLGenerator()
{
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::beginSection(QString sText, QString sAdditionalAttr)
{
    m_sText.append(QString("<div %1>%2"HTML_NL).arg(sAdditionalAttr).arg(sText));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::endSection()
{
    m_sText.append(QString("</div>"HTML_NL));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addSubSection(QString sText)
{
    m_sText.append(QString("%1<br><br>"HTML_NL).arg(sText));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::beginTable()
{
    m_sText.append("<table>"HTML_NL);
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::endTable()
{
    m_sText.append("</table>"HTML_NL);
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::beginRow()
{
    m_sText.append(QString("<tr>"));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::endRow()
{
    m_sText.append(QString("</tr>"));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::beginColumn()
{
    m_sText.append(QString("<td>"));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::endColumn()
{
    m_sText.append(QString("</td>"));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addKeyValue(QString sKey, QString sValue)
{
    m_sText.append(
                QString("<tr><td>%1</td><td>%2</td></tr>"HTML_NL)
                .arg(sKey)
                .arg(sValue)
                );
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addKeyLink(QString sKey, QString sValue, QString sLink)
{
    m_sText.append(
                QString("<tr><td>%1</td><td><a href='http://%2'>%3</a></td></tr>"HTML_NL)
                .arg(sKey)
                .arg(sLink)
                .arg(sValue)
                );
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addKeyChoice(QString sKey, QString sID, QStringList lValues, QString sOnChange, QString sSelected)
{
    m_sText.append(QString("<tr><td>%1</td><td>").arg(sKey));

    m_sText.append(
                QString("<select id='%1' onChange='%2' style='width:200px;'>")
                .arg(sID)
                .arg(sOnChange)
                );

    foreach (QString sValue, lValues)
    {
        m_sText.append(QString("<option %1>%2</option>")
                       .arg(sValue == sSelected? "selected" : "")
                       .arg(sValue)
                       );
    }

    m_sText.append(QString("</select>"));
    m_sText.append(QString("</td></tr>"HTML_NL));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addTableText(QString sKey, QString sID, QString sText)
{
    m_sText.append(QString("<tr><td>%1</td><td>").arg(sKey));
    m_sText.append(QString("<input type='text' id='%1' style='width:240px;'>%2</input>").arg(sID).arg(sText));
    m_sText.append(QString("</td></tr>"HTML_NL));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addTableButton(QString sDesc, QString sText, QString sOnClick)
{
    m_sText.append(QString("<tr><td>%1</td><td>").arg(sDesc));
    m_sText.append(QString("<input type='button' class='button1' value='%1' onClick='%2'/>").arg(sText).arg(sOnClick));
    m_sText.append(QString("</td></tr>"HTML_NL));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addText(QString sText)
{
    m_sText.append(sText);
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addButton(QString sText, QString sOnClick)
{
    m_sText.append(QString("<input type='button' class='button1' value='%1' onClick='%2'/>"HTML_NL).arg(sText).arg(sOnClick));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addTextbox(QString sID, QString sText, int iWidth)
{
    m_sText.append(QString("<input type='text' id='%1' value='%3' style='width:%2px;'></input>").arg(sID).arg(iWidth).arg(sText));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addTableTextEdit(QString sID, QString sText, QString sOnKeyPress, int iWidth)
{
    m_sText.append(QString("<tr><td></td><td>"));
    m_sText.append(QString("<textarea id='%1' onkeypress='%2' style='width:%3px;height:300px;'>%4</textarea>").arg(sID).arg(sOnKeyPress).arg(iWidth).arg(sText));
    m_sText.append(QString("</td></tr>"HTML_NL));
}

//-------------------------------------------------------------------------------------------------

void CHTMLGenerator::addCriticalBoolValue(QString sKey, bool bValue)
{
    if (bValue)
    {
        m_sText.append(QString("<tr><td>%1</td><td>%2</td></tr>"HTML_NL).arg(sKey).arg(boolToString(bValue)));
    }
    else
    {
        m_sText.append(QString("<tr><td>%1</td><td style='background-color:red;color:white;'>%2</td></tr>"HTML_NL).arg(sKey).arg(boolToString(bValue)));
    }
}
