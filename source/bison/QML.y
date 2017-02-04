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

#define SAFE_DELETE(a)  if ((a) != NULL) delete (a);

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
%token TOKEN_COLOR              508
%token TOKEN_FUNCTION           509
%token TOKEN_IF                 510
%token TOKEN_ELSE               511
%token TOKEN_FOR                512
%token TOKEN_WHILE              513
%token TOKEN_BREAK              514
%token TOKEN_CONTINUE           515
%token TOKEN_WITH               516
%token TOKEN_RETURN             517
%token TOKEN_TYPEOF             518
%token TOKEN_PRAGMA             519
%token TOKEN_ON                 520
%token TOKEN_AS                 521

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
        QMLItem* pItem = $<Object>1;

        if (pItem != NULL)
        {
            pContext->item().contents().append(pItem);
        }
    }
    |
    Declarations Declaration
    {
        QMLItem* pItem = $<Object>2;

        if (pItem != NULL)
        {
            pContext->item().contents().append(pItem);
        }
    }
;

Declaration :
    ImportStatement
    {
        $<Object>$ = $<Object>1;
    }
    |
    PragmaStatement
    {
        $<Object>$ = $<Object>1;
    }
    |
    Item
    {
        $<Object>$ = $<Object>1;
    }
    /*
    | error
    {
        yyerror(pContext, QString("Item expected").toLatin1().data());
        YYABORT;
    }
    */
;

ImportStatement :
    TOKEN_IMPORT QualifiedIdentifier Version
    {
        QMLItem* pName = $<Object>2;
        QMLItem* pVersion = $<Object>3;

        if (pName != NULL && pVersion != NULL)
        {
            $<Object>$ = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            $<Object>$ = NULL;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    }
    |
    TOKEN_IMPORT QualifiedIdentifier Version TOKEN_AS Identifier
    {
        QMLItem* pName = $<Object>2;
        QMLItem* pVersion = $<Object>3;

        if (pName != NULL && pVersion != NULL)
        {
            $<Object>$ = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            $<Object>$ = NULL;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    }
    |
    TOKEN_IMPORT Literal
    {
        QMLItem* pName = $<Object>2;

        if (pName != NULL)
        {
            $<Object>$ = new QMLImport(pContext, pName->value().toString(), "");
        }
        else
        {
            $<Object>$ = NULL;
        }

        SAFE_DELETE(pName);
    }
;

PragmaStatement :
    TOKEN_PRAGMA QualifiedIdentifier
    {
        $<Object>$ = NULL;
    }

Item :
    Identifier '{' ItemContents '}'
    {
        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>3);

        if (pComplexItem != NULL)
        {
            pComplexItem->setName(pName);
        }

        $<Object>$ = pComplexItem;
    }
    |
    Identifier '{' '}'
    {
        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = new QMLComplexItem(pName);

        $<Object>$ = pComplexItem;
    }
    |
    Identifier TOKEN_ON Identifier '{' ItemContents '}'
    {
        QMLItem* pName = $<Object>1;
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>5);

        if (pComplexItem != NULL)
        {
            pComplexItem->setName(pName);
        }

        $<Object>$ = pComplexItem;
    }
;

ItemArray :
    '[' ItemContents ']'
    {
        $<Object>$ = $<Object>2;
    }
;

