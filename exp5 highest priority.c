#include<stdio.h>

struct process
{
    char name;
    int bt;
    int priority;
    int wt;
    int tat;
};

int main()
{
    int n,i,j,pos;
    float avgwt=0,avgtat=0;

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    struct process p[n],temp;

    for(i=0;i<n;i++)
    {
        p[i].name='A'+i;

        printf("\nProcess %c\n",p[i].name);

        printf("Enter Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Enter Priority: ");
        scanf("%d",&p[i].priority);
    }

    for(i=0;i<n;i++)
    {
        pos=i;

        for(j=i+1;j<n;j++)
        {
            if(p[j].priority > p[pos].priority)
                pos=j;
        }

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    p[0].wt=0;

    for(i=1;i<n;i++)
    {
        p[i].wt=p[i-1].wt+p[i-1].bt;
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        p[i].tat=p[i].wt+p[i].bt;

        avgwt+=p[i].wt;
        avgtat+=p[i].tat;

        printf("%c\t%d\t%d\t\t%d\t%d\n",
               p[i].name,
               p[i].bt,
               p[i].priority,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    return 0;
}