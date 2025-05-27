#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define SIMULATION_TIME 20

typedef struct {
    int id;
    int execution_time;
    int period;
    int deadline;
    int remaining_time;
    int next_release;
} Task;

void reset_tasks(Task tasks[], int n) {
    for (int i = 0; i < n; i++) {
        tasks[i].remaining_time = 0;
        tasks[i].next_release = 0;
    }
}

void simulate_rate_monotonic(Task tasks[], int n) {
    printf("\n[Rate Monotonic Scheduling]\n");
    reset_tasks(tasks, n);
    for (int time = 0; time < SIMULATION_TIME; time++) {
        int chosen = -1;
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release) {
                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].next_release += tasks[i].period;
            }
        }
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                if (chosen == -1 || tasks[i].period < tasks[chosen].period)
                    chosen = i;
            }
        }
        if (chosen != -1) {
            printf("Time %2d: Task %d\n", time, tasks[chosen].id);
            tasks[chosen].remaining_time--;
        } else {
            printf("Time %2d: Idle\n", time);
        }
    }
}

void simulate_edf(Task tasks[], int n) {
    printf("\n[Earliest Deadline First Scheduling]\n");
    reset_tasks(tasks, n);
    for (int time = 0; time < SIMULATION_TIME; time++) {
        int chosen = -1;
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release) {
                tasks[i].remaining_time = tasks[i].execution_time;
                tasks[i].deadline = time + tasks[i].period;
                tasks[i].next_release += tasks[i].period;
            }
        }
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                if (chosen == -1 || tasks[i].deadline < tasks[chosen].deadline)
                    chosen = i;
            }
        }
        if (chosen != -1) {
            printf("Time %2d: Task %d\n", time, tasks[chosen].id);
            tasks[chosen].remaining_time--;
        } else {
            printf("Time %2d: Idle\n", time);
        }
    }
}

void main() {
    Task tasks[MAX_TASKS];
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nTask %d:\n", i + 1);
        printf("Execution Time: ");
        scanf("%d", &tasks[i].execution_time);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
    }

    simulate_rate_monotonic(tasks, n);
    simulate_edf(tasks, n);
}
//OUTPUT
Enter number of tasks: 1

Task 1:
Execution Time: 2
Period: 5
[Rate Monotonic Scheduling]
Time  0: Task 1
Time  1: Task 1
Time  2: Idle
Time  3: Idle
Time  4: Idle
Time  5: Task 1
Time  6: Task 1
Time  7: Idle
Time  8: Idle
Time  9: Idle
Time 10: Task 1
Time 11: Task 1
Time 12: Idle
Time 13: Idle
Time 14: Idle
Time 15: Task 1
Time 16: Task 1
Time 17: Idle
Time 18: Idle
Time 19: Idle
[Earliest Deadline First Scheduling]
Time  0: Task 1
Time  1: Task 1
Time  2: Idle
Time  3: Idle
Time  4: Idle
Time  5: Task 1
Time  6: Task 1
Time  7: Idle
Time  8: Idle
Time  9: Idle
Time 10: Task 1
Time 11: Task 1
Time 12: Idle
Time 13: Idle
Time 14: Idle
Time 15: Task 1
Time 16: Task 1
Time 17: Idle
Time 18: Idle
Time 19: Idle
