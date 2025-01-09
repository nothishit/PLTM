#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    return isdigit(c);  // Проверка, является ли символ цифрой
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
    int k = 0;  // Индекс для постфиксной записи
    int i = 0;  // Индекс для инфиксной записи
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            push(&s, '(');
        } else if (infix[i] == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';  // Добавляем пробел после оператора
            }
            pop(&s);  // Отбрасываем '('
        } else if (isOperand(infix[i])) {
            // Обработка многозначного числа
            while (isOperand(infix[i])) {
                postfix[k++] = infix[i++];  // Добавляем цифру в постфиксную запись
            }
            postfix[k++] = ' ';  // Добавляем пробел после числа
            continue;  // Продолжаем цикл с новой позицией
        } else {
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
                postfix[k++] = ' ';  // Добавляем пробел после оператора
            }
            push(&s, infix[i]);
        }
        i++;
    }
    while (s.top != -1) {
        postfix[k++] = pop(&s);
        postfix[k++] = ' ';  // Добавляем пробел после оператора
    }
    if (k > 0) {
        postfix[k - 1] = '\0';  // Заменяем последний пробел на нуль-терминатор
    } else {
        postfix[0] = '\0';  // Пустой результат
    }
}

int main() {
    char infix1[] = "(14+5)*6";
    char postfix1[MAX_SIZE];
    infixToPostfix(infix1, postfix1);
    printf("Инфикс: %s\n", infix1);
    printf("Постфикс: %s\n", postfix1);

    return 0;
}
