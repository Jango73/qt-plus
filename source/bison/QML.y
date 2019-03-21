/* -------------- declaration section -------------- */

%pure-parser
%lex-param   {QMLTreeContext* pContext}
%parse-param {QMLTreeContext* pContext}
%error-verbose
%debug

%{
#include <QDebug>
#include <stdio.h>
#include "QMLEntity.h"
#include "QMLComplexEntity.h"
#include "QMLNameValue.h"
#include "QMLIdentifier.h"
#include "QMLSpecialValue.h"
#include "QMLType.h"
#include "QMLPragma.h"
#include "QMLImport.h"
#include "QMLItem.h"
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

#define ENSURE_NON_NULL(a)  { if (a == nullptr) a = new QMLEntity(pContext->position()); }

// #define PARSER_TRACE(state, rule)  { qDebug() << state " : " << rule; }
#define PARSER_TRACE(state, rule)

%}

%union {
    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLEntity*  Object;
}

%token TOKEN_IDENTIFIER         300
%token TOKEN_LITERAL            301
%token TOKEN_BOOLCONSTANT       302
%token TOKEN_INTEGERCONSTANT    303
%token TOKEN_REALCONSTANT       304
%token TOKEN_NULL               305
%token TOKEN_UNDEFINED          306

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
%token TOKEN_NOT_NOT            342
%token TOKEN_INC                343
%token TOKEN_DEC                344
%token TOKEN_COMPLEMENT         345
%token TOKEN_DIMENSION          346

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

        QMLEntity* pEntity = $<Object>1;

        if (pEntity != nullptr)
        {
            pContext->scopes().last()->m_pFile->contents() << pEntity;
        }
    }
    |
    Declarations Declaration
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLEntity* pEntity = $<Object>2;

        if (pEntity != nullptr)
        {
            pContext->scopes().last()->m_pFile->contents() << pEntity;
        }
    }
    |
    error
    {
        // SAFE_DELETE($<Object>1);
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
    JSExpression
    {
        PARSER_TRACE("Declaration", "JSExpression");

        $<Object>$ = $<Object>1;
    }
;

ImportStatement :
    TOKEN_IMPORT JSMemberExpression Version
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression Version");

        QMLEntity* pName = $<Object>2;
        QMLEntity* pVersion = $<Object>3;

        if (pName != nullptr && pVersion != nullptr)
        {
            $<Object>$ = new QMLImport(pName->position(), pContext, pName, pVersion);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    TOKEN_IMPORT JSMemberExpression Version TOKEN_AS Identifier
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression Version TOKEN_AS Identifier");

        QMLEntity* pName = $<Object>2;
        QMLEntity* pVersion = $<Object>3;
        QMLEntity* pAs = $<Object>5;

        if (pName != nullptr && pVersion != nullptr)
        {
            $<Object>$ = new QMLImport(pName->position(), pContext, pName, pVersion, pAs);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    TOKEN_IMPORT JSMemberExpression
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression");

        QMLEntity* pName = $<Object>2;

        if (pName != nullptr)
        {
            $<Object>$ = new QMLImport(pName->position(), pContext, pName);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
    |
    TOKEN_IMPORT JSMemberExpression TOKEN_AS Identifier
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression TOKEN_AS Identifier");

        QMLEntity* pName = $<Object>2;
        QMLEntity* pAs = $<Object>4;

        if (pName != nullptr && pAs != nullptr)
        {
            $<Object>$ = new QMLImport(pName->position(), pContext, pName, nullptr, pAs);
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

PragmaStatement :
    TOKEN_PRAGMA JSMemberExpression
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA JSMemberExpression");

        QMLEntity* pStatement = $<Object>2;

        $<Object>$ = new QMLPragma(pStatement->position(), pStatement);
    }
;

Item :
    JSMemberExpression '{' ItemContents '}'
    {
        PARSER_TRACE("Item", "JSMemberExpression '{' ItemContents '}'");

        QMLEntity* pName = $<Object>1;
        QMLItem* pComplexItem = dynamic_cast<QMLItem*>($<Object>3);

        if (pName != nullptr && pComplexItem != nullptr)
        {
            pComplexItem->setPosition(pName->position());
            pComplexItem->setName(pName);
        }
        else
        {
            SAFE_DELETE(pName);
        }

        $<Object>$ = pComplexItem;
    }
    |
    JSMemberExpression '{' '}'
    {
        PARSER_TRACE("Item", "JSMemberExpression '{' '}'");

        QMLEntity* pName = $<Object>1;
        QMLItem* pComplexItem = new QMLItem(pContext->position());

        if (pName != nullptr)
        {
            pComplexItem->setPosition(pName->position());
            pComplexItem->setName(pName);
        }
        else
        {
            SAFE_DELETE(pName);
        }

        $<Object>$ = pComplexItem;
    }
    |
    Identifier TOKEN_ON JSMemberExpression '{' ItemContents '}'
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON JSMemberExpression '{' ItemContents '}'");

        QMLEntity* pName = $<Object>1;
        QMLEntity* pTarget = $<Object>3;
        QMLItem* pContents = dynamic_cast<QMLItem*>($<Object>5);

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
            pContents = new QMLItem(pContext->position(), pName->clone());
        }

        QMLOnExpression* pExpression = new QMLOnExpression(pName->position(), pTarget, pName->clone(), pContents);

        SAFE_DELETE(pName);

        $<Object>$ = pExpression;
    }
;

ItemContents :
    ItemContent
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLEntity* pOldItem = $<Object>1;

        if (pOldItem != nullptr)
        {
            QMLItem* pComplexItem = new QMLItem(pContext->position());
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

        QMLItem* pComplexItem = dynamic_cast<QMLItem*>($<Object>1);
        QMLEntity* pNewItem = $<Object>2;

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

        QMLItem* pComplexItem = dynamic_cast<QMLItem*>($<Object>1);
        QMLEntity* pNewItem = $<Object>3;

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
    PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY");

        int iModifiers = $<Integer>1;
        QMLEntity* pTypeIdentifier = $<Object>3;
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier");

        int iModifiers = $<Integer>1;
        QMLEntity* pTypeIdentifier = $<Object>3;
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>4);

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>4);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLEntity* pTypeIdentifier = $<Object>3;
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");
        QMLEntity* pData = dynamic_cast<QMLEntity*>($<Object>6);

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLEntity* pTypeIdentifier = $<Object>3;
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>4);
        QMLEntity* pData = dynamic_cast<QMLEntity*>($<Object>6);

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>4);
        QMLEntity* pData = dynamic_cast<QMLEntity*>($<Object>6);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    }
    |
    PropertyModifiersOpt TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        int iModifiers = $<Integer>1;
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>4);
        QMLEntity* pData = dynamic_cast<QMLEntity*>($<Object>6);

        if (pName != nullptr)
        {
            QMLPropertyAlias* pDeclaration = new QMLPropertyAlias(pName->position(), pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            $<Object>$ = pDeclaration;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
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
    PropertyModifiersOpt TOKEN_PROPERTY ':' PropertyContent
    {
        PARSER_TRACE("PropertyAssignment", "PropertyModifiersOpt TOKEN_PROPERTY ':' PropertyContent");

        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");
        QMLEntity* pContent = $<Object>4;

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
    |
    JSMemberExpression ':' PropertyContent
    {
        PARSER_TRACE("PropertyAssignment", "JSMemberExpression ':' PropertyContent");

        QMLEntity* pName = $<Object>1;
        QMLEntity* pContent = $<Object>3;

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

        QMLEntity* pEntity1 = $<Object>1;

        if (pEntity1 != nullptr)
        {
            QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity1->position());
            pComplex->setIsArray(true);
            pComplex->contents() << pEntity1;

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

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>($<Object>1);

        if (pComplex != nullptr)
        {
            QMLEntity* pEntity2 = $<Object>3;

            if (pEntity2 != nullptr)
            {
                pComplex->contents() << pEntity2;
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
    TOKEN_SIGNAL Identifier
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier");

        QMLEntity* pName = $<Object>2;
        QMLEntity* pParameters = new QMLEntity(pContext->position());

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
    |
    TOKEN_SIGNAL Identifier JSFunctionParameterList
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLEntity* pName = $<Object>2;
        QMLEntity* pParameters = $<Object>3;

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

        QMLEntity* pName = $<Object>2;
        QMLEntity* pParameters = $<Object>3;
        QMLComplexEntity* pContent = dynamic_cast<QMLComplexEntity*>($<Object>4);

        if (pContent == nullptr)
        {
            pContent = new QMLComplexEntity(pName->position());
            pContent->setIsBlock(true);
        }

        $<Object>$ = new QMLFunction(pName->position(), pName, pParameters, pContent);
    }
    |
    TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock");

        QMLEntity* pParameters = $<Object>2;
        QMLComplexEntity* pContent = dynamic_cast<QMLComplexEntity*>($<Object>3);

        if (pContent == nullptr)
        {
            pContent = new QMLComplexEntity(pContext->position());
            pContent->setIsBlock(true);
        }

        QPoint pPosition;

        if (pParameters != nullptr) pPosition = pParameters->position();
        else pPosition = pContent->position();

        QMLEntity* pName = new QMLIdentifier(pPosition, "");

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

        QMLComplexEntity* pList = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pExpression1 = $<Object>1;
        QMLEntity* pExpression2 = $<Object>3;

        if (pList == nullptr)
        {
            pList = new QMLComplexEntity(pExpression1->position());
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

        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>1);

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
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>2);

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

        QMLEntity* pTypeIdentifier = $<Object>1;
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>($<Object>2);

        SAFE_DELETE(pTypeIdentifier);

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

        QMLEntity* pEntity = $<Object>2;

        pEntity = QMLComplexEntity::makeBlock(pEntity);

        $<Object>$ = pEntity;
    }
;

JSStatements :
    JSStatement
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLEntity* pStatement1 = $<Object>1;

        if (pStatement1 == nullptr)
        {
            pStatement1 = new QMLEntity(pContext->position());
        }

        QMLComplexEntity* pComplex = new QMLComplexEntity(pStatement1->position());

        pComplex->contents() << pStatement1;

        $<Object>$ = pComplex;
    }
    |
    JSStatements JSStatement
    {
        PARSER_TRACE("JSStatements", "JSStatements JSStatement");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pStatement2 = $<Object>2;

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
        QMLEntity* pCondition = $<Object>3;
        QMLEntity* pThen = $<Object>5;

        if (pCondition == nullptr)
        {
            pCondition = new QMLEntity(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLEntity(pContext->position());
        }

        pThen = QMLComplexEntity::makeBlock(pThen);

        $<Object>$ = new QMLIf(pCondition->position(), pCondition, pThen, nullptr);
    }
    |
    TOKEN_IF '(' JSExpression ')' JSStatement TOKEN_ELSE JSStatement
    {
        QMLEntity* pCondition = $<Object>3;
        QMLEntity* pThen = $<Object>5;
        QMLEntity* pElse = $<Object>7;

        if (pCondition == nullptr)
        {
            pCondition = new QMLEntity(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLEntity(pContext->position());
        }

        if (pElse == nullptr)
        {
            pElse = new QMLEntity(pContext->position());
        }

        pThen = QMLComplexEntity::makeBlock(pThen);
        pElse = QMLComplexEntity::makeBlock(pElse);

        $<Object>$ = new QMLIf(pCondition->position(), pCondition, pThen, pElse);
    }
;

JSStatement_For :
    TOKEN_FOR '(' JSVariablesOrExpressionOpt ';' JSExpressionOpt ';' JSExpressionOpt ')' JSStatement
    {
        QMLEntity* pInitialization = $<Object>3;
        QMLEntity* pCondition = $<Object>5;
        QMLEntity* pIncrementation = $<Object>7;
        QMLEntity* pContent = $<Object>9;

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLEntity(pContext->position());
        }

        pContent = QMLComplexEntity::makeBlock(pContent);

        $<Object>$ = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    }
    |
    TOKEN_FOR '(' JSVariablesOrExpressionOpt TOKEN_IN JSExpression ')' JSStatement
    {
        QMLEntity* pVariable = $<Object>3;
        QMLEntity* pExpression = $<Object>5;
        QMLEntity* pContent = $<Object>7;

        if (pVariable == nullptr)
        {
            pVariable = new QMLEntity(pContext->position());
        }

        if (pExpression == nullptr)
        {
            pExpression = new QMLEntity(pContext->position());
        }

        if (pContent == nullptr)
        {
            pContent = new QMLEntity(pContext->position());
        }

        pContent = QMLComplexEntity::makeBlock(pContent);

        $<Object>$ = new QMLForIn(pVariable->position(), pVariable, pExpression, pContent);
    }
;

JSStatement_While :
    TOKEN_WHILE '(' JSExpression ')' JSStatement
    {
        QMLEntity* pInitialization = new QMLEntity(pContext->position());
        QMLEntity* pCondition = $<Object>3;
        QMLEntity* pIncrementation = new QMLEntity(pContext->position());
        QMLEntity* pContent = $<Object>5;

        pContent = QMLComplexEntity::makeBlock(pContent);

        QMLFor* pNewFor = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
        pNewFor->setIsWhile(true);

        $<Object>$ = pNewFor;
    }
;

JSStatement_Switch :
    TOKEN_SWITCH '(' JSExpression ')' JSStatementBlock
    {
        QMLEntity* pExpression = $<Object>3;
        QMLComplexEntity* pCases = dynamic_cast<QMLComplexEntity*>($<Object>5);

        if (pExpression != nullptr && pCases != nullptr)
        {
            QMLEntity* pSwitch = new QMLSwitch(pExpression->position(), pExpression, pCases);

            $<Object>$ = pSwitch;
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
;

JSStatement_Case :
    TOKEN_CASE JSExpression ':'
    {
        QMLEntity* pExpression = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    }
    |
    TOKEN_DEFAULT ':'
    {
        QMLEntity* pExpression = new QMLEntity(pContext->position(), "default");

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
        QMLEntity* pExpression = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    }
    |
    TOKEN_RETURN JSExpressionOpt
    {
        QMLEntity* pExpression = $<Object>2;

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

JSVariablesOrExpressionOpt :
    Empty
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Empty");

        $<Object>$ = $<Object>1;
    }
    |
    JSVariablesOrExpression
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "JSVariablesOrExpression");

        $<Object>$ = $<Object>1;
    }
;

JSVariablesOrExpression :
    TOKEN_VAR JSVariables
    {
        PARSER_TRACE("JSVariablesOrExpression", "TOKEN_VAR JSVariables");

        QMLEntity* pVariable = $<Object>2;
        QMLComplexEntity* pVariables = dynamic_cast<QMLComplexEntity*>($<Object>2);

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

JSVariables :
    JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        QMLEntity* pVariable = $<Object>1;

        QMLComplexEntity* pVariables = new QMLComplexEntity(pVariable->position());
        pVariables->contents() << pVariable;

        $<Object>$ = pVariables;
    }
    |
    JSVariables ',' JSVariable
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        QMLComplexEntity* pVariables = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pVariable = $<Object>3;

        if (pVariables != nullptr)
        {
            pVariables->contents() << pVariable;

            $<Object>$ = pVariables;
        }
        else
        {
            $<Object>$ = nullptr;

            SAFE_DELETE(pVariables);
            SAFE_DELETE(pVariable);
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

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        ENSURE_NON_NULL(pLeft);
        ENSURE_NON_NULL(pRight);

        $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    }
    |
    Identifier TOKEN_ASSIGN JSObject
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSObject");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        ENSURE_NON_NULL(pLeft);
        ENSURE_NON_NULL(pRight);

        $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
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

        QMLEntity* pExpression1 = $<Object>1;
        QMLEntity* pExpression2 = $<Object>3;

        ENSURE_NON_NULL(pExpression1);
        ENSURE_NON_NULL(pExpression2);

        QMLComplexEntity* pComplex = QMLComplexEntity::fromEntity(pExpression1);

        pComplex->setIsArgumentList(true);

        pComplex->contents() << pExpression2;

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

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAddAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSubAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMulAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDivAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSConditionalExpression TOKEN_ASSIGN JSObject
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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

        QMLEntity* pCondition = $<Object>1;
        QMLEntity* pThen = $<Object>3;
        QMLEntity* pElse = $<Object>5;

        if (pCondition == nullptr)
        {
            pCondition = new QMLEntity(pContext->position());
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

        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicAnd);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAnd);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSEqualityExpression TOKEN_OR JSBitwiseAndExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boOr);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSEqualityExpression TOKEN_XOR JSBitwiseAndExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boXor);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEquals);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_EQUALS_CHECK JSEqualityExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS JSEqualityExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEquals);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS_CHECK JSEqualityExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLower);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_LOWER_EQUALS JSAdditiveExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_GREATER JSAdditiveExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreater);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSRelationalExpression TOKEN_GREATER_EQUALS JSAdditiveExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAdd);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSMultiplicativeExpression TOKEN_SUB JSAdditiveExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSub);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMul);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_DIV JSMultiplicativeExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDiv);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_MOD JSMultiplicativeExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMod);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_SHL JSMultiplicativeExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftLeft);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
        }
    }
    |
    JSUnaryExpression TOKEN_SHR JSMultiplicativeExpression
    {
        QMLEntity* pLeft = $<Object>1;
        QMLEntity* pRight = $<Object>3;

        if (pLeft != nullptr && pRight != nullptr)
        {
            $<Object>$ = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftRight);
        }
        else
        {
            $<Object>$ = new QMLEntity(pContext->position());
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

        QMLEntity* pEntity = $<Object>1;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement, true);
    }
    |
    TOKEN_INC JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_INC JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement);
    }
    |
    JSMemberExpression TOKEN_DEC
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_DEC");

        QMLEntity* pEntity = $<Object>1;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement, true);
    }
    |
    TOKEN_DEC JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_DEC JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement);
    }
    |
    TOKEN_NOT JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NOT JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNot);
    }
    |
    TOKEN_NOT_NOT JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NOT_NOT JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNotNot);
    }
    |
    TOKEN_TYPEOF JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_TYPEOF JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoTypeof);
    }
    |
    TOKEN_SUB JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_SUB JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoMinus);
    }
    |
    TOKEN_NEW JSMemberExpression
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NEW JSMemberExpression");

        QMLEntity* pEntity = $<Object>2;

        $<Object>$ = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNew);
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

        QMLEntity* pExpression1 = $<Object>1;
        QMLEntity* pExpression2 = $<Object>3;

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

        QMLEntity* pLeft = $<Object>1;
        QMLArrayAccess* pArrayAccess = dynamic_cast<QMLArrayAccess*>($<Object>1);
        QMLEntity* pIndexer = $<Object>3;

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

        QMLEntity* pName = $<Object>1;
        QMLEntity* pArgument = $<Object>3;
        QMLComplexEntity* pArguments = dynamic_cast<QMLComplexEntity*>($<Object>3);

        if (pArguments == nullptr && pArgument != nullptr)
        {
            pArguments = new QMLComplexEntity(pArgument->position());
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

        QMLEntity* pEntity = $<Object>2;

        pEntity->setIsParenthesized(true);

        $<Object>$ = pEntity;
    }
