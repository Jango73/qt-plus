
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
#line 9 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"

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



/* Line 189 of yacc.c  */
#line 105 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"

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
     TOKEN_VARIANT = 508,
     TOKEN_COLOR = 509,
     TOKEN_FUNCTION = 510,
     TOKEN_IF = 511,
     TOKEN_ELSE = 512,
     TOKEN_FOR = 513,
     TOKEN_WHILE = 514,
     TOKEN_BREAK = 515,
     TOKEN_CONTINUE = 516,
     TOKEN_WITH = 517,
     TOKEN_RETURN = 518,
     TOKEN_TYPEOF = 519,
     TOKEN_PRAGMA = 520,
     TOKEN_ON = 521,
     TOKEN_AS = 522,
     TOKEN_SIGNAL = 523
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 40 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;



/* Line 214 of yacc.c  */
#line 218 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 230 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
/* YYNRULES -- Number of states.  */
#define YYNSTATES  282

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   524

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,    74,     2,     2,    70,     2,    76,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    71,
       2,     2,     2,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    69,     2,     2,     2,     2,
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
      64,    65,    66,    67,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    20,
      26,    29,    34,    37,    42,    46,    53,    55,    58,    62,
      64,    66,    68,    70,    72,    74,    77,    81,    87,    93,
      97,   101,   103,   105,   107,   109,   112,   116,   121,   125,
     129,   132,   134,   138,   140,   143,   147,   149,   152,   154,
     157,   159,   161,   163,   165,   167,   169,   171,   173,   175,
     181,   189,   199,   205,   207,   209,   215,   218,   220,   222,
     225,   227,   229,   232,   234,   236,   240,   242,   246,   248,
     252,   254,   256,   260,   264,   268,   272,   276,   280,   282,
     288,   290,   292,   296,   298,   302,   304,   308,   310,   314,
     316,   320,   324,   328,   332,   334,   338,   342,   346,   350,
     352,   356,   360,   362,   366,   370,   374,   378,   382,   384,
     387,   390,   393,   395,   399,   401,   406,   408,   413,   415,
     417,   421,   423,   425,   427,   431,   433,   435,   437,   439,
     441,   443,   445,   449,   452,   454,   458,   460,   464,   466,
     468,   472,   474,   477,   479,   482,   486,   490,   492,   494,
     496,   500,   502,   504,   506,   508,   510,   512,   514,   516,
     518,   520
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      80,     0,    -1,    81,    -1,    82,    -1,    81,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    44,   142,   144,    -1,
      44,   142,   144,    66,   143,    -1,    44,   149,    -1,    44,
     149,    66,   143,    -1,    64,   142,    -1,   143,    68,    86,
      69,    -1,   143,    68,    69,    -1,   143,    65,   143,    68,
      86,    69,    -1,    87,    -1,    86,    87,    -1,    86,    70,
      87,    -1,    90,    -1,    88,    -1,    85,    -1,    94,    -1,
      92,    -1,    89,    -1,    89,    71,    -1,    45,   143,   143,
      -1,    45,   143,   143,    72,    91,    -1,    45,    46,   143,
      72,    91,    -1,   142,    72,    91,    -1,    45,    72,    91,
      -1,    85,    -1,   100,    -1,   136,    -1,    93,    -1,    93,
      71,    -1,    67,   143,    95,    -1,    54,   143,    95,   100,
      -1,    54,    95,   100,    -1,    73,    96,    74,    -1,    73,
      74,    -1,    97,    -1,    96,    70,    97,    -1,   143,    -1,
     143,   143,    -1,    68,    99,    69,    -1,   100,    -1,    99,
     100,    -1,   101,    -1,   101,    71,    -1,    98,    -1,   110,
      -1,   102,    -1,   103,    -1,   104,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,    55,    73,   114,    74,   100,
      -1,    55,    73,   114,    74,   100,    56,   100,    -1,    57,
      73,   111,    71,   109,    71,   109,    74,   100,    -1,    58,
      73,   114,    74,   100,    -1,    59,    -1,    60,    -1,    61,
      73,   114,    74,   100,    -1,    62,   109,    -1,   150,    -1,
     114,    -1,    47,   112,    -1,   114,    -1,   150,    -1,   143,
     112,    -1,   114,    -1,   113,    -1,   112,    70,   113,    -1,
     143,    -1,   143,     8,   116,    -1,   115,    -1,   115,    70,
     114,    -1,   116,    -1,   117,    -1,   117,     8,   116,    -1,
     117,    19,   116,    -1,   117,    20,   116,    -1,   117,    21,
     116,    -1,   117,    22,   116,    -1,   117,     8,   136,    -1,
     118,    -1,   118,    75,   116,    72,   116,    -1,    94,    -1,
     119,    -1,   119,    38,   118,    -1,   120,    -1,   120,    16,
     119,    -1,   121,    -1,   121,    37,   120,    -1,   122,    -1,
     122,    14,   121,    -1,   123,    -1,   123,    33,   122,    -1,
     123,    34,   122,    -1,   123,    35,   122,    -1,   123,    36,
     122,    -1,   124,    -1,   123,    29,   124,    -1,   123,    31,
     124,    -1,   123,    30,   124,    -1,   123,    32,   124,    -1,
     125,    -1,   125,     9,   124,    -1,   125,    10,   124,    -1,
     126,    -1,   126,    11,   125,    -1,   126,    12,   125,    -1,
     126,    13,   125,    -1,   126,    17,   125,    -1,   126,    18,
     125,    -1,   127,    -1,   127,   134,    -1,   135,   127,    -1,
      10,   127,    -1,   128,    -1,   128,    76,   127,    -1,   129,
      -1,   129,    77,   114,    78,    -1,   130,    -1,   130,    73,
     131,    74,    -1,   143,    -1,   145,    -1,    73,   114,    74,
      -1,   150,    -1,   132,    -1,   133,    -1,   132,    70,   133,
      -1,    45,    -1,   136,    -1,   116,    -1,    40,    -1,    41,
      -1,    39,    -1,    63,    -1,    68,   138,    69,    -1,    68,
      69,    -1,    43,    -1,    77,   137,    78,    -1,   136,    -1,
     137,    70,   136,    -1,    86,    -1,   145,    -1,   137,    70,
     145,    -1,   139,    -1,   138,   139,    -1,   140,    -1,   140,
      70,    -1,   141,    72,   136,    -1,   141,    72,   115,    -1,
     149,    -1,   143,    -1,   143,    -1,   142,    76,   143,    -1,
       3,    -1,     7,    -1,   146,    -1,   147,    -1,   148,    -1,
     149,    -1,     5,    -1,     6,    -1,     7,    -1,     4,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   136,   148,   162,   169,   176,   185,   203,
     221,   237,   255,   263,   278,   288,   305,   324,   339,   356,
     363,   370,   377,   384,   393,   400,   409,   426,   444,   463,
     474,   486,   493,   500,   509,   516,   525,   537,   548,   561,
     568,   577,   584,   595,   612,   631,   640,   658,   675,   682,
     691,   698,   705,   712,   719,   726,   733,   740,   747,   756,
     769,   785,   802,   819,   826,   833,   840,   847,   852,   859,
     864,   871,   876,   881,   888,   895,   906,   913,   924,   931,
     948,   955,   962,   979,   996,  1013,  1030,  1047,  1066,  1073,
    1089,  1098,  1105,  1124,  1131,  1150,  1155,  1172,  1177,  1194,
    1199,  1214,  1229,  1244,  1261,  1266,  1281,  1296,  1311,  1328,
    1333,  1348,  1365,  1370,  1385,  1400,  1415,  1430,  1447,  1452,
    1457,  1462,  1469,  1476,  1498,  1505,  1514,  1521,  1533,  1540,
    1547,  1556,  1563,  1572,  1588,  1609,  1614,  1619,  1626,  1631,
    1638,  1643,  1650,  1655,  1660,  1665,  1672,  1677,  1684,  1689,
    1694,  1703,  1708,  1727,  1732,  1739,  1758,  1779,  1784,  1791,
    1796,  1810,  1826,  1833,  1838,  1843,  1848,  1855,  1862,  1869,
    1876,  1892
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
  "TOKEN_STRING", "TOKEN_VARIANT", "TOKEN_COLOR", "TOKEN_FUNCTION",
  "TOKEN_IF", "TOKEN_ELSE", "TOKEN_FOR", "TOKEN_WHILE", "TOKEN_BREAK",
  "TOKEN_CONTINUE", "TOKEN_WITH", "TOKEN_RETURN", "TOKEN_TYPEOF",
  "TOKEN_PRAGMA", "TOKEN_ON", "TOKEN_AS", "TOKEN_SIGNAL", "'{'", "'}'",
  "','", "';'", "':'", "'('", "')'", "'?'", "'.'", "'['", "']'", "$accept",
  "File", "Declarations", "Declaration", "ImportStatement",
  "PragmaStatement", "Item", "ItemContents", "ItemContent",
  "PropertyDeclaration", "PropertyDeclarationNoColon",
  "PropertyAssignment", "PropertyContent", "SignalDeclaration",
  "SignalDeclarationNoColon", "JSFunction", "JSFunctionParameterList",
  "JSFunctionParameters", "JSFunctionParameter", "JSStatementBlock",
  "JSStatements", "JSStatement", "JSStatementNoColon", "JSStatement_If",
  "JSStatement_For", "JSStatement_While", "JSStatement_Break",
  "JSStatement_Continue", "JSStatement_With", "JSStatement_Return",
  "JSExpressionOpt", "JSVariablesOrExpression",
  "JSVariablesOrExpressionOpt", "JSVariables", "JSVariable",
  "JSExpression", "JSExpressionSingle", "JSAssignmentExpression",
  "JSConditionalExpression", "JSOrExpression", "JSXorExpression",
  "JSAndExpression", "JSBitwiseAndExpression", "JSEqualityExpression",
  "JSRelationalExpression", "JSAdditiveExpression",
  "JSMultiplicativeExpression", "JSUnaryExpression", "JSMemberExpression",
  "JSArrayAccessExpression", "JSFunctionCall", "JSPrimaryExpression",
  "JSArgumentListOpt", "JSArgumentList", "JSArgument",
  "JSIncrementOperator", "JSUnaryOperator", "JSObject", "JSArrayContents",
  "JSAttributes", "JSAttribute", "JSAttributeNoComma", "JSAttributeName",
  "QualifiedIdentifier", "Identifier", "Version", "Value", "Boolean",
  "Integer", "Double", "Literal", "Empty", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   524,   300,   301,   302,   303,   304,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   123,   125,
      44,    59,    58,    40,    41,    63,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    81,    82,    82,    82,    83,    83,
      83,    83,    84,    85,    85,    85,    86,    86,    86,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    90,
      90,    91,    91,    91,    92,    92,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   104,   105,   106,   107,   108,   109,   109,   110,
     110,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   136,   136,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     142,   143,   144,   145,   145,   145,   145,   146,   147,   148,
     149,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     5,
       2,     4,     2,     4,     3,     6,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     5,     3,
       3,     1,     1,     1,     1,     2,     3,     4,     3,     3,
       2,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     9,     5,     1,     1,     5,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     5,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     2,
       2,     2,     1,     3,     1,     4,     1,     4,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     1,     3,     1,     1,
       3,     1,     2,     1,     2,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   161,     0,     0,     0,     2,     3,     5,     6,     7,
       0,   170,     0,   159,    10,    12,     1,     4,     0,     0,
     162,     0,     8,     0,     0,     0,     0,     0,    14,    21,
       0,    16,    20,    24,    19,    23,    34,    22,     0,   159,
     160,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,    17,    25,    35,     0,     9,     0,     0,
     167,   168,   169,     0,   140,   144,     0,     0,     0,     0,
      63,    64,     0,   171,   141,     0,     0,     0,    31,    30,
      90,    50,    32,    48,    52,    53,    54,    55,    56,    57,
      58,    51,    70,    78,    80,    81,    88,    91,    93,    95,
      97,    99,   104,   109,   112,   118,   122,   124,   126,     0,
      33,   128,   129,   163,   164,   165,   166,    26,    40,     0,
      41,    43,     0,    38,   128,     0,    36,    18,    29,    15,
       0,   121,    69,    74,    76,     0,   171,     0,     0,    66,
      68,    67,   143,     0,    46,     0,   151,   153,     0,   128,
     166,     0,     0,   148,   146,     0,   149,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   119,     0,     0,   171,
     120,     0,     0,    39,    44,    37,    28,     0,     0,     0,
       0,    73,   128,    71,     0,     0,    45,    47,   142,   152,
     158,   157,   154,     0,   130,     0,   145,    79,    82,    87,
      83,    84,    85,    86,     0,    92,    94,    96,    98,   105,
     107,   106,   108,   100,   101,   102,   103,   110,   111,   113,
     114,   115,   116,   117,   123,     0,   135,   137,     0,   132,
     133,   136,   131,    27,    42,    75,    77,     0,   171,    72,
       0,     0,   156,   155,   147,   150,     0,   125,   127,     0,
      59,     0,    62,    65,    89,   134,     0,   171,    60,     0,
       0,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    29,    30,    31,    32,
      33,    34,    79,    35,    36,    80,    48,   119,   120,    81,
     143,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     139,    91,   200,   132,   133,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   248,   249,   250,   186,   109,   110,   155,   145,
     146,   147,   148,    38,   124,    22,   112,   113,   114,   115,
     116,   141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -246
