
// Application
#include "CWebFactory.h"
#include "CWebDiv.h"
#include "CWebLabel.h"
#include "CWebButton.h"
#include "CWebTextBox.h"
#include "CWebTextEdit.h"
#include "CWebFileInput.h"
#include "CWebPage.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CWebFactory
    \inmodule qt-plus
    \brief A factory of web controls.
    Every type of control that can be serialized in a CWebPage must be registered with this object.
    \sa CDynamicHTTPServer
    \sa CWebControl
    \sa CWebDiv
    \sa CWebLabel
    \sa CWebButton
    \sa CWebTextBox
    \sa CWebTextEdit
    \sa CWebFileInput
    \sa CWebPage
*/

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CWebFactory with default parameters. \br\br
    Registers all core controls.
*/
CWebFactory::CWebFactory()
{
    registerProduct(CWebControl::staticMetaObject.className(), CWebControl::instantiator);
    registerProduct(CWebDiv::staticMetaObject.className(), CWebDiv::instantiator);
    registerProduct(CWebLabel::staticMetaObject.className(), CWebLabel::instantiator);
    registerProduct(CWebButton::staticMetaObject.className(), CWebButton::instantiator);
    registerProduct(CWebTextBox::staticMetaObject.className(), CWebTextBox::instantiator);
    registerProduct(CWebTextEdit::staticMetaObject.className(), CWebTextEdit::instantiator);
    registerProduct(CWebFileInput::staticMetaObject.className(), CWebFileInput::instantiator);
    registerProduct(CWebPage::staticMetaObject.className(), CWebPage::instantiator);
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CWebFactory.
*/
CWebFactory::~CWebFactory()
{
}
