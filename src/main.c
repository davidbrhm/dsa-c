#include <stdio.h>

#include "../include/matrix.h"
#include "../include/constants.h"

int main(void) {
    /*
    int n, *pArray;
    read_array(&n, &pArray, "be.txt");
    print_array(n, pArray, "CON");
    destroy_array(&pArray);
    */

    // matrix
    int rows = 3, cols = 5, **pMatrix;
    //pMatrix = allocate_memory_for_matrix1(rows, cols);
    //allocate_memory_for_matrix2(rows, cols, &pMatrix);
    read_matrix(&rows, &cols, &pMatrix, "./matrix.txt");

    print_matrix(rows, cols, pMatrix, "CON");
    destroy_matrix(rows, &pMatrix);
    return 0;
}
