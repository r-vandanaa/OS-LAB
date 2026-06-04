#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, slices;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int tickets[n];
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        printf("Enter tickets for P%d: ", i + 1);
        scanf("%d", &tickets[i]);

        total += tickets[i];
    }

    printf("Enter number of time slices: ");
    scanf("%d", &slices);

    srand(time(NULL));

    int gantt[100];
    int times[101];

    times[0] = 0;

    for(int t = 0; t < slices; t++)
    {
        int winner = rand() % total + 1;

        int sum = 0;
        int p = -1;

        for(int i = 0; i < n; i++)
        {
            sum += tickets[i];

            if(winner <= sum)
            {
                p = i;
                break;
            }
        }

        printf("Time %d -> P%d\n", t, p + 1);

        gantt[t] = p;
        times[t + 1] = t + 1;
    }

    printf("\nGantt Chart:\n\n|");

    for(int i = 0; i < slices; i++)
        printf(" P%d |", gantt[i] + 1);

    printf("\n");

    for(int i = 0; i <= slices; i++)
        printf("%d\t", times[i]);

    printf("\n");

    return 0;
}