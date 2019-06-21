
// Application
#include "CWebTextEdit.h"

#define EVENT_CHANGED	"changed"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebTextEdit
    \inmodule qt-plus
    \brief A text area for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebTextEdit.
*/
CWebControl* CWebTextEdit::instantiator()
{
    return new CWebTextEdit();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebTextEdit with default parameters.
*/
CWebTextEdit::CWebTextEdit()
{
    setStyleClass("textbox1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebTextEdit with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebTextEdit::CWebTextEdit(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
    setStyleClass("textbox1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebTextEdit.
*/
CWebTextEdit::~CWebTextEdit()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this text area to \a sHead and \a sBody.
*/
void CWebTextEdit::addHTML(QString& sHead, QString& sBody)
{
    QString sClassDeclaration = m_sStyleClass.isEmpty() ? "" : QString("class='%1'").arg(m_sStyleClass);
    QString sFunction = addHTMLEventWithControlValue(sHead, EVENT_CHANGED);

    sBody.append(QString("<textarea id='%1' %2 onChange='%3'>" HTML_NL)
                 .arg(getCodeName())
                 .arg(sClassDeclaration)
                 .arg(sFunction)
                 );

    sBody.append(m_sCaption.toLatin1());
    sBody.append("</textarea>");
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this text area. \br\br
    \a sControl is unused. \br
    If \a sEvent is \c EVENT_CHANGED, the caption is set to \a sParam.
*/
void CWebTextEdit::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);

    if (sEvent == EVENT_CHANGED)
    {
        m_sCaption = sParam;
    }
}
