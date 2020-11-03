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

int * sortArray(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("快排：%d\n", nums[i]);
    }
    return nums;
}

void quickSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int first = left, last = right;
    // 中间数key
    int key = nums[left];
    while (first < last) {
        // 从后往前遍历，找到小于key的值，赋值给first
        while (first < last && nums[last] >= key) {
            last--;
        }
        nums[first] = nums[last];
        
        // 从前往后遍历，找到大于key的值，赋值给last
        while (first < last && nums[first] <= key) {
            first++;
        }
        nums[last] = nums[first];
    }
    
    // 在当组内找完一遍以后就把中间数key回归
    nums[first] = key;
    
    quickSort(nums, left, first - 1);
    quickSort(nums, first + 1, right);
}
