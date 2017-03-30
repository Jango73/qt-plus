
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 9 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"

#include <QDebug>
#include <stdio.h>
#include "QMLEntity.h"
#include "QMLComplexEntity.h"
#include "QMLNameValue.h"
#include "QMLIdentifier.h"
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



/* Line 189 of yacc.c  */
#line 116 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_IDENTIFIER = 300,
     TOKEN_LITERAL = 301,
     TOKEN_BOOLCONSTANT = 302,
     TOKEN_INTEGERCONSTANT = 303,
     TOKEN_REALCONSTANT = 304,
     TOKEN_ASSIGN = 310,
     TOKEN_ADD = 311,
     TOKEN_SUB = 312,
     TOKEN_MUL = 313,
     TOKEN_DIV = 314,
     TOKEN_MOD = 315,
     TOKEN_AND = 316,
     TOKEN_OR = 317,
     TOKEN_XOR = 318,
     TOKEN_SHL = 319,
     TOKEN_SHR = 320,
     TOKEN_ADD_ASSIGN = 321,
     TOKEN_SUB_ASSIGN = 322,
     TOKEN_MUL_ASSIGN = 323,
     TOKEN_DIV_ASSIGN = 324,
     TOKEN_MOD_ASSIGN = 325,
     TOKEN_AND_ASSIGN = 326,
     TOKEN_OR_ASSIGN = 327,
     TOKEN_XOR_ASSIGN = 328,
     TOKEN_SHL_ASSIGN = 329,
     TOKEN_SHR_ASSIGN = 330,
     TOKEN_LOWER = 331,
     TOKEN_GREATER = 332,
     TOKEN_LOWER_EQUALS = 333,
     TOKEN_GREATER_EQUALS = 334,
     TOKEN_EQUALS = 335,
     TOKEN_EQUALS_CHECK = 336,
     TOKEN_NOT_EQUALS = 337,
     TOKEN_NOT_EQUALS_CHECK = 338,
     TOKEN_LOGICAL_AND = 339,
     TOKEN_LOGICAL_OR = 340,
     TOKEN_NOT = 341,
     TOKEN_NOT_NOT = 342,
     TOKEN_INC = 343,
     TOKEN_DEC = 344,
     TOKEN_COMPLEMENT = 345,
     TOKEN_DIMENSION = 346,
     TOKEN_IMPORT = 500,
     TOKEN_PROPERTY = 501,
     TOKEN_DEFAULT = 502,
     TOKEN_READ_ONLY = 503,
     TOKEN_ALIAS = 504,
     TOKEN_VAR = 505,
     TOKEN_BOOL = 506,
     TOKEN_INT = 507,
     TOKEN_REAL = 508,
     TOKEN_STRING = 509,
     TOKEN_VARIANT = 510,
     TOKEN_COLOR = 511,
     TOKEN_FUNCTION = 512,
     TOKEN_IF = 513,
     TOKEN_ELSE = 514,
     TOKEN_FOR = 515,
     TOKEN_IN = 516,
     TOKEN_WHILE = 517,
     TOKEN_SWITCH = 518,
     TOKEN_CASE = 519,
     TOKEN_BREAK = 520,
     TOKEN_CONTINUE = 521,
     TOKEN_WITH = 522,
     TOKEN_RETURN = 523,
     TOKEN_TYPEOF = 524,
     TOKEN_PRAGMA = 525,
     TOKEN_ON = 526,
     TOKEN_AS = 527,
     TOKEN_SIGNAL = 528,
     TOKEN_NEW = 529
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 51 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLEntity*  Object;



