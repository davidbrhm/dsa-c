//
// Created by Ábrahám Dávid on 2026. 05. 18..
//

#include "../../../include/leetcode/leetcode.h"

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *curr = root;
    while (curr != NULL && curr->val != val) {
        if (curr->val > val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return curr;
}
