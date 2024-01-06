#include<stdio.h>

int main(){
    int a = 10;
    int *ptr = &a;
    printf("A value: %d\n", a);
    printf("A memory address: %x\n", ptr);
    printf("Pointer value: %d\n", *ptr);
    printf("Pointer memory address: %x\n", ptr);
    printf("Pointer address: %x\n", &ptr);

    return 0;
}