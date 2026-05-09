#include "../include/doubly_linked_list.h"

int main(void) {
    DList *list = create_dlist();

    dlist_insert_last(list, 2);
    dlist_insert_last(list, 4);
    dlist_insert_last(list, 6);

    display_dlist(list);
    dlist_display_backward(list);

    dlist_insert_first(list, 1);
    dlist_insert_after(list, list->head->next, 3);
    display_dlist(list);
    return 0;
}
