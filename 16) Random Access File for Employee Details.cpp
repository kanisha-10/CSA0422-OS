// file: employee_random_access.c
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    float salary;
} Emp;

int main(){
    FILE *fp = fopen("employees.bin", "r+b");
    if(!fp) fp = fopen("employees.bin", "w+b");

    int choice;
    while(1){
        printf("\n1-Add Emp 2-Read Emp By RecordNo 3-Exit: ");
        scanf("%d",&choice);
        if(choice == 1){
            Emp e;
            printf("Enter id name salary: ");
            scanf("%d %s %f", &e.id, e.name, &e.salary);
            fseek(fp, 0, SEEK_END);
            fwrite(&e, sizeof(Emp), 1, fp);
            fflush(fp);
            printf("Saved.\n");
        } else if(choice == 2){
            int rec;
            printf("Enter record number (0-based): "); scanf("%d", &rec);
            fseek(fp, rec * sizeof(Emp), SEEK_SET);
            Emp e;
            if(fread(&e, sizeof(Emp), 1, fp) == 1){
                printf("Id: %d Name: %s Salary: %.2f\n", e.id, e.name, e.salary);
            } else printf("No record at that position.\n");
        } else break;
    }
    fclose(fp);
    return 0;
}
