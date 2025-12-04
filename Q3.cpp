#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, at, bt, wt, tat, done;
} Process;

int main() {
    Process p[] = {{1,0,8,0,0,0},{2,1,4,0,0,0},{3,2,2,0,0,0},{4,3,1,0,0,0}};
    int n = 4, time = 0, completed = 0;

    while(completed < n){
        int idx = -1, min_bt = 999;

        for(int i=0;i<n;i++)
            if(!p[i].done && p[i].at <= time && p[i].bt < min_bt){
                min_bt = p[i].bt;
                idx = i;
            }

        if(idx == -1){
            time++;
            continue;
        }

        p[idx].wt = time - p[idx].at;
        time += p[idx].bt;
        p[idx].tat = p[idx].wt + p[idx].bt;
        p[idx].done = 1;
        completed++;
    }

    printf("PID\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);

    system("pause");
    return 0;
}
