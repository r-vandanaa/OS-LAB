#include <stdio.h>

int main() {
    int m, n, i, j, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m], temp[m];

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n];

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for(i = 0; i < m; i++)
        temp[i] = block[i];

    printf("\nProcess\tBlock\n");

    for(i = 0; i < n; i++) {
        int index = -1;

        if(choice == 1) {  
            for(j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    index = j;
                    break;
                }
            }
        }

        else if(choice == 2) {   
            for(j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    if(index == -1 || temp[j] < temp[index])
                        index = j;
                }
            }
        }

        else if(choice == 3) {   
            for(j = 0; j < m; j++) {
                if(temp[j] >= process[i]) {
                    if(index == -1 || temp[j] > temp[index])
                        index = j;
                }
            }
        }

        if(index != -1) {
            printf("%d\t%d\n", i + 1, index + 1);
            temp[index] -= process[i];
        } else {
            printf("%d\tNot Allocated\n", i + 1);
        }
    }

    return 0;
}