/* -------------- declaration section -------------- */

// %define api.pure
%pure-parser
%lex-param   {QMLTreeContext* pContext}
%parse-param {QMLTreeContext* pContext}
%error-verbose

%{
#include <QDebug>
#include <stdio.h>
#include "QMLItem.h"
#include "QMLNameValue.h"
#include "QMLComplexItem.h"
#include "QMLIdentifier.h"
#include "QMLType.h"
#include "QMLImport.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"
#include "QMLPropertyAlias.h"
#include "QMLFunction.h"
#include "QMLFunctionCall.h"
#include "QMLQualifiedExpression.h"
#include "QMLBinaryOperation.h"
#include "QMLIf.h"
#include "QMLFor.h"
#include "QMLConditional.h"
#include "QMLTreeContext.h"

int yylex (void*, void*);
int yyerror (void*, char*);

#define SAFE_DELETE(a)  if ((a) != nullptr) delete (a);

// #define PARSER_TRACE(state, rule)  { qDebug() << state " : " << rule; }
#define PARSER_TRACE(state, rule)

%}

%union {
    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;
}

%token TOKEN_IDENTIFIER         300
%token TOKEN_LITERAL            301
%token TOKEN_BOOLCONSTANT       302
%token TOKEN_INTEGERCONSTANT    303
%token TOKEN_REALCONSTANT       304

%token TOKEN_ASSIGN             310
%token TOKEN_ADD                311
%token TOKEN_SUB                312
%token TOKEN_MUL                313
%token TOKEN_DIV                314
%token TOKEN_MOD                315
%token TOKEN_AND                316
%token TOKEN_OR                 317
%token TOKEN_XOR                318
%token TOKEN_SHL                319
%token TOKEN_SHR                320
%token TOKEN_ADD_ASSIGN         321
%token TOKEN_SUB_ASSIGN         322
%token TOKEN_MUL_ASSIGN         323
%token TOKEN_DIV_ASSIGN         324
%token TOKEN_MOD_ASSIGN         325
%token TOKEN_AND_ASSIGN         326
%token TOKEN_OR_ASSIGN          327
%token TOKEN_XOR_ASSIGN         328
%token TOKEN_SHL_ASSIGN         329
%token TOKEN_SHR_ASSIGN         330
%token TOKEN_LOWER              331
%token TOKEN_GREATER            332
%token TOKEN_LOWER_EQUALS       333
%token TOKEN_GREATER_EQUALS     334
%token TOKEN_EQUALS             335
%token TOKEN_EQUALS_CHECK       336
%token TOKEN_NOT_EQUALS         337
%token TOKEN_NOT_EQUALS_CHECK   338
%token TOKEN_LOGICAL_AND        339
%token TOKEN_LOGICAL_OR         340
%token TOKEN_NOT                341
%token TOKEN_INC                342
%token TOKEN_DEC                343
%token TOKEN_COMPLEMENT         344
%token TOKEN_DIMENSION          345

%token TOKEN_IMPORT             500
%token TOKEN_PROPERTY           501
%token TOKEN_ALIAS              502
%token TOKEN_VAR                503
%token TOKEN_BOOL               504
%token TOKEN_INT                505
%token TOKEN_REAL               506
%token TOKEN_STRING             507
%token TOKEN_VARIANT            508
%token TOKEN_COLOR              509
%token TOKEN_FUNCTION           510
%token TOKEN_IF                 511
%token TOKEN_ELSE               512
%token TOKEN_FOR                513
%token TOKEN_WHILE              514
%token TOKEN_BREAK              515
%token TOKEN_CONTINUE           516
%token TOKEN_WITH               517
%token TOKEN_RETURN             518
%token TOKEN_TYPEOF             519
%token TOKEN_PRAGMA             520
%token TOKEN_ON                 521
%token TOKEN_AS                 522
%token TOKEN_SIGNAL             523

%nonassoc TOKEN_IF
%nonassoc TOKEN_ELSE

%nonassoc TOKEN_IDENTIFIER
%nonassoc TOKEN_LITERAL
%nonassoc TOKEN_INTEGERCONSTANT
%nonassoc TOKEN_REALCONSTANT

%start File

/* -------------- rules section -------------- */
%%

File :
    Declarations
    {
    }
;

