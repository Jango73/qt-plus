
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
#line 105 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
#line 40 "D:/Work/Projects/qt-plus/source/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;



/* Line 214 of yacc.c  */
#line 218 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 230 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYLAST   524

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
      -1,   129,    73,   131,    74,    -1,   130,    -1,   130,    77,
     114,    78,    -1,   143,    -1,   145,    -1,    73,   114,    74,
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
     568,   577,   584,   595,   612,   631,   640,   652,   669,   676,
     685,   692,   699,   706,   713,   720,   727,   734,   741,   750,
     758,   769,   781,   793,   800,   807,   814,   821,   826,   833,
     838,   845,   850,   855,   862,   869,   880,   887,   898,   905,
     922,   936,   943,   953,   963,   973,   983,   993,  1005,  1012,
    1023,  1032,  1039,  1051,  1058,  1070,  1075,  1085,  1090,  1100,
    1105,  1113,  1121,  1129,  1139,  1144,  1152,  1160,  1168,  1178,
    1183,  1191,  1201,  1206,  1214,  1222,  1230,  1238,  1248,  1253,
    1258,  1263,  1270,  1277,  1314,  1321,  1333,  1340,  1349,  1356,
    1363,  1372,  1379,  1388,  1404,  1425,  1430,  1435,  1442,  1447,
    1454,  1459,  1466,  1471,  1476,  1481,  1488,  1493,  1500,  1505,
    1510,  1517,  1522,  1541,  1546,  1553,  1572,  1593,  1598,  1605,
    1610,  1624,  1640,  1647,  1652,  1657,  1662,  1669,  1676,  1683,
    1690,  1706
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
  "JSFunctionCall", "JSArrayAccessExpression", "JSPrimaryExpression",
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
       0,     0,     0,     0,   138,   139,   119,     0,   171,     0,
     120,     0,     0,    39,    44,    37,    28,     0,     0,     0,
       0,    73,   128,    71,     0,     0,    45,    47,   142,   152,
     158,   157,   154,     0,   130,     0,   145,    79,    82,    87,
      83,    84,    85,    86,     0,    92,    94,    96,    98,   105,
     107,   106,   108,   100,   101,   102,   103,   110,   111,   113,
     114,   115,   116,   117,   123,   135,   137,     0,   132,   133,
     136,   131,     0,    27,    42,    75,    77,     0,   171,    72,
       0,     0,   156,   155,   147,   150,     0,   125,     0,   127,
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
     107,   108,   247,   248,   249,   186,   109,   110,   155,   145,
     146,   147,   148,    38,   124,    22,   112,   113,   114,   115,
     116,   141
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -235
static const yytype_int16 yypact[] =
{
      12,  -235,    57,    11,    23,    12,  -235,  -235,  -235,  -235,
      82,  -235,    34,  -235,   -41,   -32,  -235,  -235,    11,   123,
    -235,    11,   -31,    11,     1,    16,    14,    11,  -235,  -235,
     103,  -235,  -235,    31,  -235,  -235,    36,  -235,   -50,    82,
    -235,    11,  -235,   124,    11,   234,    11,     8,   426,    47,
      47,  -235,   124,  -235,  -235,  -235,   234,  -235,   113,    59,
    -235,  -235,  -235,    25,  -235,  -235,    11,    60,    65,    67,
    -235,  -235,    69,   437,  -235,   338,   437,   157,  -235,  -235,
    -235,  -235,  -235,    83,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,    89,  -235,    51,    96,   136,   159,   139,
     167,   216,  -235,    45,   242,    72,   108,   112,   110,    25,
    -235,    82,  -235,  -235,  -235,  -235,  -235,   117,  -235,   -17,
    -235,    11,   426,  -235,  -235,   426,  -235,  -235,  -235,  -235,
     234,  -235,   125,  -235,   189,   437,   437,   437,   437,  -235,
    -235,  -235,  -235,   355,  -235,    42,  -235,   133,   135,   138,
     143,   132,    46,   134,  -235,   -57,  -235,  -235,   437,   313,
     437,   437,   437,   437,   437,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,  -235,  -235,  -235,    25,   261,   437,
    -235,   234,    11,  -235,  -235,  -235,  -235,    11,   437,   142,
     146,  -235,    11,  -235,   148,   155,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,   313,  -235,    32,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,   161,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -235,  -235,  -235,  -235,  -235,  -235,  -235,   162,   165,  -235,
    -235,  -235,   164,  -235,  -235,  -235,  -235,   426,   437,   125,
     426,   426,  -235,  -235,  -235,  -235,   437,  -235,   261,  -235,
     187,   185,  -235,  -235,  -235,  -235,   426,   437,  -235,   183,
     426,  -235
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,   253,  -235,  -235,     2,   -25,   -18,  -235,
    -235,  -235,   -46,  -235,  -235,   -10,   102,  -235,    70,  -235,
    -235,   -48,  -235,  -235,  -235,  -235,  -235,  -235,  -235,  -235,
    -234,  -235,  -235,    61,    64,   -72,    63,   -70,  -235,   107,
     116,   111,   106,   152,  -235,    49,   104,  -235,   -58,  -235,
    -235,  -235,  -235,  -235,    22,  -235,  -235,   -74,  -235,  -235,
     153,  -235,  -235,   163,    78,  -235,   -69,  -235,  -235,  -235,
       4,  -120
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -159
static const yytype_int16 yytable[] =
{
     123,   140,     9,   154,   151,   131,    14,     9,   156,    37,
     128,     1,    53,   215,     1,     1,   203,     1,    58,     1,
      37,   216,    56,    16,   271,    23,    21,   144,     1,    11,
      60,    61,    62,    37,   127,    41,    11,    60,    61,    62,
      53,    20,    37,   279,    21,     1,    11,    78,    37,     1,
      11,   190,   153,   192,   177,   178,     2,   193,    78,   159,
       1,    11,    44,   199,   201,   204,   205,    37,   251,    43,
     160,   161,   162,   163,   144,    65,     3,   195,    10,   150,
      13,    13,   118,    10,   196,   219,   217,    47,    45,   218,
     220,   221,   222,   223,   224,   207,    24,    39,    76,    40,
     152,    42,    54,    46,    49,    50,     1,    55,    39,    77,
      21,   208,   184,   185,   250,   142,     1,   252,   246,    57,
      47,    39,    59,   111,   117,   121,     1,     1,   256,   244,
      39,   130,    78,   135,   111,    53,    39,     1,   136,   263,
     137,   264,   138,    37,   134,   253,   265,    18,    25,   211,
      19,   125,   126,   149,   157,    39,   211,    26,    25,   158,
       1,    11,    60,    61,    62,    12,    15,    26,    25,    25,
      27,   164,    51,    52,   165,   166,   167,    26,    26,    25,
      27,   168,   129,    52,   187,   188,   140,   189,    26,   191,
      27,    27,    28,    78,   250,   197,   274,   198,   246,   194,
      65,    27,    25,   212,    52,   140,   214,   213,   111,   270,
    -158,    26,   272,   273,   202,  -157,   257,   258,   229,   230,
     231,   232,   260,   210,    27,   152,   237,   238,   278,   261,
     210,    39,   281,   266,    77,   268,   267,     1,    11,    60,
      61,    62,   269,   276,    63,   169,   170,   171,   172,   173,
     174,   175,   176,   179,   180,   181,   277,   280,    17,   182,
     183,   255,   254,   259,     1,    11,    60,    61,    62,   111,
     121,    63,   225,    64,   228,   134,   262,    65,   227,     0,
     134,    66,   226,   239,   240,   241,   242,   243,    26,    67,
     275,    68,    69,    70,    71,    72,    73,    74,   209,     0,
      64,     0,    75,     0,    65,     0,   245,    76,     0,     0,
       0,    77,     0,     0,     0,    26,     1,    11,    60,    61,
      62,     0,     0,    63,    74,   233,   234,   235,   236,   152,
       0,     0,     0,     0,    76,     0,     0,     0,    77,     0,
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
       0,     0,     0,     0,     1,    11,    60,    61,    62,     0,
       0,    63,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,    64,     0,     0,     0,
      26,    67,     0,    68,    69,    70,    71,    72,    73,    74,
      64,    26,     0,     0,   122,     0,     0,     0,     0,    76,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76
};

static const yytype_int16 yycheck[] =
{
      48,    73,     0,    77,    76,    63,     2,     5,    77,    19,
      56,     3,    30,    70,     3,     3,   136,     3,    43,     3,
      30,    78,    72,     0,   258,    66,    76,    75,     3,     4,
       5,     6,     7,    43,    52,    66,     4,     5,     6,     7,
      58,     7,    52,   277,    76,     3,     4,    45,    58,     3,
       4,   109,    77,    70,     9,    10,    44,    74,    56,     8,
       3,     4,    46,   135,   136,   137,   138,    77,   188,    68,
      19,    20,    21,    22,   122,    43,    64,   125,     0,    75,
       2,     3,    74,     5,   130,   159,   158,    73,    72,   159,
     160,   161,   162,   163,   164,   143,    18,    19,    73,    21,
      68,    23,    71,    25,    26,    27,     3,    71,    30,    77,
      76,    69,    40,    41,   188,    69,     3,   189,   188,    41,
      73,    43,    44,    45,    46,    47,     3,     3,   198,   187,
      52,    72,   130,    73,    56,   153,    58,     3,    73,   213,
      73,   215,    73,   153,    66,   191,   215,    65,    45,   145,
      68,    49,    50,    75,    71,    77,   152,    54,    45,    70,
       3,     4,     5,     6,     7,     2,     3,    54,    45,    45,
      67,    75,    69,    70,    38,    16,    37,    54,    54,    45,
      67,    14,    69,    70,    76,    73,   258,    77,    54,    72,
      67,    67,    69,   191,   268,    70,   266,     8,   268,   121,
      43,    67,    45,    70,    70,   277,    74,    72,   130,   257,
      72,    54,   260,   261,   136,    72,    74,    71,   169,   170,
     171,   172,    74,   145,    67,    68,   177,   178,   276,    74,
     152,   153,   280,    72,    77,    70,    74,     3,     4,     5,
       6,     7,    78,    56,    10,    29,    30,    31,    32,    33,
      34,    35,    36,    11,    12,    13,    71,    74,     5,    17,
      18,   197,   192,   202,     3,     4,     5,     6,     7,   191,
     192,    10,   165,    39,   168,   197,   213,    43,   167,    -1,
     202,    47,   166,   179,   180,   181,   182,   183,    54,    55,
     268,    57,    58,    59,    60,    61,    62,    63,   145,    -1,
      39,    -1,    68,    -1,    43,    -1,    45,    73,    -1,    -1,
      -1,    77,    -1,    -1,    -1,    54,     3,     4,     5,     6,
       7,    -1,    -1,    10,    63,   173,   174,   175,   176,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
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
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    10,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    39,    -1,    -1,    -1,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      39,    54,    -1,    -1,    68,    -1,    -1,    -1,    -1,    73,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73
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
      12,    13,    17,    18,    40,    41,   134,    76,    73,    77,
     127,    72,    70,    74,   143,   100,    91,    70,     8,   114,
     111,   114,   143,   150,   114,   114,    69,   100,    69,   139,
     143,   149,    70,    72,    74,    70,    78,   114,   116,   136,
     116,   116,   116,   116,   116,   118,   119,   120,   121,   124,
     124,   124,   124,   122,   122,   122,   122,   124,   124,   125,
     125,   125,   125,   125,   127,    45,   116,   131,   132,   133,
     136,   150,   114,    91,    97,   113,   116,    74,    71,   112,
      74,    74,   115,   136,   136,   145,    72,    74,    70,    78,
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
#line 131 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 137 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 149 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 163 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 170 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 177 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 186 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (3)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
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
#line 204 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (5)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (5)].Object);

        if (pName != nullptr && pVersion != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), pVersion->value().toString());
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
#line 222 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (2)].Object);

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), "");
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
#line 238 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (4)].Object);

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext, pName->value().toString(), "");
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
#line 256 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 264 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 279 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 289 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 306 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLItem* pOldItem = (yyvsp[(1) - (1)].Object);

        if (pOldItem != nullptr)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem();
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
#line 325 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 340 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 357 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 364 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 371 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 378 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 385 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 394 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 401 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 410 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (3)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 427 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(2) - (5)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName, pData);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 445 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(3) - (5)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(5) - (5)].Object));

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyAlias(pName, pData);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 464 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 475 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "TOKEN_PROPERTY ':' PropertyContent");

        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_PROPERTY)), pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 487 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 494 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 501 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 510 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 517 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 526 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, nullptr);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 538 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatement");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (4)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, pContent);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 549 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatement");

        QMLItem* pName = new QMLIdentifier("");
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, pContent);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 562 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 569 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 578 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 585 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 596 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier");

        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(1) - (1)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 613 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(1) - (2)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (2)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            (yyval.Object) = new QMLPropertyDeclaration(pType, pName);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 632 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 641 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLItem* pStatement1 = (yyvsp[(1) - (1)].Object);
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents() << pStatement1;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 653 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 670 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 677 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 686 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 693 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 700 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 707 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 714 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 721 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 728 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 735 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 742 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 751 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pThen = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, nullptr);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 759 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (7)].Object);
        QMLItem* pThen = (yyvsp[(5) - (7)].Object);
        QMLItem* pElse = (yyvsp[(7) - (7)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, pElse);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 770 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pInitialization = (yyvsp[(3) - (9)].Object);
        QMLItem* pCondition = (yyvsp[(5) - (9)].Object);
        QMLItem* pIncrementation = (yyvsp[(7) - (9)].Object);
        QMLItem* pContent = (yyvsp[(9) - (9)].Object);

        (yyval.Object) = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 782 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pInitialization = nullptr;
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pIncrementation = nullptr;
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLFor(pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 794 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 801 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 808 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 815 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 822 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 827 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 834 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 839 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 846 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 851 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 856 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 863 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 870 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 881 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 888 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 899 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 906 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 923 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpressionSingle", "JSAssignmentExpression");

        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pExpression1);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 937 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 944 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 954 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 964 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 974 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_MUL_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 984 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_DIV_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 994 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1006 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1013 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLItem* pCondition = (yyvsp[(1) - (5)].Object);
        QMLItem* pThen = (yyvsp[(3) - (5)].Object);
        QMLItem* pElse = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLConditional(pCondition, pThen, pElse);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1024 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1033 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1040 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicOr);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1052 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1059 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression TOKEN_XOR JSOrExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicOr);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1071 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1076 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicAnd);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1086 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1091 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAnd);
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1101 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1106 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEquals);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1114 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1122 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEquals);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1130 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1140 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1145 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLower);
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1153 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1161 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreater);
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1169 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1179 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1184 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAdd);
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1192 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boSub);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1202 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1207 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMul);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1215 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boDiv);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1223 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMod);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1231 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftLeft);
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1239 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftRight);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1249 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1254 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1259 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1264 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1271 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1278 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSFunctionCall '.' JSMemberExpression");

        QMLIdentifier* pIdentifier1 = dynamic_cast<QMLIdentifier*>((yyvsp[(1) - (3)].Object));
        QMLIdentifier* pIdentifier2 = dynamic_cast<QMLIdentifier*>((yyvsp[(3) - (3)].Object));

        if (pIdentifier1 != nullptr && pIdentifier2 != nullptr)
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

            if (pExpression == nullptr)
            {
                pExpression = new QMLQualifiedExpression();
                pExpression->contents().append(pExpression1);
            }

            pExpression->contents().append(pExpression2);

            (yyval.Object) = pExpression;
        }
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1315 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1322 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSArrayAccessExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        (yyval.Object) = new QMLFunctionCall(pName, pArguments);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1334 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1341 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSPrimaryExpression '[' JSExpression ']'");

        (yyval.Object) = (yyvsp[(1) - (4)].Object);
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1350 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1357 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1364 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1373 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1380 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1389 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (1)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        (yyval.Object) = pList;
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1405 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem();
            pList->contents().append(pExpression1);
        }

        pList->contents().append(pExpression2);

        (yyval.Object) = pList;
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1426 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1431 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1436 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1443 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1448 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1455 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1460 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1467 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1472 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1477 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLComplexItem();
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1482 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1489 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1494 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);

        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1501 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1506 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1511 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1518 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1523 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pAttribute1 = (yyvsp[(1) - (2)].Object);
        QMLItem* pAttribute2 = (yyvsp[(2) - (2)].Object);

        if (pComplex == nullptr)
        {
            pComplex = new QMLComplexItem();
            pComplex->contents() << pAttribute1;
        }

        pComplex->contents() << pAttribute2;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1542 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1547 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1554 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName);

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
#line 1573 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

        if (pName != nullptr && pValue != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pName);

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
#line 1594 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1599 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1606 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1611 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 1625 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != nullptr)
        {
            (yyval.Object) = new QMLIdentifier(*pString);
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1641 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->tokenValue());
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1648 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1653 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1658 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1663 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1670 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1677 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1684 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1691 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QString* pString = (yyvsp[(1) - (1)].String);

        if (pString != nullptr)
        {
            (yyval.Object) = new QMLItem(QVariant(*pString));
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1706 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3928 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 1710 "D:/Work/Projects/qt-plus/source/bison/QML.y"


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

