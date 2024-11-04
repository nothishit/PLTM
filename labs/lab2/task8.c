#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    s->items[++s->top] = c;
}

char pop(Stack *s) {
    return s->items[s->top--];
}

int isOperand(char c) {
    return (c >= '0' && c <= '9');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    init(&s);
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            push(&s, '(');
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Discard '('
        } else if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        } else {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
    }

int main() {
    char infix1[] = "(4+5)*6";
    char postfix1[MAX_SIZE];
    infixToPostfix(infix1, postfix1);
    printf("Infix expression: %s\n", infix1);
    printf("Postfix expression: %s\n\n", postfix1);

    return 0;
}





