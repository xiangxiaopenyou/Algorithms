//
//  string_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/30.
//

#include <stdbool.h>

#ifndef string_algorithms_h
#define string_algorithms_h

enum reverse_string_method {
    method1 = 0,
    method2 = 1
};

#include <stdio.h>

/// 反转字符串
/// @param s 字符串
//void reverseString(char *s, enum reverse_string_method method);

/// 逐个反转字符串中的每个单词，单词本身不反转（空格分割单词，输出单词之间不能存在多个空格）
/// 输入"Hello   world"，输出"world Hello"
/// @param s 字符串
char * reverseWords(char *s);

/// 字符串左旋转
/// @param s 字符串
/// @param n 需要旋转的字符个数
char* reverseLeftWords(char *s, int n);

/// 判断只包括 '('，')'，'{'，'}'，'['，']' 的字符串是否有效。
/// 有效字符串需满足：
/// 左括号必须用相同类型的右括号闭合。
/// 左括号必须以正确的顺序闭合。
/// @param s 字符串
bool isValidString(char *s);

/// 找出字符串中不含有重复字符的 最长子串 的长度。
/// @param s 字符串
int lengthOfLongestSubstring(char * s);

/// 字符串中的第一个唯一字符
/// @param s 字符串
int firstUniqChar(char * s);

/// 判断字符串是否为回文串
/// @param s 字符串
bool isPalindrome(char * s);

/// 给定两个字符串，判断是否字母异位词
bool isAnagram(char * s, char * t);

void reverseString5(char *string);

#endif /* string_algorithms_h */
