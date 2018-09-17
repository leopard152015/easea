/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "compiler/EaseaParse.y" /* yacc.c:339  */

/****************************************************************************
EaseaLex.y
Parser for the EASEA language (EAsy Specification for Evolutionary Algorithms)

Pierre COLLET (Pierre.Collet@polytechnique.fr)
Ecole Polytechnique
Centre de Math�matiques Appliqu�es
91128 Palaiseau cedex
****************************************************************************/

#include "Easea.h"
#include "debug.h"
#include "EaseaYTools.h"
#include "EaseaParse.hpp"

#define YYEXIT_FAILURE	1
#define YYEXIT_SUCCESS	0



// Globals     
CSymbol *pCURRENT_CLASS;
CSymbol *pCURRENT_TYPE;
CSymbol *pGENOME;
CSymbol* pCLASSES[128];
char sRAW_PROJECT_NAME[1000];
int nClasses_nb = 0;
char sPROJECT_NAME[1000];
char sLOWER_CASE_PROJECT_NAME[1000];
char sEZ_FILE_NAME[1000];
char sEO_DIR[1000];
char sEZ_PATH[1000];
char sTPL_DIR[1000];
int TARGET,TARGET_FLAVOR;
int OPERATING_SYSTEM;
int nWARNINGS=0;
int nERRORS=0;
char sSELECTOR[50], sSELECTOR_OPERATOR[50];
float fSELECT_PRM=0.0;
char sRED_PAR[50], sRED_PAR_OPERATOR[50];
float fRED_PAR_PRM=0.0;//[50] = {0};
char sRED_OFF[50], sRED_OFF_OPERATOR[50];
float fRED_OFF_PRM;//[50] = {0};
char sRED_FINAL[50], sRED_FINAL_OPERATOR[50];
float fRED_FINAL_PRM=0.0;//[50];
int nMINIMISE=2;
int nELITE=0;
bool bELITISM=0;
bool bVERBOSE=0;
bool bLINE_NUM_EZ_FILE=1;
bool bPRINT_STATS=1;
bool bPLOT_STATS=0;
bool bGENERATE_CSV_FILE=0, bGENERATE_R_SCRIPT=0, bGENERATE_GNUPLOT_SCRIPT=0;
bool bSAVE_POPULATION=0, bSTART_FROM_FILE=0;
bool bBALDWINISM=0; //memetic
bool bREMOTE_ISLAND_MODEL=0; //remote island model
float fMIGRATION_PROBABILITY=0.0;
char sIP_FILE[128]; //remote island model
int nPOP_SIZE, nOFF_SIZE, nARCH_SIZE;
float fSURV_PAR_SIZE=-1.0, fSURV_OFF_SIZE=-1.0;
char *nGENOME_NAME;
int nPROBLEM_DIM;
int nNB_GEN=0;
int nNB_OPT_IT=0;
int nTIME_LIMIT=0;
int nSERVER_PORT=0;
float fMUT_PROB;
float fXOVER_PROB;
FILE *fpOutputFile, *fpTemplateFile, *fpGenomeFile;//, *fpExplodedGenomeFile;

CSymbolTable SymbolTable;    // the symbol table


 unsigned iMAX_INIT_TREE_D,iMIN_INIT_TREE_D,iMAX_TREE_D,iNB_GPU,iPRG_BUF_SIZE,iMAX_TREE_DEPTH,iMAX_XOVER_DEPTH,iNO_FITNESS_CASES;

extern int yylex();
extern char * yytext;

void yyerror(const char * s){
  printf("%s\nSyntax Error at line : %d (on text : %s)\nFor more details during the EASEA compiling, use the \"-v\" option\n",
	 s,yylineno,yytext);
}


#line 152 "compiler/EaseaParse.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "EaseaParse.hpp".  */
#ifndef YY_YY_COMPILER_EASEAPARSE_HPP_INCLUDED
# define YY_YY_COMPILER_EASEAPARSE_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UMINUS = 258,
    CLASSES = 259,
    GENOME = 260,
    USER_CTOR = 261,
    USER_XOVER = 262,
    USER_MUTATOR = 263,
    USER_EVALUATOR = 264,
    USER_OPTIMISER = 265,
    MAKEFILE_OPTION = 266,
    END_OF_FUNCTION = 267,
    END_METHODS = 268,
    IDENTIFIER = 269,
    IDENTIFIER2 = 270,
    BOOL = 271,
    INT = 272,
    DOUBLE = 273,
    FLOAT = 274,
    GPNODE = 275,
    CHAR = 276,
    POINTER = 277,
    NUMBER = 278,
    NUMBER2 = 279,
    METHODS = 280,
    STATIC = 281,
    NB_GEN = 282,
    NB_OPT_IT = 283,
    BALDWINISM = 284,
    MUT_PROB = 285,
    XOVER_PROB = 286,
    POP_SIZE = 287,
    ARCH_SIZE = 288,
    SELECTOR = 289,
    RED_PAR = 290,
    RED_OFF = 291,
    RED_FINAL = 292,
    OFFSPRING = 293,
    SURVPAR = 294,
    SURVOFF = 295,
    MINIMAXI = 296,
    ELITISM = 297,
    ELITE = 298,
    REMOTE_ISLAND_MODEL = 299,
    IP_FILE = 300,
    MIGRATION_PROBABILITY = 301,
    SERVER_PORT = 302,
    PRINT_STATS = 303,
    PLOT_STATS = 304,
    GENERATE_CSV_FILE = 305,
    GENERATE_GNUPLOT_SCRIPT = 306,
    GENERATE_R_SCRIPT = 307,
    SAVE_POPULATION = 308,
    START_FROM_FILE = 309,
    TIME_LIMIT = 310,
    MAX_INIT_TREE_D = 311,
    MIN_INIT_TREE_D = 312,
    MAX_XOVER_DEPTH = 313,
    MAX_MUTAT_DEPTH = 314,
    MAX_TREE_D = 315,
    NB_GPU = 316,
    PRG_BUF_SIZE = 317,
    NO_FITNESS_CASES = 318,
    TEMPLATE_END = 319
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 93 "compiler/EaseaParse.y" /* yacc.c:355  */

  CSymbol* pSymbol;
  double dValue;
  int ObjectQualifier;
  int nValue;
  char *szString;

