
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



/* Line 189 of yacc.c  */
#line 113 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
     TOKEN_INC = 342,
     TOKEN_DEC = 343,
     TOKEN_COMPLEMENT = 344,
     TOKEN_DIMENSION = 345,
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
#line 48 "D:/Work/Projects/qt-plus/source/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;



/* Line 214 of yacc.c  */
#line 232 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 244 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  193
/* YYNRULES -- Number of states.  */
#define YYNSTATES  325

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
      81,    82,     2,     2,    76,     2,    84,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    78,    77,
       2,     2,     2,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,    75,     2,     2,     2,     2,
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
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      22,    28,    31,    36,    39,    44,    48,    55,    57,    60,
      64,    66,    68,    70,    72,    74,    76,    79,    84,    89,
      96,   103,   110,   112,   114,   116,   118,   122,   124,   126,
     128,   130,   134,   136,   140,   142,   145,   149,   154,   158,
     162,   165,   167,   171,   173,   176,   179,   183,   187,   189,
     192,   194,   197,   199,   201,   203,   205,   207,   209,   211,
     213,   215,   217,   219,   225,   233,   243,   251,   257,   263,
     267,   270,   272,   274,   280,   283,   286,   288,   290,   293,
     295,   297,   300,   302,   304,   308,   310,   314,   318,   320,
     324,   326,   328,   332,   336,   340,   344,   348,   352,   354,
     356,   358,   364,   366,   368,   372,   374,   378,   380,   384,
     386,   390,   392,   396,   400,   404,   408,   410,   414,   418,
     422,   426,   428,   432,   436,   438,   442,   446,   450,   454,
     458,   460,   463,   466,   469,   472,   475,   478,   481,   484,
     486,   490,   492,   497,   499,   504,   506,   508,   512,   514,
     516,   518,   522,   524,   526,   528,   532,   535,   537,   541,
     545,   549,   551,   553,   555,   558,   560,   563,   567,   571,
     573,   575,   577,   581,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      86,     0,    -1,    87,    -1,    88,    -1,    87,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,   104,    -1,    44,   153,
     155,    -1,    44,   153,   155,    71,   154,    -1,    44,   160,
      -1,    44,   160,    71,   154,    -1,    69,   153,    -1,   154,
      74,    92,    75,    -1,   154,    74,    75,    -1,   154,    70,
     154,    74,    92,    75,    -1,    93,    -1,    92,    93,    -1,
      92,    76,    93,    -1,    94,    -1,    98,    -1,    91,    -1,
     104,    -1,   102,    -1,    95,    -1,    95,    77,    -1,    96,
      45,   154,   154,    -1,    96,    45,    49,   154,    -1,    96,
      45,   154,   154,    78,    99,    -1,    96,    45,    49,   154,
      78,    99,    -1,    96,    45,    48,   154,    78,    99,    -1,
     161,    -1,    97,    -1,    46,    -1,    47,    -1,   153,    78,
      99,    -1,    91,    -1,   100,    -1,   110,    -1,   147,    -1,
      79,   101,    80,    -1,    91,    -1,   101,    76,    91,    -1,
     103,    -1,   103,    77,    -1,    72,   154,   105,    -1,    56,
     154,   105,   108,    -1,    56,   105,   108,    -1,    81,   106,
      82,    -1,    81,    82,    -1,   107,    -1,   106,    76,   107,
      -1,   154,    -1,    49,   154,    -1,   154,   154,    -1,    74,
     161,    75,    -1,    74,   109,    75,    -1,   110,    -1,   109,
     110,    -1,   111,    -1,   111,    77,    -1,   108,    -1,   122,
      -1,   112,    -1,   113,    -1,   114,    -1,   115,    -1,   116,
      -1,   117,    -1,   118,    -1,   119,    -1,   120,    -1,    57,
      81,   126,    82,   110,    -1,    57,    81,   126,    82,   110,
      58,   110,    -1,    59,    81,   123,    77,   121,    77,   121,
      82,   110,    -1,    59,    81,   123,    60,   126,    82,   110,
      -1,    61,    81,   126,    82,   110,    -1,    62,    81,   126,
      82,   108,    -1,    63,   126,    78,    -1,    46,    78,    -1,
      64,    -1,    65,    -1,    66,    81,   126,    82,   110,    -1,
      67,   147,    -1,    67,   121,    -1,   161,    -1,   126,    -1,
      49,   124,    -1,   126,    -1,   161,    -1,    49,   124,    -1,
     126,    -1,   125,    -1,   124,    76,   125,    -1,   154,    -1,
     154,     8,   128,    -1,   154,     8,   147,    -1,   127,    -1,
     127,    76,   126,    -1,   128,    -1,   130,    -1,   130,     8,
     128,    -1,   130,    19,   128,    -1,   130,    20,   128,    -1,
     130,    21,   128,    -1,   130,    22,   128,    -1,   130,     8,
     147,    -1,   128,    -1,   147,    -1,   131,    -1,   131,    83,
     129,    78,   129,    -1,   104,    -1,   132,    -1,   132,    38,
     131,    -1,   133,    -1,   133,    16,   132,    -1,   134,    -1,
     134,    37,   133,    -1,   135,    -1,   135,    14,   134,    -1,
     136,    -1,   136,    33,   135,    -1,   136,    34,   135,    -1,
     136,    35,   135,    -1,   136,    36,   135,    -1,   137,    -1,
     136,    29,   137,    -1,   136,    31,   137,    -1,   136,    30,
     137,    -1,   136,    32,   137,    -1,   138,    -1,   138,     9,
     137,    -1,   138,    10,   137,    -1,   139,    -1,   139,    11,
     138,    -1,   139,    12,   138,    -1,   139,    13,   138,    -1,
     139,    17,   138,    -1,   139,    18,   138,    -1,   140,    -1,
     140,    40,    -1,    40,   140,    -1,   140,    41,    -1,    41,
     140,    -1,    39,   140,    -1,    68,   140,    -1,    10,   140,
      -1,    73,   140,    -1,   141,    -1,   141,    84,   140,    -1,
     142,    -1,   141,    79,   126,    80,    -1,   143,    -1,   143,
      81,   144,    82,    -1,   154,    -1,   156,    -1,    81,   126,
      82,    -1,   161,    -1,   145,    -1,   146,    -1,   145,    76,
     146,    -1,    45,    -1,   147,    -1,   128,    -1,    74,   149,
      75,    -1,    74,    75,    -1,    43,    -1,    79,   148,    80,
      -1,   148,    76,   147,    -1,   148,    76,   127,    -1,   147,
      -1,   127,    -1,   150,    -1,   149,   150,    -1,   151,    -1,
     151,    76,    -1,   152,    78,   147,    -1,   152,    78,   127,
      -1,   160,    -1,   154,    -1,   154,    -1,   153,    84,   154,
      -1,     3,    -1,     7,    -1,   157,    -1,   158,    -1,   159,
      -1,   160,    -1,     5,    -1,     6,    -1,     7,    -1,     4,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   150,   162,   176,   183,   190,   197,   206,
     224,   243,   259,   278,   289,   304,   314,   344,   363,   378,
     395,   402,   409,   416,   423,   432,   439,   448,   468,   488,
     509,   530,   552,   557,   564,   569,   576,   589,   596,   603,
     610,   619,   628,   648,   673,   680,   689,   704,   721,   746,
     753,   762,   769,   792,   812,   832,   854,   861,   874,   892,
     909,   916,   925,   932,   939,   946,   953,   960,   967,   974,
     981,   988,   995,  1004,  1024,  1053,  1070,  1098,  1112,  1131,
    1138,  1147,  1154,  1161,  1168,  1175,  1184,  1189,  1196,  1224,
    1233,  1240,  1268,  1277,  1289,  1310,  1317,  1334,  1353,  1360,
    1377,  1384,  1391,  1408,  1425,  1442,  1459,  1476,  1495,  1500,
    1507,  1514,  1530,  1539,  1546,  1565,  1572,  1591,  1596,  1613,
    1618,  1635,  1640,  1655,  1670,  1685,  1702,  1707,  1722,  1737,
    1752,  1769,  1774,  1789,  1806,  1811,  1826,  1841,  1856,  1871,
    1888,  1893,  1902,  1909,  1918,  1925,  1932,  1939,  1946,  1955,
    1962,  1984,  1991,  2011,  2018,  2037,  2044,  2051,  2064,  2071,
    2080,  2093,  2107,  2112,  2117,  2124,  2131,  2141,  2151,  2160,
    2172,  2184,  2200,  2218,  2232,  2246,  2253,  2262,  2285,  2310,
    2315,  2322,  2331,  2347,  2363,  2370,  2375,  2380,  2385,  2392,
    2399,  2406,  2413,  2429
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
  "TOKEN_DEFAULT", "TOKEN_READ_ONLY", "TOKEN_ALIAS", "TOKEN_VAR",
  "TOKEN_BOOL", "TOKEN_INT", "TOKEN_REAL", "TOKEN_STRING", "TOKEN_VARIANT",
  "TOKEN_COLOR", "TOKEN_FUNCTION", "TOKEN_IF", "TOKEN_ELSE", "TOKEN_FOR",
  "TOKEN_IN", "TOKEN_WHILE", "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_BREAK",
  "TOKEN_CONTINUE", "TOKEN_WITH", "TOKEN_RETURN", "TOKEN_TYPEOF",
  "TOKEN_PRAGMA", "TOKEN_ON", "TOKEN_AS", "TOKEN_SIGNAL", "TOKEN_NEW",
  "'{'", "'}'", "','", "';'", "':'", "'['", "']'", "'('", "')'", "'?'",
  "'.'", "$accept", "File", "Declarations", "Declaration",
  "ImportStatement", "PragmaStatement", "Item", "ItemContents",
  "ItemContent", "PropertyDeclaration", "PropertyDeclarationNoColon",
  "PropertyModifiersOpt", "PropertyModifiers", "PropertyAssignment",
  "PropertyContent", "ItemArray", "ItemArrayContents", "SignalDeclaration",
  "SignalDeclarationNoColon", "JSFunction", "JSFunctionParameterList",
  "JSFunctionParameters", "JSFunctionParameter", "JSStatementBlock",
  "JSStatements", "JSStatement", "JSStatementNoColon", "JSStatement_If",
  "JSStatement_For", "JSStatement_While", "JSStatement_Switch",
  "JSStatement_Case", "JSStatement_Break", "JSStatement_Continue",
  "JSStatement_With", "JSStatement_Return", "JSExpressionOpt",
  "JSVariablesOrExpression", "JSVariablesOrExpressionOpt", "JSVariables",
  "JSVariable", "JSExpression", "JSExpressionSingle",
  "JSAssignmentExpression", "JSAssignmentExpressionOrJSObject",
  "JSConditionalExpression", "JSOrExpression", "JSXorExpression",
  "JSAndExpression", "JSBitwiseAndExpression", "JSEqualityExpression",
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
     342,   343,   344,   345,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   123,   125,    44,    59,    58,    91,
      93,    40,    41,    63,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    87,    88,    88,    88,    88,    89,
      89,    89,    89,    90,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    98,    99,    99,    99,
      99,   100,   101,   101,   102,   102,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   114,   115,   116,
     116,   117,   118,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   135,   136,   136,   136,   136,
     136,   137,   137,   137,   138,   138,   138,   138,   138,   138,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   148,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   155,   156,   156,   156,   156,   157,
     158,   159,   160,   161
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       5,     2,     4,     2,     4,     3,     6,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     6,
       6,     6,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     2,     3,     4,     3,     3,
       2,     1,     3,     1,     2,     2,     3,     3,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     7,     9,     7,     5,     5,     3,
       2,     1,     1,     5,     2,     2,     1,     1,     2,     1,
       1,     2,     1,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     5,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       3,     1,     4,     1,     4,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     2,     1,     3,     3,
       3,     1,     1,     1,     2,     1,     2,     3,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   183,     0,     0,     0,     0,     2,     3,     5,     6,
       7,     8,     0,   192,     0,   181,    11,     0,     0,     0,
      13,     1,     4,     0,   193,   184,     0,     9,     0,     0,
      50,     0,    51,    53,   193,    48,     0,     0,    34,    35,
       0,    15,    22,   193,    17,    20,    25,     0,    33,    21,
      24,    44,    23,     0,   181,    32,   182,     0,    12,    54,
       0,    49,    55,   189,   190,   191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
     193,     0,     0,     0,   112,    62,     0,    58,    60,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    63,    89,
      98,   100,   101,   110,   113,   115,   117,   119,   121,   126,
     131,   134,   140,   149,   151,   153,   155,   156,   185,   186,
     187,   188,     0,    47,   193,     0,    14,   193,    18,    26,
       0,    45,     0,    10,    52,   147,   145,   142,   144,    80,
      88,    93,    95,     0,   193,     0,     0,     0,     0,   167,
       0,     0,    85,    87,    84,    86,   146,   148,     0,    57,
      59,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   143,
       0,     0,   193,    56,   193,    46,    19,     0,     0,     0,
       0,     0,    37,    36,    38,    39,    40,   155,     0,     0,
       0,     0,     0,    92,    90,     0,     0,    79,     0,   166,
       0,   173,   175,     0,   180,   179,   172,   171,     0,   157,
      99,   102,   107,   103,   104,   105,   106,   108,     0,   109,
     114,   116,   118,   120,   127,   129,   128,   130,   122,   123,
     124,   125,   132,   133,   135,   136,   137,   138,   139,     0,
     150,   162,   164,     0,   159,   160,   163,   158,    16,     0,
      28,    27,   155,   188,    42,     0,    94,    96,    97,     0,
      91,     0,   193,     0,     0,     0,   165,   174,   176,     0,
       0,   168,     0,   152,   154,     0,     0,     0,     0,     0,
      41,    73,     0,     0,    77,    78,    83,   178,   177,   170,
     169,   111,   161,    31,    30,    29,    43,     0,     0,   193,
      74,    76,     0,     0,    75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    42,    43,    44,    45,
      46,    47,    48,    49,   203,   204,   275,    50,    51,    84,
      18,    31,    32,    85,    86,   205,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   152,    98,   212,   140,
     141,    99,   100,   101,   238,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   263,
     264,   265,   206,   228,   220,   221,   222,   223,    53,   116,
      27,   117,   118,   119,   120,   121,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -224
