/* -------------- declaration section -------------- */

%pure-parser
%lex-param   {QMLTreeContext* pContext}
%parse-param {QMLTreeContext* pContext}
%error-verbose
%debug

%{
#include <QDebug>
#include <stdio.h>
#include "QMLItem.h"
#include "QMLNameValue.h"
#include "QMLComplexItem.h"
#include "QMLIdentifier.h"
#include "QMLType.h"
#include "QMLPragma.h"
#include "QMLImport.h"
#include "QMLPropertyDeclaration.h"
#include "QMLPropertyAssignment.h"
#include "QMLPropertyAlias.h"
#include "QMLFunction.h"
#include "QMLFunctionCall.h"
#include "QMLFunctionParameter.h"
#include "QMLVariableDeclaration.h"
#include "QMLQualifiedExpression.h"
#include "QMLArrayAccess.h"
#include "QMLUnaryOperation.h"
#include "QMLBinaryOperation.h"
#include "QMLOnExpression.h"
#include "QMLIf.h"
#include "QMLFor.h"
#include "QMLForIn.h"
#include "QMLSwitch.h"
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
%token TOKEN_DEFAULT            502
%token TOKEN_READ_ONLY          503
%token TOKEN_ALIAS              504
%token TOKEN_VAR                505
%token TOKEN_BOOL               506
%token TOKEN_INT                507
%token TOKEN_REAL               508
%token TOKEN_STRING             509
%token TOKEN_VARIANT            510
%token TOKEN_COLOR              511
%token TOKEN_FUNCTION           512
%token TOKEN_IF                 513
%token TOKEN_ELSE               514
%token TOKEN_FOR                515
%token TOKEN_IN                 516
%token TOKEN_WHILE              517
%token TOKEN_SWITCH             518
%token TOKEN_CASE               519
%token TOKEN_BREAK              520
%token TOKEN_CONTINUE           521
%token TOKEN_WITH               522
%token TOKEN_RETURN             523
%token TOKEN_TYPEOF             524
%token TOKEN_PRAGMA             525
%token TOKEN_ON                 526
%token TOKEN_AS                 527
%token TOKEN_SIGNAL             528
%token TOKEN_NEW                529

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
            pContext->scopes().last()->m_pFile->contents() << pItem;
        }
    }
    |
    Declarations Declaration
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLItem* pItem = $<Object>2;

        if (pItem != nullptr)
        {
            pContext->scopes().last()->m_pFile->contents() << pItem;
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
    |
    JSFunction
    {
        PARSER_TRACE("Declaration", "Function");

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
        QMLItem* pAs = $<Object>5;

        if (pName != nullptr && pVersion != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), pVersion->value().toString(), pAs->value().toString());
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
        QMLItem* pAs = $<Object>4;

        if (pName != nullptr)
        {
            $<Object>$ = new QMLImport(pContext->position(), pContext, pName->value().toString(), "", pAs->value().toString());
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

        QMLItem* pStatement = $<Object>2;

        $<Object>$ = new QMLPragma(pStatement->position(), pStatement);
    }
;

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
        QMLItem* pTarget = $<Object>3;
        QMLComplexItem* pContents = dynamic_cast<QMLComplexItem*>($<Object>5);

        if (pName == nullptr)
        {
            pName = new QMLIdentifier(pContext->position(), "");
        }

        if (pTarget == nullptr)
        {
            pTarget = new QMLIdentifier(pContext->position(), "");
        }

        if (pContents == nullptr)
        {
            pContents = new QMLComplexItem(pContext->position(), pName);
        }

        QMLOnExpression* pExpression = new QMLOnExpression(pName->position(), pTarget, pName, pContents);

        $<Object>$ = pExpression;
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
    PropertyDeclaration
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        $<Object>$ = $<Object>1;
    }
    |
    PropertyAssignment
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

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
    PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>($<Object>3));
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>4);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>4);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>($<Object>3));
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>4);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>6);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>4);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>6);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>4);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>6);

        if (pName != nullptr)
        {
            QMLPropertyAlias* pDeclaration = new QMLPropertyAlias(pName->position(), pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

PropertyModifiersOpt :
    Empty
    {
        $<Integer>$ = (int) QMLPropertyDeclaration::mNone;
    }
    |
    PropertyModifiers
    {
        $<Integer>$ = $<Integer>1;
    }
;

PropertyModifiers:
    TOKEN_DEFAULT
    {
        $<Integer>$ = (int) QMLPropertyDeclaration::mDefault;
    }
    |
    TOKEN_READ_ONLY
    {
        $<Integer>$ = (int) QMLPropertyDeclaration::mReadonly;
    }
;

PropertyAssignment :
    QualifiedIdentifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = $<Object>1;
        QMLItem* pContent = $<Object>3;

        if (pName != nullptr)
        {
            QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName->position(), pName, pContent);

            $<Object>$ = pAssignment;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pContent);

            $<Object>$ = nullptr;
        }
    }
