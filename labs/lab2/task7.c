#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // Для функции isdigit

#define MAX_SIZE 100  

int stack[MAX_SIZE];  
int top = -1;  

void push(int item) {  
    if (top >= MAX_SIZE - 1) {  
        printf("Стек переполнен\n");  
        return;  
    }  
    stack[++top] = item;  
}  

int pop() {  
    if (top < 0) {  
        printf("Стек пуст\n");  
        return -1;  
    }  
    return stack[top--];  
}  

int is_operator(char symbol) {  
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');  
}  

int evaluate(char* expression) {  
    int i = 0;  
    char symbol;  
    int operand1, operand2, result;

    while ((symbol = expression[i]) != '\0') {
        if (isspace(symbol)) {  // Пропускаем пробелы
            i++;
            continue;
        }
        
        if (isdigit(symbol)) {  // Проверяем, является ли символ цифрой
            int num = 0;
            // Собираем многозначное число
            while (isdigit(symbol)) {
                num = num * 10 + (symbol - '0');
                i++;
                symbol = expression[i];
            }
            push(num);  // Добавляем полное число в стек
            continue; // Продолжаем с новым символом
        }  
        else if (is_operator(symbol)) {  
            operand2 = pop();
            operand1 = pop();  
            if (operand2 == -1 || operand1 == -1) {
                printf("Ошибка: недостаточно операндов\n");
                return 0; // Завершение выполнения в случае ошибки
            }
            switch (symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': 
                    if (operand2 != 0) {
                        result = operand1 / operand2; 
                    } else {
                        printf("Ошибка: деление на ноль\n");
                        return 0; // Завершение выполнения в случае ошибки
                    }
                    break;  
            }
            push(result);  
        }
        i++;
    }

    if (top != 0) {
        printf("Ошибка: недопустимое выражение\n");
        return 0; // Завершение выполнения в случае ошибки
    }

    return pop();  
}  

int main() {  
    char buffer[256];
    FILE *file = fopen("input.txt", "r");
    
    if(file)
    {
        fgets(buffer, 256, file);
        fclose(file);
    }
    
    int result = evaluate(buffer);  
    printf("Результат = %d\n", result);  
    return EXIT_SUCCESS;  
}
