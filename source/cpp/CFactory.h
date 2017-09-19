
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QString>
#include <QMap>

//-------------------------------------------------------------------------------------------------
// Forward declarations

template <class T> class CFactoryProductEnumerator;

//-------------------------------------------------------------------------------------------------

//! Defines a factory
template <class T>
class CFactory
{
    friend class CFactoryProductEnumerator<T>;

public:

    //! A method prototype for product instanciation
    typedef T* (*MProductInstanciator)();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Registers a product instanciator
    void registerProduct(QString sClassName, MProductInstanciator pInstanciator)
    {
        s_vInstanciators[sClassName] = pInstanciator;
    }

    //! Instantiates a product given its class name
    T* instanciateProduct(QString sClassName) const
    {
        if (s_vInstanciators.contains(sClassName))
        {
            return s_vInstanciators[sClassName]();
        }

        return nullptr;
    }

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

protected:

    //! Default constructor
    CFactory()
    {
    }

    //! Destructor
    virtual ~CFactory()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    QMap<QString, MProductInstanciator>	s_vInstanciators;
};

//-------------------------------------------------------------------------------------------------

//! Defines a factory product enumerator
template <class T>
class CFactoryProductEnumerator
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor from a CFactory
    CFactoryProductEnumerator(CFactory<T>* pFactory)
        : m_pFactory(pFactory)
        , m_iCurrentIndex(0)
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the next product (nullptr if none to return) : the product must be destroyed by caller
    T* next()
    {
        if (m_iCurrentIndex < m_pFactory->s_vInstanciators.keys().count())
        {
            QString sClassName = m_pFactory->s_vInstanciators.keys()[m_iCurrentIndex];
            T* pProduct = m_pFactory->s_vInstanciators[sClassName]();
            m_iCurrentIndex++;
            return pProduct;
        }

        return nullptr;
    }

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    CFactory<T>*    m_pFactory;
    int             m_iCurrentIndex;
};
