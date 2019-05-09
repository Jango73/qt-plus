
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "../ILocalizationProvider.h"
#include "../CXMLNode.h"
#include "CHTTPServer.h"
#include "CWebComposer.h"
#include "WebControls/CWebFactory.h"
#include "WebControls/CWebPage.h"

//-------------------------------------------------------------------------------------------------

//! Defines a dynamic HTTP server
class QTPLUSSHARED_EXPORT CDynamicHTTPServer
        : public CHTTPServer
        , public ILocalizationProvider
        , public CObjectTracker
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CDynamicHTTPServer(quint16 port, QObject* parent = nullptr);

    //! Destructor
    virtual ~CDynamicHTTPServer() Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setLocalizationFolder(const QString& sRelativeFolder);

    //!
    void setLang(const QString& value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retuns a localized string
    virtual QString getString(const QString& sToken) const Q_DECL_OVERRIDE;

    //! Returns the composer of this server
    CWebComposer* composer() const;

    //! Returns the factory of this server
    CWebFactory* factory() const;

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //! Returns the contents of the web page
    virtual void getContent(CWebContext& tContext, QString& sHead, QString& sBody, QString& sCustomResponse, QString& sCustomResponseMIME) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! To be overridden by subclasses in order to return a CWebPage object
    virtual CWebPage* getPage(CDynamicHTTPServer* pServer, const CWebContext& tContext);

    //-------------------------------------------------------------------------------------------------
    // Protected methods
    //-------------------------------------------------------------------------------------------------

protected:

    //! Reads the localisation files
    void readLocalization();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString				m_sLang;
    QString             m_sLocalizationFolder;
    CXMLNode			m_xStrings;
};
