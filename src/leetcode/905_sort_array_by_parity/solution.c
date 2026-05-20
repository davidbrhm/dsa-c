//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParity(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *left = nums;
    int *right = nums + numsSize - 1;

    while (left < right) {
        while (left < right && *left % 2 == 0)
            left++;
        while (left < right && *right % 2 != 0)
            right--;

        if (left < right) {
            int temp = *left;
            *left = *right;
            *right = temp;

            left++;
            right--;
        }
    }

    return nums;
}