Declarations :
    Declaration
    {
        PARSER_TRACE("Declarations", "Declaration");

        QMLItem* pItem = $<Object>1;

        if (pItem != nullptr)
        {
            pContext->item().contents().append(pItem);
        }
    }
    |
    Declarations Declaration
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLItem* pItem = $<Object>2;

        if (pItem != nullptr)
        {
            pContext->item().contents().append(pItem);
        }
    }
;

Declaration :
    ImportStatement
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        $<Object>$ = $<Object>1;
    }
    |
    PragmaStatement
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        $<Object>$ = $<Object>1;
    }
    |
    Item
    {
        PARSER_TRACE("Declaration", "Item");

        $<Object>$ = $<Object>1;
    }
;

ImportStatement :
    TOKEN_IMPORT QualifiedIdentifier Version
    {
        QMLItem* pName = $<Object>2;
        QMLItem* pVersion = $<Object>3;

        if (pName != nullptr && pVersion != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            $<Object>$ = nullptr;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    }
    |
    TOKEN_IMPORT QualifiedIdentifier Version TOKEN_AS Identifier
    {
        QMLItem* pName = $<Object>2;
        QMLItem* pVersion = $<Object>3;

        if (pName != nullptr && pVersion != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            $<Object>$ = nullptr;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    }
    |
    TOKEN_IMPORT Literal
    {
        QMLItem* pName = $<Object>2;

        if (pName != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), "");
        }
        else
        {
            $<Object>$ = nullptr;
        }

        SAFE_DELETE(pName);
    }
    |
    TOKEN_IMPORT Literal TOKEN_AS Identifier
    {
        QMLItem* pName = $<Object>2;

        if (pName != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), "");
        }
        else
        {
            $<Object>$ = nullptr;
        }

        SAFE_DELETE(pName);
    }
;

PragmaStatement :
    TOKEN_PRAGMA QualifiedIdentifier
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        $<Object>$ = nullptr;
    }

Item :
    Identifier '{' ItemContents '}'
    {
        PARSER_TRACE("Item", "Identifier '{' ItemContents '}'");

        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>3);

        if (pComplexItem != nullptr)
        {
            pComplexItem->setName(pName);
        }

        $<Object>$ = pComplexItem;
    }
    |
    Identifier '{' '}'
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position(), pName);

        $<Object>$ = pComplexItem;
    }
    |
    Identifier TOKEN_ON Identifier '{' ItemContents '}'
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON Identifier '{' ItemContents '}'");

        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>5);

        if (pComplexItem != nullptr)
        {
            pComplexItem->setName(pName);
        }

        $<Object>$ = pComplexItem;
    }
;

ItemContents :
    ItemContent
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLItem* pOldItem = $<Object>1;

        if (pOldItem != nullptr)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position());
            pComplexItem->contents() << pOldItem;

            $<Object>$ = pComplexItem;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    ItemContents ItemContent
    {
        PARSER_TRACE("ItemContents", "ItemContents ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pNewItem = $<Object>2;

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        $<Object>$ = pComplexItem;
    }
    |
    ItemContents ',' ItemContent
    {
        PARSER_TRACE("ItemContents", "ItemContents ',' ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pNewItem = $<Object>3;

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        $<Object>$ = pComplexItem;
    }
;

ItemContent :
    PropertyAssignment
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        $<Object>$ = $<Object>1;
    }
    |
    PropertyDeclaration
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        $<Object>$ = $<Object>1;
    }
    |
    Item
    {
        PARSER_TRACE("ItemContent", "Item");

        $<Object>$ = $<Object>1;
    }
    |
    JSFunction
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        $<Object>$ = $<Object>1;
    }
    |
    SignalDeclaration
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        $<Object>$ = $<Object>1;
    }
;

PropertyDeclaration :
    PropertyDeclarationNoColon
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        $<Object>$ = $<Object>1;
    }
    |
    PropertyDeclarationNoColon ';'
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        $<Object>$ = $<Object>1;
    }
;

