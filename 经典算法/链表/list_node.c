//
//  list_node.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/2.
//

#include "list_node.h"
#include <stdlib.h>
#include <math.h>

struct ListNode* reverseList5(struct ListNode* head) {
    struct ListNode *res = head;
    struct ListNode *pre = NULL;
    while (res) {
        struct ListNode *temp = res->next;
        res->next = pre;
        pre = res;
        res = temp;
    }
    return pre;
}


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previous = NULL;
    struct ListNode *current = head;
    while (current) {
        // 缓存当前节点的下一个节点
        struct ListNode *next = current->next;
        
        current->next = previous;
        
        previous = current;
        
        current = next;
    }
    return previous;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 翻转链表
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    struct ListNode *t1 = l1;
    struct ListNode *t2 = l2;
    int sum = 0;
    // 进位数
    int c = 0;
    
    struct ListNode *resNode = NULL;
    while (t1 != NULL || t2 != NULL) {
        int num1 = t1 != NULL ? t1->val : 0;
        int num2 = t2 != NULL ? t2->val : 0;
        sum = num1 + num2 + c;
        c = sum / 10;
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = resNode;
        resNode = node;
        if (t1 != NULL) {
            t1 = t1->next;
        }
        if (t2 != NULL) {
            t2 = t2->next;
        }
    }
    if (c > 0) {
        struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = c;
        node->next = resNode;
        resNode = node;
    }
    return resNode;
    
    
//    int length1 = 0;
//    struct ListNode *t1 = l1;
//    while (t1) {
//        length1++;
//        t1 = t1->next;
//    }
//    
//    int length2 = 0;
//    struct ListNode *t2 = l2;
//    while (t2) {
//        length2++;
//        t2 = t2->next;
//    }
//    int num1 = 0;
//    for (int i = length1; i > 0; i--) {
//        num1 += l1->val * pow(10, i);
//    }
//    int num2 = 0;
//    for (int i = length2; i > 0; i--) {
//        num2 += l2->val * pow(10, i);
//    }
//    int res = num1 + num2;
//    struct ListNode *currentNode = (struct ListNode *)malloc(sizeof(struct ListNode));
//    while (res > 0) {
//        int r = res % 10;
//        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));;
//        node->val = r;
//        node->next = NULL;
//        if (currentNode != NULL) {
//            currentNode = node;
//        } else {
//            struct ListNode *temp = currentNode;
//            currentNode = node;
//            node->next = temp;
//        }
//        res = res / 10;
//    }
//    return currentNode;
}
