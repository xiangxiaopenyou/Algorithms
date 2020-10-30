//
//  string_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/10/30.
//

#ifndef string_algorithms_h
#define string_algorithms_h

enum reverse_string_methods {
    method1 = 0,
    method2 = 1
};

#include <stdio.h>

/// 反转字符串
/// @param s 字符串
void reverseString(char *s, enum reverse_string_methods method);

#endif /* string_algorithms_h */
