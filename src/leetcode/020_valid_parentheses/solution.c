//
// Created by Ábrahám Dávid on 2026. 04. 28..
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../../../include/data_structures/stack.h"


int convert(char ch) {
    switch (ch) {
        case '(':
        case '{':
        case '[':
            return 0;
        case '}':
        case ')':
        case ']':
            return 1;
        default:
            return -1;
    }
}


bool is_matching_pair(int open, int close) {
    return close - open == 1 || close - open == 2;
}


bool isValid(char *s) {
    int len = strlen(s);
    if (len % 2 != 0) return false;

    Stack stack;
    create_stack(len, &stack);

    for (int i = 0; i < len; i++) {
        char current = s[i];

        if (convert(current) % 2 == 0) {
            stack_push(&stack, current);
        } else {
            if (stack_is_empty(&stack)) {
                destroy_stack(&stack);
                return false;
            }

            if (!is_matching_pair(stack_pop(&stack), current)) {
                destroy_stack(&stack);
                return false;
            }
        }
    }

    destroy_stack(&stack);
    return stack_is_empty(&stack);
}


int test() {
    char *test1 = "()[]{}";
    char *test2 = "(]";
    char *test3 = "([)]";

    printf("Test 1 '%s': %s\n", test1, isValid(test1) ? "Valid" : "Invalid");
    printf("Test 2 '%s': %s\n", test2, isValid(test2) ? "Valid" : "Invalid");
    printf("Test 3 '%s': %s\n", test3, isValid(test3) ? "Valid" : "Invalid");

    return 0;
}
