
// Application
#include "CWebListView.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebListView
    \inmodule qt-plus
    \brief A list view for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebListView.
*/
CWebControl* CWebListView::instantiator()
{
    return new CWebListView();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebListView with default parameters.
*/
CWebListView::CWebListView()
{
    setStyleClass("listview1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebListView with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebListView::CWebListView(const QString& sName, const QString& sCaption)
    : CWebModelControl(sName, sCaption)
{
    setStyleClass("listview1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebListView.
*/
CWebListView::~CWebListView()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this list view to \a sHead and \a sBody.
*/
void CWebListView::addHTML(QString& sHead, QString& sBody) const
{
    sBody.append(QString("<table id='%1' class='%2'><tr><td>Col1</td><td>Col2</td></tr></table>"HTML_NL)
                 .arg(getCodeName())
                 .arg(m_sStyleClass)
                 );
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this list view. \br\br
    \a sControl is unused. \br
    If \a sEvent is \c EVENT_CHANGED, the caption is set to \a sParam.
*/
void CWebListView::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);
}
