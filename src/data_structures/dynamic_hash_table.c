//
// Created by Ábrahám Dávid on 2026. 05. 19..
//

#include "../../include/dynamic_hash_table.h"
#include "../../include/constants.h"

#include <stdio.h>
#include <stdlib.h>


int dht_hash(int key) {
    // return abs(key) % DHT_CAPACITY;;

    // Knuth's multiplicative hashing
    unsigned int hash = (unsigned int) abs(key) * 2654435761u;
    return hash % DHT_CAPACITY;
}

int dht_get_size(DynamicHashTable *hash_table) {
    return hash_table->size;
}

DynamicHashTable *create_dht() {
    DynamicHashTable *new_dht = (DynamicHashTable *) calloc(1, sizeof(DynamicHashTable));
    if (!new_dht) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_dht->items = (DHTItem **) calloc(DHT_CAPACITY, sizeof(DHTItem *));
    if (!new_dht->items) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_dht->size = 0;

    return new_dht;
}

void destroy_dht(DynamicHashTable *hash_table) {
    if (!hash_table) return;

    for (int i = 0; i < DHT_CAPACITY; i++) {
        DHTItem *curr = hash_table->items[i];

        while (curr) {
            DHTItem *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free(hash_table->items);
    free(hash_table);
}

void display_dht(DynamicHashTable *hash_table) {
    if (!hash_table) return;
    for (int i = 0; i < DHT_CAPACITY; i++) {
        printf("Bucket [%d]: ", i);
        DHTItem *walker = hash_table->items[i];
        while (walker) {
            printf("(Key: %d, Data: %d) -> ", walker->key, walker->data);
            walker = walker->next;
        }
        printf("NULL\n");
    }
    printf("Total Size: %d\n--------------------------\n", hash_table->size);
}

DHTItem *create_dht_item(int key, int data) {
    DHTItem *new_item = calloc(1, sizeof(DHTItem));
    if (!new_item) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_item->key = key;
    new_item->data = data;
    new_item->next = NULL;

    return new_item;
}

void dht_insert(DynamicHashTable *hash_table, int key, int data) {
    if (!hash_table) return;

    int index = dht_hash(key);
    DHTItem *new_item = create_dht_item(key, data);

    new_item->next = hash_table->items[index];
    hash_table->items[index] = new_item;
    hash_table->size++;
}

int dht_search(DynamicHashTable *hash_table, int key) {
    if (!hash_table || dht_get_size(hash_table) == 0) return -1;

    int index = dht_hash(key);

    DHTItem *walker = hash_table->items[index];
    while (walker != NULL) {
        if (walker->key == key)
            return walker->data;

        walker = walker->next;
    }

    return -1;
}

void dht_remove(DynamicHashTable *hash_table, int key) {
    if (!hash_table || dht_get_size(hash_table) == 0) return;

    int index = dht_hash(key);
    DHTItem *curr = hash_table->items[index];
    DHTItem *prev = NULL;
    if (curr == NULL) return;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL)
                hash_table->items[index] = curr->next;
            else
                prev->next = curr->next;

            free(curr);
            hash_table->size--;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}
