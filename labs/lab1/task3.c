#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *arr[100];
    char value[255];
    int count = 0;

    while (strcmp(value, "stop") != 0)
    {
        count++;
        printf("Введите аргумент %i: ", count);
        scanf("%s", value);
        arr[count-1] = malloc(strlen(value) + 1);
        strcpy(arr[count-1], value);
    }
    for (int i = 0; i < count-1; i++)
    {
        puts(arr[i]);
    }
    free(*arr);
    return 0;
}