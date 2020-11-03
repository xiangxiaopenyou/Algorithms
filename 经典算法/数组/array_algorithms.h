//
//  array_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#ifndef array_algorithms_h
#define array_algorithms_h

enum sort_method {
    method_quick = 0   // 快速排序
};

#include <stdio.h>


/// 将int数组中的所有0移到末尾，并保持其他元素顺序不变（在原数组上操作）
/// @param nums 数组
/// @param numSize 数组大小
void moveZeroes(int *nums, int numSize);


/// 将int数组升序排列
/// @param nums 数组
/// @param numsSize 数组大小
int * sortArray(int* nums, int numsSize);

/// 快速排序数组
void quickSort(int *nums, int left, int right);

#endif /* array_algorithms_h */
