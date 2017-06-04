
// Application
#include "CWebListView.h"
#include "CWebDiv.h"
#include "CWebButton.h"

//-------------------------------------------------------------------------------------------------

#define CONTROLNAME_FIRST_PAGE      "FirstPage"
#define CONTROLNAME_PREVIOUS_PAGE   "PreviousPage"
#define CONTROLNAME_NEXT_PAGE       "NextPage"
#define CONTROLNAME_LAST_PAGE       "LastPage"

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
    : m_iUsersPerPage(10)
    , m_iCurrentPage(0)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebListView with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
    \a pModelProvider is the model provider.
*/
CWebListView::CWebListView(const QString& sName, const QString& sCaption, IJSONModelProvider* pModelProvider)
    : CWebModelControl(sName, sCaption, pModelProvider)
    , m_iUsersPerPage(10)
    , m_iCurrentPage(0)
{
    CWebControl* pControlDiv = addControl(new CWebDiv("Controls", ""));

    pControlDiv->addControl(new CWebButton(CONTROLNAME_FIRST_PAGE, "|<"))
            ->addObserver(this)
            ->setStyleClass("button1");

    pControlDiv->addControl(new CWebButton(CONTROLNAME_PREVIOUS_PAGE, "<<"))
            ->addObserver(this)
            ->setStyleClass("button1");

    pControlDiv->addControl(new CWebButton(CONTROLNAME_NEXT_PAGE, ">>"))
            ->addObserver(this)
            ->setStyleClass("button1");

    pControlDiv->addControl(new CWebButton(CONTROLNAME_LAST_PAGE, ">|"))
            ->addObserver(this)
            ->setStyleClass("button1");

    CWebControl* pContentDiv = addControl(new CWebDiv("Content", ""));
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
    Handles events from child controls. \br\br
    \a pControl is the control which triggered the event. \br
    \a sEvent is the event name. \br
    \a sParam is the event parameter.
*/
void CWebListView::controlEvent(CWebControl* pControl, QString sEvent, QString sParam)
{
    if (pControl->getName() == CONTROLNAME_FIRST_PAGE)
    {
    }
    else if (pControl->getName() == CONTROLNAME_PREVIOUS_PAGE)
    {
    }
    else if (pControl->getName() == CONTROLNAME_NEXT_PAGE)
    {
    }
    else if (pControl->getName() == CONTROLNAME_LAST_PAGE)
    {
    }
}

//-------------------------------------------------------------------------------------------------

void CWebListView::serialize(QDataStream& stream, CObjectTracker* pTracker) const
{
    CWebModelControl::serialize(stream, pTracker);

    stream << m_iUsersPerPage;
    stream << m_iCurrentPage;
}

//-------------------------------------------------------------------------------------------------

void CWebListView::deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootControl)
{
    CWebModelControl::deserialize(stream, pTracker, pRootControl);

    stream >> m_iUsersPerPage;
    stream >> m_iCurrentPage;
}
