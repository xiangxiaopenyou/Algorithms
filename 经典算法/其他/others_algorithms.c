//
//  others_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/9.
//

#include "others_algorithms.h"

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
