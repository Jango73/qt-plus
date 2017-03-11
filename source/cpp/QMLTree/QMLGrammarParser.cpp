
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

#define PARSER_TRACE(state, rule)  { qDebug() << state " : " << rule; }
// #define PARSER_TRACE(state, rule)



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
#define YYLAST   471

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  273

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
      97,   101,   103,   105,   107,   109,   111,   114,   118,   123,
     127,   130,   132,   136,   138,   141,   145,   147,   150,   152,
     155,   157,   159,   161,   163,   165,   167,   169,   171,   173,
     179,   187,   197,   203,   205,   207,   213,   216,   218,   220,
     223,   225,   227,   230,   232,   234,   238,   240,   244,   246,
     250,   252,   254,   258,   262,   266,   270,   272,   278,   280,
     284,   286,   290,   292,   296,   298,   302,   306,   310,   314,
     316,   320,   324,   328,   332,   334,   338,   342,   344,   348,
     352,   356,   360,   364,   366,   369,   372,   375,   377,   381,
     383,   388,   390,   395,   397,   399,   403,   405,   407,   409,
     413,   415,   417,   419,   421,   423,   425,   427,   431,   434,
     436,   440,   442,   446,   448,   450,   452,   455,   457,   460,
     464,   468,   472,   474,   476,   478,   482,   484,   486,   488,
     490,   492,   494,   496,   498,   500,   502
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
      -1,    85,    -1,   100,    -1,   135,    -1,   136,    -1,    93,
      -1,    93,    71,    -1,    67,   143,    95,    -1,    54,   143,
      95,    98,    -1,    73,    96,    74,    -1,    73,    74,    -1,
      97,    -1,    96,    70,    97,    -1,   143,    -1,   143,   143,
      -1,    68,    99,    69,    -1,   100,    -1,    99,   100,    -1,
     101,    -1,   101,    71,    -1,    98,    -1,   110,    -1,   102,
      -1,   103,    -1,   104,    -1,   105,    -1,   106,    -1,   107,
      -1,   108,    -1,    55,    73,   114,    74,   100,    -1,    55,
      73,   114,    74,   100,    56,   100,    -1,    57,    73,   111,
      71,   109,    71,   109,    74,   100,    -1,    58,    73,   114,
      74,   100,    -1,    59,    -1,    60,    -1,    61,    73,   114,
      74,   100,    -1,    62,   109,    -1,   150,    -1,   114,    -1,
      47,   112,    -1,   114,    -1,   150,    -1,   143,   112,    -1,
     114,    -1,   113,    -1,   112,    70,   113,    -1,   143,    -1,
     143,     8,   116,    -1,   115,    -1,   115,    70,   114,    -1,
     116,    -1,   117,    -1,   117,     8,   116,    -1,   117,    19,
     116,    -1,   117,    20,   116,    -1,   117,     8,   135,    -1,
     118,    -1,   118,    75,   116,    72,   116,    -1,   119,    -1,
     119,    38,   118,    -1,   120,    -1,   120,    37,   119,    -1,
     121,    -1,   121,    14,   120,    -1,   122,    -1,   122,    33,
     121,    -1,   122,    34,   121,    -1,   122,    35,   121,    -1,
     122,    36,   121,    -1,   123,    -1,   122,    29,   123,    -1,
     122,    31,   123,    -1,   122,    30,   123,    -1,   122,    32,
     123,    -1,   124,    -1,   124,     9,   123,    -1,   124,    10,
     123,    -1,   125,    -1,   125,    11,   124,    -1,   125,    12,
     124,    -1,   125,    13,   124,    -1,   125,    17,   124,    -1,
     125,    18,   124,    -1,   126,    -1,   126,   133,    -1,   134,
     126,    -1,    10,   126,    -1,   127,    -1,   127,    76,   126,
      -1,   128,    -1,   128,    73,   130,    74,    -1,   129,    -1,
     129,    77,   114,    78,    -1,   143,    -1,   145,    -1,    73,
     114,    74,    -1,   150,    -1,   131,    -1,   132,    -1,   131,
      70,   132,    -1,    45,    -1,   135,    -1,   116,    -1,    40,
      -1,    41,    -1,    39,    -1,    63,    -1,    68,   138,    69,
      -1,    68,    69,    -1,    43,    -1,    77,   137,    78,    -1,
     135,    -1,   137,    70,   135,    -1,    86,    -1,   145,    -1,
     139,    -1,   138,   139,    -1,   140,    -1,   140,    70,    -1,
     141,    72,   135,    -1,   141,    72,   136,    -1,   141,    72,
     115,    -1,   149,    -1,   143,    -1,   143,    -1,   142,    76,
     143,    -1,     3,    -1,     7,    -1,   146,    -1,   147,    -1,
     148,    -1,   149,    -1,     5,    -1,     6,    -1,     7,    -1,
       4,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   136,   148,   162,   169,   176,   192,   210,
     228,   244,   262,   270,   285,   295,   312,   331,   346,   363,
     370,   377,   384,   391,   400,   407,   416,   433,   451,   470,
     481,   493,   500,   507,   514,   523,   530,   539,   551,   563,
     570,   579,   586,   597,   614,   633,   642,   654,   671,   678,
     687,   694,   701,   708,   715,   722,   729,   736,   743,   752,
     760,   771,   783,   795,   802,   809,   816,   823,   828,   835,
     840,   847,   852,   857,   864,   871,   882,   889,   900,   907,
     924,   938,   945,   955,   965,   975,   987,   994,  1007,  1014,
    1026,  1031,  1041,  1046,  1056,  1061,  1069,  1077,  1085,  1095,
    1100,  1108,  1116,  1124,  1134,  1139,  1147,  1157,  1162,  1170,
    1178,  1186,  1194,  1204,  1209,  1214,  1219,  1226,  1233,  1270,
    1277,  1289,  1296,  1305,  1312,  1319,  1328,  1335,  1344,  1360,
    1381,  1386,  1391,  1398,  1403,  1410,  1415,  1422,  1427,  1434,
    1439,  1446,  1451,  1458,  1463,  1470,  1475,  1494,  1499,  1506,
    1525,  1544,  1565,  1570,  1577,  1582,  1596,  1612,  1619,  1624,
    1629,  1634,  1641,  1648,  1655,  1662,  1678
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
  "JSConditionalExpression", "JSOrExpression", "JSAndExpression",
  "JSBitwiseAndExpression", "JSEqualityExpression",
  "JSRelationalExpression", "JSAdditiveExpression",
  "JSMultiplicativeExpression", "JSUnaryExpression", "JSMemberExpression",
  "JSFunctionCall", "JSArrayAccessExpression", "JSPrimaryExpression",
  "JSArgumentListOpt", "JSArgumentList", "JSArgument",
  "JSIncrementOperator", "JSUnaryOperator", "JSObject", "JSArray",
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
      90,    91,    91,    91,    91,    92,    92,    93,    94,    95,
      95,    96,    96,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   103,   104,   105,   106,   107,   108,   109,   109,   110,
     110,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   116,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   123,   124,   124,   124,
     124,   124,   124,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   142,   142,   143,   144,   145,   145,
     145,   145,   146,   147,   148,   149,   150
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     5,
       2,     4,     2,     4,     3,     6,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     5,     3,
       3,     1,     1,     1,     1,     1,     2,     3,     4,     3,
       2,     1,     3,     1,     2,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       7,     9,     5,     1,     1,     5,     2,     1,     1,     2,
       1,     1,     2,     1,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     1,     2,     2,     2,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       3,     1,     3,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   156,     0,     0,     0,     2,     3,     5,     6,     7,
       0,   165,     0,   154,    10,    12,     1,     4,     0,     0,
     157,     0,     8,     0,     0,     0,     0,     0,    14,    21,
       0,    16,    20,    24,    19,    23,    35,    22,     0,   154,
     155,     0,    11,     0,     0,     0,     0,     0,     0,    13,
       0,    17,    25,    36,     0,     9,     0,     0,   162,   163,
     164,     0,   135,   139,     0,     0,     0,     0,    63,    64,
       0,   166,   136,     0,     0,     0,    31,    30,    50,    32,
      48,    52,    53,    54,    55,    56,    57,    58,    51,    70,
      78,    80,    81,    86,    88,    90,    92,    94,    99,   104,
     107,   113,   117,   119,   121,     0,    33,    34,   123,   124,
     158,   159,   160,   161,    26,     0,     0,    37,    18,    29,
      15,     0,   116,   123,    69,    74,    76,     0,   166,     0,
       0,    66,    68,    67,     0,   138,     0,    46,     0,   145,
     147,     0,   123,   161,     0,     0,   143,   141,     0,   144,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,   134,   114,     0,   166,     0,
     115,     0,    40,     0,    41,    43,    38,    28,     0,     0,
       0,     0,    73,   123,    71,     0,     0,    45,    47,   137,
     146,   153,   152,   148,     0,   125,     0,   140,    79,    82,
      85,    83,    84,     0,    89,    91,    93,   100,   102,   101,
     103,    95,    96,    97,    98,   105,   106,   108,   109,   110,
     111,   112,   118,   130,   132,     0,   127,   128,   131,   126,
       0,    27,     0,    39,    44,    75,    77,     0,   166,    72,
       0,     0,   151,   149,   150,   142,     0,   120,     0,   122,
      42,    59,     0,    62,    65,    87,   129,     0,   166,    60,
       0,     0,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    29,    30,    31,    32,
      33,    34,    77,    35,    36,    37,   116,   183,   184,    78,
     136,    79,    80,    81,    82,    83,    84,    85,    86,    87,
     131,    88,   191,   124,   125,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   235,   236,   237,   176,   105,   106,   107,   148,   138,
     139,   140,   141,    38,   123,    22,   109,   110,   111,   112,
     113,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -234
