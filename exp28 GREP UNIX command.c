#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void searchFile(const char *pattern, const char *filename)
{
    FILE *file = fopen(filename, "r");

    if(file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];

    while(fgets(line, sizeof(line), file))
    {
        if(strstr(line, pattern) != NULL)
        {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    searchFile(argv[1], argv[2]);

    return 0;
}