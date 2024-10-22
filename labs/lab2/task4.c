
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void BubbleSort(float a[], int array_size)
{
    float temp;
    for (int i = 0; i < (array_size - 1); ++i)
    {
        for (int j = 0; j < array_size - 1 - i; ++j )
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(int argc, char * argv[])
{
    int size, min, max;
    sscanf(argv[1], "%d", &size);
    sscanf(argv[2], "%d", &min);
    sscanf(argv[3], "%d", &max);
    
    float arr[size];
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++)
    {
        int x = rand() % (max - min + 1) + min;
        arr[i] = x;
        if (i < size-1) 
        {
            printf("%f, ", arr[i]);
        } else printf("%f", arr[i]);
    }
    
    BubbleSort(arr, size);
    
    FILE *file = fopen("sorted.txt", "w");
    if(file)
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(file, "%f ", arr[i]);
        }
        fclose(file);
    }
    
    return 0;
}
