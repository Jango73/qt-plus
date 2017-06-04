
#pragma once

#include "qtplus_global.h"

// Qt
#include <QObject>
#include <QDataStream>
#include <QVector>

// Application
#include "CSingleton.h"

//-------------------------------------------------------------------------------------------------

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
    //! Sérialise l'objet
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const = 0;

    //! Desérialise l'objet
    virtual void deserialize(QDataStream& stream, CObjectTracker* pTracker, QObject* pRootObject) = 0;
};

//-------------------------------------------------------------------------------------------------

//! Defines a class that can be referenced in serialization
template <class T>
class CSerialReferencable : public ISerializable
{
public:

    //! Constructeur par défaut
    CSerialReferencable()
        : m_pObject(NULL)
    {
    }

    //! Constructeur avec objet
    CSerialReferencable(T* pObject)
        : m_pObject(pObject)
    {
    }

    //! Destructeur
    ~CSerialReferencable()
    {
    }

    //! Retourne le pointeur
    T* get() { return m_pObject; }

    //! Retourne le pointeur constant
    const T* get() const { return m_pObject; }

    //! Sérialise l'objet
    virtual void serialize(QDataStream& stream, CObjectTracker* pTracker) const
    {
        Q_UNUSED(pTracker);

        stream << (qlonglong)m_pObject;
    }

    //! Desérialise l'objet
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

    T*	m_pObject;		// L'objet pointé par cette instance
};
