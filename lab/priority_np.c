#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0, hp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int done[n];

    int order[20], times[21], k = 0;

    float avgTAT = 0, avgWT = 0, avgRT = 0;

    for(i = 0; i < n; i++)
    {
        printf("Enter AT, BT and Priority for P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);

        done[i] = 0;
    }

    times[0] = 0;

    while(completed < n)
    {
        hp = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(hp == -1 || pr[i] < pr[hp])
                    hp = i;
            }
        }

        if(hp == -1)
        {
            order[k] = -1;
            time++;
            k++;
            times[k] = time;
            continue;
        }

        rt[hp] = time - at[hp];

        order[k] = hp;

        time += bt[hp];
        ct[hp] = time;

        tat[hp] = ct[hp] - at[hp];
        wt[hp] = tat[hp] - bt[hp];

        avgTAT += tat[hp];
        avgWT += wt[hp];
        avgRT += rt[hp];

        done[hp] = 1;
        completed++;

        k++;
        times[k] = time;
    }

    printf("\nP\tAT\tBT\tPRI\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i], rt[i]);
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