
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
#line 9 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"

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
#include "QMLUnaryOperation.h"
#include "QMLBinaryOperation.h"
#include "QMLIf.h"
#include "QMLFor.h"
#include "QMLSwitch.h"
#include "QMLConditional.h"
#include "QMLTreeContext.h"

int yylex (void*, void*);
int yyerror (void*, char*);

#define SAFE_DELETE(a)  if ((a) != nullptr) delete (a);

// #define PARSER_TRACE(state, rule)  { qDebug() << state " : " << rule; }
#define PARSER_TRACE(state, rule)



/* Line 189 of yacc.c  */
#line 107 "C:/User/E487027/Work/Projects/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"

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
     TOKEN_SIGNAL = 528
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"

    bool        Boolean;
    int         Integer;
    double      Real;
    QString*    String;
    QMLItem*    Object;



/* Line 214 of yacc.c  */
#line 225 "C:/User/E487027/Work/Projects/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 237 "C:/User/E487027/Work/Projects/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"

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
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  304

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   529

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      78,    79,     2,     2,    75,     2,    81,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,    76,
       2,     2,     2,    80,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,    74,     2,     2,     2,     2,
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
      64,    65,    66,    67,    68,    69,    70,    71,    72,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    20,
      26,    29,    34,    37,    42,    46,    53,    55,    58,    62,
      64,    66,    68,    70,    72,    74,    77,    82,    89,    96,
      98,   100,   102,   104,   108,   110,   112,   114,   116,   119,
     123,   128,   132,   136,   139,   141,   145,   147,   150,   154,
     158,   160,   163,   165,   168,   170,   172,   174,   176,   178,
     180,   182,   184,   186,   188,   190,   196,   204,   214,   222,
     228,   234,   238,   241,   243,   245,   251,   254,   257,   259,
     261,   264,   266,   268,   271,   273,   275,   279,   281,   285,
     287,   291,   293,   295,   299,   303,   307,   311,   315,   319,
     321,   327,   329,   331,   335,   337,   341,   343,   347,   349,
     353,   355,   359,   363,   367,   371,   373,   377,   381,   385,
     389,   391,   395,   399,   401,   405,   409,   413,   417,   421,
     423,   426,   429,   432,   434,   438,   440,   445,   447,   452,
     454,   456,   460,   462,   464,   466,   470,   472,   474,   476,
     478,   480,   482,   484,   488,   491,   493,   497,   499,   503,
     505,   507,   511,   513,   516,   518,   521,   525,   529,   531,
     533,   535,   539,   541,   543,   545,   547,   549,   551,   553,
     555,   557,   559
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      85,     0,    -1,    86,    -1,    87,    -1,    86,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    44,   151,   153,    -1,
      44,   151,   153,    71,   152,    -1,    44,   158,    -1,    44,
     158,    71,   152,    -1,    69,   151,    -1,   152,    73,    91,
      74,    -1,   152,    73,    74,    -1,   152,    70,   152,    73,
      91,    74,    -1,    92,    -1,    91,    92,    -1,    91,    75,
      92,    -1,    97,    -1,    93,    -1,    90,    -1,   101,    -1,
      99,    -1,    94,    -1,    94,    76,    -1,    95,    45,   152,
     152,    -1,    95,    45,   152,   152,    77,    98,    -1,    95,
      45,    48,   152,    77,    98,    -1,   159,    -1,    96,    -1,
      46,    -1,    47,    -1,   151,    77,    98,    -1,    90,    -1,
     107,    -1,   145,    -1,   100,    -1,   100,    76,    -1,    72,
     152,   102,    -1,    56,   152,   102,   107,    -1,    56,   102,
     107,    -1,    78,   103,    79,    -1,    78,    79,    -1,   104,
      -1,   103,    75,   104,    -1,   152,    -1,   152,   152,    -1,
      73,   159,    74,    -1,    73,   106,    74,    -1,   107,    -1,
     106,   107,    -1,   108,    -1,   108,    76,    -1,   105,    -1,
     119,    -1,   109,    -1,   110,    -1,   111,    -1,   112,    -1,
     113,    -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,
      57,    78,   123,    79,   107,    -1,    57,    78,   123,    79,
     107,    58,   107,    -1,    59,    78,   120,    76,   118,    76,
     118,    79,   107,    -1,    59,    78,   120,    60,   123,    79,
     107,    -1,    61,    78,   123,    79,   107,    -1,    62,    78,
     123,    79,   105,    -1,    63,   123,    77,    -1,    46,    77,
      -1,    64,    -1,    65,    -1,    66,    78,   123,    79,   107,
      -1,    67,   145,    -1,    67,   118,    -1,   159,    -1,   123,
      -1,    49,   121,    -1,   123,    -1,   159,    -1,   152,   121,
      -1,   123,    -1,   122,    -1,   121,    75,   122,    -1,   152,
      -1,   152,     8,   125,    -1,   124,    -1,   124,    75,   123,
      -1,   125,    -1,   126,    -1,   126,     8,   125,    -1,   126,
      19,   125,    -1,   126,    20,   125,    -1,   126,    21,   125,
      -1,   126,    22,   125,    -1,   126,     8,   145,    -1,   127,
      -1,   127,    80,   125,    77,   125,    -1,   101,    -1,   128,
      -1,   128,    38,   127,    -1,   129,    -1,   129,    16,   128,
      -1,   130,    -1,   130,    37,   129,    -1,   131,    -1,   131,
      14,   130,    -1,   132,    -1,   132,    33,   131,    -1,   132,
      34,   131,    -1,   132,    35,   131,    -1,   132,    36,   131,
      -1,   133,    -1,   132,    29,   133,    -1,   132,    31,   133,
      -1,   132,    30,   133,    -1,   132,    32,   133,    -1,   134,
      -1,   134,     9,   133,    -1,   134,    10,   133,    -1,   135,
      -1,   135,    11,   134,    -1,   135,    12,   134,    -1,   135,
      13,   134,    -1,   135,    17,   134,    -1,   135,    18,   134,
      -1,   136,    -1,   136,   143,    -1,   144,   136,    -1,    10,
     136,    -1,   137,    -1,   137,    81,   136,    -1,   138,    -1,
     138,    82,   123,    83,    -1,   139,    -1,   139,    78,   140,
      79,    -1,   152,    -1,   154,    -1,    78,   123,    79,    -1,
     159,    -1,   141,    -1,   142,    -1,   141,    75,   142,    -1,
      45,    -1,   145,    -1,   125,    -1,    40,    -1,    41,    -1,
      39,    -1,    68,    -1,    73,   147,    74,    -1,    73,    74,
      -1,    43,    -1,    82,   146,    83,    -1,   145,    -1,   146,
      75,   145,    -1,    91,    -1,   154,    -1,   146,    75,   154,
      -1,   148,    -1,   147,   148,    -1,   149,    -1,   149,    75,
      -1,   150,    77,   145,    -1,   150,    77,   124,    -1,   158,
      -1,   152,    -1,   152,    -1,   151,    81,   152,    -1,     3,
      -1,     7,    -1,   155,    -1,   156,    -1,   157,    -1,   158,
      -1,     5,    -1,     6,    -1,     7,    -1,     4,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   143,   155,   169,   176,   183,   192,   210,
     228,   244,   262,   270,   285,   295,   312,   331,   346,   363,
     370,   377,   384,   391,   400,   407,   416,   433,   451,   470,
     475,   482,   487,   494,   507,   514,   521,   530,   537,   546,
     558,   569,   582,   589,   598,   605,   616,   633,   652,   659,
     668,   686,   703,   710,   719,   726,   733,   740,   747,   754,
     761,   768,   775,   782,   789,   798,   811,   827,   842,   869,
     881,   900,   907,   916,   923,   930,   937,   944,   953,   958,
     965,   970,   977,   982,   987,   994,  1001,  1012,  1019,  1030,
    1037,  1054,  1061,  1068,  1085,  1102,  1119,  1136,  1153,  1172,
    1179,  1195,  1204,  1211,  1230,  1237,  1256,  1261,  1278,  1283,
    1300,  1305,  1320,  1335,  1350,  1367,  1372,  1387,  1402,  1417,
    1434,  1439,  1454,  1471,  1476,  1491,  1506,  1521,  1536,  1553,
    1558,  1563,  1568,  1575,  1582,  1604,  1611,  1620,  1627,  1639,
    1646,  1653,  1662,  1669,  1678,  1694,  1715,  1720,  1725,  1732,
    1737,  1744,  1749,  1756,  1761,  1766,  1774,  1791,  1796,  1803,
    1808,  1813,  1830,  1835,  1854,  1859,  1866,  1885,  1906,  1911,
    1918,  1923,  1937,  1953,  1960,  1965,  1970,  1975,  1982,  1989,
    1996,  2003,  2019
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
  "TOKEN_PRAGMA", "TOKEN_ON", "TOKEN_AS", "TOKEN_SIGNAL", "'{'", "'}'",
  "','", "';'", "':'", "'('", "')'", "'?'", "'.'", "'['", "']'", "$accept",
  "File", "Declarations", "Declaration", "ImportStatement",
  "PragmaStatement", "Item", "ItemContents", "ItemContent",
  "PropertyDeclaration", "PropertyDeclarationNoColon",
  "PropertyModifiersOpt", "PropertyModifiers", "PropertyAssignment",
  "PropertyContent", "SignalDeclaration", "SignalDeclarationNoColon",
  "JSFunction", "JSFunctionParameterList", "JSFunctionParameters",
  "JSFunctionParameter", "JSStatementBlock", "JSStatements", "JSStatement",
  "JSStatementNoColon", "JSStatement_If", "JSStatement_For",
  "JSStatement_While", "JSStatement_Switch", "JSStatement_Case",
  "JSStatement_Break", "JSStatement_Continue", "JSStatement_With",
  "JSStatement_Return", "JSExpressionOpt", "JSVariablesOrExpression",
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
       0,   256,   529,   300,   301,   302,   303,   304,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   123,   125,    44,    59,    58,    40,    41,
      63,    46,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    90,    90,    90,    91,    91,    91,    92,
      92,    92,    92,    92,    93,    93,    94,    94,    94,    95,
      95,    96,    96,    97,    98,    98,    98,    99,    99,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     112,   113,   113,   114,   115,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   131,   131,   131,   132,   132,   132,   132,   132,
     133,   133,   133,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   142,   142,   143,
     143,   144,   144,   145,   145,   145,   145,   146,   146,   146,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   151,   152,   153,   154,   154,   154,   154,   155,   156,
     157,   158,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     5,
       2,     4,     2,     4,     3,     6,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     4,     6,     6,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     3,
       4,     3,     3,     2,     1,     3,     1,     2,     3,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     9,     7,     5,
       5,     3,     2,     1,     1,     5,     2,     2,     1,     1,
       2,     1,     1,     2,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       5,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       2,     2,     2,     1,     3,     1,     4,     1,     4,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     3,     1,     3,     1,
       1,     3,     1,     2,     1,     2,     3,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   172,     0,     0,     0,     2,     3,     5,     6,     7,
       0,   181,     0,   170,    10,    12,     1,     4,     0,   182,
     173,     0,     8,     0,     0,    31,    32,     0,     0,    14,
      21,   182,    16,    20,    24,     0,    30,    19,    23,    37,
      22,     0,   170,    29,   171,     0,    11,   182,     0,     0,
       0,     0,    13,   182,    17,    25,     0,    38,     0,     9,
     182,    43,     0,    44,    46,   178,   179,   180,     0,   151,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
     182,   152,   182,     0,   101,    54,    41,    52,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    55,    81,    89,
      91,    92,    99,   102,   104,   106,   108,   110,   115,   120,
     123,   129,   133,   135,   137,     0,   139,   140,   174,   175,
     176,   177,     0,    39,    18,     0,     0,   155,     0,   182,
      34,    33,    35,    36,   139,    15,     0,    42,    47,   132,
      72,    80,    85,    87,     0,   182,     0,     0,     0,     0,
       0,    77,    79,    76,    78,     0,    50,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   150,   130,     0,
       0,   182,   131,    40,     0,    26,   154,     0,   162,   164,
       0,   139,   177,   159,   157,     0,   160,    45,     0,     0,
       0,     0,    84,   139,    82,     0,     0,    71,     0,   169,
     168,    49,    51,    48,   141,    90,    93,    98,    94,    95,
      96,    97,     0,   103,   105,   107,   109,   116,   118,   117,
     119,   111,   112,   113,   114,   121,   122,   124,   125,   126,
     127,   128,   134,     0,   146,   148,     0,   143,   144,   147,
     142,     0,     0,   153,   163,   165,     0,     0,   156,    86,
      88,     0,     0,   182,    83,     0,     0,     0,     0,   136,
     138,     0,    28,    27,   167,   166,   158,   161,    65,     0,
       0,    69,    70,    75,   100,   145,     0,     0,   182,    66,
      68,     0,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    30,    31,    32,    33,
      34,    35,    36,    37,   131,    38,    39,    84,    49,    62,
      63,    85,   155,   132,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   151,    97,   211,   141,   142,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   256,   257,   258,   188,
     115,   133,   205,   197,   198,   199,   200,    41,   116,    22,
     117,   118,   119,   120,   121,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -248