static const yytype_int16 yypact[] =
{
      67,  -224,    71,    27,    24,    34,    67,  -224,  -224,  -224,
    -224,  -224,    70,  -224,    11,  -224,    -6,    17,    -2,    10,
      20,  -224,  -224,    24,   167,  -224,    24,    43,    24,    24,
    -224,     1,  -224,    24,   415,  -224,    -2,    51,  -224,  -224,
      24,  -224,  -224,    73,  -224,  -224,    40,    93,  -224,  -224,
    -224,    58,  -224,    31,    70,  -224,  -224,    24,  -224,  -224,
      53,  -224,  -224,  -224,  -224,  -224,    82,    82,    82,    82,
      63,    24,    65,    88,    94,    96,   517,  -224,  -224,   101,
     463,    82,    82,   517,  -224,  -224,   319,  -224,   106,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
      83,  -224,   241,   103,   133,   171,   156,   182,   573,  -224,
      97,    50,   121,    49,  -224,   129,  -224,  -224,  -224,  -224,
    -224,  -224,   137,  -224,    75,    10,  -224,    75,  -224,  -224,
      52,  -224,   271,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     139,  -224,   208,   517,   506,   517,   517,   141,   517,  -224,
      28,   463,  -224,  -224,  -224,  -224,  -224,  -224,   140,  -224,
    -224,  -224,   517,   463,   517,   517,   517,   517,   463,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,  -224,  -224,
     517,    82,   185,  -224,   109,  -224,  -224,    24,    24,    24,
     367,   463,  -224,  -224,  -224,  -224,  -224,    70,    24,   463,
     147,    24,    -8,  -224,  -224,   151,   153,  -224,   154,  -224,
      38,  -224,   145,   160,  -224,  -224,  -224,  -224,    78,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   162,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   163,
    -224,  -224,  -224,   165,   168,  -224,  -224,  -224,  -224,   170,
     173,   176,   179,   187,  -224,    92,  -224,  -224,  -224,   415,
     139,   517,   517,   415,    -2,   415,  -224,  -224,  -224,   463,
     463,  -224,   463,  -224,  -224,   185,   271,   271,   271,    24,
    -224,   214,   197,   203,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   415,   415,   517,
    -224,  -224,   200,   415,  -224
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,   239,  -224,  -224,     5,   159,   -30,  -224,
    -224,  -224,  -224,  -224,  -118,  -224,  -224,  -224,  -224,    15,
      -9,  -224,   231,   -11,  -224,   -33,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -223,  -224,  -224,    81,
      98,   -64,  -137,  -119,     8,  -224,   136,   138,   142,   135,
      25,  -224,   113,    84,  -224,   -31,  -224,  -224,  -224,  -224,
    -224,    14,   -58,  -224,  -224,    95,  -224,  -224,    90,     0,
    -224,  -224,  -224,  -224,  -224,     7,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
      12,    87,    15,    19,    15,    10,    12,    35,   122,    16,
      36,    10,   147,   128,   226,    11,   153,    33,    25,   158,
       1,    11,   154,    37,    54,   123,    56,     1,    58,    59,
       1,     1,    13,    62,    21,   135,   136,   137,   138,    52,
     125,     1,    13,    54,   231,   233,   234,   235,   236,   237,
     156,   157,   281,   160,   155,     1,     1,   133,    52,   303,
      33,   183,   184,   185,   226,    28,    29,   186,   187,   282,
       1,   142,    34,   262,     1,    13,     1,    60,     1,   210,
     213,   215,   216,    61,   218,     1,    13,    63,    64,    65,
     277,    17,    14,   227,    20,    26,   322,   196,   230,    30,
     197,   198,    29,   219,    26,   232,   181,   182,    17,   132,
     239,     2,     1,   286,    57,    26,   195,   129,   214,    38,
      39,    38,    39,     3,    54,   124,   259,    54,   190,     3,
     199,     3,   207,   191,   266,   131,     4,   202,   130,    52,
      23,   139,    52,   227,    24,    40,   143,    40,   126,   127,
     224,   278,   307,   309,   290,    38,    39,   225,   291,   162,
     260,   188,   189,    83,   128,     3,   267,    87,   299,   144,
       1,   169,   300,   237,   122,   145,   262,   146,   313,   314,
     315,    40,   148,   161,   268,   127,   168,   170,     1,    13,
      63,    64,    65,   171,    54,    66,   172,   269,   270,   271,
     272,   207,   248,   249,   250,   251,   274,   273,   142,    52,
     192,   142,   193,    38,    39,   208,   209,   302,   153,   217,
     224,   288,   229,     3,    67,    68,    69,   225,   149,   279,
     261,   308,   310,   283,   239,   284,   285,   266,   289,    40,
     292,     3,    41,   293,   295,    22,   301,   294,   296,   163,
     304,   297,   306,    81,   298,   153,   155,  -180,    82,   150,
     164,   165,   166,   167,   151,  -179,    83,   254,   255,   256,
     257,   258,   317,   305,     1,    13,    63,    64,    65,   318,
     319,    66,   323,   194,   320,   321,   244,   245,   246,   247,
     324,   134,   280,   155,   252,   253,   207,   207,   207,    12,
     311,   202,   202,   202,   316,   240,   276,   243,   241,   312,
      67,    68,    69,   242,   149,   287,     0,    70,     0,     0,
      71,     0,     1,    13,    63,    64,    65,     3,    72,    66,
      73,     0,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,    82,   200,     0,     0,     0,     0,
     201,     0,    83,     0,     0,     0,     0,     0,    67,    68,
      69,     0,     0,     0,     0,    70,     0,     0,    71,     0,
       1,    13,    63,    64,    65,     3,    72,    66,    73,     0,
      74,    75,    76,    77,    78,    79,    80,    81,     0,     0,
       0,     0,    82,    34,   159,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    67,    68,    69,     0,
       0,     0,     0,    70,     0,     0,    71,     0,     1,    13,
      63,    64,    65,     3,    72,    66,    73,     0,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,     0,
      82,    34,   219,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,    67,    68,    69,     0,     0,     0,
       0,    70,     0,     0,    71,     0,     1,    13,    63,    64,
      65,     3,    72,    66,    73,     0,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,    82,    34,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,    67,    68,    69,     0,   149,     0,     0,     1,
      13,    63,    64,    65,     0,     0,    66,     0,     0,     3,
       1,    13,    63,    64,    65,     0,     0,    66,     0,     0,
       0,    81,     0,     0,     0,     0,    82,   150,     0,     0,
       0,     0,   151,     0,    83,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,   211,    67,    68,    69,     0,
       0,     0,     3,     1,    13,    63,    64,    65,     0,     0,
      66,     0,     0,     3,    81,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,    81,     0,    83,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,    83,    67,
      68,    69,   173,   174,   175,   176,   177,   178,   179,   180,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,    83
};

