#include "stdio.h"


int main() {
    FILE *fptr;
    fptr = fopen("n1c.txt", "r"); // overwrite 

    if(fptr == NULL){
        printf("Fail");
    } else {
        printf("Success");
    }

    return 0;
}