static const yytype_int16 yypact[] =
{
      40,  -248,    69,    32,    44,    40,  -248,  -248,  -248,  -248,
      62,  -248,    10,  -248,   -25,   -22,  -248,  -248,    32,   138,
    -248,    32,   -10,    32,    16,  -248,  -248,    22,    32,  -248,
    -248,   253,  -248,  -248,   -63,    38,  -248,  -248,  -248,    20,
    -248,    13,    62,  -248,  -248,    32,  -248,   248,     7,   413,
      24,    24,  -248,   248,  -248,  -248,    27,  -248,   109,  -248,
     268,  -248,    42,  -248,    32,  -248,  -248,  -248,   213,  -248,
      41,    32,    45,    56,    71,    73,   347,  -248,  -248,    75,
     240,  -248,   413,   347,  -248,  -248,  -248,    54,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,    81,
    -248,   339,    79,   125,   151,   132,   164,   463,  -248,   129,
      93,   102,   105,   101,   111,   213,  -248,  -248,  -248,  -248,
    -248,  -248,   413,  -248,  -248,    32,    32,  -248,   328,   283,
    -248,  -248,  -248,  -248,    62,  -248,    32,  -248,  -248,  -248,
    -248,   113,  -248,   182,   347,   347,   347,   347,   115,   347,
      29,  -248,  -248,  -248,  -248,   365,  -248,   119,   116,  -248,
     347,   240,   347,   347,   347,   347,   347,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,  -248,  -248,  -248,   213,
     347,   229,  -248,  -248,   134,   137,  -248,    46,  -248,   121,
     145,   147,   148,    52,  -248,   -18,  -248,  -248,    32,   347,
     123,    -8,  -248,    32,  -248,   149,   152,  -248,   162,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,   165,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,   143,  -248,  -248,   173,   180,  -248,  -248,
    -248,   109,   109,  -248,  -248,  -248,   240,   194,  -248,  -248,
    -248,   413,   347,   347,   113,   413,   190,   413,   347,  -248,
    -248,   229,  -248,  -248,  -248,  -248,  -248,  -248,   195,   185,
     193,  -248,  -248,  -248,  -248,  -248,   413,   413,   347,  -248,
    -248,   191,   413,  -248
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,   270,  -248,  -248,     4,   -36,   -24,  -248,
    -248,  -248,  -248,  -248,  -115,  -248,  -248,    35,   110,  -248,
     141,    -3,  -248,   -48,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -247,  -248,  -248,    65,    72,   -68,
      15,  -124,  -248,   117,   114,   124,   122,    82,  -248,   284,
     197,  -248,   -52,  -248,  -248,  -248,  -248,  -248,    17,  -248,
    -248,   -60,  -248,  -248,   104,  -248,  -248,   178,     0,  -248,
    -123,  -248,  -248,  -248,    12,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -183
static const yytype_int16 yytable[] =
{
      10,    86,    13,    13,     9,    10,   206,    54,   148,     9,
       1,    60,   152,    55,    14,   158,   139,    20,    24,    42,
     153,    44,   154,    46,   157,     1,   290,    50,    51,   124,
       1,    42,     1,    11,   156,     1,    54,   226,   228,   229,
     230,   231,   232,     1,    16,    59,    23,    42,    64,     1,
      11,   301,   272,    42,    40,     1,   126,   267,   134,    21,
      42,    45,   130,   192,   138,   268,    40,   255,   273,   204,
     157,   143,     1,    11,   193,   125,   210,   212,   215,   216,
     156,   218,    40,    56,     2,   270,    61,   214,    40,    47,
      58,    21,   225,   203,    21,    40,    57,  -182,    25,    26,
      48,   227,    48,   196,   181,   182,   183,   222,    27,     3,
     184,   185,     1,    11,    65,    66,    67,   136,   140,    68,
     263,   137,   253,   144,    28,   194,   195,    53,   201,    42,
     159,   259,    18,   260,   145,    19,    64,   252,   179,   180,
     202,     1,   186,   187,   287,   213,   282,   283,    69,   146,
     219,   147,   127,   149,   294,    70,   160,   255,    71,   166,
     122,   123,   220,   167,    40,    27,    72,   168,    73,   169,
      74,    75,    76,    77,    78,    79,    80,    81,   170,    54,
      12,    15,   128,   190,    25,    26,   189,    83,   208,   191,
     209,   129,   217,   223,    27,   224,   265,   219,    11,    65,
      66,    67,   271,    42,   289,   152,   285,   286,   143,   220,
      28,   261,    29,   143,   262,   154,     1,    11,    65,    66,
      67,   259,   266,   288,  -169,  -168,   279,   291,   275,   293,
     152,   276,     1,    11,    65,    66,    67,   127,    40,    68,
     154,   277,   278,     1,    11,    65,    66,    67,   299,   300,
      68,     1,   280,   296,   303,   281,     1,   241,   242,   243,
     244,   134,   134,    82,   297,   130,   130,   150,    69,   298,
     302,     1,   127,   292,   254,    17,   129,   207,   274,    69,
     269,   284,   234,   127,   233,    27,     1,    11,    65,    66,
      67,    83,   236,   235,    25,    26,    27,    81,   295,    25,
      26,   264,   150,     0,    27,     0,     0,    83,    81,    27,
       0,   129,     0,   150,    25,    26,     0,     0,    83,     0,
      28,     0,   129,     0,    27,    28,   127,    52,    53,    25,
      26,     1,    11,    65,    66,    67,     0,     0,    68,    27,
      28,     0,   135,    53,     0,     0,     0,   161,     0,     0,
       1,    11,    65,    66,    67,    28,   150,    68,   162,   163,
     164,   165,     0,     0,     0,   129,     0,    69,     1,    11,
      65,    66,    67,     0,    70,    68,     0,    71,   247,   248,
     249,   250,   251,     0,    27,    72,    69,    73,     0,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
       0,    82,   196,    27,    69,     0,    83,     0,     0,     0,
       0,    70,     0,     0,    71,    81,     1,    11,    65,    66,
      67,    27,    72,    68,    73,    83,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,    82,   221,
       0,     0,     0,    83,     0,     0,     1,    11,    65,    66,
      67,     0,    69,    68,     0,   237,   238,   239,   240,    70,
       0,     0,    71,   245,   246,     0,     0,     0,     0,    27,
      72,     0,    73,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    69,     0,     0,     0,    82,     0,     0,     0,
       0,    83,   171,   172,   173,   174,   175,   176,   177,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83
};

static const yytype_int16 yycheck[] =
{
       0,    49,     2,     3,     0,     5,   129,    31,    76,     5,
       3,    47,    80,    76,     2,    83,    68,     7,    18,    19,
      80,    21,    80,    23,    82,     3,   273,    27,    28,    53,
       3,    31,     3,     4,    82,     3,    60,   161,   162,   163,
     164,   165,   166,     3,     0,    45,    71,    47,    48,     3,
       4,   298,    60,    53,    19,     3,    56,    75,    58,    81,
      60,    71,    58,   115,    64,    83,    31,   191,    76,   129,
     128,    71,     3,     4,   122,    48,   144,   145,   146,   147,
     128,   149,    47,    45,    44,   209,    79,   145,    53,    73,
      77,    81,   160,   129,    81,    60,    76,    45,    46,    47,
      78,   161,    78,    74,    11,    12,    13,   155,    56,    69,
      17,    18,     3,     4,     5,     6,     7,    75,    77,    10,
      74,    79,   190,    78,    72,   125,   126,    75,   128,   129,
      76,   191,    70,   191,    78,    73,   136,   189,     9,    10,
     128,     3,    40,    41,   267,   145,   261,   262,    39,    78,
     150,    78,    43,    78,   278,    46,    75,   281,    49,    80,
      50,    51,   150,    38,   129,    56,    57,    16,    59,    37,
      61,    62,    63,    64,    65,    66,    67,    68,    14,   203,
       2,     3,    73,    82,    46,    47,    81,    78,    75,    78,
       8,    82,    77,    74,    56,    79,    75,   197,     4,     5,
       6,     7,    79,   203,   272,   273,   266,   267,   208,   197,
      72,    77,    74,   213,    77,   273,     3,     4,     5,     6,
       7,   281,    77,   271,    77,    77,    83,   275,    79,   277,
     298,    79,     3,     4,     5,     6,     7,    43,   203,    10,
     298,    79,    77,     3,     4,     5,     6,     7,   296,   297,
      10,     3,    79,    58,   302,    75,     3,   175,   176,   177,
     178,   261,   262,    73,    79,   261,   262,    73,    39,    76,
      79,     3,    43,   276,    45,     5,    82,   136,   213,    39,
     208,   266,   168,    43,   167,    56,     3,     4,     5,     6,
       7,    78,   170,   169,    46,    47,    56,    68,   281,    46,
      47,   197,    73,    -1,    56,    -1,    -1,    78,    68,    56,
      -1,    82,    -1,    73,    46,    47,    -1,    -1,    78,    -1,
      72,    -1,    82,    -1,    56,    72,    43,    74,    75,    46,
      47,     3,     4,     5,     6,     7,    -1,    -1,    10,    56,
      72,    -1,    74,    75,    -1,    -1,    -1,     8,    -1,    -1,
       3,     4,     5,     6,     7,    72,    73,    10,    19,    20,
      21,    22,    -1,    -1,    -1,    82,    -1,    39,     3,     4,
       5,     6,     7,    -1,    46,    10,    -1,    49,   181,   182,
     183,   184,   185,    -1,    56,    57,    39,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    73,    74,    56,    39,    -1,    78,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    68,     3,     4,     5,     6,
       7,    56,    57,    10,    59,    78,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    -1,    78,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    39,    10,    -1,   171,   172,   173,   174,    46,
      -1,    -1,    49,   179,   180,    -1,    -1,    -1,    -1,    56,
      57,    -1,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    39,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    78,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    69,    85,    86,    87,    88,    89,    90,
     152,     4,   151,   152,   158,   151,     0,    87,    70,    73,
       7,    81,   153,    71,   152,    46,    47,    56,    72,    74,
      90,    91,    92,    93,    94,    95,    96,    97,    99,   100,
     101,   151,   152,   159,   152,    71,   152,    73,    78,   102,
     152,   152,    74,    75,    92,    76,    45,    76,    77,   152,
      91,    79,   103,   104,   152,     5,     6,     7,    10,    39,
      46,    49,    57,    59,    61,    62,    63,    64,    65,    66,
      67,    68,    73,    78,   101,   105,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   119,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   144,   152,   154,   155,   156,
     157,   158,   102,   102,    92,    48,   152,    43,    73,    82,
      90,    98,   107,   145,   152,    74,    75,    79,   152,   136,
      77,   121,   122,   152,    78,    78,    78,    78,   123,    78,
      73,   118,   123,   145,   159,   106,   107,   159,   123,    76,
      75,     8,    19,    20,    21,    22,    80,    38,    16,    37,
      14,    29,    30,    31,    32,    33,    34,    35,    36,     9,
      10,    11,    12,    13,    17,    18,    40,    41,   143,    81,
      82,    78,   136,   107,   152,   152,    74,   147,   148,   149,
     150,   152,   158,    91,   145,   146,   154,   104,    75,     8,
     123,   120,   123,   152,   159,   123,   123,    77,   123,   152,
     158,    74,   107,    74,    79,   123,   125,   145,   125,   125,
     125,   125,   125,   127,   128,   129,   130,   133,   133,   133,
     133,   131,   131,   131,   131,   133,   133,   134,   134,   134,
     134,   134,   136,   123,    45,   125,   140,   141,   142,   145,
     159,    77,    77,    74,   148,    75,    77,    75,    83,   122,
     125,    79,    60,    76,   121,    79,    79,    79,    77,    83,
      79,    75,    98,    98,   124,   145,   145,   154,   107,   123,
     118,   107,   105,   107,   125,   142,    58,    79,    76,   107,
     107,   118,    79,   107
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
#line 138 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 144 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 156 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 170 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "ImportStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 177 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "PragmaStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 184 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Declaration", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 193 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 211 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 229 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 245 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 263 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 271 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 286 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pContext->position(), pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 296 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 313 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 332 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 347 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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
#line 364 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 371 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 378 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 385 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 392 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 401 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 408 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 417 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(3) - (4)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (4)].Object));

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
#line 434 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY Identifier Identifier ':' PropertyContent");

        QMLType* pType = QMLType::fromQMLItem(dynamic_cast<QMLItem*>((yyvsp[(3) - (6)].Object)));
        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (6)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(6) - (6)].Object));

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
#line 452 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclarationNoColon", "PropertyModifiersOpt TOKEN_PROPERTY TOKEN_ALIAS Identifier ':' PropertyContent");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(4) - (6)].Object));
        QMLItem* pData = dynamic_cast<QMLItem*>((yyvsp[(6) - (6)].Object));

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
#line 471 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 476 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 483 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 488 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 495 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "QualifiedIdentifier ':' PropertyContent");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(pContext->position(), pName, pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 508 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 515 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 522 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 531 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 538 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 547 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, nullptr);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 559 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatement");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (4)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 570 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION JSFunctionParameterList JSStatement");

        QMLItem* pName = new QMLIdentifier(pContext->position(), "");
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pContext->position(), pName, pParameters, pContent);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 583 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 590 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 599 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 606 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 617 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 47:

