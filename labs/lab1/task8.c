#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *arr[100];
    char filename[256];
    char buffer[256];
    char data[] = "";
    int count = 0;
    printf("Введите название файла для записи: ");
    scanf("%[^\n]%*c", filename);
    FILE *fr = fopen(filename, "r");
    if(fr)
    {
        while((fgets(buffer, 256, fr))!=NULL)
        {
            arr[count] = malloc(strlen(buffer) + 1);
            strcpy(arr[count], buffer);
            count++;
        }
        fclose(fr);
    }
    
    FILE *fw = fopen(filename, "w");
    if(fw)
    {
        printf("%i", count);
        printf("Введите строку для записи в файл: ");
        scanf("%[^\n]%*c", buffer);
        fseek(fw, 0, 0);
        fputs(buffer, fw);
        fputs("\n", fw);
        for (int i = 0; i < count; i++)
        {
            fputs(arr[i], fw);
        }
        fclose(fw);
    }
    free(*arr);
    return 0;
}