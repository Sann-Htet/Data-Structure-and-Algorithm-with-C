#include<stdio.h>

int main(){
    int aungaung_mark[1];
    int mgmg_mark[1];
    int kk_mark[1];

    int i = 0;

    int student = 3;

    for(int i=0; i<student; i++){
        if(i==0){
            for(int xx=0; xx<1; xx++){
                printf("Enter Mark for Aung Aung %d: ", xx+1);
                scanf("%d", &aungaung_mark[xx]);
            }
        } else if(i==1){
            for(int xx=0; xx<1; xx++){
                printf("Enter Mark for Mg Mg %d: ", xx+1);
                scanf("%d", &mgmg_mark[xx]);
            }
        } else {
            for(int xx=0; xx<1; xx++){
                printf("Enter Mark for Kyaw Kyaw %d: ", xx+1);
                scanf("%d", &kk_mark[xx]);
            }
        }
    }

    for(int i=0; i<student; i++){
        if(i==0){
            if(aungaung_mark[0] > 40 && aungaung_mark[0] < 80){
                printf("Aung Aung passed the exam!\n");
            } else if(aungaung_mark[0] < 40){
                printf("Aung Aung failed the exam!\n");
            }
            if(aungaung_mark[0] >= 80){
                printf("Aung Aung passed the exam with distinction!\n");
            }
        }else if(i==1){
            if(mgmg_mark[0] > 40 && mgmg_mark[0] < 80){
                printf("Mg Mg passed the exam!\n");
            } else if(mgmg_mark[0] < 40){
                printf("Mg Mg failed the exam!\n");
            }
            if(mgmg_mark[0] >= 80){
                printf("Mg Mg passed the exam with distinction!\n");
            }
        } else {
            if(kk_mark[0] > 40 && kk_mark[0] < 80){
                printf("Kaung Kaung passed the exam!\n");
            } else if(kk_mark[0] < 40){
                printf("Kaung Kaung failed the exam!\n");
            }
            if(kk_mark[0] >= 80){
                printf("Kaung Kaung passed the exam with distinction!\n");
            }
        }
    }

    if(aungaung_mark[0] > mgmg_mark[0] && kk_mark[0]){
        printf("Aung Aung has the highest mark!");
    } else if (mgmg_mark[0] > aungaung_mark[0] && kk_mark[0]){
        printf("Mg Mg has the highest mark!");
    } else {
        printf("Kaung Kaung has the highest mark!");
    }

    return 0;
}