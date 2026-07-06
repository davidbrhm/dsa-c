//
// Created by Ábrahám Dávid on 2026. 05. 18..
//

#ifndef DSA_C_HASH_TABLE_H
#define DSA_C_HASH_TABLE_H

#define CAPACITY 31

typedef struct HashItem {
    int key;
    int data;
} HashItem;

typedef struct HashTable {
    HashItem *items;
    int size;
} HashTable;

HashTable *create_hash_table();
void destroy_hash_table(HashTable *hash_table);
void display_hash_table(HashTable *hash_table);

void ht_insert(HashTable *hash_table, int key, int data);
int ht_search(HashTable *hash_table, int key);
void ht_remove(HashTable *hash_table, int key);
int ht_get_size(HashTable *hash_table);

#endif //DSA_C_HASH_TABLE_H
