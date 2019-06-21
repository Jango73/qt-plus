
// Qt
#include <QDateTime>
#include <QCoreApplication>
#include <QDirIterator>

// Application
#include "CDynamicHTTPServer.h"
#include "WebControls/CWebFactory.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CDynamicHTTPServer
    \inmodule qt-plus
    \brief A server based on CHTTPServer that can serve pages generated in C++ (like MS ASP).
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CDynamicHTTPServer with a binding port equal to \a port. \br
    \a parent is the owner of this object.
*/
CDynamicHTTPServer::CDynamicHTTPServer(quint16 port, QObject* parent)
    : CHTTPServer(port, parent)
    , m_sLang("fr")
    , m_sLocalizationFolder("")
{
    append(this);
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CDynamicHTTPServer.
*/
CDynamicHTTPServer::~CDynamicHTTPServer()
{
    remove(this);
}

//-------------------------------------------------------------------------------------------------

/*!
    Tells the server to look for localization files in \a sRelativeFolder.
*/
void CDynamicHTTPServer::setLocalizationFolder(const QString& sRelativeFolder)
{
    m_sLocalizationFolder = sRelativeFolder;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the current language to \a value, which is an ISO language code. \br\br
    Usually, the language is set by the client using URL arguments. \br
*/
void CDynamicHTTPServer::setLang(const QString& value)
{
    m_sLang = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a localization string that is mapped to \a sToken, given the current language.
*/
QString CDynamicHTTPServer::getString(const QString& sToken) const
{
    CXMLNode xNode = m_xStrings.getNodeByTagName(sToken);

    if (xNode.isEmpty() == false)
    {
        CXMLNode xLang = xNode.getNodeByTagName(m_sLang);

        if (xLang.isEmpty() == false)
        {
            return xLang.attributes()["Value"];
        }
    }

    return sToken;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the instance of the CWebComposer class.
*/
CWebComposer* CDynamicHTTPServer::composer() const
{
    return CWebComposer::getInstance();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the instance of the CWebFactory class.
*/
CWebFactory* CDynamicHTTPServer::factory() const
{
    return CWebFactory::getInstance();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns some content to the caller (CHTTPServer) by calling getPage(), or by processing an XMLHTTPRequest event. \br\br
    \a tContext contains contextual information for the content generator (the associated socket, resource path, arguments, ...) \br
    \a sHead can be filled with the HTML page header. \br
    \a sBody can be filled with the HTML page body. \br
    If \a sCustomResponse is filled, it will override \a sHead and \a sBody and will be sent as is.
*/
void CDynamicHTTPServer::getContent(CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME)
{
    if (tContext.m_mArguments.contains(TOKEN_ACTION))
    {
        if (tContext.m_mArguments.contains(TOKEN_VIEWSTATE))
        {
            CWebControl* pControl = CWebPage::fromViewState(tContext.m_mArguments[TOKEN_VIEWSTATE], this);

            if (pControl != nullptr)
            {
                QString sEventControlName = tContext.m_mArguments[TOKEN_CONTROL];

                if (tContext.m_mArguments[TOKEN_ACTION] == TOKEN_EVENT)
                {
                    pControl->handleEvent(
                                sEventControlName,
                                tContext.m_mArguments[TOKEN_EVENT],
                            tContext.m_mArguments[TOKEN_PARAM]
                            );
                }
                else if (tContext.m_mArguments[TOKEN_ACTION] == TOKEN_UPLOAD)
                {
                    pControl->handleEvent(
                                sEventControlName,
                                TOKEN_UPLOAD,
                                tContext.m_mArguments[sEventControlName]
                                );
                }

                CWebPage* pPage = dynamic_cast<CWebPage*>(pControl);

                if (pPage != nullptr)
                {
                    pPage->setViewstate(pPage->getViewState(this));
                    sCustomResponse = pPage->getPropertyChanges();
                    sCustomResponseMIME = MIME_Content_XML;
                }

                if (sCustomResponse.isEmpty())
                {
                    sCustomResponse = INVALID_RESPONSE_STRING;
                    sCustomResponseMIME = MIME_Content_XML;
                }

                delete pControl;
            }
        }
    }
    else
    {
        if (tContext.m_mArguments.contains(TOKEN_LANG))
        {
            m_sLang = tContext.m_mArguments[TOKEN_LANG];
        }

        CWebComposer::getInstance()->reset();

        CWebPage* pPage = getPage(this, tContext);

        if (pPage != nullptr)
        {
            pPage->getContent(this, tContext, sHead, sBody, sCustomResponse);

            delete pPage;
        }
        else
        {
            sBody = "Ooops : page not found.";
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a CWebPage to display. Meant to be overridden by subclasses, the default implementation does nothing.\br\br
    \a pServer is a pointer to the server requesting the page. \br
    \a tContext contains information about the request and the client.
*/
CWebPage* CDynamicHTTPServer::getPage(CDynamicHTTPServer* pServer, const CWebContext& tContext)
{
    Q_UNUSED(pServer);
    Q_UNUSED(tContext);

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Reads all localization files.
*/
void CDynamicHTTPServer::readLocalization()
{
    m_xStrings = CXMLNode::loadXMLFromFile(QCoreApplication::applicationDirPath() + "/Localization.xml");

    QDirIterator iterator(QCoreApplication::applicationDirPath() + "/" + m_sLocalizationFolder);

    while (iterator.hasNext())
    {
        QString sFile = iterator.next();

        if (sFile.contains(".xml"))
        {
            m_xStrings.merge(CXMLNode::loadXMLFromFile(sFile));
        }
    }
}