static const yytype_int16 yycheck[] =
{
       0,    34,     2,     3,     4,     0,     6,    18,    34,     2,
      19,     6,    76,    43,   151,     0,    80,    17,     7,    83,
       3,     6,    80,    23,    24,    36,    26,     3,    28,    29,
       3,     3,     4,    33,     0,    66,    67,    68,    69,    24,
      40,     3,     4,    43,   163,   164,   165,   166,   167,   168,
      81,    82,    60,    86,    80,     3,     3,    57,    43,   282,
      60,    11,    12,    13,   201,    71,    49,    17,    18,    77,
       3,    71,    74,   192,     3,     4,     3,    76,     3,   143,
     144,   145,   146,    82,   148,     3,     4,     5,     6,     7,
     209,    81,     2,   151,     4,    84,   319,   127,   162,    82,
      48,    49,    49,    75,    84,   163,     9,    10,    81,    78,
     168,    44,     3,    75,    71,    84,   125,    77,   144,    46,
      47,    46,    47,    56,   124,    74,   190,   127,    79,    56,
     130,    56,   132,    84,   192,    77,    69,   132,    45,   124,
      70,    78,   127,   201,    74,    72,    81,    72,    75,    76,
     150,   209,   289,   290,    76,    46,    47,   150,    80,    76,
     191,    40,    41,    81,   194,    56,   192,   200,    76,    81,
       3,    38,    80,   292,   200,    81,   295,    81,   296,   297,
     298,    72,    81,    77,    75,    76,    83,    16,     3,     4,
       5,     6,     7,    37,   194,    10,    14,   197,   198,   199,
     200,   201,   177,   178,   179,   180,   201,   200,   208,   194,
      81,   211,    75,    46,    47,    76,     8,   281,   282,    78,
     220,    76,    82,    56,    39,    40,    41,   220,    43,    82,
      45,   289,   290,    82,   292,    82,    82,   295,    78,    72,
      78,    56,    75,    80,    76,     6,   279,    82,    78,     8,
     283,    78,   285,    68,    78,   319,   282,    78,    73,    74,
      19,    20,    21,    22,    79,    78,    81,   183,   184,   185,
     186,   187,    58,   284,     3,     4,     5,     6,     7,    82,
      77,    10,    82,   124,   317,   318,   173,   174,   175,   176,
     323,    60,   211,   319,   181,   182,   296,   297,   298,   299,
     292,   296,   297,   298,   299,   169,   208,   172,   170,   295,
      39,    40,    41,   171,    43,   220,    -1,    46,    -1,    -1,
      49,    -1,     3,     4,     5,     6,     7,    56,    57,    10,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,    -1,
      79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,
       3,     4,     5,     6,     7,    56,    57,    10,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    -1,     3,     4,
       5,     6,     7,    56,    57,    10,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      73,    74,    75,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    -1,     3,     4,     5,     6,
       7,    56,    57,    10,    59,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    -1,    43,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    56,
       3,     4,     5,     6,     7,    -1,    -1,    10,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    79,    -1,    81,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    39,    40,    41,    -1,
      -1,    -1,    56,     3,     4,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    56,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    81,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    39,
      40,    41,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    56,    69,    86,    87,    88,    89,    90,
      91,   104,   154,     4,   153,   154,   160,    81,   105,   154,
     153,     0,    88,    70,    74,     7,    84,   155,    71,    49,
      82,   106,   107,   154,    74,   108,   105,   154,    46,    47,
      72,    75,    91,    92,    93,    94,    95,    96,    97,    98,
     102,   103,   104,   153,   154,   161,   154,    71,   154,   154,
      76,    82,   154,     5,     6,     7,    10,    39,    40,    41,
      46,    49,    57,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    73,    81,   104,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   122,   126,
     127,   128,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   154,   156,   157,   158,
     159,   160,   161,   108,    74,   154,    75,    76,    93,    77,
      45,    77,    78,   154,   107,   140,   140,   140,   140,    78,
     124,   125,   154,    81,    81,    81,    81,   126,    81,    43,
      74,    79,   121,   126,   147,   161,   140,   140,   126,    75,
     110,    77,    76,     8,    19,    20,    21,    22,    83,    38,
      16,    37,    14,    29,    30,    31,    32,    33,    34,    35,
      36,     9,    10,    11,    12,    13,    17,    18,    40,    41,
      79,    84,    81,    75,    92,   105,    93,    48,    49,   154,
      74,    79,    91,    99,   100,   110,   147,   154,    76,     8,
     126,    49,   123,   126,   161,   126,   126,    78,   126,    75,
     149,   150,   151,   152,   154,   160,   127,   147,   148,    82,
     126,   128,   147,   128,   128,   128,   128,   128,   129,   147,
     131,   132,   133,   134,   137,   137,   137,   137,   135,   135,
     135,   135,   137,   137,   138,   138,   138,   138,   138,   126,
     140,    45,   128,   144,   145,   146,   147,   161,    75,   154,
     154,   154,   154,   160,    91,   101,   125,   128,   147,    82,
     124,    60,    77,    82,    82,    82,    75,   150,    76,    78,
      76,    80,    78,    80,    82,    76,    78,    78,    78,    76,
      80,   110,   126,   121,   110,   108,   110,   127,   147,   127,
     147,   129,   146,    99,    99,    99,    91,    58,    82,    77,
     110,   110,   121,    82,   110
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
#line 145 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 151 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declaration");

        QMLItem* pItem = (yyvsp[(1) - (1)].Object);

        if (pItem != nullptr)
        {
            pContext->item().contents() << pItem;
        }
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 163 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declarations", "Declarations Declaration");

        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        if (pItem != nullptr)
        {
            pContext->item().contents() << pItem;
        }
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 177 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 184 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 191 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 198 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Function");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 207 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 10:

/* Line 1455 of yacc.c  */
#line 225 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (5)].Object);
        QMLItem* pVersion = (yyvsp[(3) - (5)].Object);
        QMLItem* pAs = (yyvsp[(5) - (5)].Object);

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

  case 11:

/* Line 1455 of yacc.c  */
#line 244 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 12:

/* Line 1455 of yacc.c  */
#line 260 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pName = (yyvsp[(2) - (4)].Object);
        QMLItem* pAs = (yyvsp[(4) - (4)].Object);

        if (pName != nullptr)
        {
            (yyval.Object) = new QMLImport(pContext->position(), pContext, pName->value().toString(), "", pAs->value().toString());
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
#line 279 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        QMLItem* pStatement = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLPragma(pStatement->position(), pStatement);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 290 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 15:

/* Line 1455 of yacc.c  */
#line 305 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position(), pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 315 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier TOKEN_ON Identifier '{' ItemContents '}'");

        QMLItem* pName = (yyvsp[(1) - (6)].Object);
        QMLItem* pTarget = (yyvsp[(3) - (6)].Object);
        QMLComplexItem* pContents = dynamic_cast<QMLComplexItem*>((yyvsp[(5) - (6)].Object));

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

        (yyval.Object) = pExpression;
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 345 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 18:

/* Line 1455 of yacc.c  */
#line 364 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 19:

/* Line 1455 of yacc.c  */
#line 379 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 20:

/* Line 1455 of yacc.c  */
#line 396 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 403 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 410 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 417 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 424 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 433 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 440 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 449 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier");

        int iModifiers = (yyvsp[(1) - (4)].Integer);
        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(3) - (4)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (4)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pContext->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 469 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier");

        int iModifiers = (yyvsp[(1) - (4)].Integer);
        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (4)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pContext->position(), pType, pName);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 489 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(3) - (6)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (6)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(6) - (6)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pContext->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 510 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_VAR Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (6)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(6) - (6)].Object));

        if (pType != nullptr && pName != nullptr)
        {
            QMLPropertyDeclaration* pDeclaration = new QMLPropertyDeclaration(pContext->position(), pType, pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 531 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        int iModifiers = (yyvsp[(1) - (6)].Integer);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (6)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(6) - (6)].Object));

        if (pName != nullptr)
        {
            QMLPropertyAlias* pDeclaration = new QMLPropertyAlias(pContext->position(), pName, pData);
            pDeclaration->setModifiers((QMLPropertyDeclaration::EModifier) iModifiers);
            (yyval.Object) = pDeclaration;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 553 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mNone;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 558 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (yyvsp[(1) - (1)].Integer);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 565 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mDefault;
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 570 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Integer) = (int) QMLPropertyDeclaration::mReadonly;
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 577 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 590 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 597 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "ItemArray");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 604 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 611 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 620 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArray", "'[' ItemArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 629 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArrayContents", "Item");

        QMLItem* pItem1 = (yyvsp[(1) - (1)].Object);

        if (pItem1 != nullptr)
        {
            QMLComplexItem* pComplex = new QMLComplexItem(pItem1->position());
            pComplex->setIsArray(true);
            pComplex->contents() << pItem1;

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 649 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemArrayContents", "ItemArrayContents ',' Item");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));

        if (pComplex != nullptr)
        {
            QMLItem* pItem2 = (yyvsp[(3) - (3)].Object);

            if (pItem2 != nullptr)
            {
                pComplex->contents() << pItem2;
            }

            (yyval.Object) = pComplex;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 674 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 681 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 690 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = (yyvsp[(2) - (3)].Object);
        QMLItem* pParameters = (yyvsp[(3) - (3)].Object);

        QMLFunction* pFunction = new QMLFunction(pContext->position(), pName, pParameters, nullptr);
        pFunction->setIsSignal(true);

        (yyval.Object) = pFunction;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 705 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock");

        QMLItem* pName = (yyvsp[(2) - (4)].Object);
        QMLItem* pParameters = (yyvsp[(3) - (4)].Object);
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        if (pContent == nullptr)
        {
            pContent = new QMLComplexItem(pName->position());
            pContent->setIsBlock(true);
        }

        (yyval.Object) = new QMLFunction(pName->position(), pName, pParameters, pContent);
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 722 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatementBlock");

        QMLItem* pParameters = (yyvsp[(2) - (3)].Object);
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        if (pContent == nullptr)
        {
            pContent = new QMLComplexItem(pContext->position());
            pContent->setIsBlock(true);
        }

        QPoint pPosition;

        if (pParameters != nullptr) pPosition = pParameters->position();
        else pPosition = pContent->position();

        QMLItem* pName = new QMLIdentifier(pPosition, "");

        (yyval.Object) = new QMLFunction(pPosition, pName, pParameters, pContent);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 747 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 754 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 763 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 770 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents() << pExpression1;
        }

        pList->setIsArgumentList(true);

        pList->contents() << pExpression2;

        (yyval.Object) = pList;
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 793 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier");

        QMLType* pType = QMLType::fromQMLItem(nullptr);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(1) - (1)].Object));

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

  case 54:

