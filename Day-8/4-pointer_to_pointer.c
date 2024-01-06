#include<stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    int **pptr;

    pptr = &ptr;

    printf("Value of a: %d\n", a);
    printf("Address of a: %d\n", &a);
    printf("Value of ptr: %d\n", *ptr);
    printf("Address of ptr: %d\n", &ptr);
    printf("Value of pptr: %d\n", *pptr);
    printf("Address of pptr: %d\n", &pptr);
    return 0;
}