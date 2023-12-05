#include<stdio.h>

int main(){
    printf("Hello N1C");

    int first_number = 0;
    int sec_number = 0;
    int total = 0;
    int age = 0;
    
    //printf("This program is for add:\n");
    //printf("Enter you first number:");
    //scanf("%d", &first_number);

    //printf("Enter you second number:");
    //scanf("%d", &sec_number);

    //total = first_number + sec_number;

    //printf("Your total number: %d", total);

    printf("Enter you age: ");
    scanf("%d", &age);

    if(age > 18){ // curly brace for defining scope
        printf("Your age is over 19.");
    } else {
        printf("Your age is under 18.\n");
    }

    // looping
    int count = 0;
    int i = 0;
    for(i=0; i<10; i++){
        printf("Looping Counting: %d\n", i);
        printf("Count = %d\n", count);
        count++;
    }

    //Programming logic
    for(i=0; i<10; i++){
        printf("*");
        for(int x=0; x<i; x++){
            printf("#");
        }
        printf("\n");
    }


    return 0;
}