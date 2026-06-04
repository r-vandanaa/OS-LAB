#include <stdio.h>

int main()
{
    int n, i;
    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    ct[0] = at[0] + bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT += tat[i];
        avgWT += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT / n);
    printf("\nAverage WT  = %.2f\n", avgWT / n);
    
    printf("\nGantt Chart:\n");
    
    printf("|");
    
    for(i = 0; i < n; i++)
    {
        if(i > 0 && ct[i-1] < at[i])
            printf(" IDLE |");
    
        printf(" P%d |", i + 1);
    }
    
    printf("\n");
    
    printf("%d", at[0]);
    
    for(i = 0; i < n; i++)
    {
        if(i > 0 && ct[i-1] < at[i])
            printf("    %d", at[i]);
    
        printf("    %d", ct[i]);
    }
    
    printf("\n");
    return 0;
}