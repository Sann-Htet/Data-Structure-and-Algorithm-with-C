#include<stdio.h>

struct Data{
    char user_name[20]; //user name
    char user_email[40];
    char user_password[20];
    int phone;
};

struct Data db[1000];
int main(){
    int i = 0;
    for(i=0; i<3; i++){
        printf("Enter your user name: ");
        scanf(" %[^\n]", &db[i].user_name);

        printf("Enter your user email: ");
        scanf(" %[^\n]", &db[i].user_email);

        printf("Enter your user password: ");
        scanf(" %[^\n]", &db[i].user_password);

        printf("Enter your phone: ");
        scanf("%d", &db[i].phone);
    }

    for(i=0; i<3; i++){
        printf("User Name: %s\n", db[i].user_name);
        printf("User Email: %s\n", db[i].user_email);
        printf("User Password: %s\n", db[i].user_password);
        printf("User Phone: %d\n", db[i].phone);
    }

    return 0;
}