#include <stdio.h>

int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5}, n = 12, f = 3;

void FIFO() {
    int frame[3] = {-1,-1,-1}, j=0, pf=0;
    for(int i=0;i<n;i++) {
        int hit=0;
        for(int k=0;k<f;k++) if(frame[k]==pages[i]) hit=1;
        if(!hit) { frame[j]=pages[i]; j=(j+1)%f; pf++; }
    }
    printf("FIFO Page Faults = %d\n", pf);
}

void LRU() {
    int frame[3] = {-1,-1,-1}, time[3]={0}, t=0, pf=0;
    for(int i=0;i<n;i++,t++) {
        int hit=0;
        for(int j=0;j<f;j++) if(frame[j]==pages[i]) { time[j]=t; hit=1; }
        if(!hit) {
            int lru=0;
            for(int j=1;j<f;j++) if(time[j]<time[lru]) lru=j;
            frame[lru]=pages[i]; time[lru]=t; pf++;
        }
    }
    printf("LRU Page Faults = %d\n", pf);
}

void Optimal() {
    int frame[3] = {-1,-1,-1}, pf=0;
    for(int i=0;i<n;i++) {
        int hit=0;
        for(int j=0;j<f;j++) if(frame[j]==pages[i]) hit=1;
        if(hit) continue;
        int idx=-1, far=-1;
        for(int j=0;j<f;j++) {
            int k;
            for(k=i+1;k<n;k++) if(frame[j]==pages[k]) break;
            if(k>far) { far=k; idx=j; }
        }
        frame[(idx==-1)?0:idx]=pages[i]; pf++;
    }
    printf("Optimal Page Faults = %d\n", pf);
}

int main() {
    FIFO();
    LRU();
    Optimal();
    return 0;
}

//OUTPUT
FIFO Page Faults = 9
LRU Page Faults = 8
Optimal Page Faults = 7
