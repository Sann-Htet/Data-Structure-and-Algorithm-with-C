#include "stdio.h"
#include "stdlib.h"

//function declare
void copy_two_charArray(char first[30],char second[30]);
void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int compare_two_char_array(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
void my_privilege(int user_id);
void user_info_change(int user_id);
int email_scanner(char to_check_email[30]);
int email_valid_two(char to_valid_email[30]);
int is_strong_password(char password[20]);
void points_fun(int user_id);
void record_data();
void retrieve_data();
void update_record_file();
void view_all_user_information();
void view_all_transaction_records();

//Global Var
int g_userCount=0; // count how many user
int g_login_check=-1;
int email_validation=-1; // to check email
int total_points=500; //user point

typedef struct {
    char transaction_description[80];
} TransactionRecord;

// structure declare
typedef struct{
    int user_id;
    char user_name[30];
    char user_email[30];
    char user_pass[20];
    int phone_number;
    char address[30];
    int postal_code;
    int user_points;
    int isAdmin;
    TransactionRecord transaction_records[50];
    int num_transactions;

}Db;

// database
Db data[10];

// main function
int main(){

    retrieve_data();
    menu();

    return 0;
}

// menu function
void menu(){

    while (1) { // 1 true 0 false
        int option = 0;
        printf("\nWelcome to our System!\n");
        printf("Press:1 To Login!\nPress:2 To Register!\nPress:3 To Exist!:\nEnter:");
        scanf("%d", &option);

        if (option == 1) {

            login();

        } else if (option == 2) {

            registration();

        } else {

            exit(1);

        }
    }

}

// login function
void login(){

    char l_email[30];
    char l_password[20];
    printf("This is Login!\n");
    printf("Enter your email to Login:");
    scanf(" %[^\n]",&l_email);
    printf("Enter your password to Login:");
    scanf(" %[^\n]",&l_password);

    login_checking(l_email,l_password);
    if(g_login_check != -1){
        printf("Login Success!\n Your Id= %d",g_login_check);
        my_privilege(g_login_check);
    } else{
        printf("Login Failed!\n");
        menu();
    }

}


void my_privilege(int user_id){

    int m_option=-1;
    printf("\nWelcome %s!", data[user_id].isAdmin ? "Admin" : "User");
    printf("\nWelcome Sir: %s",data[user_id].user_name);
    printf("\nYour PhoneNumber: %d",data[user_id].phone_number);
    printf("\nYour Points: %d",data[user_id].user_points);
    printf("\nTransaction Records:\n");
    for (int i = 0; i < data[user_id].num_transactions; i++) {
        printf("%d. %s\n", i + 1, data[user_id].transaction_records[i].transaction_description);
    }

    printf("\nWhat you want to do!\n");
    printf("Enter 0 To Complete Exist:\nEnter 1 to Menu:\nEnter 2 to change user info:\nEnter 3 to give points to other:\n");

    if (data[user_id].isAdmin) {
        // Additional admin features
        printf("Enter 4 to view all user information:\n");
        printf("Enter 5 to view all transaction records:\n");
    }
    scanf("%d",&m_option);

    if (m_option == 0) {
        exit(1);
    } else if (m_option == 1) {
        menu();
    } else if (m_option == 2) {
        user_info_change(user_id);
    } else if (m_option == 3) {
        points_fun(user_id);
    }

    if (data[user_id].isAdmin) {

        if (m_option == 4) {
            view_all_user_information();
            my_privilege(user_id);
        } else if (m_option == 5) {
            view_all_transaction_records();
            my_privilege(user_id);
        }

    }

    else {
        printf("Wrong Option Number:\n");
        my_privilege(user_id);
    }


}

void user_info_change(int user_id){
    int change_option=0;
    printf("Press 1: To change Name:\nPress 2: To change Email:\n");
    printf("Press 3: To change Password:\nPress 4: To change PhoneNumber:\n");
    printf("Press 5: To change Address:\nPress 6: To change Postal Code:\n");
    printf("Press 7: For your privilege:");
    scanf("%d",&change_option);

    if(change_option==1){
        char newuser_name[30];
        printf("To change name:\n");
        printf("This is your user name: %s\n",data[user_id].user_name);
        printf("Enter your new user name:");
        scanf(" %[^\n]",&newuser_name);
        copy_two_charArray(data[user_id].user_name,newuser_name);
        printf("This is your new user name: %s",data[user_id].user_name);

    }else if(change_option==2){
        char newuser_email[30];
        printf("To change email:\n");
        printf("This is your user email: %s\n",data[user_id].user_email);
        printf("Enter your new user email:");
        scanf(" %[^\n]",&newuser_email);
        copy_two_charArray(data[user_id].user_email,newuser_email);
        printf("This is your new user email: %s",data[user_id].user_email);
    }else if(change_option==3){
        char newuser_pass[20];
        printf("To change password:\n");
        printf("This is your user password: %s\n",data[user_id].user_pass);
        printf("Enter your new user password:");
        scanf(" %[^\n]",&newuser_pass);
        copy_two_charArray(data[user_id].user_pass,newuser_pass);
        printf("This is your new user password: %s",data[user_id].user_pass);
    }else if(change_option==4){
        int newuser_phone;
        printf("To change phone number:\n");
        printf("This is your user phone number: %d\n",data[user_id].phone_number);
        printf("Enter your new user number:");
        scanf("%d",&newuser_phone);
        data[user_id].phone_number = newuser_phone;
        printf("This is your new user phone number: %d",data[user_id].phone_number);
    }else if(change_option==5){
        char newuser_address[30];
        printf("To change address:\n");
        printf("This is your user address: %s\n",data[user_id].address);
        printf("Enter your new user address:");
        scanf(" %[^\n]",&newuser_address);
        copy_two_charArray(data[user_id].address,newuser_address);
        printf("This is your new user address: %s",data[user_id].address);
    }else if(change_option==6){
        int newuser_post_code;
        printf("To change Postal Code:\n");
        printf("This is your user postal code: %d\n",data[user_id].phone_number);
        printf("Enter your new user postal code:");
        scanf("%d",&newuser_post_code);
        data[user_id].postal_code = newuser_post_code;
        printf("This is your new user postal code: %d",data[user_id].postal_code);
    }else if(change_option==7){
        my_privilege(user_id);
    }else{
        return;
    }

}

void login_checking(char l_email[30],char l_pass[20]){

    int i=0;
    g_login_check=-1;
    for(i=0; i<g_userCount; i++){

        int email_check = compare_two_char_array(data[i].user_email,l_email);

        if(email_check == 1){
            int pass_check = compare_two_char_array(data[i].user_pass,l_pass);
            if(pass_check==1){
                g_login_check=data[i].user_id;
                break;
            }
        }

    }

}

void registration(){

    char r_username[30];
    char r_useremail[30];
    char r_userpassword[20];
    int r_phoneNumber=0;
    char r_address[50];
    int r_postal_code=0;
    printf("This is Registration Option:\n");
    printf("Enter your user name to Register:");
    scanf(" %[^\n]",&r_username);
    int email_exist = -1;
    while (email_exist == -1) {
        printf("Enter your user email to Register:");
        scanf(" %[^\n]", &r_useremail);
        email_exist = email_scanner(r_useremail);

        if (email_exist == -1) {
            printf("Your email already registered! %s\n", r_useremail);
            printf("Enter your new email address!\n");
        }
    }

    int email_valid_result = -1;
    while (email_valid_result == -1) {
        email_valid_result = email_valid_two(r_useremail);

        if (email_valid_result == -1) {
            printf("Email invalid! Enter your new email address\n");
        }
    }

    printf("Enter your user password to Register:");
    scanf(" %[^\n]",&r_userpassword);
    while (!is_strong_password(r_userpassword)) {
        printf("*Error: Password is weak\n Please enter new stronger password:");
        scanf(" %[^\n]", &r_userpassword);
    }

    printf("Enter your user PhoneNumber to Register:");
    scanf("%d",&r_phoneNumber);
    printf("Enter your address to Register:");
    scanf(" %[^\n]",&r_address);
    printf("Enter your Postal code to Register:");
    scanf("%d",&r_postal_code);

    // collecting
    copy_two_charArray(data[g_userCount].user_name,r_username);
    printf("\nChecking for username: %s",data[g_userCount].user_name);

    copy_two_charArray(data[g_userCount].user_email,r_useremail);
    printf("\nChecking for useremail: %s",data[g_userCount].user_email);

    copy_two_charArray(data[g_userCount].user_pass,r_userpassword);
    printf("\nChecking for Password: %s",data[g_userCount].user_pass);

    data[g_userCount].phone_number = r_phoneNumber;
    printf("\nChecking for PhoneNumber: %d",data[g_userCount].phone_number);

    copy_two_charArray(data[g_userCount].address,r_address);
    printf("\nChecking for Address: %s",data[g_userCount].address);

    data[g_userCount].postal_code = r_postal_code;
    printf("\nChecking for Postal Code: %d",data[g_userCount].postal_code);

    data[g_userCount].user_points = total_points;
    data[g_userCount].user_id = g_userCount;
    if (g_userCount == 0 || g_userCount == 1 || g_userCount == 2) {
        data[g_userCount].isAdmin = 1;
    } else {
        data[g_userCount].isAdmin = 0;
    }
    g_userCount++;
    record_data();

}

void copy_two_charArray(char first[30],char second[30]){

    for(int x=0; x<30; x++){
        first[x]=='\0';
    }

    int i=0;
    for(i=0; i<30; i++){

        if(second[i]=='\0'){

            break;
        } else{
            first[i] = second[i];
        }

    }

}

int compare_two_char_array(char first[30],char second[30]){

    int size1 = size_of_charArray(first);
    int size2 = size_of_charArray(second);
    int sameCount=0;

    if(size1 == size2){

        for(int i=0; i<size1; i++){
            if(first[i] == second[i]){
                sameCount++;
            }
        }
    }

    if(size1 == sameCount){
        return 1; // if same
    } else{
        return 0; //if not same
    }
}

int size_of_charArray(char arr[30]){

    int size=0;
    for(int i=0; i<30; i++){

        if(arr[i] == '\0'){
            break;
        }
        size++;
    }
    return size;
}

int email_scanner(char to_check_email[30]){

    int exit_or_not=-1;
    if(g_userCount==0){
        return 1;
    } else{
        for(int i=0; i<g_userCount; i++){
            exit_or_not = compare_two_char_array(data[i].user_email, to_check_email);
            if(exit_or_not==1){
                return -1;
            }
        }
    }
    return 1; //you can register
}


int email_valid_two(char to_valid_email[30]) {
    int first_count = 0;
    char one_char;
    int arr_size = size_of_charArray(to_valid_email);
    char arr_sec_part[14];

    // email domain
    char gmail[12] = {'@', 'g', 'm', 'a', 'i', 'l', '.', 'c', 'o', 'm'};
    char yahoo[12] = {'@', 'y', 'a', 'h', '0', '0', '.', 'c', 'o', 'm'};
    char outlook[12] = {'@', 'o', 'u', 't', 'l', 'o', 'o', 'k', '.', 'c', 'o', 'm'};
    char apple[12] = {'@', 'a', 'p', 'p', 'l', 'e', '.', 'c', 'o', 'm'};
    char n1c[12] = {'@', 'n', '1', 'c', '.', 'c', 'o', 'm'};

    for (int i = 0; i < arr_size; i++) {
        if (to_valid_email[i] == '@') {
            int j;
            for (j = i; j < arr_size; j++) {
                arr_sec_part[j - i] = to_valid_email[j];
            }
            arr_sec_part[j - i] = '\0';
            break;
        } else {
            first_count++;
        }
    }

    int first_valid = 0;
    for (int x = 0; x < first_count; x++) {
        one_char = to_valid_email[x];
        if ((one_char >= 48 && one_char <= 57) || (one_char >= 97 && one_char <= 122)) {
            first_valid++;
        } else {
            email_validation = -1;
            return -1;
        }
    }

    if (first_count != first_valid || first_count == arr_size || first_count == 0) {
        email_validation = -1;
        return -1;
    } else {
        int g = compare_two_char_array(arr_sec_part, gmail);
        int y = compare_two_char_array(arr_sec_part, yahoo);
        int o = compare_two_char_array(arr_sec_part, outlook);
        int a = compare_two_char_array(arr_sec_part, apple);
        int n = compare_two_char_array(arr_sec_part, n1c);

        if (g || y || o || a || n) {
            email_validation = 1;
            return 1;
        } else {
            email_validation = -1;
            return -1;
        }
    }
}

int is_strong_password(char password[20]){

    if (size_of_charArray(password) < 6) {
        return 0;
    }

    int hasUpperCase = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpperCase = 1;
            break;
        }
    }

    int hasLowerCase = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowerCase = 1;
            break;
        }
    }

    int hasDigit = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }

    int hasSpecialChar = 0;
    for (int i = 0; password[i] != '\0'; i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >= '0' && password[i] <= '9'))) {
            hasSpecialChar = 1;
            break;
        }
    }

    return (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar);
}


