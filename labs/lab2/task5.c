
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


struct Product
{
    char name[50];
    float price;
};

void PriceSort(struct Product a[], int array_size)
{
    struct Product temp;
    for (int i = 0; i < (array_size - 1); ++i)
    {
        for (int j = 0; j < array_size - 1 - i; ++j )
        {
            if (a[j].price > a[j+1].price)
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    
    char buffer[256];
    
    int count = 0;
    FILE *file = fopen("products.txt", "r");
    if(file)
    {
        while((fgets(buffer, 256, file))!=NULL)
        {
            count++;
        }
        fclose(file);
    }
    
    struct Product products[count];
    
    FILE *file1 = fopen("products.txt", "r");
    if(file1)
    {
        int i = 0;
        while((fgets(buffer, 256, file1))!=NULL)
        {
            sscanf(buffer, "%s %f", products[i].name, &products[i].price);
            i++;
        }
        fclose(file1);
    }
    
    
    FILE *file2 = fopen("sorted_products.txt", "w");
    if(file2)
    {
        int size = (int)(sizeof(products)/sizeof(struct Product));
        
        PriceSort(products, size);
        
        for (int i = 0; i < size; i++)
            fprintf(file, "%s %.2f \n", products[i].name, products[i].price);
        
        fclose(file2);
    }
    
    return 0;
}
