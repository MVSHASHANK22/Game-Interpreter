%{
    
#include "y.tab.h"
void yyerror (char *s);
int yylex();
    
%}

num [1-9][0-9]*
str [a-zA-Z][0-9a-z_A-Z]*
%%
"ADD" {return ADD;}
"SUBTRACT" {return SUBTRACT;}
"MULTIPLY" {return MULTIPLY;}
"DIVIDE" {return DIVIDE;}
"LEFT" {return LEFT;}
"RIGHT" {return RIGHT;}
"UP" {return UP;}
"DOWN" {return DOWN;}
"ASSIGN" {return ASSIGN;}
"TO" {return TO;}
"VAR" {return VAR;}
"IS" {return IS;}
"VALUE" {return VALUE;}
"IN" {return IN;}
([ ]) {return SPACE;}
[\n] {return NEXTLINE;}
[ \t\n] {}
{num} {yylval.num=atoi(yytext); return NUMBERS;}
{str} {sscanf(yytext,"%s",yylval.s); return NAME;}
"." {return FULLSTOP;}
"," {return COMMA;}
. {return ERRORF;}

%%
int yywrap(void)
{
    return 1;
}