static const yytype_int16 yypact[] =
{
      21,  -234,    28,    19,    37,    21,  -234,  -234,  -234,  -234,
     -26,  -234,     3,  -234,   -17,   -21,  -234,  -234,    19,   312,
    -234,    19,    11,    19,     6,    17,    19,    19,  -234,  -234,
     174,  -234,  -234,    16,  -234,  -234,    45,  -234,   -43,   -26,
    -234,    19,  -234,    77,    19,   152,    19,    47,    47,  -234,
      77,  -234,  -234,  -234,   152,  -234,   278,    46,  -234,  -234,
    -234,    87,  -234,  -234,    19,    78,    79,    90,  -234,  -234,
      91,   253,  -234,   227,   253,   403,  -234,  -234,  -234,  -234,
      68,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
      95,  -234,    76,    92,   130,   132,   156,   382,  -234,    62,
     136,    66,    96,   100,    97,    87,  -234,  -234,   -26,  -234,
    -234,  -234,  -234,  -234,   104,     9,   111,  -234,  -234,  -234,
    -234,   152,  -234,  -234,   112,  -234,   178,   253,   253,   253,
     253,  -234,  -234,  -234,   315,  -234,   244,  -234,    44,  -234,
     117,   118,   120,   124,   123,    48,    65,  -234,   -42,  -234,
    -234,   253,   332,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,  -234,  -234,  -234,    87,   324,   253,
    -234,   152,  -234,    12,  -234,    19,  -234,  -234,    19,   253,
     128,   134,  -234,    19,  -234,   142,   143,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,    98,  -234,   138,  -234,  -234,  -234,
    -234,  -234,  -234,   146,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,  -234,  -234,  -234,   147,   153,  -234,  -234,  -234,
     144,  -234,    19,  -234,  -234,  -234,  -234,   315,   253,   112,
     315,   315,  -234,  -234,  -234,  -234,   253,  -234,   324,  -234,
    -234,   168,   137,  -234,  -234,  -234,  -234,   315,   253,  -234,
     161,   315,  -234
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -234,   221,  -234,  -234,     8,    -5,   -16,  -234,
    -234,  -234,   -45,  -234,  -234,  -234,   179,  -234,    -6,   122,
    -234,   -67,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -233,  -234,  -234,    52,    51,   -70,    36,   -55,  -234,    99,
      89,    94,   -39,  -234,   108,   180,  -234,   -44,  -234,  -234,
    -234,  -234,  -234,     4,  -234,  -234,   -64,    49,  -234,  -234,
     126,  -234,  -234,   109,     0,  -234,   186,  -234,  -234,  -234,
       5,  -112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -154
static const yytype_int16 yytable[] =
{
      10,   132,    13,    13,   144,    10,   137,    14,     9,   119,
      20,   147,     1,     9,    51,   262,   194,   122,    24,    39,
       1,    40,     1,    42,     1,    46,    47,    48,   206,    54,
      39,     1,    11,    21,   118,   270,   207,    16,    56,    18,
      51,    55,    19,    39,    57,   108,   114,     1,    11,    23,
      39,     1,    11,    76,   108,    21,    39,   190,   192,   195,
     196,   180,    76,    44,   126,     2,   239,   137,     1,   198,
     146,   167,   168,   142,    43,    39,   187,    41,   143,    21,
       1,   208,   242,   182,   152,     3,   243,    52,   210,    45,
       1,    11,    58,    59,    60,   153,   154,   209,   211,   212,
     213,     1,    11,    58,    59,    60,   174,   175,    61,   240,
      25,    12,    15,   199,   238,   185,    53,   135,   121,    26,
     115,   108,    25,   234,   221,   222,   223,   224,   193,    76,
      51,    26,    27,   232,   246,    50,   241,    62,   201,   150,
     253,    63,   255,   202,    27,   201,    39,   169,   170,   171,
     202,   127,   128,   172,   173,     1,    11,    58,    59,    60,
      74,    72,    61,   129,   130,   151,   145,   155,   156,   157,
     158,    74,   177,   178,   179,    75,   181,     1,   132,   134,
     261,   108,   188,   263,   264,   244,   189,   203,   126,    76,
     204,    62,  -153,   126,   238,    63,  -152,   205,   132,    64,
     269,   265,   247,   234,   272,   248,   145,    65,   268,    66,
      67,    68,    69,    70,    71,    72,   250,   251,   256,    25,
      73,   257,   259,   258,   267,    74,    17,   117,    26,    75,
       1,    11,    58,    59,    60,   271,   260,    61,   186,   245,
     252,    27,   185,    49,    50,   249,   215,     1,    11,    58,
      59,    60,   216,   254,    61,   214,     1,    11,    58,    59,
      60,   149,   266,    61,   200,     0,    62,   217,   218,   219,
     220,     0,     0,     0,    64,   225,   226,     0,     0,     0,
       0,     1,    65,    62,    66,    67,    68,    69,    70,    71,
      72,    64,    62,     0,     0,   134,   135,     0,     0,    65,
      74,    66,    67,    68,    69,    70,    71,    72,     0,     0,
       0,     0,   134,   197,     0,     1,    72,    74,     1,    11,
      58,    59,    60,    25,     0,    61,    74,     1,    11,    58,
      59,    60,    26,     0,    61,     1,    11,    58,    59,    60,
       0,     0,    61,     0,     0,    27,     0,   120,    50,   227,
     228,   229,   230,   231,    62,     0,     0,    25,     0,     0,
       0,     0,    64,    62,     0,     0,    26,     0,     0,   233,
      65,    62,    66,    67,    68,    69,    70,    71,    72,    27,
       0,    28,     0,   134,     0,     0,     0,    72,    74,     0,
       0,     0,   145,     0,     0,    72,     0,    74,     0,     0,
     145,     0,     0,     0,     0,    74,     1,    11,    58,    59,
      60,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,   145
};

static const yytype_int16 yycheck[] =
{
       0,    71,     2,     3,    74,     5,    73,     2,     0,    54,
       7,    75,     3,     5,    30,   248,   128,    61,    18,    19,
       3,    21,     3,    23,     3,    25,    26,    27,    70,    72,
      30,     3,     4,    76,    50,   268,    78,     0,    43,    65,
      56,    41,    68,    43,    44,    45,    46,     3,     4,    66,
      50,     3,     4,    45,    54,    76,    56,   127,   128,   129,
     130,   105,    54,    46,    64,    44,   178,   134,     3,   136,
      75,     9,    10,    73,    68,    75,   121,    66,    73,    76,
       3,   151,    70,    74,     8,    64,    74,    71,   152,    72,
       3,     4,     5,     6,     7,    19,    20,   152,   153,   154,
     155,     3,     4,     5,     6,     7,    40,    41,    10,   179,
      45,     2,     3,    69,   178,   115,    71,    69,    72,    54,
      73,   121,    45,   178,   163,   164,   165,   166,   128,   121,
     146,    54,    67,   177,   189,    70,   181,    39,   138,    71,
     204,    43,   206,   138,    67,   145,   146,    11,    12,    13,
     145,    73,    73,    17,    18,     3,     4,     5,     6,     7,
      73,    63,    10,    73,    73,    70,    68,    75,    38,    37,
      14,    73,    76,    73,    77,    77,    72,     3,   248,    68,
     247,   181,    70,   250,   251,   185,     8,    70,   188,   181,
      72,    39,    72,   193,   258,    43,    72,    74,   268,    47,
     267,   256,    74,   258,   271,    71,    68,    55,    71,    57,
      58,    59,    60,    61,    62,    63,    74,    74,    72,    45,
      68,    74,    78,    70,    56,    73,     5,    48,    54,    77,
       3,     4,     5,     6,     7,    74,   242,    10,   116,   188,
     204,    67,   242,    69,    70,   193,   157,     3,     4,     5,
       6,     7,   158,   204,    10,   156,     3,     4,     5,     6,
       7,    75,   258,    10,   138,    -1,    39,   159,   160,   161,
     162,    -1,    -1,    -1,    47,   167,   168,    -1,    -1,    -1,
      -1,     3,    55,    39,    57,    58,    59,    60,    61,    62,
      63,    47,    39,    -1,    -1,    68,    69,    -1,    -1,    55,
      73,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    69,    -1,     3,    63,    73,     3,     4,
       5,     6,     7,    45,    -1,    10,    73,     3,     4,     5,
       6,     7,    54,    -1,    10,     3,     4,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    67,    -1,    69,    70,   169,
     170,   171,   172,   173,    39,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    47,    39,    -1,    -1,    54,    -1,    -1,    45,
      55,    39,    57,    58,    59,    60,    61,    62,    63,    67,
      -1,    69,    -1,    68,    -1,    -1,    -1,    63,    73,    -1,
      -1,    -1,    68,    -1,    -1,    63,    -1,    73,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    73,     3,     4,     5,     6,
       7,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    44,    64,    80,    81,    82,    83,    84,    85,
     143,     4,   142,   143,   149,   142,     0,    82,    65,    68,
       7,    76,   144,    66,   143,    45,    54,    67,    69,    85,
      86,    87,    88,    89,    90,    92,    93,    94,   142,   143,
     143,    66,   143,    68,    46,    72,   143,   143,   143,    69,
      70,    87,    71,    71,    72,   143,    86,   143,     5,     6,
       7,    10,    39,    43,    47,    55,    57,    58,    59,    60,
      61,    62,    63,    68,    73,    77,    85,    91,    98,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   110,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   134,   135,   136,   143,   145,
     146,   147,   148,   149,   143,    73,    95,    95,    87,    91,
      69,    72,   126,   143,   112,   113,   143,    73,    73,    73,
      73,   109,   114,   150,    68,    69,    99,   100,   138,   139,
     140,   141,   143,   149,   114,    68,    86,   135,   137,   145,
      71,    70,     8,    19,    20,    75,    38,    37,    14,    29,
      30,    31,    32,    33,    34,    35,    36,     9,    10,    11,
      12,    13,    17,    18,    40,    41,   133,    76,    73,    77,
     126,    72,    74,    96,    97,   143,    98,    91,    70,     8,
     114,   111,   114,   143,   150,   114,   114,    69,   100,    69,
     139,   143,   149,    70,    72,    74,    70,    78,   114,   116,
     135,   116,   116,   116,   118,   119,   120,   123,   123,   123,
     123,   121,   121,   121,   121,   123,   123,   124,   124,   124,
     124,   124,   126,    45,   116,   130,   131,   132,   135,   150,
     114,    91,    70,    74,   143,   113,   116,    74,    71,   112,
      74,    74,   115,   135,   136,   135,    72,    74,    70,    78,
      97,   100,   109,   100,   100,   116,   132,    56,    71,   100,
     109,    74,   100
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
#line 193 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 211 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 229 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 245 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 263 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PragmaStatement", "TOKEN_PRAGMA QualifiedIdentifier");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 271 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 286 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("Item", "Identifier '{' '}'");

        QMLItem* pName = (yyvsp[(1) - (3)].Object);
        QMLComplexItem* pComplexItem = new QMLComplexItem(pName);

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 296 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 313 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContent");

        QMLItem* pOldItem = (yyvsp[(1) - (1)].Object);

        if (pOldItem != nullptr)
        {
            QMLComplexItem* pComplexItem = new QMLComplexItem();
            pComplexItem->contents().append(pOldItem);

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
#line 332 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pNewItem = (yyvsp[(2) - (2)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents().append(pNewItem);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 347 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContents", "ItemContents ',' ItemContent");

        QMLComplexItem* pComplexItem = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pNewItem = (yyvsp[(3) - (3)].Object);

        if (pComplexItem != nullptr && pNewItem != nullptr)
        {
            pComplexItem->contents().append(pNewItem);
        }

        (yyval.Object) = pComplexItem;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 364 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyAssignment");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 371 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "PropertyDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 378 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 385 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "JSFunction");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 392 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("ItemContent", "SignalDeclaration");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 401 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 408 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyDeclaration", "PropertyDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 417 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 434 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 452 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 471 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 482 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyAssignment", "TOKEN_PROPERTY ':' PropertyContent");

        QMLItem* pContent = (yyvsp[(3) - (3)].Object);
        QMLPropertyAssignment* pAssignment = new QMLPropertyAssignment(new QMLItem(QString(TOKEN_PROPERTY)), pContent);

        (yyval.Object) = pAssignment;
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 494 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "Item");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 501 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSStatement");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 508 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSObject");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 515 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("PropertyContent", "JSArray");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 524 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 531 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclaration", "SignalDeclarationNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 540 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("SignalDeclarationNoColon", "TOKEN_SIGNAL Identifier JSFunctionParameterList");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (3)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (3)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, nullptr);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 552 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunction", "TOKEN_FUNCTION Identifier JSFunctionParameterList JSStatementBlock");

        QMLItem* pName = dynamic_cast<QMLItem*>((yyvsp[(2) - (4)].Object));
        QMLComplexItem* pParameters = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));
        QMLComplexItem* pContent = dynamic_cast<QMLComplexItem*>((yyvsp[(4) - (4)].Object));

        (yyval.Object) = new QMLFunction(pName, pParameters, pContent);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 564 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' JSFunctionParameters ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 571 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameterList", "'(' ')'");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 580 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameter");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 587 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionParameters", "JSFunctionParameters ',' JSFunctionParameter");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 598 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 615 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 634 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementBlock", "'{' JSStatements '}'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 643 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatement");

        QMLItem* pStatement1 = (yyvsp[(1) - (1)].Object);
        QMLComplexItem* pComplex = new QMLComplexItem();

        pComplex->contents().append(pStatement1);

        (yyval.Object) = pComplex;
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 655 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatements", "JSStatements JSStatement");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (2)].Object));
        QMLItem* pStatement2 = (yyvsp[(2) - (2)].Object);

        if (pComplex != nullptr)
        {
            pComplex->contents().append(pStatement2);
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 672 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 679 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement", "JSStatementNoColon ';'");

        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 688 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatementBlock");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 695 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSVariablesOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 702 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_If");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 709 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_For");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 716 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatementNoColon", "JSStatement_While");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 723 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Break");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 730 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Continue");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 737 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_With");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 744 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSStatement_Break", "JSStatement_Return");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 753 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (5)].Object);
        QMLItem* pThen = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, nullptr);
    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 761 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pCondition = (yyvsp[(3) - (7)].Object);
        QMLItem* pThen = (yyvsp[(5) - (7)].Object);
        QMLItem* pElse = (yyvsp[(7) - (7)].Object);

        (yyval.Object) = new QMLIf(pCondition, pThen, pElse);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 772 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 784 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 796 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 803 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 810 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(3) - (5)].Object);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 817 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 824 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 829 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 836 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 841 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 848 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 853 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 858 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 865 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariable");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 872 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariables", "JSVariables ',' JSVariable");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 883 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 890 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSVariable", "Identifier TOKEN_ASSIGN JSAssignmentExpression");

        SAFE_DELETE((yyvsp[(3) - (3)].Object));

        (yyval.Object) = (yyvsp[(1) - (3)].Object);
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 901 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 908 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSExpression", "JSExpressionSingle ',' JSExpression");

        QMLComplexItem* pComplex = dynamic_cast<QMLComplexItem*>((yyvsp[(1) - (3)].Object));
        QMLItem* pExpression2 = (yyvsp[(2) - (3)].Object);

        if (pComplex != nullptr)
        {
            pComplex->contents().append(pExpression2);
        }

        (yyval.Object) = pComplex;
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 925 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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
#line 939 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 946 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 956 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ADD_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 966 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_SUB_ASSIGN JSAssignmentExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 976 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSAssignmentExpression", "JSConditionalExpression TOKEN_ASSIGN JSObject");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAssign);
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 988 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 995 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSConditionalExpression", "JSOrExpression '?' JSAssignmentExpression ':' JSAssignmentExpression");

        QMLItem* pCondition = (yyvsp[(1) - (5)].Object);
        QMLItem* pThen = (yyvsp[(3) - (5)].Object);
        QMLItem* pElse = (yyvsp[(5) - (5)].Object);

        (yyval.Object) = new QMLConditional(pCondition, pThen, pElse);
    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1008 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1015 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSOrExpression", "JSAndExpression TOKEN_LOGICAL_OR JSOrExpression");

        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicOr);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1027 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1032 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLogicAnd);
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1042 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1047 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAnd);
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1057 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1062 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEquals);
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1070 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boEqualsCheck);
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1078 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEquals);
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1086 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boNotEqualsCheck);
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1096 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1101 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLower);
    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1109 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boLowerOrEquals);
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1117 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreater);
    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1125 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boGreaterOrEquals);
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1135 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1140 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boAdd);
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1148 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boSub);
    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1158 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1163 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMul);
    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1171 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boDiv);
    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1179 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boMod);
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1187 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftLeft);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1195 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRight = (yyvsp[(3) - (3)].Object);

        (yyval.Object) = new QMLBinaryOperation(pLeft, pRight, QMLBinaryOperation::boShiftRight);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1205 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1210 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1215 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1220 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (2)].Object);
    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1227 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSMemberExpression", "JSFunctionCall");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1234 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 119:

