
#pragma once

// std
#include <typeinfo>

// Qt
#include <QList>
#include <QHash>

//-------------------------------------------------------------------------------------------------

//! Defines a fast lookup list
template<typename K, typename T>
class CFastList : public QList<T>
{
public:

    CFastList()
    {
    }

    void addItem(K key, const T& item, int index = -1)
    {
        if (index != -1)
            QList<T>::insert(index, item);
        else
            QList<T>::append(item);

        m_hLookup[key] = item;
    }

    void removeItem(K key)
    {
        if (m_hLookup.contains(key))
        {
            QList<T>::removeAll(m_hLookup[key]);
            m_hLookup.remove(key);
        }
    }

    void removeItem(K key, const T& item)
    {
        removeAll(item);
        m_hLookup.remove(key);
    }

    bool containsKey(K key)
    {
        return m_hLookup.contains(key);
    }

    T itemByKey(K key)
    {
        return m_hLookup[key];
    }

    void deleteAll()
    {
        qDeleteAll(*this);
        qDeleteAll(m_hLookup);
    }

protected:

    QHash<K, T> m_hLookup;
};
