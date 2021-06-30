/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ADD = 258,
    SUBTRACT = 259,
    MULTIPLY = 260,
    DIVIDE = 261,
    LEFT = 262,
    RIGHT = 263,
    UP = 264,
    DOWN = 265,
    ASSIGN = 266,
    TO = 267,
    VAR = 268,
    IS = 269,
    VALUE = 270,
    IN = 271,
    NEXTLINE = 272,
    NUMBERS = 273,
    FULLSTOP = 274,
    SPACE = 275,
    COMMA = 276,
    CORDINATES = 277,
    ERRORF = 278,
    NAME = 279
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUBTRACT 259
#define MULTIPLY 260
#define DIVIDE 261
#define LEFT 262
#define RIGHT 263
#define UP 264
#define DOWN 265
#define ASSIGN 266
#define TO 267
#define VAR 268
#define IS 269
#define VALUE 270
#define IN 271
#define NEXTLINE 272
#define NUMBERS 273
#define FULLSTOP 274
#define SPACE 275
#define COMMA 276
#define CORDINATES 277
#define ERRORF 278
#define NAME 279

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 4 "test.y"
int num; char s[200];

#line 108 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
