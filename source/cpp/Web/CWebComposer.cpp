
// Application
#include "CHTTPServer.h"
#include "CWebComposer.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebComposer
    \inmodule qt-plus
    \brief A class that renders HTML components.
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebComposer with default parameters.
*/
CWebComposer::CWebComposer()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebComposer.
*/
CWebComposer::~CWebComposer()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list of required JS files.
*/
const QVector<QString>& CWebComposer::getJSFiles() const
{
    return m_vJSFiles;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list of required CSS files.
*/
const QVector<QString>& CWebComposer::getCSSFiles() const
{
    return m_vCSSFiles;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list of ready lines.
*/
const QVector<QString>& CWebComposer::getReadyScriptLines() const
{
    return m_vReadyScriptLines;
}

//-------------------------------------------------------------------------------------------------

/*!
    Clears all lists in the object.
*/
void CWebComposer::reset()
{
    m_vJSFiles.clear();
    m_vCSSFiles.clear();
    m_vReadyScriptLines.clear();
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a javascript file name (\a sFileName) to the list.
*/
void CWebComposer::addJSFile(QString sFileName)
{
    if (m_vJSFiles.contains(sFileName) == false)
    {
        m_vJSFiles.append(sFileName);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a css file name (\a sFileName) to the list.
*/
void CWebComposer::addCSSFile(QString sFileName)
{
    if (m_vCSSFiles.contains(sFileName) == false)
    {
        m_vCSSFiles.append(sFileName);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the javascript include statement for \a sFileName in \a sHead.
*/
void CWebComposer::addJSFileStatement(QString& sHead, QString sFileName)
{
    sHead.append(
                QString("<script type='text/javascript' src='%1'></script>" HTML_NL)
                .arg(sFileName)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the css include statement for \a sFileName in \a sHead.
*/
void CWebComposer::addCSSFileStatement(QString& sHead, QString sFileName)
{
    sHead.append(
                QString("<link rel='stylesheet' href='%1' type='text/css'/>" HTML_NL)
                .arg(sFileName)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the javascript snippet in \a sScript, which will be executed when HTML document has loaded.
*/
void CWebComposer::addReadyScript(QString sScript)
{
    m_vReadyScriptLines.append(sScript);
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the raw text \a sText to the HTML output in \a sPage.
*/
void CWebComposer::addText(QString& sPage, QString sText)
{
    sPage.append(sText);
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the '<br>' tag to the HTML output in \a sPage.
*/
void CWebComposer::addNewLine(QString& sPage)
{
    sPage.append("<br>");
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a div begin tag to the HTML output in \a sPage, using \a sID as control ID and \a sClass as CSS style class.
*/
void CWebComposer::beginDiv(QString& sPage, QString sID, QString sClass)
{
    QString sClassDeclaration = sClass.isEmpty() ? "" : QString("class='%1'").arg(sClass);

    sPage.append(
                QString("<div id='%1' %2>")
                .arg(sID)
                .arg(sClassDeclaration)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a div end tag to the HTML output in \a sPage.
*/
void CWebComposer::endDiv(QString& sPage)
{
    sPage.append(QString("</div>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a table begin tag to the HTML output in \a sPage, using \a sID as control ID.
*/
void CWebComposer::beginTable(QString& sPage, QString sID)
{
    sPage.append(QString("<table id='%1'>").arg(sID));
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a table end tag to the HTML output in \a sPage.
*/
void CWebComposer::endTable(QString& sPage)
{
    sPage.append(QString("</table>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage.
*/
void CWebComposer::beginTableRow(QString& sPage)
{
    sPage.append(QString("<tr>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage.
*/
void CWebComposer::endTableRow(QString& sPage)
{
    sPage.append(QString("</tr>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage.
*/
void CWebComposer::beginTableCell(QString& sPage)
{
    sPage.append(QString("<td>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage.
*/
void CWebComposer::endTableCell(QString& sPage)
{
    sPage.append(QString("</td>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage. \br
    \a sValue.
*/
void CWebComposer::addTableCell(QString& sPage, QString sValue)
{
    sPage.append(QString("<td>%1</td>").arg(sValue));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage. \br
    \a sText. \br
    \a sLink.
*/
void CWebComposer::addLink(QString& sPage, QString sText, QString sLink)
{
    sPage.append(
                QString("<a href='http://%1'>%2</a>")
                .arg(sLink)
                .arg(sText)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage. \br
    \a sID. \br
    \a lValues. \br
    \a sSelected. \br
    \a sOnChanged.
*/
void CWebComposer::addSelector(QString& sPage, QString sID, QStringList lValues, QString sSelected, QString sOnChanged)
{
    sPage.append(QString("<select id='%1' onChange='%2(value)'>")
                 .arg(sID)
                 .arg(sOnChanged)
                 );

    for (QString sValue : lValues)
    {
        sPage.append(QString("<option %1>%2</option>")
                     .arg(sValue == sSelected? "selected" : "")
                     .arg(sValue)
                     );
    }

    sPage.append(QString("</select>"));
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage. \br
    \a sID. \br
    \a sText. \br
    \a sSize. \br
    \a sOnClicked.
    \a sArgument.
*/
void CWebComposer::addButton(QString& sPage, QString sID, QString sText, QSize sSize, QString sOnClicked, QString sArgument)
{
    if (sSize.width() == 0 && sSize.height() == 0)
    {
        sSize.setWidth(80);
        sSize.setHeight(25);
    }

    if (sOnClicked.isEmpty())
    {
        sPage.append(QString("<input type='button' id='%1' value='%2'/>")
                     .arg(sID)
                     .arg(sText)
                     );
    }
    else
    {
        sPage.append(QString("<input type='button' id='%1' value='%2' onClick='%3(\"%4\")'/>")
                     .arg(sID)
                     .arg(sText)
                     .arg(sOnClicked)
                     .arg(sArgument)
                     );
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sPage. \br
    \a sID. \br
    \a sText. \br
    \a sSize. \br
    \a sPlaceHolder.
    \a sOnChanged.
*/
void CWebComposer::addTextInput(QString& sPage, QString sID, QString sText, QSize sSize, QString sPlaceHolder, QString sOnChanged)
{
    Q_UNUSED(sPlaceHolder);

    if (sSize.width() == 0 && sSize.height() == 0)
    {
        sSize.setWidth(100);
        sSize.setHeight(25);
    }

    if (sOnChanged.isEmpty())
    {
        sPage.append(QString("<input type='text' id='%1' value='%2'/>")
                     .arg(sID)
                     .arg(sText)
                     );
    }
    else
    {
        sPage.append(QString("<input type='text' id='%1' value='%2' onChange='%3()'/>")
                     .arg(sID)
                     .arg(sText)
                     .arg(sOnChanged)
                     );
    }
}