;

PropertyContent :
    Item
    {
        PARSER_TRACE("PropertyContent", "Item");

        $<Object>$ = $<Object>1;
    }
    |
    ItemArray
    {
        PARSER_TRACE("PropertyContent", "ItemArray");

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

ItemArray :
    '[' ItemArrayContents ']'
    {
        PARSER_TRACE("ItemArray", "'[' ItemArrayContents ']'");

        $<Object>$ = $<Object>2;
    }
;

ItemArrayContents :
    Item
    {
        PARSER_TRACE("ItemArrayContents", "Item");

        QMLItem* pItem1 = $<Object>1;

        if (pItem1 != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pItem1->position());
            pComplex->setIsArray(true);
            pComplex->contents() << pItem1;

            $<Object>$ = pComplex;
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    ItemArrayContents ',' Item
    {
        PARSER_TRACE("ItemArrayContents", "ItemArrayContents ',' Item");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);

        if (pComplex != nullptr)
        {
            QMLItem* pItem2 = $<Object>3;

            if (pItem2 != nullptr)
            {
                pComplex->contents() << pItem2;
            }

            $<Object>$ = pComplex;
        }
        else
        {
            $<Object>$ = nullptr;
        }
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

        QMLItem* pName = $<Object>2;
        QMLItem* pParameters = $<Object>3;

        if (pName != nullptr)
        {
            QMLFunction* pFunction = new QMLFunction(pName->position(), pName, pParameters, nullptr);
            pFunction->setIsSignal(true);

            $<Object>$ = pFunction;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pParameters);

            $<Object>$ = nullptr;
        }
    }
;

JSFunction :
    TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock");

        QMLItem* pName = $<Object>2;
        QMLItem* pParameters = $<Object>3;
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>($<Object>4);

        if (pContent == nullptr)
        {
            pContent = new QMLComplexItem(pName->position());
            pContent->setIsBlock(true);
        }

        $<Object>$ = new QMLFunction(pName->position(), pName, pParameters, pContent);
    }
    |
    TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock");

        QMLItem* pParameters = $<Object>2;
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>($<Object>3);

        if (pContent == nullptr)
        {
            pContent = new QMLComplexItem(pContext->position());
            pContent->setIsBlock(true);
        }

        QPoint pPosition;

        if (pParameters != nullptr) pPosition = pParameters->position();
        else pPosition = pContent->position();

        QMLItem* pName = new QMLIdentifier(pPosition, "");

        $<Object>$ = new QMLFunction(pPosition, pName, pParameters, pContent);
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

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression1 = $<Object>1;
        QMLItem* pExpression2 = $<Object>3;

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents() << pExpression1;
        }

        pList->setIsArgumentList(true);

        pList->contents() << pExpression2;

        $<Object>$ = pList;
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
            $<Object>$ = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    }
    |
    TOKEN_VAR Identifier
    {
        PARSER_TRACE("JSFunctionParameter", "TOKEN_VAR Identifier");

        QMLType* pType = new QMLType(pContext->position(), QVARIANT_VARIANT);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>2);

        if (pType != nullptr && pName != nullptr)
        {
            $<Object>$ = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
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
            $<Object>$ = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    }
