
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------

// Qt
#include <QString>
#include <QTextStream>

// Foundations
#include "../CXMLNode.h"
#include "../CMacroable.h"

//-------------------------------------------------------------------------------------------------
// XML Grammar File Tokens

#define FORMATTER_TOKEN_FRAGMENT            "Fragment"
#define FORMATTER_TOKEN_ACTION              "Action"
#define FORMATTER_TOKEN_NAMES               "Names"
#define FORMATTER_TOKEN_TYPE                "Type"

#define FORMATTER_ACTION_NEW_LINE           "NewLine"
#define FORMATTER_ACTION_DOUBLE_NEW_LINE    "DoubleNewLine"
#define FORMATTER_ACTION_INDENTATION_INC    "IndentationIncrement"
#define FORMATTER_ACTION_INDENTATION_DEC    "IndentationDecrement"

//-------------------------------------------------------------------------------------------------

//! Defines a QML formatter
class QTPLUSSHARED_EXPORT QMLFormatter : public QObject, public CMacroable
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Enumerators
    //-------------------------------------------------------------------------------------------------

    enum EQMLFormatterFragment {
        qffBeforeImport,
        qffAfterImport,
        qffBeforeItemName,
        qffAfterItemName,
        qffBeforeItemContent,
        qffAfterItemContent,
        qffBeforePropertyName,
        qffAfterPropertyName,
        qffBeforePropertyContent,
        qffAfterPropertyContent,
        qffBeforeFunction,
        qffAfterFunction,
        qffBeforeSignal,
        qffAfterSignal,
        qffBeforeVariableDeclaration,
        qffBeforeFunctionCall,
        qffAfterFunctionCall,
        qffBeforeForFirstSibling,
        qffBeforeFor,
        qffAfterFor,
        qffBeforeWhile,
        qffBeforeWhileFirstSibling,
        qffAfterWhile,
        qffBeforeSwitchFirstSibling,
        qffBeforeSwitch,
        qffAfterSwitch,
        qffBeforeIfFirstSibling,
        qffBeforeIf,
        qffAfterIf,
        qffBeforeTopLevelBinaryOp,
        qffBeforeTopLevelUnaryOp,
        qffBeforeQualifiedExpression,
        qffBeforePrefixUnaryOp,
        qffAfterPrefixUnaryOp,
        qffBeforePostfixUnaryOp,
        qffAfterPostfixUnaryOp
    };

    Q_ENUM(EQMLFormatterFragment);

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QMLFormatter();

    //! Destructor
    virtual ~QMLFormatter();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Increments the indentation counter
    void incIndentation();

    //! Decrements the indentation counter
    void decIndentation();

    //! Outputs a new line
    void writeNewLine(QTextStream& stream);

    //! Outputs a double new line
    void writeDoubleNewLine(QTextStream& stream);

    //! Processes a fragment of code text
    void processFragment(QTextStream& stream, EQMLFormatterFragment fragment);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    int m_iIndentation;
};
