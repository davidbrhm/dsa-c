//
// Created by Ábrahám Dávid on 2026. 05. 10..
//

#include <stddef.h>

#include "../../../include/leetcode/leetcode.h"

int getDecimalValue(struct ListNode* head) {
    int result = 0;

    while (head != NULL) {
        result = result * 2 + head->val;
        head = head->next;
    }

    return result;
}