;

JSStatementBlock :
    '{' Empty '}'
    {
        PARSER_TRACE("JSStatementBlock", "'{' Empty '}'");

        $<Object>$ = $<Object>2;
    }
    |
    '{' JSStatements '}'
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        QMLItem* pItem = $<Object>2;

        pItem = QMLComplexItem::makeBlock(pItem);

        $<Object>$ = pItem;
    }
;

JSStatements :
    JSStatement
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLItem* pStatement1 = $<Object>1;

        if (pStatement1 == nullptr)
        {
            pStatement1 = new QMLItem(pContext->position());
        }

        QMLComplexItem* pComplex = new QMLComplexItem(pStatement1->position());

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
    JSStatement_Switch
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Switch");

        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Case
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Case");

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

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLItem(pContext->position());
        }

        pThen = QMLComplexItem::makeBlock(pThen);

        $<Object>$ = new QMLIf(pCondition->position(), pCondition, pThen, nullptr);
    }
    |
    TOKEN_IF '(' JSExpression ')' JSStatement TOKEN_ELSE JSStatement
    {
        QMLItem* pCondition = $<Object>3;
        QMLItem* pThen = $<Object>5;
        QMLItem* pElse = $<Object>7;

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLItem(pContext->position());
        }

        if (pElse == nullptr)
        {
            pElse = new QMLItem(pContext->position());
        }

        pThen = QMLComplexItem::makeBlock(pThen);
        pElse = QMLComplexItem::makeBlock(pElse);

        $<Object>$ = new QMLIf(pCondition->position(), pCondition, pThen, pElse);
    }
;

JSStatement_For :
    TOKEN_FOR '(' JSVariablesOrExpressionOpt ';' JSExpressionOpt ';' JSExpressionOpt ')' JSStatement
    {
        QMLItem* pInitialization = $<Object>3;
        QMLItem* pCondition = $<Object>5;
        QMLItem* pIncrementation = $<Object>7;
        QMLItem* pContent = $<Object>9;

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLItem(pContext->position());
        }

        pContent = QMLComplexItem::makeBlock(pContent);

        $<Object>$ = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    }
    |
    TOKEN_FOR '(' JSVariablesOrExpressionOpt TOKEN_IN JSExpression ')' JSStatement
    {
        QMLItem* pVariable = $<Object>3;
        QMLItem* pExpression = $<Object>5;
        QMLItem* pContent = $<Object>7;

        if (pVariable == nullptr)
        {
            pVariable = new QMLItem(pContext->position());
        }

        if (pExpression == nullptr)
        {
            pExpression = new QMLItem(pContext->position());
        }

        if (pContent == nullptr)
        {
            pContent = new QMLItem(pContext->position());
        }

        pContent = QMLComplexItem::makeBlock(pContent);

        $<Object>$ = new QMLForIn(pVariable->position(), pVariable, pExpression, pContent);
    }
;

JSStatement_While :
    TOKEN_WHILE '(' JSExpression ')' JSStatement
    {
        QMLItem* pInitialization = new QMLItem(pContext->position());
        QMLItem* pCondition = $<Object>3;
        QMLItem* pIncrementation = new QMLItem(pContext->position());
        QMLItem* pContent = $<Object>5;

        pContent = QMLComplexItem::makeBlock(pContent);

        $<Object>$ = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    }
;

