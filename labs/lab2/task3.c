
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int size = 0;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    float arr[size];
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++)
    {
        float x = (float)rand()/(float)(RAND_MAX);
        arr[i] = x;
        if (i < size-1) 
        {
            printf("%f, ", arr[i]);
        } else printf("%f", arr[i]);
    }
    
    return 0;
}