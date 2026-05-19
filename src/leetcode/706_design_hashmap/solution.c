//
// Created by Ábrahám Dávid on 2026. 05. 19..
//

#include <stdlib.h>

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/

#define CAPACITY 10007

typedef struct DHTNode {
    int key;
    int val;
    struct DHTNode *next;
} DHTNode;

typedef struct {
    DHTNode *items[CAPACITY];
} MyHashMap;


int hash(int key) {
    unsigned int hash = (unsigned int) abs(key) * 2654435761u;
    return hash % CAPACITY;
}

MyHashMap *myHashMapCreate() {
    MyHashMap *hash_map = (MyHashMap *) calloc(1, sizeof(MyHashMap));
    return hash_map;
}

void myHashMapPut(MyHashMap *obj, int key, int value) {
    if (!obj) return;

    int index = hash(key);
    DHTNode *curr = obj->items[index];

    while (curr) {
        if (curr->key == key) {
            curr->val = value;
            return;
        }
        curr = curr->next;
    }

    DHTNode *new_item = (DHTNode *) calloc(1, sizeof(DHTNode));
    new_item->val = value;
    new_item->key = key;

    new_item->next = obj->items[index];
    obj->items[index] = new_item;
}

int myHashMapGet(MyHashMap *obj, int key) {
    if (!obj) return -1;

    int index = hash(key);

    DHTNode *walker = obj->items[index];
    while (walker) {
        if (walker->key == key)
            return walker->val;

        walker = walker->next;
    }

    return -1;
}

void myHashMapRemove(MyHashMap *obj, int key) {
    if (!obj) return;

    int index = hash(key);

    DHTNode *curr = obj->items[index];
    DHTNode *prev = NULL;
    if (!curr) return;

    while (curr) {
        if (curr->key == key) {
            if (prev == NULL)
                obj->items[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void myHashMapFree(MyHashMap *obj) {
    if (!obj) return;

    for (int i = 0; i < CAPACITY; i++) {
        DHTNode *curr = obj->items[i];

        while (curr) {
            DHTNode *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free(obj);
}
