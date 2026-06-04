#include <stdio.h>

int main()
{
    int n, time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], rt[n];
    int ct[n], tat[n], wt[n];

    int gantt[100], k = 0;

    for(int i = 0; i < n; i++)
    {
        printf("Enter AT BT Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);

        rt[i] = bt[i];
    }

    while(completed < n)
    {
        int hp = -1;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(hp == -1 || pr[i] < pr[hp])
                    hp = i;
            }
        }

        if(hp == -1)
        {
            gantt[k++] = -1;   
            time++;
            continue;
        }

        gantt[k++] = hp;

        rt[hp]--;
        time++;

        if(rt[hp] == 0)
        {
            completed++;

            ct[hp] = time;
            tat[hp] = ct[hp] - at[hp];
            wt[hp] = tat[hp] - bt[hp];
        }
    }
    printf("\nP\tAT\tBT\tPRI\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("\nGantt Chart:\n|");

    for(int i = 0; i < k; i++)
    {
        if(gantt[i] == -1)
            printf(" IDLE |");
        else
            printf(" P%d |", gantt[i] + 1);
    }

    printf("\n0");

    for(int i = 1; i <= k; i++)
        printf("   %d", i);

    printf("\n");

    return 0;
}