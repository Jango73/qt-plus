
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

    //! Méthode à implémenter pour gérer l'évènement de l'objet observé
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) = 0;

    //!
    virtual qint32 getObserverID() const = 0;
};

//-------------------------------------------------------------------------------------------------

//! Définit un contrôle de page web
class QTPLUSSHARED_EXPORT CWebControl : public QObject, public ISerializable, public IWebControlObserver
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

    //!
    static CWebControl* instantiator();

    //! Constructeur par défaut
    CWebControl();

    //! Constructeur avec paramètres
    CWebControl(const QString& sName, const QString& sCaption, const QString& sParam = "");

    //! Destructeur
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
    // Méthodes héritées
    //-------------------------------------------------------------------------------------------------

    //!
    virtual void controlEvent(CWebControl* pControl, QString sEvent, QString sParam) Q_DECL_OVERRIDE;

    //!
    virtual qint32 getObserverID() const;

    //!
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const Q_DECL_OVERRIDE;

    //!
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject) Q_DECL_OVERRIDE;

    //-------------------------------------------------------------------------------------------------
    // Méthodes de construction de page
    //-------------------------------------------------------------------------------------------------

    //!
    CWebControl* addControl(CWebControl* pControl);

    //!
    void deleteControl(CWebControl* pControl);

    //!
    CWebControl* addObserver(IWebControlObserver* pObserver);

    //!
    virtual void addHTML(QString& sHead, QString& sBody);

    //!
    QString addHTMLEvent(QString& sHead, QString sEvent, QString sEventParam = "") const;

    //!
    QString addHTMLEventWithControlValue(QString& sHead, QString sEvent) const;

    //!
    QString addCustomHTMLEvent(QString& sHead, QString sEvent, QString sFunctionBody) const;

    //-------------------------------------------------------------------------------------------------
    // Méthodes de gestion d'évènements
    //-------------------------------------------------------------------------------------------------

    //!
    void propertyModified(const QString& sPropertyName, const QString& sPropertyValue);

    //!
    void controlAdded(CWebControl* pControl);

    //!
    void controlDeleted(const QString& sChildCodeName);

    //!
    void locationModified(const QString& sPropertyValue);

    //!
    void scriptCall(const QString& sScript);

    //!
    virtual void handleEvent(QString sControl, QString sEvent, QString sParam);

    //-------------------------------------------------------------------------------------------------
    // Méthodes diverses
    //-------------------------------------------------------------------------------------------------

    //!
    void addScriptFromResources(QString& sHead, const QString &sFileName) const;

    //-------------------------------------------------------------------------------------------------
    // Méthodes statiques
    //-------------------------------------------------------------------------------------------------

    //!
    static qint32 generateID();

    //-------------------------------------------------------------------------------------------------
    // Signaux
    //-------------------------------------------------------------------------------------------------

signals:

    //-------------------------------------------------------------------------------------------------
    // Propriétés
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
