//
//  main.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#include <stdio.h>
#include "array_algorithms.h"
#include "string_algorithms.h"
#include "sort_algorithms.h"
#include "others_algorithms.h"

#include <string.h>

int main(int argc, const char * argv[]) {
    
    // 反转字符串
    char string[] = "hello world";
    reverseString(string, method2);

    // 反转字符串中单词（单词本身不变）
    char temp[] = "a good   example";
    reverseWords(temp);

    // 左旋转字符串
    char left[] = "abcdefg";
    reverseLeftWords(left, 2);

    // 找字符串中不含重复字符的最长子串
    char longest[] = "dvdf";
    lengthOfLongestSubstring(longest);

    // 字符串中第一个唯一字符
    firstUniqChar(longest);
    
    // 回文串判断
    isPalindrome("A man, a plan, a canal: Panama");
    
    // 有效的字母异位词
    isAnagram("rat", "car");

    // 移动数组中的0到数组末尾
    int array[] = {0, 1, 0, 3, 12};
    int arraySize = 5;
    moveZeroes(array, arraySize);

    // int数组升序排序
    int needSort[] = {9, 6, 5, 0, 0, 7};
    sortArray(needSort, 6);

    // 合并有序数组
    int array1[] = {4, 5, 6, 0, 0, 0};
    int array2[] = {1, 2, 3};
    mergeArrays(array1, 6, 3, array2, 3, 3);

    // 两数之和
    int sumArray[] = {2, 7, 11, 15};
    twoSum(sumArray, 4, 9);
    
    // 两数之和（有序数组
    int sumArray2[] = {2, 7, 11, 15};
    twoSum2(sumArray2, 4, 9);
    
    
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    maxSubArray(nums, 9);

    // 冒泡排序
    int bubbleArray[] = {7, 4, 1, 0, 5, 9, 8};
    bubbleSort(bubbleArray, 7);

    // 选择排序
    int selectionArray[] = {5, 4, 3, 7, 9, 0, 2};
    selectionSort(selectionArray, 7);

    // 快速排序
    int quicklyArray[] = {6, 8, 1, 5, 4, 3, 7, 9, 0, 2};
    quicklySort(quicklyArray, 0, 9);

    // 二分查找
    int binaryArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    binarySearch(binaryArray, 10, 5);

    // 小于n的质数的数量
    countPrimes(10);

    // 判断有序二维数组中是否含有某整数
    int findNumberArray[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
    findNumberIn2DArray(findNumberArray, 5, 5, 5);

    // 寻找数组中唯一重复数
    int duplicateArray[] = {3,1,3,4,2};
    findDuplicate(duplicateArray, 5);
    
    // 寻找数组中唯一不重复数
    int singleArray[] = {1, 1, 2, 2, 3, 5, 5};
    findSingle(singleArray, 7);
    
    // 计算平方根
    mySqrt(16);
    
    // 反转整数
    reverseNum(1534236469);
    
    return 0;
}

