
#include <stdio.h>

int main(void)
{
    char filename[] = "";
    char buffer[256];
    scanf("%s", &filename);
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    } 
}