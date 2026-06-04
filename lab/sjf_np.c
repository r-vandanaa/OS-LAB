#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0, sj;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int done[n];

    int order[20], times[21], k = 0;

    float avgTAT = 0, avgWT = 0;

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        done[i] = 0;
    }

    times[k] = 0;

    while(completed < n)
    {
        sj = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(sj == -1 || bt[i] < bt[sj])
                    sj = i;
            }
        }

        if(sj == -1)
        {
            order[k] = -1;     
            time++;
            k++;
            times[k] = time;
            continue;
        }

        order[k] = sj;

        time += bt[sj];
        ct[sj] = time;

        tat[sj] = ct[sj] - at[sj];
        wt[sj] = tat[sj] - bt[sj];

        avgTAT += tat[sj];
        avgWT += wt[sj];

        done[sj] = 1;
        completed++;

        k++;
        times[k] = time;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT/n);
    printf("\nAverage WT  = %.2f\n", avgWT/n);

    printf("\nGantt Chart:\n|");

    for(i = 0; i < k; i++)
    {
        if(order[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", order[i] + 1);
    }

    printf("\n");

    for(i = 0; i <= k; i++)
        printf("%d\t", times[i]);

    printf("\n");

    return 0;
}