PropertyDeclarationNoColon :
    TOKEN_PROPERTY Identifier Identifier
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>($<Object>2));
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);

        if (pType != nullptr && pName != nullptr)
        {
            $<Object>$ = new QMLPropertyDeclaration(pContext->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    TOKEN_PROPERTY Identifier Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>($<Object>2));
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>5);

        if (pType != nullptr && pName != nullptr)
        {
            $<Object>$ = new QMLPropertyDeclaration(pContext->position(), pType, pName, pData);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>5);

        if (pName != nullptr)
        {
            $<Object>$ = new QMLPropertyAlias(pContext->position(), pName, pData);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

PropertyAssignment :
    QualifiedIdentifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = $<Object>1;
        QMLItem* pContent = $<Object>3;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), pName, pContent);

        $<Object>$ = pAssignment;
    }
    |
    TOKEN_PROPERTY ':' PropertyContent
    {
        PARSER_TRACE("PropertyAssignment", "TOKEN_PROPERTY ':' PropertyContent");

        QMLItem* pContent = $<Object>3;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), new QMLItem(pContext->position(), QString(TOKEN_PROPERTY)), pContent);

        $<Object>$ = pAssignment;
    }
;

PropertyContent :
    Item
    {
        PARSER_TRACE("PropertyContent", "Item");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        $<Object>$ = $<Object>1;
    }
    |
    JSObject
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        $<Object>$ = $<Object>1;
    }
;

SignalDeclaration :
    SignalDeclarationNoColon
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        $<Object>$ = $<Object>1;
    }
    |
    SignalDeclarationNoColon ';'
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        $<Object>$ = $<Object>1;
    }
;

SignalDeclarationNoColon :
    TOKEN_SIGNAL Identifier JSFunctionParameterList
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>2);
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>($<Object>3);

        $<Object>$ = new QMLFunction(pContext->position(), pName, pParameters, nullptr);
    }
;

JSFunction :
    TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatement
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatement");

        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>2);
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>($<Object>3);
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>($<Object>4);

        $<Object>$ = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    }
    |
    TOKEN_FUNCTION JSFunctionParameterList JSStatement
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatement");

        QMLItem* pName = new QMLIdentifier(pContext->position(), "");
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>($<Object>2);
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>($<Object>3);

        $<Object>$ = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    }
;

JSFunctionParameterList :
    '(' JSFunctionParameters ')'
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        $<Object>$ = $<Object>2;
    }
    |
    '(' ')'
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        $<Object>$ = nullptr;
    }
;

JSFunctionParameters :
    JSFunctionParameter
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        $<Object>$ = $<Object>1;
    }
    |
    JSFunctionParameters ',' JSFunctionParameter
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        SAFE_DELETE($<Object>3);

        $<Object>$ = $<Object>1;
    }
;

JSFunctionParameter :
    Identifier
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier");

        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>1);

        if (pType != nullptr && pName != nullptr)
        {
            $<Object>$ = new QMLPropertyDeclaration(pContext->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    Identifier Identifier
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>($<Object>1));
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>2);

        if (pType != nullptr && pName != nullptr)
        {
            $<Object>$ = new QMLPropertyDeclaration(pContext->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

JSStatementBlock :
    '{' JSStatements '}'
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        $<Object>$ = $<Object>2;
    }
;

JSStatements :
    JSStatement
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLItem* pStatement1 = $<Object>1;
        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());

        pComplex->contents() << pStatement1;

        $<Object>$ = pComplex;
    }
    |
    JSStatements JSStatement
    {
        PARSER_TRACE("JSStatements", "JSStatements JSStatement");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pStatement2 = $<Object>2;

        if (pComplex != nullptr)
        {
            pComplex->contents() << pStatement2;
        }

        $<Object>$ = pComplex;
    }
;

JSStatement :
    JSStatementNoColon
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatementNoColon ';'
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        $<Object>$ = $<Object>1;
    }
;

JSStatementNoColon :
    JSStatementBlock
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        $<Object>$ = $<Object>1;
    }
    |
    JSVariablesOrExpression
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_If
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_For
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_While
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Break
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Continue
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_With
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Return
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        $<Object>$ = $<Object>1;
    }
;

JSStatement_If :
    TOKEN_IF '(' JSExpression ')' JSStatement
    {
        QMLItem* pCondition = $<Object>3;
        QMLItem* pThen = $<Object>5;

        $<Object>$ = new QMLIf(pContext->position(), pCondition, pThen, nullptr);
    }
    |
    TOKEN_IF '(' JSExpression ')' JSStatement TOKEN_ELSE JSStatement
    {
        QMLItem* pCondition = $<Object>3;
        QMLItem* pThen = $<Object>5;
        QMLItem* pElse = $<Object>7;

        $<Object>$ = new QMLIf(pContext->position(), pCondition, pThen, pElse);
    }
;

