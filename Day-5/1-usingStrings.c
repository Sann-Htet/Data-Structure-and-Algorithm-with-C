#include<stdio.h>

struct Data{
    char name[20]; //user name
};

int main(){
    char myName[20];
    printf("Please enter your name:");
    scanf(" %[^\n]", &myName);

    printf("This is your name: %s", myName);

    return 0;
}