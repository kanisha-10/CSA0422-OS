#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, bt, rt;
} Process;

int main() {
    int tq = 3;
    Process p[] = {{1,10,10},{2,5,5},{3,8,8}};
    int n = 3, time = 0, done;

    printf("Gantt Chart: ");

    do {
        done = 1;

        for(int i=0;i<n;i++){
            if(p[i].rt > 0){
                done = 0;

                if(p[i].rt > tq){
                    printf("P%d ", p[i].pid);
                    time += tq;
                    p[i].rt -= tq;
                } else {
                    printf("P%d ", p[i].pid);
                    time += p[i].rt;
                    p[i].rt = 0;
                }
            }
        }

    } while(!done);

    printf("\n");
    system("pause");
    return 0;
}
