//
// Created by Ábrahám Dávid on 2026. 05. 04..
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
} MyCircularQueue;


MyCircularQueue *myCircularQueueCreate(int k) {
    MyCircularQueue *cq = malloc(sizeof(MyCircularQueue));
    cq->elements = malloc(sizeof(int) * k);
    cq->front = cq->rear = -1;
    cq->capacity = k;

    return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj) {
    return obj->front == -1;
}

bool myCircularQueueIsFull(MyCircularQueue *obj) {
    return (obj->rear + 1) % obj->capacity == obj->front;
}

int myCircularQueueFront(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->elements[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    return obj->elements[obj->rear];
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    if (myCircularQueueIsEmpty(obj))
        obj->front = 0;

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->elements[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }

    return true;
}

void myCircularQueueFree(MyCircularQueue *obj) {
    free(obj->elements);
    free(obj);
    obj = NULL;
}
