//
// Created by Ábrahám Dávid on 2026. 05. 10..
//


#include <stdlib.h>
#include <string.h>

char *removeOuterParentheses(char *s) {
    int len = strlen(s);
    char *result = calloc(len, sizeof(char));

    int idx = 0;
    int count = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] == '(') count++;
        else count--;

        if (count == 0) {
            i++;
            count = 1;
        } else {
            result[idx++] = s[i];
        }
    }

    char *resized = realloc(result, idx + 1);
    resized[idx] = '\0';
    return resized;
}
