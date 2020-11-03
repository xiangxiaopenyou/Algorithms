//
//  main.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/23.
//

#include <stdio.h>
#include "array_algorithms.h"
#include "string_algorithms.h"

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
    
    // 移动数组中的0到数组末尾
    int array[] = {0, 1, 0, 3, 12};
    int arraySize = 5;
    moveZeroes(array, arraySize);
    
    // int数组升序排序
    int needSort[] = {9, 6, 5, 0, 0, 7};
    sortArray(needSort, 6);
    
    return 0;
}
