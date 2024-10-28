
#include <stdio.h>
#include <stdbool.h>

// Максимальная вместимость стека
#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;

void initialize(Stack *stack) {
    // Добавить -1 в вершину чтобы проверять пуст ли стек
    stack->top = -1;  
}

bool isEmpty(Stack *stack) {
    // Если верхнее значение -1, стек пуст
    return stack->top == -1;  
}

bool isFull(Stack *stack) {
    // Если верхнее значение MAX_SIZE - 1, стек полон
    return stack->top == MAX_SIZE - 1;  
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Стек переполнен\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Извлечь элемент из стека
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    
    return popped;
}

// Верхний элемент стека
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    
    initialize(&stack);  

    push(&stack, 3);
    printf("Верхний элемент: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}