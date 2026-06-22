#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int bt[10], rt[10], pr[10];
    int wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed < n)
    {
        int highest = -1;

        for(i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                if(highest == -1 || pr[i] > pr[highest])
                    highest = i;
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0)
        {
            completed++;

            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    float avgwt = 0, avgtat = 0;

    for(i = 0; i < n; i++)
    {
        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               i + 1,
               bt[i],
               pr[i],
               wt[i],
               tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f", avgtat/n);

    return 0;
}