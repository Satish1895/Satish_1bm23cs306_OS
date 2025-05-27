#include <stdio.h>

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int n = 5, m = 4;

    // First Fit
    printf("First Fit:\n");
    for (int i = 0; i < m; i++) {
        int done = 0;
        for (int j = 0; j < n; j++) {
            if (blocks[j] >= process[i]) {
                printf("P%d -> B%d\n", i + 1, j + 1);
                blocks[j] -= process[i];
                done = 1; break;
            }
        }
        if (!done) printf("P%d -> Not Allocated\n", i + 1);
    }

    // Reset blocks
    int blocks2[] = {100, 500, 200, 300, 600};

    // Best Fit
    printf("\nBest Fit:\n");
    for (int i = 0; i < m; i++) {
        int best = -1;
        for (int j = 0; j < n; j++)
            if (blocks2[j] >= process[i] && (best == -1 || blocks2[j] < blocks2[best]))
                best = j;
        if (best != -1) {
            printf("P%d -> B%d\n", i + 1, best + 1);
            blocks2[best] -= process[i];
        } else printf("P%d -> Not Allocated\n", i + 1);
    }

    // Reset blocks
    int blocks3[] = {100, 500, 200, 300, 600};

    // Worst Fit
    printf("\nWorst Fit:\n");
    for (int i = 0; i < m; i++) {
        int worst = -1;
        for (int j = 0; j < n; j++)
            if (blocks3[j] >= process[i] && (worst == -1 || blocks3[j] > blocks3[worst]))
                worst = j;
        if (worst != -1) {
            printf("P%d -> B%d\n", i + 1, worst + 1);
            blocks3[worst] -= process[i];
        } else printf("P%d -> Not Allocated\n", i + 1);
    }

    return 0;
}

//OUTPUT
First Fit:
P1 -> B2
P2 -> B5
P3 -> B2
P4 -> Not Allocated

Best Fit:
P1 -> B3
P2 -> B5
P3 -> B1
P4 -> B4

Worst Fit:
P1 -> B5
P2 -> B2
P3 -> B2
P4 -> Not Allocated
