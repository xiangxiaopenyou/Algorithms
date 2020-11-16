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

    // 冒泡排序
    int bubbleArray[] = {7, 4, 1, 0, 5, 9, 8};
    bubbleSort(bubbleArray, 7);

    // 选择排序
    int selectionArray[] = {5, 4, 3, 7, 9, 0, 2};
    selectionSort(selectionArray, 7);

    // 快速排序
    int quicklyArray[] = {6, 8, 1, 5, 4, 3, 7, 9, 0, 2};
    quicklySort(quicklyArray, 0, 9);
    
    __block int i = 2;
    void (^block)(void) = ^{
        printf("%d", i);
    };
    block();
    
    return 0;
}
