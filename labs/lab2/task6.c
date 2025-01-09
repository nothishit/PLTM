#include <stdio.h>
#include <stdbool.h>

// Максимальная вместимость стека
#define MAX_SIZE 3

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
        printf("Стек переполнен, элемент не был добавлен\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Добавлен %d в стек\n", value);
}

// Извлечь элемент из стека
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Стек пуст\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    printf("Удалён элемент %d из стека\n", popped);
    
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
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 5);
    
    while (!isEmpty(&stack)) {
        printf("Верхний элемент: %d\n", peek(&stack));
        pop(&stack);
    }

    return 0;
}