#line 265 "compiler/EaseaParse.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);
/* "%code provides" blocks.  */
#line 87 "compiler/EaseaParse.y" /* yacc.c:355  */

// forward references
class CSymbol;
#line 180 "compiler/EaseaParse.y" /* yacc.c:355  */

#include "EaseaSym.h"
#include "EaseaLex.h"

  int  CEASEAParser_create();
  
  double  CEASEAParser_assign(CSymbol* pIdentifier, double dValue);
  double  CEASEAParser_divide(double dDividend, double dDivisor);
  CSymbol*  CEASEAParser_insert();

  //virtual void yysyntaxerror();


#line 296 "compiler/EaseaParse.cpp" /* yacc.c:355  */

#endif /* !YY_YY_COMPILER_EASEAPARSE_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 302 "compiler/EaseaParse.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    78,     2,     2,
      80,    81,     6,     4,    74,     5,    79,     7,    75,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    72,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,    71,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   196,   196,   199,   199,   204,   204,   212,   212,   215,
     220,   221,   225,   225,   239,   240,   245,   245,   246,   246,
     247,   251,   259,   260,   264,   265,   269,   270,   274,   275,
     276,   277,   278,   279,   280,   284,   296,   297,   305,   317,
     327,   337,   350,   364,   387,   388,   392,   405,   405,   427,
     428,   432,   436,   440,   441,   445,   445,   449,   449,   453,
     453,   457,   457,   461,   461,   465,   468,   472,   473,   477,
     479,   481,   483,   485,   487,   489,   491,   501,   511,   521,
     531,   541,   549,   558,   567,   568,   569,   570,   571,   572,
     573,   582,   585,   588,   595,   603,   610,   615,   618,   621,
     628,   635,   642,   649,   656,   663,   670,   671,   672,   673,
     674,   677,   681,   688,   689,   690,   691,   695,   696,   697,
     698
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "CLASSES", "GENOME", "USER_CTOR", "USER_XOVER", "USER_MUTATOR",
  "USER_EVALUATOR", "USER_OPTIMISER", "MAKEFILE_OPTION", "END_OF_FUNCTION",
  "END_METHODS", "IDENTIFIER", "IDENTIFIER2", "BOOL", "INT", "DOUBLE",
  "FLOAT", "GPNODE", "CHAR", "POINTER", "NUMBER", "NUMBER2", "METHODS",
  "STATIC", "NB_GEN", "NB_OPT_IT", "BALDWINISM", "MUT_PROB", "XOVER_PROB",
  "POP_SIZE", "ARCH_SIZE", "SELECTOR", "RED_PAR", "RED_OFF", "RED_FINAL",
  "OFFSPRING", "SURVPAR", "SURVOFF", "MINIMAXI", "ELITISM", "ELITE",
  "REMOTE_ISLAND_MODEL", "IP_FILE", "MIGRATION_PROBABILITY", "SERVER_PORT",
  "PRINT_STATS", "PLOT_STATS", "GENERATE_CSV_FILE",
  "GENERATE_GNUPLOT_SCRIPT", "GENERATE_R_SCRIPT", "SAVE_POPULATION",
  "START_FROM_FILE", "TIME_LIMIT", "MAX_INIT_TREE_D", "MIN_INIT_TREE_D",
  "MAX_XOVER_DEPTH", "MAX_MUTAT_DEPTH", "MAX_TREE_D", "NB_GPU",
  "PRG_BUF_SIZE", "NO_FITNESS_CASES", "TEMPLATE_END", "'{'", "'}'", "';'",
  "':'", "','", "'0'", "'['", "']'", "'%'", "'.'", "'('", "')'", "$accept",
  "EASEA", "GenomeAnalysis", "$@1", "$@2", "ClassDeclarationsSection",
  "$@3", "ClassDeclarations", "ClassDeclaration", "$@4",
  "VariablesDeclarations", "VariablesDeclaration", "$@5", "$@6",
  "MethodsDeclaration", "Qualifier", "BaseObjects", "UserObjects",
  "BaseType", "UserType", "Objects", "Object", "BaseConstructorParameters",
  "BaseConstructorParameter", "GenomeDeclarationSection", "$@7",
  "UserConstructorParameters", "UserConstructorParameter", "Symbol",
  "StandardFunctionsAnalysis", "StandardFunctionAnalysis", "$@8", "$@9",
  "$@10", "$@11", "$@12", "RunParameters", "Parameter", "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    61,    43,    45,    42,    47,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     123,   125,    59,    58,    44,    48,    91,    93,    37,    46,
      40,    41
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,     2,    13,    17,    29,    33,    35,    45,    28,    57,
      59,    62,    47,    54,    55,    99,   100,   127,   137,   152,
     144,   145,   155,   156,   157,   158,   159,   160,   161,   153,
     154,   162,   163,   165,   166,   167,   184,    56,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,   168,   169,   170,   171,
     107,   108,   109,  -144,  -144,   110,  -144,   111,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,   179,  -144,   124,   191,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   182,
     185,   133,  -144,  -144,   151,  -144,  -144,   185,  -144,  -144,
       9,   151,  -144,  -144,  -144,  -144,  -144,   188,   151,  -144,
    -144,   136,   189,  -144,   -10,  -144,  -144,    30,   151,   192,
     193,   194,   195,   196,  -144,  -144,     9,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,  -144,  -144,  -144,    -8,    11,    11,  -144,    19,
     185,  -144,   -39,  -144,   132,  -144,    -4,   185,   138,  -144,
    -144,   187,    11,     0,  -144,   185,  -144,     0,  -144,   -22,
    -144,  -144,     0,   213,  -144,     0,     4,    -1,  -144,  -144,
       8,  -144,  -144,  -144,     0,    -3,     0,     0,     0,     0,
    -144,  -144,  -144,  -144,   164,  -144,    66,    66,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    69,
      70,    94,    72,    73,    74,    75,    76,    78,    80,    82,
      84,    86,    88,    90,    93,    91,    95,     0,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    71,   106,   107,
     108,   109,   110,   111,     1,     7,    47,     0,     0,     5,
      68,    77,    79,    81,    83,    85,    87,    89,    92,     0,
       0,     0,     2,     3,     0,    96,    52,     8,    10,    12,
      23,     0,    55,    57,    59,    61,    63,    66,     6,    53,
      11,     0,     0,    22,    23,    14,    20,     0,     4,     0,
       0,     0,     0,     0,    65,    54,    23,    21,    48,    15,
      28,    29,    30,    31,    34,    32,    33,    16,    18,    35,
      56,    58,    60,    62,    64,    23,     0,     0,    13,     0,
       0,    17,     0,    36,    38,    19,     0,     0,    39,    40,
      24,     0,     0,     0,    26,     0,    41,     0,    46,     0,
      44,    37,     0,   120,   119,     0,     0,     0,    49,    51,
       0,    25,    45,   118,     0,     0,     0,     0,     0,     0,
      42,    27,    50,    43,   112,   117,   113,   114,   115,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,   120,  -144,
      92,   -98,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
      72,    58,  -144,    52,   146,  -144,  -144,    46,   -90,   121,
     -82,  -144,  -144,  -144,  -144,  -144,  -144,   190,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    36,    77,   101,    94,    78,    90,    97,    98,   111,
     114,   115,   146,   147,   116,   117,   151,   155,   137,   138,
     152,   153,   169,   170,    79,    91,   177,   178,   154,   108,
     109,   119,   120,   121,   122,   123,    37,    38,   176
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,   186,   187,   188,   189,   172,   168,    99,   186,   187,
     188,   189,   186,   187,   188,   189,   129,   149,    96,   173,
     112,   113,   112,   113,   180,   157,   125,   139,   174,   183,
      96,    39,   185,   160,   161,   162,   125,    41,    96,   112,
     113,   194,    40,   196,   197,   198,   199,   129,    46,    96,
     181,   130,   131,   132,   133,   134,   135,   136,    42,   158,
     159,   128,    43,   148,    44,    75,    76,   166,   164,   165,
     162,   191,   188,   189,    45,   179,    50,    47,   195,    48,
     175,   190,    49,    51,    52,   193,   150,   179,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    53,
      54,    32,    33,    34,    35,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    55,    56,    32,    33,
      34,    35,   102,   103,   104,   105,   106,   107,   186,   187,
     188,   189,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    74,    85,    86,    87,    88,    -9,
      89,    69,    70,    92,    71,    72,    73,    81,    82,    83,
      84,    76,    95,   100,    96,   124,   126,   127,   163,   140,
     141,   142,   143,   144,   167,   168,   184,   110,   145,   156,
     171,   182,   118,   192,    93,     0,     0,    80
};

