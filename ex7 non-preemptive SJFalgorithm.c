#include<stdio.h>

int main()
{
    int n,i,j;
    int at[10],bt[10],st[10],et[10];
    int wt[10],tat[10];
    float avgwt=0,avgtat=0;

    printf("Enter the number of processes\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time and execution time for process %d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    st[0]=0;
    et[0]=bt[0];

    wt[0]=st[0]-at[0];
    tat[0]=et[0]-at[0];

    for(i=1;i<n;i++)
    {
        st[i]=et[i-1];
        et[i]=st[i]+bt[i];

        wt[i]=st[i]-at[i];
        tat[i]=et[i]-at[i];
    }

    printf("\n");
    printf("Process |Arrival time |Execution time |Start time |End time |Waiting |Turnaround\n");

    for(i=0;i<n;i++)
    {
        printf("p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",
        i+1,at[i],bt[i],st[i],et[i],wt[i],tat[i]);

        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nAverage waiting time is %f",avgwt/n);
    printf("\nAverage turnaround time is %f\n",avgtat/n);

    return 0;
}