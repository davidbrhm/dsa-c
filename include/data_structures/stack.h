//
// Created by Ábrahám Dávid on 2026. 04. 28..
//

#ifndef DSA_C_STACK_H
#define DSA_C_STACK_H
#include <stdbool.h>

typedef struct {
    int top;
    int capacity;
    int *elements;
} Stack;

void create_stack(int capacity, Stack *stack);
void destroy_stack(Stack *stack);
void stack_push(Stack *stack, int item);
int stack_pop(Stack *stack);
bool stack_is_full(Stack *stack);
bool stack_is_empty(Stack *stack);
int stack_peek(Stack *stack);
int stack_size(Stack *stack);

#endif //DSA_C_STACK_H
