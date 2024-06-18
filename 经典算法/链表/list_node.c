//
//  list_node.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/2.
//

#include "list_node.h"
#include <stdlib.h>
#include <math.h>


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


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    struct ListNode *result = head->next;
    struct ListNode *temp;
    while (fast != NULL) {
        temp = fast->next;
        fast->next = slow;
        if (temp == NULL) {
            // 双数最后一组数据，交换后设置尾节点的next节点为NULL
            slow->next = NULL;
            return result;
        } else if (temp->next == NULL) {
            // 单数最后一个节点直接设置为尾节点返回
            slow->next = temp;
            return result;
        } else {
            // 下一组 fast和slow
            slow->next = temp->next;
            slow = temp;
            fast = temp->next;
        }
    }
    return result;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
//    struct ListNode *cur = head;
//    while (list1 != NULL && list2 != NULL) {
//        if (list1->val >= list2->val) {
//            cur->next = list2;
//            list2 = list2->next;
//        } else {
//            cur->next = list1;
//            list1 = list1->next;
//        }
//        cur = cur->next;
//    }
//    // 合并剩下节点
//    cur->next = list1 == NULL ? list2 : list1;
//    return head->next;
    
    
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    } else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
