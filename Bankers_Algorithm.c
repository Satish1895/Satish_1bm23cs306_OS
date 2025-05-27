#include <stdio.h>

#define MAX 10

int main() {
    int n, m;
    int alloc[MAX][MAX], max[MAX][MAX], avail[MAX];
    int need[MAX][MAX], finish[MAX];
    int request[MAX], pid;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Need Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("Enter process number making the request (0 to %d): ", n - 1);
    scanf("%d", &pid);
    printf("Enter request for process P%d:\n", pid);
    for (int j = 0; j < m; j++)
        scanf("%d", &request[j]);

    int valid = 1;
    for (int j = 0; j < m; j++) {
        if (request[j] > need[pid][j] || request[j] > avail[j]) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("Request exceeds need or available resources. Denied.\n");
        return 0;
    }

    for (int j = 0; j < m; j++) {
        avail[j] -= request[j];
        alloc[pid][j] += request[j];
        need[pid][j] -= request[j];
    }

    for (int i = 0; i < n; i++) finish[i] = 0;
    int work[MAX];
    for (int j = 0; j < m; j++) work[j] = avail[j];

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j]) break;
                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) break;
    }

    if (count == n)
        printf("Request can be granted safely. No deadlock.\n");
    else
        printf("Request would lead to unsafe state. Denied to avoid deadlock.\n");

    return 0;
}
//OUTPUT
Enter number of processes: 5
Enter number of resource types: 3

Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Enter Maximum Need Matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter Available Resources:
3 3 2

Enter process number making the request (0 to 4): 1
Enter request for process P1:
1 0 2

Request can be granted safely. No deadlock.

  
