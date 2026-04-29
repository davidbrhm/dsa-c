//
// Created by Ábrahám Dávid on 2026. 04. 29..
//

int count(int *nums, int numsSize, int target) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) count++;
    }

    return count;
}

int majorityElementN2(int *nums, int numsSize) {
    int half = (numsSize / 2) + 1;

    for (int i = 0; i < numsSize; i++) {
        if (count(nums, numsSize, nums[i]) >= half)
            return nums[i];
    }

    return -1;
}

// Boyer–Moore majority vote algorithm
int majorityElement(int *nums, int numSize) {
    int n = nums[0];
    int votes = 1;

    for (int i = 1; i < numSize; i++) {
        if (votes == 0)
            n = nums[i];

        if (n == nums[i])
            votes++;
        else
            votes--;
    }

    return n;
}
