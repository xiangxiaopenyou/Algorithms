//
//  sort_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/13.
//

#ifndef sort_algorithms_h
#define sort_algorithms_h

#include <stdio.h>

/// 冒泡排序 O(n²)，稳定
int * bubbleSort(int *nums, int numsSize);

/// 选择排序 O(n²)，不稳定
int * selectionSort(int *nums, int numsSize);

/// 快速排序 O(n log n)，不稳定
int * quicklySort(int *nums, int low, int high);

/// 二分查找（有序数列） O(log n)
/// 返回目标数下标
int binarySearch(int *nums, int numsSize, int target);

void bubbleSort1(int *nums, int length);

void selectionSort1(int *nums, int numsSize);

#endif /* sort_algorithms_h */
