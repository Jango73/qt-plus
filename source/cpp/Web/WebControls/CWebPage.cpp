
// Qt
#include <QByteArray>

// Application
#include "../CDynamicHTTPServer.h"
#include "CWebFactory.h"
#include "CWebPage.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebPage
    \inmodule qt-plus
    \brief The base class of a web page.
    \section1 How it works
    The CWebPage class is derived from CWebControl. Apart from extending CWebControl, it also provides mechanims that enables a developer to create and handle web pages and controls in his/her C++ code. \br\br
    Here is a summary of the lifetime of a web page:
    \list
    \li A request arrives in the CHTTPServer class.
    \li The CHTTPServer calls its own getContent() method.
    \li The CDynamicHTTPServer, which derives from CHTTPServer, calls its own getPage() method.
    \li The class that subclasses CDynamicHTTPServer, in its getPage() method, returns a new instance of a subclass of CWebPage.
    \li The new page, in its constructor, creates its controls using objects that inherits CWebControl.
    \li The CDynamicHTTPServer calls the page's getContent() method.
    \list
    \li The page orders all its child controls to render as HTML.
    \li It then serializes itself and places the result in the 'viewstate' property of the DOM document, via Javascript.
    \endlist
    \li The CDynamicHTTPServer gives back control to the CHTTPServer.
    \li The CHTTPServer sends the generated content to the client.
    \endlist
    ... An event occurs in the browser, then
    \list
    \li The client emits an event via a XMLHTTPRequest object, in the form "action='event'&control='CTRL_nnn'&event='clicked'".
    \li The CHTTPServer calls its getContent() method.
    \li The CDynamicHTTPServer decides to process the request as an event because of the 'action' argument. Instead of creating a new page, it uses the 'viewstate' argument and deserializes the original page.
    \li The CDynamicHTTPServer calls the handleEvent() method of the concerned control.
    \li Javascript code is generated in order to apply any control state change in client's browser.
    \li The CDynamicHTTPServer serializes the page and calls its getPropertyChanges() method. This returns javascript that will be executed client-side.
    \li The result is sent back to the CHTTPServer, and to the client brower.
    \endlist
    \section1 What you should do when subclassing CWebPage
    The page can be filled with controls in its constructor, like in the following example.
    \code
    CHomePage::CHomePage(const QString& sName) : CWebPage(sName)
    {
        CWebControl* pHeaderDiv = addControl(new CWebDiv("Header", ""))->setStyleClass("header");
        pHeaderDiv->addControl(new CWebButton("HomeButton", "Home"))->addObserver(this)->setStyleClass("standardButton1);
    }
    \endcode
    If the page has events to handle (like most pages), do this in controlEvent() like so:
    \code
    void CHomePage::controlEvent(CWebControl* pControl, QString sEvent, QString sParam)
    {
        Q_UNUSED(sParam);

        if (pControl->getName() == "HomeButton" && sEvent == "clicked")
        {
            locationModified("/");
        }
    }
    \endcode
    If the page contains special objects that should be saved with it, you have to override the serialization methods, like so:
    \code
    void CHomePage::serialize(QDataStream& stream, CObjectTracker* pTracker) const
    {
        CWebPage::serialize(stream, pTracker);

        stream << someData;
    }

    void CHomePage::deserialize(QDataStream& stream, CObjectTracker *pTracker, QObject* pRootControl)
    {
        CWebPage::deserialize(stream, pTracker, pRootControl);

        stream >> someData;
    }
    \endcode
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebPage.
*/
CWebControl* CWebPage::instantiator()
{
    return new CWebPage();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebPage with default parameters.
*/
CWebPage::CWebPage()
    : m_bDeserialized(false)
{
    m_sPropertyChanges.append(QString("var newElement;" HTML_NL));
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebPage which will be named \a sName.
*/
CWebPage::CWebPage(const QString& sName)
    : CWebControl(sName, "")
    , m_bDeserialized(false)
{
    m_sPropertyChanges.append(QString("var newElement;" HTML_NL));
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebPage.
*/
CWebPage::~CWebPage()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns javascript that reflects all changes made to the page and its controls. \br\br
    It is used to update the page client-side.
*/
QString CWebPage::getPropertyChanges()
{
    return m_sPropertyChanges;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the page was constructed by deserialization
*/
bool CWebPage::isDeserialized() const
{
    return m_bDeserialized;
}

//-------------------------------------------------------------------------------------------------

/*!
    This method returns a HTML rendering of the page and its child controls. \br\br
    \a pServer is the server requesting the contents. \br
    \a sHead is filled with the HTML page head statements. \br
    \a sBody is filled with the HTML page body statements. \br
    \a tContext and \a xmlResponse are unused. \br
*/
void CWebPage::getContent(CDynamicHTTPServer* pServer, const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse)
{
    Q_UNUSED(tContext);
    Q_UNUSED(xmlResponse);

    sHead += QString("<meta charset=\"UTF-8\">" HTML_NL);

    for (QString sFileName : pServer->composer()->getCSSFiles())
    {
        pServer->composer()->addCSSFileStatement(sHead, sFileName);
    }

    for (QString sFileName : pServer->composer()->getJSFiles())
    {
        pServer->composer()->addJSFileStatement(sHead, sFileName);
    }

    addHTML(sHead, sBody);

    sHead += QString(
                "<script type='text/javascript' language='javascript'>" HTML_NL
                "window.onload = function()" HTML_NL
                "{" HTML_NL
                );

    sHead += m_sPropertyChanges;

    sHead += "document.viewstate='" + getViewState(pServer) + "';" HTML_NL;

    sHead += QString(
                "};" HTML_NL
                "</script>" HTML_NL
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    This can be called to create a redirection to the URL in \a sPropertyValue.
*/
void CWebPage::locationModified(const QString& sPropertyValue)
{
    m_sPropertyChanges.append(
                QString(
                    "document.location = '%1';" HTML_NL
                    )
                .arg(sPropertyValue)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    This adds a javascript line that will set \a sPropertyName of control \a sID to value \a sPropertyValue.
*/
void CWebPage::propertyModified(const QString& sID, const QString& sPropertyName, const QString& sPropertyValue)
{
    m_sPropertyChanges.append(
                QString(
                    "document.getElementById('%1').%2='%3';" HTML_NL
                    )
                .arg(sID)
                .arg(sPropertyName)
                .arg(sPropertyValue)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    This adds javascript code that will add the \a pChildControl control to the control \a sID client-side. \br\br
    It uses the htmlToElement() function which in turn uses the <template> HTML type to generate a HTML control.
*/
void CWebPage::controlAdded(const QString& sID, CWebControl* pChildControl)
{
    if (m_bDeserialized)
    {
        QString sHead;
        QString sBody;

        pChildControl->addHTML(sHead, sBody);

        sBody.replace(HTML_NL, "");

        m_sPropertyChanges.append(
                    QString(
                        "document.getElementById('%2').appendChild(htmlToElement(\"%1\"));" HTML_NL
                        )
                    .arg(sBody)
                    .arg(sID)
                    );
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    This adds javascript code that will delete the \a sChildID child control of \a sID client-side.
*/
void CWebPage::controlDeleted(const QString& sID, const QString& sChildID)
{
    if (m_bDeserialized)
    {
        m_sPropertyChanges.append(
                    QString(
                        "document.getElementById('%1').removeChild(%2);" HTML_NL
                        )
                    .arg(sID)
                    .arg(sChildID)
                    );
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the javascript snippet in \a sScript to the page.
*/
void CWebPage::scriptCall(const QString& sScript)
{
    m_sPropertyChanges.append(sScript);
    m_sPropertyChanges.append(HTML_NL);
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the javascript instructions that will set document.viewstate to \a sViewState.
*/
void CWebPage::setViewstate(const QString& sViewState)
{
    m_sPropertyChanges.append(
                QString("document.viewstate = '%1';" HTML_NL)
                .arg(sViewState)
                );
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this control to \a sHead and \a sBody.
*/
void CWebPage::addHTML(QString& sHead, QString& sBody)
{
    sHead += QString(
                "<script type='text/javascript' language='javascript'>%1"
                "function htmlToElement(html)%1"
                "{%1"
                "  var template = document.createElement('template');%1"
                "  template.innerHTML = html;%1"
                "  return template.content.firstChild;%1"
                "}%1"
                "function httpWebEvent(theUrl)%1"
                "{%1"
                "  var xmlHttp = null;%1"
                "  xmlHttp = new XMLHttpRequest();%1"
                "  xmlHttp.onload = function()%1"
                "  {%1"
                "    if (this.status == 200)%1"
                "    {%1"
                "      processRequestReturnValue(this.responseText);%1"
                "    }%1"
                "  }%1"
                "  xmlHttp.open('%8', theUrl);%1"
                "  xmlHttp.send(null);%1"
                "}%1"
                "function httpWebEventPOST(theUrl, theText)%1"
                "{%1"
                "  var xmlHttp = null;%1"
                "  xmlHttp = new XMLHttpRequest();%1"
                "  xmlHttp.onload = function()%1"
                "  {%1"
                "    if (this.status == 200)%1"
                "    {%1"
                "      processRequestReturnValue(this.responseText);%1"
                "    }%1"
                "  }%1"
                "  xmlHttp.open('%9', theUrl);%1"
                "  xmlHttp.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');%1"
                "  xmlHttp.send(theText);%1"
                "}%1"
                "function httpUpload(control)%1"
                "{%1"
                "  var xmlHttp = new XMLHttpRequest();%1"
                "  var formData = new FormData();%1"
                "  var actualControl = document.getElementById(control);%1"
                "  xmlHttp.onload = function()%1"
                "  {%1"
                "    if (this.status == 200)%1"
                "    {%1"
                "      processRequestReturnValue(this.responseText);%1"
                "    }%1"
                "  }%1"
                "  xmlHttp.open('%9', getUploadURL(control));%1"
                "  formData.append('%6', document.%6);%1"
                "  formData.append(control, actualControl.files[0]);%1"
                "  xmlHttp.send(formData);%1"
                "  actualControl.value = '';%1"
                "}%1"
                "function getWebEventURL(control, event, param)%1"
                "{%1"
                "  return '?%2=%3' + '&%4=' + control + '&%3=' + event + '&%5=' + param;%1"
                "}%1"
                "function getUploadURL(control)%1"
                "{%1"
                "  return '?%2=%7' + '&%4=' + control;%1"
                "}%1"
                "function emitWebEvent(control, event, param)%1"
                "{%1"
                "  httpWebEventPOST(getWebEventURL(control, event, param), '%6=' + document.%6);%1"
                "}%1"
                "function processRequestReturnValue(value)%1"
                "{%1"
                "  debugOut(value);%1"
                "  if (value != '%10')%1"
                "    eval(value);%1"
                "}%1"
                "function debugOut(text)%1"
                "{%1"
                // "  document.getElementById('DebugOut').value = text;%1"
                "}%1"
                "</script>%1"
                )
            .arg(HTML_NL)
            .arg(TOKEN_ACTION)
            .arg(TOKEN_EVENT)
            .arg(TOKEN_CONTROL)
            .arg(TOKEN_PARAM)
            .arg(TOKEN_VIEWSTATE)
            .arg(TOKEN_UPLOAD)
            .arg(HTTP_GET)
            .arg(HTTP_POST)
            .arg(INVALID_RESPONSE_STRING);

    // Debug out
    // sBody.append(QString("<div width='100%' style='div1'><textarea id='DebugOut'></textarea></div>" HTML_NL));

    for (CWebControl* pControl : m_vControls)
    {
        pControl->addHTML(sHead, sBody);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Serializes the page to a stream. \br\br
    \a stream specifies the stream to use for output. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers.
*/
void CWebPage::serialize(QDataStream& stream, CObjectTracker *pTracker) const
{
    CWebControl::serialize(stream, pTracker);
}

//-------------------------------------------------------------------------------------------------

/*!
    Deserializes the page from a stream. \br\br
    \a stream specifies the stream to use for input. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers. \br
    \a pRootObject specifies the root control of the page being deserialized
*/
void CWebPage::deserialize(QDataStream& stream, CObjectTracker *pTracker, QObject* pRootObject)
{
    CWebControl::deserialize(stream, pTracker, pRootObject);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a string that holds the serialized and compressed page in BASE64 encoding. \br\br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers. \br
*/
QString CWebPage::getViewState(CObjectTracker *pTracker) const
{
    QByteArray baViewState;
    QDataStream stream(&baViewState, QIODevice::WriteOnly);

    serialize(stream, pTracker);

    QByteArray baViewStateCompressed = qCompress(baViewState);
    QByteArray baViewState64(baViewStateCompressed.toBase64());
    QString sViewState(baViewState64);

    return sViewState;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a decompressed and deserialized page from the BASE64 encoded string in \a sViewState. \br\br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers. \br
*/
CWebControl* CWebPage::fromViewState(QString sViewState, CObjectTracker *pTracker)
{
    QByteArray baViewStateLatin = sViewState.toLatin1();
    QByteArray baViewState64 = QByteArray::fromBase64(baViewStateLatin);
    QByteArray baViewState = qUncompress(baViewState64);

    if (baViewState.count() > 0)
    {
        QDataStream stream(&baViewState, QIODevice::ReadOnly);
        QString sClassName;
        stream >> sClassName;

        Q_ASSERT_X(sClassName.isEmpty() == false, "CWebPage::fromViewState", "Class not found while deserializing");

        CWebControl* pControl = CWebFactory::getInstance()->instanciateProduct(sClassName);

        if (pControl != nullptr)
        {
            pControl->deserialize(stream, pTracker, pControl);

            CWebPage* pWebPage = dynamic_cast<CWebPage*>(pControl);

            if (pWebPage != nullptr)
                pWebPage->m_bDeserialized = true;

            return pControl;
        }

    }

    return nullptr;
}
