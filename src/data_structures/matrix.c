//
// Created by Ábrahám Dávid on 2026. 05. 02..
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../../include/matrix.h"
#include "../../include/constants.h"


#define CONSOLE_KEYWORD "CON"

int *allocate_memory_for_array1(int n) {
    int *pArray = malloc(n * sizeof(int));

    if (!pArray) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    return pArray;
}

// dp_arr = double pointer to an array
void allocate_memory_for_array2(int n, int **dp_arr) {
    *dp_arr = malloc(n * sizeof(int));

    if (!*dp_arr) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void read_array(int *pn, int **dp_arr, const char *input) {
    FILE *in;

    if (strcmp(input, CONSOLE_KEYWORD) == 0) {
        in = stdin;
    } else {
        in = fopen(input, "r");

        if (!in) {
            printf("%s", FILE_OPENING_ERROR_MESSAGE);
            exit(FILE_OPENING_ERROR_CODE);
        }
    }

    if (fscanf(in, "%i", pn) != 1) {
        if (in != stdin) fclose(in);
        return;
    }

    allocate_memory_for_array2(*pn, dp_arr);

    for (int i = 0; i < *pn; i++) {
        fscanf(in, "%i", *dp_arr + i);
    }

    if (in != stdin) {
        fclose(in);
    }
}

void print_array(int n, int *p_arr, const char *output) {
    FILE *out;

    if (strcmp(output, CONSOLE_KEYWORD) == 0) {
        out = stdout;
    } else {
        out = fopen(output, "w");
        if (!out) {
            printf("fopen error");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        fprintf(out, "%i ", p_arr[i]);
    }
    fprintf(out, "\n");

    if (out != stdout) {
        fclose(out);
    }
}

void deallocate_memory_for_array(int **dp_arr) {
    free(*dp_arr);
    *dp_arr = NULL;
}

int **allocate_memory_for_matrix1(int rows, int cols) {
    int **pMatrix = (int **) calloc(rows, sizeof(int *));
    if (!pMatrix) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    for (int i = 0; i < rows; i++) {
        pMatrix[i] = (int *) calloc(cols, sizeof(int));

        if (!pMatrix[i]) {
            printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }

    return pMatrix;
}

void allocate_memory_for_matrix2(int rows, int cols, int ***dp_matrix) {
    *dp_matrix = (int**) calloc(rows, sizeof(int*));

    if (!*dp_matrix) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    for (int i = 0; i < rows; i++) {
        (*dp_matrix)[i] = (int *) calloc(cols, sizeof(int));

        if (!(*dp_matrix)[i]) {
            printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
            exit(MEMORY_ALLOCATION_ERROR_CODE);
        }
    }
}

void print_matrix(int rows, int cols, int **p_matrix, const char *output) {
    FILE *out;
    if (strcmp(output, CONSOLE_KEYWORD) == 0) {
        out = stdout;
    } else {
        out = fopen(output, "w");
        if (!out) {
            printf("fopen error");
            return;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(out, "%5i", p_matrix[i][j]);
        }
        fprintf(out, "\n");
    }

    if (out != stdout) {
        fclose(out);
    }
}

void destroy_matrix(int rows, int ***dp_matrix) {
    for (int i = 0; i < rows; i++) {
        free((*dp_matrix)[i]);
    }

    free(*dp_matrix);
    *dp_matrix = NULL;
}

void read_matrix(int *p_rows, int *p_cols, int ***dp_matrix, const char *input) {
    FILE *in;
    if (strcmp(input, CONSOLE_KEYWORD) == 0) {
        in = stdin;
    } else {
        in = fopen(input, "r");
        if (!in) {
            printf("%s", FILE_OPENING_ERROR_MESSAGE);
            exit(FILE_OPENING_ERROR_CODE);
        }
    }

    fscanf(in, "%i %i", p_rows, p_cols);

    allocate_memory_for_matrix2(*p_rows, *p_cols, dp_matrix);

    for (int i = 0; i < *p_rows; i++) {
        for (int j = 0; j < *p_cols; j++) {
            fscanf(in, "%i", &((*dp_matrix)[i][j]));
        }
    }

    if (in != stdin) {
        fclose(in);
    }
}

