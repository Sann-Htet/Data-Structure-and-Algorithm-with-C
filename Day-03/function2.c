#include<stdio.h>

int nOneC();
char printing();

int main(){
    printf("This is main function!\n");
    int data = nOneC();
    char a = printing();

    printf("This is from n1C func: %d\n", data);
    printf("This is from printing func: %c\n", a);

    // printf("This is from n1C func: %d\n", nOneC());
    // printf("This is from printing func: %c\n", printing());


    return 0;
}

int nOneC(){

    return 10;

}

char printing(){
    return 'a';
}