#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char shared_memory[100];

    printf("Enter a message: ");
    fgets(shared_memory, sizeof(shared_memory), stdin);

    printf("\nWriting to Shared Memory...\n");
    printf("Data written: %s", shared_memory);

    printf("\nReading from Shared Memory...\n");
    printf("Data read: %s", shared_memory);

    return 0;
}