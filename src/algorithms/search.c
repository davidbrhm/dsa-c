//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

#include "../../include/algorithms/search.h"

int linear_search(const int *arr, int size, int target) {
    if (!arr || size <= 0) return -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int binary_search(const int *arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    int center = left + (right - left) / 2;

    while (left <= right) {
        if (arr[center] > target) {
            right = center - 1;
        } else if (arr[center] < target) {
            left = center + 1;
        } else {
            return center;
        }

        center = (left + right) / 2;
    }

    return -1;
}

