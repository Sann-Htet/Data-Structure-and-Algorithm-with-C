#include "stdio.h"

void reference(int *a, int *b);

int main(){
    int a = 100;
    int b = 200;
    printf("Before call: a=%d, b=%d\n", a, b);
    reference(&a, &b);
    printf("After call: a=%d, b=%d\n", a, b);


    return 0;
}

void reference(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}