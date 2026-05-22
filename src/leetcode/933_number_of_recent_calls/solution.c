//
// Created by Ábrahám Dávid on 2026. 05. 22..
//

#include <stdlib.h>

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/

#define CAPACITY 10000

typedef struct {
    int front;
    int rear;
    int requests[CAPACITY];
} RecentCounter;


RecentCounter *recentCounterCreate() {
    RecentCounter *new_rc = (RecentCounter *) malloc(sizeof(RecentCounter));

    new_rc->front = new_rc->rear = 0;

    return new_rc;
}

int recentCounterPing(RecentCounter *obj, int t) {
    obj->requests[obj->rear++] = t;

    while (obj->requests[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter *obj) {
    free(obj);
}
