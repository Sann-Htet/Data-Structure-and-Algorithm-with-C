#include "stdio.h"

void pass_value(int a, int b);

int main(){
    int a = 10;
    int b = 20;
    printf("This is main func!\n");
    printf("Before function call : a=%d b=%d\n", a, b);
    pass_value(a, b);
    printf("After calling function!\n");
    printf("Values a=%d b=%d\n", a, b);

    return 0;
}

void pass_value(int a, int b){
    // printf("%d %d\n", a, b);
    a++;
    b++;
    int c = a + b;
}