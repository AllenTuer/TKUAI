#include<stdio.h>
#include<stdbool.h>

int main (void){
    char str[1000];
    int len = 0, middle = 0;
    bool even = true, judge = true;

    printf("Please enter a string : \n");
    gets(str);

    for(int i = 0; str[i] != NULL; i++){
        len++;
    }

    if(len % 2 != 0){
        even = false;
        middle = (len + 1) / 2;
    }else{
        middle = (len / 2) - 1;
    }

    if (even == false){
        for(int i = 0; i < middle; i++){
            if(str[i] != str[len - 1 - i]){
                printf("No \n");
                judge = false;
                break;
            }
        }
    }else{
        for(int i = 0; i <= middle; i++){
            if(str[i] != str[len - 1 - i]){
                printf("No \n");
                judge = false;
                break;
            }
        }
    }
    if(judge == true){
        printf("Yes \n");
    }
    return 0;
}
