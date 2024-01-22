#include "stdio.h"

typedef struct
{
    /* data */
    int id;
    float score;
}sannhtet;

int main() {
    FILE *fptr;
    int a;
    sannhtet outRecord = {1, 10.10};
    sannhtet inRecord;

    fptr = fopen("record.bin", "wb");

    if (fptr == NULL){
        perror("\n");
        return -1;
    }

    fwrite(&outRecord, sizeof(sannhtet), 1, fptr);
    fclose(fptr);

    fptr = fopen("record.bin", "rb");
    if(fptr == NULL){
        perror("\n");
        return -1;
    }
    fread(&inRecord, sizeof(sannhtet), 1, fptr);
    printf("MyRecode ID: %d, Score: %.2f \n", inRecord.id, inRecord.score);
    fclose(fptr);

    return 0;
}