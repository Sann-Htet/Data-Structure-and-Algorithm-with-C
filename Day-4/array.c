#include<stdio.h>

int main(){
    int myArr[5] = {10, 20, 30, 40, 50};
    myArr[4] = 100;
    printf("First data: %d", myArr[4]);

    return 0;
}