void points_fun(int user_id){

    char receiver_email[30];
    int points;
    printf("\nThis is Points Giving Page!\n");
    printf("Your Total Points: %d\n", data[user_id].user_points);
    printf("Enter Receiver Mail :");
    scanf(" %[^\n]",&receiver_email);
    printf("How many points do you give :");
    scanf("%d",&points);

    int receiver_id = -1;
    for (int i = 0; i < g_userCount; i++) {
        if (compare_two_char_array(data[i].user_email, receiver_email) == 1) {
            receiver_id = i;
            break;
        }
    }

    if (receiver_id != -1) {

        sprintf(data[user_id].transaction_records[data[user_id].num_transactions].transaction_description, "User:%s transferred %d points to User:%s ",data[user_id].user_name, points, data[receiver_id].user_name);
        data[user_id].num_transactions++;
        sprintf(data[receiver_id].transaction_records[data[receiver_id].num_transactions].transaction_description, "User:%s received %d points from User:%s ",data[receiver_id].user_name, points, data[user_id].user_name);
        data[receiver_id].num_transactions++;

        data[user_id].user_points -= points;
        data[receiver_id].user_points += points;

        printf("\nPoints Giving Successfully\n");
        printf("Giver %s Total Points: %d\n", data[user_id].user_name,data[user_id].user_points);
        printf("Receiver %s Total Points: %d\n", data[receiver_id].user_name,data[receiver_id].user_points);

        record_data();
        my_privilege(user_id);

    } else {
        printf("\nInvalid Mail. Check the receiver's email.\n");
        points_fun(user_id);
    }
}

