//
// Created by Ábrahám Dávid on 2026. 05. 18..
//

#include "../../include/hash_table.h"
#include "../../include/constants.h"

#include <stdio.h>
#include <stdlib.h>

static const HashItem DUMMY_ITEM = {-1, 0};

int ht_hash_code(int key) {
    return key % CAPACITY;
}

HashTable *create_hash_table() {
    HashTable *new_hs = (HashTable *) calloc(1, sizeof(HashTable));
    if (!new_hs) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_hs->items = (HashItem *) calloc(CAPACITY, sizeof(HashItem));
    if (!new_hs->items) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_hs->size = 0;
    for (int i = 0; i < CAPACITY; i++) {
        new_hs->items[i] = DUMMY_ITEM;
    }

    return new_hs;
}

void destroy_hash_table(HashTable *hash_table) {
    if (hash_table == NULL) return;
    free(hash_table->items);
    free(hash_table);
}

void display_hash_table(HashTable *hash_table) {
    if (ht_get_size(hash_table) == 0) {
        printf("HashTable is empty!");
        return;
    }

    printf("%-6s | %-10s | %-10s | %-4s\n", "Index", "Key", "Value", "Hash");
    printf("-------+------------+------------+------\n");
    for (int i = 0; i < CAPACITY; i++) {
        if (hash_table->items[i].key != DUMMY_ITEM.key) {
            printf("%-6d | %-10d | %-10d | %-4d\n",
                   i,
                   hash_table->items[i].key,
                   hash_table->items[i].data,
                   ht_hash_code(hash_table->items[i].key));
        }
    }
}

void ht_insert(HashTable *hash_table, int key, int data) {
    if (hash_table->size == CAPACITY) {
        printf("HashTable is full!");
        return;
    }

    HashItem new_item = {key, data};
    int index = ht_hash_code(key);
    int step = 0;
    while (hash_table->items[(index + step) % CAPACITY].key != DUMMY_ITEM.key) {
        step++;
    }

    hash_table->items[(index + step) % CAPACITY] = new_item;
    hash_table->size++;
}

int ht_search(HashTable *hash_table, int key) {
    int index = ht_hash_code(key);
    int step = 0;

    while (step < CAPACITY) {
        int idx = (index + step) % CAPACITY;

        if (hash_table->items[idx].key == key) {
            return idx;
        }

        if (hash_table->items[idx].key == DUMMY_ITEM.key) {
            return -1;
        }

        step++;
    }

    return -1;
}

void ht_remove(HashTable *hash_table, int key) {
    // Broken chain issue
    int pos = ht_search(hash_table, key);
    if (pos == -1) return;

    hash_table->items[pos] = DUMMY_ITEM;
    hash_table->size--;
}

int ht_get_size(HashTable *hash_table) {
    return hash_table->size;
}
