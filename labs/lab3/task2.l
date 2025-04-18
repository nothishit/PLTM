%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

[0-9]+      { yylval.num = atoi(yytext); return NUMBER; }
"+"         { return PLUS; }
"-"         { return MINUS; }
[ \t]       ; 
\n          { return EOL; }
.           { yyerror("Неправильный символ"); }

%%

int yywrap(void) {
    return 1;
}