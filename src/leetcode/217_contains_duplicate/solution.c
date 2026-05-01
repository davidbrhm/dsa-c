//
// Created by Ábrahám Dávid on 2026. 05. 01..
//

#include <stdbool.h>
#include <stdlib.h>

bool containsDuplicateN2(int* nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}

static int compare(const void *a, const void *b) {
    int int_a = *(int *) a;
    int int_b = *(int *) b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}


bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i])
            return true;
    }

    return false;
}

