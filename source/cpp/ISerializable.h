
#pragma once

#include "qtplus_global.h"

// Qt
#include <QObject>
#include <QDataStream>
#include <QVector>

// Application
#include "CSingleton.h"

//-------------------------------------------------------------------------------------------------

//! Keeps track of objects for serialization
class QTPLUSSHARED_EXPORT CObjectTracker
{
public:

    //!
    void append(QObject* pObject);

    //!
    void remove(QObject* pObject);

    //!
    bool exists(QObject* pObject) const;

protected:

    QVector<QObject*> m_vInstances;
};

//-------------------------------------------------------------------------------------------------

//! Defines a serializable object
class ISerializable
{
    //! Serializes the object
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const = 0;

    //! Deserializes the object
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject) = 0;
};

//-------------------------------------------------------------------------------------------------

//! Defines a class that can be referenced in serialization
template <class T>
class CSerialReferencable : public ISerializable
{
public:

    //! Default constructor
    CSerialReferencable()
        : m_pObject(nullptr)
    {
    }

    //! Parametered constructor
    CSerialReferencable(T* pObject)
        : m_pObject(pObject)
    {
    }

    //! Destructor
    ~CSerialReferencable()
    {
    }

    //! Returns the pointer
    T* get() { return m_pObject; }

    //! Returns the constant pointer
    const T* get() const { return m_pObject; }

    //! Serializes the object
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const
    {
        Q_UNUSED(pTracker);

        stream << (qlonglong)m_pObject;
    }

    //! Deserializes the object
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject)
    {
        Q_UNUSED(pRootObject);

        qlonglong lPointer;
        stream >> lPointer;

        if (lPointer)
        {
            T* pObject = (T*)lPointer;

            if (pTracker != nullptr && pTracker->exists(reinterpret_cast<QObject*>(pObject)))
            {
                m_pObject = pObject;
            }
        }
    }

protected:

    T*	m_pObject;		// The object pointed to by this instance
};
