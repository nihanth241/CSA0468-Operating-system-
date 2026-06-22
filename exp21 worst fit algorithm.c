#include <stdio.h>

int main()
{
    int b[20], f[20], bf[20];
    int i, j, nb, nf;
    int temp;
    int frag[20], bno[20];

    printf("Memory Management Scheme - Worst Fit\n");

    printf("Enter the number of blocks:");
    scanf("%d", &nb);

    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:-\n");

    for(i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files :-\n");

    for(i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++)
    {
        for(j = 1; j <= nb; j++)
        {
            bf[j] = b[j] - f[i];
        }

        temp = -1;

        for(j = 1; j <= nb; j++)
        {
            if(bf[j] >= 0)
            {
                if(temp < bf[j])
                {
                    bno[i] = j;
                    temp = bf[j];
                }
            }
        }

        frag[i] = temp;

        b[bno[i]] = 0;
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment\n");

    for(i = 1; i <= nf; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               i,
               f[i],
               bno[i],
               f[i] + frag[i],
               frag[i]);
    }

    return 0;
}