JSStatement_For :
    TOKEN_FOR '(' JSVariablesOrExpressionOpt ';' JSExpressionOpt ';' JSExpressionOpt ')' JSStatement
    {
        QMLItem* pInitialization = $<Object>3;
        QMLItem* pCondition = $<Object>5;
        QMLItem* pIncrementation = $<Object>7;
        QMLItem* pContent = $<Object>9;

        $<Object>$ = new QMLFor(pContext->position(), pInitialization, pCondition, pIncrementation, pContent);
    }
;

JSStatement_While :
    TOKEN_WHILE '(' JSExpression ')' JSStatement
    {
        QMLItem* pInitialization = nullptr;
        QMLItem* pCondition = $<Object>3;
        QMLItem* pIncrementation = nullptr;
        QMLItem* pContent = $<Object>5;

        $<Object>$ = new QMLFor(pContext->position(), pInitialization, pCondition, pIncrementation, pContent);
    }
;

JSStatement_Break :
    TOKEN_BREAK
    {
        $<Object>$ = nullptr;
    }
;

JSStatement_Continue :
    TOKEN_CONTINUE
    {
        $<Object>$ = nullptr;
    }
;

JSStatement_With :
    TOKEN_WITH '(' JSExpression ')' JSStatement
    {
        $<Object>$ = $<Object>3;
    }
;

JSStatement_Return :
    TOKEN_RETURN JSExpressionOpt
    {
        $<Object>$ = $<Object>2;
    }
;

JSExpressionOpt :
    Empty
    {
        $<Object>$ = nullptr;
    }
    |
    JSExpression
    {
        $<Object>$ = $<Object>1;
    }
;

JSVariablesOrExpression :
    TOKEN_VAR JSVariables
    {
        $<Object>$ = $<Object>2;
    }
    |
    JSExpression
    {
        $<Object>$ = $<Object>1;
    }
;

JSVariablesOrExpressionOpt :
    Empty
    {
        $<Object>$ = nullptr;
    }
    |
    Identifier JSVariables
    {
        $<Object>$ = $<Object>2;
    }
    |
    JSExpression
    {
        $<Object>$ = $<Object>1;
    }
;

JSVariables :
    JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        $<Object>$ = $<Object>1;
    }
    |
    JSVariables ',' JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        SAFE_DELETE($<Object>3);

        $<Object>$ = $<Object>1;
    }
;

JSVariable :
    Identifier
    {
        PARSER_TRACE("JSVariable", "Identifier");

        $<Object>$ = $<Object>1;
    }
    |
    Identifier TOKEN_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        SAFE_DELETE($<Object>3);

        $<Object>$ = $<Object>1;
    }
;

JSExpression :
    JSExpressionSingle
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        $<Object>$ = $<Object>1;
    }
    |
    JSExpressionSingle ',' JSExpression
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle ',' JSExpression");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression2 = $<Object>2;

        if (pComplex != nullptr)
        {
            pComplex->contents() << pExpression2;
        }

        $<Object>$ = pComplex;
    }
;

JSExpressionSingle :
    JSAssignmentExpression
    {
        $<Object>$ = $<Object>1;
    }
;

JSAssignmentExpression :
    JSConditionalExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    JSConditionalExpression TOKEN_ASSIGN JSObject
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
;

JSConditionalExpression :
    JSOrExpression
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLItem* pCondition = $<Object>1;
        QMLItem* pThen = $<Object>3;
        QMLItem* pElse = $<Object>5;

        $<Object>$ = new QMLConditional(pContext->position(), pCondition, pThen, pElse);
    }
    |
    JSFunction
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        $<Object>$ = $<Object>1;
    }
;

JSOrExpression :
    JSXorExpression
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSXorExpression TOKEN_LOGICAL_OR JSOrExpression
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
    }
;

JSXorExpression :
    JSAndExpression
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSAndExpression TOKEN_XOR JSXorExpression
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression TOKEN_XOR JSOrExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
    }
;

JSAndExpression :
    JSBitwiseAndExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSBitwiseAndExpression TOKEN_LOGICAL_AND JSAndExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boLogicAnd);
    }
;

JSBitwiseAndExpression :
    JSEqualityExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSEqualityExpression TOKEN_AND JSBitwiseAndExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAnd);
    }
;

JSEqualityExpression :
    JSRelationalExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSRelationalExpression TOKEN_EQUALS JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boEquals);
    }
    |
    JSRelationalExpression TOKEN_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boNotEquals);
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
    }
