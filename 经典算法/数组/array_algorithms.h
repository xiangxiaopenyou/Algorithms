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
#include <stdbool.h>


/// 将int数组中的所有0移到末尾，并保持其他元素顺序不变（在原数组上操作）
/// @param nums 数组
/// @param numSize 数组大小
void moveZeroes(int *nums, int numSize);


/// 将int数组升序排列
/// @param nums 数组
/// @param numsSize 数组大小
int * sortArray(int *nums, int numsSize);

/// 合并两个有序数组
/// @param nums1 数组1
/// @param nums1Size 数组1大小
/// @param m 数组1元素数量
/// @param nums2 数组2
/// @param nums2Size 数组2大小
/// @param n 数组2元素数量
void mergeArrays(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n);

/// 两数之和：给定一个整数数组nums和一个目标值target，在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
/// @param nums 数组
/// @param numsSize 数组大小
/// @param target 目标值
int *twoSum(int* nums, int numsSize, int target);

/// 两数之和：输入一个递增排序的数组和一个目标值，在数组中查找两个数，使得它们的和正好是s
/// @param nums 有序递增数组
/// @param numsSize 数组大小
/// @param target 目标值
int *twoSum2(int* nums, int numsSize, int target);

/// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值
/// @param nums 数组
/// @param numsSize 数组大小
int maxSubArray(int* nums, int numsSize);

/// 统计小于n的质数的数量
/// @param n 非负整数
int countPrimes(int n);

/// 判断有序二维数组中（从左到右递增，从上到下递增）是否含有某整数
/// @param matrix 二维数组
/// @param matrixSize 第二层数组元素个数（矩阵列数）
/// @param matrixColSize 第一层数组元素个数（矩阵行数）
/// @param target 目标整数
bool findNumberIn2DArray(int matrix[5][5], int matrixSize, int matrixColSize, int target);

/// 寻找数组中唯一重复数，n+1个整数的数组nums，其数字都在1到n之间
/// @param nums 数组
/// @param numsSize 数组大小
int findDuplicate(int* nums, int numsSize);

/// 寻找数组中唯一不重复数
/// @param nums 数组
/// @param numsSize 数组大小
int findSingle(int* nums, int numsSize);

/// 删除有序数组中重复元素
/// @param nums 数组
/// @param numsSize 数组大小
int removeDuplicates(int* nums, int numsSize);

int removeDuplicates1(int* nums, int numsSize);

/// 使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度
int removeDuplicates2(int* nums, int numsSize);

/// 找出数组中任一重复的数字
/// @param nums 数组
/// @param numsSize 数组大小
int findRepeatNumber(int* nums, int numsSize);

/// 最大连续1的个数
int findMaxConsecutiveOnes(int* nums, int numsSize);

#endif /* array_algorithms_h */
