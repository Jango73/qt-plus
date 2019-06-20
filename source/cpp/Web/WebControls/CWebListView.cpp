
// Application
#include "CWebListView.h"
#include "CWebDiv.h"
#include "CWebButton.h"
#include "CWebLabel.h"
#include "CWebTextBox.h"

//-------------------------------------------------------------------------------------------------

#define CONTROLNAME_FIRST_PAGE          "FirstPage"
#define CONTROLNAME_PREVIOUS_PAGE       "PreviousPage"
#define CONTROLNAME_NEXT_PAGE           "NextPage"
#define CONTROLNAME_LAST_PAGE           "LastPage"
#define CONTROLNAME_CURRENT_PAGE_INDEX  "CurrentPageIndex"
#define CONTROLNAME_TOTAL_PAGE_COUNT    "TotalPageCount"
#define CONTROLNAME_CONTENT             "Content"

#define EVENT_UPDATE                    "update"

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
    : m_iItemsPerPage(10)
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
    , m_iItemsPerPage(10)
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

    pControlDiv->addControl(new CWebLabel("", "Page"))
            ->setStyleClass("label1");

    CWebControl* pCurrentPageLabel = pControlDiv->addControl(new CWebTextBox(CONTROLNAME_CURRENT_PAGE_INDEX, ""))
            ->setReadOnly(true)
            ->setStyleClass("label1");

    pControlDiv->addControl(new CWebLabel("", "/"))
            ->setStyle("width:20px;");

    CWebControl* pTotalPageLabel = pControlDiv->addControl(new CWebTextBox(CONTROLNAME_TOTAL_PAGE_COUNT, ""))
            ->setReadOnly(true)
            ->setStyleClass("label1");

    // Set paging data
    int iTotalCount = m_pModelProvider.get()->modelItemCount();
    int iTotalPages = iTotalCount % m_iItemsPerPage == 0 ? iTotalCount / m_iItemsPerPage : (iTotalCount / m_iItemsPerPage) + 1;
    pCurrentPageLabel->setCaption(QString::number(m_iCurrentPage + 1));
    pTotalPageLabel->setCaption(QString::number(iTotalPages));

    setModel();
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
    Creates the control according to the model provided by the given IJSONModelProvider.
*/
void CWebListView::setModel()
{
    CXMLNode xModel = m_pModelProvider.get()->modelItems(m_iCurrentPage * m_iItemsPerPage, m_iItemsPerPage);

    CWebControl* pContent = findControlByName(CONTROLNAME_CONTENT);

    if (pContent != nullptr)
        deleteControl(pContent);

    CWebControl* pContentDiv = addControl(new CWebDiv(CONTROLNAME_CONTENT, ""));

    CXMLNode xHeader = xModel.getNodeByTagName("header");
    QVector<CXMLNode> xProperties = xHeader.getNodesByTagName("property");

    QStringList lPropertyNames;
    QStringList lPropertyTypes;

    for (CXMLNode xProperty : xProperties)
    {
        QString sType = xProperty.attributes()["type"];
        QString sText = xProperty.attributes()["name"];

        lPropertyTypes << sType;
        lPropertyNames << sText;
    }

    {
        CWebControl* pLineDiv = pContentDiv->addControl(new CWebDiv("", ""))->setStyleClass("listview-header-line");

        for (QString sProperty : lPropertyNames)
        {
            pLineDiv->addControl(new CWebLabel("", sProperty));
        }
    }

    CXMLNode xData = xModel.getNodeByTagName("data");
    QVector<CXMLNode> xItems = xData.getNodesByTagName("item");

    for (CXMLNode xItem : xItems)
    {
        CWebControl* pLineDiv = pContentDiv->addControl(new CWebDiv("", ""))->setStyleClass("listview-data-line");

        for (int index = 0; index < lPropertyNames.count(); index++)
        {
            QString sType = index < lPropertyTypes.count() ? lPropertyTypes[index] : "string";
            QString sText = xItem.attributes()[lPropertyNames[index]];

            if (sType == "string")
            {
                pLineDiv->addControl(new CWebLabel("", sText));
            }
            else if (sType == "button")
            {
                pLineDiv->addControl(new CWebButton("", sText));
            }
        }
    }
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
    if (m_pModelProvider.get() != nullptr)
    {
        int iTotalCount = m_pModelProvider.get()->modelItemCount();
        int iTotalPages = iTotalCount % m_iItemsPerPage == 0 ? iTotalCount / m_iItemsPerPage : (iTotalCount / m_iItemsPerPage) + 1;

        if (pControl->getName() == CONTROLNAME_FIRST_PAGE)
        {
            m_iCurrentPage = 0;
        }
        else if (pControl->getName() == CONTROLNAME_PREVIOUS_PAGE)
        {
            if (m_iCurrentPage > 0)
            {
                m_iCurrentPage--;
            }
        }
        else if (pControl->getName() == CONTROLNAME_NEXT_PAGE)
        {
            if (m_iCurrentPage < iTotalPages - 1)
            {
                m_iCurrentPage++;
            }
        }
        else if (pControl->getName() == CONTROLNAME_LAST_PAGE)
        {
            m_iCurrentPage = iTotalPages - 1;
        }

        CWebTextBox* pCurrentPageLabel = dynamic_cast<CWebTextBox*>(findControlByName(CONTROLNAME_CURRENT_PAGE_INDEX));
        CWebTextBox* pTotalPageLabel = dynamic_cast<CWebTextBox*>(findControlByName(CONTROLNAME_TOTAL_PAGE_COUNT));

        if (pCurrentPageLabel != nullptr)
            pCurrentPageLabel->setCaption(QString::number(m_iCurrentPage + 1));

        if (pTotalPageLabel != nullptr)
            pTotalPageLabel->setCaption(QString::number(iTotalPages));

        setModel();
    }
}

//-------------------------------------------------------------------------------------------------

void CWebListView::serialize(QDataStream& stream, CObjectTracker* pTracker) const
{
    CWebModelControl::serialize(stream, pTracker);

    stream << m_sUpdateFunction;
    stream << m_iItemsPerPage;
    stream << m_iCurrentPage;
}

//-------------------------------------------------------------------------------------------------

void CWebListView::deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootControl)
{
    CWebModelControl::deserialize(stream, pTracker, pRootControl);

    stream >> m_sUpdateFunction;
    stream >> m_iItemsPerPage;
    stream >> m_iCurrentPage;
}
