//
// Created by Ábrahám Dávid on 2026. 05. 02..
//


#include <stdio.h>
#include <stdlib.h>

#include "../../include/constants.h"
#include "../../include/array.h"


IntArray *create_array(int capacity) {
    IntArray *arr = malloc(sizeof(IntArray) + (capacity * sizeof(int)));

    if (!arr) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    arr->capacity = capacity;
    arr->size = 0;

    return arr;
}


void destroy_array(IntArray *arr) {
    if (arr != NULL)
        free(arr);
}

bool array_is_full(IntArray *p_arr) {
    return p_arr->size == p_arr->capacity;
}

bool array_is_empty(IntArray *p_arr) {
    return p_arr->size == 0;
}

int array_at(IntArray *p_arr, int index) {
    if (index < 0 || index > p_arr->size) {
        printf("%s", ERR_MSG_OUT_OF_BOUNDS);
        exit(-1);
    }

    return p_arr->elements[index];
}

void array_insert_last(IntArray *p_arr, int element) {
    if (array_is_full(p_arr)) {
        printf("%s", ERR_MSG_DS_FULL);
        return;
    }

    p_arr->elements[p_arr->size++] = element;
}

void array_insert_at(IntArray *p_arr, int index, int element) {
    if (array_is_full(p_arr)) {
        printf("%s", ERR_MSG_DS_FULL);
        return;
    }
    if (index < 0 || index >= p_arr->size) {
        printf("%s", ERR_MSG_OUT_OF_BOUNDS);
        return;
    }

    if (index == p_arr->size) {
        array_insert_last(p_arr, element);
    } else {
        for (int i = p_arr->size; i > index; i--) {
            p_arr->elements[i] = p_arr->elements[i - 1];
        }

        p_arr->elements[index] = element;
        p_arr->size++;
    }
}

void array_insert_first(IntArray *p_arr, int element) {
    array_insert_at(p_arr, 0, element);
}

void array_pop(IntArray *p_arr, int index) {
    if (array_is_empty(p_arr)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return;
    }
    if (index < 0 || index >= p_arr->size) {
        printf("%s", ERR_MSG_OUT_OF_BOUNDS);
        return;
    }

    // p_arr->elements[index] = p_arr->elements[--p_arr->size]; // O(1)
    for (int i = index; i < p_arr->size - 1; i++) {
        p_arr->elements[i] = p_arr->elements[i + 1];
    }
    p_arr->size--;
}

int array_search(IntArray *p_arr, int target) {
    if (array_is_empty(p_arr)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return -1;
    }

    for (int i = 0; i < p_arr->size; i++) {
        if (p_arr->elements[i] == target)
            return i;
    }

    return -1;
}

bool array_update(IntArray *p_arr, int index, int element) {
    if (index < 0 || index >= p_arr->size) {
        printf("%s", ERR_MSG_OUT_OF_BOUNDS);
        return false;
    }

    p_arr->elements[index] = element;
    return true;
}
