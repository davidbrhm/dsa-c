//
// Created by Ábrahám Dávid on 2026. 04. 29..
//

#include <stdbool.h>
#include <math.h>

bool isThree(int n) {
    int root = sqrt(n);
    if (n < 4 || root * root != n) return false;

    for (int i = 2; i < root; i++) {
        if (n % i == 0) return false;
    }

    return true;
}
