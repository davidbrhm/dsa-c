//
// Created by Ábrahám Dávid on 2026. 05. 01..
//

#include <stdlib.h>
#include <string.h>

char *addBinary(char *a, char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);

    if (len_b > len_a) {
        char *t1 = a;
        a = b;
        b = t1;

        int t2 = len_a;
        len_a = len_b;
        len_b = t2;
    }

    int max_len = len_a + 1;
    char *result = malloc(max_len + 1);
    result[max_len] = '\0';


    int b_i = len_b - 1;
    int carry = 0;
    for (int a_i = len_a - 1; a_i >= 0; a_i--) {
        int r_i = a_i + 1;

        // bit sum
        int a_bit = a[a_i] - '0';
        int b_bit = 0;
        if (b_i >= 0)
            b_bit = b[b_i] - '0';
        int sum = carry + a_bit + b_bit;

        result[r_i] = (sum % 2 == 0) ? '0' : '1';

        carry = sum / 2;
        b_i--;
    }

    if (carry)
        result[0] = '1';
    else {
        memmove(result, result + 1, max_len);
    }

    return result;
}