JSStatement_Switch :
    TOKEN_SWITCH '(' JSExpression ')' JSStatementBlock
    {
        QMLItem* pExpression = $<Object>3;
        QMLComplexItem* pCases = dynamic_cast<QMLComplexItem*>($<Object>5);

        if (pExpression != nullptr && pCases != nullptr)
        {
            QMLItem* pSwitch = new QMLSwitch(pExpression->position(), pExpression, pCases);

            $<Object>$ = pSwitch;
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
;

JSStatement_Case :
    TOKEN_CASE JSExpression ':'
    {
        QMLItem* pExpression = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    }
    |
    TOKEN_DEFAULT ':'
    {
        QMLItem* pExpression = new QMLItem(pContext->position(), "default");

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    }
;

JSStatement_Break :
    TOKEN_BREAK
    {
        $<Object>$ = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoBreak);
    }
;

JSStatement_Continue :
    TOKEN_CONTINUE
    {
        $<Object>$ = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoContinue);
    }
;

JSStatement_With :
    TOKEN_WITH '(' JSExpression ')' JSStatement
    {
        $<Object>$ = $<Object>3;
    }
;

JSStatement_Return :
    TOKEN_RETURN JSObject
    {
        QMLItem* pExpression = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    }
    |
    TOKEN_RETURN JSExpressionOpt
    {
        QMLItem* pExpression = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
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
        PARSER_TRACE("JSVariablesOrExpression", "Identifier JSVariables");

        QMLItem* pVariable = $<Object>2;
        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>($<Object>2);

        if (pVariables != nullptr)
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariables->position());

            pDeclaration->setIsArgumentList(true);
            pDeclaration->contents() = pVariables->grabContents();

            SAFE_DELETE(pVariables);

            $<Object>$ = pDeclaration;
        }
        else
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariable->position());

            pDeclaration->contents() << pVariable;

            $<Object>$ = pDeclaration;
        }
    }
    |
    JSExpression
    {
        PARSER_TRACE("JSVariablesOrExpression", "JSExpression");

        $<Object>$ = $<Object>1;
    }
;

JSVariablesOrExpressionOpt :
    Empty
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Empty");

        $<Object>$ = nullptr;
    }
    |
    TOKEN_VAR JSVariables
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Identifier JSVariables");

        QMLItem* pVariable = $<Object>2;
        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>($<Object>2);

        if (pVariables != nullptr)
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariables->position());

            pDeclaration->setIsArgumentList(true);
            pDeclaration->contents() = pVariables->grabContents();

            SAFE_DELETE(pVariables);

            $<Object>$ = pDeclaration;
        }
        else
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariable->position());

            pDeclaration->contents() << pVariable;

            $<Object>$ = pDeclaration;
        }
    }
    |
    JSExpression
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "JSExpression");

        $<Object>$ = $<Object>1;
    }
;

JSVariables :
    JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        QMLItem* pVariable = $<Object>1;

        QMLComplexItem* pVariables = new QMLComplexItem(pVariables->position());
        pVariables->contents() << pVariable;

        $<Object>$ = pVariables;
    }
    |
    JSVariables ',' JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pVariable = $<Object>3;

        if (pVariables != nullptr)
        {
            pVariables->contents() << pVariable;

            $<Object>$ = pVariables;
        }
        else
        {
            $<Object>$ = nullptr;
        }
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

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    Identifier TOKEN_ASSIGN JSObject
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_ASSIGN JSObject
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
;

JSAssignmentExpressionOrJSObject :
    JSAssignmentExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSObject
    {
        $<Object>$ = $<Object>1;
    }
;

JSConditionalExpression :
    JSOrExpression
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSOrExpression '?' JSAssignmentExpressionOrJSObject ':' JSAssignmentExpressionOrJSObject
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLItem* pCondition = $<Object>1;
        QMLItem* pThen = $<Object>3;
        QMLItem* pElse = $<Object>5;

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        $<Object>$ = new QMLConditional(pCondition->position(), pCondition, pThen, pElse);
    }
    |
    JSFunction
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        $<Object>$ = $<Object>1;
    }
;

