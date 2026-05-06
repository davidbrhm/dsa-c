//
// Created by Ábrahám Dávid on 2026. 05. 06..
//

#ifndef DSA_C_SINGLY_LINKED_LIST_H
#define DSA_C_SINGLY_LINKED_LIST_H
#include <stdbool.h>

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode; // Singly Linked Node

typedef struct {
    SNode* head;
    int size;
} SList;

SList* create_slist();
void destroy_slist(SList* list);
void display_slist(SList* list);

bool slist_is_empty(SList* list);
bool slist_contains(SList* list, int key);
SNode *slist_get(SList *list, int index);
SNode *slist_search(SList *list, int key);
void slist_insert_first(SList* list, int data);
void slist_insert_last(SList* list, int data);
void slist_insert_after(SList *list, SNode* prev_node, int data);
void slist_delete_first(SList* list);
void slist_delete_last(SList* list);
void slist_delete_by_key(SList* list, int key);


#endif //DSA_C_SINGLY_LINKED_LIST_H
