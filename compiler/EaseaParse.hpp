/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 93 "compiler/EaseaParse.y" /* yacc.c:1909  */

  CSymbol* pSymbol;
  double dValue;
  int ObjectQualifier;
  int nValue;
  char *szString;

#line 127 "compiler/EaseaParse.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);
/* "%code provides" blocks.  */
#line 87 "compiler/EaseaParse.y" /* yacc.c:1909  */

// forward references
class CSymbol;
#line 180 "compiler/EaseaParse.y" /* yacc.c:1909  */

#include "EaseaSym.h"
#include "EaseaLex.h"

  int  CEASEAParser_create();
  
  double  CEASEAParser_assign(CSymbol* pIdentifier, double dValue);
  double  CEASEAParser_divide(double dDividend, double dDivisor);
  CSymbol*  CEASEAParser_insert();

  //virtual void yysyntaxerror();


#line 158 "compiler/EaseaParse.hpp" /* yacc.c:1909  */

#endif /* !YY_YY_COMPILER_EASEAPARSE_HPP_INCLUDED  */