JSOrExpression :
    JSAndExpression
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression");

        $<Object>$ = $<Object>1;
    }
    |
    JSAndExpression TOKEN_LOGICAL_OR JSOrExpression
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicAnd);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAnd);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSEqualityExpression TOKEN_OR JSBitwiseAndExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boOr);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSEqualityExpression TOKEN_XOR JSBitwiseAndExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boXor);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEquals);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEquals);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLower);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_LOWER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_GREATER JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreater);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_GREATER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAdd);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSMultiplicativeExpression TOKEN_SUB JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSub);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
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

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMul);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_DIV JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDiv);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_MOD JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMod);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_SHL JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftLeft);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_SHR JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftRight);
        }
        else
        {
            $<Object>$ = new QMLItem(pContext->position());
        }
    }
;

JSUnaryExpression :
    JSMemberExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSMemberExpression TOKEN_INC
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_INC");

        QMLItem* pItem = $<Object>1;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoIncrement, true);
    }
    |
    TOKEN_INC JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoIncrement);
    }
    |
    JSMemberExpression TOKEN_DEC
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_DEC");

        QMLItem* pItem = $<Object>1;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoDecrement, true);
    }
    |
    TOKEN_DEC JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoDecrement);
    }
    |
    TOKEN_NOT JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoNot);
    }
    |
    TOKEN_TYPEOF JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoTypeof);
    }
    |
    TOKEN_SUB JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoMinus);
    }
    |
    TOKEN_NEW JSMemberExpression
    {
        QMLItem* pItem = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoNew);
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

        QMLItem* pExpression1 = $<Object>1;
        QMLItem* pExpression2 = $<Object>3;

        QMLQualifiedExpression* pExpression = dynamic_cast<QMLQualifiedExpression*>($<Object>1);

        if (pExpression == nullptr)
        {
            pExpression = new QMLQualifiedExpression(pExpression1->position());
            pExpression->contents() << pExpression1;
        }

        pExpression->contents() << pExpression2;

        $<Object>$ = pExpression;
    }
;

JSArrayAccessExpression :
    JSFunctionCall
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        $<Object>$ = $<Object>1;
    }
    |
    JSArrayAccessExpression '[' JSExpression ']'
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSArrayAccessExpression '[' JSExpression ']'");

        QMLItem* pLeft = $<Object>1;
        QMLArrayAccess* pArrayAccess = dynamic_cast<QMLArrayAccess*>($<Object>1);
        QMLItem* pIndexer = $<Object>3;

        if (pArrayAccess == nullptr)
        {
            pArrayAccess = new QMLArrayAccess(pIndexer->position(), pLeft);
        }

        pArrayAccess->contents() << pIndexer;

        $<Object>$ = pArrayAccess;
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
        QMLItem* pArgument = $<Object>3;
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>($<Object>3);

        if (pArguments == nullptr && pArgument != nullptr)
        {
            pArguments = new QMLComplexItem(pArgument->position());
            pArguments->contents() << pArgument;
        }

        $<Object>$ = new QMLFunctionCall(pName->position(), pName, pArguments);
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

        QMLItem* pItem = $<Object>2;

        pItem->setIsParenthesized(true);

        $<Object>$ = pItem;
    }
;

JSArgumentListOpt :
    Empty
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        $<Object>$ = new QMLComplexItem(pContext->position());
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

        QMLItem* pArgument = $<Object>1;

        QMLComplexItem* pList = new QMLComplexItem(pArgument->position());
        pList->setIsArgumentList(true);
        pList->contents() << pArgument;

        $<Object>$ = pList;
    }
    |
    JSArgumentList ',' JSArgument
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pArgument = $<Object>3;

        pList->contents() << pArgument;

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

