
#ifndef CWEBPAGE_H
#define CWEBPAGE_H

// Qt
#include <QString>
#include <QStringList>
#include <QMap>

// Application
#include "../CWebContext.h"
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------
// D�clarations avanc�es
// Forward declarations

class CDynamicHTTPServer;

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CWebPage : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur
    CWebPage();

    //! Constructeur
    CWebPage(const QString& sName);

    //! Destructeur
    virtual ~CWebPage();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QString getPropertyChanges();

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //! Retourne le contenu de la page web
    virtual void getContent(CDynamicHTTPServer *pServer, const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse);

    //!
    void locationModified(const QString& sPropertyValue);

    //!
    void propertyModified(const QString& sID, const QString& sPropertyName, const QString& sPropertyValue);

    //!
    void scriptCall(const QString& sScript);

    //!
    void setViewstate(const QString& sViewState);

    //-------------------------------------------------------------------------------------------------
    // M�thodes h�rit�es
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody) const;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject);

    //!
    QString getViewState(CObjectTracker* pTracker) const;

    //-------------------------------------------------------------------------------------------------
    // M�thodes statiques
    //-------------------------------------------------------------------------------------------------

    static CWebControl* fromViewState(QString sViewState, CObjectTracker *pTracker);

    //-------------------------------------------------------------------------------------------------
    // M�thodes prot�g�es
    //-------------------------------------------------------------------------------------------------

protected:

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sPropertyChanges;
};

#endif // CWEBPAGE_H
