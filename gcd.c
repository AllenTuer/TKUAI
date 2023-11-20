#include<stdio.h>

void swap(int* first, int* second){
    int temp = 0;
    temp = *first;
    *first = *second;
    *second = temp;
}

int gcd(int first, int second){
    if(second == 0){
        return first;
    }
    if(second == 1){
        return second;
    }
    int temp = 0;
    temp = first % second;
    return gcd(second, temp);
}

int main (void){
    int first  = 0, second = 0, ans = 0;
    printf("Enter two values : ");
    scanf("%d %d", &first, &second);
    if(first < second){
        swap(&first, &second);
    }
    ans = gcd(first, second);
    printf("the gcd is : %d", ans);
    return 0;
}
