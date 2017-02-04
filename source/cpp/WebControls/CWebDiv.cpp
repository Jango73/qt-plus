
// Application
#include "CWebDiv.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebDiv
    \inmodule qt-plus
    \brief A div for a web page.
    \sa CWebFactory
*/

//-------------------------------------------------------------------------------------------------

/*!
    Instantiates a new CWebDiv.
*/
CWebControl* CWebDiv::instantiator()
{
    return new CWebDiv();
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebDiv with default parameters.
*/
CWebDiv::CWebDiv()
{
    setStyleClass("div1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebDiv with basic parameters. \br\br
    \a sName specifies the name of the control. \br
    \a sCaption specifies the caption of the control, which is the displayed text. \br
*/
CWebDiv::CWebDiv(const QString& sName, const QString& sCaption)
    : CWebControl(sName, sCaption)
{
    setStyleClass("div1");
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebDiv.
*/
CWebDiv::~CWebDiv()
{
}
