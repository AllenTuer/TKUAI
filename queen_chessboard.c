#include <stdio.h>
#include <stdbool.h>

bool straight (int *checkerboard, int x, int y, int n){
    for (int i = x - 1; i >= 0; i--){
        if (checkerboard[i * n + y] == 1){
            return false;                             //從此棋往上檢查
        }
    }

    for (int i = x + 1; i != n; i++){
        if (checkerboard[i * n + y] == 1){           //往下檢查
            return false;
        }
    }

    return true;
}

bool row (int *checkerboard, int x, int y, int n){

        for(int j = y - 1; j >= 0; j--){
        if (checkerboard[x * n + j] == 1){
            return false;                             //從此棋往左檢查
        }
    }

        for(int j = y + 1; j != n; j++){
        if (checkerboard[x * n + j] == 1){
            return false;                             //從此棋往右檢查
            }
        }

    return true;
}

bool  positive_slope(int *checkerboard, int x, int y, int n){
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (checkerboard[i * n + j] == 1) {
            return false;                                           // 從此往左下檢查
        }
    }

    for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
        if (checkerboard[i * n + j] == 1) {
            return false;                                          //從此往右上檢查
        }
    }

    return true;
}

bool negative_slope(int *checkerboard, int x, int y, int n){
    for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
    if (checkerboard[i * n + j] == 1) {
        return false;                                              // 往左上檢查
    }
}
for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) {
    if (checkerboard[i * n + j] == 1) {
        return false;                                              // 往右下檢查
    }
}
    return true;
}

int main (void){

    int n = 0, i, j, x, y, queen = 1;            //queen 為計數器,因為已經有加過一個了所以從1開始
    bool judge_straight, judge_row, judge_positive_slope, judge_negative_slope;

    do{
        printf("n = (5 <= n < 1000) \n");      //輸入你要N*N矩陣,當N小於5或是大於1000時重新輸入
        scanf("%d", &n);
    }while (n < 5 || n >1000);

    int checkerboard[n][n];

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){       //棋盤歸0
            checkerboard[i][j] = 0;
        }
    }

    checkerboard[4][4] = 1;           // 412770744 學號末四碼44各加一為5,5

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ",checkerboard[i][j] );       //印出棋盤
        }
        printf("\n");
    }

    while (1) {
        printf("(x,y) = ");
        scanf("%d %d", &x, &y);                     //得座標
        if (checkerboard[x - 1][y - 1] == 0){         //下棋+防呆
            checkerboard[x - 1][y - 1]++;
        }else {
            continue;
        };

    judge_straight = straight(&checkerboard[0][0], x - 1, y - 1, n);
    judge_row = row(&checkerboard[0][0], x - 1, y - 1, n);                                //會判斷行列以及兩斜的路上有沒有皇后，如果有那就傳回false
    judge_positive_slope = positive_slope(&checkerboard[0][0], x - 1, y - 1, n);
    judge_negative_slope = negative_slope(&checkerboard[0][0], x - 1, y - 1, n);

    if (judge_straight == true && judge_row == true && judge_positive_slope == true && judge_negative_slope == true){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                printf("%d ",checkerboard[i][j] );                         //判斷下的位置沒有撞到其他皇后之後列印棋盤否則印出錯誤並結束迴圈
            }
            printf("\n");
        }
        queen++;
        if(queen == n){
            printf("Pass!");            //通關了

            break;
        }
    }else{
            printf("error");
            break;
        }
    };

    return 0;
}