ItemContents :
    ItemContent
    {
        QMLItem* pOldItem = $<Object>1;

        if (pOldItem != NULL)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem();
            pComplexItem->contents().append(pOldItem);

            $<Object>$ = pComplexItem;
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
    |
    ItemContents ItemContent
    {
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pNewItem = $<Object>2;

        if (pComplexItem != NULL && pNewItem != NULL)
        {
            pComplexItem->contents().append(pNewItem);
        }

        $<Object>$ = pComplexItem;
    }
    |
    ItemContents ',' ItemContent
    {
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pNewItem = $<Object>3;

        if (pComplexItem != NULL && pNewItem != NULL)
        {
            pComplexItem->contents().append(pNewItem);
        }

        $<Object>$ = pComplexItem;
    }
;

ItemContent :
    PropertyAssignment
    {
        $<Object>$ = $<Object>1;
    }
    |
    PropertyDeclaration
    {
        $<Object>$ = $<Object>1;
    }
    |
    Item
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSFunction
    {
        $<Object>$ = $<Object>1;
    }
;

PropertyDeclaration :
    PropertyDeclarationNoColon
    {
        $<Object>$ = $<Object>1;
    }
    |
    PropertyDeclarationNoColon ';'
    {
        $<Object>$ = $<Object>1;
    }
;

PropertyDeclarationNoColon :
    TOKEN_PROPERTY PropertyType Identifier
    {
        QMLType* pType = dynamic_cast<QMLType*>($<Object>2);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);

        if (pType != NULL && pName != NULL)
        {
            $<Object>$ = new QMLPropertyDeclaration(pType, pName);
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
    |
    TOKEN_PROPERTY PropertyType Identifier ':' PropertyContent
    {
        QMLType* pType = dynamic_cast<QMLType*>($<Object>2);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>5);

        if (pType != NULL && pName != NULL)
        {
            $<Object>$ = new QMLPropertyDeclaration(pType, pName, pData);
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
    |
    TOKEN_PROPERTY TOKEN_COLOR Identifier ':' PropertyContent
    {
        QMLType* pType = new QMLType(QVariant::Color);
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>5);

        if (pType != NULL && pName != NULL)
        {
            $<Object>$ = new QMLPropertyDeclaration(pType, pName, pData);
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
    |
    TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent
    {
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>3);
        QMLItem* pData = dynamic_cast<QMLItem*>($<Object>5);

        if (pName != NULL)
        {
            $<Object>$ = new QMLPropertyAlias(pName, pData);
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
;

PropertyType :
    TOKEN_VAR
    {
        $<Object>$ = new QMLType((QVariant::Type) 0);
    }
    |
    TOKEN_BOOL
    {
        $<Object>$ = new QMLType(QVariant::Bool);
    }
    |
    TOKEN_INT
    {
        $<Object>$ = new QMLType(QVariant::Int);
    }
    |
    TOKEN_REAL
    {
        $<Object>$ = new QMLType(QVariant::Double);
    }
    |
    TOKEN_STRING
    {
        $<Object>$ = new QMLType(QVariant::String);
    }
;

PropertyAssignment :
    QualifiedIdentifier ':' PropertyContent
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pContent = $<Object>3;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName, pContent);

        $<Object>$ = pAssignment;
    }
    |
    TOKEN_PROPERTY ':' PropertyContent
    {
        QMLItem* pContent = $<Object>3;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_PROPERTY)), pContent);

        $<Object>$ = pAssignment;
    }
    |
    TOKEN_COLOR ':' PropertyContent
    {
        QMLItem* pContent = $<Object>3;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_COLOR)), pContent);

        $<Object>$ = pAssignment;
    }
    |
    QualifiedIdentifier '.' TOKEN_COLOR ':' PropertyContent
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pContent = $<Object>5;
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName, pContent);

        $<Object>$ = pAssignment;
    }
;

PropertyContent :
    Item
    {
        $<Object>$ = $<Object>1;
    }
    |
    ItemArray
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSArrayInitializerBlock
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSONObject
    {
        $<Object>$ = $<Object>1;
    }
;

JSFunction :
    TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock
    {
        QMLItem* pName = dynamic_cast<QMLItem*>($<Object>2);
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>($<Object>3);
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>($<Object>4);

        $<Object>$ = new QMLFunction(pName, pParameters, pContent);
    }

JSFunctionParameterList :
    '(' JSFunctionParameters ')'
    {
        $<Object>$ = $<Object>2;
    }
    | '(' ')'
    {
        $<Object>$ = NULL;
    }
;

JSFunctionParameters :
    JSFunctionParameter
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSFunctionParameters JSFunctionParameter
    {
        SAFE_DELETE($<Object>2);

        $<Object>$ = $<Object>1;
    }
;

JSFunctionParameter :
    Identifier
    {
        $<Object>$ = $<Object>1;
    }

JSStatementBlock :
    '{' JSStatements '}'
    {
        $<Object>$ = $<Object>2;
    }
;

JSStatements :
    JSStatement
    {
        QMLItem* pStatement1 = $<Object>1;
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pStatement1);

        $<Object>$ = pComplex;
    }
    |
    JSStatements JSStatement
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pStatement2 = $<Object>2;

        if (pComplex != NULL)
        {
            pComplex->contents().append(pStatement2);
        }

        $<Object>$ = pComplex;
    }
;

JSStatement :
    JSStatementNoColon
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatementNoColon ';'
    {
        $<Object>$ = $<Object>1;
    }
;

JSStatementNoColon :
    JSStatementBlock
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSVariablesOrExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_If
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_For
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_While
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Break
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Continue
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_With
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSStatement_Return
    {
        $<Object>$ = $<Object>1;
    }
;

JSStatement_If :
    TOKEN_IF '(' JSExpression ')' JSStatement
    {
        QMLItem* pCondition = $<Object>3;
        QMLItem* pThen = $<Object>5;

        $<Object>$ = new QMLIf(pCondition, pThen, NULL);
    }
    |
    TOKEN_IF '(' JSExpression ')' JSStatement TOKEN_ELSE JSStatement
    {
        QMLItem* pCondition = $<Object>3;
        QMLItem* pThen = $<Object>5;
        QMLItem* pElse = $<Object>7;

        $<Object>$ = new QMLIf(pCondition, pThen, pElse);
    }
;

