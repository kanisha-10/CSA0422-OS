// file: mem_alloc_strategies.c
#include <stdio.h>
#include <limits.h>

void print_alloc(int alloc[], int n) {
    printf("\nProcess\tSize\tBlockAllocated\n");
    for(int i=0;i<n;i++){
        if(alloc[i] == -1) printf("P%d\t%d\tNot Allocated\n", i+1, alloc[i]==-1?0:0); // size printed separately
    }
}
int main(){
    int m,n;
    printf("Number of memory blocks: "); scanf("%d",&m);
    int blocks[m]; for(int i=0;i<m;i++){ printf("Block %d size: ", i+1); scanf("%d",&blocks[i]); }
    printf("Number of processes: "); scanf("%d",&n);
    int proc[n]; for(int i=0;i<n;i++){ printf("Process %d size: ", i+1); scanf("%d",&proc[i]); }

    int choice; 
    printf("Choose strategy: 1-First Fit, 2-Best Fit, 3-Worst Fit: "); scanf("%d",&choice);

    int alloc[n]; for(int i=0;i<n;i++) alloc[i] = -1;
    int temp[m]; for(int i=0;i<m;i++) temp[i]=blocks[i];

    if(choice == 1){ // First Fit
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[j] >= proc[i]) { alloc[i]=j; temp[j]-=proc[i]; break; }
            }
        }
    } else if(choice == 2){ // Best Fit
        for(int i=0;i<n;i++){
            int best=-1, bestSize=INT_MAX;
            for(int j=0;j<m;j++){
                if(temp[j] >= proc[i] && temp[j] < bestSize){ bestSize=temp[j]; best=j; }
            }
            if(best!=-1){ alloc[i]=best; temp[best]-=proc[i]; }
        }
    } else if(choice == 3){ // Worst Fit
        for(int i=0;i<n;i++){
            int worst=-1, worstSize=-1;
            for(int j=0;j<m;j++){
                if(temp[j] >= proc[i] && temp[j] > worstSize){ worstSize=temp[j]; worst=j; }
            }
            if(worst!=-1){ alloc[i]=worst; temp[worst]-=proc[i]; }
        }
    } else { printf("Invalid choice\n"); return 0; }

    printf("\nProcess\tSize\tBlockAllocated\n");
    for(int i=0;i<n;i++){
        if(alloc[i] == -1) printf("P%d\t%d\tNot Allocated\n", i+1, proc[i]);
        else printf("P%d\t%d\tB%d\n", i+1, proc[i], alloc[i]+1);
    }
    return 0;
}
