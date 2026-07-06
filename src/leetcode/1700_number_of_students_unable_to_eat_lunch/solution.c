//
// Created by Ábrahám Dávid on 2026. 05. 02..
//

#include <stdlib.h>
#include <string.h>

#include "../../../include/data_structures/circular_queue.h"

void init_cq(CircularQueue *cq, int *arr, int n) {
    cq->elements = malloc((n + 1) * sizeof(int));
    memcpy(cq->elements, arr, n * sizeof(int));

    cq->capacity = n + 1;
    cq->front = 0;
    cq->rear = n - 1;
}

int cq_first(CircularQueue *cq) {
    return cq->elements[cq->front];
}

int countStudents(int *students, int studentsSize, int *sandwiches, int sandwichesSize) {
    CircularQueue cqueue;
    init_cq(&cqueue, students, studentsSize);

    int max_lim = studentsSize;
    int top_sw = 0;

    while (max_lim > 0 && top_sw < sandwichesSize) {
        if (cq_first(&cqueue) == sandwiches[top_sw]) {
            top_sw++;
            cqueue_dequeue(&cqueue);
            max_lim = studentsSize - top_sw;
        } else {
            cqueue_enqueue(&cqueue, cqueue_dequeue(&cqueue));
            max_lim--;
        }

    }

    destroy_cqueue(&cqueue);
    return sandwichesSize - top_sw;
}
