// optimal_paging.c
// Simulates Optimal page replacement (looks ahead).
// Input: number of frames, number of references, reference sequence.

#include <stdio.h>
#include <limits.h>

int find_optimal_victim(int frame[], int frames, int ref[], int n, int idx) {
    int victim = -1, farthest = idx;
    for (int i = 0; i < frames; i++) {
        if (frame[i] == -1) return i; // empty frame
        int j;
        for (j = idx; j < n; j++) if (ref[j] == frame[i]) break;
        if (j == n) return i; // won't be used again -> best victim
        if (j > farthest) { farthest = j; victim = i; }
    }
    return victim == -1 ? 0 : victim;
}

int main() {
    int frames, n;
    printf("Number of frames: ");
    scanf("%d",&frames);
    printf("Number of references: ");
    scanf("%d",&n);
    int ref[n];
    printf("Enter reference string:\n");
    for (int i=0;i<n;i++) scanf("%d",&ref[i]);

    int frame[frames]; for(int i=0;i<frames;i++) frame[i] = -1;
    int faults = 0;

    printf("\nStep\tRef\tFrames\t\tHit/Fault\n");
    for (int i=0;i<n;i++){
        int p = ref[i], hit = 0;
        for (int j=0;j<frames;j++) if(frame[j]==p){ hit=1; break; }
        if(!hit){
            int victim = find_optimal_victim(frame, frames, ref, n, i+1);
            frame[victim] = p;
            faults++;
        }
        printf("%2d\t%3d\t", i+1, p);
        for(int j=0;j<frames;j++){
            if(frame[j]==-1) printf(" - ");
            else printf(" %d ", frame[j]);
        }
        printf("\t%s\n", hit ? "Hit":"Fault");
    }

    printf("\nTotal page faults = %d\n", faults);
    return 0;
}