/* Line 1455 of yacc.c  */
#line 634 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 48:

/* Line 1455 of yacc.c  */
#line 653 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' Empty '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 660 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 669 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 51:

/* Line 1455 of yacc.c  */
#line 687 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 52:

/* Line 1455 of yacc.c  */
#line 704 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 711 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 720 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 727 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 734 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 741 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 748 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 755 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Switch");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 762 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_Case");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 769 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 776 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 783 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 790 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 799 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 66:

/* Line 1455 of yacc.c  */
#line 812 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 67:

/* Line 1455 of yacc.c  */
#line 828 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 68:

/* Line 1455 of yacc.c  */
#line 843 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pInitialization = (yyvsp[(3) - (7)].Object);
        QMLItem* pCondition = nullptr;
        QMLItem* pIncrementation = nullptr;
        QMLItem* pContent = (yyvsp[(7) - (7)].Object);

        if (pInitialization == nullptr)
        {
            pInitialization = new QMLItem(pContext->position());
        }

        if (pCondition == nullptr)
        {
            pCondition = new QMLItem(pContext->position());
        }

        if (pIncrementation == nullptr)
        {
            pIncrementation = new QMLItem(pContext->position());
        }

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 870 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pInitialization = new QMLItem(pContext->position());
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pIncrementation = new QMLItem(pContext->position());
        QMLItem* pContent = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLFor(pInitialization->position(), pInitialization, pCondition, pIncrementation, pContent);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 882 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 71:

