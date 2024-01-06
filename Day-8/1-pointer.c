#include<stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    printf("%d\n", a);
    printf("%x", *ptr);

    return 0;
}