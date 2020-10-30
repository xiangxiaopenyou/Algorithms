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
    char string[11] = "hello world";
    reverseString(string, method2);
    
    // 移动数组中的0到数组末尾
    int array[] = {0, 1, 0, 3, 12};
    int arraySize = 5;
    moveZeroes(array, arraySize);
    
    return 0;
}
