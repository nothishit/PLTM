
#include <stdio.h>

int main()
{
    float a, b, c;
    printf("Введите a: ");
    scanf("%f", &a);
    printf("Введите b: ");
    scanf("%f", &b);
    printf("Введите c: ");
    scanf("%f", &c);
    float x = (c - b) / a;
    printf("Решение ax+b=c, x=%f", x);
    return 0;
}