;

JSRelationalExpression :
    JSAdditiveExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSRelationalExpression TOKEN_LOWER JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boLower);
    }
    |
    JSRelationalExpression TOKEN_LOWER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
    }
    |
    JSRelationalExpression TOKEN_GREATER JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boGreater);
    }
    |
    JSRelationalExpression TOKEN_GREATER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
    }
;

JSAdditiveExpression :
    JSMultiplicativeExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSMultiplicativeExpression TOKEN_ADD JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boAdd);
    }
    |
    JSMultiplicativeExpression TOKEN_SUB JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boSub);
    }
;

JSMultiplicativeExpression :
    JSUnaryExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSUnaryExpression TOKEN_MUL JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boMul);
    }
    |
    JSUnaryExpression TOKEN_DIV JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boDiv);
    }
    |
    JSUnaryExpression TOKEN_MOD JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boMod);
    }
    |
    JSUnaryExpression TOKEN_SHL JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boShiftLeft);
    }
    |
    JSUnaryExpression TOKEN_SHR JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pContext->position(), pLeft, pRight, QMLBinaryOperation::boShiftRight);
    }
;

JSUnaryExpression :
    JSMemberExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSMemberExpression JSIncrementOperator
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSUnaryOperator JSMemberExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    TOKEN_SUB JSMemberExpression
    {
        $<Object>$ = $<Object>2;
    }
;

JSMemberExpression:
    JSArrayAccessExpression
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSArrayAccessExpression '.' JSMemberExpression
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression '.' JSMemberExpression");

        QMLIdentifier* pIdentifier1 = dynamic_cast<QMLIdentifier*>($<Object>1);
        QMLIdentifier* pIdentifier2 = dynamic_cast<QMLIdentifier*>($<Object>3);

        if (pIdentifier1 != nullptr && pIdentifier2 != nullptr)
        {
            QString sFullString = pIdentifier1->value().value<QString>() + "." + pIdentifier2->value().value<QString>();
            pIdentifier1->setValue(sFullString);

            SAFE_DELETE(pIdentifier2);

            $<Object>$ = pIdentifier1;
        }
        else
        {
            QMLItem* pExpression1 = $<Object>1;
            QMLItem* pExpression2 = $<Object>3;

            QMLQualifiedExpression* pExpression = dynamic_cast<QMLQualifiedExpression*>($<Object>1);

            if (pExpression == nullptr)
            {
                pExpression = new QMLQualifiedExpression(pContext->position());
                pExpression->contents().append(pExpression1);
            }

            pExpression->contents().append(pExpression2);

            $<Object>$ = pExpression;
        }
    }
;

JSArrayAccessExpression :
    JSFunctionCall
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        $<Object>$ = $<Object>1;
    }
    |
    JSFunctionCall '[' JSExpression ']'
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall '[' JSExpression ']'");

        $<Object>$ = $<Object>1;
    }
;

JSFunctionCall :
    JSPrimaryExpression
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSPrimaryExpression '(' JSArgumentListOpt ')'
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = $<Object>1;
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>($<Object>3);

        $<Object>$ = new QMLFunctionCall(pContext->position(), pName, pArguments);
    }
;

JSPrimaryExpression :
    Identifier
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        $<Object>$ = $<Object>1;
    }
    |
    Value
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        $<Object>$ = $<Object>1;
    }
    |
    '(' JSExpression ')'
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        $<Object>$ = $<Object>2;
    }
;

JSArgumentListOpt :
    Empty
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        $<Object>$ = nullptr;
    }
    |
    JSArgumentList
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        $<Object>$ = $<Object>1;
    }
;

JSArgumentList :
    JSArgument
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression1 = $<Object>1;

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pContext->position());
            pList->contents().append(pExpression1);
        }

        $<Object>$ = pList;
    }
    |
    JSArgumentList ',' JSArgument
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression1 = $<Object>1;
        QMLItem* pExpression2 = $<Object>3;

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pContext->position());
            pList->contents().append(pExpression1);
        }

        pList->contents().append(pExpression2);

        $<Object>$ = pList;
    }
;

JSArgument:
    TOKEN_PROPERTY
    {
        $<Object>$ = nullptr;
    }
    |
    JSObject
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSAssignmentExpression
    {
        $<Object>$ = $<Object>1;
    }
;