JSObject :
    '{' JSAttributes '}'
    {
        PARSER_TRACE("JSObject", "'{' JSAttributes '}'");

        $<Object>$ = $<Object>2;
    }
    |
    '{' '}'
    {
        PARSER_TRACE("JSObject", "'{' '}'");

        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());
        pComplex->setIsObject(true);

        $<Object>$ = pComplex;
    }
    |
    TOKEN_DIMENSION
    {
        PARSER_TRACE("JSObject", "TOKEN_DIMENSION");

        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());
        pComplex->setIsArray(true);

        $<Object>$ = pComplex;
    }
    |
    '[' JSArrayContents ']'
    {
        PARSER_TRACE("JSObject", "'[' JSArrayContents ']'");

        $<Object>$ = $<Object>2;
    }
;

JSArrayContents :
    JSArrayContents ',' JSObject
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSObject");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pItem = $<Object>3;

        pComplex->contents() << pItem;

        $<Object>$ = pComplex;
    }
    |
    JSArrayContents ',' JSExpressionSingle
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSExpressionSingle");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pItem = $<Object>3;

        pComplex->contents() << pItem;

        $<Object>$ = pComplex;
    }
    |
    JSObject
    {
        PARSER_TRACE("JSArrayContents", "JSObject");

        QMLItem* pItem = $<Object>1;

        if (pItem == nullptr)
            pItem = new QMLItem(pContext->position());

        QMLComplexItem* pComplex = new QMLComplexItem(pItem->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pItem;

        $<Object>$ = pComplex;
    }
    |
    JSExpressionSingle
    {
        PARSER_TRACE("JSArrayContents", "JSExpressionSingle");

        QMLItem* pItem = $<Object>1;

        if (pItem == nullptr)
            pItem = new QMLItem(pContext->position());

        QMLComplexItem* pComplex = new QMLComplexItem(pItem->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pItem;

        $<Object>$ = pComplex;
    }
;

JSAttributes :
    JSAttribute
    {
        PARSER_TRACE("JSAttributes", "JSAttribute");

        QMLItem* pAttribute1 = $<Object>1;

        QMLComplexItem* pComplex = new QMLComplexItem(pAttribute1->position());
        pComplex->setIsObject(true);

        pComplex->contents() << pAttribute1;

        $<Object>$ = pComplex;
    }
    |
    JSAttributes JSAttribute
    {
        PARSER_TRACE("JSAttributes", "JSAttributes JSAttribute");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pAttribute2 = $<Object>2;

        pComplex->contents() << pAttribute2;

        $<Object>$ = pComplex;
    }
;

JSAttribute :
    JSAttributeNoComma
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma");

        $<Object>$ = $<Object>1;
    }
    |
    JSAttributeNoComma ','
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma ','");

        $<Object>$ = $<Object>1;
    }
;

JSAttributeNoComma :
    JSAttributeName ':' JSObject
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSObject");

        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != nullptr && pValue != nullptr)
        {
            PARSER_TRACE("JSAttributeNoComma", pName->value().toString() + ", " + pValue->value().toString());

            QMLPropertyAssignment* pAssign = new QMLPropertyAssignment(pName->position(), pName, pValue);

            $<Object>$ = pAssign;
        }
        else
        {
            PARSER_TRACE("JSAttributeNoComma", "... name or value is NULL !!");

            $<Object>$ = nullptr;
        }
    }
    |
    JSAttributeName ':' JSExpressionSingle
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSExpressionSingle");

        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != nullptr && pValue != nullptr)
        {
            PARSER_TRACE("JSAttributeNoComma", pName->value().toString() + ", " + pValue->value().toString());

            QMLPropertyAssignment* pAssign = new QMLPropertyAssignment(pName->position(), pName, pValue);

            $<Object>$ = pAssign;
        }
        else
        {
            PARSER_TRACE("JSAttributeNoComma", "... name or value is NULL !!");

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
        PARSER_TRACE("QualifiedIdentifier", "Identifier");

        QMLItem* pIdentifier = $<Object>1;

        $<Object>$ = pIdentifier;
    }
    |
    QualifiedIdentifier '.' Identifier
    {
        PARSER_TRACE("QualifiedIdentifier", "QualifiedIdentifier '.' Identifier");

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
