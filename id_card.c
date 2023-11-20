/******************************
ens+9 numbers
num [i] = numbers / 10^(i - 1) % 10
sum = num [i] * i + sum
A-H (65-72) (10-17)  (-55)
I = 73 34 -39
O = 79 35 -44
J-N (74-78) (18-22)  (-56)
P-V(80-86) (23-29)  (-57)
X-Z (88-90) (30-33)  (-58)
W = 87 32 (-55)
C121726806
1
2 * 9
1 * 8 num 9
2 * 7 num
1 * 6 num
7 * 5 num
2 * 4 num
6 * 3 num
8 * 2 num
0 * 1 num
6 * 1 num 0
*******************************/
#include <stdio.h>

int main(void) {
    char city = 0;
    int IC[10] = {0}, sum = 0, num = 0;

    printf("Enter your ID number: ");
    scanf(" %c %d", &city, &num);

    if (city == 73) {
        city = city - 39;
    } else if (city == 79) {
        city = city - 44;
    } else if (city >= 65 && city <= 72 || city == 'W') {
        city = city - 55;
    } else if (city >= 74 && city <= 78) {
        city = city - 56;
    } else if (city >= 88 && city <= 90) {
        city = city - 58;
    } else {
        city = city - 57;
    }

    for (int i = 0; i < 10; i++) {
        IC[i] = num % 10;
        num = num / 10;
    }

    for (int i = 1; i < 9; i++) {
        sum = sum + IC[i] * i;
    }
    sum = sum + IC[0];

    for (int i = 0; i < 2; i++) {
        sum = sum + ((city % 10) * (9 - 8 * i));
        city = city / 10;
    }

    if (sum % 10 == 0) {
        printf("Real\n");
    } else {
        printf("Fake\n");
    }

    return 0;
}
