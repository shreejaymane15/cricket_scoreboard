// sample code -- for reference
#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[64];
    float marks;
};

struct student arr[9];

int main() {
    FILE *fp;
    int i;

    fp = fopen("students.txt", "r");
    if(fp == NULL) {
        perror("error in opening file.");
        exit(1);
    }

    for(i=0; i<9; i++) {
        arr[i].roll = i+1;
        fgets(arr[i].name, 64, fp);
    }

    for(i=0; i<9; i++)
        printf("%d. %s\n", arr[i].roll, arr[i].name);

    fclose(fp);
    return 0;
}
