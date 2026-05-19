#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../include/dynamic_hash_table.h"

int main(void) {
    DynamicHashTable *dht = create_dht();

    dht_insert(dht, 10, 100);
    dht_insert(dht, 20, 200);
    dht_insert(dht, 30, 300);

    dht_insert(dht, 15, 150);
    dht_insert(dht, 25, 250);

    printf("Size: %d\n", dht_get_size(dht));
    display_dht(dht);

    int search_key = 20;
    int found_data = dht_search(dht, search_key);

    if (found_data != -1) {
        printf("\nFound (Key: %d): Data: %d\n", search_key, found_data);
        dht_remove(dht, search_key);
    }

    printf("\nSize: %d\n", dht_get_size(dht));
    display_dht(dht);

    destroy_dht(dht);
    return 0;
}