static const yytype_int16 yypact[] =
{
      88,  -246,    37,    18,     8,    88,  -246,  -246,  -246,  -246,
      -6,  -246,    11,  -246,   -38,   -46,  -246,  -246,    18,   126,
    -246,    18,    10,    18,   -16,    48,    16,    18,  -246,  -246,
     103,  -246,  -246,   -11,  -246,  -246,    44,  -246,   -29,    -6,
    -246,    18,  -246,   162,    18,   234,    18,    14,   426,    17,
      17,  -246,   162,  -246,  -246,  -246,   234,  -246,   114,    54,
    -246,  -246,  -246,   106,  -246,  -246,    18,    60,    64,    69,
    -246,  -246,    72,   437,  -246,   338,   437,   157,  -246,  -246,
    -246,  -246,  -246,    83,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,    77,  -246,   168,    94,   120,   158,   140,
     183,   226,  -246,   141,   314,   -26,   122,   105,   128,   106,
    -246,    -6,  -246,  -246,  -246,  -246,  -246,   131,  -246,   -25,
    -246,    18,   426,  -246,  -246,   426,  -246,  -246,  -246,  -246,
     234,  -246,   134,  -246,   198,   437,   437,   437,   437,  -246,
    -246,  -246,  -246,   355,  -246,    31,  -246,   145,   138,   150,
     154,   159,    33,   182,  -246,   -39,  -246,  -246,   437,   313,
     437,   437,   437,   437,   437,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,  -246,  -246,  -246,   106,   437,   261,
    -246,   234,    18,  -246,  -246,  -246,  -246,    18,   437,   161,
     171,  -246,    18,  -246,   169,   176,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,   313,  -246,    50,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,   179,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,   185,  -246,  -246,   200,   202,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,   426,   437,   134,
     426,   426,  -246,  -246,  -246,  -246,   437,  -246,  -246,   261,
     220,   207,  -246,  -246,  -246,  -246,   426,   437,  -246,   205,
     426,  -246
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,  -246,   281,  -246,  -246,     5,   -31,   -14,  -246,
    -246,  -246,   -45,  -246,  -246,   -10,   117,  -246,    95,  -246,
    -246,   -48,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -245,  -246,  -246,    96,    93,   -72,    86,   -91,  -246,   136,
     137,   142,   144,   109,  -246,    76,    38,  -246,   -56,  -246,
    -246,  -246,  -246,  -246,    36,  -246,  -246,   -75,  -246,  -246,
     163,  -246,  -246,   189,    78,  -246,   -74,  -246,  -246,  -246,
       4,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -159
static const yytype_int16 yytable[] =
{
     123,   140,   154,   156,   151,     9,    14,   131,    16,    37,
       9,   128,    58,   271,   184,   185,    53,     1,    20,     1,
      37,     1,     1,    11,    60,    61,    62,   144,    23,    63,
      21,   215,   279,    37,     1,    11,     1,    11,   127,   216,
       1,    11,    37,    56,    53,   192,   153,    21,    37,   193,
      78,     1,    43,   190,    11,    60,    61,    62,    64,    18,
      54,    78,    19,   199,   201,   204,   205,    37,   218,   220,
     221,   222,   223,   224,   144,   203,    41,   195,    10,   150,
      13,    13,    74,    10,   219,   196,   217,    21,   118,    47,
      47,     1,    76,    65,    44,   207,    24,    39,   247,    40,
     208,    42,   142,    46,    49,    50,     1,   256,    39,     1,
      11,    60,    61,    62,   251,    55,   245,     1,   152,    57,
      45,    39,    59,   111,   117,   121,   130,    77,   252,     1,
      39,   244,     2,   135,   111,    78,    39,   136,   263,    53,
     264,   265,   137,    37,   134,   138,   253,   158,    25,   211,
     177,   178,     3,   149,   157,    39,   211,    26,   165,    25,
       1,    11,    60,    61,    62,     1,   125,   126,    26,   164,
      27,    25,    51,    52,   166,   274,   159,   167,   247,    76,
      26,    27,   188,   129,    52,     1,   140,   160,   161,   162,
     163,    12,    15,    27,   251,    28,    78,   168,   187,   194,
      65,   189,    25,   191,   197,   140,   198,    25,   111,   270,
     213,    26,   272,   273,   202,   212,    26,   239,   240,   241,
     242,   243,  -158,   210,    27,   152,  -157,    25,   278,    27,
     210,    39,   281,   214,    77,   257,    26,     1,    11,    60,
      61,    62,   258,   260,    63,   229,   230,   231,   232,    27,
     261,   266,    52,   237,   238,   169,   170,   171,   172,   173,
     174,   175,   176,   267,     1,    11,    60,    61,    62,   111,
     121,    63,   269,    64,   268,   134,   276,    65,   277,   280,
     134,    66,   233,   234,   235,   236,    17,   254,    26,    67,
     255,    68,    69,    70,    71,    72,    73,    74,   259,   262,
      64,   225,    75,   226,    65,   275,   246,    76,   209,   227,
       0,    77,   228,     0,     0,    26,     1,    11,    60,    61,
      62,     0,     0,    63,    74,   179,   180,   181,     0,   152,
       0,   182,   183,     0,    76,     0,     0,     0,    77,     0,
       0,     1,    11,    60,    61,    62,     0,     0,    63,     0,
       0,     0,    64,     0,     0,     0,    65,     0,     1,    11,
      60,    61,    62,     0,     0,    63,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    64,     0,     0,
       0,   152,     0,     0,     0,    66,    76,     0,     0,     0,
      77,     0,    26,    67,    64,    68,    69,    70,    71,    72,
      73,    74,    66,     0,     0,     0,   122,   142,     0,    26,
      67,    76,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,     0,   122,   206,     0,     0,     0,    76,     1,
      11,    60,    61,    62,     0,     0,    63,     0,     0,     0,
       1,    11,    60,    61,    62,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,    64,     0,     0,     0,
      26,    67,     0,    68,    69,    70,    71,    72,    73,    74,
       0,    26,     0,     0,   122,     0,     0,     0,     0,    76,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76
};

static const yytype_int16 yycheck[] =
{
      48,    73,    77,    77,    76,     0,     2,    63,     0,    19,
       5,    56,    43,   258,    40,    41,    30,     3,     7,     3,
      30,     3,     3,     4,     5,     6,     7,    75,    66,    10,
      76,    70,   277,    43,     3,     4,     3,     4,    52,    78,
       3,     4,    52,    72,    58,    70,    77,    76,    58,    74,
      45,     3,    68,   109,     4,     5,     6,     7,    39,    65,
      71,    56,    68,   135,   136,   137,   138,    77,   159,   160,
     161,   162,   163,   164,   122,   136,    66,   125,     0,    75,
       2,     3,    63,     5,   159,   130,   158,    76,    74,    73,
      73,     3,    73,    43,    46,   143,    18,    19,   189,    21,
      69,    23,    69,    25,    26,    27,     3,   198,    30,     3,
       4,     5,     6,     7,   189,    71,   188,     3,    68,    41,
      72,    43,    44,    45,    46,    47,    72,    77,   189,     3,
      52,   187,    44,    73,    56,   130,    58,    73,   213,   153,
     215,   215,    73,   153,    66,    73,   191,    70,    45,   145,
       9,    10,    64,    75,    71,    77,   152,    54,    38,    45,
       3,     4,     5,     6,     7,     3,    49,    50,    54,    75,
      67,    45,    69,    70,    16,   266,     8,    37,   269,    73,
      54,    67,    77,    69,    70,     3,   258,    19,    20,    21,
      22,     2,     3,    67,   269,    69,   191,    14,    76,   121,
      43,    73,    45,    72,    70,   277,     8,    45,   130,   257,
      72,    54,   260,   261,   136,    70,    54,   179,   180,   181,
     182,   183,    72,   145,    67,    68,    72,    45,   276,    67,
     152,   153,   280,    74,    77,    74,    54,     3,     4,     5,
       6,     7,    71,    74,    10,   169,   170,   171,   172,    67,
      74,    72,    70,   177,   178,    29,    30,    31,    32,    33,
      34,    35,    36,    78,     3,     4,     5,     6,     7,   191,
     192,    10,    70,    39,    74,   197,    56,    43,    71,    74,
     202,    47,   173,   174,   175,   176,     5,   192,    54,    55,
     197,    57,    58,    59,    60,    61,    62,    63,   202,   213,
      39,   165,    68,   166,    43,   269,    45,    73,   145,   167,
      -1,    77,   168,    -1,    -1,    54,     3,     4,     5,     6,
       7,    -1,    -1,    10,    63,    11,    12,    13,    -1,    68,
      -1,    17,    18,    -1,    73,    -1,    -1,    -1,    77,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    43,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    10,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    39,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    47,    73,    -1,    -1,    -1,
      77,    -1,    54,    55,    39,    57,    58,    59,    60,    61,
      62,    63,    47,    -1,    -1,    -1,    68,    69,    -1,    54,
      55,    73,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    73,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    39,    -1,    -1,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    54,    -1,    -1,    68,    -1,    -1,    -1,    -1,    73,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    64,    80,    81,    82,    83,    84,    85,
     143,     4,   142,   143,   149,   142,     0,    82,    65,    68,
       7,    76,   144,    66,   143,    45,    54,    67,    69,    85,
      86,    87,    88,    89,    90,    92,    93,    94,   142,   143,
     143,    66,   143,    68,    46,    72,   143,    73,    95,   143,
     143,    69,    70,    87,    71,    71,    72,   143,    86,   143,
       5,     6,     7,    10,    39,    43,    47,    55,    57,    58,
      59,    60,    61,    62,    63,    68,    73,    77,    85,    91,
      94,    98,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   110,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   135,
     136,   143,   145,   146,   147,   148,   149,   143,    74,    96,
      97,   143,    68,   100,   143,    95,    95,    87,    91,    69,
      72,   127,   112,   113,   143,    73,    73,    73,    73,   109,
     114,   150,    69,    99,   100,   138,   139,   140,   141,   143,
     149,   114,    68,    86,   136,   137,   145,    71,    70,     8,
      19,    20,    21,    22,    75,    38,    16,    37,    14,    29,
      30,    31,    32,    33,    34,    35,    36,     9,    10,    11,
      12,    13,    17,    18,    40,    41,   134,    76,    77,    73,
     127,    72,    70,    74,   143,   100,    91,    70,     8,   114,
     111,   114,   143,   150,   114,   114,    69,   100,    69,   139,
     143,   149,    70,    72,    74,    70,    78,   114,   116,   136,
     116,   116,   116,   116,   116,   118,   119,   120,   121,   124,
     124,   124,   124,   122,   122,   122,   122,   124,   124,   125,
     125,   125,   125,   125,   127,   114,    45,   116,   131,   132,
     133,   136,   150,    91,    97,   113,   116,    74,    71,   112,
      74,    74,   115,   136,   136,   145,    72,    78,    74,    70,
     100,   109,   100,   100,   116,   133,    56,    71,   100,   109,
      74,   100
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
#line 131 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 137 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declaration");

        QMLItem* pItem = (yyvsp[(1) - (1)].Object);

        if (pItem != nullptr)
        {
            pContext->item().contents().append(pItem);
        }
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 149 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        if (pItem != nullptr)
        {
            pContext->item().contents().append(pItem);
        }
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 163 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 170 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 177 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 186 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (3)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (3)].Object);

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

  case 9:

