#include <stdio.h>

int main() {
    int m, n, i, j, worst;
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    
    int block[m];
    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n];
    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    printf("\nProcess\tBlock\n");

    for(i = 0; i < n; i++) {
        worst = -1;

        for(j = 0; j < m; j++) {
            if(block[j] >= process[i]) {
                if(worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if(worst != -1) {
            printf("%d\t%d\n", i + 1, worst + 1);
            block[worst] -= process[i];
        } else {
            printf("%d\tNot Allocated\n", i + 1);
        }
    }

    return 0;
}