//
// Created by Ábrahám Dávid on 2026. 05. 02..
//

#include "../../include/data_structures/regular_queue.h"

#include <limits.h>

#include "../../include/_utils/constants.h"

#include <stdio.h>
#include <stdlib.h>


void create_queue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;

    queue->elements = (int *) calloc(capacity, sizeof(int));

    if (!queue->elements) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }
}


void destroy_queue(Queue *queue) {
    queue->capacity = 0;
    queue->front = queue->rear = -1;
    free(queue->elements);
    queue = NULL;
}


void display_queue(const Queue *queue) {
    if (queue_is_empty(queue)) return;

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%i ", queue->elements[i]);
    }

    printf("\n");
}


bool queue_is_full(const Queue *queue) {
    return queue->rear == queue->capacity - 1;
}


bool queue_is_empty(const Queue *queue) {
    return queue->front == -1;
}


void queue_enqueue(Queue *queue, int element) {
    if (queue_is_full(queue)) {
        printf("%s", ERR_MSG_DS_FULL);
        return;
    }

    if (queue_is_empty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->elements[queue->rear] = element;
}


int queue_dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return INT_MIN;
    }

    if (queue->front == queue->rear) {
        int pos = queue->front;
        queue->front = queue->rear = -1;

        return queue->elements[pos];
    }

    return queue->elements[queue->front++];
}