static const yytype_int16 yycheck[] =
{
      90,     4,     5,     6,     7,     5,    28,    97,     4,     5,
       6,     7,     4,     5,     6,     7,   114,     6,    19,    19,
      30,    31,    30,    31,   167,     6,   108,   117,    28,   172,
      19,    29,   175,    72,    73,    74,   118,    20,    19,    30,
      31,   184,    29,   186,   187,   188,   189,   145,    20,    19,
      72,    21,    22,    23,    24,    25,    26,    27,    29,   149,
     150,    71,    29,    71,    29,     9,    10,   157,    72,    73,
      74,    72,     6,     7,    29,   165,    29,    20,    81,    20,
      80,    77,    20,    29,    29,    77,    75,   177,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    20,
      20,    65,    66,    67,    68,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    29,    20,    65,    66,
      67,    68,    11,    12,    13,    14,    15,    16,     4,     5,
       6,     7,    20,    29,    29,    20,    20,    20,    20,    20,
      20,    20,    29,    29,     0,    78,    78,    78,    78,    10,
      79,    29,    29,    69,    29,    29,    29,    29,    29,    29,
      29,    10,    20,    70,    19,    17,    70,    18,    76,    17,
      17,    17,    17,    17,    76,    28,     3,    97,   126,   147,
     162,   169,   101,   177,    78,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    65,    66,    67,    68,    83,   118,   119,    29,
      29,    20,    29,    29,    29,    29,    20,    20,    20,    20,
      29,    29,    29,    20,    20,    29,    20,    20,    29,    29,
      20,    20,    20,    20,    20,    20,    20,    29,    29,    29,
      29,    29,    29,    29,     0,     9,    10,    84,    87,   106,
     119,    29,    29,    29,    29,    78,    78,    78,    78,    79,
      88,   107,    69,   106,    86,    20,    19,    89,    90,   110,
      70,    85,    11,    12,    13,    14,    15,    16,   111,   112,
      90,    91,    30,    31,    92,    93,    96,    97,   111,   113,
     114,   115,   116,   117,    17,   112,    70,    18,    71,    93,
      21,    22,    23,    24,    25,    26,    27,   100,   101,   110,
      17,    17,    17,    17,    17,    92,    94,    95,    71,     6,
      75,    98,   102,   103,   110,    99,   102,     6,   110,   110,
      72,    73,    74,    76,    72,    73,   110,    76,    28,   104,
     105,   103,     5,    19,    28,    80,   120,   108,   109,   110,
     120,    72,   105,   120,     3,   120,     4,     5,     6,     7,
      77,    72,   109,    77,   120,    81,   120,   120,   120,   120
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    85,    84,    86,    84,    88,    87,    87,
      89,    89,    91,    90,    92,    92,    94,    93,    95,    93,
      93,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   100,   101,   102,   102,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   107,   106,   108,
     108,   109,   110,   111,   111,   113,   112,   114,   112,   115,
     112,   116,   112,   117,   112,   112,   112,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     4,     0,     3,     0,     3,     1,
       1,     2,     0,     5,     1,     2,     0,     4,     0,     4,
       1,     2,     1,     0,     2,     4,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       2,     3,     4,     5,     1,     2,     1,     0,     5,     1,
       2,     1,     1,     1,     2,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     2,     3,
       2,     2,     3,     2,     2,     2,     4,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 196 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {return 0;}
#line 1546 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 199 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        if (bVERBOSE){ printf("                    _______________________________________\n");
        printf ("\nGeneration of the C++ source file for %s.\n\n",sPROJECT_NAME);}
      }
