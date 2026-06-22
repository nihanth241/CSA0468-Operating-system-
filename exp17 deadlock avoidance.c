#include <stdio.h>

int main()
{
    int allocation[5][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int maximum[5][3] = {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int available[3] = {3,3,2};

    int need[5][3];
    int request[3];
    int process;

    int i,j;

    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("Enter process number (0 to 4): ");
    scanf("%d",&process);

    printf("Enter resource request (e.g., 0 1 0): ");

    for(i=0;i<3;i++)
        scanf("%d",&request[i]);

    for(i=0;i<3;i++)
    {
        if(request[i] > need[process][i])
        {
            printf("\nRequest denied. Exceeds maximum need.\n");
            return 0;
        }
    }

    for(i=0;i<3;i++)
    {
        if(request[i] > available[i])
        {
            printf("\nRequest denied. Resources unavailable.\n");
            return 0;
        }
    }

    for(i=0;i<3;i++)
    {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    int finish[5]={0};
    int safe[5];
    int count=0;

    while(count<5)
    {
        int found=0;

        for(i=0;i<5;i++)
        {
            if(!finish[i])
            {
                int flag=1;

                for(j=0;j<3;j++)
                {
                    if(need[i][j] > available[j])
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                {
                    safe[count++]=i;

                    for(j=0;j<3;j++)
                        available[j]+=allocation[i][j];

                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count==5)
    {
        printf("\nRequest granted. System remains in safe state.\n");
    }
    else
    {
        printf("\nRequest denied. System is not in safe state.\n");
    }

    return 0;
}