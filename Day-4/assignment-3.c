#include<stdio.h>

int option();

int main(){
    int num1 = 0;
    int num2 = 0;
    int total = 0;
    int opt = option();

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    if(opt == 1){
        total = adding(num1, num2);
    }else if(opt == 2){
        total = sub(num1, num2);
    }else if(opt == 3){
        total = multiplication(num1, num2);
    }else if(opt == 4){
        total = division(num1, num2);
    } else {
        printf("Wrong option!\n");
    };

    printf("The result is: %d", total);

    return 0;
}

int option(){
    int opt = 0;
    printf("#Enter 1 to add: \n#Enter 2 to sub:\n#Enter 3 to mul:\n#Enter 4 to divide: ");
    scanf("%d", &opt);

    return opt;
}

int adding(int num1, int num2){
    int total = num1 + num2;
    return total;
}

int sub(int num1, int num2){
    int total = num1 - num2;
    return total;
}

int multiplication(int num1, int num2){
    int total = num1 * num2;
    return total;
}

int division(int num1, int num2){
    int total = num1 / num2;
    return total;
}