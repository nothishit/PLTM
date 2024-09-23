#include <stdio.h>

int main(void)
{
    char filename[256];
    char buffer[256];
    printf("Введите название файла для записи: ");
    scanf("%[^\n]%*c", filename);
    FILE *f = fopen(filename, "r+");
    if(f)
    {
        printf("Введите строку для записи в файл: ");
        scanf("%[^\n]%*c", buffer);
        fseek(f, 0, 2);
        fputs("\n", f);
        fputs(buffer, f);
    }
    fclose(f);

    return 0;
}