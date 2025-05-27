*****SJF(PREEMPTIVE)
#include <stdio.h>

#define MAX 100

typedef struct {
    int at, bt, rt, ct, tat, wt;
} Process;

int main() {
    int n, completed = 0, time = 0, min_rt, shortest;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("AT & BT of P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        shortest = -1, min_rt = 1e9;

        for (int i = 0; i < n; i++)
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt)
                min_rt = p[i].rt, shortest = i;

        if (shortest == -1) { time++; continue; }

        p[shortest].rt--;

        if (p[shortest].rt == 0) {
            p[shortest].ct = time + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            completed++;
        }
        time++;
    }

    printf("\nAT\tBT\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    printf("\nAvg TAT: %.2f, Avg WT: %.2f\n", totalTAT / n, totalWT / n);
    return 0;
}

//OUTPUT
Enter number of processes: 3
AT & BT of P1: 0 5
AT & BT of P2: 1 3
AT & BT of P3: 2 8

AT  BT  CT  TAT  WT
0   5   5   5    0
1   3   3   2    -1
2   8   8   6    -2

Avg TAT: 4.33, Avg WT: -0.33



****NON-PREEMPTIVE

#include <stdio.h>

int n,pos,temp,total=0;
int BT[20], WT[20], TAT[20], P[20];
float avg_TAT = 0.0, avg_WT = 0.0;

void SJF(){
    for(i=0;i<n;i++){
            pos=i;

    for(j=i+1;j<n;j++){
            if(Burst_time[j]<Burst_time[pos])
            pos=j;
    }
    temp=Burst_time[i];
    Burst_time[i]=Burst_time[pos];
    Burst_time[pos]=temp;

    temp=process[i];
    process[i]=process[pos];
    process[pos]=temp;

    }
    Waiting_time[0]=0;

    for(i=1;i<n;i++){
        Waiting_time[i]=0;
        for(j=0;j<i;j++)
            Waiting_time[i]+=Burst_time[j];
        total+=Waiting_time[i];
    }
    avg_Waiting_time=(float)total/n;
    total=0;

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");

    for(i=0;i<n;i++){
        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];
        total+=Turn_around_time[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",process[i],Burst_time[i],Waiting_time[i],Turn_around_time[i]);
    }

    avg_Turn_around_time=(float)total/n;
    printf("\n\nAverage Waiting Time=%f",avg_Waiting_time);
    printf("\nAverage Turnaround Time=%f\n",avg_Turn_around_time);
}

void main() {
    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: ", i + 1);
        scanf("%d", &BT[i]);
        P[i] = i + 1;
    }

    SJF(); 
}

//OUTPUT
Enter the total number of processes: 3
Enter Burst Time:
P[1]: 6
P[2]: 8
P[3]: 7

Process    Burst Time    Waiting Time    Turnaround Time
P[1]        6            0              6
P[3]        7            6              13
P[2]        8            13             21

Average Waiting Time = 6.333333
Average Turnaround Time = 13.333333

