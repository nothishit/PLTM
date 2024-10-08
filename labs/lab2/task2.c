
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int arr[5];
    
    srand(time(NULL));
    
    for (int i = 0; i < 5; i++)
    {
        int r = rand();
        arr[i] = r;
    }
    
    char filename[256];
    printf("Введите название файла для записи: ");
    scanf("%[^\n]%*c", filename);
    FILE *f = fopen(filename, "w");
    if(f)
    {
        for (int i = 4; i >= 0; i--)
        {
            fprintf(f, "%d ", arr[i]);
        }
    }
    fclose(f);
    
    
    return 0;
}