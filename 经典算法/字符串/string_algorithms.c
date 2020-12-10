//
//  string_algorithms.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/30.
//

#include "string_algorithms.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

void reverse(char *s, int start, unsigned long end) {
    char temp;
    while (start < end) {
        temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
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
        // 末尾字符是空格时设置为\0用于删除最后字符
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

char resultString(char s) {
    if (s == '}') {
        return '{';
    }
    if (s == ']') {
        return '[';
    }
    if (s == ')') {
        return '(';
    }
    return 0;
}

bool isValidString(char *s) {
    int length = (int)strlen(s);
    if (length % 2 == 1) {
        // 括号成对出现，所以当长度为单数时直接返回错误
        return false;
    }
    // 保存字符数组
    int valid[length + 1];
    int top = 0;
    for (int i = 0; i < strlen(s); i++) {
        // 获取对应字符('('对应')','['对应']','{'对应'}')
        char ch = resultString(s[i]);
        if (ch) {
            if (top == 0 || valid[top - 1] != ch) {
                // 如果获取到了对应字符，说明当前字符为')'或者']'或者'}'，此时如果数组为空或者最后元素部位对应字符，则直接返回错误
                return false;
            }
            top--;
        } else {
            // 如果没有获取到对应字符，说明当前字符为'('或者'['或者'{'，将字符加入到数组中
            valid[top++] = s[i];
        }
    }
    return top == 0;
}



int lengthOfLongestSubstring(char * s) {
    int length = (int)strlen(s);
    // 最长长度
    int longest = 0;
    // 当前统计长度
    int count = 0;
    // 当前下标
    int current = 0;
    // 用哈希数组储存下标
    int hash[128];
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < length; i++) {
        if (hash[s[i]] >= current) {
            // 利用哈希找到重复的字符，当前下标更新为重复字符下一个位置
            current = hash[s[i]] + 1;
            // 重置当前长度
            count = i - current;
        }
        // 储存下标
        hash[s[i]] = i;
        // 不重复长度加1
        count++;
        if (count > longest) {
            longest = count;
        }
    }
    printf("最长子串长度:%d\n", longest);
    return longest;
}

int firstUniqChar(char * s) {
    int length = (int)strlen(s);
    if (length == 0) {
        return -1;
    }
    int hash[26];
    memset(hash, 0, sizeof(hash));
    // hash思想保存重复字符出现次数
    for (int i = 0; i < length; i++) {
        hash[s[i] - 'a']++;
    }
    for (int j = 0; j < length; j++) {
        if (hash[s[j] - 'a'] == 1) {
            return j;
        }
    }
    return -1;
}

bool isPalindrome(char * s) {
    if (strlen(s) == 0) {
        // 空字符串返回true
        return true;
    }
    int length = (int)strlen(s);
    // 保存一个删除了特殊字符的字符串
    char *temp = malloc(sizeof(char) * (length + 1));
    int r = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(s[i]) || islower(s[i])) {
            // 数字和小写字母直接保存
            temp[r++] = s[i];
        } else if (isupper(s[i])) {
            // 大写字母转为小写字母保存
            temp[r++] = s[i] + 32;
        }
    }
    // 结束符
    temp[r] = '\0';
    int tempLength = (int)strlen(temp);
    // 对比字符串是否回文串
    for (int j = 0; j < tempLength / 2; j++) {
        if (temp[j] != temp[tempLength - j - 1]) {
            return false;
        }
    }
    return true;
}

bool isAnagram(char * s, char * t){
    int length_s = (int)strlen(s);
    int length_t = (int)strlen(t);
    if (length_s != length_t) {
        return false;
    }
    int hash[26];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < length_s; i++) {
        hash[s[i] - 'a']++;
    }
    for (int j = 0; j < length_t; j++) {
        hash[t[j] - 'a']--;
        if (hash[t[j] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
