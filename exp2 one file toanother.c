#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f1,*f2;
    char ch;

    f1 = fopen("source.txt","r");

    if(f1 == NULL)
    {
        printf("Source file not found");
        return 0;
    }

    f2 = fopen("destination.txt","w");

    while((ch=fgetc(f1)) != EOF)
    {
        fputc(ch,f2);
    }

    fclose(f1);
    fclose(f2);

    printf("File copied successfully");

    return 0;
}