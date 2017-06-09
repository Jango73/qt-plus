
#pragma once

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QStringList>
#include <QMap>

// Application
#include "../CWebContext.h"
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------
// Forward declarations

class CDynamicHTTPServer;

//-------------------------------------------------------------------------------------------------

class QTPLUSSHARED_EXPORT CWebPage : public CWebControl
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructor
    CWebPage();

    //! Constructor
    CWebPage(const QString& sName);

    //! Destructor
    virtual ~CWebPage();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    QString getPropertyChanges();

    //!
    bool isDeserialized() const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Retourne le contenu de la page web
    virtual void getContent(CDynamicHTTPServer *pServer, const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse);

    //!
    void locationModified(const QString& sPropertyValue);

    //!
    void propertyModified(const QString& sID, const QString& sPropertyName, const QString& sPropertyValue);

    //!
    void controlAdded(const QString& sID, CWebControl* pChildControl);

    //!
    void controlDeleted(const QString& sID, const QString& sChildID);

    //!
    void scriptCall(const QString& sScript);

    //!
    void setViewstate(const QString& sViewState);

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void addHTML(QString& sHead, QString& sBody);

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject);

    //!
    QString getViewState(CObjectTracker* pTracker) const;

    //-------------------------------------------------------------------------------------------------
    // Static control methods
    //-------------------------------------------------------------------------------------------------

    static CWebControl* fromViewState(QString sViewState, CObjectTracker *pTracker);

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    //-------------------------------------------------------------------------------------------------

protected:

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sPropertyChanges;
    bool        m_bDeserialized;
};
