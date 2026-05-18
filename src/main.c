#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/hash_table.h"

int main(void) {
    HashTable *hash_table = create_hash_table();

    ht_insert(hash_table, 10, 100);
    ht_insert(hash_table, 41, 200);
    ht_insert(hash_table, 20, 300);

    printf("Size: %d\n", ht_get_size(hash_table));
    display_hash_table(hash_table);

    int index = ht_search(hash_table, 41);
    if (index != -1) {
        printf("\nFound index: %d\n", index);
        ht_remove(hash_table, 41);
    }

    printf("\nSize: %d\n", ht_get_size(hash_table));
    display_hash_table(hash_table);

    destroy_hash_table(hash_table);
    return 0;
}
