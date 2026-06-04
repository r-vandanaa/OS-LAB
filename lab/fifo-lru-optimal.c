#include <stdio.h>

int main() {
    int n, f, i, j, k, choice;
    int page[50], frame[20], time[20];
    int fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("\n1. FIFO\n2. LRU\n3. Optimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = -1;
    }

    int ptr = 0;   
    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                found = 1;

                if(choice == 2)   
                    time[j] = i;

                break;
            }
        }

        if(!found) {

            if(choice == 1) {
                frame[ptr] = page[i];
                ptr = (ptr + 1) % f;
            }

            else if(choice == 2) {
                int lru = 0;

                for(j = 1; j < f; j++)
                    if(time[j] < time[lru])
                        lru = j;

                frame[lru] = page[i];
                time[lru] = i;
            }
            else if(choice == 3) {
                int pos = 0, farthest = -1;

                for(j = 0; j < f; j++) {
                    int next = 999;

                    for(k = i + 1; k < n; k++) {
                        if(frame[j] == page[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }

                frame[pos] = page[i];
            }

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