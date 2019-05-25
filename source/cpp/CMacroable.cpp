
// Qt
#include <QDebug>

// Application
#include "CMacroable.h"

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a CMacroable.
*/
CMacroable::CMacroable()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a CMacroable.
*/
CMacroable::~CMacroable()
{
}

//-------------------------------------------------------------------------------------------------

/*!
    Sets the grammar member to \a xGrammar.
*/
void CMacroable::setGrammar(const CXMLNode& xGrammar)
{
    m_xGrammar = xGrammar;
    parseMacros();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the grammar.
*/
const CXMLNode& CMacroable::grammar() const
{
    return m_xGrammar;
}

//-------------------------------------------------------------------------------------------------

/*!
    Parses all macros defined in the current grammar file.
*/
void CMacroable::parseMacros()
{
    QVector<CXMLNode> vMacros = m_xGrammar.getNodesByTagName(TOKEN_MACRO);

    m_mMacros.clear();

    for (CXMLNode xMacro : vMacros)
    {
        QString sName = xMacro.attributes()[TOKEN_NAME];
        QString sValue = xMacro.attributes()[TOKEN_VALUE];

        m_mMacros[sName] = sValue;
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns \a sText with macro names replaced .with their respective value.
*/
QString CMacroable::processMacros(const QString& sText)
{
    QString sResult = sText;

    for (QString sMacro : m_mMacros.keys())
    {
        QString sFullMacroName = QString("$%1$").arg(sMacro);

        if (sResult.contains(sFullMacroName))
        {
            if (m_mMacros[sMacro].count() > 0)
            {
                QString sMacroValue = m_mMacros[sMacro];
                sResult.replace(sFullMacroName, sMacroValue);
            }
        }
    }

    return sResult;
}
