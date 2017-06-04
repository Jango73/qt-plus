
// Application
#include "CWebModelControl.h"

#define EVENT_CHANGED	"changed"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebModelControl
    \inmodule qt-plus
    \brief A model control for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebModelControl.
*/
CWebControl* CWebModelControl::instantiator()
{
    return new CWebModelControl();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebModelControl with default parameters.
*/
CWebModelControl::CWebModelControl()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebModelControl with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebModelControl::CWebModelControl(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebModelControl.
*/
CWebModelControl::~CWebModelControl()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this text box to \a sHead and \a sBody.
*/
void CWebModelControl::addHTML(QString& sHead, QString& sBody) const
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this text box. \br\br
    \a sControl is unused. \br
    If \a sEvent is \c EVENT_CHANGED, the caption is set to \a sParam.
*/
void CWebModelControl::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);
    Q_UNUSED(sEvent);
    Q_UNUSED(sParam);
}
