//
// Created by Ábrahám Dávid on 2026. 05. 02..
//

#ifndef DSA_C_REGULAR_QUEUE_H
#define DSA_C_REGULAR_QUEUE_H
#include <stdbool.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
} Queue;

void create_queue(int capacity, Queue *queue);
void destroy_queue(Queue *queue);
void display_queue(const Queue *queue);

bool queue_is_full(const Queue *queue);
bool queue_is_empty(const Queue *queue);
void queue_enqueue(Queue *queue, int element);
int queue_dequeue(Queue *queue);


#endif //DSA_C_REGULAR_QUEUE_H
