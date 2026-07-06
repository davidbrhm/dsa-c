//
// Created by Ábrahám Dávid on 2026. 05. 06..
//

#include "../../include/data_structures/singly_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../include/_utils/constants.h"

SList *create_slist() {
    SList *list = (SList *) calloc(1, sizeof(SList));

    if (!list) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }
    list->head = NULL;
    list->size = 0;

    return list;
}

void destroy_slist(SList *list) {
    if (list == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    SNode *current = list->head;

    SNode *temp;
    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }

    free(list);
    list = NULL;
}

void display_slist(SList *list) {
    SNode *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

bool slist_is_empty(SList *list) {
    return list->size == 0;
}

bool slist_contains(SList *list, int key) {
    SNode *current = list->head;

    while (current != NULL) {
        if (current->data == key)
            return true;

        current = current->next;
    }

    return false;
}

int slist_search_index(SList *list, int key) {
    SNode *current = list->head;

    int idx = 0;
    while (current != NULL) {
        if (current->data == key)
            return idx;
        idx++;
    }

    return -1;
}

SNode *slist_search(SList *list, int key) {
    SNode *current = list->head;

    while (current != NULL) {
        if (current->data == key)
            return current;

        current = current->next;
    }

    return NULL;
}

SNode *slist_get(SList *list, int index) {
    if (list->size < index)
        return NULL;

    SNode *current = list->head;
    while (current != NULL && index > 0) {
        current = current->next;
        index--;
    }

    return current;
}

void slist_insert_last(SList *list, int data) {
    SNode *newNode = (SNode *) calloc(1, sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;

    if (slist_is_empty(list)) {
        list->head = newNode;
    } else {
        SNode *top = list->head;
        while (top->next != NULL) {
            top = top->next;
        }
        top->next = newNode;
    }
    list->size++;
}

void slist_insert_first(SList *list, int data) {
    SNode *new_head = (SNode *) calloc(1, sizeof(SNode));
    new_head->data = data;
    new_head->next = list->head;
    list->head = new_head;
    list->size++;
}

void slist_insert_after(SList *list, SNode *prev_node, int data) {
    if (list == NULL || prev_node == NULL) {
        printf("%s", ERR_MSG_NULL_PTR);
        return;
    }

    SNode *new_node = (SNode *) calloc(1, sizeof(SNode));
    new_node->data = data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;

    list->size++;
}

void slist_delete_first(SList *list) {
    if (slist_is_empty(list)) {
        printf("%s", ERR_MSG_DS_EMPTY);
        return;
    }

    SNode *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void slist_delete_last(SList *list) {
    if (slist_is_empty(list)) return;

    if (list->size == 1) {
        slist_delete_first(list);
        return;
    }

    SNode *before_last = slist_get(list, list->size - 2);
    free(before_last->next);
    before_last->next = NULL;

    list->size--;
}

void slist_delete_by_key(SList *list, int key) {
    if (slist_is_empty(list)) return;

    SNode *current = list->head;
    SNode *prev = NULL;

    if (current != NULL && current->data == key) {
        slist_delete_first(list);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) return;

    prev->next = current->next;
    free(current);
    list->size--;
}