/* Line 214 of yacc.c  */
#line 236 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 248 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   664

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNRULES -- Number of states.  */
#define YYNSTATES  332

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   530

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      82,    83,     2,     2,    77,     2,    85,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    78,
       2,     2,     2,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     6,     7,     2,     2,     2,     2,     2,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    24,    30,    33,    38,    41,    46,    50,    57,    59,
      62,    66,    68,    70,    72,    74,    76,    78,    81,    86,
      91,    96,   103,   110,   117,   124,   126,   128,   130,   132,
     137,   141,   143,   145,   147,   149,   153,   155,   159,   161,
     164,   167,   171,   176,   180,   184,   187,   189,   193,   195,
     198,   201,   205,   209,   211,   214,   216,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   241,   247,
     255,   265,   273,   279,   285,   289,   292,   294,   296,   302,
     305,   308,   310,   312,   314,   316,   319,   321,   323,   327,
     329,   333,   337,   339,   343,   345,   347,   351,   355,   359,
     363,   367,   371,   373,   375,   377,   383,   385,   387,   391,
     393,   397,   399,   403,   407,   411,   413,   417,   421,   425,
     429,   431,   435,   439,   443,   447,   449,   453,   457,   459,
     463,   467,   471,   475,   479,   481,   484,   487,   490,   493,
     496,   499,   502,   505,   508,   510,   514,   516,   521,   523,
     528,   530,   532,   536,   538,   540,   542,   546,   548,   550,
     552,   556,   559,   561,   565,   569,   573,   575,   577,   579,
     582,   584,   587,   591,   595,   597,   599,   601,   605,   607,
     609,   611,   613,   615,   617,   619,   621,   623,   625
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    89,    -1,    88,    89,    -1,
       1,    -1,    90,    -1,    91,    -1,    92,    -1,   105,    -1,
      45,   153,   155,    -1,    45,   153,   155,    72,   154,    -1,
      45,   160,    -1,    45,   160,    72,   154,    -1,    70,   153,
      -1,   154,    75,    93,    76,    -1,   154,    75,    76,    -1,
     154,    71,   154,    75,    93,    76,    -1,    94,    -1,    93,
      94,    -1,    93,    77,    94,    -1,    95,    -1,    99,    -1,
      92,    -1,   105,    -1,   103,    -1,    96,    -1,    96,    78,
      -1,    97,    46,   154,    46,    -1,    97,    46,   154,   154,
      -1,    97,    46,    50,   154,    -1,    97,    46,   154,    46,
      79,   100,    -1,    97,    46,   154,   154,    79,   100,    -1,
      97,    46,    50,   154,    79,   100,    -1,    97,    46,    49,
     154,    79,   100,    -1,   161,    -1,    98,    -1,    47,    -1,
      48,    -1,    97,    46,    79,   100,    -1,   153,    79,   100,
      -1,    92,    -1,   101,    -1,   111,    -1,   147,    -1,    80,
     102,    81,    -1,    92,    -1,   102,    77,    92,    -1,   104,
      -1,   104,    78,    -1,    73,   154,    -1,    73,   154,   106,
      -1,    57,   154,   106,   109,    -1,    57,   106,   109,    -1,
      82,   107,    83,    -1,    82,    83,    -1,   108,    -1,   107,
      77,   108,    -1,   154,    -1,    50,   154,    -1,   154,   154,
      -1,    75,   161,    76,    -1,    75,   110,    76,    -1,   111,
      -1,   110,   111,    -1,   112,    -1,   112,    78,    -1,   109,
      -1,   124,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,   121,
      -1,    58,    82,   127,    83,   111,    -1,    58,    82,   127,
      83,   111,    59,   111,    -1,    60,    82,   123,    78,   122,
      78,   122,    83,   111,    -1,    60,    82,   123,    61,   127,
      83,   111,    -1,    62,    82,   127,    83,   111,    -1,    63,
      82,   127,    83,   109,    -1,    64,   127,    79,    -1,    47,
      79,    -1,    65,    -1,    66,    -1,    67,    82,   127,    83,
     111,    -1,    68,   147,    -1,    68,   122,    -1,   161,    -1,
     127,    -1,   161,    -1,   124,    -1,    50,   125,    -1,   127,
      -1,   126,    -1,   125,    77,   126,    -1,   154,    -1,   154,
       8,   129,    -1,   154,     8,   147,    -1,   128,    -1,   128,
      77,   127,    -1,   129,    -1,   131,    -1,   131,     8,   129,
      -1,   131,    19,   129,    -1,   131,    20,   129,    -1,   131,
      21,   129,    -1,   131,    22,   129,    -1,   131,     8,   147,
      -1,   129,    -1,   147,    -1,   132,    -1,   132,    84,   130,
      79,   130,    -1,   105,    -1,   133,    -1,   133,    38,   132,
      -1,   134,    -1,   134,    37,   133,    -1,   135,    -1,   135,
      14,   134,    -1,   135,    15,   134,    -1,   135,    16,   134,
      -1,   136,    -1,   136,    33,   135,    -1,   136,    34,   135,
      -1,   136,    35,   135,    -1,   136,    36,   135,    -1,   137,
      -1,   136,    29,   137,    -1,   136,    31,   137,    -1,   136,
      30,   137,    -1,   136,    32,   137,    -1,   138,    -1,   138,
       9,   137,    -1,   138,    10,   137,    -1,   139,    -1,   139,
      11,   138,    -1,   139,    12,   138,    -1,   139,    13,   138,
      -1,   139,    17,   138,    -1,   139,    18,   138,    -1,   140,
      -1,   140,    41,    -1,    41,   140,    -1,   140,    42,    -1,
      42,   140,    -1,    39,   140,    -1,    40,   140,    -1,    69,
     140,    -1,    10,   140,    -1,    74,   140,    -1,   141,    -1,
     141,    85,   140,    -1,   142,    -1,   141,    80,   127,    81,
      -1,   143,    -1,   143,    82,   144,    83,    -1,   154,    -1,
     156,    -1,    82,   127,    83,    -1,   161,    -1,   145,    -1,
     146,    -1,   145,    77,   146,    -1,    46,    -1,   147,    -1,
     129,    -1,    75,   149,    76,    -1,    75,    76,    -1,    44,
      -1,    80,   148,    81,    -1,   148,    77,   147,    -1,   148,
      77,   128,    -1,   147,    -1,   128,    -1,   150,    -1,   149,
     150,    -1,   151,    -1,   151,    77,    -1,   152,    79,   147,
      -1,   152,    79,   128,    -1,   160,    -1,   154,    -1,   154,
      -1,   153,    85,   154,    -1,     3,    -1,     7,    -1,   157,
      -1,   158,    -1,   159,    -1,   160,    -1,     5,    -1,     6,
      -1,     7,    -1,     4,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   154,   166,   178,   185,   192,   199,   206,
     215,   233,   252,   268,   288,   299,   318,   337,   367,   386,
     401,   418,   425,   432,   439,   446,   455,   462,   471,   497,
     523,   546,   574,   602,   627,   652,   657,   664,   669,   676,
     698,   722,   729,   736,   743,   752,   761,   781,   806,   813,
     822,   845,   870,   887,   912,   919,   928,   935,   958,   978,
     998,  1023,  1030,  1043,  1061,  1078,  1085,  1094,  1101,  1108,
    1115,  1122,  1129,  1136,  1143,  1150,  1157,  1164,  1173,  1193,
    1222,  1239,  1267,  1281,  1300,  1307,  1316,  1323,  1330,  1337,
    1344,  1353,  1358,  1365,  1372,  1381,  1409,  1418,  1430,  1454,
    1461,  1474,  1489,  1496,  1517,  1524,  1531,  1548,  1565,  1582,
    1599,  1616,  1635,  1640,  1647,  1654,  1670,  1679,  1686,  1705,
    1710,  1727,  1732,  1747,  1762,  1779,  1784,  1799,  1814,  1829,
    1846,  1851,  1866,  1881,  1896,  1913,  1918,  1933,  1950,  1955,
    1970,  1985,  2000,  2015,  2032,  2037,  2046,  2053,  2062,  2069,
    2076,  2083,  2090,  2097,  2106,  2113,  2135,  2142,  2162,  2169,
    2188,  2195,  2202,  2215,  2222,  2231,  2245,  2259,  2264,  2269,
    2276,  2283,  2293,  2303,  2312,  2324,  2336,  2352,  2370,  2384,
    2398,  2405,  2414,  2437,  2462,  2467,  2474,  2483,  2499,  2515,
    2522,  2527,  2532,  2537,  2544,  2551,  2558,  2565,  2581
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_IDENTIFIER", "TOKEN_LITERAL",
  "TOKEN_BOOLCONSTANT", "TOKEN_INTEGERCONSTANT", "TOKEN_REALCONSTANT",
  "TOKEN_ASSIGN", "TOKEN_ADD", "TOKEN_SUB", "TOKEN_MUL", "TOKEN_DIV",
  "TOKEN_MOD", "TOKEN_AND", "TOKEN_OR", "TOKEN_XOR", "TOKEN_SHL",
  "TOKEN_SHR", "TOKEN_ADD_ASSIGN", "TOKEN_SUB_ASSIGN", "TOKEN_MUL_ASSIGN",
  "TOKEN_DIV_ASSIGN", "TOKEN_MOD_ASSIGN", "TOKEN_AND_ASSIGN",
  "TOKEN_OR_ASSIGN", "TOKEN_XOR_ASSIGN", "TOKEN_SHL_ASSIGN",
  "TOKEN_SHR_ASSIGN", "TOKEN_LOWER", "TOKEN_GREATER", "TOKEN_LOWER_EQUALS",
  "TOKEN_GREATER_EQUALS", "TOKEN_EQUALS", "TOKEN_EQUALS_CHECK",
  "TOKEN_NOT_EQUALS", "TOKEN_NOT_EQUALS_CHECK", "TOKEN_LOGICAL_AND",
  "TOKEN_LOGICAL_OR", "TOKEN_NOT", "TOKEN_NOT_NOT", "TOKEN_INC",
  "TOKEN_DEC", "TOKEN_COMPLEMENT", "TOKEN_DIMENSION", "TOKEN_IMPORT",
  "TOKEN_PROPERTY", "TOKEN_DEFAULT", "TOKEN_READ_ONLY", "TOKEN_ALIAS",
  "TOKEN_VAR", "TOKEN_BOOL", "TOKEN_INT", "TOKEN_REAL", "TOKEN_STRING",
  "TOKEN_VARIANT", "TOKEN_COLOR", "TOKEN_FUNCTION", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_IN", "TOKEN_WHILE", "TOKEN_SWITCH",
  "TOKEN_CASE", "TOKEN_BREAK", "TOKEN_CONTINUE", "TOKEN_WITH",
  "TOKEN_RETURN", "TOKEN_TYPEOF", "TOKEN_PRAGMA", "TOKEN_ON", "TOKEN_AS",
  "TOKEN_SIGNAL", "TOKEN_NEW", "'{'", "'}'", "','", "';'", "':'", "'['",
  "']'", "'('", "')'", "'?'", "'.'", "$accept", "File", "Declarations",
  "Declaration", "ImportStatement", "PragmaStatement", "Item",
  "ItemContents", "ItemContent", "PropertyDeclaration",
  "PropertyDeclarationNoColon", "PropertyModifiersOpt",
  "PropertyModifiers", "PropertyAssignment", "PropertyContent",
  "ItemArray", "ItemArrayContents", "SignalDeclaration",
  "SignalDeclarationNoColon", "JSFunction", "JSFunctionParameterList",
  "JSFunctionParameters", "JSFunctionParameter", "JSStatementBlock",
  "JSStatements", "JSStatement", "JSStatementNoColon", "JSStatement_If",
  "JSStatement_For", "JSStatement_While", "JSStatement_Switch",
  "JSStatement_Case", "JSStatement_Break", "JSStatement_Continue",
  "JSStatement_With", "JSStatement_Return", "JSExpressionOpt",
  "JSVariablesOrExpressionOpt", "JSVariablesOrExpression", "JSVariables",
  "JSVariable", "JSExpression", "JSExpressionSingle",
  "JSAssignmentExpression", "JSAssignmentExpressionOrJSObject",
  "JSConditionalExpression", "JSOrExpression", "JSAndExpression",
  "JSBitwiseAndExpression", "JSEqualityExpression",
  "JSRelationalExpression", "JSAdditiveExpression",
  "JSMultiplicativeExpression", "JSUnaryExpression", "JSMemberExpression",
  "JSArrayAccessExpression", "JSFunctionCall", "JSPrimaryExpression",
  "JSArgumentListOpt", "JSArgumentList", "JSArgument", "JSObject",
  "JSArrayContents", "JSAttributes", "JSAttribute", "JSAttributeNoComma",
  "JSAttributeName", "QualifiedIdentifier", "Identifier", "Version",
  "Value", "Boolean", "Integer", "Double", "Literal", "Empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   530,   300,   301,   302,   303,   304,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   123,   125,    44,    59,    58,
      91,    93,    40,    41,    63,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    90,    91,    92,    92,    92,    93,    93,
      93,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   116,   117,   117,   118,   119,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   126,   127,   127,   128,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     136,   136,   136,   136,   136,   137,   137,   137,   138,   138,
     138,   138,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   145,   146,   146,   146,
     147,   147,   147,   147,   148,   148,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   155,
     156,   156,   156,   156,   157,   158,   159,   160,   161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     5,     2,     4,     2,     4,     3,     6,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     6,     6,     6,     6,     1,     1,     1,     1,     4,
       3,     1,     1,     1,     1,     3,     1,     3,     1,     2,
       2,     3,     4,     3,     3,     2,     1,     3,     1,     2,
       2,     3,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     7,
       9,     7,     5,     5,     3,     2,     1,     1,     5,     2,
       2,     1,     1,     1,     1,     2,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     5,     1,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     3,     1,     4,     1,     4,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     2,     1,     3,     3,     3,     1,     1,     1,     2,
       1,     2,     3,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   188,     0,     0,     0,     0,     2,     3,     6,
       7,     8,     9,     0,   197,     0,   186,    12,     0,     0,
       0,    14,     1,     4,     0,   198,   189,     0,    10,     0,
       0,    55,     0,    56,    58,   198,    53,     0,     0,    37,
      38,     0,    16,    23,   198,    18,    21,    26,     0,    36,
      22,    25,    48,    24,     0,   186,    35,   187,     0,    13,
      59,     0,    54,    60,   194,   195,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,     0,   198,     0,     0,     0,   116,    67,     0,    63,
      65,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      68,    96,   102,   104,   105,   114,   117,   119,   121,   125,
     130,   135,   138,   144,   154,   156,   158,   160,   161,   190,
     191,   192,   193,     0,    52,   198,    50,    15,   198,    19,
      27,     0,    49,     0,    11,    57,   152,   149,   150,   146,
     148,    85,    95,    97,    99,     0,   198,     0,     0,     0,
       0,   172,     0,     0,    90,    92,    89,    91,   151,   153,
       0,    62,    64,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   147,     0,     0,   198,    61,   198,    51,    20,
       0,     0,     0,     0,     0,     0,    41,    40,    42,    43,
      44,   160,     0,     0,     0,     0,    94,    93,     0,     0,
      84,     0,   171,     0,   178,   180,     0,   185,   184,   177,
     176,     0,   162,   103,   106,   111,   107,   108,   109,   110,
     112,     0,   113,   118,   120,   122,   123,   124,   131,   133,
     132,   134,   126,   127,   128,   129,   136,   137,   139,   140,
     141,   142,   143,     0,   155,   167,   169,     0,   164,   165,
     168,   163,    17,     0,    30,    39,    28,    29,   160,   193,
      46,     0,    98,   100,   101,     0,     0,   198,     0,     0,
       0,   170,   179,   181,     0,     0,   173,     0,   157,   159,
       0,     0,     0,     0,     0,     0,    45,    78,     0,     0,
      82,    83,    88,   183,   182,   175,   174,   115,   166,    34,
      33,    31,    32,    47,     0,     0,   198,    79,    81,     0,
       0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,   206,    44,    45,    46,
      47,    48,    49,    50,   207,   208,   281,    51,    52,    86,
      19,    32,    33,    87,    88,   209,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   154,   215,   100,   142,
     143,   101,   102,   103,   241,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   267,   268,
     269,   210,   231,   223,   224,   225,   226,    54,   117,    28,
     118,   119,   120,   121,   122,    56
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -274
static const yytype_int16 yypact[] =
{
      77,  -274,  -274,    93,    20,    32,    43,   154,  -274,  -274,
    -274,  -274,  -274,    74,  -274,    29,  -274,   -40,    18,   -13,
     -10,    59,  -274,  -274,    32,   171,  -274,    32,    31,    32,
      32,  -274,    -8,  -274,    32,   415,  -274,   -13,    79,  -274,
    -274,    32,  -274,  -274,   113,  -274,  -274,    78,    62,  -274,
    -274,  -274,    84,  -274,     4,    74,  -274,  -274,    32,  -274,
    -274,    37,  -274,  -274,  -274,  -274,  -274,    60,    60,    60,
      60,    60,    88,    32,    90,    91,    94,    98,   568,  -274,
    -274,    99,   488,    60,    60,   568,  -274,  -274,   317,  -274,
     107,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,   100,  -274,   217,   103,   150,   155,   272,   233,
    -274,   126,   106,   117,    24,  -274,   114,  -274,  -274,  -274,
    -274,  -274,  -274,   132,  -274,   136,   -10,  -274,   136,  -274,
    -274,    36,  -274,   268,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,   145,  -274,   219,   568,   508,   568,   568,   152,
     568,  -274,    56,   488,  -274,  -274,  -274,  -274,  -274,  -274,
     151,  -274,  -274,  -274,   568,   488,   568,   568,   568,   568,
     488,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,  -274,  -274,   568,    60,   464,  -274,   118,  -274,  -274,
      32,    32,   268,    30,   366,   488,  -274,  -274,  -274,  -274,
    -274,    74,    32,   488,   162,   -24,  -274,  -274,   163,   167,
    -274,   168,  -274,    67,  -274,   156,   174,  -274,  -274,  -274,
    -274,   -35,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,   175,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,   177,  -274,  -274,  -274,   173,   182,  -274,
    -274,  -274,  -274,   191,   197,  -274,   198,   200,   210,   211,
    -274,    69,  -274,  -274,  -274,   415,   568,   568,   415,   -13,
     415,  -274,  -274,  -274,   488,   488,  -274,   488,  -274,  -274,
     464,   268,   268,   268,   268,    32,  -274,   237,   215,   221,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,   415,   415,   568,  -274,  -274,   228,
     415,  -274
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -274,  -274,  -274,   306,  -274,  -274,     1,   189,   -29,  -274,
    -274,  -274,  -274,  -274,  -191,  -274,  -274,  -274,  -274,    13,
      11,  -274,   255,    -9,  -274,   -33,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -273,  -274,   183,  -274,
     105,   -66,  -131,  -118,    22,  -274,   169,   166,   120,    33,
    -274,    64,    95,  -274,    23,  -274,  -274,  -274,  -274,  -274,
      39,   -65,  -274,  -274,   121,  -274,  -274,   148,     0,  -274,
    -274,  -274,  -274,  -274,     3,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
      13,    11,    89,    16,    20,    16,    17,    13,    11,   123,
      36,   275,   149,    12,   309,   129,   155,   156,    34,   160,
      12,     2,   229,     2,    38,    55,    43,    57,   124,    59,
      60,    37,    29,     2,    63,     2,    26,   286,    53,     2,
       2,   126,   295,    22,    55,    43,   296,   234,   236,   237,
     238,   239,   240,   329,   287,   162,   157,    53,   134,     2,
      14,    34,    35,     2,    14,    64,    65,    66,    30,    61,
       2,    14,    18,   144,   229,    62,   276,   266,     1,   214,
       2,   218,   219,   133,   221,   200,   201,    30,   230,    27,
     136,   137,   138,   139,   140,   283,     2,    14,   233,   199,
     235,    31,    18,    58,   193,   242,   158,   159,   131,   194,
     319,   320,   321,   322,    27,   202,     2,   186,   187,   188,
     217,     2,     3,   189,   190,    55,    43,   263,    55,    43,
     270,   203,   222,   211,     4,   184,   185,   198,    53,     2,
     230,    53,    85,   291,    27,    24,   305,     5,   284,    25,
     306,    15,   227,    21,   125,   228,   130,     2,   191,   192,
      39,    40,   132,   313,   315,    39,    40,   141,   129,   271,
       4,    89,   145,   146,     2,     4,   147,   164,   123,   240,
     148,   150,   266,    39,    40,   163,    41,   170,   171,   127,
     128,    41,   172,     4,   272,   128,   195,    55,    43,     3,
     273,   274,   211,   277,   278,   211,   280,   279,   196,    41,
      53,     4,   144,   252,   253,   254,   255,   264,    39,    40,
     308,   155,   212,   227,     5,   165,   228,   213,     4,   314,
     316,   220,   242,   293,   232,   270,   166,   167,   168,   169,
     248,   249,   250,   251,    41,   285,   288,    42,   256,   257,
     289,   290,   307,   294,   297,   310,   299,   312,   298,   300,
     155,   157,   176,   177,   178,   179,   180,   181,   182,   183,
     301,     2,    14,    64,    65,    66,   302,   303,    67,   304,
     311,   258,   259,   260,   261,   262,   173,   174,   175,  -185,
    -184,   327,   328,   245,   246,   247,   324,   331,   325,   326,
     157,   211,   211,   211,   211,    13,   323,    68,    69,    70,
      71,   330,   151,    23,   197,    72,   135,   282,    73,   317,
       2,    14,    64,    65,    66,     4,    74,    67,    75,   216,
      76,    77,    78,    79,    80,    81,    82,    83,   244,   318,
     243,     0,    84,   204,   292,     0,     0,     0,   205,     0,
      85,     0,     0,     0,     0,     0,    68,    69,    70,    71,
       0,     0,     0,     0,    72,     0,     0,    73,     0,     2,
      14,    64,    65,    66,     4,    74,    67,    75,     0,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,    84,    35,   161,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,    68,    69,    70,    71,     0,
       0,     0,     0,    72,     0,     0,    73,     0,     2,    14,
      64,    65,    66,     4,    74,    67,    75,     0,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
      84,    35,   222,     0,     0,     0,     0,     0,    85,     0,
       0,     0,     0,     0,    68,    69,    70,    71,     0,     0,
       0,     0,    72,     0,     0,    73,     0,     2,    14,    64,
      65,    66,     4,    74,    67,    75,     0,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,    84,
      35,     2,    14,    64,    65,    66,     0,    85,    67,     0,
       0,     0,     0,    68,    69,    70,    71,     0,   151,     0,
     265,     2,    14,    64,    65,    66,     0,     0,    67,     0,
       0,     4,     0,     0,     0,     0,     0,    68,    69,    70,
      71,     0,   151,    83,     0,     0,     0,     0,    84,   152,
       0,     0,     0,     0,   153,     4,    85,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,    83,    73,     0,
       0,     0,    84,   152,     0,     4,     0,     0,   153,     0,
      85,     2,    14,    64,    65,    66,     0,    83,    67,     0,
       0,     0,    84,     0,     0,     2,    14,    64,    65,    66,
      85,     0,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    68,    69,    70,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    68,    69,    70,    71,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
      85,    83,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,    85
};