/* Line 1455 of yacc.c  */
#line 1271 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSArrayAccessExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1278 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSFunctionCall", "JSArrayAccessExpression '(' JSArgumentListOpt ')'");

        QMLItem* pName = (yyvsp[(1) - (4)].Object);
        QMLComplexItem* pArguments = dynamic_cast<QMLComplexItem*>((yyvsp[(3) - (4)].Object));

        (yyval.Object) = new QMLFunctionCall(pName, pArguments);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1290 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSPrimaryExpression");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1297 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArrayAccessExpression", "JSPrimaryExpression '[' JSExpression ']'");

        (yyval.Object) = (yyvsp[(1) - (4)].Object);
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1306 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Identifier");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1313 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "Value");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1320 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSPrimaryExpression", "'(' JSExpression ')'");

        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1329 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "Empty");

        (yyval.Object) = nullptr;
    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1336 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        PARSER_TRACE("JSArgumentListOpt", "JSArgumentList");

        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1345 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 129:

/* Line 1455 of yacc.c  */
#line 1361 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 130:

/* Line 1455 of yacc.c  */
#line 1382 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1387 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1392 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1399 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1404 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1411 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1416 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1423 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1428 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1435 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLComplexItem();
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1440 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(2) - (3)].Object);
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1447 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1452 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (3)].Object);

        SAFE_DELETE((yyvsp[(3) - (3)].Object));
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1459 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1464 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1471 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1476 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 147:

