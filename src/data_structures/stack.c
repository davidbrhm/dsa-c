//
// Created by Ábrahám Dávid on 2026. 04. 28..
//

#include "../../include/data_structures/stack.h"
#include "../../include/_utils/constants.h"

#include <stdio.h>
#include <stdlib.h>


void create_stack(int capacity, Stack *stack) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = calloc(stack->capacity, sizeof(int));
    // stack->elements = malloc(stack->capacity * sizeof(int));

    if (!stack->elements) {
        printf("%s", ERR_MSG_MEM_ALLOC);
    }
}

void destroy_stack(Stack *stack) {
    stack->capacity = 0;
    stack->top = -1;
    free(stack->elements);
    stack = NULL;
}

bool stack_is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool stack_is_empty(Stack *stack) {
    return stack->top == -1;
}

void stack_push(Stack *stack, int item) {
    if (stack_is_full(stack)) return;

    stack->elements[++stack->top] = item;
}

int stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) return 0;

    return stack->elements[stack->top--];
}

int stack_peek(Stack *stack) {
    return stack->elements[stack->top];
}

int stack_size(Stack *stack) {
    return stack->top + 1;
}