/* Line 1455 of yacc.c  */
#line 813 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "TOKEN_VAR Identifier");

        QMLType* pType = new QMLType(pContext->position(), QVARIANT_VARIANT);
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (2)].Object));

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

  case 55:

/* Line 1455 of yacc.c  */
#line 833 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameter", "Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(1) - (2)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (2)].Object));

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

  case 56:

/* Line 1455 of yacc.c  */
#line 855 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' Empty '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 862 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        QMLItem* pItem = (yyvsp[(2) - (3)].Object);

        pItem = QMLComplexItem::makeBlock(pItem);

        (yyval.Object) = pItem;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 875 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 59:

/* Line 1455 of yacc.c  */
#line 893 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 60:

/* Line 1455 of yacc.c  */
#line 910 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 917 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 926 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 933 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 940 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 947 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 954 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 961 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Switch");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 968 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Case");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 975 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 982 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 989 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 996 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 1005 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pThen = (yyvsp[(5) - (5)].Object);

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        if (pThen == nullptr)
        {
            pThen = new QMLItem(pContext->position());
        }

        pThen = QMLComplexItem::makeBlock(pThen);

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, nullptr);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 1025 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (7)].Object);
        QMLItem* pThen = (yyvsp[(5) - (7)].Object);
        QMLItem* pElse = (yyvsp[(7) - (7)].Object);

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

        (yyval.Object) = new QMLIf(pCondition->position(), pCondition, pThen, pElse);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 1054 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pInitialization = (yyvsp[(3) - (9)].Object);
        QMLItem* pCondition = (yyvsp[(5) - (9)].Object);
        QMLItem* pIncrementation = (yyvsp[(7) - (9)].Object);
        QMLItem* pContent = (yyvsp[(9) - (9)].Object);

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLItem(pContext->position());
        }

        pContent = QMLComplexItem::makeBlock(pContent);

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1071 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pVariable = (yyvsp[(3) - (7)].Object);
        QMLItem* pExpression = (yyvsp[(5) - (7)].Object);
        QMLItem* pContent = (yyvsp[(7) - (7)].Object);

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

        (yyval.Object) = new QMLForIn(pVariable->position(), pVariable, pExpression, pContent);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1099 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pInitialization = new QMLItem(pContext->position());
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pIncrementation = new QMLItem(pContext->position());
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);

        pContent = QMLComplexItem::makeBlock(pContent);

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 1113 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(3) - (5)].Object);
        QMLComplexItem* pCases = dynamic_cast<QMLComplexItem*>((yyvsp[(5) - (5)].Object));

        if (pExpression != nullptr && pCases != nullptr)
        {
            QMLItem* pSwitch = new QMLSwitch(pExpression->position(), pExpression, pCases);

            (yyval.Object) = pSwitch;
        }
        else
        {
            (yyval.Object) = new QMLItem(pContext->position());
        }
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1132 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (3)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 1139 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pExpression = new QMLItem(pContext->position(), "default");

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1148 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoBreak);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1155 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoContinue);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1162 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1169 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1176 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1185 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1190 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1197 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpression", "Identifier JSVariables");

        QMLItem* pVariable = (yyvsp[(2) - (2)].Object);
        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (2)].Object));

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

  case 89:

