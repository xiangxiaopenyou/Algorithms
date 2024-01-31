//
//  sort_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/13.
//

#include "sort_algorithms.h"

int * bubbleSort(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for (int k = 0; k < numsSize; k++) {
        printf("冒泡排序：%d\n", nums[k]);
    }
    return nums;
}

int * selectionSort(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
    }
    for (int k = 0; k < numsSize; k++) {
        printf("选择排序：%d\n", nums[k]);
    }
    return nums;
}

int * quicklySort(int *nums, int low, int high) {
    if (low >= high) {
        return nums;
    }
    int left = low, right = high;
    int key = nums[low];
    while (left < right) {
        while (left < right && nums[right] >= key) {
            right--;
        }
        nums[left] = nums[right];
        
        while (left < right && nums[left] <= key) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = key;
    quicklySort(nums, low, left - 1);
    quicklySort(nums, left + 1, high);
    
    for (int k = 0; k <= high; k++) {
        printf("快速排序：%d\n", nums[k]);
    }
    
    return nums;
}

int binarySearch(int *nums, int numsSize, int target)  {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            printf("二分查找：%d\n", mid);
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // 找不到时返回-1
    return -1;
}


void bubbleSort1(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            int num1 = nums[j], num2 = nums[j+1];
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        printf("冒泡：%d\n", nums[i]);
    }
}

void selectionSort1(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        printf("选择：%d\n", nums[i]);
    }
}
