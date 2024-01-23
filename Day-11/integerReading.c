#include "stdio.h"

int main(){
    FILE *fptr;
    int number;

    fptr = fopen("sann.txt", "r");
    if(fptr=NULL){
        perror("\n");
        return -1;
    }

    while(fscanf(fptr, "%d", &number) != EOF){
        printf("%d\n", number);
    }
    fclose(fptr);
    return 0;
}