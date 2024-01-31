//
//  node_tree.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/16.
//

#ifndef node_tree_h
#define node_tree_h

#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

/// 翻转二叉树
TreeNode* invertTree(TreeNode* root);

/// 判断是否平衡二叉树
bool isBalance(struct TreeNode* root);

#endif /* node_tree_h */
