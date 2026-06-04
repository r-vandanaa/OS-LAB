#include <stdio.h>

int main()
{
    int n, t;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int period[n], burst[n], rem[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter Period and Burst Time for P%d: ",i+1);
        scanf("%d%d",&period[i],&burst[i]);

        rem[i] = burst[i];
    }

    printf("Enter Total Time: ");
    scanf("%d",&t);

    int gantt[100], gt[101];
    int k = 0;

    gt[0] = 0;

    for(int time=0; time<t; time++)
    {
        int p = -1;

        for(int i=0;i<n;i++)
        {
            if(rem[i] > 0)
            {
                if(p==-1 || period[i] < period[p])
                    p = i;
            }
        }

        gantt[k] = p;

        if(p != -1)
            rem[p]--;

        k++;
        gt[k] = time + 1;
    }

    printf("\nGantt Chart:\n|");

    for(int i=0;i<k;i++)
    {
        if(gantt[i]==-1)
            printf(" IDLE |");
        else
            printf(" P%d |",gantt[i]+1);
    }

    printf("\n");

    for(int i=0;i<=k;i++)
        printf("%d\t",gt[i]);

    printf("\n");

    return 0;
}