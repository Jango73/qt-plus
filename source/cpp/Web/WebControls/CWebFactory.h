
#ifndef CWEBFACTORY_H
#define CWEBFACTORY_H

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>

// Application
#include "../../CSingleton.h"
#include "../../CXMLNode.h"
#include "../../CFactory.h"
#include "CWebControl.h"

//-------------------------------------------------------------------------------------------------

//! Définit une usine de script
class QTPLUSSHARED_EXPORT CWebFactory : public CSingleton<CWebFactory>, public CFactory<CWebControl>
{
    friend class CSingleton<CWebFactory>;

public:

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

protected:

    //! Constructeur par défaut
    CWebFactory();

    //! Destructeur
    virtual ~CWebFactory();
};

#endif // CWEBFACTORY_H
