//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify(int *nums, int size, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && nums[left] > nums[largest]) {
        largest = left;
    }
    if (right < size && nums[right] > nums[largest]) {
        largest = right;
    }

    if (largest != idx) {
        swap(&nums[idx], &nums[largest]);
        heapify(nums, size, largest);
    }
}

// heap sort
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize <= 1) return nums;

    for (int i = numsSize / 2 - 1; i >= 0; i--) {
        heapify(nums, numsSize, i);
    }

    for (int i = numsSize - 1; i > 0; i--) {
        swap(&nums[0], &nums[i]);

        heapify(nums, i, 0);
    }

    return nums;
}
