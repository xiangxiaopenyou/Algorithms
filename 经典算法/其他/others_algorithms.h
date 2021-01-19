//
//  others_algorithms.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/9.
//

#ifndef others_algorithms_h
#define others_algorithms_h

#include <stdio.h>
#include <stdbool.h>

/// 计算x的平方根，如果是小数则忽略小数
int mySqrt(int x);


/// 反转整数x（如：123->321）
int reverseNum(int x);

/// 给定一个二维网格和一个单词，找出该单词是否存在于网格中
// 示例:
// board =
// [
//     ['A','B','C','E'],
//     ['S','F','C','S'],
//     ['A','D','E','E']
// ]
//
// 给定 word = "ABCCED", 返回 true
// 给定 word = "SEE", 返回 true
// 给定 word = "ABCB", 返回 false
bool exist(char** board, int boardSize, int* boardColSize, char * word);

#endif /* others_algorithms_h */
