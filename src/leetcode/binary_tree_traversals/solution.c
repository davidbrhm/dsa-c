//
// Created by Ábrahám Dávid on 2026. 05. 16..
//

#include <stddef.h>
#include <stdlib.h>

#include "../../../include/leetcode/leetcode.h"

int *inorderTraversal(struct TreeNode *root, int *returnSize) {
    CallStack *call_stack = (CallStack *) calloc(1, sizeof(CallStack));
    call_stack->nodes = calloc(100, sizeof(struct TreeNode *)); // max 100
    call_stack->top = 0;

    *returnSize = 0;
    int *result = calloc(100, sizeof(int));

    struct TreeNode *curr = root;
    while (curr != NULL || call_stack->top > 0) {
        while (curr != NULL) {
            call_stack->nodes[call_stack->top++] = curr;
            curr = curr->left;
        }

        curr = call_stack->nodes[--call_stack->top];
        result[(*returnSize)] = curr->val;
        (*returnSize)++;
        curr = curr->right;
    }

    free(call_stack->nodes);
    free(call_stack);
    call_stack = NULL;
    return result;
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    CallStack *call_stack = (CallStack *) calloc(1, sizeof(CallStack));
    call_stack->nodes = calloc(100, sizeof(struct TreeNode *));
    call_stack->top = 0;

    *returnSize = 0;
    int *result = calloc(100, sizeof(int));

    call_stack->nodes[call_stack->top++] = root;
    while (call_stack->top > 0) {
        struct TreeNode *curr = call_stack->nodes[--call_stack->top];
        result[(*returnSize)++] = curr->val;

        if (curr->right)
            call_stack->nodes[call_stack->top++] = curr->right;
        if (curr->left)
            call_stack->nodes[call_stack->top++] = curr->left;
    }

    free(call_stack->nodes);
    free(call_stack);

    return result;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    CallStack *call_stack = (CallStack *) calloc(1, sizeof(CallStack));
    call_stack->nodes = calloc(100, sizeof(struct TreeNode *));
    call_stack->top = 0;

    int *result = calloc(100, sizeof(int));

    call_stack->nodes[call_stack->top++] = root;
    while (call_stack->top > 0) {
        struct TreeNode *curr = call_stack->nodes[--call_stack->top];
        result[(*returnSize)++] = curr->val;

        if (curr->left)
            call_stack->nodes[call_stack->top++] = curr->left;
        if (curr->right)
            call_stack->nodes[call_stack->top++] = curr->right;
    }

    int *left = &result[0];
    int *right = &result[*returnSize - 1];
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    free(call_stack->nodes);
    free(call_stack);

    return result;
}

