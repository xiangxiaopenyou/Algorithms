//
//  string_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/30.
//

#include "string_algorithms.h"

#include <string.h>
#include <stdlib.h>

void reverseString(char *s, enum reverse_string_method method) {
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

char * reverseWords(char *s) {
    while (*s == ' ') {
        // 首字符是空格时指针后移一位取消头部空格
        s++;
    }
    if (strlen(s) == 0) {
        return s;
    }
    unsigned long length = strlen(s) - 1;
    while (s[length] == ' ') {
        // 末尾字符是空格时设置为\0，并且删除最后字符
        s[length] = '\0';
        length --;
    }
    
    // 整体反转
    reverse(s, 0, length);
    
    // 遍历字符串反转局部单词，并删除多余空格
    int start = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            // 空格表示某个单词结束，反转当前结束单词
            reverse(s, start, i - 1);
            // 删除多余空格
            while (s[i + 1] && s[i + 1] == ' ') {
                // 将空格移到字符串末尾
                int j = i + 1;
                while (s[j]) {
                    s[j] = s[j + 1];
                    j++;
                }
                // 字符串长度减1
                length--;
            }
            // 新单词开始位置
            start = i + 1;
        }
    }
    reverse(s, start, length);
    printf("%s\n", s);
    return s;
}


void reverse(char *s, int start, unsigned long end) {
    char temp;
    while (start < end) {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

char * reverseLeftWords(char *s, int n) {
    int length = (int)strlen(s), k = 0;
    // 字符串后面部分
    char *temp = s + n;
    // 创建新字符串
    char *result = (char *)malloc(sizeof (char) * (length + 1));
    // 前半部分
    for (int i = 0; i < (length - n); i ++) {
        result[k] = temp[i];
        k++;
    }
    // 后半部分
    for (int j = 0; j < n; j++) {
        result[k] = s[j];
        k++;
    }
    // 最后字符
    result[k] = '\0';
    printf("left:%s\n", result);
    return result;
}
