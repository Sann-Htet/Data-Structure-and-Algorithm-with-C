// Looping -> while loop / do while
#include<stdio.h> // standard input output .h (header file)

int main(){
    int i = 0;
    int counter = 1;

    // for(i=0; i<10; i++){
    //     printf("Hello: %d\n", i);
    // }

    while(i<10){
        printf("Counter = %d\n", counter);
        printf("Hello\n");
        i++;
        counter++;
    }
    


    return 0;
}