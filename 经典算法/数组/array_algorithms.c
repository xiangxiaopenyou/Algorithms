//
//  array_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#include "array_algorithms.h"

void moveZeroes(int *nums, int numSize) {
//    int j = 0;
//    for (int i = 0; i < numSize; i++) {
//        if (nums[i] != 0) {
//            // 将不是0的元素放到最前
//            nums[j++] = nums[i];
//        }
//    }
//    // 末尾补0
//    for (int k = 0; k < j; k++) {
//        nums[k + j] = 0;
//    }
    int m = 0;
    for (int i = 0; i < numSize; i++) {
        if (nums[i] == 0) {
            m++;
        } else if (m > 0) {
            nums[i - m] = nums[i];
            nums[i] = 0;
        }
    }
    
    for (int i = 0; i < numSize; i++) {
        printf("%d\n", nums[i]);
    }
}
