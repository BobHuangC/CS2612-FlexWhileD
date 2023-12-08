/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LANGANALYSIS_PARSER_H_INCLUDED
# define YY_YY_LANGANALYSIS_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TM_NAT = 258,                  /* TM_NAT  */
    TM_INT_TYPE = 259,             /* TM_INT_TYPE  */
    TM_CHAR_TYPE = 260,            /* TM_CHAR_TYPE  */
    TM_ENUM_TYPE = 261,            /* TM_ENUM_TYPE  */
    TM_STRUCT_TYPE = 262,          /* TM_STRUCT_TYPE  */
    TM_UNION_TYPE = 263,           /* TM_UNION_TYPE  */
    TM_TYPEDEF_TYPE = 264,         /* TM_TYPEDEF_TYPE  */
    TM_DEREFERENCE = 265,          /* TM_DEREFERENCE  */
    TM_COMMA = 266,                /* TM_COMMA  */
    TM_LEFT_BRACE = 267,           /* TM_LEFT_BRACE  */
    TM_RIGHT_BRACE = 268,          /* TM_RIGHT_BRACE  */
    TM_LEFT_PAREN = 269,           /* TM_LEFT_PAREN  */
    TM_RIGHT_PAREN = 270,          /* TM_RIGHT_PAREN  */
    TM_LEFT_BRACKET = 271,         /* TM_LEFT_BRACKET  */
    TM_RIGHT_BRACKET = 272,        /* TM_RIGHT_BRACKET  */
    TM_SEMICOL = 273,              /* TM_SEMICOL  */
    TM_IDENT = 274                 /* TM_IDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "LangAnalysis/lang.y"

unsigned int n;
char * i;
struct expr * e;
void * none;

#line 90 "LangAnalysis/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LANGANALYSIS_PARSER_H_INCLUDED  */
