
#pragma once

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