#line 1555 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 204 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        if (bVERBOSE) printf("                    _______________________________________\n");
        if (bVERBOSE) printf ("\nGeneration of the C++ source file for %s.\n\n",sPROJECT_NAME);
      }
#line 1564 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 212 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
    if (bVERBOSE) printf("Declaration of user classes :\n\n");}
#line 1571 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 215 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (bVERBOSE) printf("No user class declaration found other than GenomeClass.\n");}
#line 1578 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 225 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      pCURRENT_CLASS=SymbolTable.insert((yyvsp[0].pSymbol));  
      pCURRENT_CLASS->pSymbolList=new CLList<CSymbol *>();
      (yyvsp[0].pSymbol)->ObjectType=oUserClass;
      //DEBUG_PRT("Yacc Symbol declaration %s %d",$1->sName,$1->nSize);
      pCLASSES[nClasses_nb++] = (yyvsp[0].pSymbol);
    }
#line 1590 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 232 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (bVERBOSE) printf("Class %s declared for %d bytes.\n\n",(yyvsp[-4].pSymbol)->sName,(yyvsp[-4].pSymbol)->nSize);
      //DEBUG_PRT("Yacc variable declaration %s %d",$1->sName,$1->nSize);
    }
#line 1599 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 245 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {pCURRENT_TYPE=(yyvsp[0].pSymbol); pCURRENT_TYPE->ObjectQualifier=(yyvsp[-1].ObjectQualifier);}
#line 1605 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 245 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1611 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {pCURRENT_TYPE=(yyvsp[0].pSymbol); pCURRENT_TYPE->ObjectQualifier=(yyvsp[-1].ObjectQualifier);}
#line 1617 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 246 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1623 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
    pCURRENT_CLASS->sString = new char[strlen((yyvsp[0].szString)) + 1];
    strcpy(pCURRENT_CLASS->sString, (yyvsp[0].szString));      
    if (bVERBOSE) printf("\n    The following methods have been declared:\n\n%s\n\n",pCURRENT_CLASS->sString);
    }
#line 1633 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 259 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {(yyval.ObjectQualifier)=1;}
#line 1639 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 260 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {(yyval.ObjectQualifier)=0;}
#line 1645 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 265 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1651 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 269 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1657 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 270 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1663 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 284 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {  
      CSymbol *pSym=SymbolTable.find((yyvsp[0].pSymbol)->sName);
      if (pSym==NULL) {
        fprintf(stderr,"\n%s - Error line %d: Class \"%s\" was not defined.\n",sEZ_FILE_NAME,yylineno,(yyvsp[0].pSymbol)->sName);
        fprintf(stderr,"Only base types (bool, int, float, double, char) or new user classes defined\nwithin the \"User classes\" sections are allowed.\n");
        exit(1);
      }       
      else (yyval.pSymbol)=pSym;
    }
#line 1677 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 305 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
//      CSymbol *pSym;
//      pSym=$1;
        (yyvsp[0].pSymbol)->nSize=pCURRENT_TYPE->nSize;
        (yyvsp[0].pSymbol)->pClass=pCURRENT_CLASS;
        (yyvsp[0].pSymbol)->pType=pCURRENT_TYPE;
        (yyvsp[0].pSymbol)->ObjectType=oObject;
        (yyvsp[0].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
        pCURRENT_CLASS->nSize+=(yyvsp[0].pSymbol)->nSize;
        pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[0].pSymbol)));
        if (bVERBOSE) printf("    %s variable declared (%d bytes)\n",(yyvsp[0].pSymbol)->sName,(yyvsp[0].pSymbol)->nSize);
    }
#line 1694 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 317 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      (yyvsp[0].pSymbol)->nSize=sizeof (char *);
      (yyvsp[0].pSymbol)->pClass=pCURRENT_CLASS;
      (yyvsp[0].pSymbol)->pType=pCURRENT_TYPE;
      (yyvsp[0].pSymbol)->ObjectType=oPointer;
      (yyvsp[0].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
      pCURRENT_CLASS->nSize+=(yyvsp[0].pSymbol)->nSize;
      pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[0].pSymbol)));
      if (bVERBOSE) printf("    %s pointer declared (%d bytes)\n",(yyvsp[0].pSymbol)->sName,(yyvsp[0].pSymbol)->nSize);
    }