void record_data(){

    FILE *fptr = fopen("database.txt","a");
    if(!fptr){
        perror("Recording Data:\n");
    }
    for(int i=0; i<g_userCount; i++){

        fwrite(&data[i],sizeof(Db),1,fptr);

    }

    update_record_file();
    fclose(fptr);
}

void update_record_file(){
    FILE *fptr = fopen("database.txt", "w");
    if (!fptr) {
        perror("Error opening file!");
        return;
    }

    for (int i = 0; i < g_userCount; i++) {
        fwrite(&data[i], sizeof(Db), 1, fptr);
    }

    fclose(fptr);
}


void retrieve_data(){

    FILE *fptr = fopen("database.txt","r");
    if (!fptr) {
        perror("Error opening file!");
        return;
    }

    g_userCount = 0;
    while(fread(&data[g_userCount],sizeof(Db),1,fptr)==1){
        g_userCount++;
        if(g_userCount >= 10){
            printf("Maximum user is reached!");
            break;
        }
    }

    fclose(fptr);
}

void view_all_user_information() {
    printf("\nAll User Information:\n");
    for (int i = 0; i < g_userCount; i++) {
        printf("User ID: %d, Name: %s, Email: %s\n", data[i].user_id, data[i].user_name, data[i].user_email);
    }
    printf("Enter 1 to My Privilege\nEnter 2 to all user transaction record:");
    int option=-1;
    scanf("%d",&option);
    if(option==1){
        return;
    }else if(option==2){
        view_all_transaction_records();
    }
}

void view_all_transaction_records() {
    printf("\n*All Transaction Records*\n");
    for (int i = 0; i < g_userCount; i++) {
        printf("Transaction Records for User %s:\n", data[i].user_name);
        for (int j = 0; j < data[i].num_transactions; j++) {
            printf("%d. %s\n", j + 1, data[i].transaction_records[j].transaction_description);
        }
    }
    printf("Enter 1 to My Privilege:");
    int option=-1;
    scanf("%d",&option);
    if(option==1){
        return;
    }else{
        view_all_transaction_records();
    }
}