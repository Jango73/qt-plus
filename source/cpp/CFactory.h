
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QMap>

//-------------------------------------------------------------------------------------------------
// D�clarations avanc�es
// Forward declarations

template <class T> class CFactoryProductEnumerator;

//-------------------------------------------------------------------------------------------------

//! D�finit une usine
//! Defines a factory
template <class T>
class CFactory
{
    friend class CFactoryProductEnumerator<T>;

public:

    //! Type de m�thode qui instancie un produit
    //! A method prototype for product instanciation
    typedef T* (*MProductInstanciator)();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // M�thodes de contr�le
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Enregistre un instanciateur de produit
    //! Registers a product instanciator
    void registerProduct(QString sClassName, MProductInstanciator pInstanciator)
    {
        s_vInstanciators[sClassName] = pInstanciator;
    }

    //! Instancie un produit d'apr�s son nom de classe
    //! Instanciates a product given its class name
    T* instanciateProduct(QString sClassName) const
    {
        if (s_vInstanciators.contains(sClassName))
        {
            return s_vInstanciators[sClassName]();
        }

        return NULL;
    }

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

protected:

    //! Constructeur par d�faut
    //! Default constructor
    CFactory()
    {
    }

    //! Destructeur
    //! Destructor
    virtual ~CFactory()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMap<QString, MProductInstanciator>	s_vInstanciators;
};

//-------------------------------------------------------------------------------------------------

//! D�finit un �num�rateur de produit d'usine
//! Defines a factory product enumerator
template <class T>
class CFactoryProductEnumerator
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructeur d'apr�s une CFactory
    //! Constructor from a CFactory
    CFactoryProductEnumerator(CFactory<T>* pFactory)
        : m_pFactory(pFactory)
        , m_iCurrentIndex(0)
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne le prochain produit (NULL si pas de produit � retourner) : le produit devra �tre d�truit par l'appelant
    //! Returns the next product (NULL if none to return) : the product must be destroyed by caller
    T* next()
    {
        if (m_iCurrentIndex < m_pFactory->s_vInstanciators.keys().count())
        {
            QString sClassName = m_pFactory->s_vInstanciators.keys()[m_iCurrentIndex];
            T* pProduct = m_pFactory->s_vInstanciators[sClassName]();
            m_iCurrentIndex++;
            return pProduct;
        }

        return NULL;
    }

    //-------------------------------------------------------------------------------------------------
    // Propri�t�s
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    CFactory<T>*	m_pFactory;
    int				m_iCurrentIndex;
};
