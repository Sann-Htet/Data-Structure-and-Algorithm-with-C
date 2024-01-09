// function -> 1. Standard Library Function 2 - Programmer Defined Functions
#include<stdio.h>

void nOneC();
void printing();

int main(){
    printf("This is main function!\n");
    nOneC();
    printing();

    return 0;
}

void nOneC(){
    printf("Hello This is N1C function!\n");
}

void printing(){
    printf("This is from printing function!\n");
}