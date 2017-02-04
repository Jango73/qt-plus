
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
#line 9 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"

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



/* Line 189 of yacc.c  */
#line 102 "C:/User/E487027/Work/Projects/qt-plus/src/cpp/QMLTree/QMLGrammarParser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
     TOKEN_INC = 342,
     TOKEN_DEC = 343,
     TOKEN_COMPLEMENT = 344,
     TOKEN_DIMENSION = 345,
     TOKEN_IMPORT = 500,
     TOKEN_PROPERTY = 501,
     TOKEN_ALIAS = 502,
     TOKEN_VAR = 503,
     TOKEN_BOOL = 504,
     TOKEN_INT = 505,
     TOKEN_REAL = 506,
     TOKEN_STRING = 507,
     TOKEN_COLOR = 508,
     TOKEN_FUNCTION = 509,
     TOKEN_IF = 510,
     TOKEN_ELSE = 511,
     TOKEN_FOR = 512,
     TOKEN_WHILE = 513,
     TOKEN_BREAK = 514,
     TOKEN_CONTINUE = 515,
     TOKEN_WITH = 516,
     TOKEN_RETURN = 517,
     TOKEN_TYPEOF = 518,
     TOKEN_PRAGMA = 519,
     TOKEN_ON = 520,
     TOKEN_AS = 521
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 37 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;



