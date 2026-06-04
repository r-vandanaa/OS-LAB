#include <stdio.h>

int main() {
    int n, f, i, j, page[50], frame[20];
    int fault = 0, k = 0, found;

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
        found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            frame[k] = page[i];
            k = (k + 1) % f;
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