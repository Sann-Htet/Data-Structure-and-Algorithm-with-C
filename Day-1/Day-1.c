//Adding program by N1C
#include<stdio.h>

int main(){
    int age = 0;
    int first_number = 0;
    int sec_number = 0;
    int total = 0;
    printf("Hello coder\nDSA\n"); // \n = new line character
    printf("This is from N1C");
    
    //printf("Please enter you age:");
    //scanf("%d", &age); // d = decimal
    //printf("Your age = %d", age); // %x = hexadecimal
    
    printf("This program is for add:\n");
    printf("Enter you first number:");
    scanf("%d", &first_number);

    printf("Enter you second number:");
    scanf("%d", &sec_number);

    total = first_number + sec_number;

    printf("Your total number: %d", total);
    
    return 0;
}