
// Application
#include "CWebFileInput.h"

//-------------------------------------------------------------------------------------------------

#define EVENT_CHANGED	"changed"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebFileInput
    \inmodule qt-plus
    \brief A file input for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a CWebFileInput.
*/
CWebControl* CWebFileInput::instantiator()
{
    return new CWebFileInput();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebFileInput with default parameters.
*/
CWebFileInput::CWebFileInput()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebFileInput with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebFileInput::CWebFileInput(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebFileInput.
*/
CWebFileInput::~CWebFileInput()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this file input to \a sHead and \a sBody.
*/
void CWebFileInput::addHTML(QString& sHead, QString& sBody)
{
    QString sFunction = addCustomHTMLEvent(
                sHead,
                EVENT_CHANGED,
                QString("httpUpload('%1');").arg(getCodeName())
                );

    QString sClassDeclaration = m_sStyleClass.isEmpty() ? "" : QString("class='%1'").arg(m_sStyleClass);
    QString sStyleDeclaration = m_sStyle.isEmpty() ? "" : QString("style='%1'").arg(m_sStyle);

    sBody.append(QString("<input type='file' id='%1' %2 %3 style.visibility='%4' onChange='%5()'/>" HTML_NL)
                 .arg(getCodeName())
                 .arg(sClassDeclaration)
                 .arg(sStyleDeclaration)
                 .arg(m_bVisible ? "visible" : "hidden")
                 .arg(sFunction)
                 );
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this file input. The method currently does nothing. \br\br
    \a sControl, \a sEvent and \a sParam are unused.
*/
void CWebFileInput::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);
    Q_UNUSED(sParam);
    Q_UNUSED(sEvent);
}
