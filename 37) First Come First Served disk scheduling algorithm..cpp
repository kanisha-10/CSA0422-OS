#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, totalMovement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk requests (cylinder numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling\n");
    printf("Head Movement Sequence:\n");

    int current = head;

    for (i = 0; i < n; i++) {
        printf("%d -> %d\n", current, request[i]);
        totalMovement += abs(request[i] - current);
        current = request[i];
    }

    printf("\nTotal Head Movement = %d cylinders\n", totalMovement);

    return 0;
}
