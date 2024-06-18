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
#include "list_node.h"

#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
//    // 反转字符串
//    char string[] = "hello world";
//    reverseString(string, method2);
//
//    // 反转字符串中单词（单词本身不变）
//    char temp[] = "a good   example";
//    reverseWords(temp);
//
//    // 左旋转字符串
//    char left[] = "abcdefg";
//    reverseLeftWords(left, 2);
//
//    // 找字符串中不含重复字符的最长子串
//    char longest[] = "dvdf";
//    lengthOfLongestSubstring(longest);
//
//    // 字符串中第一个唯一字符
//    firstUniqChar(longest);
//    
//    // 回文串判断
//    isPalindrome("A man, a plan, a canal: Panama");
//    
//    // 有效的字母异位词
//    isAnagram("rat", "car");
//
//    // 移动数组中的0到数组末尾
//    int array[] = {0, 1, 0, 3, 12};
//    int arraySize = 5;
//    moveZeroes(array, arraySize);
//
//    // int数组升序排序
//    int needSort[] = {9, 6, 5, 0, 0, 7};
//    sortArray(needSort, 6);
//
//    // 合并有序数组
//    int array1[] = {4, 5, 6, 0, 0, 0};
//    int array2[] = {1, 2, 3};
//    mergeArrays(array1, 6, 3, array2, 3, 3);
//
//    // 两数之和
//    int sumArray[] = {2, 7, 11, 15};
//    twoSum(sumArray, 4, 9);
//    
//    // 两数之和（有序数组
//    int sumArray2[] = {2, 7, 11, 15};
//    twoSum2(sumArray2, 4, 9);
//    
//    
//    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    maxSubArray(nums, 9);
//
//    // 冒泡排序
//    int bubbleArray[] = {7, 4, 1, 0, 5, 9, 8};
//    bubbleSort(bubbleArray, 7);
//
//    // 选择排序
//    int selectionArray[] = {5, 4, 3, 7, 9, 0, 2};
//    selectionSort(selectionArray, 7);
//
    // 快速排序
    int quicklyArray[] = {6, 8, 1, 5, 4, 3, 7, 9, 0, 2};
    quicklySort(quicklyArray, 0, 9);

//    // 二分查找
//    int binaryArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    binarySearch(binaryArray, 10, 5);
//
//    // 小于n的质数的数量
//    countPrimes(10);
//
//    // 判断有序二维数组中是否含有某整数
//    int findNumberArray[5][5] = {
//        {1, 4, 7, 11, 15},
//        {2, 5, 8, 12, 19},
//        {3, 6, 9, 16, 22},
//        {10, 13, 14, 17, 24},
//        {18, 21, 23, 26, 30},
//    };
//    findNumberIn2DArray(findNumberArray, 5, 5, 5);
//
    
    int duplicateArray1[] = {0,0,1,1,1,2,2,3,3,4};
    
    removeDuplicates1(duplicateArray1, 10);
    
    int duplicateArray2[] = {0,0,1,1,1,1,2,3,3};
    
    removeDuplicates2(duplicateArray2, 9);
    
    int nums[6] = {1,1,0,1,1,1};
    int max = findMaxConsecutiveOnes(nums, 6);
    
    
    int nums1[4] = {3,2,2,3};
    int ret = removeElement(nums1, 4, 3);
    
//    // 寻找数组中唯一不重复数
//    int singleArray[] = {1, 1, 2, 2, 3, 5, 5};
//    findSingle(singleArray, 7);
//    
//    // 计算平方根
//    mySqrt(16);
//    
//    // 反转整数
//    reverseNum(1534236469);
    
//    int bubbleArray[] = {7, 4, 1, 0, 5, 9, 8};
//    bubbleSort1(bubbleArray, 7);
    
//    int selectionArray[] = {5, 4, 3, 7, 9, 0, 2};
//    selectionSort1(selectionArray, 7);
    
    // 创建头结点用malloc分配内存
//    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
//    head
    
    struct ListNode * node1 = malloc(sizeof(struct ListNode));
    struct ListNode * node2 = malloc(sizeof(struct ListNode));
    struct ListNode * node3 = malloc(sizeof(struct ListNode));
    struct ListNode * node4 = malloc(sizeof(struct ListNode));
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 4;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    struct ListNode * l1 = node1;
    
    struct ListNode * node5 = malloc(sizeof(struct ListNode));
    struct ListNode * node6 = malloc(sizeof(struct ListNode));
    struct ListNode * node7 = malloc(sizeof(struct ListNode));
    node5->val = 1;
    node6->val = 2;
    node7->val = 3;
    
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;
    
    struct ListNode * l2 = node5;
    
//    addTwoNumbers(l1, l2);
    
//    reverseList5(l1);
    
//    int ways = trainWays(5);
//    swapPairs(l1);

    mergeTwoLists(l1, l2);
    
    int prices[] = {7, 1, 5, 3, 6, 4};
    maxProfit2(prices, 6);
    
    return 0;
    
    
}
