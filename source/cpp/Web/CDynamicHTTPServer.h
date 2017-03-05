
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

//! Définit un serveur HTTP de domotique
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

    //! Retourne une chaîne de caractère de localisation
    virtual QString getString(const QString& sToken) const;

    //!
    CWebComposer* composer() const;

    //!
    CWebFactory* factory() const;

    //-------------------------------------------------------------------------------------------------
    // Méthodes héritées
    //-------------------------------------------------------------------------------------------------

    //! Retourne le contenu de la page web
    virtual void getContent(const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse, QString& sCustomResponse);

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //! A implémenter pour retourner une page
    virtual CWebPage* getPage(CDynamicHTTPServer* pServer, const CWebContext& tContext);

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

protected:

    //! Lit les fichiers de localisation
    void readLocalization();

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    //-------------------------------------------------------------------------------------------------

protected:

    QString				m_sLang;
    QString             m_sLocalizationFolder;
    CXMLNode			m_xStrings;
};
