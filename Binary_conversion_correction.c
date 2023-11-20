#include<stdio.h>

int will (int i, int temp){
    if (i == 0){
        return temp;
    }else{
        for (int j = 0; j != i; j++){
            temp = temp * 10;
        }
    }
    return temp;
}

int binary(int in){
    int temp = 0, ans = 0;

    for (int i = 0; in != 0; i++){
        temp = in % 2;
        ans = ans + will(i, temp);
        in = in / 2;
    }
    return ans;
}

int main (void){
    int in = 0, bin = 0;
    printf("Enter a value : \n");
    scanf("%d", &in);
    bin = binary(in);
    printf("%d", bin);
    return 0;
}
