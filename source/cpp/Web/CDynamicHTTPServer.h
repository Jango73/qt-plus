
#pragma once

//-------------------------------------------------------------------------------------------------

// Application
#include "../CXMLNode.h"
#include "CHTTPServer.h"
#include "CWebComposer.h"
#include "../ILocalizationProvider.h"
#include "WebControls/CWebFactory.h"
#include "WebControls/CWebPage.h"

//-------------------------------------------------------------------------------------------------

//! D�finit un serveur HTTP de domotique
class QTPLUSSHARED_EXPORT CDynamicHTTPServer
        : public CHTTPServer
        , public ILocalizationProvider
        , public CObjectTracker
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //! Constructeur
    CDynamicHTTPServer(quint16 port, QObject* parent = 0);

    //! Destructeur
    virtual ~CDynamicHTTPServer();

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

    //! Retourne une cha�ne de caract�re de localisation
    virtual QString getString(const QString& sToken) const;

    //!
    CWebComposer* composer() const;

    //!
    CWebFactory* factory() const;

    //-------------------------------------------------------------------------------------------------
    // M�thodes h�rit�es
    //-------------------------------------------------------------------------------------------------

    //! Retourne le contenu de la page web
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse, QString& sCustomResponse);

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //! A impl�menter pour retourner une page
    virtual CWebPage* getPage(CDynamicHTTPServer* pServer, const CWebContext& tContext);

    //-------------------------------------------------------------------------------------------------
    // M�thodes prot�g�es
    //-------------------------------------------------------------------------------------------------

protected:

    //! Lit les fichiers de localisation
    void readLocalization();

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    QString				m_sLang;
    QString             m_sLocalizationFolder;
    CXMLNode			m_xStrings;
};
