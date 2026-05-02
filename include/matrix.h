//
// Created by Ábrahám Dávid on 2026. 05. 02..
//


#ifndef DSA_C_ARRAY_H
#define DSA_C_ARRAY_H

/*
int* allocate_memory_for_array1(int n);
void allocate_memory_for_array2(int n, int **dp_arr);
void read_array(int *pn, int **dp_arr, const char *input);
void print_array(int n, int *p_arr, const char *output);
void destroy_array(int **dp_arr);
*/

int** allocate_memory_for_matrix1(int rows, int cols);
void allocate_memory_for_matrix2(int rows, int cols, int*** dp_matrix);
void print_matrix(int rows, int cols, int **p_matrix, const char *output);
void destroy_matrix(int rows, int ***dp_matrix);
void read_matrix(int *p_rows, int *p_cols, int ***dp_matrix, const char *input);

#endif //DSA_C_ARRAY_H
