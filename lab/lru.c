#include <stdio.h>

int main() {
    int n, f, i, j, page[50], frame[20], time[20];
    int fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }

        if(!found) {
            int lru = 0;

            for(j = 1; j < f; j++)
                if(time[j] < time[lru])
                    lru = j;

            frame[lru] = page[i];
            time[lru] = i;
            fault++;
        }

        printf("%d\t", page[i]);

        for(j = 0; j < f; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}