/* Line 214 of yacc.c  */
#line 213 "C:/User/E487027/Work/Projects/qt-plus/src/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "C:/User/E487027/Work/Projects/qt-plus/src/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   522

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      74,    75,     2,     2,    70,     2,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    71,
       2,     2,     2,    76,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,     2,    67,     2,     2,     2,     2,
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
      38,    39,    40,    41,    42,    43,     2,     2,     2,     2,
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
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    20,
      26,    29,    32,    37,    41,    48,    52,    54,    57,    61,
      63,    65,    67,    69,    71,    74,    78,    84,    90,    96,
      98,   100,   102,   104,   106,   110,   114,   118,   124,   126,
     128,   130,   132,   134,   139,   143,   146,   148,   151,   153,
     157,   159,   162,   164,   167,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   191,   199,   209,   215,   217,   219,
     225,   228,   230,   232,   235,   237,   239,   242,   244,   246,
     250,   252,   256,   258,   262,   264,   268,   270,   276,   278,
     282,   284,   288,   290,   294,   296,   300,   304,   308,   312,
     314,   318,   322,   326,   330,   332,   336,   340,   342,   346,
     350,   354,   358,   360,   363,   366,   369,   371,   375,   380,
     382,   387,   389,   391,   395,   397,   399,   401,   403,   407,
     411,   415,   417,   421,   423,   427,   429,   433,   435,   437,
     439,   441,   443,   447,   450,   452,   455,   457,   460,   464,
     468,   470,   474,   478,   480,   482,   484,   486,   488,   490,
     492,   494,   496,   498
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      78,     0,    -1,    79,    -1,    80,    -1,    79,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    44,   140,   142,    -1,
      44,   140,   142,    65,   141,    -1,    44,   147,    -1,    63,
     140,    -1,   141,    66,    85,    67,    -1,   141,    66,    67,
      -1,   141,    64,   141,    66,    85,    67,    -1,    68,    85,
      69,    -1,    86,    -1,    85,    86,    -1,    85,    70,    86,
      -1,    90,    -1,    87,    -1,    83,    -1,    92,    -1,    88,
      -1,    88,    71,    -1,    45,    89,   141,    -1,    45,    89,
     141,    72,    91,    -1,    45,    52,   141,    72,    91,    -1,
      45,    46,   141,    72,    91,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,   140,    72,    91,    -1,
      45,    72,    91,    -1,    52,    72,    91,    -1,   140,    73,
      52,    72,    91,    -1,    83,    -1,    84,    -1,    98,    -1,
     131,    -1,   136,    -1,    53,   141,    93,    96,    -1,    74,
      94,    75,    -1,    74,    75,    -1,    95,    -1,    94,    95,
      -1,   141,    -1,    66,    97,    67,    -1,    98,    -1,    97,
      98,    -1,    99,    -1,    99,    71,    -1,    96,    -1,   108,
      -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,    54,    74,   112,    75,    98,
      -1,    54,    74,   112,    75,    98,    55,    98,    -1,    56,
      74,   109,    71,   107,    71,   107,    75,    98,    -1,    57,
      74,   112,    75,    98,    -1,    58,    -1,    59,    -1,    60,
      74,   112,    75,    98,    -1,    61,   107,    -1,   148,    -1,
     112,    -1,    47,   110,    -1,   112,    -1,   148,    -1,    47,
     110,    -1,   112,    -1,   111,    -1,   110,    70,   111,    -1,
     141,    -1,   141,     8,   113,    -1,   113,    -1,   113,    70,
     112,    -1,   114,    -1,   114,     8,   113,    -1,   115,    -1,
     115,    76,   113,    72,   113,    -1,   116,    -1,   116,    38,
     115,    -1,   117,    -1,   117,    37,   116,    -1,   118,    -1,
     118,    14,   117,    -1,   119,    -1,   119,    33,   118,    -1,
     119,    34,   118,    -1,   119,    35,   118,    -1,   119,    36,
     118,    -1,   120,    -1,   119,    29,   120,    -1,   119,    31,
     120,    -1,   119,    30,   120,    -1,   119,    32,   120,    -1,
     121,    -1,   121,     9,   120,    -1,   121,    10,   120,    -1,
     122,    -1,   122,    11,   121,    -1,   122,    12,   121,    -1,
     122,    17,   121,    -1,   122,    18,   121,    -1,   123,    -1,
     123,   134,    -1,   135,   123,    -1,    10,   123,    -1,   124,
      -1,   124,    73,   123,    -1,   124,    68,   112,    69,    -1,
     125,    -1,   125,    74,   126,    75,    -1,   141,    -1,   143,
      -1,    74,   112,    75,    -1,   148,    -1,   127,    -1,   113,
      -1,   128,    -1,   127,    70,   113,    -1,   127,    70,   128,
      -1,    66,   129,    67,    -1,   130,    -1,   129,    70,   130,
      -1,    90,    -1,    68,   132,    69,    -1,   133,    -1,   132,
      70,   133,    -1,   143,    -1,    40,    -1,    41,    -1,    39,
      -1,    62,    -1,    66,   137,    67,    -1,    66,    67,    -1,
     138,    -1,   137,   138,    -1,   139,    -1,   139,    70,    -1,
     147,    72,   143,    -1,   147,    72,   136,    -1,   141,    -1,
     140,    73,   141,    -1,   140,    73,    52,    -1,     3,    -1,
       7,    -1,   144,    -1,   145,    -1,   146,    -1,   147,    -1,
       5,    -1,     6,    -1,     7,    -1,     4,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   131,   141,   153,   158,   163,   177,   195,
     213,   231,   237,   250,   258,   273,   280,   297,   310,   325,
     330,   335,   340,   347,   352,   359,   374,   390,   406,   423,
     428,   433,   438,   443,   450,   459,   467,   475,   486,   491,
     496,   501,   506,   513,   523,   527,   534,   539,   548,   554,
     561,   571,   586,   591,   598,   603,   608,   613,   618,   623,
     628,   633,   638,   645,   653,   664,   676,   688,   695,   702,
     709,   716,   721,   728,   733,   740,   745,   750,   757,   762,
     771,   776,   785,   795,   810,   815,   825,   830,   841,   846,
     856,   861,   871,   876,   886,   891,   899,   907,   915,   925,
     930,   938,   946,   954,   964,   969,   977,   987,   992,  1000,
    1008,  1016,  1026,  1031,  1036,  1041,  1048,  1053,  1086,  1093,
    1098,  1108,  1113,  1118,  1125,  1130,  1137,  1151,  1156,  1173,
    1180,  1187,  1192,  1199,  1205,  1212,  1217,  1224,  1230,  1235,
    1242,  1247,  1254,  1259,  1266,  1271,  1290,  1295,  1302,  1320,
    1341,  1346,  1358,  1370,  1386,  1393,  1398,  1403,  1408,  1415,
    1422,  1429,  1436,  1452
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
  "TOKEN_LOGICAL_OR", "TOKEN_NOT", "TOKEN_INC", "TOKEN_DEC",
  "TOKEN_COMPLEMENT", "TOKEN_DIMENSION", "TOKEN_IMPORT", "TOKEN_PROPERTY",
  "TOKEN_ALIAS", "TOKEN_VAR", "TOKEN_BOOL", "TOKEN_INT", "TOKEN_REAL",
  "TOKEN_STRING", "TOKEN_COLOR", "TOKEN_FUNCTION", "TOKEN_IF",
  "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_WHILE", "TOKEN_BREAK",
  "TOKEN_CONTINUE", "TOKEN_WITH", "TOKEN_RETURN", "TOKEN_TYPEOF",
  "TOKEN_PRAGMA", "TOKEN_ON", "TOKEN_AS", "'{'", "'}'", "'['", "']'",
  "','", "';'", "':'", "'.'", "'('", "')'", "'?'", "$accept", "File",
  "Declarations", "Declaration", "ImportStatement", "PragmaStatement",
  "Item", "ItemArray", "ItemContents", "ItemContent",
  "PropertyDeclaration", "PropertyDeclarationNoColon", "PropertyType",
  "PropertyAssignment", "PropertyContent", "JSFunction",
  "JSFunctionParameterList", "JSFunctionParameters", "JSFunctionParameter",
  "JSStatementBlock", "JSStatements", "JSStatement", "JSStatementNoColon",
  "JSStatement_If", "JSStatement_For", "JSStatement_While",
  "JSStatement_Break", "JSStatement_Continue", "JSStatement_With",
  "JSStatement_Return", "JSExpressionOpt", "JSVariablesOrExpression",
  "JSVariablesOrExpressionOpt", "JSVariables", "JSVariable",
  "JSExpression", "JSAssignmentExpression", "JSConditionalExpression",
  "JSOrExpression", "JSAndExpression", "JSBitwiseAndExpression",
  "JSEqualityExpression", "JSRelationalExpression", "JSAdditiveExpression",
  "JSMultiplicativeExpression", "JSUnaryExpression", "JSMemberExpression",
  "JSFunctionCall", "JSPrimaryExpression", "JSArgumentListOpt",
  "JSArgumentList", "JSInitializerBlock", "JSInitializers",
  "JSInitializer", "JSArrayInitializerBlock", "JSArrayInitializers",
  "JSArrayInitializer", "JSIncrementOperator", "JSUnaryOperator",
  "JSONObject", "JSONAttributes", "JSONAttribute", "JSONAttributeNoComma",
  "QualifiedIdentifier", "Identifier", "Version", "Value", "Boolean",
  "Integer", "Double", "Literal", "Empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   522,   300,   301,   302,   303,   304,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   123,   125,    91,    93,
      44,    59,    58,    46,    40,    41,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    79,    79,    80,    80,    80,    81,    81,
      81,    82,    83,    83,    83,    84,    85,    85,    85,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    92,    93,    93,    94,    94,    95,    96,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   102,   103,   104,   105,
     106,   107,   107,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   120,   120,   120,   121,   121,   121,
     121,   121,   122,   122,   122,   122,   123,   123,   123,   124,
     124,   125,   125,   125,   126,   126,   127,   127,   127,   127,
     128,   129,   129,   130,   131,   132,   132,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   140,   141,   142,   143,   143,   143,   143,   144,
     145,   146,   147,   148
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     5,
       2,     2,     4,     3,     6,     3,     1,     2,     3,     1,
       1,     1,     1,     1,     2,     3,     5,     5,     5,     1,
       1,     1,     1,     1,     3,     3,     3,     5,     1,     1,
       1,     1,     1,     4,     3,     2,     1,     2,     1,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     9,     5,     1,     1,     5,
       2,     1,     1,     2,     1,     1,     2,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     2,     2,     2,     1,     3,     4,     1,
       4,     1,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     2,     1,     2,     1,     2,     3,     3,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   153,     0,     0,     0,     2,     3,     5,     6,     7,
       0,   162,     0,   150,    10,    11,     1,     4,     0,     0,
     154,     0,     8,     0,     0,     0,     0,    13,    21,     0,
      16,    20,    23,    19,    22,     0,   150,   152,   151,     0,
       0,     0,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,    12,     0,    17,    24,     0,     0,     9,     0,
       0,     0,   159,   160,   161,     0,   140,     0,     0,     0,
       0,    67,    68,     0,   163,   141,     0,     0,     0,    38,
      39,    35,    54,    40,    52,    56,    57,    58,    59,    60,
      61,    62,    55,    74,    82,    84,    86,    88,    90,    92,
      94,    99,   104,   107,   112,   116,   119,    41,     0,    42,
     121,   122,   155,   156,   157,   158,    25,    36,     0,     0,
      18,    34,   152,    14,     0,     0,   115,   121,    73,    78,
      80,     0,   163,     0,     0,    70,    72,    71,     0,   143,
       0,    50,     0,   144,   146,   158,     0,     0,   135,   137,
       0,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   113,     0,     0,   163,   114,     0,
      45,     0,    46,    48,    43,     0,    28,    27,     0,     0,
       0,     0,     0,    77,    75,     0,     0,    49,    51,   142,
     145,     0,   147,     0,    15,   134,     0,   123,    83,    85,
       0,    89,    91,    93,   100,   102,   101,   103,    95,    96,
      97,    98,   105,   106,   108,   109,   110,   111,     0,   117,
       0,   126,     0,   125,   127,   124,    26,    44,    47,    37,
      79,    81,     0,    76,   163,     0,     0,     0,   149,   148,
     136,     0,   118,     0,   133,     0,   131,   120,     0,    63,
       0,    66,    69,    87,   130,     0,   128,   129,     0,   163,
     132,    64,     0,     0,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    28,    80,    29,    30,
      31,    32,    49,    33,    81,    34,   119,   181,   182,    82,
     140,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     135,    92,   192,   128,   129,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   232,
     233,   234,   255,   256,   107,   147,   148,   174,   108,   109,
     142,   143,   144,    35,   127,    22,   111,   112,   113,   114,
     115,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -208
