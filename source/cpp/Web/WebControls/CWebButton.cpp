
// Application
#include "CWebButton.h"

//-------------------------------------------------------------------------------------------------

#define EVENT_CLICKED	"clicked"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebButton
    \inmodule qt-plus
    \brief A button for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebButton.
*/
CWebControl* CWebButton::instantiator()
{
    return new CWebButton();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebButton with default parameters.
*/
CWebButton::CWebButton()
{
    setStyleClass("button1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebControl with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
    \a sParam specifies a user parameter. \br
*/
CWebButton::CWebButton(const QString& sName, const QString& sCaption, const QString& sParam)
    : CWebControl(sName, sCaption, sParam)
{
    setStyleClass("button1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebButton.
*/
CWebButton::~CWebButton()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this button to \a sHead and \a sBody.
*/
void CWebButton::addHTML(QString& sHead, QString& sBody)
{
    QString sFunction = addHTMLEvent(sHead, EVENT_CLICKED, m_sEventParameter);

    sBody.append(QString("<input type='button' id='%1' class='%2' style.visibility='%3' value='%4' onClick='%5'/>" HTML_NL)
                 .arg(getCodeName())
                 .arg(m_sStyleClass)
                 .arg(m_bVisible ? "visible" : "hidden")
                 .arg(m_sCaption)
                 .arg(sFunction)
                 );
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this button. The method currently does nothing. \br\br
    \a sControl, \a sEvent and \a sParam are unused
*/
void CWebButton::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);
    Q_UNUSED(sParam);
    Q_UNUSED(sEvent);
}

//-------------------------------------------------------------------------------------------------

/*!
    Serializes the button to a stream. \br\br
    \a stream specifies the stream to use for output. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers.
*/
void CWebButton::serialize(QDataStream& stream, CObjectTracker* pTracker) const
{
    CWebControl::serialize(stream, pTracker);
}

//-------------------------------------------------------------------------------------------------

/*!
    Deserializes the button from a stream. \br\br
    \a stream specifies the stream to use for input. \br
    \a pRootObject specifies the root control of the page being deserialized. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers.
*/
void CWebButton::deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject)
{
    CWebControl::deserialize(stream, pTracker, pRootObject);
}
