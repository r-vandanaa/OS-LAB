#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0, shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], start[n];

    int order[100], times[101], k = 0;

    float avgTAT = 0, avgWT = 0, avgRT = 0;

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);

        rt[i] = bt[i];
        start[i] = -1;
    }

    times[0] = 0;

    while(completed < n)
    {
        shortest = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(shortest == -1 || rt[i] < rt[shortest])
                    shortest = i;
            }
        }

        if(shortest == -1)
        {
            order[k] = -1;
            time++;
            k++;
            times[k] = time;
            continue;
        }

        if(start[shortest] == -1)
            start[shortest] = time;

        order[k] = shortest;

        rt[shortest]--;
        time++;

        k++;
        times[k] = time;

        if(rt[shortest] == 0)
        {
            completed++;
            ct[shortest] = time;
        }
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];
        avgRT += start[i] - at[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i],
               tat[i], wt[i], start[i]-at[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT/n);
    printf("\nAverage WT  = %.2f", avgWT/n);
    printf("\nAverage RT  = %.2f\n", avgRT/n);

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