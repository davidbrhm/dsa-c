//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

#include "../../include/algorithms/sort.h"

#include <stdlib.h>

void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}


static void merge(int *arr, int *temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

static void merge_sort_rec(int *arr, int *temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_rec(arr, temp, left, mid);
        merge_sort_rec(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void merge_sort(int *arr, int size) {
    if (size <= 1) return;

    int *temp = (int *) malloc(size * sizeof(int));
    merge_sort_rec(arr, temp, 0, size - 1);
    free(temp);
}


static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

static void quick_sort_rec(int *arr, int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);

        quick_sort_rec(arr, left, pi - 1);
        quick_sort_rec(arr, pi + 1, right);
    }
}

void quick_sort(int *arr, int size) {
    if (size <= 1) return;
    quick_sort_rec(arr, 0, size - 1);
}


void counting_sort(int *arr, int size) {
    if (size <= 1) return;

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int *count = (int *) calloc(max + 1, sizeof(int));

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int idx = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[idx++] = i;
            count[i]--;
        }
    }

    free(count);
}


static void counting_sort_for_radix(int *arr, int size, int exp) {
    int *output = (int *) malloc(size * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(output);
}

void radix_sort(int *arr, int size) {
    if (size <= 1) return;

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        counting_sort_for_radix(arr, size, exp);
    }
}
