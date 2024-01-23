#include "stdio.h"
#include "stdlib.h"

void n1c_file_copy(const char *sourceFile, const char *destinationFile){
    FILE *source, *destination;
    int ch;

    source = fopen(sourceFile, "rb");
    if(source == NULL){
        perror("Source\n");
        exit(EXIT_FAILURE);
    }

    destination = fopen(destinationFile, "wb");
    if(destination == NULL){
        fclose("Destination\n");
        fclose(source);
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(source)) != EOF){
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
}

int main(){

    n1c_file_copy("sann.txt", "n1c.txt");
    printf("File Copied Successfully.!");
    return 0;
}