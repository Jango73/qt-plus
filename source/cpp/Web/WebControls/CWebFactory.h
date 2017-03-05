
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

//! D�finit une usine de script
class QTPLUSSHARED_EXPORT CWebFactory : public CSingleton<CWebFactory>, public CFactory<CWebControl>
{
    friend class CSingleton<CWebFactory>;

public:

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    //-------------------------------------------------------------------------------------------------

protected:

    //! Constructeur par d�faut
    CWebFactory();

    //! Destructeur
    virtual ~CWebFactory();
};

#endif // CWEBFACTORY_H
