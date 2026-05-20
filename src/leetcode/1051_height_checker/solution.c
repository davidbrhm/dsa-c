//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

#include <stdlib.h>
#include <string.h>

static int compare_ints(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int heightChecker(int *heights, int heightsSize) {
    int *sorted = (int *) malloc(heightsSize * sizeof(int));

    memcpy(sorted, heights, sizeof(int) * heightsSize);
    qsort(sorted, heightsSize, sizeof(int), compare_ints);

    int count = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != sorted[i]) count++;
    }

    free(sorted);
    return count;
}
