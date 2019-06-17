
#pragma once

// Declares a Qt property with setter and getter
// Automatically adds the member variable
// Parameters: Type, type symbol for member name, set name, get name
#define Q_FAST_PROPERTY(t, i, g, s)                                 \
public:                                                             \
    Q_PROPERTY(t g READ g WRITE set##s NOTIFY g##Changed)           \
public:                                                             \
    t g () const { return m_##i##s; }                               \
    void set##s (t value) {                                         \
        if (m_##i##s == value) return;                              \
        m_##i##s = value;                                           \
        emit g##Changed();                                          \
    }                                                               \
    Q_SIGNAL void g##Changed();                                     \
protected:                                                          \
    t m_##i##s;

// Declares a Qt property with getter only
// Automatically adds the member variable
// Parameters: Type, type symbol for member name, set name, get name
#define Q_FAST_PROPERTY_READ_ONLY(t, i, g, s)                       \
public:                                                             \
    Q_PROPERTY(t g READ g)                                          \
public:                                                             \
    t g () const { return m_##i##s; }                               \
protected:                                                          \
    t m_##i##s;
