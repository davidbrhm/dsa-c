//
// Created by Ábrahám Dávid on 2026. 05. 22..
//

#include <string.h>
#include <stdbool.h>

char *destCity(char ***paths, int pathsSize, int *pathsColSize) {
    for (int i = 0; i < pathsSize; i++) {
        char *dest = paths[i][1];
        bool is_source = false;

        for (int j = 0; j < pathsSize; j++) {
            char *src = paths[j][0];

            if (strcmp(dest, src) == 0) {
                is_source = true;
                break;
            }
        }

        if (!is_source) {
            return dest;
        }
    }

    return "";
}


