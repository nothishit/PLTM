%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%union {
    int num;
}

%token <num> NUMBER
%token PLUS MINUS MULT DIV LPAREN RPAREN EOL

%type <num> expr term factor

%%

input:  
        | input line
        ;

line:       EOL
        | expr EOL      { printf("\n"); }
        ;

expr:       expr PLUS term      { printf("+ "); $$ = $1 + $3; }
        | expr MINUS term       { printf("- "); $$ = $1 - $3; }
        | term                 { $$ = $1; }
        ;

term:       term MULT factor    { printf("* "); $$ = $1 * $3; }
        | term DIV factor       { printf("/ "); $$ = $1 / $3; }
        | factor                { $$ = $1; }
        ;

factor:     NUMBER              { printf("%d ", $1); $$ = $1; }
        | LPAREN expr RPAREN    { $$ = $2; }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Ошибка: %s\n", s);
}

int main(void) {
    printf("Введите арифметическое выражение:\n");
    yyparse();
    return 0;
}