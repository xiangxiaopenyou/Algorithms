//
//  node_tree.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/16.
//

#include "node_tree.h"
#include <stdio.h>
#include <stdlib.h>



TreeNode* invertTree(TreeNode* root){
    if (root == NULL) {
        return NULL;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

/// 二叉树深度
int TreeDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    return left > right ? (left + 1) : (right + 1);
}

bool isBalance(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    int leftDepth = TreeDepth(left);
    int rightDepth = TreeDepth(right);
    return (abs(leftDepth - rightDepth) <= 1) && isBalance(left) && isBalance(right);
}
