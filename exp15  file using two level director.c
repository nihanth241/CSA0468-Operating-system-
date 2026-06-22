#include <stdio.h>

int main()
{
    int i, j;
    int users, files;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 0; i < users; i++)
    {
        printf("\nEnter number of files for User %d: ", i + 1);
        scanf("%d", &files);

        printf("Files of User %d:\n", i + 1);

        for(j = 0; j < files; j++)
        {
            char fname[20];

            printf("Enter file %d name: ", j + 1);
            scanf("%s", fname);

            printf("Stored: User%d/%s\n", i + 1, fname);
        }
    }

    return 0;
}