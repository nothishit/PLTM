%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%union {
    double num;
}

%token <num> NUMBER
%token PLUS MINUS MULT DIV LPAREN RPAREN EOL

%%

input:  
        | input line
        ;

line:       EOL
        | expr EOL      { printf("\n"); }
        ;

expr:       expr PLUS term      { printf("+ "); }
        | expr MINUS term       { printf("- "); }
        | term
        ;

term:       term MULT factor    { printf("* "); }
        | term DIV factor       { printf("/ "); }
        | factor
        ;

factor:     NUMBER              { printf("%g ", $1); } 
        | LPAREN expr RPAREN
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