static const yytype_int16 yycheck[] =
{
       0,     0,    35,     3,     4,     5,     3,     7,     7,    35,
      19,   202,    78,     0,   287,    44,    82,    82,    18,    85,
       7,     3,   153,     3,    24,    25,    25,    27,    37,    29,
      30,    20,    72,     3,    34,     3,     7,    61,    25,     3,
       3,    41,    77,     0,    44,    44,    81,   165,   166,   167,
     168,   169,   170,   326,    78,    88,    82,    44,    58,     3,
       4,    61,    75,     3,     4,     5,     6,     7,    50,    77,
       3,     4,    82,    73,   205,    83,    46,   195,     1,   145,
       3,   147,   148,    79,   150,    49,    50,    50,   153,    85,
      67,    68,    69,    70,    71,   213,     3,     4,   164,   128,
     165,    83,    82,    72,    80,   170,    83,    84,    46,    85,
     301,   302,   303,   304,    85,    79,     3,    11,    12,    13,
     146,     3,    45,    17,    18,   125,   125,   193,   128,   128,
     195,   131,    76,   133,    57,     9,    10,   126,   125,     3,
     205,   128,    82,    76,    85,    71,    77,    70,   213,    75,
      81,     3,   152,     5,    75,   152,    78,     3,    41,    42,
      47,    48,    78,   294,   295,    47,    48,    79,   197,   195,
      57,   204,    82,    82,     3,    57,    82,    77,   204,   297,
      82,    82,   300,    47,    48,    78,    73,    84,    38,    76,
      77,    73,    37,    57,    76,    77,    82,   197,   197,    45,
     200,   201,   202,   203,   204,   205,   205,   204,    76,    73,
     197,    57,   212,   180,   181,   182,   183,   194,    47,    48,
     286,   287,    77,   223,    70,     8,   223,     8,    57,   294,
     295,    79,   297,    77,    83,   300,    19,    20,    21,    22,
     176,   177,   178,   179,    73,    83,    83,    76,   184,   185,
      83,    83,   285,    79,    79,   288,    83,   290,    81,    77,
     326,   287,    29,    30,    31,    32,    33,    34,    35,    36,
      79,     3,     4,     5,     6,     7,    79,    79,    10,    79,
     289,   186,   187,   188,   189,   190,    14,    15,    16,    79,
      79,   324,   325,   173,   174,   175,    59,   330,    83,    78,
     326,   301,   302,   303,   304,   305,   305,    39,    40,    41,
      42,    83,    44,     7,   125,    47,    61,   212,    50,   297,
       3,     4,     5,     6,     7,    57,    58,    10,    60,   146,
      62,    63,    64,    65,    66,    67,    68,    69,   172,   300,
     171,    -1,    74,    75,   223,    -1,    -1,    -1,    80,    -1,
      82,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    -1,     3,
       4,     5,     6,     7,    57,    58,    10,    60,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    50,    -1,     3,     4,
       5,     6,     7,    57,    58,    10,    60,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,     3,     4,     5,
       6,     7,    57,    58,    10,    60,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    74,
      75,     3,     4,     5,     6,     7,    -1,    82,    10,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      46,     3,     4,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    44,    69,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,    -1,    80,    57,    82,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    69,    50,    -1,
      -1,    -1,    74,    75,    -1,    57,    -1,    -1,    80,    -1,
      82,     3,     4,     5,     6,     7,    -1,    69,    10,    -1,
      -1,    -1,    74,    -1,    -1,     3,     4,     5,     6,     7,
      82,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    69,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    45,    57,    70,    87,    88,    89,    90,
      91,    92,   105,   154,     4,   153,   154,   160,    82,   106,
     154,   153,     0,    89,    71,    75,     7,    85,   155,    72,
      50,    83,   107,   108,   154,    75,   109,   106,   154,    47,
      48,    73,    76,    92,    93,    94,    95,    96,    97,    98,
      99,   103,   104,   105,   153,   154,   161,   154,    72,   154,
     154,    77,    83,   154,     5,     6,     7,    10,    39,    40,
      41,    42,    47,    50,    58,    60,    62,    63,    64,    65,
      66,    67,    68,    69,    74,    82,   105,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     124,   127,   128,   129,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   154,   156,   157,
     158,   159,   160,   161,   109,    75,   154,    76,    77,    94,
      78,    46,    78,    79,   154,   108,   140,   140,   140,   140,
     140,    79,   125,   126,   154,    82,    82,    82,    82,   127,
      82,    44,    75,    80,   122,   127,   147,   161,   140,   140,
     127,    76,   111,    78,    77,     8,    19,    20,    21,    22,
      84,    38,    37,    14,    15,    16,    29,    30,    31,    32,
      33,    34,    35,    36,     9,    10,    11,    12,    13,    17,
      18,    41,    42,    80,    85,    82,    76,    93,   106,    94,
      49,    50,    79,   154,    75,    80,    92,   100,   101,   111,
     147,   154,    77,     8,   127,   123,   124,   161,   127,   127,
      79,   127,    76,   149,   150,   151,   152,   154,   160,   128,
     147,   148,    83,   127,   129,   147,   129,   129,   129,   129,
     129,   130,   147,   132,   133,   134,   134,   134,   137,   137,
     137,   137,   135,   135,   135,   135,   137,   137,   138,   138,
     138,   138,   138,   127,   140,    46,   129,   144,   145,   146,
     147,   161,    76,   154,   154,   100,    46,   154,   154,   160,
      92,   102,   126,   129,   147,    83,    61,    78,    83,    83,
      83,    76,   150,    77,    79,    77,    81,    79,    81,    83,
      77,    79,    79,    79,    79,    77,    81,   111,   127,   122,
     111,   109,   111,   128,   147,   128,   147,   130,   146,   100,
     100,   100,   100,    92,    59,    83,    78,   111,   111,   122,
      83,   111
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (pContext, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, pContext)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, pContext); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, QMLTreeContext* pContext)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, pContext)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    QMLTreeContext* pContext;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (pContext);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, QMLTreeContext* pContext)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, pContext)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    QMLTreeContext* pContext;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, pContext);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, QMLTreeContext* pContext)
#else
static void
yy_reduce_print (yyvsp, yyrule, pContext)
    YYSTYPE *yyvsp;
    int yyrule;
    QMLTreeContext* pContext;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , pContext);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, pContext); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, QMLTreeContext* pContext)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, pContext)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    QMLTreeContext* pContext;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (pContext);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (QMLTreeContext* pContext);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (QMLTreeContext* pContext)
