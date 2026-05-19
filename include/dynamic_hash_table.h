//
// Created by Ábrahám Dávid on 2026. 05. 19..
//

#ifndef DSA_C_DYNAMIC_HASH_TABLE_H
#define DSA_C_DYNAMIC_HASH_TABLE_H

#define DHT_CAPACITY 31

typedef struct DHTItem {
    int key;
    int data;
    struct DHTItem *next;
} DHTItem;

typedef struct DynamicHashTable {
    DHTItem **items;
    int size;
} DynamicHashTable;

DynamicHashTable *create_dht();
void destroy_dht(DynamicHashTable *hash_table);
void display_dht(DynamicHashTable *hash_table);

void dht_insert(DynamicHashTable *hash_table, int key, int data);
int dht_search(DynamicHashTable *hash_table, int key);
void dht_remove(DynamicHashTable *hash_table, int key);

int dht_hash(int key);
int dht_get_size(DynamicHashTable *hash_table);


#endif //DSA_C_DYNAMIC_HASH_TABLE_H