/* Line 1455 of yacc.c  */
#line 1225 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpression", "JSExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1234 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Empty");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1241 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "Identifier JSVariables");

        QMLItem* pVariable = (yyvsp[(2) - (2)].Object);
        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (2)].Object));

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

  case 92:

/* Line 1455 of yacc.c  */
#line 1269 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariablesOrExpressionOpt", "JSExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1278 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        QMLItem* pVariable = (yyvsp[(1) - (1)].Object);

        QMLComplexItem* pVariables = new QMLComplexItem(pVariables->position());
        pVariables->contents() << pVariable;

        (yyval.Object) = pVariables;
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1290 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        QMLComplexItem* pVariables = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pVariable = (yyvsp[(3) - (3)].Object);

        if (pVariables != nullptr)
        {
            pVariables->contents() << pVariable;

            (yyval.Object) = pVariables;
        }
        else
        {
            (yyval.Object) = nullptr;
        }
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1311 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1318 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

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

  case 97:

/* Line 1455 of yacc.c  */
#line 1335 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSObject");

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

  case 98:

/* Line 1455 of yacc.c  */
#line 1354 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1361 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 100:

/* Line 1455 of yacc.c  */
#line 1378 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1385 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1392 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 103:

/* Line 1455 of yacc.c  */
#line 1409 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 104:

/* Line 1455 of yacc.c  */
#line 1426 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 105:

/* Line 1455 of yacc.c  */
#line 1443 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 1460 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 107:

/* Line 1455 of yacc.c  */
#line 1477 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 1496 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1501 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1508 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1515 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 112:

/* Line 1455 of yacc.c  */
#line 1531 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1540 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1547 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 115:

/* Line 1455 of yacc.c  */
#line 1566 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1573 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 117:

/* Line 1455 of yacc.c  */
#line 1592 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1597 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 119:

/* Line 1455 of yacc.c  */
#line 1614 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1619 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 121:

/* Line 1455 of yacc.c  */
#line 1636 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1641 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 123:

/* Line 1455 of yacc.c  */
#line 1656 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 124:

/* Line 1455 of yacc.c  */
#line 1671 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 125:

/* Line 1455 of yacc.c  */
#line 1686 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 126:

/* Line 1455 of yacc.c  */
#line 1703 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1708 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 128:

/* Line 1455 of yacc.c  */
#line 1723 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 1738 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 130:

/* Line 1455 of yacc.c  */
#line 1753 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 131:

/* Line 1455 of yacc.c  */
#line 1770 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1775 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 133:

/* Line 1455 of yacc.c  */
#line 1790 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 134:

/* Line 1455 of yacc.c  */
#line 1807 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1812 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 136:

/* Line 1455 of yacc.c  */
#line 1827 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 137:

/* Line 1455 of yacc.c  */
#line 1842 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 138:

/* Line 1455 of yacc.c  */
#line 1857 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 139:

/* Line 1455 of yacc.c  */
#line 1872 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 140:

/* Line 1455 of yacc.c  */
#line 1889 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1894 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_INC");

        QMLItem* pItem = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoIncrement, true);
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1903 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoIncrement);
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1910 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSUnaryExpression", "JSMemberExpression TOKEN_DEC");

        QMLItem* pItem = (yyvsp[(1) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoDecrement, true);
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1919 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoDecrement);
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1926 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoNot);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1933 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoTypeof);
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1940 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoMinus);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1947 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pItem = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pItem->position(), pItem, QMLUnaryOperation::uoNew);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1956 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1963 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 151:

/* Line 1455 of yacc.c  */
#line 1985 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1992 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSArrayAccessExpression '[' JSExpression ']'");

        QMLItem* pLeft = (yyvsp[(1) - (4)].Object);
        QMLArrayAccess* pArrayAccess = dynamic_cast<QMLArrayAccess*>((yyvsp[(1) - (4)].Object));
        QMLItem* pIndexer = (yyvsp[(3) - (4)].Object);

        if (pArrayAccess == nullptr)
        {
            pArrayAccess = new QMLArrayAccess(pIndexer->position(), pLeft);
        }

        pArrayAccess->contents() << pIndexer;

        (yyval.Object) = pArrayAccess;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 2012 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 2019 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLItem* pArgument = (yyvsp[(3) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        if (pArguments == nullptr && pArgument != nullptr)
        {
            pArguments = new QMLComplexItem(pArgument->position());
            pArguments->contents() << pArgument;
        }

        (yyval.Object) = new QMLFunctionCall(pName->position(), pName, pArguments);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 2038 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 2045 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 2052 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        QMLItem* pItem = (yyvsp[(2) - (3)].Object);

        pItem->setIsParenthesized(true);

        (yyval.Object) = pItem;
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 2065 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 2072 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 2081 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLItem* pArgument = (yyvsp[(1) - (1)].Object);

        QMLComplexItem* pList = new QMLComplexItem(pArgument->position());
        pList->setIsArgumentList(true);
        pList->contents() << pArgument;

        (yyval.Object) = pList;
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 2094 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pArgument = (yyvsp[(3) - (3)].Object);

        pList->contents() << pArgument;

        (yyval.Object) = pList;
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 2108 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 2113 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 2118 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 2125 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' JSAttributes '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 2132 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'{' '}'");

        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());
        pComplex->setIsObject(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 2142 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "TOKEN_DIMENSION");

        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());
        pComplex->setIsArray(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 2152 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSObject", "'[' JSArrayContents ']'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 2161 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSObject");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pItem = (yyvsp[(3) - (3)].Object);

        pComplex->contents() << pItem;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 2173 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSArrayContents ',' JSExpressionSingle");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pItem = (yyvsp[(3) - (3)].Object);

        pComplex->contents() << pItem;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 2185 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSObject");

        QMLItem* pItem = (yyvsp[(1) - (1)].Object);

        if (pItem == nullptr)
            pItem = new QMLItem(pContext->position());

        QMLComplexItem* pComplex = new QMLComplexItem(pItem->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pItem;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 2201 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayContents", "JSExpressionSingle");

        QMLItem* pItem = (yyvsp[(1) - (1)].Object);

        if (pItem == nullptr)
            pItem = new QMLItem(pContext->position());

        QMLComplexItem* pComplex = new QMLComplexItem(pItem->position());
        pComplex->setIsArray(true);
        pComplex->contents() << pItem;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 2219 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributes", "JSAttribute");

        QMLItem* pAttribute1 = (yyvsp[(1) - (1)].Object);

        QMLComplexItem* pComplex = new QMLComplexItem(pAttribute1->position());
        pComplex->setIsObject(true);

        pComplex->contents() << pAttribute1;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 2233 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributes", "JSAttributes JSAttribute");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pAttribute2 = (yyvsp[(2) - (2)].Object);

        pComplex->contents() << pAttribute2;

        (yyval.Object) = pComplex;
    ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 2247 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 2254 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttribute", "JSAttributeNoComma ','");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 2263 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSObject");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

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

  case 178:

/* Line 1455 of yacc.c  */
#line 2286 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAttributeNoComma", "JSAttributeName ':' JSExpressionSingle");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pValue = (yyvsp[(3) - (3)].Object);

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

  case 179:

/* Line 1455 of yacc.c  */
#line 2311 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 2316 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2323 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("QualifiedIdentifier", "Identifier");

        QMLItem* pIdentifier = (yyvsp[(1) - (1)].Object);

        (yyval.Object) = pIdentifier;
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 2332 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("QualifiedIdentifier", "QualifiedIdentifier '.' Identifier");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 2348 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 184:

/* Line 1455 of yacc.c  */
#line 2364 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), pContext->tokenValue());
    ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 2371 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 2376 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 2381 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 2386 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 2393 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 2400 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 2407 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 2414 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 193:

/* Line 1455 of yacc.c  */
#line 2429 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 4784 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 2433 "D:/Work/Projects/qt-plus/source/bison/QML.y"


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