#line 1709 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 327 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      (yyvsp[0].pSymbol)->nSize=sizeof (char *);
      (yyvsp[0].pSymbol)->pClass=pCURRENT_CLASS;
      (yyvsp[0].pSymbol)->pType=pCURRENT_TYPE;
      (yyvsp[0].pSymbol)->ObjectType=oPointer;
      (yyvsp[0].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
      pCURRENT_CLASS->nSize+=(yyvsp[0].pSymbol)->nSize;
      pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[0].pSymbol)));
      if (bVERBOSE) printf("    %s NULL pointer declared (%d bytes)\n",(yyvsp[0].pSymbol)->sName,(yyvsp[0].pSymbol)->nSize);
    }
#line 1724 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 337 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      (yyvsp[0].pSymbol)->nSize=sizeof (char *);
      (yyvsp[0].pSymbol)->pClass=pCURRENT_CLASS;
      (yyvsp[0].pSymbol)->pType=pCURRENT_TYPE;
      (yyvsp[0].pSymbol)->ObjectType=oPointer;
      (yyvsp[0].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
      pCURRENT_CLASS->nSize+=(yyvsp[0].pSymbol)->nSize;
      pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[0].pSymbol)));
      if (bVERBOSE) printf("    %s pointer of pointer declared (%d bytes)\n",(yyvsp[0].pSymbol)->sName,(yyvsp[0].pSymbol)->nSize);
      fprintf(stderr,"Pointer of pointer doesn't work properly yet\n");
      exit(-1);
    }
#line 1741 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 350 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if((TARGET_FLAVOR==CMAES) && nPROBLEM_DIM==0 && strcmp(pCURRENT_CLASS->sName,"Genome")==0) { nGENOME_NAME=(yyvsp[-3].pSymbol)->sName; nPROBLEM_DIM=(int)(yyvsp[-1].dValue);}

      //printf("DEBUG : size of $3 %d nSize %d\n",(int)$3,pCURRENT_TYPE->nSize);

      (yyvsp[-3].pSymbol)->nSize=pCURRENT_TYPE->nSize*(int)(yyvsp[-1].dValue);
      (yyvsp[-3].pSymbol)->pClass=pCURRENT_CLASS;
      (yyvsp[-3].pSymbol)->pType=pCURRENT_TYPE;
      (yyvsp[-3].pSymbol)->ObjectType=oArray;
      (yyvsp[-3].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
      pCURRENT_CLASS->nSize+=(yyvsp[-3].pSymbol)->nSize;
      pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[-3].pSymbol)));
      if (bVERBOSE) printf("    %s array declared (%d bytes)\n",(yyvsp[-3].pSymbol)->sName,(yyvsp[-3].pSymbol)->nSize);
    }
#line 1760 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 364 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {

    // this is for support of pointer array. This should be done in a more generic way in a later version
      if((TARGET_FLAVOR==CMAES) && nPROBLEM_DIM==0 && strcmp(pCURRENT_CLASS->sName,"Genome")==0) { 
	nGENOME_NAME=(yyvsp[-3].pSymbol)->sName; nPROBLEM_DIM=(int)(yyvsp[-1].dValue);
      }
      
      //pCURRENT_CLASS->nSize

      (yyvsp[-3].pSymbol)->nSize=sizeof(char*)*(int)(yyvsp[-1].dValue);
      (yyvsp[-3].pSymbol)->pClass=pCURRENT_CLASS;
      (yyvsp[-3].pSymbol)->pType=pCURRENT_TYPE;
      (yyvsp[-3].pSymbol)->ObjectType=oArrayPointer;
      (yyvsp[-3].pSymbol)->ObjectQualifier=pCURRENT_TYPE->ObjectQualifier;
      pCURRENT_CLASS->nSize+=(yyvsp[-3].pSymbol)->nSize;
      pCURRENT_CLASS->pSymbolList->addFirst((CSymbol *)((yyvsp[-3].pSymbol)));

      printf("DEBUG : size of $4 %d nSize %d\n",(int)(yyvsp[-1].dValue),pCURRENT_TYPE->nSize);
      if (bVERBOSE) printf("    %s array of pointers declared (%d bytes)\n",(yyvsp[-3].pSymbol)->sName,(yyvsp[-3].pSymbol)->nSize);
    }
#line 1785 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 392 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1791 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 405 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
    ////DEBUG_PRT("Yacc genome decl %s",$1.pSymbol->sName);
      if (bVERBOSE) printf ("\nGenome declaration analysis :\n\n");
      pGENOME=new CSymbol("Genome");
      pCURRENT_CLASS=SymbolTable.insert(pGENOME);  
      pGENOME->pSymbolList=new CLList<CSymbol *>();
      pGENOME->ObjectType=oUserClass;
      pGENOME->ObjectQualifier=0;
      pGENOME->sString=NULL;
    }
#line 1806 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 415 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1812 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 432 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1818 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 436 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {(yyval.pSymbol)=(yyvsp[0].pSymbol);}
#line 1824 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 445 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {         
      if (bVERBOSE) printf("Inserting genome initialiser (taken from .ez file).\n");
    }
#line 1832 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 448 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1838 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 449 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (bVERBOSE) printf("Inserting user genome crossover (taken from .ez file).\n");
    }
#line 1846 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 452 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1852 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 453 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (bVERBOSE) printf("Inserting user genome mutator (taken from .ez file).\n");
    }
#line 1860 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 456 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1866 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 457 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { 
      if (bVERBOSE) printf("Inserting user genome evaluator (taken from .ez file).\n");
    }
#line 1874 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 460 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1880 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 461 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { 
      if (bVERBOSE) printf("Inserting user genome optimiser (taken from .ez file).\n");
    }
#line 1888 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 464 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1894 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 465 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
     //DEBUG_PRT("User makefile options have been reduced");
     }
