#include <stdio.h>

int main()
{
    int n, m;

    printf("Processes: ");
    scanf("%d",&n);

    printf("Resources: ");
    scanf("%d",&m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n] = {0};

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    for(int j=0;j<m;j++)
        scanf("%d",&avail[j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nSafe Sequence: ");

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
                    if(need[i][j] > avail[j])
                    {
                        ok = 0;
                        break;
                    }
                }

                if(ok)
                {
                    printf("P%d ",i);

                    for(int j=0;j<m;j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if(!found)
        {
            printf("\nUnsafe State");
            return 0;
        }
    }

    printf("\nSafe State");
    return 0;
}