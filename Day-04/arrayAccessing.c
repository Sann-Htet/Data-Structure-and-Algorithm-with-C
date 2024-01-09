#include<stdio.h>

int main(){
    int i = 0;
    int arrSize = 5;
    int myArr[5];
    // int myArr[5] = {10, 20, 30, 40, 50};

    for(i=0; i<arrSize; i++){
        printf("Enter Data for Index: %d: ", i);
        scanf("%d", &myArr[i]);
    }

    for(i=0; i<arrSize; i++){
        printf("Printing data: %d\n", myArr[i]);
    }

    return 0;
}