#line 1902 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 468 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {}
#line 1908 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 478 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nNB_GEN=(int)(yyvsp[0].dValue);}
#line 1914 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 480 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nNB_OPT_IT=(int)(yyvsp[0].dValue);}
#line 1920 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 482 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nTIME_LIMIT=(int)(yyvsp[0].dValue);}
#line 1926 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 484 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fMUT_PROB=(float)(yyvsp[0].dValue);}
#line 1932 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 486 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fXOVER_PROB=(float)(yyvsp[0].dValue);}
#line 1938 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 488 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nPOP_SIZE=(int)(yyvsp[0].dValue);}
#line 1944 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 490 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nARCH_SIZE=(int)(yyvsp[0].dValue);}
#line 1950 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 491 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      strcpy(sSELECTOR, (yyvsp[0].pSymbol)->sName);
      strcpy(sSELECTOR_OPERATOR, (yyvsp[0].pSymbol)->sName);
      switch (TARGET) {
      case CUDA:
      case STD:
	pickupSTDSelector(sSELECTOR,&fSELECT_PRM,sEZ_FILE_NAME);
	break;
      }
    }
#line 1965 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 501 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      sprintf(sSELECTOR, (yyvsp[-1].pSymbol)->sName);   
      sprintf(sSELECTOR_OPERATOR, (yyvsp[-1].pSymbol)->sName);   
      switch (TARGET) {
      case CUDA:
      case STD:
	pickupSTDSelectorArgument(sSELECTOR,&fSELECT_PRM,sEZ_FILE_NAME,(float)(yyvsp[0].dValue));
	break;
      }
    }
#line 1980 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 511 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sRED_PAR, (yyvsp[0].pSymbol)->sName);
	sprintf(sRED_PAR_OPERATOR, (yyvsp[0].pSymbol)->sName);
        switch (TARGET) {
	case CUDA:
	case STD:
	  pickupSTDSelector(sRED_PAR,&fRED_PAR_PRM,sEZ_FILE_NAME);
	  break;
	}
    }
#line 1995 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 521 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sRED_PAR, (yyvsp[-1].pSymbol)->sName);
	sprintf(sRED_PAR_OPERATOR, (yyvsp[-1].pSymbol)->sName);
        switch (TARGET) {
	case CUDA :
	case STD:
	  pickupSTDSelectorArgument(sRED_PAR,&fRED_PAR_PRM,sEZ_FILE_NAME,(float)(yyvsp[0].dValue));
	  break;
	}
    }
#line 2010 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 531 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
	sprintf(sRED_OFF, (yyvsp[0].pSymbol)->sName);
	sprintf(sRED_OFF_OPERATOR, (yyvsp[0].pSymbol)->sName);
      switch (TARGET) {
      case STD:
      case CUDA:
	pickupSTDSelector(sRED_OFF,&fRED_OFF_PRM,sEZ_FILE_NAME);
	break;
      }
    }
#line 2025 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 541 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sRED_OFF, (yyvsp[-1].pSymbol)->sName);
	sprintf(sRED_OFF_OPERATOR, (yyvsp[-1].pSymbol)->sName);
        switch (TARGET) {
	case STD:
	case CUDA:
	  pickupSTDSelectorArgument(sRED_OFF,&fRED_OFF_PRM,sEZ_FILE_NAME,(yyvsp[0].dValue));
       }}
#line 2038 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 549 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sRED_FINAL, (yyvsp[0].pSymbol)->sName);
        sprintf(sRED_FINAL_OPERATOR, (yyvsp[0].pSymbol)->sName);
        switch (TARGET) {
	case CUDA:
	case STD:
	  pickupSTDSelector(sRED_FINAL,&fRED_FINAL_PRM,sEZ_FILE_NAME);
	  break;
       }}
#line 2052 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 558 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sRED_FINAL, (yyvsp[-1].pSymbol)->sName);
        sprintf(sRED_FINAL_OPERATOR, (yyvsp[-1].pSymbol)->sName);
        switch (TARGET) {
	case CUDA :
	case STD:
	  pickupSTDSelectorArgument(sRED_FINAL,&fRED_FINAL_PRM,sEZ_FILE_NAME,(yyvsp[0].dValue));
	  break;
	}}
#line 2066 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 567 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nOFF_SIZE=(int)(yyvsp[0].dValue);}
#line 2072 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 568 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {nOFF_SIZE=(int)((yyvsp[-1].dValue)*nPOP_SIZE/100);}
#line 2078 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 569 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fSURV_PAR_SIZE=(float)(yyvsp[0].dValue);}
#line 2084 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 570 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fSURV_PAR_SIZE=(float)((yyvsp[-1].dValue)/100);}
#line 2090 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 571 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fSURV_OFF_SIZE=(float)(yyvsp[0].dValue);}
#line 2096 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 572 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {fSURV_OFF_SIZE=(float)((yyvsp[-1].dValue)/100);}
#line 2102 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 573 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if ((!mystricmp((yyvsp[0].pSymbol)->sName,"Maximise")) || (!mystricmp((yyvsp[0].pSymbol)->sName,"Maximize"))) nMINIMISE=0;
      else if ((!mystricmp((yyvsp[0].pSymbol)->sName,"Minimise")) || (!mystricmp((yyvsp[0].pSymbol)->sName,"Minimize"))) nMINIMISE=1;
      else {
         fprintf(stderr,"\n%s - Error line %d: The evaluator goal default parameter can only take\n",sEZ_FILE_NAME,yylineno);
         fprintf(stderr,"two values : maximi[sz]e or minimi[sz]e.\n",sEZ_FILE_NAME,yylineno);
         exit(1);
       }
      }
#line 2116 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 582 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        nELITE=(int)(yyvsp[0].dValue);
        }
#line 2124 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 585 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        nELITE=(int)(yyvsp[-1].dValue)*nPOP_SIZE/100;
        }
