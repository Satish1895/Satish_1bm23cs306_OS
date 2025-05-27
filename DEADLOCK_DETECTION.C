#include <stdio.h>

#define MAX 10

int main() {
    int n, m;
    int alloc[MAX][MAX], request[MAX][MAX], avail[MAX];
    int finish[MAX] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Deadlock Detection Algorithm
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (request[i][j] > avail[j])
                        break;
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) break;
    }

    int deadlock = 0;
    printf("\nProcesses in Deadlock:\n");
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("P%d ", i);
            deadlock = 1;
        }
    }
    if (!deadlock)
        printf("None. No deadlock detected.\n");

    return 0;
}

//OUTPUT
Enter number of processes: 3
Enter number of resource types: 2

Enter Allocation Matrix:
1 2
2 0
3 1

Enter Request Matrix:
1 0
0 1
2 1

Enter Available Resources:
0 0
//with Deadlock
Processes in Deadlock:
P0 P1 P2

//if Safe
Processes in Deadlock:
None. No deadlock detected.
