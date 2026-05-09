//
// Created by Ábrahám Dávid on 2026. 05. 06..
//

#ifndef DSA_C_DOUBLY_LINKED_LIST_H
#define DSA_C_DOUBLY_LINKED_LIST_H
#include <stdbool.h>

typedef struct DNode {
    int data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
    int size;
} DList;

DList *create_dlist();
void destroy_dlist(DList *list);
void display_dlist(DList *list);

bool dlist_is_empty(DList *list);
bool dlist_contains(DList* list, int key);
DNode* dlist_search(DList* list, int key);

void dlist_display_forward(DList* list);
void dlist_display_backward(DList* list);

void dlist_insert_first(DList* list, int data);
void dlist_insert_last(DList* list, int data);
void dlist_insert_after(DList* list, DNode* prev_node, int data);

void dlist_delete_first(DList* list);
void dlist_delete_last(DList* list);
void dlist_delete_by_key(DList* list, int key);

#endif //DSA_C_DOUBLY_LINKED_LIST_H
