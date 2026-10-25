
// std
#include <type_traits>

// Qt
#include <QList>
#include <QHash>

//-------------------------------------------------------------------------------------------------

//! Defines a fast lookup list: an ordered list of values with a key index
//! on top, so values stay sorted/iterable like a QList while remaining
//! reachable by key in constant time.
//! The list owns the lookup contract: only addItem, removeItem and
//! deleteAll mutate the content, the exposed QList vocabulary is read-only
//! (plus iteration for algorithms like std::sort which only reorder).
//! Not thread-safe: all calls for one instance belong on a single thread.
//! K must provide qHash() and operator==, T must be default-constructible
//! (itemByKey returns T() on miss). deleteAll additionally requires T to
//! be a pointer type.
template<typename K, typename T>
class CFastList : private QList<T>
{
public:

    CFastList()
    {
    }

    // Copy and move keep both containers together: the hash always
    // describes the list, which queued signal delivery relies on
    CFastList(const CFastList& other) = default;
    CFastList(CFastList&& other) = default;
    CFastList& operator=(const CFastList& other) = default;
    CFastList& operator=(CFastList&& other) = default;

    //! Compares the ordered values, like QList
    bool operator==(const CFastList& other) const
    {
        return static_cast<const QList<T>&>(*this) == static_cast<const QList<T>&>(other);
    }

    //! Compares the ordered values, like QList
    bool operator!=(const CFastList& other) const
    {
        return not (*this == other);
    }

    // Read-only list vocabulary: none of these can desynchronize the hash
    using QList<T>::count;
    using QList<T>::size;
    using QList<T>::isEmpty;
    using QList<T>::at;
    using QList<T>::operator[];
    using QList<T>::first;
    using QList<T>::last;
    using QList<T>::indexOf;
    using QList<T>::contains;
    using QList<T>::begin;
    using QList<T>::end;

    //! Adds an item under a key, at the given index or appended
    void addItem(K key, const T& item, int index = -1)
    {
        if (index != -1)
            QList<T>::insert(index, item);
        else
            QList<T>::append(item);

        m_hLookup[key] = item;
    }

    //! Removes the entry registered under a key: a single list occurrence
    //! plus its hash entry, other keys sharing the same value stay valid
    void removeItem(K key)
    {
        typename QHash<K, T>::iterator itr = m_hLookup.find(key);

        if (itr != m_hLookup.end())
        {
            int iIndex = QList<T>::indexOf(itr.value());

            if (iIndex != -1)
                QList<T>::removeAt(iIndex);

            m_hLookup.erase(itr);
        }
    }

    //! Removes the entry registered under a key when it holds the given
    //! item, does nothing otherwise
    void removeItem(K key, const T& item)
    {
        if (m_hLookup.value(key) == item)
            removeItem(key);
    }

    //! Tells whether a key is registered, never inserts
    bool containsKey(K key) const
    {
        return m_hLookup.contains(key);
    }

    //! Returns the value registered under a key, a default T() when the
    //! key is missing. Never inserts: check containsKey() first when the
    //! difference between missing and default matters
    T itemByKey(K key) const
    {
        return m_hLookup.value(key);
    }

    //! Deletes every value then clears the list and the hash together.
    //! Clear the content only through this function: clearing the list
    //! alone would leave dangling values behind in the hash
    void deleteAll()
    {
        static_assert(std::is_pointer<T>::value, "CFastList::deleteAll requires a pointer value type");
        qDeleteAll(*this);
        QList<T>::clear();
        m_hLookup.clear();
    }

protected:

    QHash<K, T> m_hLookup;
};
