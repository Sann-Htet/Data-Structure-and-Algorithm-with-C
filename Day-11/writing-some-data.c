#include "stdio.h"


int main() {
    FILE *fptr;
    fptr = fopen("n1c.txt", "w"); // overwrite 

    if(fptr == NULL){
        printf("Fail");
    } else {
        printf("Success");
        // char some_data[] = "Myanmar Crazy Coder!";
        // for(int i=0; some_data[i]!='\n'; i++){
        //     fputc(some_data[i], fptr);
        // }
        fprintf(fptr, "Hi");
    }

    fclose(fptr);

    return 0;
}