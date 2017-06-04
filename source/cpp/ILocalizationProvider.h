
#pragma once

// Qt
#include <QString>

//-------------------------------------------------------------------------------------------------

//! Defines a localization provider
class ILocalizationProvider
{
public:

    //! Returns a string given a token
	virtual QString getString(const QString& sToken) const = 0;
};
