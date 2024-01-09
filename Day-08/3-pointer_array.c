#include<stdio.h>

int main(){
    int arr[5]={10, 20, 30, 40, 50};
    int *ptr = arr;

    for(int i=0; i<5; i++){
        printf("Value %d\n", &ptr[i]);
    }

    return 0;
}