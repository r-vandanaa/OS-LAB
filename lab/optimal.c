#include <stdio.h>

int main() {
    int n, f, i, j, k, page[50], frame[20];
    int fault = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int pos = -1, farthest = -1;

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