
#include <stdio.h>

int main(void)
{
    char readfile[] = "";
    char writefile[] = "";
    char buffer[256];
    printf("Введите имя файла для чтения: ");
    scanf("%s", readfile);
    FILE *file_1 = fopen(readfile, "r");
    printf("Введите имя файла для записи: ");
    scanf("%s", writefile);
    FILE *file_2 = fopen(writefile, "w");
    if(file_1 && file_2)
    {
        for (int i = 0; i < 3; i++) 
        {
            fgets(buffer, 256, file_1);
            fputs(buffer, file_2);
        }
        fclose(file_1);
        fclose(file_2);
        printf("Данные были записаны\n");
    } 
}