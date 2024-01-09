#include<stdio.h>

void copy_two_charArray(char first[30], char second[30]);
void registration();

struct Db{
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
};

struct Db data[10];


int main(){
    registration();

    return 0;
}

void registration(){
    char r_username[30];
    char r_useremail[30];
    char r_userpassword[20];
    int r_phoneNumber = 0;

    printf("\nThis is Registration Option:\n");
    printf("Enter your user name to register: ");
    scanf(" %[^\n]", &r_username);
    printf("Enter your user email to register: ");
    scanf(" %[^\n]", &r_useremail);
    printf("Enter your user password to register: ");
    scanf(" %[^\n]", &r_userpassword);
    printf("Enter your user ph number to register: ");
    scanf("%d", &r_phoneNumber);

    // collecting
    copy_two_charArray(data[0].user_name, r_username);
    printf("\nChecking for username: %s\n", data[0].user_name);

    copy_two_charArray(data[0].user_email, r_useremail);
    printf("Checking for username: %s\n", data[0].user_email);

    copy_two_charArray(data[0].user_pass, r_userpassword);
    printf("Checking for username: %s\n", data[0].user_pass);

    data[0].phone_number = r_phoneNumber;
    printf("Checking for Phone number: %d\n", data[0].phone_number);
}

void copy_two_charArray(char first[30], char second[30]){
    int i = 0;
    for(i=0; i<30; i++){
        
        if(second[i] == "\0"){

        } else {
            first[i] = second[i];
        }
    }
}