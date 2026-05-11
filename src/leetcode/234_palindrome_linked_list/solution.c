//
// Created by Ábrahám Dávid on 2026. 05. 10..
//

#include <stdbool.h>
#include <stddef.h>

#include "../../../include/_leetcode.h"

bool isPalindrome(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    // slow fast pointer algorithm
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }


    struct ListNode *prev = NULL;
    struct ListNode *temp = NULL;
    struct ListNode *current = slow;
    while (current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    struct ListNode *tail = prev;
    while (tail != NULL) {
        if (tail->val != head->val)
            return false;

        tail = tail->next;
        head = head->next;
    }

    return true;
}
