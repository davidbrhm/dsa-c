//
// Created by Ábrahám Dávid on 2026. 05. 01..
//

#include <stdlib.h>

#include "../../../include/data_structures/stack.h"


int sumPoints(Stack *stack) {
    int sum = 0;
    for (int i = 0; i < stack->top + 1; i++) {
        sum += stack->elements[i];
    }

    return sum;
}

int calPoints(char **operations, int operationsSize) {
    Stack stack;
    create_stack(operationsSize, &stack);

    for (int i = 0; i < operationsSize; i++) {
        char operation = *operations[i];

        switch (operation) {
            case '+':
                int sumP2 = stack_peek(&stack) + stack.elements[stack.top - 1];
                stack_push(&stack, sumP2);
                break;
            case 'D':
                int doubleP1 = stack_peek(&stack) * 2;
                stack_push(&stack, doubleP1);
                break;
            case 'C':
                stack_pop(&stack);
                break;
            default:
                int num = atoi(operations[i]);
                stack_push(&stack, num);
                break;
        }
    }

    int sum = sumPoints(&stack);
    destroy_stack(&stack);
    return sum;
}