JSStatement_For :
    TOKEN_FOR '(' JSVariablesOrExpressionOpt ';' JSExpressionOpt ';' JSExpressionOpt ')' JSStatement
    {
        QMLItem* pInitialization = $<Object>3;
        QMLItem* pCondition = $<Object>5;
        QMLItem* pIncrementation = $<Object>7;
        QMLItem* pContent = $<Object>9;

        $<Object>$ = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    }
;

JSStatement_While :
    TOKEN_WHILE '(' JSExpression ')' JSStatement
    {
        QMLItem* pInitialization = NULL;
        QMLItem* pCondition = $<Object>3;
        QMLItem* pIncrementation = NULL;
        QMLItem* pContent = $<Object>5;

        $<Object>$ = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    }
;

JSStatement_Break :
    TOKEN_BREAK
    {
        $<Object>$ = NULL;
    }
;

JSStatement_Continue :
    TOKEN_CONTINUE
    {
        $<Object>$ = NULL;
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
        $<Object>$ = NULL;
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
        $<Object>$ = NULL;
    }
    |
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

JSVariables :
    JSVariable
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSVariables ',' JSVariable
    {
        SAFE_DELETE($<Object>3);

        $<Object>$ = $<Object>1;
    }
;

JSVariable :
    Identifier
    {
        $<Object>$ = $<Object>1;
    }
    |
    Identifier TOKEN_ASSIGN JSAssignmentExpression
    {
        SAFE_DELETE($<Object>3);

        $<Object>$ = $<Object>1;
    }
;

JSExpression :
    JSAssignmentExpression
    {
        QMLItem* pExpression1 = $<Object>1;
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pExpression1);

        $<Object>$ = pComplex;
    }
    |
    JSAssignmentExpression ',' JSExpression
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression2 = $<Object>2;

        if (pComplex != NULL)
        {
            pComplex->contents().append(pExpression2);
        }

        $<Object>$ = pComplex;
    }
;

JSAssignmentExpression :
    JSConditionalExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    }
;

JSConditionalExpression :
    JSOrExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression
    {
        QMLItem* pCondition = $<Object>1;
        QMLItem* pThen = $<Object>3;
        QMLItem* pElse = $<Object>5;

        $<Object>$ = new QMLConditional(pCondition, pThen, pElse);
    }
;

JSOrExpression :
    JSAndExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSAndExpression TOKEN_LOGICAL_OR JSOrExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicOr);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicAnd);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAnd);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEquals);
    }
    |
    JSRelationalExpression TOKEN_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEquals);
    }
    |
    JSRelationalExpression TOKEN_NOT_EQUALS_CHECK JSEqualityExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLower);
    }
    |
    JSRelationalExpression TOKEN_LOWER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
    }
    |
    JSRelationalExpression TOKEN_GREATER JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreater);
    }
    |
    JSRelationalExpression TOKEN_GREATER_EQUALS JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAdd);
    }
    |
    JSMultiplicativeExpression TOKEN_SUB JSAdditiveExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boSub);
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

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMul);
    }
    |
    JSUnaryExpression TOKEN_DIV JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boDiv);
    }
    |
    JSUnaryExpression TOKEN_SHL JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftLeft);
    }
    |
    JSUnaryExpression TOKEN_SHR JSMultiplicativeExpression
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRight = $<Object>3;

        $<Object>$ = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftRight);
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
    JSFunctionCall
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSFunctionCall '.' JSMemberExpression
    {
        QMLIdentifier* pIdentifier1 = dynamic_cast<QMLIdentifier*>($<Object>1);
        QMLIdentifier* pIdentifier2 = dynamic_cast<QMLIdentifier*>($<Object>3);

        if (pIdentifier1 != NULL && pIdentifier2 != NULL)
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

            if (pExpression == NULL)
            {
                pExpression = new QMLQualifiedExpression();
                pExpression->contents().append(pExpression1);
            }

            pExpression->contents().append(pExpression2);

            $<Object>$ = pExpression;
        }
    }
    |
    JSFunctionCall '[' JSExpression ']'
    {
        $<Object>$ = $<Object>1;
    }
;

JSFunctionCall :
    JSPrimaryExpression
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSPrimaryExpression '(' JSArgumentListOpt ')'
    {
        QMLItem* pName = $<Object>1;
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>($<Object>3);

        $<Object>$ = new QMLFunctionCall(pName, pArguments);
    }
;

JSPrimaryExpression :
    Identifier
    {
        $<Object>$ = $<Object>1;
    }
    |
    Value
    {
        $<Object>$ = $<Object>1;
    }
    |
    '(' JSExpression ')'
    {
        $<Object>$ = $<Object>2;
    }
;

JSArgumentListOpt :
    Empty
    {
        $<Object>$ = NULL;
    }
    |
    JSArgumentList
    {
        $<Object>$ = $<Object>1;
    }
