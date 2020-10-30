//
//  string_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/30.
//

#include "string_algorithms.h"

#include <string.h>

void reverseString(char *s, enum reverse_string_methods method) {
    if (s == NULL) {
        return;
    }
    switch (method) {
        case method1: {
            // 创建临时变量，首尾交换
            char temp;
            unsigned long length = strlen(s);
            for (int i = 0; i < length / 2; i++) {
                temp = s[i];
                s[i] = s[length - i - 1];
                s[length - i - 1] = temp;
            }
            printf("%s\n", s);
        }
            break;
        case method2: {
            // 异或交换
            unsigned long length = strlen(s);
            for (int i = 0; i < length / 2; i++) {
                s[i] = s[i] ^ s[length - i - 1];
                s[length - i - 1] = s[i] ^ s[length - i - 1];
                s[i] = s[i] ^ s[length - i - 1];
            }
            printf("%s\n", s);
        }
            break;
            
        default:
            break;
    }
    
}
