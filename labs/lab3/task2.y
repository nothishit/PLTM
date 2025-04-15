%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%union {
    int num;  
}

%token <num> NUMBER
%token PLUS MINUS EOL

%type <num> expr

%%

input:  
        | input line
        ;

line:       EOL
        | expr EOL      { printf("Result: %d\n", $1); }
        ;

expr:       expr PLUS NUMBER      { $$ = $1 + $3; }
        | expr MINUS NUMBER       { $$ = $1 - $3; }
        | NUMBER                 { $$ = $1; }
        ;
%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}