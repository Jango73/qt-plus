
// Application
#include "CWebLabel.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebLabel
    \inmodule qt-plus
    \brief A label for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebLabel.
*/
CWebControl* CWebLabel::instantiator()
{
    return new CWebLabel();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebLabel with default parameters.
*/
CWebLabel::CWebLabel()
{
    setStyleClass("label1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebLabel with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebLabel::CWebLabel(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
    setStyleClass("label1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebLabel.
*/
CWebLabel::~CWebLabel()
{
}
