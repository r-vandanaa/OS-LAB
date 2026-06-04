#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of philosophers: ");
    scanf("%d", &n);

    int fork[n];
    for(int i = 0; i < n; i++)
        fork[i] = 1;

    for(int i = 0; i < n; i++)
    {
        int left = i;
        int right = (i + 1) % n;

        printf("\nPhilosopher %d is Thinking\n", i + 1);

        if(fork[left] && fork[right])
        {
            fork[left] = 0;
            fork[right] = 0;

            printf("Philosopher %d takes Fork %d and Fork %d\n",
                   i + 1, left + 1, right + 1);

            printf("Philosopher %d is Eating\n", i + 1);

            fork[left] = 1;
            fork[right] = 1;

            printf("Philosopher %d puts down Fork %d and Fork %d\n",
                   i + 1, left + 1, right + 1);
        }
        else
        {
            printf("Forks not available\n");
        }
    }

    return 0;
}
