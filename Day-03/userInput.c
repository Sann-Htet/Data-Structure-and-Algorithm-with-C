#include<stdio.h>

int option();

int main(){
    int opt = option();
    if(opt == 1){
        printf("This is for adding!\n");
    }else if(opt == 2){
        printf("This is for subtract!\n");
    }else if(opt == 3){
        printf("This is for multiplication!\n");
    } else {
        printf("Wrong option!\n");
    };

    return 0;
}

int option(){
    int opt = 0;
    printf("#Enter 1 to add: \n#Enter 2 to sub:\n#Enter 3 to mul:");
    scanf("%d", &opt);

    return opt;
}