// contiguous_allocation.c
// Simulates contiguous allocation of file records.
// Input: file size (number of records), start block, and simulate accessing a record
// Accessing record i must read 0..i (sequential access cost).

#include <stdio.h>

int main() {
    int total_blocks, file_size, start_block;
    printf("Enter total disk blocks available: ");
    scanf("%d",&total_blocks);
    printf("File size (number of consecutive records): ");
    scanf("%d",&file_size);
    printf("Start block index for file (0-based): ");
    scanf("%d",&start_block);

    if (start_block < 0 || start_block + file_size > total_blocks) {
        printf("Error: file does not fit contiguously in disk.\n");
        return 0;
    }

    printf("File stored in blocks %d to %d (contiguous).\n", start_block, start_block + file_size - 1);
    int access_index;
    printf("Enter record index to access (0 is first record): ");
    scanf("%d",&access_index);
    if(access_index < 0 || access_index >= file_size){
        printf("Invalid record index.\n"); return 0;
    }

    // to access record k, must read k+1 records
    printf("To access record %d, must read %d records sequentially (from start).\n",
           access_index, access_index + 1);
    printf("Blocks read: ");
    for(int i = start_block; i <= start_block + access_index; i++){
        if(i > start_block) printf(" -> ");
        printf("%d", i);
    }
    printf("\n");
    return 0;
}
