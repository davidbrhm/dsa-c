//
// Created by Ábrahám Dávid on 2026. 05. 22..
//

#ifndef DSA_C_COMPRESSION_H
#define DSA_C_COMPRESSION_H

#include <stddef.h>

#define ALPHABET 256

typedef struct HuffmanNode {
    unsigned char ch;
    unsigned freq;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

char *huffman_encode(const unsigned char *text, size_t len, HuffmanNode **out_root);

unsigned char *huffman_decode(const char *bits, const HuffmanNode *root, size_t *out_len);

void huffman_tree_free(HuffmanNode *t);

#endif //DSA_C_COMPRESSION_H
