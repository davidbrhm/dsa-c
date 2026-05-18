//
// Created by Ábrahám Dávid on 2026. 05. 10..
//

#ifndef DSA_C_LIST_NODE_H
#define DSA_C_LIST_NODE_H
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct CallStack {
    int top;
    struct TreeNode **nodes;
} CallStack;
#endif //DSA_C_LIST_NODE_H