/* Line 1455 of yacc.c  */
#line 901 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (3)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 908 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pExpression = new QMLItem(pContext->position(), "default");

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoCase);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 917 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoBreak);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 924 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLUnaryOperation(pContext->position(), nullptr, QMLUnaryOperation::uoContinue);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 931 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 938 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 945 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pExpression = (yyvsp[(2) - (2)].Object);

        (yyval.Object) = new QMLUnaryOperation(pContext->position(), pExpression, QMLUnaryOperation::uoReturn);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 954 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 959 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 966 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 971 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 978 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 983 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 988 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 995 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1002 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1013 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1020 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1031 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1038 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 91:

/* Line 1455 of yacc.c  */
#line 1055 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1062 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1069 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 94:

/* Line 1455 of yacc.c  */
#line 1086 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 95:

/* Line 1455 of yacc.c  */
#line 1103 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 96:

/* Line 1455 of yacc.c  */
#line 1120 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 97:

/* Line 1455 of yacc.c  */
#line 1137 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 98:

/* Line 1455 of yacc.c  */
#line 1154 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 1173 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1180 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 101:

/* Line 1455 of yacc.c  */
#line 1196 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1205 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSXorExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1212 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 104:

/* Line 1455 of yacc.c  */
#line 1231 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSXorExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1238 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 1257 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1262 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 108:

