// fifo_paging.c
// Simulates FIFO page replacement.
// Input: number of frames, number of reference pages, sequence of page references.

#include <stdio.h>

int main() {
    int frames, n;
    printf("Number of frames: ");
    scanf("%d", &frames);
    printf("Number of page references: ");
    scanf("%d", &n);

    int ref[n];
    printf("Enter page reference sequence (space separated):\n");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);

    int frame[frames];
    for (int i=0;i<frames;i++) frame[i] = -1;
    int ptr = 0; // points to next frame to replace (FIFO)
    int faults = 0;

    printf("\nStep\tReference\tFrames\t\tHit/Fault\n");
    for (int i = 0; i < n; i++) {
        int page = ref[i];
        int hit = 0;
        for (int j = 0; j < frames; j++) if (frame[j] == page) { hit = 1; break; }

        if (!hit) {
            frame[ptr] = page;
            ptr = (ptr + 1) % frames;
            faults++;
        }
        printf("%2d\t%8d\t", i+1, page);
        for (int j=0;j<frames;j++) {
            if(frame[j]==-1) printf(" - ");
            else printf(" %d ", frame[j]);
        }
        printf("\t%s\n", hit ? "Hit" : "Fault");
    }

    printf("\nTotal page faults = %d\n", faults);
    return 0;
}
