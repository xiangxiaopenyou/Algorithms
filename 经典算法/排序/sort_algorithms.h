//
//  sort_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/13.
//

#ifndef sort_algorithms_h
#define sort_algorithms_h

#include <stdio.h>

/// 冒泡排序
int * bubbleSort(int *nums, int numsSize);

/// 选择排序
int * selectionSort(int *nums, int numsSize);

/// 快速排序
int * quicklySort(int *nums, int low, int high);

/// 二分查找
/// 返回目标数下标
int binarySearch(int *nums, int numsSize, int target);

#endif /* sort_algorithms_h */
