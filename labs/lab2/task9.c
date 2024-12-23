#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char expression[MAX];
char output[MAX]; // Output for postifix expression
int outIndex = 0;

// Function to add characters to output
void addToOutput(char ch) {
    output[outIndex++] = ch;
    output[outIndex] = '\0'; // Null-terminate the string
}

// Function to handle numbers
void handleNumber() {
    while (isdigit(*expression)) {
        addToOutput(*expression);
        expression++;
    }
}

// Function to handle factor
void factor() {
    if (*expression == '(') {
        expression++; // Skip '('
        E(); // Parse the expression
        if (*expression == ')') {
            expression++; // Skip ')'
        }
    } else if (isdigit(*expression)) {
        handleNumber();
    }
}

// Function to handle term
void T() {
    factor();
    
    while (*expression == '*' || *expression == '/') {
        addToOutput(*expression);
        expression++;
        factor(); // Parse the next factor
    }
}

// Function to handle expression
void E() {
    T();
    
    while (*expression == '+' || *expression == '-') {
        addToOutput(*expression);
        expression++;
        T(); // Parse the next term
    }
}

// Main function to convert infix to postfix
void infixToPostfix(char* expr) {
    strcpy(expression, expr);
    outIndex = 0; // Reset output index

    E(); // Start parsing the expression

    printf("Postfix Expression: %s\n", output);
}

int main() {
    char* expressions[] = {
        "3+5",
        "10 + 2 * 6",
        "(2 + 3) * 4",
        "100 * (2 + 12) / 14 - 6",
        "5 + (3 - 2) * 6"
    };

    for (int i = 0; i < 5; i++) {
        printf("Infix Expression: %s\n", expressions[i]);
        infixToPostfix(expressions[i]);
    }
    
    return 0;
}