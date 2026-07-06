//
// Created by Ábrahám Dávid on 2026. 05. 18..
//


#include "../../../include/leetcode/leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *create_tnode(int val) {
    struct TreeNode *new_node = (struct TreeNode*) calloc(1, sizeof(struct TreeNode));
    new_node->left = new_node->right = NULL;
    new_node->val = val;

    return new_node;
}

struct TreeNode *bst_builder(int *nums, int left, int right) {
    if (left > right) return NULL;

    int center = left + (right - left) / 2;

    struct TreeNode *node = create_tnode(nums[center]);
    node->left = bst_builder(nums, left, center - 1);
    node->right = bst_builder(nums, center + 1, right);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;

    return bst_builder(nums, 0, numsSize - 1);
}