;

JSArgumentListOpt :
    Empty
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        $<Object>$ = new QMLComplexEntity(pContext->position());
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

        QMLEntity* pArgument = $<Object>1;

        QMLComplexEntity* pList = new QMLComplexEntity(pArgument->position());
        pList->setIsArgumentList(true);

        pList->contents() << pArgument;

        $<Object>$ = pList;
    }
    |
    JSArgumentList ',' JSArgument
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexEntity* pList = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pArgument = $<Object>3;

        pList->contents() << pArgument;

        $<Object>$ = pList;
    }
;

JSArgument:
    TOKEN_PROPERTY
    {
        PARSER_TRACE("JSArgument", "TOKEN_PROPERTY");

        $<Object>$ = new QMLIdentifier(pContext->position(), "property");
    }
    |
    JSObject
    {
        PARSER_TRACE("JSArgument", "JSObject");

        $<Object>$ = $<Object>1;
    }
    |
    JSAssignmentExpression
    {
        PARSER_TRACE("JSArgument", "JSAssignmentExpression");

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

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
        pComplex->setIsObject(true);

        $<Object>$ = pComplex;
    }
    |
    TOKEN_DIMENSION
    {
        PARSER_TRACE("JSObject", "TOKEN_DIMENSION");

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
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

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pEntity = $<Object>3;

        pComplex->contents() << pEntity;

        $<Object>$ = pComplex;
    }
    |
    JSArrayContents ',' JSExpressionSingle
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSExpressionSingle");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pEntity = $<Object>3;

        pComplex->contents() << pEntity;

        $<Object>$ = pComplex;
    }
    |
    JSObject
    {
        PARSER_TRACE("JSArrayContents", "JSObject");

        QMLEntity* pEntity = $<Object>1;

        if (pEntity == nullptr)
            pEntity = new QMLEntity(pContext->position());

        QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pEntity;

        $<Object>$ = pComplex;
    }
    |
    JSExpressionSingle
    {
        PARSER_TRACE("JSArrayContents", "JSExpressionSingle");

        QMLEntity* pEntity = $<Object>1;

        if (pEntity == nullptr)
            pEntity = new QMLEntity(pContext->position());

        QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pEntity;

        $<Object>$ = pComplex;
    }
