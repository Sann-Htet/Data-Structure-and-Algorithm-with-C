// Logic 2
#include<stdio.h>

int main(){
    int i = 0;
    int x = 0;
    int ii = 0;
    int size = 10;
    for(i=0; i<size; i++){
        for(x=0; x<=size-i; x++){
            printf(" ");
        }
        for(ii=0; ii<i*2-1; ii++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}