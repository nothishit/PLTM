
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
        if (i < 4) 
        {
            printf("%d, ", arr[i]);
        } else printf("%d", arr[i]);
    }

    
    
    return 0;
}