/* Line 1455 of yacc.c  */
#line 204 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (5)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (5)].Object);

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

  case 10:

/* Line 1455 of yacc.c  */
#line 222 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (2)].Object);

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

  case 11:

/* Line 1455 of yacc.c  */
#line 238 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (4)].Object);

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

  case 12:

/* Line 1455 of yacc.c  */
#line 256 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 264 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' ItemContents '}'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        if (pComplexItem != nullptr)
        {
            pComplexItem->setName(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 279 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position(), pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 289 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON Identifier '{' ItemContents '}'");

        QMLItem* pName = (yyvsp[(1) - (6)].Object);
        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(5) - (6)].Object));

        if (pComplexItem != nullptr)
        {
            pComplexItem->setName(pName);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 306 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLItem* pOldItem = (yyvsp[(1) - (1)].Object);

        if (pOldItem != nullptr)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position());
            pComplexItem->contents() << pOldItem;

            (yyval.Object) = pComplexItem;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 325 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pNewItem = (yyvsp[(2) - (2)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 340 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ',' ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pNewItem = (yyvsp[(3) - (3)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents() << pNewItem;
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 357 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 364 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 371 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 378 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 385 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 394 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 401 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 410 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (3)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pContext->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 427 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(2) - (5)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pContext->position(), pType, pName, pData);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 445 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyAlias(pContext->position(), pName, pData);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 464 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 475 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "TOKEN_PROPERTY ':' PropertyContent");

        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), new QMLItem(pContext->position(), QString(TOKEN_PROPERTY)), pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 487 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 494 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 501 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 510 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 517 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 526 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, nullptr);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 538 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatement");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (4)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 549 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatement");

        QMLItem* pName = new QMLIdentifier(pContext->position(), "");
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 562 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 569 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 578 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 585 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 596 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier");

        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(1) - (1)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pName->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 613 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(1) - (2)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (2)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pName->position(), pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 632 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 641 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLItem* pStatement1 = (yyvsp[(1) - (1)].Object);

        if (pStatement1 == nullptr)
        {
            pStatement1 = new QMLItem(pContext->position());
        }

        QMLComplexItem* pComplex = new QMLComplexItem(pStatement1->position());

        pComplex->contents() << pStatement1;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 659 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatements JSStatement");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pStatement2 = (yyvsp[(2) - (2)].Object);

        if (pComplex != nullptr)
        {
            pComplex->contents() << pStatement2;
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 676 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 683 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 692 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 699 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 706 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 713 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 720 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 727 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 734 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 741 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 748 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 757 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pThen = (yyvsp[(5) - (5)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, nullptr);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 770 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (7)].Object);
        QMLItem* pThen = (yyvsp[(5) - (7)].Object);
        QMLItem* pElse = (yyvsp[(7) - (7)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, pElse);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 786 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pInitialization = (yyvsp[(3) - (9)].Object);
        QMLItem* pCondition = (yyvsp[(5) - (9)].Object);
        QMLItem* pIncrementation = (yyvsp[(7) - (9)].Object);
        QMLItem* pContent = (yyvsp[(9) - (9)].Object);

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 803 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pInitialization = nullptr;
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pIncrementation = nullptr;
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 820 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 827 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 834 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 841 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 848 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 853 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 860 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 865 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 872 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 877 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 882 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 889 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 896 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 907 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 914 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 925 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 932 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle ',' JSExpression");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression2 = (yyvsp[(2) - (3)].Object);

        if (pComplex != nullptr)
        {
            pComplex->contents() << pExpression2;
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 949 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 956 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 963 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 980 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 997 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1014 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1031 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1048 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAssign);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1067 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1074 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLItem* pCondition = (yyvsp[(1) - (5)].Object);
        QMLItem* pThen = (yyvsp[(3) - (5)].Object);
        QMLItem* pElse = (yyvsp[(5) - (5)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLConditional(pCondition->position(), pCondition, pThen, pElse);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1090 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1099 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1106 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1125 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1132 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression TOKEN_XOR JSOrExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicOr);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1151 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1156 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLogicAnd);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1173 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1178 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAnd);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1195 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1200 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEquals);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1215 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1230 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEquals);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1245 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1262 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1267 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLower);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1282 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1297 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreater);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1312 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1329 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1334 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boAdd);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1349 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boSub);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1366 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1371 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMul);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1386 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boDiv);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1401 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boMod);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1416 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftLeft);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1431 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        if (pLeft != nullptr && pRight != nullptr)
        {
            (yyval.Object) = new QMLBinaryOperation(pLeft->position(), pLeft, pRight, QMLBinaryOperation::boShiftRight);
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1448 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1453 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1458 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1463 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1470 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1477 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression '.' JSMemberExpression");

        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

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

  case 124:

/* Line 1455 of yacc.c  */
#line 1499 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1506 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall '[' JSExpression ']'");

        (yyval.Object) = (yyvsp[(1) - (4)].Object);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1515 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1522 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        (yyval.Object) = new QMLFunctionCall(pName->position(), pName, pArguments);
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1534 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1541 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1548 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1557 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1564 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1573 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (1)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents().append(pExpression1);
        }

        (yyval.Object) = pList;
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1589 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents().append(pExpression1);
        }

        pList->contents().append(pExpression2);

        (yyval.Object) = pList;
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1610 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1615 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1620 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1627 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1632 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1639 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1644 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1651 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1656 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1661 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1666 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1673 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1678 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);

        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1685 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1690 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1695 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);

        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1704 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1709 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pAttribute1 = (yyvsp[(1) - (2)].Object);
        QMLItem* pAttribute2 = (yyvsp[(2) - (2)].Object);

        if (pComplex == nullptr)
        {
            pComplex = new QMLComplexItem(pAttribute1->position());
            pComplex->contents() << pAttribute1;
        }

        pComplex->contents() << pAttribute2;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1728 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1733 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1740 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName->position(), pName);

            pComplex->contents() << pValue;

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1759 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName->position(), pName);

            pComplex->contents() << pValue;

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1780 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1785 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1792 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1797 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1811 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
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

  case 162:

/* Line 1455 of yacc.c  */
#line 1827 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), pContext->tokenValue());
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1834 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1839 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1844 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1849 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1856 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1863 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1870 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1877 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != nullptr)
        {
            (yyval.Object) = new QMLItem(pContext->position(), QVariant(*pString));
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1892 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 4112 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 1896 "C:/User/E487027/Work/Projects/qmlprototyper/unis-lib/src/bison/QML.y"


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

