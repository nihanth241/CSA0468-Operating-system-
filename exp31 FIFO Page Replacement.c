#include <stdio.h>

int main()
{
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2};
    int n = 13;

    int frame[3] = {-1,-1,-1};

    int ptr = 0;
    int i,j,found;

    printf("Reference String: ");

    for(i=0;i<n;i++)
        printf("%d ",pages[i]);

    printf("\n\nPage Replacement Order:\n");

    for(i=0;i<n;i++)
    {
        found = 0;

        for(j=0;j<3;j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frame[ptr] = pages[i];
            ptr = (ptr + 1) % 3;

            printf("Page %d -> ", pages[i]);

            for(j=0;j<3;j++)
            {
                if(frame[j] == -1)
                    printf("- ");
                else
                    printf("%d ", frame[j]);
            }

            printf("\n");
        }
    }

    return 0;
}