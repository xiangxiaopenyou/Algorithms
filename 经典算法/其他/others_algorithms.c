//
//  others_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/9.
//

#include "others_algorithms.h"
#include <stdlib.h>
#include <string.h>

int mySqrt(int x) {
    if (x == 1) {
        return 1;
    }
    // 二分查找思想
    int left = 1, right = x / 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (x / mid < mid) {
            right = mid - 1;
        } else if (x / mid > mid) {
            left = mid + 1;
        } else {
            printf("平方根：%d", mid);
            return mid;
        }
    }
    printf("平方根：%d\n", right);
    return right;
}

int reverseNum(int x){
    long result = 0;
    while (x != 0) {
        result = result * 10 + x % 10;
        x = x / 10;
    }
    if((int)result != result) {
        return 0;
    }
    printf("反转整数：%ld\n", result);
    return (int)result;
}

bool check(char **board, int boardSize, int boardColSize, int **visited, int i, int j, char *s, int sSize, int k) {
    if (board[i][j] != s[k]) {
        return false;
    } else if (k == sSize - 1) {
        return true;
    }
    // 查找的四个方向
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    visited[i][j] = true;
    bool result = false;
    for (int m = 0; m < 4; m++) {
        int newi = i + directions[m][0], newj = j + directions[m][1];
        if (newi >= 0 && newi < boardSize && newj >= 0 && newj < boardColSize) {
            if (!visited[newi][newj]) {
                bool flag = check(board, boardSize, boardColSize, visited, newi, newj, s, sSize, k + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word) {
    int **visited = malloc(sizeof(int *) * boardSize);
    for (int i = 0; i < boardSize; i++) {
        visited[i] = malloc(sizeof(int) * boardColSize[0]);
        memset(visited[i], 0, sizeof(int) * boardColSize[0]);
    }
    int wordSize = (int)strlen(word);
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            // 每次循环对比单词第一个字母和board[i][j]
            bool checked = check(board, boardSize, boardColSize[0], visited, i, j, word, wordSize, 0);
            if (checked) {
                return true;
            }
        }
    }
    return false;
}
