
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

//! Defines a lazy pointer
template <typename dataType>
class CLazyPointer
{
public:

    // A method that can instantiate a CLazyPointer
    typedef dataType* (*LazyPointerInstantiator)(void* context);

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CLazyPointer(LazyPointerInstantiator instantiator, void* context)
        : m_pInstantiator(instantiator)
        , m_pContext(context)
        , m_pData(nullptr)
    {
    }

    //! Copy constructor
    CLazyPointer(const CLazyPointer<dataType>& target)
    {
        *this = target;
    }

    //! Destructor
    ~CLazyPointer()
    {
        delete m_pData;
    }

    void clear()
    {
        delete m_pData;
        m_pData = nullptr;
    }

    void set(dataType* pData)
    {
        delete m_pData;
        m_pData = pData;
    }

    dataType* get()
    {
        if (m_pData == nullptr)
            loadData();

        return m_pData;
    }

    const dataType* get() const
    {
        if (m_pData == nullptr)
            loadData();

        return m_pData;
    }

    bool isNull()
    {
        if (m_pData == nullptr)
            loadData();

        return m_pData == nullptr;
    }

    dataType& operator*() {
        if (m_pData == nullptr)
            loadData();

        return *m_pData;
    }

    // might dereference NULL pointer if unset...
    // but if this is const, what else can be done?
    const dataType& operator*() const
    {
        return *m_pData;
    }

    dataType* operator->()
    {
        if (m_pData == nullptr)
            loadData();

        return m_pData;
    }

    const dataType* operator->() const
    {
        return m_pData;
    }

    CLazyPointer& operator = (const CLazyPointer& target)
    {
        m_pInstantiator = target.m_pInstantiator;
        m_pContext = target.m_pContext;
        m_pData = target.m_pData;

        return *this;
    }

    bool operator == (const CLazyPointer& target)
    {
        return m_pData == target.m_pData;
    }


    bool operator != (const CLazyPointer& target)
    {
        return m_pData != target.m_pData;
    }

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    void loadData()
    {
        delete m_pData;
        m_pData = m_pInstantiator(m_pContext);
    }

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    LazyPointerInstantiator m_pInstantiator;
    void*                   m_pContext;
    dataType*               m_pData;
};
