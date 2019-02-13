
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

    //! Returns a HTML rendering of the page and its child controls
    virtual void getContent(CDynamicHTTPServer *pServer, const CWebContext& tContext, QString& sHead, QString& sBody, QString& xmlResponse);

    //! This can be called to create a redirection to the URL in sPropertyValue
    void locationModified(const QString& sPropertyValue);

    //! This adds a javascript line that will set sPropertyName of control sID to value sPropertyValue
    void propertyModified(const QString& sID, const QString& sPropertyName, const QString& sPropertyValue);

    //! This adds javascript code that will add the pChildControl control to the control sID client-side
    void controlAdded(const QString& sID, CWebControl* pChildControl);

    //! This adds javascript code that will delete the sChildID child control of sID client-side
    void controlDeleted(const QString& sID, const QString& sChildID);

    //! Adds the javascript snippet in sScript to the page
    void scriptCall(const QString& sScript);

    //! Adds the javascript instructions that will set document.viewstate to sViewState
    void setViewstate(const QString& sViewState);

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //! Appends the HTML text that represents this control to sHead and sBody
    virtual void addHTML(QString& sHead, QString& sBody);

    //! Serializes the page to a stream
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const;

    //! Deserializes the page from a stream
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject);

    //! Returns a string that holds the serialized and compressed page in BASE64 encoding
    QString getViewState(CObjectTracker* pTracker) const;

    //-------------------------------------------------------------------------------------------------
    // Static control methods
    //-------------------------------------------------------------------------------------------------

    // Returns a decompressed and deserialized page from the BASE64 encoded string in sViewState
    static CWebControl* fromViewState(QString sViewState, CObjectTracker *pTracker);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QString     m_sPropertyChanges;
    bool        m_bDeserialized;
};
