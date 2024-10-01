
#include <stdio.h>

int main (int argc, char * argv[]) {
    char *filename = argv[1];
    char buffer[256];
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    }
    return 0;
}