#else
int
yyparse (pContext)
    QMLTreeContext* pContext;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 149 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 155 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declaration");

        QMLEntity* pEntity = (yyvsp[(1) - (1)].Object);

        if (pEntity != nullptr)
        {
            pContext->scopes().last()->m_pFile->contents() << pEntity;
        }
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 167 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        if (pEntity != nullptr)
        {
            pContext->scopes().last()->m_pFile->contents() << pEntity;
        }
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 179 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        // SAFE_DELETE($<Object>1);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 186 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 193 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 200 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 207 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Function");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 216 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pName = (yyvsp[(2) - (3)].Object);
        QMLEntity* pVersion = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext->position(), pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            (yyval.Object) = nullptr;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 234 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pName = (yyvsp[(2) - (5)].Object);
        QMLEntity* pVersion = (yyvsp[(3) - (5)].Object);
        QMLEntity* pAs = (yyvsp[(5) - (5)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext->position(), pContext, pName->value().toString(), pVersion->value().toString(), pAs->value().toString());
        }
        else
        {
            (yyval.Object) = nullptr;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 253 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pName = (yyvsp[(2) - (2)].Object);

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext->position(), pContext, pName->value().toString(), "");
        }
        else
        {
            (yyval.Object) = nullptr;
        }

        SAFE_DELETE(pName);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 269 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pName = (yyvsp[(2) - (4)].Object);
        QMLEntity* pAs = (yyvsp[(4) - (4)].Object);

        if (pName != nullptr && pAs != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext->position(), pContext, pName->value().toString(), "", pAs->value().toString());
        }
        else
        {
            (yyval.Object) = nullptr;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pAs);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 289 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        QMLEntity* pStatement = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLPragma(pStatement->position(), pStatement);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 300 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' ItemContents '}'");

        QMLEntity* pName = (yyvsp[(1) - (4)].Object);
        QMLItem* pComplexItem = dynamic_cast<QMLItem*>((yyvsp[(3) - (4)].Object));

        if (pName != nullptr && pComplexItem != nullptr)
        {
            pComplexItem->setName(pName);
        }
        else
        {
            SAFE_DELETE(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 319 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLEntity* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pComplexItem = new QMLItem(pContext->position());

        if (pName != nullptr)
        {
            pComplexItem->setName(pName);
        }
        else
        {
            SAFE_DELETE(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 338 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON Identifier '{' ItemContents '}'");

        QMLEntity* pName = (yyvsp[(1) - (6)].Object);
        QMLEntity* pTarget = (yyvsp[(3) - (6)].Object);
        QMLItem* pContents = dynamic_cast<QMLItem*>((yyvsp[(5) - (6)].Object));

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
            pContents = new QMLItem(pContext->position(), pName);
        }

        QMLOnExpression* pExpression = new QMLOnExpression(pName->position(), pTarget, pName->clone(), pContents);

        (yyval.Object) = pExpression;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 368 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLEntity* pOldItem = (yyvsp[(1) - (1)].Object);

        if (pOldItem != nullptr)
        {
            QMLItem* pComplexItem = new QMLItem(pContext->position());
            pComplexItem->contents() << pOldItem;

            (yyval.Object) = pComplexItem;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 387 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ItemContent");

        QMLItem* pComplexItem = dynamic_cast<QMLItem*>((yyvsp[(1) - (2)].Object));
        QMLEntity* pNewItem = (yyvsp[(2) - (2)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 402 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ',' ItemContent");

        QMLItem* pComplexItem = dynamic_cast<QMLItem*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pNewItem = (yyvsp[(3) - (3)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 419 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 426 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 433 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 440 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 447 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 456 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 463 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 472 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY");

        int iModifiers = (yyvsp[(1) - (4)].Integer);
        QMLEntity* pTypeIdentifier = (yyvsp[(3) - (4)].Object);
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 498 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier");

        int iModifiers = (yyvsp[(1) - (4)].Integer);
        QMLEntity* pTypeIdentifier = (yyvsp[(3) - (4)].Object);
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(4) - (4)].Object));

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 524 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier");

        int iModifiers = (yyvsp[(1) - (4)].Integer);
        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(4) - (4)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 547 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier TOKEN_PROPERTY ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLEntity* pTypeIdentifier = (yyvsp[(3) - (6)].Object);
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");
        QMLEntity* pData = dynamic_cast<QMLEntity*>((yyvsp[(6) - (6)].Object));

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 575 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLEntity* pTypeIdentifier = (yyvsp[(3) - (6)].Object);
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(4) - (6)].Object));
        QMLEntity* pData = dynamic_cast<QMLEntity*>((yyvsp[(6) - (6)].Object));

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 603 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(4) - (6)].Object));
        QMLEntity* pData = dynamic_cast<QMLEntity*>((yyvsp[(6) - (6)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pName->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 628 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(4) - (6)].Object));
        QMLEntity* pData = dynamic_cast<QMLEntity*>((yyvsp[(6) - (6)].Object));

        if (pName != nullptr)
        {
            QMLPropertyAlias* pDeclaration = new QMLPropertyAlias(pName->position(), pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pName);
            SAFE_DELETE(pData);
        }
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 653 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mNone;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 658 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (yyvsp[(1) - (1)].Integer);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 665 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mDefault;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 670 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mReadonly;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 677 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "PropertyModifiersOpt TOKEN_PROPERTY ':' PropertyContent");

        QMLEntity* pName = new QMLIdentifier(pContext->position(), "property");
        QMLEntity* pContent = (yyvsp[(4) - (4)].Object);

        if (pName != nullptr)
        {
            QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName->position(), pName, pContent);

            (yyval.Object) = pAssignment;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pContent);

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 699 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLEntity* pName = (yyvsp[(1) - (3)].Object);
        QMLEntity* pContent = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr)
        {
            QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName->position(), pName, pContent);

            (yyval.Object) = pAssignment;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pContent);

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 723 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 730 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "ItemArray");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 737 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 744 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 753 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArray", "'[' ItemArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 762 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArrayContents", "Item");

        QMLEntity* pEntity1 = (yyvsp[(1) - (1)].Object);

        if (pEntity1 != nullptr)
        {
            QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity1->position());
            pComplex->setIsArray(true);
            pComplex->contents() << pEntity1;

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 782 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArrayContents", "ItemArrayContents ',' Item");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));

        if (pComplex != nullptr)
        {
            QMLEntity* pEntity2 = (yyvsp[(3) - (3)].Object);

            if (pEntity2 != nullptr)
            {
                pComplex->contents() << pEntity2;
            }

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 807 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 814 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 823 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier");

        QMLEntity* pName = (yyvsp[(2) - (2)].Object);
        QMLEntity* pParameters = new QMLEntity(pContext->position());

        if (pName != nullptr)
        {
            QMLFunction* pFunction = new QMLFunction(pName->position(), pName, pParameters, nullptr);
            pFunction->setIsSignal(true);

            (yyval.Object) = pFunction;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pParameters);

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 846 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLEntity* pName = (yyvsp[(2) - (3)].Object);
        QMLEntity* pParameters = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr)
        {
            QMLFunction* pFunction = new QMLFunction(pName->position(), pName, pParameters, nullptr);
            pFunction->setIsSignal(true);

            (yyval.Object) = pFunction;
        }
        else
        {
            SAFE_DELETE(pName);
            SAFE_DELETE(pParameters);

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 871 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock");

        QMLEntity* pName = (yyvsp[(2) - (4)].Object);
        QMLEntity* pParameters = (yyvsp[(3) - (4)].Object);
        QMLComplexEntity* pContent = dynamic_cast<QMLComplexEntity*>((yyvsp[(4) - (4)].Object));

        if (pContent == nullptr)
        {
            pContent = new QMLComplexEntity(pName->position());
            pContent->setIsBlock(true);
        }

        (yyval.Object) = new QMLFunction(pName->position(), pName, pParameters, pContent);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 888 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock");

        QMLEntity* pParameters = (yyvsp[(2) - (3)].Object);
        QMLComplexEntity* pContent = dynamic_cast<QMLComplexEntity*>((yyvsp[(3) - (3)].Object));

        if (pContent == nullptr)
        {
            pContent = new QMLComplexEntity(pContext->position());
            pContent->setIsBlock(true);
        }

        QPoint pPosition;

        if (pParameters != nullptr) pPosition = pParameters->position();
        else pPosition = pContent->position();

        QMLEntity* pName = new QMLIdentifier(pPosition, "");

        (yyval.Object) = new QMLFunction(pPosition, pName, pParameters, pContent);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 913 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 920 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 929 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 936 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        QMLComplexEntity* pList = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLEntity* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexEntity(pExpression1->position());
            pList->contents() << pExpression1;
        }

        pList->setIsArgumentList(true);

        pList->contents() << pExpression2;

        (yyval.Object) = pList;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 959 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier");

        QMLType* pType = QMLType::fromQMLEntity(nullptr);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(1) - (1)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 979 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "TOKEN_VAR Identifier");

        QMLType* pType = new QMLType(pContext->position(), QVARIANT_VARIANT);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(2) - (2)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 999 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier Identifier");

        QMLEntity* pTypeIdentifier = (yyvsp[(1) - (2)].Object);
        QMLType* pType = QMLType::fromQMLEntity(pTypeIdentifier);
        QMLEntity* pName = dynamic_cast<QMLEntity*>((yyvsp[(2) - (2)].Object));

        SAFE_DELETE(pTypeIdentifier);

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLFunctionParameter(pName->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pType);
            SAFE_DELETE(pName);
        }
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1024 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' Empty '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1031 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        QMLEntity* pEntity = (yyvsp[(2) - (3)].Object);

        pEntity = QMLComplexEntity::makeBlock(pEntity);

        (yyval.Object) = pEntity;
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1044 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLEntity* pStatement1 = (yyvsp[(1) - (1)].Object);

        if (pStatement1 == nullptr)
        {
            pStatement1 = new QMLEntity(pContext->position());
        }

        QMLComplexEntity* pComplex = new QMLComplexEntity(pStatement1->position());

        pComplex->contents() << pStatement1;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1062 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatements JSStatement");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (2)].Object));
        QMLEntity* pStatement2 = (yyvsp[(2) - (2)].Object);

        if (pComplex != nullptr)
        {
            pComplex->contents() << pStatement2;
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1079 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1086 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1095 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1102 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1109 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1116 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1123 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1130 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Switch");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1137 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Case");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1144 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1151 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1158 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1165 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1174 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pCondition = (yyvsp[(3) - (5)].Object);
        QMLEntity* pThen = (yyvsp[(5) - (5)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLEntity(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLEntity(pContext->position());
        }

        pThen = QMLComplexEntity::makeBlock(pThen);

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, nullptr);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1194 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pCondition = (yyvsp[(3) - (7)].Object);
        QMLEntity* pThen = (yyvsp[(5) - (7)].Object);
        QMLEntity* pElse = (yyvsp[(7) - (7)].Object);

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

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, pElse);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1223 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pInitialization = (yyvsp[(3) - (9)].Object);
        QMLEntity* pCondition = (yyvsp[(5) - (9)].Object);
        QMLEntity* pIncrementation = (yyvsp[(7) - (9)].Object);
        QMLEntity* pContent = (yyvsp[(9) - (9)].Object);

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLEntity(pContext->position());
        }

        pContent = QMLComplexEntity::makeBlock(pContent);

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1240 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pVariable = (yyvsp[(3) - (7)].Object);
        QMLEntity* pExpression = (yyvsp[(5) - (7)].Object);
        QMLEntity* pContent = (yyvsp[(7) - (7)].Object);

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

        (yyval.Object) = new QMLForIn(pVariable->position(), pVariable, pExpression, pContent);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1268 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pInitialization = new QMLEntity(pContext->position());
        QMLEntity* pCondition = (yyvsp[(3) - (5)].Object);
        QMLEntity* pIncrementation = new QMLEntity(pContext->position());
        QMLEntity* pContent = (yyvsp[(5) - (5)].Object);

        pContent = QMLComplexEntity::makeBlock(pContent);

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1282 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(3) - (5)].Object);
        QMLComplexEntity* pCases = dynamic_cast<QMLComplexEntity*>((yyvsp[(5) - (5)].Object));

        if (pExpression != nullptr && pCases != nullptr)
        {
            QMLEntity* pSwitch = new QMLSwitch(pExpression->position(), pExpression, pCases);

            (yyval.Object) = pSwitch;
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1301 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (3)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1308 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = new QMLEntity(pContext->position(), "default");

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1317 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoBreak);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1324 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoContinue);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1331 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1338 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1345 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1354 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1359 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1366 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Empty");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1373 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1382 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpression", "TOKEN_VAR JSVariables");

        QMLEntity* pVariable = (yyvsp[(2) - (2)].Object);
        QMLComplexEntity* pVariables = dynamic_cast<QMLComplexEntity*>((yyvsp[(2) - (2)].Object));

        if (pVariables != nullptr)
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariables->position());

            pDeclaration->setIsArgumentList(true);
            pDeclaration->contents() = pVariables->grabContents();

            SAFE_DELETE(pVariables);

            (yyval.Object) = pDeclaration;
        }
        else
        {
            QMLVariableDeclaration* pDeclaration = new QMLVariableDeclaration(pVariable->position());

            pDeclaration->contents() << pVariable;

            (yyval.Object) = pDeclaration;
        }
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1410 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpression", "JSExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1419 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        QMLEntity* pVariable = (yyvsp[(1) - (1)].Object);

        QMLComplexEntity* pVariables = new QMLComplexEntity(pVariables->position());
        pVariables->contents() << pVariable;

        (yyval.Object) = pVariables;
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1431 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        QMLComplexEntity* pVariables = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pVariable = (yyvsp[(3) - (3)].Object);

        if (pVariables != nullptr)
        {
            pVariables->contents() << pVariable;

            (yyval.Object) = pVariables;
        }
        else
        {
            (yyval.Object) = nullptr;

            SAFE_DELETE(pVariables);
            SAFE_DELETE(pVariable);
        }
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1455 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1462 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        ENSURE_NON_NULL(pLeft);
        ENSURE_NON_NULL(pRight);

        (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1475 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSObject");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        ENSURE_NON_NULL(pLeft);
        ENSURE_NON_NULL(pRight);

        (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1490 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1497 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle ',' JSExpression");

        QMLEntity* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLEntity* pExpression2 = (yyvsp[(3) - (3)].Object);

        ENSURE_NON_NULL(pExpression1);
        ENSURE_NON_NULL(pExpression2);

        QMLComplexEntity* pComplex = QMLComplexEntity::fromEntity(pExpression1);

        pComplex->setIsArgumentList(true);

        pComplex->contents() << pExpression2;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1518 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1525 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1532 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1549 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1566 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1583 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1600 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1617 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1636 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1641 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1648 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1655 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLEntity* pCondition = (yyvsp[(1) - (5)].Object);
        QMLEntity* pThen = (yyvsp[(3) - (5)].Object);
        QMLEntity* pElse = (yyvsp[(5) - (5)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLEntity(pContext->position());
        }

        (yyval.Object) = new QMLConditional(pCondition->position(), pCondition, pThen, pElse);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1671 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1680 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1687 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1706 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1711 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicAnd);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1728 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1733 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAnd);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1748 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boOr);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1763 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boXor);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1780 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1785 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEquals);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1800 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1815 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEquals);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1830 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1847 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1852 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLower);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1867 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1882 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreater);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1897 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1914 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1919 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAdd);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1934 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSub);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1951 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1956 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMul);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1971 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDiv);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1986 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMod);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 2001 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftLeft);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 2016 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftRight);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 2033 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2038 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_INC");

        QMLEntity* pEntity = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement, true);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2047 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2054 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_DEC");

        QMLEntity* pEntity = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement, true);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2063 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2070 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNot);
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 2077 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNotNot);
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 2084 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoTypeof);
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2091 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoMinus);
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2098 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNew);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2107 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2114 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression '.' JSMemberExpression");

        QMLEntity* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLEntity* pExpression2 = (yyvsp[(3) - (3)].Object);

        QMLQualifiedExpression* pExpression = dynamic_cast<QMLQualifiedExpression*>((yyvsp[(1) - (3)].Object));

        if (pExpression == nullptr)
        {
            pExpression = new QMLQualifiedExpression(pExpression1->position());
            pExpression->contents() << pExpression1;
        }

        pExpression->contents() << pExpression2;

        (yyval.Object) = pExpression;
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 2136 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2143 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSArrayAccessExpression '[' JSExpression ']'");

        QMLEntity* pLeft = (yyvsp[(1) - (4)].Object);
        QMLArrayAccess* pArrayAccess = dynamic_cast<QMLArrayAccess*>((yyvsp[(1) - (4)].Object));
        QMLEntity* pIndexer = (yyvsp[(3) - (4)].Object);

        if (pArrayAccess == nullptr)
        {
            pArrayAccess = new QMLArrayAccess(pIndexer->position(), pLeft);
        }

        pArrayAccess->contents() << pIndexer;

        (yyval.Object) = pArrayAccess;
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 2163 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2170 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression '(' JSArgumentListOpt ')'");

        QMLEntity* pName = (yyvsp[(1) - (4)].Object);
        QMLEntity* pArgument = (yyvsp[(3) - (4)].Object);
        QMLComplexEntity* pArguments = dynamic_cast<QMLComplexEntity*>((yyvsp[(3) - (4)].Object));

        if (pArguments == nullptr && pArgument != nullptr)
        {
            pArguments = new QMLComplexEntity(pArgument->position());
            pArguments->contents() << pArgument;
        }

        (yyval.Object) = new QMLFunctionCall(pName->position(), pName, pArguments);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 2189 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2196 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2203 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        QMLEntity* pEntity = (yyvsp[(2) - (3)].Object);

        pEntity->setIsParenthesized(true);

        (yyval.Object) = pEntity;
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2216 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = new QMLComplexEntity(pContext->position());
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2223 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2232 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLEntity* pArgument = (yyvsp[(1) - (1)].Object);

        QMLComplexEntity* pList = new QMLComplexEntity(pArgument->position());
        pList->setIsArgumentList(true);

        pList->contents() << pArgument;

        (yyval.Object) = pList;
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 2246 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexEntity* pList = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pArgument = (yyvsp[(3) - (3)].Object);

        pList->contents() << pArgument;

        (yyval.Object) = pList;
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 2260 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLIdentifier(pContext->position(), "property");
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2265 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 2270 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 2277 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' JSAttributes '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2284 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' '}'");

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
        pComplex->setIsObject(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2294 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "TOKEN_DIMENSION");

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
        pComplex->setIsArray(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2304 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'[' JSArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2313 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSObject");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pEntity = (yyvsp[(3) - (3)].Object);

        pComplex->contents() << pEntity;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 2325 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSExpressionSingle");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (3)].Object));
        QMLEntity* pEntity = (yyvsp[(3) - (3)].Object);

        pComplex->contents() << pEntity;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 2337 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSObject");

        QMLEntity* pEntity = (yyvsp[(1) - (1)].Object);

        if (pEntity == nullptr)
            pEntity = new QMLEntity(pContext->position());

        QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pEntity;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 2353 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSExpressionSingle");

        QMLEntity* pEntity = (yyvsp[(1) - (1)].Object);

        if (pEntity == nullptr)
            pEntity = new QMLEntity(pContext->position());

        QMLComplexEntity* pComplex = new QMLComplexEntity(pEntity->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pEntity;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 2371 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributes", "JSAttribute");

        QMLEntity* pAttribute1 = (yyvsp[(1) - (1)].Object);

        QMLComplexEntity* pComplex = new QMLComplexEntity(pAttribute1->position());
        pComplex->setIsObject(true);

        pComplex->contents() << pAttribute1;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 2385 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributes", "JSAttributes JSAttribute");

        QMLComplexEntity* pComplex = dynamic_cast<QMLComplexEntity*>((yyvsp[(1) - (2)].Object));
        QMLEntity* pAttribute2 = (yyvsp[(2) - (2)].Object);

        pComplex->contents() << pAttribute2;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 2399 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2406 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma ','");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 2415 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSObject");

        QMLEntity* pName = (yyvsp[(1) - (3)].Object);
        QMLEntity* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            PARSER_TRACE("JSAttributeNoComma", pName->value().toString() + ", " + pValue->value().toString());

            QMLPropertyAssignment* pAssign = new QMLPropertyAssignment(pName->position(), pName, pValue);

            (yyval.Object) = pAssign;
        }
        else
        {
            PARSER_TRACE("JSAttributeNoComma", "... name or value is NULL !!");

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 2438 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSExpressionSingle");

        QMLEntity* pName = (yyvsp[(1) - (3)].Object);
        QMLEntity* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            PARSER_TRACE("JSAttributeNoComma", pName->value().toString() + ", " + pValue->value().toString());

            QMLPropertyAssignment* pAssign = new QMLPropertyAssignment(pName->position(), pName, pValue);

            (yyval.Object) = pAssign;
        }
        else
        {
            PARSER_TRACE("JSAttributeNoComma", "... name or value is NULL !!");

            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 2463 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 2468 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 2475 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("QualifiedIdentifier", "Identifier");

        QMLEntity* pIdentifier = (yyvsp[(1) - (1)].Object);

        (yyval.Object) = pIdentifier;
    ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 2484 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("QualifiedIdentifier", "QualifiedIdentifier '.' Identifier");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 2500 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != nullptr)
        {
            (yyval.Object) = new QMLIdentifier(pContext->position(), *pString);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 2516 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLEntity(pContext->position(), pContext->tokenValue());
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 2523 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 2528 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 2533 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 2538 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 2545 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 2552 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 2559 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 2566 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != nullptr)
        {
            (yyval.Object) = new QMLEntity(pContext->position(), QVariant(*pString));
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 2581 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 4968 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (pContext, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (pContext, yymsg);
	  }
	else
	  {
	    yyerror (pContext, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, pContext);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, pContext);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (pContext, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, pContext);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, pContext);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2585 "C:/User/E487027/Work/Projects/Temp/qt-plus/source/bison/QML.y"


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

