#include "stdio.h"

int main(){
    FILE *fptr;

    fopen("sann.txt", "a");

    if(fptr == NULL){
        perror("\n");
    }

}