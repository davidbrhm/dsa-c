//
// Created by Ábrahám Dávid on 2026. 05. 06..
//

#include "../../include/doubly_linked_list.h"
#include "../../include/constants.h"

#include <stdio.h>
#include <stdlib.h>

DList *create_dlist() {
    DList *dlist = (DList *) calloc(1, sizeof(DList));

    if (!dlist) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    dlist->head = NULL;
    dlist->tail = NULL;
    dlist->size = 0;


    return dlist;
}

void destroy_dlist(DList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *node = list->head;

    while (node != NULL) {
        DNode *temp = node->next;
        free(node);
        node = temp;
    }

    free(list);
    list = NULL;
}

void display_dlist(DList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *node = list->head;

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }

    printf("\n");
}

bool dlist_is_empty(DList *list) {
    return list->size == 0;
}

DNode *dlist_search(DList *list, int key) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return NULL;
    }

    DNode *node = list->head;

    while (node != NULL) {
        if (node->data == key)
            return node;

        node = node->next;
    }

    return NULL;
}

bool dlist_contains(DList *list, int key) {
    return dlist_search(list, key) != NULL;
}

void dlist_display_forward(DList *list) {
    display_dlist(list);
}

void dlist_display_backward(DList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *node = list->tail;

    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }

    printf("\n");
}

void dlist_insert_last(DList *list, int data) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *last = list->tail;
    DNode *new_node = (DNode *) calloc(1, sizeof(DNode));

    if (!new_node) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }
    new_node->data = data;

    if (!last) {
        list->head = new_node;
        new_node->prev = NULL;
    } else {
        last->next = new_node;
        new_node->prev = last;
    }
    new_node->next = NULL;

    list->tail = new_node;
    list->size++;
}

void dlist_insert_first(DList *list, int data) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *new_node = (DNode *) calloc(1, sizeof(DNode));
    if (!new_node) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (dlist_is_empty(list)) {
        list->tail = new_node;
    } else {
        list->head->prev = new_node;
    }

    list->head = new_node;
    list->size++;
}

void dlist_insert_after(DList *list, DNode *prev_node, int data) {
    if (list == NULL || prev_node == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *new_node = (DNode *) calloc(1, sizeof(DNode));
    if (!new_node) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }
    new_node->data = data;

    if (prev_node == list->tail) {
        list->tail = new_node;
    }

    new_node->next = prev_node->next;
    new_node->prev = prev_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    } else {
        list->tail = new_node;
    }
    prev_node->next = new_node;

    list->size++;
}

void dlist_delete_first(DList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }
    if (dlist_is_empty(list)) return;

    DNode *target = list->head;

    if (list->size == 1) {
        list->head = list->tail = NULL;
    } else {
        list->head = target->next;
        list->head->prev = NULL;
    }

    free(target);
    list->size--;
}

void dlist_delete_last(DList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }
    if (dlist_is_empty(list)) return;

    if (list->size == 1) {
        dlist_delete_first(list);
        return;
    }

    DNode *last = list->tail;
    DNode *new_tail = last->prev;
    new_tail->next = NULL;
    free(last);
    list->tail = new_tail;
    list->size--;
}

void dlist_delete_by_key(DList *list, int key) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    DNode *target = dlist_search(list, key);

    if (!target) return;

    if (target == list->head) {
        dlist_delete_first(list);
        return;
    }
    if (target == list->tail) {
        dlist_delete_last(list);
        return;
    }

    DNode *before = target->prev;
    DNode *after = target->next;
    before->next = after;
    after->prev = before;

    free(target);
    list->size--;
}