/* Line 1455 of yacc.c  */
#line 1279 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1284 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 1301 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1306 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 112:

/* Line 1455 of yacc.c  */
#line 1321 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 113:

/* Line 1455 of yacc.c  */
#line 1336 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 114:

/* Line 1455 of yacc.c  */
#line 1351 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 115:

/* Line 1455 of yacc.c  */
#line 1368 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1373 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 117:

/* Line 1455 of yacc.c  */
#line 1388 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 118:

/* Line 1455 of yacc.c  */
#line 1403 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 119:

/* Line 1455 of yacc.c  */
#line 1418 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 120:

/* Line 1455 of yacc.c  */
#line 1435 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1440 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 122:

/* Line 1455 of yacc.c  */
#line 1455 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 123:

/* Line 1455 of yacc.c  */
#line 1472 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1477 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 125:

/* Line 1455 of yacc.c  */
#line 1492 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 126:

/* Line 1455 of yacc.c  */
#line 1507 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 127:

/* Line 1455 of yacc.c  */
#line 1522 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 128:

/* Line 1455 of yacc.c  */
#line 1537 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 1554 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1559 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1564 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1569 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1576 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1583 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 135:

/* Line 1455 of yacc.c  */
#line 1605 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1612 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSFunctionCall '[' JSExpression ']'");

        (yyval.Object) = (yyvsp[(1) - (4)].Object);
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1621 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1628 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSPrimaryExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        (yyval.Object) = new QMLFunctionCall(pName->position(), pName, pArguments);
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1640 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1647 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1654 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1663 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1670 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1679 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (1)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (1)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents() << pExpression1;
        }

        (yyval.Object) = pList;
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1695 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentList", "JSArgumentList ',' JSAssignmentExpression");

        QMLComplexItem* pList = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pExpression2 = (yyvsp[(3) - (3)].Object);

        if (pList == nullptr)
        {
            pList = new QMLComplexItem(pExpression1->position());
            pList->contents() << pExpression1;
        }

        pList->contents() << pExpression2;

        (yyval.Object) = pList;
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1716 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1721 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1726 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1733 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1738 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1745 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1750 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1757 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1762 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLComplexItem(pContext->position());
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1767 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = new QMLComplexItem(pContext->position());
        pComplex->setIsArray(true);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1775 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(2) - (3)].Object));
        QMLItem* pItem1 = (yyvsp[(2) - (3)].Object);

        if (pComplex == nullptr)
        {
            pComplex = new QMLComplexItem(pItem1->position());
            pComplex->contents() << pItem1;
            pComplex->setIsArray(true);
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1792 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1797 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);

        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1804 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1809 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1814 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pItem1 = (yyvsp[(1) - (3)].Object);
        QMLItem* pItem2 = (yyvsp[(3) - (3)].Object);

        if (pComplex == nullptr)
        {
            pComplex = new QMLComplexItem(pItem1->position());
            pComplex->contents() << pItem1;
        }

        pComplex->contents() << pItem2;
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1831 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1836 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 164:

/* Line 1455 of yacc.c  */
#line 1855 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1860 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1867 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 167:

/* Line 1455 of yacc.c  */
#line 1886 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 168:

/* Line 1455 of yacc.c  */
#line 1907 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1912 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1919 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1924 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1938 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 173:

/* Line 1455 of yacc.c  */
#line 1954 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), pContext->tokenValue());
    ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1961 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1966 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1971 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1976 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1983 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1990 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1997 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->position(), QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 2004 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
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

  case 182:

/* Line 1455 of yacc.c  */
#line 2019 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 4293 "C:/User/E487027/Work/Projects/unis-lib/src/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 2023 "C:/User/E487027/Work/Projects/unis-lib/src/bison/QML.y"


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

