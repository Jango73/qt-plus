
#pragma once

//-------------------------------------------------------------------------------------------------

#include "../../qtplus_global.h"

// Qt
#include <QString>
#include <QVector>
#include <QDataStream>

// Application
#include "../../ISerializable.h"
#include "../CHTTPServer.h"

//-------------------------------------------------------------------------------------------------

#define TOKEN_ACTION    "action"
#define TOKEN_EVENT     "event"
#define TOKEN_LANG      "lang"
#define TOKEN_VIEWSTATE "viewstate"
#define TOKEN_CONTROL   "control"
#define TOKEN_UPLOAD    "upload"
#define TOKEN_PARAM     "param"

//-------------------------------------------------------------------------------------------------

class CWebControl;

class IWebControlObserver
{
public:

    //! Implement this to handle an event for the observed control
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) = 0;

    //!
    virtual qint32 getObserverID() const = 0;
};

//-------------------------------------------------------------------------------------------------

//! Defines a web control
class QTPLUSSHARED_EXPORT CWebControl : public QObject, public ISerializable, public IWebControlObserver
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Default constructor
    CWebControl();

    //! Constructor
    CWebControl(const QString& sName, const QString& sCaption, const QString& sParam = "");

    //! Destructor
    virtual ~CWebControl();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //!
    void setID(qint32 value);

    //!
    CWebControl* setName(const QString& value);

    //!
    CWebControl* setCaption(const QString& value);

    //!
    CWebControl* setStyleClass(const QString& value);

    //!
    CWebControl* setStyle(const QString& value);

    //!
    CWebControl* setEventParameter(const QString& value);

    //!
    CWebControl* setVisible(bool value);

    //!
    CWebControl* setReadOnly(bool value);

    //!
    CWebControl* setParentControl(CWebControl* pControl);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //!
    virtual qint32 getID() const;

    //!
    QString getCodeName() const;

    //!
    QString getName() const;

    //!
    QString getCaption() const;

    //!
    QString getStyleClass() const;

    //!
    QString getStyle() const;

    //!
    QString getEventParameter() const;

    //!
    bool isVisible() const;

    //!
    bool isReadOnly() const;

    //!
    QVector<CWebControl*> getControls();

    //!
    const QVector<CWebControl*> getControls() const;

    //!
    CWebControl* findControl(qint32 iID);

    //!
    CWebControl* findControlByCodeName(QString sCodeName);

    //!
    CWebControl* findControlByName(QString sCodeName);

    //!
    CWebControl* getParentControl();

    //!
    CWebControl* getRoot();

    //-------------------------------------------------------------------------------------------------
    // Inherited methods
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual qint32 getObserverID() const;

    //! Serializes the control to a stream
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //! Deserializes the control from a stream
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Page construction methods
    //-------------------------------------------------------------------------------------------------

    //! Adds a control as a child of this control
    CWebControl* addControl(CWebControl* pControl);

    //! Deletes the child control referenced by pControl
    void deleteControl(CWebControl* pControl);

    //! Add a control observer that watches this control
    CWebControl* addObserver(IWebControlObserver* pObserver);

    //! Adds required HTML text in sHead and sBody to render this control
    virtual void addHTML(QString& sHead, QString& sBody);

    //!
    QString addHTMLEvent(QString& sHead, QString sEvent, QString sEventParam = "") const;

    //!
    QString addHTMLEventWithControlValue(QString& sHead, QString sEvent) const;

    //!
    QString addCustomHTMLEvent(QString& sHead, QString sEvent, QString sFunctionBody) const;

    //-------------------------------------------------------------------------------------------------
    // Event handling methods
    //-------------------------------------------------------------------------------------------------

    //! Generates javascript that will modify an object property client-side
    void propertyModified(const QString& sPropertyName, const QString& sPropertyValue);

    //! Generates javascript that will add a child control client-side
    void controlAdded(CWebControl* pControl);

    //! Generates javascript that will delete a child control client-side
    void controlDeleted(const QString& sChildCodeName);

    //! This can be called to create a redirection to the URL in sPropertyValue
    void locationModified(const QString& sPropertyValue);

    //! Adds the javascript snippet in sScript to the page that owns this control
    void scriptCall(const QString& sScript);

    //! Finds sControl and calls its handleEvent method, then calls the controlEvent method of its observers
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam);

    //-------------------------------------------------------------------------------------------------
    // Various methods
    //-------------------------------------------------------------------------------------------------

    //! Adds a javascript snippet loaded from the resource file sFileName to sHead
    void addScriptFromResources(QString& sHead, const QString &sFileName) const;

    //-------------------------------------------------------------------------------------------------
    // Static methods
    //-------------------------------------------------------------------------------------------------

    //! Returns a unique ID for a web control
    static qint32 generateID();

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    qint32							m_iID;						// ID unique du contrôle
    QString							m_sName;					// Nom du contrôle
    QString							m_sCaption;					// Texte affiché
    QString							m_sStyleClass;				// Classe CSS
    QString							m_sStyle;					// Style CSS
    QString							m_sEventParameter;			// Paramètre transmis sur évènement
    bool							m_bVisible;					// Contrôle visible?
    bool							m_bReadOnly;
    CWebControl*                    m_pParentControl;           // Contrôle parent
    QVector<CWebControl*>			m_vControls;				// Contrôles enfants
    QVector<IWebControlObserver*>	m_vObservers;				// Observateurs de ce contrôle
    QMap<qint32, QVector<qint32> >	m_mObservers;				// Clé = observé, valeur = observateurs

    static qint32					m_iNextID;
};
