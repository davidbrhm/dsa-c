//
// Created by Ábrahám Dávid on 2026. 05. 18..
//


#include "../../../include/_leetcode.h"
#include "../../../include/hash_table.h"

/*
typedef struct HashItem {
    int key;
    int data;
} HashItem;

typedef struct HashTable {
    HashItem *items;
    int size;
} HashTable;
*/

static const char *row1 = "qwertyuiopQWERTYUIOP";
static const char *row2 = "asdfghjklASDFGHJKL";
static const char *row3 = "zxcvbnmZXCVBNM";

int get_key(char ch) {
    return (int) (unsigned char) ch;
}

void fill(HashTable *hash_table, const char *row, int data) {
    while (*row) {
        HashItem item = {get_key(*row), data};
        hash_table->items[item.key] = item;
        hash_table->size++;
        row++;
    }
}

HashTable *get_row_map() {
    HashTable *row_map = (HashTable *) calloc(1, sizeof(HashTable));
    row_map->items = (HashItem *) calloc(256, sizeof(HashItem));
    row_map->size = 0;

    fill(row_map, row1, 1);
    fill(row_map, row2, 2);
    fill(row_map, row3, 3);

    return row_map;
}

char **findWords(char **words, int wordsSize, int *returnSize) {
    HashTable *row_map = get_row_map();

    char **result = (char **) calloc(wordsSize, sizeof(char *));
    *returnSize = 0;

    for (int i = 0; i < wordsSize; i++) {
        char *current = words[i];

        int target_row = row_map->items[get_key(current[0])].data;
        bool is_valid = true;

        for (int j = 1; current[j] != '\0'; j++) {
            int current_row = row_map->items[get_key(current[j])].data;

            if (current_row != target_row) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            result[(*returnSize)++] = current;
        }
    }

    free(row_map->items);
    free(row_map);
    return result;
}
