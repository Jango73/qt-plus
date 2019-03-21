
#pragma once

#include "qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QMap>

// Foundations
#include "CXMLNode.h"

//-------------------------------------------------------------------------------------------------

#define TOKEN_MACRO         "Macro"
#define TOKEN_NAME          "Name"
#define TOKEN_VALUE         "Value"

//-------------------------------------------------------------------------------------------------

//! Defines a static QML analyzer
class QTPLUSSHARED_EXPORT CMacroable
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CMacroable();

    //! Destructor
    virtual ~CMacroable();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Set folder
    void setGrammar(const CXMLNode& xGrammar);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Return grammar
    const CXMLNode& grammar() const;

public:

    //!
    void parseMacros();

    //!
    QString processMacros(const QString& sText);

protected:

    CXMLNode                m_xGrammar;
    QMap<QString, QString>  m_mMacros;
};