#line 2132 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 588 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"Weak")) bELITISM=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"Strong")) bELITISM=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Elitism must be \"Strong\" or \"Weak\".\nDefault value \"Strong\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bELITISM=1;
       }}
#line 2144 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 595 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bBALDWINISM=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bBALDWINISM=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Baldwinism must be \"True\" or \"False\".\nDefault value \"True\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bBALDWINISM=1;
       }}
#line 2156 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 603 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
	if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bREMOTE_ISLAND_MODEL=0;
	else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bREMOTE_ISLAND_MODEL=1;
	else {
	  fprintf(stderr,"\n%s - Warning line %d: remote island model must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n",sEZ_FILE_NAME,yylineno);nWARNINGS++;
	  bREMOTE_ISLAND_MODEL=0;
	}}
#line 2168 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 610 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
        sprintf(sIP_FILE, (yyvsp[-2].pSymbol)->sName);
	strcat(sIP_FILE,".");
	strcat(sIP_FILE,(yyvsp[0].pSymbol)->sName);
	}
#line 2178 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 615 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
	fMIGRATION_PROBABILITY=(float)(yyvsp[0].dValue);
	}
#line 2186 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 618 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      nSERVER_PORT=(int)(yyvsp[0].dValue);
    }
#line 2194 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 621 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bPRINT_STATS=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bPRINT_STATS=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Print stats must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bPRINT_STATS=0;
       }}
#line 2206 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 628 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bPLOT_STATS=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bPLOT_STATS=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Generate stats must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bPLOT_STATS=0;
       }}
#line 2218 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 635 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bGENERATE_CSV_FILE=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bGENERATE_CSV_FILE=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Generate csv file must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bGENERATE_CSV_FILE=0;
       }}
#line 2230 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 642 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bGENERATE_GNUPLOT_SCRIPT=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bGENERATE_GNUPLOT_SCRIPT=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Generate gnuplot script must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bGENERATE_GNUPLOT_SCRIPT=0;
       }}
#line 2242 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 649 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bGENERATE_R_SCRIPT=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bGENERATE_R_SCRIPT=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: Generate R script must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bGENERATE_R_SCRIPT=0;
       }}
#line 2254 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 656 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bSAVE_POPULATION=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bSAVE_POPULATION=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: SavePopulation must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bSAVE_POPULATION=0;
       }}
#line 2266 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 663 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (!mystricmp((yyvsp[0].pSymbol)->sName,"False")) bSTART_FROM_FILE=0;
      else if (!mystricmp((yyvsp[0].pSymbol)->sName,"True")) bSTART_FROM_FILE=1;
      else {
         fprintf(stderr,"\n%s - Warning line %d: StartFromFile must be \"True\" or \"False\".\nDefault value \"False\" inserted.\n.",sEZ_FILE_NAME,yylineno);nWARNINGS++;
         bSTART_FROM_FILE=0;
       }}
#line 2278 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 670 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iMAX_INIT_TREE_D = (unsigned)(yyvsp[0].dValue);}
#line 2284 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 671 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iMIN_INIT_TREE_D = (unsigned)(yyvsp[0].dValue);}
#line 2290 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 672 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iMAX_TREE_D = (unsigned)(yyvsp[0].dValue);}
#line 2296 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 673 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iNB_GPU = (unsigned)(yyvsp[0].dValue);}
#line 2302 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 674 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iPRG_BUF_SIZE = (unsigned)(yyvsp[0].dValue);}
#line 2308 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 677 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {iNO_FITNESS_CASES = (unsigned)(yyvsp[0].dValue);}
#line 2314 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 681 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { 
      if (SymbolTable.find((yyvsp[-2].pSymbol)->sName)==NULL){
         fprintf(stderr,"\n%s - Error line %d: Symbol \"%s\" not found.\n",sEZ_FILE_NAME,yylineno,(yyvsp[-2].pSymbol)->sName);
         exit(1);
      }
      (yyval.dValue) = CEASEAParser_assign(SymbolTable.find((yyvsp[-2].pSymbol)->sName), (yyvsp[0].dValue));
    }
#line 2326 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 688 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = (yyvsp[-2].dValue) + (yyvsp[0].dValue); }
#line 2332 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 689 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = (yyvsp[-2].dValue) - (yyvsp[0].dValue); }
#line 2338 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 690 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = (yyvsp[-2].dValue) * (yyvsp[0].dValue); }
#line 2344 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 691 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { /* CEASEAParser_divide can't be used because g++ can't goto the label YYERROR go,
                                           So I directely use its code. I don't know why g++ can't compile CEASEAParser_divide */
                                        if((yyvsp[0].dValue) == 0) {(yyval.dValue)=0; YYERROR; return 0;}
                                        else (yyval.dValue) = (yyvsp[-2].dValue) / (yyvsp[0].dValue); }
#line 2353 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 695 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = (yyvsp[-1].dValue); }
#line 2359 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 696 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = -(yyvsp[0].dValue); }
#line 2365 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 697 "compiler/EaseaParse.y" /* yacc.c:1646  */
    { (yyval.dValue) = (yyvsp[0].dValue); }
#line 2371 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 698 "compiler/EaseaParse.y" /* yacc.c:1646  */
    {
      if (SymbolTable.find((yyvsp[0].pSymbol)->sName)==NULL){
         fprintf(stderr,"\n%s - Error line %d: Symbol \"%s\" not found.\n",sEZ_FILE_NAME,yylineno,(yyvsp[0].pSymbol)->sName);
         exit(1);
      }
      (yyval.dValue) = (SymbolTable.find((yyvsp[0].pSymbol)->sName))->dValue;
    }
#line 2383 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
    break;


#line 2387 "compiler/EaseaParse.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
                      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 707 "compiler/EaseaParse.y" /* yacc.c:1906  */

                       
