%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

[0-9]+("."[0-9]+)?      { yylval.num = atof(yytext); return NUMBER; }
"+"                     { return PLUS; }
"-"                     { return MINUS; }
"*"                     { return MULT; }
"/"                     { return DIV; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
[ \t]                   ; 
\n                      { return EOL; }
.                       { yyerror("Неизвестный символ"); }

%%

int yywrap(void) {
    return 1;
}