static const yytype_int16 yypact[] =
{
      58,  -208,    60,    21,    43,    58,  -208,  -208,  -208,  -208,
     -32,  -208,    15,  -208,  -208,   -27,  -208,  -208,    21,   131,
    -208,    22,   -13,   -11,   186,     7,    21,  -208,  -208,    39,
    -208,  -208,    18,  -208,  -208,    55,   -32,  -208,  -208,    21,
     141,    21,  -208,  -208,  -208,  -208,  -208,    21,    91,    21,
      91,    19,  -208,   141,  -208,  -208,    91,    24,  -208,    59,
      38,    48,  -208,  -208,  -208,   157,  -208,    21,    31,    63,
      69,  -208,  -208,    82,   340,  -208,   213,   366,   340,  -208,
    -208,  -208,  -208,  -208,    62,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,    88,   163,   104,   149,   138,   178,
     284,  -208,   107,   238,   137,    35,   121,  -208,   157,  -208,
     -32,  -208,  -208,  -208,  -208,  -208,   125,  -208,     8,   140,
    -208,  -208,   136,  -208,    91,    91,  -208,  -208,   142,  -208,
     205,   340,   318,   340,   340,  -208,  -208,  -208,   302,  -208,
     237,  -208,    32,  -208,   152,   167,    70,   120,  -208,  -208,
     154,  -208,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,  -208,  -208,  -208,   340,   157,   327,  -208,    91,
    -208,    12,  -208,  -208,  -208,    91,  -208,  -208,    21,   340,
     170,    21,   177,  -208,  -208,   176,   179,  -208,  -208,  -208,
    -208,   167,  -208,   162,  -208,  -208,   220,  -208,  -208,  -208,
     181,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,   188,  -208,
     169,  -208,   184,   196,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,   302,   142,   340,   302,   302,    33,  -208,  -208,
    -208,   340,  -208,   206,  -208,   -39,  -208,  -208,   327,   222,
     210,  -208,  -208,  -208,  -208,   169,  -208,  -208,   302,   340,
    -208,  -208,   193,   302,  -208
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,   277,  -208,  -208,    30,  -208,   -23,   -15,
    -208,  -208,  -208,  -207,   -43,  -208,  -208,  -208,   102,   166,
    -208,   -72,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -184,  -208,  -208,    95,   100,   -62,  -144,  -208,   134,   144,
     133,    99,  -208,    44,   183,  -208,   -57,  -208,  -208,  -208,
    -208,    34,  -208,    36,  -208,  -208,    96,  -208,  -208,   123,
    -208,   168,  -208,   197,     0,  -208,   -71,  -208,  -208,  -208,
      -1,  -112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      10,    14,    13,    13,   141,    10,   149,   117,   126,   209,
     210,     1,   136,   121,    54,     1,   150,    59,    23,    36,
     194,    38,    20,   254,     1,     1,    51,     1,   264,    36,
       9,   265,    18,   231,    19,     9,    11,    11,   120,    58,
      36,    60,     1,    16,    54,   241,    21,    61,   110,   116,
     110,   178,    39,    36,   146,    40,   110,    38,   254,    36,
     260,     1,     1,     1,    11,   235,   141,   130,   198,   190,
     193,   195,   196,     1,    37,   145,   122,    36,    79,    50,
      79,   186,   187,   180,    24,   272,    79,   237,    21,    55,
     208,    25,    26,   118,     1,    11,    62,    63,    64,   199,
     139,    65,     2,   175,    24,   131,    52,   263,   176,    53,
     124,    25,    26,   228,   266,    24,   166,   167,   183,   229,
     125,     3,    25,    26,   110,   110,   123,    56,    57,    53,
      66,    54,   249,   151,     1,   149,   236,   132,    67,   204,
      53,   201,   239,   133,     1,    68,    36,    69,    70,    71,
      72,    73,    74,    75,    79,    79,   134,    76,   152,    77,
       1,    11,    62,    63,    64,    78,    11,    62,    63,    64,
     259,   153,     1,   261,   262,   156,    24,   172,   173,   110,
     154,   183,   136,    25,    26,   110,    24,   155,   130,   205,
     206,   130,   157,    25,    26,   177,   271,   179,    27,    12,
      15,   274,   214,   215,   216,   217,   138,   136,   185,    79,
     222,   223,   188,   189,   253,    79,     1,    11,    62,    63,
      64,    25,   202,    65,    11,    62,    63,    64,   247,   207,
      13,    78,    41,    42,    43,    44,    45,    46,    47,   203,
       1,    11,    62,    63,    64,   242,   201,    65,   244,   168,
     169,   245,    66,   251,   246,   170,   171,   252,    48,   257,
      67,   218,   219,   220,   221,    13,   258,    68,   273,    69,
      70,    71,    72,    73,    74,    75,    66,   268,    48,   138,
     139,   269,    17,   238,    67,   184,   243,    78,   240,   211,
     213,    68,   267,    69,    70,    71,    72,    73,    74,    75,
     212,   270,   250,   138,   197,     1,    11,    62,    63,    64,
     200,    78,    65,   158,   159,   160,   161,   162,   163,   164,
     165,     1,    11,    62,    63,    64,   248,     0,    65,     0,
       1,    11,    62,    63,    64,     0,     0,    65,     0,     0,
       0,    66,     0,     1,    11,    62,    63,    64,     0,    67,
      65,   224,   225,   226,   227,     0,    68,    66,    69,    70,
      71,    72,    73,    74,    75,   191,    66,     0,   138,     1,
      11,    62,    63,    64,     0,     0,    78,     0,     0,    66,
      75,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,    78,   230,     0,     0,     0,     0,     0,     0,
       0,    78,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,    78,     0,     0,     0,    25,    26
};

