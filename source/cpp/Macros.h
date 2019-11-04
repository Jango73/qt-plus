
#pragma once

// Qt
#include <QDebug>

//-------------------------------------------------------------------------------------------------
// Properties

// Declares a Qt property with setter and getter
// Automatically adds the member variable
// Names the member variable as m_<prefix><set name> (for instance: m_iCount)
// Parameters: Type, prefix for type, get name, set name
#define Q_FAST_PROPERTY(t, p, g, s)                                 \
public:                                                             \
    Q_PROPERTY(t g READ g WRITE set##s NOTIFY g##Changed)           \
public:                                                             \
    t g () const { return m_##p##s; }                               \
    void set##s (t value) {                                         \
        if (m_##p##s == value) return;                              \
        m_##p##s = value;                                           \
        emit g##Changed();                                          \
    }                                                               \
    Q_SIGNAL void g##Changed();                                     \
protected:                                                          \
    t m_##p##s;

// Declares a Qt property with getter only
// Automatically adds the member variable
// Names the member variable as m_<prefix><set name> (for instance: m_iCount)
// Parameters: Type, prefix for type, get name, set name
#define Q_FAST_PROPERTY_READ_ONLY(t, p, g, s)                       \
public:                                                             \
    Q_PROPERTY(t g READ g)                                          \
public:                                                             \
    t g () const { return m_##p##s; }                               \
protected:                                                          \
    t m_##p##s;

// Declares a Qt property with setter and getter
// Automatically adds the member variable
// Does not implement the setter
// Names the member variable as m_<prefix><set name> (for instance: m_iCount)
// Parameters: Type, prefix for type, get name, set name
#define Q_FAST_PROPERTY_NO_SET_IMPL(t, p, g, s)                     \
public:                                                             \
    Q_PROPERTY(t g READ g WRITE set##s NOTIFY g##Changed)           \
public:                                                             \
    t g () const { return m_##p##s; }                               \
    void set##s (t value);                                          \
    Q_SIGNAL void g##Changed();                                     \
protected:                                                          \
    t m_##p##s;

//-------------------------------------------------------------------------------------------------
// Pointers

// Checks nullity of a pointer
#define IS_NULL(p)      ((p) == nullptr)

// Checks non nullity of a pointer
#define IS_NOT_NULL(p)  ((p) != nullptr)

// Delete a pointer if it is not null
#define SAFE_DELETE(p)  if ((p) != nullptr) delete (p); (p) = nullptr

//-------------------------------------------------------------------------------------------------
// Math

#define CLIPPED(a,n,x)  (std::min(std::max(a, n), x))

//-------------------------------------------------------------------------------------------------
// Console

// Gets the current source file name
#define __FILENAME__    (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

// Outputs a debug string
#define OUT_DEBUG(a)    qDebug() << QString("%1::%2() : %3").arg(__FILENAME__).arg(__FUNCTION__).arg(a)

// Outputs an error string
#define OUT_ERROR(a)    qCritical() << a

//-------------------------------------------------------------------------------------------------
// From http://blubbqt.blogspot.com

// c = class name; e = enum name; v = enum value
#define enumToQString(c, e, v) \
    (c::staticMetaObject.enumerator(c::staticMetaObject.indexOfEnumerator(#e)).valueToKey(v))

// c = class name; e = enum name; s = string value
#define qStringToEnum(c, e, s) \
    c::e(c::staticMetaObject.enumerator(c::staticMetaObject.indexOfEnumerator(#e)).keyToValue(s.toUtf8()))

// c = class name; f = flag name, v = flag value
#define flagToQString(c, f, v) \
    (c::staticMetaObject.enumerator(c::staticMetaObject.indexOfEnumerator(#f)).valueToKeys(v))

// c = class name; f = flag name; s = string value
#define qStringToFlag(c, f, s) \
    c::f(c::staticMetaObject.enumerator(c::staticMetaObject.indexOfEnumerator(#f)).keysToValue(s.toUtf8()))

//-------------------------------------------------------------------------------------------------
// Container functions

template <typename keyType, typename valueType>
keyType mapKeyForValue(QMap<keyType, valueType> map, valueType v)
{
    keyType sExistingId;
    QList<keyType> lKeys = map.keys(v);

    if (lKeys.count() > 0)
        return lKeys[0];

    return keyType();
}
