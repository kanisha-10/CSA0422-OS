// file: single_level_dir.c
#include <stdio.h>
#include <string.h>

#define MAXFILES 50
#define NAMELEN 40

char dir[MAXFILES][NAMELEN];
int file_count = 0;

void create_file(char *name){
    if(file_count >= MAXFILES){ printf("Directory full\n"); return; }
    strcpy(dir[file_count++], name);
    printf("File '%s' created.\n", name);
}
void delete_file(char *name){
    for(int i=0;i<file_count;i++){
        if(strcmp(dir[i], name) == 0){
            for(int j=i;j<file_count-1;j++) strcpy(dir[j], dir[j+1]);
            file_count--; printf("Deleted '%s'\n", name); return;
        }
    }
    printf("File '%s' not found\n", name);
}
void list_files(){
    if(file_count == 0) { printf("Directory is empty\n"); return; }
    printf("Files:\n");
    for(int i=0;i<file_count;i++) printf("%s\n", dir[i]);
}

int main(){
    int choice; char name[NAMELEN];
    while(1){
        printf("\n1-Create 2-Delete 3-List 4-Exit : ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter filename: "); scanf("%s", name);
            create_file(name);
        } else if(choice == 2){
            printf("Enter filename to delete: "); scanf("%s", name);
            delete_file(name);
        } else if(choice == 3){
            list_files();
        } else break;
    }
    return 0;
}
