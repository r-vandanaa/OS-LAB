#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&m);

    int alloc[n][m], req[n][m];
    int avail[m], finish[n] = {0};

    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("\nEnter Request Matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("\nEnter Available Resources:\n");
    for(int j=0;j<m;j++)
        scanf("%d",&avail[j]);

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(int i=0;i<n;i++)
        {
            if(!finish[i])
            {
                int ok = 1;

                for(int j=0;j<m;j++)
                {
                    if(req[i][j] > avail[j])
                    {
                        ok = 0;
                        break;
                    }
                }

                if(ok)
                {
                    for(int j=0;j<m;j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    if(count == n)
        printf("\nNo Deadlock");
    else
        printf("\nDeadlock Detected");

    return 0;
}