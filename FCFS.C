#include<stdio.h>

int n;
int BT[20],WT[20],TAT[20],P[20];
float avg_TAT=0.0,avg_WT=0.0;

void FCFS(){
    WT[0]=0;

    for(int i=1;i<n;i++){
        WT[i]=0;
        for(int j=0;j<i;j++){
            WT[i]+=BT[j];
        }
    }
    printf("\nProcess\t\tBrust Time\t\tWaiting Time\t\tTurn Around Time");
        for(int i=0;i<n;i++){
            TAT[i]=BT[i]+WT[i];
            avg_WT+=WT[i];
            avg_TAT+=TAT[i];

            printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,BT[i],WT[i],TAT[i]);
        }
        avg_WT=(float)avg_WT/n;
    avg_TAT=(float)avg_TAT/n;

    printf("\nAvg. Waiting time:%.2f",avg_WT);
    printf("\nAvg. Trun Around Time :%.2f",avg_TAT);
}

void main(){
    printf("Enter the total number of processes: ");
    scanf("%d",&n);

    printf("Enter Brust Time:\n");
    for(int i=0;i<n;i++){
        printf("P[%d]:",i+1);
        scanf("%d",&BT[i]);
        P[i]=i+1;
    }

    FCFS();
}

//OUTPUT
Enter the total number of processes: 3
Enter Brust Time:
P[1]: 2
P[2]: 3
P[3]: 4

Process		Burst Time	Waiting Time	Turn Around Time
P[1]		2		0		2
P[2]		3		2		5
P[3]		4		5		9

Avg. Waiting time: 2.33
Avg. Turn Around Time: 5.33
