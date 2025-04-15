%{
#include <stdio.h>
%}

%%
[a-zA-Z0-9]*	printf("%s", yytext); 
%%

