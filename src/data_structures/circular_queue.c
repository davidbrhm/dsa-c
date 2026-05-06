//
// Created by Ábrahám Dávid on 2026. 05. 04..
//

#include "../../include/constants.h"
#include "../../include/circular_queue.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


void create_cqueue(int capacity, CircularQueue *cqueue) {
    cqueue->capacity = capacity;
    cqueue->front = cqueue->rear = -1;

    cqueue->elements = (int *) calloc(capacity, sizeof(int));

    if (!cqueue->elements) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }
}

void destroy_cqueue(CircularQueue *cqueue) {
    free(cqueue->elements);

    cqueue->front = cqueue->rear = -1;
    cqueue->capacity = 0;
    cqueue = NULL;
}

bool cqueue_is_full(const CircularQueue *cqueue) {
    return (cqueue->rear + 1) % cqueue->capacity == cqueue->front;
}

bool cqueue_is_empty(const CircularQueue *cqueue) {
    return cqueue->front == -1;
}

void cqueue_enqueue(CircularQueue *cqueue, int element) {
    if (cqueue_is_full(cqueue)) {
        printf("%s", ERR_MSG_DS_FULL);
        return;
    }
    if (cqueue_is_empty(cqueue))
        cqueue->front = 0;

    cqueue->rear = (cqueue->rear + 1) % cqueue->capacity; // handle overflow
    cqueue->elements[cqueue->rear] = element;
}

int cqueue_dequeue(CircularQueue *cqueue) {
    if (cqueue_is_empty(cqueue)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return INT_MIN;
    }

    const int save = cqueue->elements[cqueue->front];
    if (cqueue->front == cqueue->rear) {
        cqueue->front = cqueue->rear = -1;
    } else {
        cqueue->front = (cqueue->front + 1) % cqueue->capacity;
    }

    return save;
}

void display_cqueue(const CircularQueue *cqueue) {
    if (cqueue_is_empty(cqueue)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return;
    }

    int i = cqueue->front;
    do {
        printf("%i ", cqueue->elements[i]);
        i = (i + 1) % cqueue->capacity;
    } while (i != (cqueue->rear + 1) % cqueue->capacity);
    printf("\n");
}

void display_cqueue2(const CircularQueue *cqueue) {
    if (cqueue_is_empty(cqueue)) {
        printf("%s\n", ERR_MSG_DS_EMPTY);
        return;
    }

    int count = (cqueue->rear + cqueue->capacity - cqueue->front) % cqueue->capacity + 1;

    int idx = cqueue->front;

    for (int step = 0; step < count; step++) {
        printf("%i ", cqueue->elements[idx]);
        idx = (idx + 1) % cqueue->capacity;
    }
    printf("\n");
}
