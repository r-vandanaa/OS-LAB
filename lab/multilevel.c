#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], type[n];
    int ct[n], tat[n], wt[n];
    int done[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT BT Type(0-SYS 1-USR) for P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&type[i]);

        done[i] = 0;
    }

    int time = 0, completed = 0;

    int gantt[100], gt[101];
    int k = 0;

    gt[0] = 0;

    while(completed < n)
    {
        int p = -1;

        for(int i=0;i<n;i++)
        {
            if(!done[i] && at[i] <= time && type[i] == 0)
            {
                p = i;
                break;
            }
        }
        if(p == -1)
        {
            for(int i=0;i<n;i++)
            {
                if(!done[i] && at[i] <= time && type[i] == 1)
                {
                    p = i;
                    break;
                }
            }
        }

        if(p == -1)
        {
            gantt[k] = -1;
            time++;

            k++;
            gt[k] = time;

            continue;
        }

        gantt[k] = p;

        time += bt[p];

        ct[p] = time;
        tat[p] = ct[p] - at[p];
        wt[p] = tat[p] - bt[p];

        done[p] = 1;
        completed++;

        k++;
        gt[k] = time;
    }

    float avgwt = 0, avgtat = 0;

    printf("\nP\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%s\t%d\t%d\t%d\n",
               i+1,
               at[i],
               bt[i],
               type[i]==0 ? "SYS" : "USR",
               ct[i],
               tat[i],
               wt[i]);

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage WT = %.2f", avgwt/n);
    printf("\nAverage TAT = %.2f\n", avgtat/n);

    printf("\nGantt Chart:\n|");

    for(int i=0;i<k;i++)
    {
        if(gantt[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", gantt[i] + 1);
    }

    printf("\n");

    for(int i=0;i<=k;i++)
        printf("%d\t", gt[i]);

    printf("\n");

    return 0;
}