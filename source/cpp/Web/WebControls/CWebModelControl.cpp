
// Application
#include "CWebModelControl.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebModelControl
    \inmodule qt-plus
    \brief A model control for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebModelControl.
*/
CWebControl* CWebModelControl::instantiator()
{
    return new CWebModelControl();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebModelControl with default parameters.
*/
CWebModelControl::CWebModelControl()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebModelControl with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
    \a pModelProvider provides model data. \br
*/
CWebModelControl::CWebModelControl(const QString& sName, const QString& sCaption, IJSONModelProvider* pModelProvider)
    : CWebControl(sName, sCaption)
    , m_pModelProvider(pModelProvider)
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebModelControl.
*/
CWebModelControl::~CWebModelControl()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Handles any event for this text box. \br\br
    \a sControl is unused. \br
    If \a sEvent is \c EVENT_CHANGED, the caption is set to \a sParam.
*/
void CWebModelControl::handleEvent(QString sControl, QString sEvent, QString sParam)
{
    Q_UNUSED(sControl);
    Q_UNUSED(sEvent);
    Q_UNUSED(sParam);
}

//-------------------------------------------------------------------------------------------------

void CWebModelControl::serialize(QDataStream& stream, CObjectTracker* pTracker) const
{
    CWebControl::serialize(stream, pTracker);

    m_pModelProvider.serialize(stream, pTracker);
}

//-------------------------------------------------------------------------------------------------

void CWebModelControl::deserialize(QDataStream& stream, CObjectTracker *pTracker, QObject* pRootControl)
{
    CWebControl::deserialize(stream, pTracker, pRootControl);

    m_pModelProvider.deserialize(stream, pTracker, pRootControl);
}
