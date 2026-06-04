#include <stdio.h>

int main()
{
    int n, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        rt[i] = bt[i];
    }

    int completed = 0, time = 0;

    int gantt[100];
    int gt[101];
    int k = 0;

    gt[0] = 0;

    while(completed < n)
    {
        int found = 0;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                found = 1;
                gantt[k] = i;
                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    completed++;
                }
                k++;
                gt[k] = time;
            }
        }

        if(found == 0)
        {
            gantt[k] = -1;  
            time++;

            k++;
            gt[k] = time;
        }
    }

    float avgtat = 0, avgwt = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgtat += tat[i];
        avgwt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,at[i],bt[i], ct[i],tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgtat / n);
    printf("\nAverage WT  = %.2f\n", avgwt / n);

    printf("\nGantt Chart:\n|");

    for(int i = 0; i < k; i++)
    {
        if(gantt[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", gantt[i] + 1);
    }

    printf("\n");

    for(int i = 0; i <= k; i++)
        printf("%d\t", gt[i]);

    printf("\n");

    return 0;
}