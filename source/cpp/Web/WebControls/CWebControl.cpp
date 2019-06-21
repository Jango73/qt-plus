
// Qt
#include <QFile>

// Application
#include "CWebFactory.h"
#include "CWebControl.h"
#include "CWebPage.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebControl
    \inmodule qt-plus
    \brief The base class of a web control that can be serialized in a web page.
    For an explanation of how to use web controls, see CWebPage.
    \sa CWebFactory
    \sa CWebPage
*/

//-------------------------------------------------------------------------------------------------

qint32 CWebControl::m_iNextID = 0;

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebControl.
*/
CWebControl* CWebControl::instantiator()
{
    return new CWebControl();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebControl with default parameters.
*/
CWebControl::CWebControl()
    : m_iID(generateID())
    , m_bVisible(true)
    , m_bReadOnly(false)
    , m_pParentControl(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebControl with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
    \a sParam specifies a user parameter. \br
*/
CWebControl::CWebControl(const QString& sName, const QString& sCaption, const QString& sParam)
    : m_iID(generateID())
    , m_sName(sName)
    , m_sCaption(sCaption)
    , m_sEventParameter(sParam)
    , m_bVisible(true)
    , m_bReadOnly(false)
    , m_pParentControl(nullptr)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebControl, and all its children.
*/
CWebControl::~CWebControl()
{
    for (CWebControl* control : m_vControls)
    {
        delete control;
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the ID of the control to \a value.
*/
void CWebControl::setID(qint32 value)
{
    m_iID = value;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the name of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setName(const QString& value)
{
    m_sName = value;
    propertyModified("id", value);
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the caption of the control (displayed text) to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setCaption(const QString& value)
{
    m_sCaption = value;
    propertyModified("value", value);
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the CSS style class of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setStyleClass(const QString& value)
{
    m_sStyleClass = value;
    propertyModified("className", value);
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the CSS style of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setStyle(const QString& value)
{
    m_sStyle = value;
    propertyModified("style", value);
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the event parameter of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setEventParameter(const QString& value)
{
    m_sEventParameter = value;
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the visibility of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setVisible(bool value)
{
    m_bVisible = value;
    propertyModified("style.visibility", value ? "visible" : "hidden");
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the read-only property of the control to \a value. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setReadOnly(bool value)
{
    m_bReadOnly = value;
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the parent of the control to \a pControl. \br\br
    Returns a pointer to this control.
*/
CWebControl* CWebControl::setParentControl(CWebControl* pControl)
{
    m_pParentControl = pControl;
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the ID of this control.
*/
qint32 CWebControl::getID() const
{
    return m_iID;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the code of this control, which is used to identify the control in the HTML document.
*/
QString CWebControl::getCodeName() const
{
    return QString("CTRL_") + QString::number(m_iID);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the name of this control.
*/
QString CWebControl::getName() const
{
    return m_sName;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the caption of this control.
*/
QString CWebControl::getCaption() const
{
    return m_sCaption;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the CSS style class of this control.
*/
QString CWebControl::getStyleClass() const
{
    return m_sStyleClass;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the CSS style of this control.
*/
QString CWebControl::getStyle() const
{
    return m_sStyle;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the CSS style of this control.
*/
QString CWebControl::getEventParameter() const
{
    return m_sEventParameter;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the control is visible.
*/
bool CWebControl::isVisible() const
{
    return m_bVisible;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \c true if the control is visible.
*/
bool CWebControl::isReadOnly() const
{
    return m_bReadOnly;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list of child controls.
*/
QVector<CWebControl*> CWebControl::getControls()
{
    return m_vControls;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the constant list of child controls.
*/
const QVector<CWebControl*> CWebControl::getControls() const
{
    return m_vControls;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a control whose ID is equal to \a iID. \br\br
    Looks in all child controls and can return \c this or \c nullptr.
*/
CWebControl* CWebControl::findControl(qint32 iID)
{
    if (m_iID == iID)
    {
        return this;
    }

    for (CWebControl* pControl : m_vControls)
    {
        CWebControl* pTarget = pControl->findControl(iID);

        if (pTarget != nullptr)
        {
            return pTarget;
        }
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a control whose code name is equal to \a sCodeName. \br\br
    Looks in all child controls and can return \c this or \c nullptr.
*/
CWebControl* CWebControl::findControlByCodeName(QString sCodeName)
{
    if (getCodeName() == sCodeName)
    {
        return this;
    }

    for (CWebControl* pControl : m_vControls)
    {
        CWebControl* pTarget = pControl->findControlByCodeName(sCodeName);

        if (pTarget != nullptr)
        {
            return pTarget;
        }
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a control whose name is equal to \a sName. \br\br
    Looks in all child controls and can return \c this or \c nullptr.
*/
CWebControl* CWebControl::findControlByName(QString sName)
{
    if (m_sName == sName)
    {
        return this;
    }

    for (CWebControl* pControl : m_vControls)
    {
        CWebControl* pTarget = pControl->findControlByName(sName);

        if (pTarget != nullptr)
        {
            return pTarget;
        }
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the parent of this control.
*/
CWebControl* CWebControl::getParentControl()
{
    return m_pParentControl;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the root parent of this control.
*/
CWebControl* CWebControl::getRoot()
{
    CWebControl* pRoot = this;

    while (pRoot->getParentControl() != nullptr)
    {
        pRoot = pRoot->getParentControl();
    }

    return pRoot;
}

//-------------------------------------------------------------------------------------------------

/*!
    This method is meant to be overridden by subclasses in order to react to child control events. \br\br
    \a pControl is the control which triggered the event. \br
    \a sEvent is the event name. \br
    \a sParam is the event parameter.
*/
void CWebControl::controlEvent(CWebControl* pControl, QString sEvent, QString sParam)
{
    Q_UNUSED(pControl);
    Q_UNUSED(sEvent);
    Q_UNUSED(sParam);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the ID of the control.
*/
qint32 CWebControl::getObserverID() const
{
    return m_iID;
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds \a pControl as a child of this control.
*/
CWebControl* CWebControl::addControl(CWebControl* pControl)
{
    if (pControl != nullptr && m_vControls.contains(pControl) == false)
    {
        pControl->setParentControl(this);
        m_vControls.append(pControl);

        controlAdded(pControl);
    }

    return pControl;
}

//-------------------------------------------------------------------------------------------------

/*!
    Deletes the child control \a pControl.
*/
void CWebControl::deleteControl(CWebControl* pControl)
{
    if (m_vControls.contains(pControl))
    {
        QString sCodeName = pControl->getCodeName();

        m_vControls.removeAll(pControl);
        delete pControl;

        controlDeleted(sCodeName);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds \a pObserver as an observer of this control. \br\br
    The observer will be called to handle events that occur in the observed control.
*/
CWebControl* CWebControl::addObserver(IWebControlObserver* pObserver)
{
    m_vObservers.append(pObserver);
    return this;
}

//-------------------------------------------------------------------------------------------------

/*!
    Appends the HTML text that represents this control to \a sHead and \a sBody. \br\br
    This method is meant to be overridden by subclasses. \br
    The default implementation simply adds a <div>.
*/
void CWebControl::addHTML(QString& sHead, QString& sBody)
{
    QString sClassDeclaration = m_sStyleClass.isEmpty() ? "" : QString("class='%1'").arg(m_sStyleClass);
    QString sStyleDeclaration = m_sStyle.isEmpty() ? "" : QString("style='%1'").arg(m_sStyle);

    sBody.append(
                QString("<div id='%1' %2 %3 style.visibility='%4'>")
                .arg(getCodeName())
                .arg(sClassDeclaration)
                .arg(sStyleDeclaration)
                .arg(m_bVisible ? "visible" : "hidden")
                );

    sBody.append(m_sCaption);

    for (CWebControl* pControl : m_vControls)
    {
        pControl->addHTML(sHead, sBody);
    }

    sBody.append(QString("</div>" HTML_NL));
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the javascript function name that is created using \a sEvent and \a sEventParam. \br\br
    The created function calls the javascript function emitWebEvent() with the provided arguments. \br
    It is also appended to \a sHead.
*/
QString CWebControl::addHTMLEvent(QString& sHead, QString sEvent, QString sEventParam) const
{
    return QString("emitWebEvent(&quot;%1&quot;, &quot;%2&quot;, &quot;%3&quot;)")
            .arg(getCodeName())
            .arg(sEvent)
            .arg(sEventParam);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the javascript function name that is created using \a sEvent and the control's value. \br\br
    The created function calls the javascript function emitWebEvent() with the provided arguments. \br
    It is also appended to \a sHead.
*/
QString CWebControl::addHTMLEventWithControlValue(QString& sHead, QString sEvent) const
{
    return QString("emitWebEvent(&quot;%1&quot;, &quot;%2&quot;, %1.value)")
            .arg(getCodeName())
            .arg(sEvent);
}

//-------------------------------------------------------------------------------------------------

/*!
    \a sHead. \br
    \a sEvent. \br
    \a sFunctionBody.
*/
QString CWebControl::addCustomHTMLEvent(QString& sHead, QString sEvent, QString sFunctionBody) const
{
    QString sFunction = QString("%1_%2")
            .arg(getCodeName())
            .arg(sEvent);

    sHead += QString(
                "<script type='text/javascript' language='javascript'>" HTML_NL
                "function %1()" HTML_NL
                "{" HTML_NL
                "  %4" HTML_NL
                "}" HTML_NL
                "</script>" HTML_NL
                )
            .arg(sFunction)
            .arg(sFunctionBody);

    return sFunction;
}

//-------------------------------------------------------------------------------------------------

/*!
    Generates javascript that will modify an object property client-side. \br\br
    \a sPropertyName specifies the name of the property. \br
    \a sPropertyValue specifies the value of the property. \br
*/
void CWebControl::propertyModified(const QString& sPropertyName, const QString& sPropertyValue)
{
    CWebControl* pRoot = getRoot();

    if (pRoot != nullptr)
    {
        CWebPage* pPage = dynamic_cast<CWebPage*>(pRoot);

        if (pPage != nullptr)
        {
            if (pPage->isDeserialized())
            {
                pPage->propertyModified(getCodeName(), sPropertyName, sPropertyValue);
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Generates javascript that will add a child control client-side. \br\br
    \a pControl is the new child control. \br
*/
void CWebControl::controlAdded(CWebControl* pControl)
{
    CWebControl* pRoot = getRoot();

    if (pRoot != nullptr)
    {
        CWebPage* pPage = dynamic_cast<CWebPage*>(pRoot);

        if (pPage != nullptr)
        {
            pPage->controlAdded(getCodeName(), pControl);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Generates javascript that will delete a child control client-side. \br\br
    \a sChildCodeName specifies the name of the child control. \br
*/
void CWebControl::controlDeleted(const QString& sChildCodeName)
{
    CWebControl* pRoot = getRoot();

    if (pRoot != nullptr)
    {
        CWebPage* pPage = dynamic_cast<CWebPage*>(pRoot);

        if (pPage != nullptr)
        {
            pPage->controlDeleted(getCodeName(), sChildCodeName);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    This can be called to create a redirection to the URL in \a sPropertyValue.
*/
void CWebControl::locationModified(const QString& sPropertyValue)
{
    CWebControl* pRoot = getRoot();

    if (pRoot != nullptr)
    {
        CWebPage* pPage = dynamic_cast<CWebPage*>(pRoot);

        if (pPage != nullptr)
        {
            pPage->locationModified(sPropertyValue);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds the javascript snippet in \a sScript to the page that owns this control.
*/
void CWebControl::scriptCall(const QString& sScript)
{
    CWebControl* pRoot = getRoot();

    if (pRoot != nullptr)
    {
        CWebPage* pPage = dynamic_cast<CWebPage*>(pRoot);

        if (pPage != nullptr)
        {
            pPage->scriptCall(sScript);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Looks for a control named \a sControl. \br
    If found, calls its handleEvent() method, then calls the controlEvent() method of every observer of the control. \br
    \a sEvent and \a sParam are the arguments of the event.
*/
void CWebControl::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    CWebControl* pTargetControl = findControlByCodeName(sControl);

    if (pTargetControl != nullptr)
    {
        if (pTargetControl != this)
        {
            pTargetControl->handleEvent(sControl, sEvent, sParam);
        }

        for (IWebControlObserver* pObserver : pTargetControl->m_vObservers)
        {
            pObserver->controlEvent(pTargetControl, sEvent, sParam);
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Adds a javascript snippet loaded from the resource file \a sFileName to \a sHead.
*/
void CWebControl::addScriptFromResources(QString& sHead, const QString& sFileName) const
{
    QFile in(QString(":/%1").arg(sFileName));

    if (in.open(QFile::ReadOnly))
    {
        QByteArray baData = in.readAll();
        in.close();

        sHead += QString(
                    "<script type='text/javascript' language='javascript'>" HTML_NL
                    "%1"
                    "</script>" HTML_NL
                    ).arg(QString(baData));
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Serializes the control to a stream. \br\br
    \a stream specifies the stream to use for output. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers.
*/
void CWebControl::serialize(QDataStream& stream, CObjectTracker *pTracker) const
{
    stream << QString(metaObject()->className());
    stream << m_iID;
    stream << m_sName;
    stream << m_sCaption;
    stream << m_sStyleClass;
    stream << m_sEventParameter;
    stream << m_bVisible;
    stream << m_bReadOnly;

    stream << qint32(m_vObservers.count());
    for (IWebControlObserver* observer : m_vObservers)
    {
        stream << observer->getObserverID();
    }

    stream << qint32(m_vControls.count());
    for (CWebControl* control : m_vControls)
    {
        control->serialize(stream, pTracker);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Deserializes the control from a stream. \br\br
    \a stream specifies the stream to use for input. \br
    \a pTracker is an object that is used to serialize pointers, it keeps track of valid pointers. \br
    \a pRootObject specifies the root control of the page being deserialized
*/
void CWebControl::deserialize(QDataStream& stream, CObjectTracker *pTracker, QObject* pRootObject)
{
    CWebControl* pRootControl = dynamic_cast<CWebControl*>(pRootObject);

    if (pRootControl != nullptr)
    {
        qint32 iControlsCount = 0;
        qint32 iObserverCount = 0;

        // Read properties

        stream >> m_iID;
        stream >> m_sName;
        stream >> m_sCaption;
        stream >> m_sStyleClass;
        stream >> m_sEventParameter;
        stream >> m_bVisible;
        stream >> m_bReadOnly;

        // Read this object's observers IDs

        stream >> iObserverCount;
        for (qint32 iIndex = 0; iIndex < iObserverCount; iIndex++)
        {
            qint32 iID;
            stream >> iID;

            pRootControl->m_mObservers[m_iID].append(iID);
        }

        // Read child controls

        stream >> iControlsCount;
        for (qint32 iIndex = 0; iIndex < iControlsCount; iIndex++)
        {
            QString sClassName;
            stream >> sClassName;

            CWebControl* pControl = CWebFactory::getInstance()->instanciateProduct(sClassName);

            if (pControl != nullptr)
            {
                pControl->deserialize(stream, pTracker, pRootObject);

                addControl(pControl);
            }
        }

        // Resolve observers

        for (qint32 iObservedID : m_mObservers.keys())
        {
            CWebControl* pObservedControl = pRootControl->findControl(iObservedID);

            if (pObservedControl != nullptr)
            {
                for (qint32 iObserverID : m_mObservers[iObservedID])
                {
                    CWebControl* pObserverControl = pRootControl->findControl(iObserverID);

                    if (pObserverControl != nullptr)
                    {
                        IWebControlObserver* pObserver = dynamic_cast<IWebControlObserver*>(pObserverControl);

                        if (pObserver != nullptr)
                        {
                            pObservedControl->addObserver(pObserver);
                        }
                    }
                }
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns a unique ID for a web control.
*/
qint32 CWebControl::generateID()
{
    m_iNextID++;
    return m_iNextID;
}