/* Line 1455 of yacc.c  */
#line 1495 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1500 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (2)].Object);
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1507 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 150:

/* Line 1455 of yacc.c  */
#line 1526 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 151:

/* Line 1455 of yacc.c  */
#line 1545 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 152:

/* Line 1455 of yacc.c  */
#line 1566 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1571 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1578 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1583 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        QMLItem* pLeft = (yyvsp[(1) - (3)].Object);
        QMLItem* pRite = (yyvsp[(3) - (3)].Object);

        pLeft->setValue(pLeft->value().toString() + QString(".") + pRite->value().toString());

        SAFE_DELETE(pRite);

        (yyval.Object) = pLeft;
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1597 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 157:

/* Line 1455 of yacc.c  */
#line 1613 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(pContext->tokenValue());
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1620 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1625 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1630 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1635 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = (yyvsp[(1) - (1)].Object);
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1642 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Boolean)));
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1649 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = new QMLItem(QVariant((yyvsp[(1) - (1)].Integer)));
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1656 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) =  new QMLItem(QVariant((yyvsp[(1) - (1)].Real)));
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1663 "D:/Work/Projects/qt-plus/source/bison/QML.y"
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

  case 166:

/* Line 1455 of yacc.c  */
#line 1678 "D:/Work/Projects/qt-plus/source/bison/QML.y"
    {
        (yyval.Object) = nullptr;
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3855 "D:/Work/Projects/qt-plus/source/cpp/QMLTree/QMLGrammarParser.cpp"
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
#line 1682 "D:/Work/Projects/qt-plus/source/bison/QML.y"


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

