
#ifndef ILOCALIZATIONPROVIDER_H
#define ILOCALIZATIONPROVIDER_H

// Qt
#include <QString>

//-------------------------------------------------------------------------------------------------

//! Définit un fournisseur de localisation
class ILocalizationProvider
{
public:

	//! Retourne la liste d'actions
	virtual QString getString(const QString& sToken) const = 0;
};

#endif // ILOCALIZATIONPROVIDER_H