/////////////////////////////////////////////////////////////////////////////
// main

int main(int argc, char *argv[]){
  int n = YYEXIT_FAILURE;
  int nParamNb=0;
  char *sTemp;
  int i=0;
  
  TARGET=STD;
  bVERBOSE=0;
  sRAW_PROJECT_NAME[0]=0; // used to ask for a filename if no filename is found on the command line.

  while ((++nParamNb) < argc) {
    sTemp=&(argv[nParamNb][0]);
    if ((argv[nParamNb][0]=='-')||(argv[nParamNb][0]=='/')) sTemp=&(argv[nParamNb][1]);
    if (!mystricmp(sTemp,"cuda")){
      TARGET=CUDA;
      TARGET_FLAVOR = CUDA_FLAVOR_SO;
    }
    else if( !mystricmp(sTemp,"cuda_mo") ){
      TARGET=CUDA;
      TARGET_FLAVOR = CUDA_FLAVOR_MO;
    }
    else if( !mystricmp(sTemp,"cuda_gp") ){
      printf("tpl is cuda gp\n");
      TARGET=CUDA;
      TARGET_FLAVOR = FLAVOR_GP;
    }
    else if( !mystricmp(sTemp,"gp") ){
      printf("tpl is gp\n");
      TARGET=STD;
      TARGET_FLAVOR = FLAVOR_GP;
    }
    else if (!mystricmp(sTemp,"std"))  {
      TARGET=STD;
      TARGET_FLAVOR = STD_FLAVOR_SO;
    }
    else if (!mystricmp(sTemp,"std_mo")) {
      TARGET=STD;
      TARGET_FLAVOR = STD_FLAVOR_MO;
    }
    else if (!mystricmp(sTemp,"cmaes"))  {
      TARGET_FLAVOR = CMAES;
    }
    else if (!mystricmp(sTemp,"memetic"))  {
      TARGET_FLAVOR = MEMETIC;
    }
    else if (!mystricmp(sTemp,"nsgaii"))  {
      TARGET_FLAVOR = NSGAII;
    }
    else if (!mystricmp(sTemp,"asrea"))  {
      TARGET_FLAVOR = ASREA;
    }


    else if (!mystricmp(sTemp,"v"))  bVERBOSE=true;
    else if (!mystricmp(sTemp,"tl")){
      bLINE_NUM_EZ_FILE=false;
    }
    else if (!mystricmp(sTemp,"path"))  {
      if (argv[++nParamNb][0]=='"') {
        strcpy(sEZ_PATH,&(argv[nParamNb][1]));
        while (argv[++nParamNb][strlen(argv[nParamNb])]!='"')
          strcat(sEZ_PATH,argv[nParamNb]);
          argv[nParamNb][strlen(argv[nParamNb])]=0;
          strcat(sEZ_PATH,argv[nParamNb]);
      }
      else {
        if (argv[nParamNb][strlen(argv[nParamNb])-1]=='"') argv[nParamNb][strlen(argv[nParamNb])-1]=0;
        strcpy(sEZ_PATH,argv[nParamNb]);
      }
    }
    else if (!mystricmp(sTemp,"eo_dir"))  {
      if (argv[++nParamNb][0]=='"') {
        strcpy(sEO_DIR,&(argv[nParamNb][1]));
        while (argv[++nParamNb][strlen(argv[nParamNb])]!='"')
          strcat(sEO_DIR,argv[nParamNb]);
          argv[nParamNb][strlen(argv[nParamNb])]=0;
          strcat(sEO_DIR,argv[nParamNb]);
      }
      else {
        if (argv[nParamNb][strlen(argv[nParamNb])-1]=='"') argv[nParamNb][strlen(argv[nParamNb])-1]=0;
        strcpy(sEO_DIR,argv[nParamNb]);
      }
    }
    else strcpy(sRAW_PROJECT_NAME,argv[nParamNb]);
  }

  CEASEAParser_create();
  n = yyparse();
  exit(n);
  return n;
}

/////////////////////////////////////////////////////////////////////////////
// EASEAParser commands

int CEASEAParser_create()
{
  CSymbol *pNewBaseType;

  pNewBaseType=new CSymbol("bool");
  pNewBaseType->nSize=sizeof(bool);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);

  pNewBaseType=new CSymbol("int");
  pNewBaseType->nSize=sizeof(int);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);

  pNewBaseType=new CSymbol("double");
  pNewBaseType->nSize=sizeof(double);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);

  pNewBaseType=new CSymbol("float");
  pNewBaseType->nSize=sizeof(float);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);

  pNewBaseType=new CSymbol("char");
  pNewBaseType->nSize=sizeof(char);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);

  pNewBaseType=new CSymbol("pointer");
  pNewBaseType->nSize=sizeof(char *);   
  pNewBaseType->ObjectType=oBaseClass;
  SymbolTable.insert(pNewBaseType);


  //if (!yycreate(&EASEALexer)) {
  //  return 0;
  //}
  if (!CEASEALexer_create(&SymbolTable)) {
    return 0;
  }
  return 1; // success
}

/////////////////////////////////////////////////////////////////////////////
// calc_parser attribute commands

double CEASEAParser_assign(CSymbol* spIdentifier, double dValue)
{
  assert(spIdentifier != NULL);

  spIdentifier->dValue = dValue;
  return spIdentifier->dValue;
}

/*double CEASEAParser_divide(double a, double b)
{
  if (b == 0) {
    printf("division by zero\n");
    YYERROR;
    return 0;
  }
  else {
    return a / b;
  }
}
*/

void CEASEAParser_yysyntaxerror(){

  printf("Syntax Error at line : %d (on text : %s)\nFor more details during the EASEA compiling, use the \"-v\" option\n",
	 yylineno,yytext);
}