;

JSAttributes :
    JSAttribute
    {
        PARSER_TRACE("JSAttributes", "JSAttribute");

        QMLEntity* pAttribute1 = $<Object>1;

        QMLComplexEntity* pComplex = new QMLComplexEntity(pAttribute1->position());
        pComplex->setIsObject(true);

        pComplex->contents() << pAttribute1;

        $<Object>$ = pComplex;
    }
    |
    JSAttributes JSAttribute
    {
        PARSER_TRACE("JSAttributes", "JSAttributes JSAttribute");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>($<Object>1);
        QMLEntity* pAttribute2 = $<Object>2;

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

        QMLEntity* pName = $<Object>1;
        QMLEntity* pValue = $<Object>3;

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

        QMLEntity* pName = $<Object>1;
        QMLEntity* pValue = $<Object>3;

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
        PARSER_TRACE("JSAttributeName", "Literal");

        $<Object>$ = $<Object>1;
    }
    |
    Identifier
    {
        PARSER_TRACE("JSAttributeName", "Identifier");

        $<Object>$ = $<Object>1;
    }
;

Identifier :
    TOKEN_IDENTIFIER
    {
        PARSER_TRACE("Identifier", "TOKEN_IDENTIFIER");

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
        PARSER_TRACE("Version", "TOKEN_REALCONSTANT");

        $<Object>$ =  new QMLEntity(pContext->position(), pContext->tokenValue());
    }
