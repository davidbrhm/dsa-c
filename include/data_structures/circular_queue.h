//
// Created by Ábrahám Dávid on 2026. 05. 04..
//

#ifndef DSA_C_CIRCULAR_QUEUE_H
#define DSA_C_CIRCULAR_QUEUE_H
#include <stdbool.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
} CircularQueue;

void create_cqueue(int capacity, CircularQueue *cqueue);
void destroy_cqueue(CircularQueue *cqueue);
void display_cqueue(const CircularQueue *cqueue);

bool cqueue_is_full(const CircularQueue *cqueue);
bool cqueue_is_empty(const CircularQueue *cqueue);
void cqueue_enqueue(CircularQueue *cqueue, int element);
int cqueue_dequeue(CircularQueue *cqueue);

#endif //DSA_C_CIRCULAR_QUEUE_H