;

JSArgumentList :
    JSAssignmentExpression
    {
        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression1 = $<Object>1;

        if (pList == NULL)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        $<Object>$ = pList;
    }
    |
    JSInitializerBlock
    {
        $<Object>$ = NULL;
    }
    |
    JSArgumentList ',' JSAssignmentExpression
    {
        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pExpression1 = $<Object>1;
        QMLItem* pExpression2 = $<Object>3;

        if (pList == NULL)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        pList->contents().append(pExpression2);

        $<Object>$ = pList;
    }
    |
    JSArgumentList ',' JSInitializerBlock
    {
        $<Object>$ = NULL;
    }
;

JSInitializerBlock :
    '{' JSInitializers '}'
    {
        $<Object>$ = NULL;
    }
;

JSInitializers :
    JSInitializer
    {
        $<Object>$ = NULL;
    }
    |
    JSInitializers ',' JSInitializer
    {
        $<Object>$ = NULL;
    }
;

JSInitializer :
    PropertyAssignment
    {
    }
;

JSArrayInitializerBlock :
    '[' JSArrayInitializers ']'
    {
        $<Object>$ = $<Object>2;
    }
;

JSArrayInitializers :
    JSArrayInitializer
    {
        $<Object>$ = NULL;
    }
    |
    JSArrayInitializers ',' JSArrayInitializer
    {
        $<Object>$ = NULL;
    }
;

JSArrayInitializer :
    Value
    {
    }
;

JSIncrementOperator :
    TOKEN_INC
    {
        $<Object>$ = NULL;
    }
    |
    TOKEN_DEC
    {
        $<Object>$ = NULL;
    }
;

JSUnaryOperator :
    TOKEN_NOT
    {
        $<Object>$ = NULL;
    }
    |
    TOKEN_TYPEOF
    {
        $<Object>$ = NULL;
    }
;

JSONObject :
    '{' JSONAttributes '}'
    {
        $<Object>$ = $<Object>2;
    }
    |
    '{' '}'
    {
        $<Object>$ = NULL;
    }
;

JSONAttributes :
    JSONAttribute
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSONAttributes JSONAttribute
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>($<Object>1);
        QMLItem* pAttribute1 = $<Object>1;
        QMLItem* pAttribute2 = $<Object>2;

        if (pComplex == NULL)
        {
            pComplex = new QMLComplexItem();
            pComplex->contents().append(pAttribute1);
        }

        pComplex->contents().append(pAttribute2);

        $<Object>$ = pComplex;
    }
;

JSONAttribute :
    JSONAttributeNoComma
    {
        $<Object>$ = $<Object>1;
    }
    |
    JSONAttributeNoComma ','
    {
        $<Object>$ = $<Object>1;
    }
;

JSONAttributeNoComma :
    Literal ':' Value
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != NULL && pValue != NULL)
        {
            $<Object>$ = new QMLNameValue(pName->value().value<QString>(), pValue->value());
        }
        else
        {
            $<Object>$ = NULL;
        }

        SAFE_DELETE($<Object>1);
        SAFE_DELETE($<Object>3);
    }
    |
    Literal ':' JSONObject
    {
        QMLItem* pName = $<Object>1;
        QMLItem* pValue = $<Object>3;

        if (pName != NULL && pValue != NULL)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName);

            pComplex->contents().append(pValue);

            $<Object>$ = pComplex;
        }
        else
        {
            $<Object>$ = NULL;
        }
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
    |
    QualifiedIdentifier '.' TOKEN_COLOR
    {
        QMLItem* pLeft = $<Object>1;
        QMLItem* pRite = $<Object>3;

        pLeft->setValue(pLeft->value().toString() + QString(".") + QString(TOKEN_COLOR));

        $<Object>$ = pLeft;
    }
;

Identifier :
    TOKEN_IDENTIFIER
    {
        QString* pString = $<String>1;

        if (pString != NULL)
        {
            $<Object>$ = new QMLIdentifier(*pString);
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
;

Version :
    TOKEN_REALCONSTANT
    {
        $<Object>$ =  new QMLItem(pContext->tokenValue());
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
        $<Object>$ = new QMLItem(QVariant($<Boolean>1));
    }
;

Integer :
    TOKEN_INTEGERCONSTANT
    {
        $<Object>$ = new QMLItem(QVariant($<Integer>1));
    }
;

Double :
    TOKEN_REALCONSTANT
    {
        $<Object>$ =  new QMLItem(QVariant($<Real>1));
    }
;

Literal :
    TOKEN_LITERAL
    {
        QString* pString = $<String>1;

        if (pString != NULL)
        {
            $<Object>$ = new QMLItem(QVariant(*pString));
        }
        else
        {
            $<Object>$ = NULL;
        }
    }
;

Empty :
    {
        $<Object>$ = NULL;
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
