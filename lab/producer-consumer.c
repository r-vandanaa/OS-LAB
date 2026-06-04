#include <stdio.h>

int mutex = 1;
int full = 0;
int empty;

void wait(int *s)
{
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

int main()
{
    int bufferSize, produce, consume;

    printf("Enter Buffer Size: ");
    scanf("%d", &bufferSize);

    empty = bufferSize;

    printf("Enter Number of Items to Produce: ");
    scanf("%d", &produce);

    printf("Enter Number of Items to Consume: ");
    scanf("%d", &consume);

    if(produce <= empty)
    {
        wait(&empty);
        wait(&mutex);

        full += produce;
        empty = empty + produce - 1;

        printf("\nProduced %d items", produce);

        signal(&mutex);
        signal(&full);
    }
    else
    {
        printf("\nBuffer Full");
        return 0;
    }

    if(consume <= full)
    {
        wait(&full);
        wait(&mutex);

        full = full - consume + 1;
        empty += consume;

        printf("\nConsumed %d items", consume);

        signal(&mutex);
        signal(&empty);
    }
    else
    {
        printf("\nBuffer Empty");
        return 0;
    }

    printf("\n\nFinal Status:");
    printf("\nFull  = %d", full);
    printf("\nEmpty = %d", empty);

    return 0;
}