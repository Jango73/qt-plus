
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
#line 9 "D:/Work/Projects/qt-plus/source/bison/QML.y"

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



/* Line 189 of yacc.c  */
#line 117 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
     TOKEN_NULL = 305,
     TOKEN_UNDEFINED = 306,
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
#line 52 "D:/Work/Projects/qt-plus/source/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLEntity*  Object;



/* Line 214 of yacc.c  */
#line 239 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 251 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   877

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  331

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
      84,    85,     2,     2,    79,     2,    87,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    80,
       2,     2,     2,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,    78,     2,     2,     2,     2,
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
       3,     4,     5,     6,     7,     8,     9,     2,     2,     2,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     2,     2,     2,
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
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
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
     582,   584,   587,   591,   595,   597,   599,   601,   603,   605,
     607,   609,   611,   613,   615,   617,   619,   621,   623,   625
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      89,     0,    -1,    90,    -1,    91,    -1,    90,    91,    -1,
       1,    -1,    92,    -1,    93,    -1,    94,    -1,   129,    -1,
      47,   142,   156,    -1,    47,   142,   156,    74,   155,    -1,
      47,   142,    -1,    47,   142,    74,   155,    -1,    72,   142,
      -1,   142,    77,    95,    78,    -1,   142,    77,    78,    -1,
     155,    73,   142,    77,    95,    78,    -1,    96,    -1,    95,
      96,    -1,    95,    79,    96,    -1,    97,    -1,   101,    -1,
      94,    -1,   107,    -1,   105,    -1,    98,    -1,    98,    80,
      -1,    99,    48,   155,    48,    -1,    99,    48,   155,   155,
      -1,    99,    48,    52,   155,    -1,    99,    48,   155,    48,
      81,   102,    -1,    99,    48,   155,   155,    81,   102,    -1,
      99,    48,    52,   155,    81,   102,    -1,    99,    48,    51,
     155,    81,   102,    -1,   163,    -1,   100,    -1,    49,    -1,
      50,    -1,    99,    48,    81,   102,    -1,   142,    81,   102,
      -1,    94,    -1,   103,    -1,   113,    -1,   149,    -1,    82,
     104,    83,    -1,    94,    -1,   104,    79,    94,    -1,   106,
      -1,   106,    80,    -1,    75,   155,    -1,    75,   155,   108,
      -1,    59,   155,   108,   111,    -1,    59,   108,   111,    -1,
      84,   109,    85,    -1,    84,    85,    -1,   110,    -1,   109,
      79,   110,    -1,   155,    -1,    52,   155,    -1,   155,   155,
      -1,    77,   163,    78,    -1,    77,   112,    78,    -1,   113,
      -1,   112,   113,    -1,   114,    -1,   114,    80,    -1,   111,
      -1,   126,    -1,   115,    -1,   116,    -1,   117,    -1,   118,
      -1,   119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,
      -1,    60,    84,   129,    85,   113,    -1,    60,    84,   129,
      85,   113,    61,   113,    -1,    62,    84,   125,    80,   124,
      80,   124,    85,   113,    -1,    62,    84,   125,    63,   129,
      85,   113,    -1,    64,    84,   129,    85,   113,    -1,    65,
      84,   129,    85,   111,    -1,    66,   129,    81,    -1,    49,
      81,    -1,    67,    -1,    68,    -1,    69,    84,   129,    85,
     113,    -1,    70,   149,    -1,    70,   124,    -1,   163,    -1,
     129,    -1,   163,    -1,   126,    -1,    52,   127,    -1,   129,
      -1,   128,    -1,   127,    79,   128,    -1,   155,    -1,   155,
      10,   131,    -1,   155,    10,   149,    -1,   130,    -1,   130,
      79,   129,    -1,   131,    -1,   133,    -1,   133,    10,   131,
      -1,   133,    21,   131,    -1,   133,    22,   131,    -1,   133,
      23,   131,    -1,   133,    24,   131,    -1,   133,    10,   149,
      -1,   131,    -1,   149,    -1,   134,    -1,   134,    86,   132,
      81,   132,    -1,   107,    -1,   135,    -1,   135,    40,   134,
      -1,   136,    -1,   136,    39,   135,    -1,   137,    -1,   137,
      16,   136,    -1,   137,    17,   136,    -1,   137,    18,   136,
      -1,   138,    -1,   138,    35,   137,    -1,   138,    36,   137,
      -1,   138,    37,   137,    -1,   138,    38,   137,    -1,   139,
      -1,   138,    31,   139,    -1,   138,    33,   139,    -1,   138,
      32,   139,    -1,   138,    34,   139,    -1,   140,    -1,   140,
      11,   139,    -1,   140,    12,   139,    -1,   141,    -1,   141,
      13,   140,    -1,   141,    14,   140,    -1,   141,    15,   140,
      -1,   141,    19,   140,    -1,   141,    20,   140,    -1,   142,
      -1,   142,    43,    -1,    43,   142,    -1,   142,    44,    -1,
      44,   142,    -1,    41,   142,    -1,    42,   142,    -1,    71,
     142,    -1,    12,   142,    -1,    76,   142,    -1,   143,    -1,
     143,    87,   142,    -1,   144,    -1,   143,    82,   129,    83,
      -1,   145,    -1,   145,    84,   146,    85,    -1,   155,    -1,
     157,    -1,    84,   129,    85,    -1,   163,    -1,   147,    -1,
     148,    -1,   147,    79,   148,    -1,    48,    -1,   149,    -1,
     131,    -1,    77,   151,    78,    -1,    77,    78,    -1,    46,
      -1,    82,   150,    83,    -1,   150,    79,   149,    -1,   150,
      79,   130,    -1,   149,    -1,   130,    -1,   152,    -1,   151,
     152,    -1,   153,    -1,   153,    79,    -1,   154,    81,   149,
      -1,   154,    81,   130,    -1,   161,    -1,   155,    -1,     3,
      -1,     7,    -1,   158,    -1,   159,    -1,   160,    -1,   161,
      -1,   162,    -1,     5,    -1,     6,    -1,     7,    -1,     4,
      -1,     8,    -1,     9,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   157,   169,   181,   188,   195,   202,   209,
     218,   235,   253,   269,   288,   299,   319,   339,   371,   390,
     405,   422,   429,   436,   443,   450,   459,   466,   475,   501,
     527,   550,   578,   606,   631,   656,   661,   668,   673,   680,
     702,   726,   733,   740,   747,   756,   765,   785,   810,   817,
     826,   849,   874,   891,   916,   923,   932,   939,   962,   982,
    1002,  1027,  1034,  1047,  1065,  1082,  1089,  1098,  1105,  1112,
    1119,  1126,  1133,  1140,  1147,  1154,  1161,  1168,  1177,  1197,
    1226,  1243,  1271,  1288,  1307,  1314,  1323,  1330,  1337,  1344,
    1351,  1360,  1365,  1372,  1379,  1388,  1416,  1425,  1437,  1461,
    1468,  1481,  1496,  1503,  1524,  1531,  1538,  1555,  1572,  1589,
    1606,  1623,  1642,  1647,  1654,  1661,  1677,  1686,  1693,  1712,
    1717,  1734,  1739,  1754,  1769,  1786,  1791,  1806,  1821,  1836,
    1853,  1858,  1873,  1888,  1903,  1920,  1925,  1940,  1957,  1962,
    1977,  1992,  2007,  2022,  2039,  2044,  2053,  2060,  2069,  2078,
    2087,  2096,  2105,  2114,  2125,  2132,  2154,  2161,  2181,  2188,
    2207,  2214,  2221,  2234,  2241,  2250,  2264,  2278,  2285,  2292,
    2301,  2308,  2318,  2328,  2337,  2349,  2361,  2377,  2395,  2409,
    2423,  2430,  2439,  2462,  2487,  2494,  2503,  2521,  2530,  2537,
    2544,  2551,  2558,  2567,  2574,  2581,  2588,  2604,  2609,  2616
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_IDENTIFIER", "TOKEN_LITERAL",
  "TOKEN_BOOLCONSTANT", "TOKEN_INTEGERCONSTANT", "TOKEN_REALCONSTANT",
  "TOKEN_NULL", "TOKEN_UNDEFINED", "TOKEN_ASSIGN", "TOKEN_ADD",
  "TOKEN_SUB", "TOKEN_MUL", "TOKEN_DIV", "TOKEN_MOD", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_XOR", "TOKEN_SHL", "TOKEN_SHR", "TOKEN_ADD_ASSIGN",
  "TOKEN_SUB_ASSIGN", "TOKEN_MUL_ASSIGN", "TOKEN_DIV_ASSIGN",
  "TOKEN_MOD_ASSIGN", "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN",
  "TOKEN_XOR_ASSIGN", "TOKEN_SHL_ASSIGN", "TOKEN_SHR_ASSIGN",
  "TOKEN_LOWER", "TOKEN_GREATER", "TOKEN_LOWER_EQUALS",
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
  "JSAttributeName", "Identifier", "Version", "Value", "Boolean",
  "Integer", "Double", "Literal", "SpecialValue", "Empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   530,   300,   301,   302,   303,   304,   305,   306,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   123,   125,    44,
      59,    58,    91,    93,    40,    41,    63,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    93,    94,    94,    94,    95,    95,
      95,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   102,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     116,   116,   117,   118,   119,   119,   120,   121,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   129,   129,   130,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   137,   137,   137,   137,   137,
     138,   138,   138,   138,   138,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   145,   146,   146,   147,   147,   148,   148,   148,
     149,   149,   149,   149,   150,   150,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   155,   156,   157,   157,
     157,   157,   157,   158,   159,   160,   161,   162,   162,   163
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
       1,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   186,   196,   193,   194,   195,   197,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     6,     7,     8,   116,     9,   102,   104,
     105,   114,   117,   119,   121,   125,   130,   135,   138,   144,
     154,   156,   158,   160,   161,   188,   189,   190,   191,   192,
     152,   160,   149,   150,   146,   148,    12,     0,     0,     0,
     151,    14,   153,     0,   144,     1,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,   147,   199,     0,     0,   199,
       0,   187,     0,    10,     0,    55,     0,    56,    58,   199,
      53,     0,   162,   103,   172,     0,     0,   106,   111,   107,
     108,   109,   110,   112,     0,   113,   118,   120,   122,   123,
     124,   131,   133,   132,   134,   126,   127,   128,   129,   136,
     137,   139,   140,   141,   142,   143,    37,    38,     0,    16,
      23,   199,    18,    21,    26,     0,    36,    22,    25,    48,
      24,     0,    35,     0,   155,   167,   169,     0,   164,   165,
     168,   163,     0,    13,     0,    59,     0,    54,    60,     0,
       0,     0,     0,     0,     0,     0,    86,    87,     0,   199,
      67,     0,    63,    65,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    68,    96,     0,    52,   171,     0,   178,
     180,     0,   185,   184,   177,   176,     0,     0,    50,    15,
     199,    19,    27,     0,    49,     0,   157,   159,     0,   199,
      11,    57,    85,    95,    97,    99,     0,   199,     0,     0,
       0,     0,    90,    92,    89,    91,    62,    64,    66,    61,
     170,   179,   181,     0,     0,   173,   115,    51,    20,     0,
       0,     0,     0,     0,     0,    41,    40,    42,    43,    44,
     166,   199,     0,     0,     0,     0,    94,    93,     0,     0,
      84,     0,   183,   182,   175,   174,     0,    30,    39,    28,
      29,   160,   191,    46,     0,    17,    98,   100,   101,     0,
       0,   199,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    78,     0,     0,    82,    83,    88,    34,    33,    31,
      32,    47,     0,     0,     0,   199,    79,    81,     0,     0,
      80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,   265,   151,   152,   153,
     154,   155,   156,   157,   266,   267,   294,   158,   159,    26,
      58,   106,   107,   190,   191,   268,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   242,   275,   203,   233,
     234,   204,    28,    29,   124,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    64,    40,    41,    42,   167,   168,
     169,   269,   216,   208,   209,   210,   211,    51,   103,    44,
      45,    46,    47,    48,    49,   162
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -280
static const yytype_int16 yypact[] =
{
     212,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,    77,
      77,    77,    77,    77,    77,     8,    77,    77,    77,   768,
      18,   665,  -280,  -280,  -280,  -280,  -280,  -280,   -28,  -280,
     180,    -7,    65,    68,   131,   305,  -280,   124,   278,    19,
     -37,  -280,    30,    43,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,     3,     6,    74,    71,
    -280,  -280,  -280,    67,    99,  -280,  -280,   768,   651,   768,
     768,   768,   768,   651,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,   793,   793,   793,   793,   793,   793,
     793,   793,   793,   793,  -280,  -280,   511,   768,    77,   116,
      77,  -280,   162,    98,   162,  -280,   -65,  -280,   162,   569,
    -280,    74,  -280,  -280,  -280,    31,   651,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,    92,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,   162,  -280,
    -280,   347,  -280,  -280,    94,   129,  -280,  -280,  -280,   101,
    -280,   -24,  -280,    96,  -280,  -280,  -280,   103,   104,  -280,
    -280,  -280,   107,  -280,   162,  -280,     9,  -280,  -280,   110,
     162,   111,   122,   127,   128,   768,  -280,  -280,   130,   651,
    -280,   405,  -280,   114,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,   145,  -280,  -280,    40,  -280,
     147,   149,  -280,  -280,  -280,  -280,    29,   651,    71,  -280,
     681,  -280,  -280,    13,  -280,   323,  -280,  -280,   116,   681,
    -280,  -280,  -280,   155,  -280,   198,   768,   711,   768,   768,
     156,   768,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   651,   651,  -280,  -280,  -280,  -280,   162,
     162,   323,    27,   487,   651,  -280,  -280,  -280,  -280,  -280,
    -280,   429,   162,   651,   143,   -14,  -280,  -280,   164,   166,
    -280,   172,  -280,  -280,  -280,  -280,   177,   179,  -280,   186,
     191,   197,   199,  -280,    47,  -280,  -280,  -280,  -280,   569,
     768,   768,   569,    74,   569,   323,   323,   323,   323,    77,
    -280,   220,   200,   167,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,   205,   569,   569,   768,  -280,  -280,   202,   569,
    -280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,   268,  -280,  -280,    48,    61,  -144,  -280,
    -280,  -280,  -280,  -280,  -205,  -280,  -280,  -280,  -280,   -91,
     -55,  -280,   118,   -57,  -280,   -54,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -279,  -280,    58,  -280,
      32,     0,  -108,   -31,    82,  -280,   228,   230,    93,     4,
    -280,    52,   -19,  -280,    15,  -280,  -280,  -280,  -280,  -280,
      75,   -21,  -280,  -280,   105,  -280,  -280,     2,  -280,  -280,
    -280,  -280,  -280,  -109,  -280,   -96
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -186
static const yytype_int16 yytable[] =
{
      27,   110,    43,   171,   111,   160,   213,   221,   214,     2,
     101,     2,     2,   205,   176,    39,     2,    59,    65,    63,
     177,    27,   313,    43,    50,    52,    53,    54,    55,    56,
       2,    60,    61,    62,     2,     3,    39,   117,   119,   120,
     121,   122,   123,     2,     3,    97,   328,   118,    25,   300,
      98,    67,   125,    96,   206,   192,   288,   225,   104,   108,
     160,   104,    94,    95,   259,   260,   301,   113,   166,    25,
     141,   142,   143,   144,   145,   289,   258,   102,   170,    73,
       2,     3,     4,     5,     6,     7,     8,   135,   136,   137,
     138,   105,    57,   245,   261,   215,    96,   163,    43,   213,
     317,   318,   319,   320,   173,    74,   175,    75,   254,   207,
     178,   161,   255,   164,    99,   172,   100,   212,   250,     2,
       3,     4,     5,     6,     7,     8,   309,   221,     9,   160,
     310,   131,   132,   133,   134,    87,    88,   247,   160,   139,
     140,   277,    94,    95,   150,   282,   284,    76,    77,    78,
     218,   109,   112,    43,   292,    57,   214,    10,    11,    12,
      13,    19,   114,   257,   165,     2,   161,   205,   244,   128,
     129,   130,   174,   217,   222,    15,   230,   223,   108,   226,
     160,   224,   235,   228,   229,   240,   123,    16,   227,   243,
      68,   232,    18,   115,   248,   236,   125,   166,   116,   150,
      19,    69,    70,    71,    72,   245,   237,   170,   273,   192,
     212,   238,   239,     1,   241,     2,     3,     4,     5,     6,
       7,     8,    43,   249,     9,   262,   252,    43,   299,   245,
     253,    43,   283,   285,   272,   161,   274,   280,   278,   279,
      39,   281,   297,   215,   161,   311,   315,   325,   314,   302,
     316,   303,   298,    10,    11,    12,    13,   304,   305,    14,
     306,   286,   287,    43,   290,   291,    43,   307,   150,   326,
     327,    15,   308,    43,   235,   330,    39,   150,  -185,    39,
    -184,   323,    96,    16,    17,   324,   161,   329,    18,    66,
     271,    89,    90,    91,   231,   276,    19,    92,    93,   256,
     312,   243,   126,   270,   296,   127,     0,    43,    43,    43,
      43,    43,   293,   251,     0,     0,     0,     0,     0,   150,
      39,    39,    39,    39,   322,   243,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     9,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,   321,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,   114,
       0,     0,   179,     0,     0,   180,     0,     0,     0,     0,
       0,     0,    15,   181,     0,   182,     0,   183,   184,   185,
     186,   187,   188,   189,    16,     0,   146,   147,     0,    18,
     263,     0,     0,     0,     0,   264,    15,    19,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     9,     0,     0,
       0,     0,   148,     0,     0,   219,   220,     0,     0,     0,
       0,    19,     2,     3,     4,     5,     6,     7,     8,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
       0,     0,     0,     0,   179,     0,     0,   180,     0,     0,
       0,     0,     0,     0,    15,   181,     0,   182,     0,   183,
     184,   185,   186,   187,   188,   189,    16,     0,   146,   147,
       0,    18,   109,   246,     0,     0,     0,     0,    15,    19,
       2,     3,     4,     5,     6,     7,     8,     0,     0,     9,
       0,     0,     0,     0,   148,     0,     0,   295,   220,     0,
       0,     0,     0,    19,     2,     3,     4,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,     0,     0,     0,     0,   179,     0,     0,   180,
       0,     0,     0,     0,     0,     0,    15,   181,     0,   182,
       0,   183,   184,   185,   186,   187,   188,   189,    16,     0,
     146,   147,     0,    18,   109,   207,     0,     0,     0,     0,
      15,    19,     2,     3,     4,     5,     6,     7,     8,     0,
       0,     9,     0,     0,     0,     0,   148,     0,     0,   149,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,     0,     0,     0,   179,     0,
       0,   180,     0,     0,     0,     0,     0,     0,    15,   181,
       0,   182,     0,   183,   184,   185,   186,   187,   188,   189,
      16,     0,     0,     0,     0,    18,   109,     0,     0,     0,
       0,     0,     0,    19,     2,     3,     4,     5,     6,     7,
       8,     0,     0,     9,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     5,     6,     7,
       8,     0,    10,    11,    12,    13,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      15,     0,    14,     0,     2,     3,     4,     5,     6,     7,
       8,     0,    16,     9,    15,     0,     0,    18,   115,     0,
     146,   147,     0,   116,     0,    19,    16,    17,     0,     0,
      15,    18,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    10,    11,    12,    13,   148,     0,     0,     0,
       0,     0,     0,   180,     0,    19,     0,     0,     0,     0,
      15,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       9,     0,    16,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,    19,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     9,     0,     0,     0,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,     0,    16,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,    19
};

static const yytype_int16 yycheck[] =
{
       0,    58,     0,    99,    59,    96,   115,   151,   116,     3,
       7,     3,     3,   109,    79,     0,     3,    15,     0,    19,
      85,    21,   301,    21,     9,    10,    11,    12,    13,    14,
       3,    16,    17,    18,     3,     4,    21,    68,    69,    70,
      71,    72,    73,     3,     4,    82,   325,    68,     0,    63,
      87,    79,    73,    77,   111,   109,   261,    81,    52,    57,
     151,    52,    43,    44,    51,    52,    80,    67,    99,    21,
      89,    90,    91,    92,    93,    48,   220,    74,    99,    86,
       3,     4,     5,     6,     7,     8,     9,    83,    84,    85,
      86,    85,    84,   189,    81,   116,    77,    97,    96,   208,
     305,   306,   307,   308,   102,    40,   104,    39,    79,    78,
     108,    96,    83,    98,    84,   100,    73,   115,    78,     3,
       4,     5,     6,     7,     8,     9,    79,   271,    12,   220,
      83,    79,    80,    81,    82,    11,    12,   191,   229,    87,
      88,   237,    43,    44,    96,   253,   254,    16,    17,    18,
     148,    77,    85,   151,   263,    84,   264,    41,    42,    43,
      44,    84,    46,   218,    48,     3,   151,   263,   189,    76,
      77,    78,    74,    81,    80,    59,   174,    48,   176,    83,
     271,    80,   180,    79,    77,   185,   217,    71,    85,   189,
      10,    81,    76,    77,    80,    84,   217,   228,    82,   151,
      84,    21,    22,    23,    24,   301,    84,   228,    10,   263,
     208,    84,    84,     1,    84,     3,     4,     5,     6,     7,
       8,     9,   220,    78,    12,   223,    79,   225,    85,   325,
      81,   229,   253,   254,    79,   220,   236,    81,   238,   239,
     225,   241,   273,   264,   229,   299,   303,    80,   302,    85,
     304,    85,   273,    41,    42,    43,    44,    85,    81,    47,
      81,   259,   260,   261,   262,   263,   264,    81,   220,   323,
     324,    59,    81,   271,   272,   329,   261,   229,    81,   264,
      81,    61,    77,    71,    72,    85,   271,    85,    76,    21,
     229,    13,    14,    15,   176,   237,    84,    19,    20,   217,
     300,   301,    74,   228,   272,    75,    -1,   305,   306,   307,
     308,   309,   264,   208,    -1,    -1,    -1,    -1,    -1,   271,
     305,   306,   307,   308,   309,   325,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    31,    32,    33,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,   309,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    46,
      -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    62,    -1,    64,    65,    66,
      67,    68,    69,    70,    71,    -1,    49,    50,    -1,    76,
      77,    -1,    -1,    -1,    -1,    82,    59,    84,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,
      -1,    84,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    62,    -1,    64,
      65,    66,    67,    68,    69,    70,    71,    -1,    49,    50,
      -1,    76,    77,    78,    -1,    -1,    -1,    -1,    59,    84,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    62,
      -1,    64,    65,    66,    67,    68,    69,    70,    71,    -1,
      49,    50,    -1,    76,    77,    78,    -1,    -1,    -1,    -1,
      59,    84,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    62,    -1,    64,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    12,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    41,    42,    43,    44,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      59,    -1,    47,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    71,    12,    59,    -1,    -1,    76,    77,    -1,
      49,    50,    -1,    82,    -1,    84,    71,    72,    -1,    -1,
      59,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    41,    42,    43,    44,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    84,    -1,    -1,    -1,    -1,
      59,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    12,    -1,    -1,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    12,
      41,    42,    43,    44,    47,    59,    71,    72,    76,    84,
      89,    90,    91,    92,    93,    94,   107,   129,   130,   131,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   155,   157,   158,   159,   160,   161,   162,
     142,   155,   142,   142,   142,   142,   142,    84,   108,   155,
     142,   142,   142,   129,   142,     0,    91,    79,    10,    21,
      22,    23,    24,    86,    40,    39,    16,    17,    18,    31,
      32,    33,    34,    35,    36,    37,    38,    11,    12,    13,
      14,    15,    19,    20,    43,    44,    77,    82,    87,    84,
      73,     7,    74,   156,    52,    85,   109,   110,   155,    77,
     111,   108,    85,   129,    46,    77,    82,   131,   149,   131,
     131,   131,   131,   131,   132,   149,   134,   135,   136,   136,
     136,   139,   139,   139,   139,   137,   137,   137,   137,   139,
     139,   140,   140,   140,   140,   140,    49,    50,    75,    78,
      94,    95,    96,    97,    98,    99,   100,   101,   105,   106,
     107,   142,   163,   129,   142,    48,   131,   146,   147,   148,
     149,   163,   142,   155,    74,   155,    79,    85,   155,    49,
      52,    60,    62,    64,    65,    66,    67,    68,    69,    70,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   126,   129,   163,   111,    78,   151,   152,
     153,   154,   155,   161,   130,   149,   150,    81,   155,    78,
      79,    96,    80,    48,    80,    81,    83,    85,    79,    77,
     155,   110,    81,   127,   128,   155,    84,    84,    84,    84,
     129,    84,   124,   129,   149,   163,    78,   113,    80,    78,
      78,   152,    79,    81,    79,    83,   132,   108,    96,    51,
      52,    81,   155,    77,    82,    94,   102,   103,   113,   149,
     148,    95,    79,    10,   129,   125,   126,   163,   129,   129,
      81,   129,   130,   149,   130,   149,   155,   155,   102,    48,
     155,   155,   161,    94,   104,    78,   128,   131,   149,    85,
      63,    80,    85,    85,    85,    81,    81,    81,    81,    79,
      83,   113,   129,   124,   113,   111,   113,   102,   102,   102,
     102,    94,   142,    61,    85,    80,   113,   113,   124,    85,
     113
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
#line 152 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 158 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 170 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 182 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        // SAFE_DELETE($<Object>1);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 189 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 196 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 203 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 210 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "JSExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 219 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression Version");

        QMLEntity* pName = (yyvsp[(2) - (3)].Object);
        QMLEntity* pVersion = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pName->position(), pContext, pName, pVersion);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 236 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression Version TOKEN_AS Identifier");

        QMLEntity* pName = (yyvsp[(2) - (5)].Object);
        QMLEntity* pVersion = (yyvsp[(3) - (5)].Object);
        QMLEntity* pAs = (yyvsp[(5) - (5)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pName->position(), pContext, pName, pVersion, pAs);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 254 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression");

        QMLEntity* pName = (yyvsp[(2) - (2)].Object);

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLImport(pName->position(), pContext, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 270 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ImportStatement", "JSMemberExpression TOKEN_AS Identifier");

        QMLEntity* pName = (yyvsp[(2) - (4)].Object);
        QMLEntity* pAs = (yyvsp[(4) - (4)].Object);

        if (pName != nullptr && pAs != nullptr)
        {
            (yyval.Object) = new QMLImport(pName->position(), pContext, pName, nullptr, pAs);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 289 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA JSMemberExpression");

        QMLEntity* pStatement = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLPragma(pStatement->position(), pStatement);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 300 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "JSMemberExpression '{' ItemContents '}'");

        QMLEntity* pName = (yyvsp[(1) - (4)].Object);
        QMLItem* pComplexItem = dynamic_cast<QMLItem*>((yyvsp[(3) - (4)].Object));

        if (pName != nullptr && pComplexItem != nullptr)
        {
            pComplexItem->setPosition(pName->position());
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
#line 320 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "JSMemberExpression '{' '}'");

        QMLEntity* pName = (yyvsp[(1) - (3)].Object);
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

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 340 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON JSMemberExpression '{' ItemContents '}'");

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
            pContents = new QMLItem(pContext->position(), pName->clone());
        }

        QMLOnExpression* pExpression = new QMLOnExpression(pName->position(), pTarget, pName->clone(), pContents);

        SAFE_DELETE(pName);

        (yyval.Object) = pExpression;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 372 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 391 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 406 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 423 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 430 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 437 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 444 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 451 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 460 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 467 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 476 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 502 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 528 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 551 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 579 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 607 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 632 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 657 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mNone;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 662 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (yyvsp[(1) - (1)].Integer);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 669 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mDefault;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 674 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mReadonly;
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 681 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 703 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "JSMemberExpression ':' PropertyContent");

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
#line 727 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 734 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "ItemArray");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 741 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 748 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 757 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArray", "'[' ItemArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 766 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 786 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 811 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 818 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 827 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 850 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 875 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 892 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 917 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 924 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 933 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 940 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 963 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 983 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1003 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1028 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' Empty '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1035 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        QMLEntity* pEntity = (yyvsp[(2) - (3)].Object);

        pEntity = QMLComplexEntity::makeBlock(pEntity);

        (yyval.Object) = pEntity;
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1048 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1066 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1083 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1090 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1099 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 1106 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 1113 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 1120 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 1127 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 1134 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Switch");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1141 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Case");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1148 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1155 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1162 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1169 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1178 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1198 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1227 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1244 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1272 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pInitialization = new QMLEntity(pContext->position());
        QMLEntity* pCondition = (yyvsp[(3) - (5)].Object);
        QMLEntity* pIncrementation = new QMLEntity(pContext->position());
        QMLEntity* pContent = (yyvsp[(5) - (5)].Object);

        pContent = QMLComplexEntity::makeBlock(pContent);

        QMLFor* pNewFor = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
        pNewFor->setIsWhile(true);

        (yyval.Object) = pNewFor;
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1289 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1308 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (3)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1315 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = new QMLEntity(pContext->position(), "default");

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1324 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoBreak);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1331 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoContinue);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1338 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1345 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1352 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1361 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1366 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1373 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Empty");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1380 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1389 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1417 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpression", "JSExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1426 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        QMLEntity* pVariable = (yyvsp[(1) - (1)].Object);

        QMLComplexEntity* pVariables = new QMLComplexEntity(pVariable->position());
        pVariables->contents() << pVariable;

        (yyval.Object) = pVariables;
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1438 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1462 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1469 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1482 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1497 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1504 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1525 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1532 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1539 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1556 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAddAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1573 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSubAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1590 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMulAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1607 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLEntity* pLeft = (yyvsp[(1) - (3)].Object);
        QMLEntity* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDivAssign);
        }
        else
        {
            (yyval.Object) = new QMLEntity(pContext->position());
        }
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1624 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1643 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1648 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1655 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1662 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1678 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1687 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1694 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1713 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1718 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1735 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1740 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1755 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1770 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1787 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1792 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1807 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1822 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1837 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1854 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1859 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1874 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1889 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1904 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1921 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1926 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1941 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1958 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1963 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1978 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1993 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2008 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2023 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2040 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 2045 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_INC");

        QMLEntity* pEntity = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement, true);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 2054 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoIncrement);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 2061 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_DEC");

        QMLEntity* pEntity = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement, true);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 2070 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_DEC JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoDecrement);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 2079 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NOT JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNot);
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 2088 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NOT_NOT JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNotNot);
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 2097 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_TYPEOF JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoTypeof);
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 2106 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_SUB JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoMinus);
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2115 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "TOKEN_NEW JSMemberExpression");

        QMLEntity* pEntity = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pEntity->position(), pEntity, QMLUnaryOperation::uoNew);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2126 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2133 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2155 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2162 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2182 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2189 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2208 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2215 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2222 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        QMLEntity* pEntity = (yyvsp[(2) - (3)].Object);

        pEntity->setIsParenthesized(true);

        (yyval.Object) = pEntity;
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2235 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = new QMLComplexEntity(pContext->position());
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2242 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2251 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2265 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2279 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgument", "TOKEN_PROPERTY");

        (yyval.Object) = new QMLIdentifier(pContext->position(), "property");
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2286 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgument", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 2293 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgument", "JSAssignmentExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 2302 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' JSAttributes '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2309 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' '}'");

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
        pComplex->setIsObject(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2319 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "TOKEN_DIMENSION");

        QMLComplexEntity* pComplex = new QMLComplexEntity(pContext->position());
        pComplex->setIsArray(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2329 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'[' JSArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2338 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2350 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2362 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2378 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2396 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2410 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2424 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2431 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma ','");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 2440 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2463 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 2488 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeName", "Literal");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 2495 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeName", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 2504 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Identifier", "TOKEN_IDENTIFIER");

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

  case 187:

/* Line 1455 of yacc.c  */
#line 2522 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Version", "TOKEN_REALCONSTANT");

        (yyval.Object) =  new QMLEntity(pContext->position(), pContext->tokenValue());
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 2531 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Value", "Boolean");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 2538 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Value", "Integer");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 2545 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Value", "Double");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 2552 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Value", "Literal");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 2559 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Value", "SpecialValue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 2568 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 2575 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 2582 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLEntity(pContext->position(), QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 2589 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 197:

/* Line 1455 of yacc.c  */
#line 2605 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLSpecialValue(pContext->position(), QMLSpecialValue::svNull);
    ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 2610 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLSpecialValue(pContext->position(), QMLSpecialValue::svUndefined);
    ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 2616 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 5050 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 2620 "D:/Work/Projects/qt-plus/source/bison/QML.y"


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