;

Value :
    Boolean
    {
        PARSER_TRACE("Value", "Boolean");

        $<Object>$ = $<Object>1;
    }
    |
    Integer
    {
        PARSER_TRACE("Value", "Integer");

        $<Object>$ = $<Object>1;
    }
    |
    Double
    {
        PARSER_TRACE("Value", "Double");

        $<Object>$ = $<Object>1;
    }
    |
    Literal
    {
        PARSER_TRACE("Value", "Literal");

        $<Object>$ = $<Object>1;
    }
    |
    SpecialValue
    {
        PARSER_TRACE("Value", "SpecialValue");

        $<Object>$ = $<Object>1;
    }
;

Boolean :
    TOKEN_BOOLCONSTANT
    {
        $<Object>$ = new QMLEntity(pContext->position(), QVariant($<Boolean>1));
    }
;

Integer :
    TOKEN_INTEGERCONSTANT
    {
        $<Object>$ = new QMLEntity(pContext->position(), QVariant($<Integer>1));
    }
;

Double :
    TOKEN_REALCONSTANT
    {
        $<Object>$ =  new QMLEntity(pContext->position(), QVariant($<Real>1));
    }
;

Literal :
    TOKEN_LITERAL
    {
        QString* pString = $<String>1;

        if (pString != nullptr)
        {
            $<Object>$ = new QMLEntity(pContext->position(), QVariant(*pString));
        }
        else
        {
            $<Object>$ = nullptr;
        }
    }
;

SpecialValue :
    TOKEN_NULL
    {
        $<Object>$ = new QMLSpecialValue(pContext->position(), QMLSpecialValue::svNull);
    }
    |
    TOKEN_UNDEFINED
    {
        $<Object>$ = new QMLSpecialValue(pContext->position(), QMLSpecialValue::svUndefined);
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
