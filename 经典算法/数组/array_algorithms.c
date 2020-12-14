//
//  array_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#include "array_algorithms.h"
#include <stdlib.h>
#include <string.h>

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

/// 快速排序数组
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
    
    // 当组内找完一遍以后就把中间数key回归
    nums[first] = key;
    
    quickSort(nums, left, first - 1);
    quickSort(nums, first + 1, right);
}

int * sortArray(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("快排：%d\n", nums[i]);
    }
    return nums;
}



void mergeArrays(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    // 数组1最后一个元素下标
    int last1 = m - 1;
    // 数组2最后一个元素下标
    int last2 = n - 1;
    // 合并以后数组最后元素下标
    int last = m + n - 1;
    while (last1 >= 0 && last2 >= 0) {
        // 每次比较两个数组最后一个元素，将大的保存到nums1
        if (nums1[last1] >= nums2[last2]) {
            nums1[last--] = nums1[last1--];
        } else if (nums1[last1] < nums2[last2]) {
            nums1[last--] = nums2[last2--];
        }
    }
    while (last2 >= 0) {
        // 如果nums2还有剩余元素，逐个保存
        nums1[last--] = nums2[last2--];
    }
    for (int i = 0; i < n + m; i++) {
        printf("合并有序数组：%d\n", nums1[i]);
    }
}

int *twoSum(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        // 需要查找的数值
        int needSearchNum = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == needSearchNum) {
                int *result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                printf("两数之和：%d, 两数之和%d\n", i, j);
                return result;
            }
        }
    }
    return NULL;
}

int countPrimes(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return 0;
    }
    int *primes = malloc(sizeof(int) * n);
    // 设置所有元素为0
    memset(primes, 0, sizeof(int) * n);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (primes[i] == 0) {
            count++;
            for (int j = i; j < n; j += i) {
                // 筛选出所有i的倍数
                primes[j] = 1;
            }
        }
    }
    printf("countPrimes:%d\n", count);
    return count;
}

bool findNumberIn2DArray(int matrix[5][5], int matrixSize, int matrixColSize, int target) {
    // 从矩阵左下角元素开始查找
    int col = matrixColSize - 1;
    int row = 0;
    while (row < matrixSize && col >= 0) {
        if (matrix[col][row] == target) {
            return true;
        } else if (matrix[col][row] > target) {
            // 大于目标值时往上查找
            col--;
        } else {
            // 小于目标值时往右查找
            row++;
        }
    }
    return false;
}

int findDuplicate(int* nums, int numsSize) {
    int left = 1, right = numsSize - 1;
    while (left < right) {
        // 统计在[left, mid]区间的数个数
        int count = 0;
        // 中位数
        int mid = (left + right) / 2;
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] <= mid) {
                count++;
            }
        }
        if (count <= mid) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    printf("唯一重复数：%d\n", left);
    return left;
}

int findSingle(int* nums, int numsSize) {
    int find = nums[0];
    for (int i = 1; i < numsSize; i++) {
        find = find^nums[i];
    }
    printf("唯一不重复数：%d\n", find);
    return find;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) {
        return numsSize;
    }
    // 重复数数量统计
    int duplicateNum = 0;
    for (int i = 0; i < numsSize - 1; i ++) {
        if (nums[i] == nums[i + 1]) {
            // 遇到重复数字加一
            duplicateNum++;
        }
        nums[i + 1 - duplicateNum] = nums[i + 1];
    }
    printf("有序数组删除重复元素以后元素个数：%d", (numsSize - duplicateNum));
    return (numsSize - duplicateNum);
}
