//
// Created by Ábrahám Dávid on 2026. 05. 11..
//

#include "../../../include/_leetcode.h"
#include <stddef.h>

int sumOfLeftLeaves(struct TreeNode *root) {
    if (root == NULL) return 0;

    int sum = 0;
    if (root->left != NULL && (root->left->right == NULL && root->left->left == NULL)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}
