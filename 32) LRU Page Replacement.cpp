// lru_paging.c
// Simulates LRU page replacement using usage timestamps.
// Input: number of frames, number of references, sequence of pages.

#include <stdio.h>
#include <limits.h>

int main() {
    int frames, n;
    printf("Number of frames: ");
    scanf("%d", &frames);
    printf("Number of page references: ");
    scanf("%d", &n);

    int ref[n];
    printf("Enter page reference sequence:\n");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);

    int frame[frames];
    int last_used[frames]; // timestamp of last use
    for (int i=0;i<frames;i++){ frame[i] = -1; last_used[i] = -1; }

    int time = 0, faults = 0;
    printf("\nStep\tRef\tFrames\t\tHit/Fault\n");
    for (int i=0;i<n;i++){
        int p = ref[i]; time++;
        int hit = -1;
        for (int j=0;j<frames;j++) if(frame[j]==p){ hit = j; break; }

        if(hit != -1){
            last_used[hit] = time;
        } else {
            // find empty or LRU
            int idx = -1;
            for(int j=0;j<frames;j++) if(frame[j]==-1){ idx=j; break; }
            if(idx == -1){
                int lru_time = INT_MAX;
                for(int j=0;j<frames;j++){
                    if(last_used[j] < lru_time){ lru_time = last_used[j]; idx = j; }
                }
            }
            frame[idx] = p; last_used[idx] = time; faults++;
        }

        printf("%2d\t%3d\t", i+1, p);
        for(int j=0;j<frames;j++){
            if(frame[j]==-1) printf(" - ");
            else printf(" %d ", frame[j]);
        }
        printf("\t%s\n", (hit!=-1) ? "Hit" : "Fault");
    }

    printf("\nTotal page faults = %d\n", faults);
    return 0;
}