JSIncrementOperator :
    TOKEN_INC
    {
        $<Object>$ = nullptr;
    }
    |
    TOKEN_DEC
    {
        $<Object>$ = nullptr;
    }
;

JSUnaryOperator :
    TOKEN_NOT
    {
        $<Object>$ = nullptr;
    }
    |
    TOKEN_TYPEOF
    {
        $<Object>$ = nullptr;
    }
;

JSObject :
    '{' JSAttributes '}'
    {
        $<Object>$ = $<Object>2;
    }
    |
    '{' '}'
    {
        $<Object>$ = nullptr;
    }
    |
    TOKEN_DIMENSION
    {
        $<Object>$ = new QMLComplexItem(pContext->position());
    }
    |
    '[' JSArrayContents ']'
    {
        $<Object>$ = $<Object>2;
    }
;

JSArrayContents :
    JSObject
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSArrayContents ',' JSObject
    {
        $<Object>$ = $<Object>1;

        SAFE_DELETE($<Object>3);
    }
    |
    ItemContents
    {
        $<Object>$ = $<Object>1;
    }
    |
    Value
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSArrayContents ',' Value
    {
        $<Object>$ = $<Object>1;
    }
;

JSAttributes :
    JSAttribute
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSAttributes JSAttribute
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pAttribute1 = $<Object>1;
        QMLItem* pAttribute2 = $<Object>2;

        if (pComplex == nullptr)
        {
            pComplex = new QMLComplexItem(pContext->position());
            pComplex->contents() << pAttribute1;
        }

        pComplex->contents() << pAttribute2;

        $<Object>$ = pComplex;
    }
;

JSAttribute :
    JSAttributeNoComma
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSAttributeNoComma ','
    {
        $<Object>$ = $<Object>1;
    }
;

JSAttributeNoComma :
    JSAttributeName ':' JSObject
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pContext->position(), pName);

            pComplex->contents() << pValue;

            $<Object>$ = pComplex;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    JSAttributeName ':' JSExpressionSingle
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pContext->position(), pName);

            pComplex->contents() << pValue;

            $<Object>$ = pComplex;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

JSAttributeName :
    Literal
    {
        $<Object>$ = $<Object>1;
    }
    |
    Identifier
    {
        $<Object>$ = $<Object>1;
    }
;

QualifiedIdentifier :
    Identifier
    {
        $<Object>$ = $<Object>1;
    }
    |
    QualifiedIdentifier '.' Identifier
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRite = $<Object>3;

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        $<Object>$ = pLeft;
    }
;

Identifier :
    TOKEN_IDENTIFIER
    {
        QString* pString = $<String>1;

        if (pString != nullptr)
        {
            $<Object>$ = new QMLIdentifier(pContext->position(), *pString);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

Version :
    TOKEN_REALCONSTANT
    {
        $<Object>$ =  new QMLItem(pContext->position(), pContext->tokenValue());
    }
;

Value :
    Boolean
    {
        $<Object>$ = $<Object>1;
    }
    |
    Integer
    {
        $<Object>$ = $<Object>1;
    }
    |
    Double
    {
        $<Object>$ = $<Object>1;
    }
    |
    Literal
    {
        $<Object>$ = $<Object>1;
    }
;

Boolean :
    TOKEN_BOOLCONSTANT
    {
        $<Object>$ = new QMLItem(pContext->position(), QVariant($<Boolean>1));
    }
;

Integer :
    TOKEN_INTEGERCONSTANT
    {
        $<Object>$ = new QMLItem(pContext->position(), QVariant($<Integer>1));
    }
;

Double :
    TOKEN_REALCONSTANT
    {
        $<Object>$ =  new QMLItem(pContext->position(), QVariant($<Real>1));
    }
;

Literal :
    TOKEN_LITERAL
    {
        QString* pString = $<String>1;

        if (pString != nullptr)
        {
            $<Object>$ = new QMLItem(pContext->position(), QVariant(*pString));
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

Empty :
    {
        $<Object>$ = nullptr;
    }

%%

/* -------------- body section -------------- */

int yylex (void* pLval, void* pCtx)
{
    YYSTYPE* lval = (YYSTYPE*) pLval;
    QMLTreeContext* pContext = (QMLTreeContext*) pCtx;
    return pContext->nextToken(lval);
}

int yyerror (void* pCtx, char* pText)
{
    QMLTreeContext* pContext = (QMLTreeContext*) pCtx;
    pContext->showError(QString(pText));
    return 1;
}
