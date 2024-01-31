//
//  list_node.h
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/2.
//

#ifndef list_node_h
#define list_node_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList5(struct ListNode* head);

/// 反转链表
struct ListNode* reverseList(struct ListNode* head);

/// 两数相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif /* list_node_h */
