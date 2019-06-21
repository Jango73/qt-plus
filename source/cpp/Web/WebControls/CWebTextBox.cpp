
// Application
#include "CWebTextBox.h"

#define EVENT_CHANGED	"changed"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebTextBox
    \inmodule qt-plus
    \brief A text box for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebTextBox.
*/
CWebControl* CWebTextBox::instantiator()
{
    return new CWebTextBox();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebTextBox with default parameters.
*/
CWebTextBox::CWebTextBox()
{
    setStyleClass("textbox1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebTextBox with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebTextBox::CWebTextBox(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
    setStyleClass("textbox1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebTextBox.
*/
CWebTextBox::~CWebTextBox()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this text box to \a sHead and \a sBody.
*/
void CWebTextBox::addHTML(QString& sHead, QString& sBody)
{
    QString sClassDeclaration = m_sStyleClass.isEmpty() ? "" : QString("class='%1'").arg(m_sStyleClass);
    QString sFunction = addHTMLEventWithControlValue(sHead, EVENT_CHANGED);

    sBody.append(QString("<input type='text' id='%1' %2 value='%3' onChange='%4' %5/>" HTML_NL)
                 .arg(getCodeName())
                 .arg(sClassDeclaration)
                 .arg(m_sCaption)
                 .arg(sFunction)
                 .arg(m_bReadOnly ? "readonly" : "")
                 );
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this text box. \br\br
    \a sControl is unused. \br
    If \a sEvent is \c EVENT_CHANGED, the caption is set to \a sParam.
*/
void CWebTextBox::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);

    if (sEvent == EVENT_CHANGED)
    {
        m_sCaption = sParam;
    }
}
