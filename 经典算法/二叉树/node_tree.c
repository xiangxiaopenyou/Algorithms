//
//  node_tree.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/11/16.
//

#include "node_tree.h"


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode *left = invertTree(root->left);
    struct TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}