static const yytype_int16 yycheck[] =
{
       0,     2,     2,     3,    76,     5,    77,    50,    65,   153,
     154,     3,    74,    56,    29,     3,    78,    40,    18,    19,
     132,    21,     7,   230,     3,     3,    26,     3,    67,    29,
       0,    70,    64,   177,    66,     5,     4,     4,    53,    39,
      40,    41,     3,     0,    59,   189,    73,    47,    48,    49,
      50,   108,    65,    53,    77,    66,    56,    57,   265,    59,
     244,     3,     3,     3,     4,   177,   138,    67,   140,   131,
     132,   133,   134,     3,    52,    76,    52,    77,    48,    72,
      50,   124,   125,    75,    45,   269,    56,    75,    73,    71,
     152,    52,    53,    74,     3,     4,     5,     6,     7,    67,
      67,    10,    44,    68,    45,    74,    67,   251,    73,    70,
      72,    52,    53,   175,   258,    45,     9,    10,   118,   176,
      72,    63,    52,    53,   124,   125,    67,    72,    73,    70,
      39,   146,   203,    71,     3,   206,   179,    74,    47,    69,
      70,   142,   185,    74,     3,    54,   146,    56,    57,    58,
      59,    60,    61,    62,   124,   125,    74,    66,    70,    68,
       3,     4,     5,     6,     7,    74,     4,     5,     6,     7,
     242,     8,     3,   245,   246,    37,    45,    40,    41,   179,
      76,   181,   244,    52,    53,   185,    45,    38,   188,    69,
      70,   191,    14,    52,    53,    74,   268,    72,    67,     2,
       3,   273,   158,   159,   160,   161,    66,   269,    72,   179,
     166,   167,    70,     8,    45,   185,     3,     4,     5,     6,
       7,    52,    70,    10,     4,     5,     6,     7,    66,    75,
     230,    74,    46,    47,    48,    49,    50,    51,    52,    72,
       3,     4,     5,     6,     7,    75,   247,    10,    71,    11,
      12,    75,    39,    72,    75,    17,    18,    69,    72,    75,
      47,   162,   163,   164,   165,   265,    70,    54,    75,    56,
      57,    58,    59,    60,    61,    62,    39,    55,    72,    66,
      67,    71,     5,   181,    47,   119,   191,    74,   188,   155,
     157,    54,   258,    56,    57,    58,    59,    60,    61,    62,
     156,   265,   206,    66,    67,     3,     4,     5,     6,     7,
     142,    74,    10,    29,    30,    31,    32,    33,    34,    35,
      36,     3,     4,     5,     6,     7,   203,    -1,    10,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      -1,    39,    -1,     3,     4,     5,     6,     7,    -1,    47,
      10,   168,   169,   170,   171,    -1,    54,    39,    56,    57,
      58,    59,    60,    61,    62,    47,    39,    -1,    66,     3,
       4,     5,     6,     7,    -1,    -1,    74,    -1,    -1,    39,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    74,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    74,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    63,    78,    79,    80,    81,    82,    83,
     141,     4,   140,   141,   147,   140,     0,    80,    64,    66,
       7,    73,   142,   141,    45,    52,    53,    67,    83,    85,
      86,    87,    88,    90,    92,   140,   141,    52,   141,    65,
      66,    46,    47,    48,    49,    50,    51,    52,    72,    89,
      72,   141,    67,    70,    86,    71,    72,    73,   141,    85,
     141,   141,     5,     6,     7,    10,    39,    47,    54,    56,
      57,    58,    59,    60,    61,    62,    66,    68,    74,    83,
      84,    91,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   108,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   131,   135,   136,
     141,   143,   144,   145,   146,   147,   141,    91,    74,    93,
      86,    91,    52,    67,    72,    72,   123,   141,   110,   111,
     141,    74,    74,    74,    74,   107,   112,   148,    66,    67,
      97,    98,   137,   138,   139,   147,    85,   132,   133,   143,
     112,    71,    70,     8,    76,    38,    37,    14,    29,    30,
      31,    32,    33,    34,    35,    36,     9,    10,    11,    12,
      17,    18,    40,    41,   134,    68,    73,    74,   123,    72,
      75,    94,    95,   141,    96,    72,    91,    91,    70,     8,
     112,    47,   109,   112,   148,   112,   112,    67,    98,    67,
     138,   147,    70,    72,    69,    69,    70,    75,   112,   113,
     113,   115,   116,   117,   120,   120,   120,   120,   118,   118,
     118,   118,   120,   120,   121,   121,   121,   121,   112,   123,
      66,   113,   126,   127,   128,   148,    91,    75,    95,    91,
     111,   113,    75,   110,    71,    75,    75,    66,   136,   143,
     133,    72,    69,    45,    90,   129,   130,    75,    70,    98,
     107,    98,    98,   113,    67,    70,   113,   128,    55,    71,
     130,    98,   107,    75,    98
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
#line 126 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 132 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(1) - (1)].Object);

        if (pItem != NULL)
        {
            pContext->item().contents().append(pItem);
        }
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 142 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        if (pItem != NULL)
        {
            pContext->item().contents().append(pItem);
        }
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 154 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 159 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 164 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 178 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (3)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (3)].Object);

        if (pName != NULL && pVersion != NULL)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            (yyval.Object) = NULL;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 196 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (5)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (5)].Object);

        if (pName != NULL && pVersion != NULL)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
        }
        else
        {
            (yyval.Object) = NULL;
        }

        SAFE_DELETE(pName);
        SAFE_DELETE(pVersion);
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 214 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (2)].Object);

        if (pName != NULL)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), "");
        }
        else
        {
            (yyval.Object) = NULL;
        }

        SAFE_DELETE(pName);
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 232 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 238 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        if (pComplexItem != NULL)
        {
            pComplexItem->setName(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 251 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 259 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (6)].Object);
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(5) - (6)].Object));

        if (pComplexItem != NULL)
        {
            pComplexItem->setName(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 274 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 281 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pOldItem = (yyvsp[(1) - (1)].Object);

        if (pOldItem != NULL)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem();
            pComplexItem->contents().append(pOldItem);

            (yyval.Object) = pComplexItem;
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 298 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pNewItem = (yyvsp[(2) - (2)].Object);

        if (pComplexItem != NULL && pNewItem != NULL)
        {
            pComplexItem->contents().append(pNewItem);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 311 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pNewItem = (yyvsp[(3) - (3)].Object);

        if (pComplexItem != NULL && pNewItem != NULL)
        {
            pComplexItem->contents().append(pNewItem);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 326 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 331 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 336 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 341 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 348 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 353 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 360 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLType* pType = dynamic_cast<QMLType*>((yyvsp[(2) - (3)].Object));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (3)].Object));

        if (pType != NULL && pName != NULL)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName);
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 375 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLType* pType = dynamic_cast<QMLType*>((yyvsp[(2) - (5)].Object));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pType != NULL && pName != NULL)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName, pData);
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 391 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLType* pType = new QMLType(QVariant::Color);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pType != NULL && pName != NULL)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName, pData);
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 407 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pName != NULL)
        {
            (yyval.Object) = new QMLPropertyAlias(pName, pData);
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 424 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLType((QVariant::Type) 0);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 429 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLType(QVariant::Bool);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 434 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLType(QVariant::Int);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 439 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLType(QVariant::Double);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 444 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLType(QVariant::String);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 451 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 460 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_PROPERTY)), pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 468 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_COLOR)), pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 476 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (5)].Object);
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 487 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 492 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 497 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 502 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 507 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 514 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (4)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, pContent);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 524 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 528 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 535 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 540 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        SAFE_DELETE((yyvsp[(2) - (2)].Object));

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 549 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 555 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 562 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pStatement1 = (yyvsp[(1) - (1)].Object);
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pStatement1);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 572 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pStatement2 = (yyvsp[(2) - (2)].Object);

        if (pComplex != NULL)
        {
            pComplex->contents().append(pStatement2);
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 587 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 592 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 599 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 604 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 609 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 614 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 619 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 624 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 629 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 634 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 639 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 646 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pThen = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, NULL);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 654 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (7)].Object);
        QMLItem* pThen = (yyvsp[(5) - (7)].Object);
        QMLItem* pElse = (yyvsp[(7) - (7)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, pElse);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 665 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pInitialization = (yyvsp[(3) - (9)].Object);
        QMLItem* pCondition = (yyvsp[(5) - (9)].Object);
        QMLItem* pIncrementation = (yyvsp[(7) - (9)].Object);
        QMLItem* pContent = (yyvsp[(9) - (9)].Object);

        (yyval.Object) = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 677 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pInitialization = NULL;
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pIncrementation = NULL;
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 689 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 696 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 703 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 710 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 717 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 722 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 729 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 734 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 741 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 746 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 751 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 758 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 763 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 772 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 777 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 786 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pExpression1);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 796 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression2 = (yyvsp[(2) - (3)].Object);

        if (pComplex != NULL)
        {
            pComplex->contents().append(pExpression2);
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 811 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 816 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 826 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 831 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(1) - (5)].Object);
        QMLItem* pThen = (yyvsp[(3) - (5)].Object);
        QMLItem* pElse = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLConditional(pCondition, pThen, pElse);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 842 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 847 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicOr);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 857 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 862 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicAnd);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 872 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 877 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAnd);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 887 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 892 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEquals);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 900 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 908 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEquals);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 916 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 926 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 931 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLower);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 939 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 947 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreater);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 955 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 965 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 970 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAdd);
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 978 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boSub);
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 988 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 993 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMul);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1001 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boDiv);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1009 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftLeft);
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1017 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftRight);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1027 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1032 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1037 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1042 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1049 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1054 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLIdentifier* pIdentifier1 = dynamic_cast<QMLIdentifier*>((yyvsp[(1) - (3)].Object));
        QMLIdentifier* pIdentifier2 = dynamic_cast<QMLIdentifier*>((yyvsp[(3) - (3)].Object));

        if (pIdentifier1 != NULL && pIdentifier2 != NULL)
        {
            QString sFullString = pIdentifier1->value().value<QString>() + "." + pIdentifier2->value().value<QString>();
            pIdentifier1->setValue(sFullString);

            SAFE_DELETE(pIdentifier2);

            (yyval.Object) = pIdentifier1;
        }
        else
        {
            QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
            QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

            QMLQualifiedExpression* pExpression = dynamic_cast<QMLQualifiedExpression*>((yyvsp[(1) - (3)].Object));

            if (pExpression == NULL)
            {
                pExpression = new QMLQualifiedExpression();
                pExpression->contents().append(pExpression1);
            }

            pExpression->contents().append(pExpression2);

            (yyval.Object) = pExpression;
        }
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1087 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (4)].Object);
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1094 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1099 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        (yyval.Object) = new QMLFunctionCall(pName, pArguments);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1109 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1114 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1119 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1126 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1131 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1138 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (1)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);

        if (pList == NULL)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        (yyval.Object) = pList;
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1152 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1157 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == NULL)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        pList->contents().append(pExpression2);

        (yyval.Object) = pList;
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1174 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1181 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1188 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1193 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1200 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1206 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1213 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1218 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1225 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1231 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1236 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1243 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1248 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1255 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1260 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1267 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1272 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pAttribute1 = (yyvsp[(1) - (2)].Object);
        QMLItem* pAttribute2 = (yyvsp[(2) - (2)].Object);

        if (pComplex == NULL)
        {
            pComplex = new QMLComplexItem();
            pComplex->contents().append(pAttribute1);
        }

        pComplex->contents().append(pAttribute2);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1291 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1296 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1303 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != NULL && pValue != NULL)
        {
            (yyval.Object) = new QMLNameValue(pName->value().value<QString>(), pValue->value());
        }
        else
        {
            (yyval.Object) = NULL;
        }

        SAFE_DELETE((yyvsp[(1) - (3)].Object));
        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1321 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != NULL && pValue != NULL)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName);

            pComplex->contents().append(pValue);

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1342 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1347 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1359 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + QString(TOKEN_COLOR));

        (yyval.Object) = pLeft;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1371 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != NULL)
        {
            (yyval.Object) = new QMLIdentifier(*pString);
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1387 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->tokenValue());
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1394 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1399 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1404 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1409 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1416 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1423 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1430 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1437 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != NULL)
        {
            (yyval.Object) = new QMLItem(QVariant(*pString));
        }
        else
        {
            (yyval.Object) = NULL;
        }
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1452 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"
    {
        (yyval.Object) = NULL;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3605 "C:/User/E487027/Work/Projects/qt-plus/src/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 1456 "C:/User/E487027/Work/Projects/qt-plus/src/bison/QML.y"


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

