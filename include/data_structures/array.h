//
// Created by Ábrahám Dávid on 2026. 05. 02..
//

#ifndef DSA_C_ARRAY_H
#define DSA_C_ARRAY_H
#include <stdbool.h>

typedef struct {
    int capacity;
    int size;
    int elements[]; // flexible array member (FAM)
} IntArray;

IntArray* create_array(int size);
void destroy_array(IntArray *p_arr);
bool array_is_full(IntArray *p_arr);
bool array_is_empty(IntArray *p_arr);
int array_at(IntArray *p_arr, int index);
void array_insert_first(IntArray *p_arr, int element);
void array_insert_last(IntArray *p_arr, int element);
void array_insert_at(IntArray *p_arr, int index, int element);
void array_pop(IntArray *p_arr, int index);
int array_search(IntArray *p_arr, int target);
bool array_update(IntArray *p_arr, int index, int element);

#endif //DSA_C_ARRAY_H
