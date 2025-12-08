// file: two_level_dir.c
#include <stdio.h>
#include <string.h>

#define MAX_USERS 20
#define MAXFILES 50
#define UNAMELEN 30
#define FNAMELEN 40

typedef struct {
    char uname[UNAMELEN];
    char files[MAXFILES][FNAMELEN];
    int fcount;
} User;

User users[MAX_USERS];
int ucount = 0;

int find_user(char *name){
    for(int i=0;i<ucount;i++) if(strcmp(users[i].uname, name)==0) return i;
    return -1;
}

void create_user(char *name){
    if(find_user(name) != -1){ printf("User exists\n"); return; }
    strcpy(users[ucount].uname, name);
    users[ucount].fcount = 0; ucount++;
    printf("User '%s' created\n", name);
}
void add_file(char *uname, char *fname){
    int idx = find_user(uname);
    if(idx == -1){ printf("User not found\n"); return; }
    int fc = users[idx].fcount;
    strcpy(users[idx].files[fc], fname); users[idx].fcount++;
    printf("File '%s' added to user '%s'\n", fname, uname);
}
void list_user(char *uname){
    int idx = find_user(uname);
    if(idx == -1){ printf("User not found\n"); return; }
    if(users[idx].fcount == 0) { printf("No files\n"); return; }
    printf("Files of %s:\n", uname);
    for(int i=0;i<users[idx].fcount;i++) printf("%s\n", users[idx].files[i]);
}

int main(){
    int ch; char uname[UNAMELEN], fname[FNAMELEN];
    while(1){
        printf("\n1-CreateUser 2-AddFile 3-ListFiles 4-Exit: "); scanf("%d",&ch);
        if(ch==1){ printf("Username: "); scanf("%s", uname); create_user(uname); }
        else if(ch==2){ printf("Username: "); scanf("%s", uname); printf("Filename: "); scanf("%s", fname); add_file(uname, fname); }
        else if(ch==3){ printf("Username: "); scanf("%s", uname); list_user(uname); }
        else break;
    }
    return 0;
}
