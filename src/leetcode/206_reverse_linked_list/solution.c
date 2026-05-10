//
// Created by Ábrahám Dávid on 2026. 05. 10..
//

#include <stddef.h>

#include "../../../include/list_node.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    while (current != NULL) {
        struct ListNode *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}