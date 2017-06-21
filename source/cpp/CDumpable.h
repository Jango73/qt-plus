
#pragma once

#include "qtplus_global.h"

// Qt
#include <QTextStream>
#include <QString>

//-------------------------------------------------------------------------------------------------

// Defines a dumpable object
class QTPLUSSHARED_EXPORT CDumpable
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructor
    CDumpable();

    //! Destructor
    virtual ~CDumpable();

    //! Dumps content to a stream, using an identation level
    virtual void dump(QTextStream& stream, int iIdent);

    //! Opens a block ( the '{' character ) in the stream, using an identation level
    void dumpOpenBlock(QTextStream& stream, int iIdent);

    //! Closes a block ( the '}' character ) in the stream, using an identation level
    void dumpCloseBlock(QTextStream& stream, int iIdent);

    //! Opens an array ( the '[' character ) in the stream, using an identation level
    void dumpOpenArray(QTextStream& stream, int iIdent);

    //! Closes an array ( the ']' character ) in the stream, using an identation level
    void dumpCloseArray(QTextStream& stream, int iIdent);

    //! Dumps text in a stream, without indentation and new line
    void dumpNoIndentNoNewLine(QTextStream& stream, QString sText);

    //! Dumps a new line character in a stream
    void dumpNewLine(QTextStream& stream);

    //! Dumps text in a stream, with indentation but no new line
    void dumpIndentedNoNewLine(QTextStream& stream, int iIdent, QString sText);

    //! Dumps text in a stream, with indentation and new line
    void dumpIndented(QTextStream& stream, int iIdent, QString sText);

    //-------------------------------------------------------------------------------------------------
    // Static properties
    //-------------------------------------------------------------------------------------------------

    static bool m_bJavaStyle;
};
