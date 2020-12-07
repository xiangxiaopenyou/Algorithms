//
//  list_node.c
//  经典算法
//
//  Created by zhangdu_imac on 2020/12/2.
//

#include "list_node.h"

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 

struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode *Node;
    Node new_header = NULL, old_header = head, temp;
    while (old_header) {
        temp = old_header->next;
        old_header->next = new_header;
        new_header = old_header;
        old_header = temp;
    }
    head = new_header;
    return head;
}
