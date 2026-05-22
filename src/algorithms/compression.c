//
// Created by Ábrahám Dávid on 2026. 05. 22..
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "../../include/compression.h"
#include "../../include/constants.h"


typedef struct MinHeap {
    HuffmanNode **a;
    int n;
    int cap;
} MinHeap;

static HuffmanNode *node_new(unsigned char ch, unsigned freq, HuffmanNode *l, HuffmanNode *r) {
    HuffmanNode *p = (HuffmanNode *) malloc(sizeof(HuffmanNode));
    if (!p) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    p->ch = ch;
    p->freq = freq;
    p->left = l;
    p->right = r;

    return p;
}

static bool is_leaf(const HuffmanNode *x) {
    return x && !x->left && !x->right;
}

void huffman_tree_free(HuffmanNode *t) {
    if (!t) return;

    huffman_tree_free(t->left);
    huffman_tree_free(t->right);
    free(t);
}

static MinHeap *heap_new(int cap) {
    MinHeap *h = (MinHeap *) malloc(sizeof(MinHeap));
    if (!h) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    h->a = (HuffmanNode **) malloc(sizeof(HuffmanNode *) * (cap + 1));
    if (!h->a) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    h->n = 0;
    h->cap = cap;

    return h;
}

static void heap_swap(HuffmanNode **x, HuffmanNode **y) {
    HuffmanNode *t = *x;
    *x = *y;
    *y = t;
}

static void heap_push(MinHeap *h, HuffmanNode *v) {
    if (h->n == h->cap) {
        h->cap *= 2;
        h->a = (HuffmanNode **) realloc(h->a, sizeof(HuffmanNode *) * (h->cap + 1));
        if (!h->a) {
            printf("%s", ERR_MSG_MEM_ALLOC);
            exit(ERR_CODE_MEM_ALLOC);
        }
    }

    int i = ++h->n;
    h->a[i] = v;
    while (i > 1 && h->a[i]->freq < h->a[i / 2]->freq) {
        heap_swap(&h->a[i], &h->a[i / 2]);
        i /= 2;
    }
}

static void heap_shift_down(MinHeap *h, int i) {
    int s = i;
    bool swapped = true;

    while (swapped) {
        int l = i * 2;
        int r = l + 1;
        s = i;

        if (l <= h->n && h->a[l]->freq < h->a[s]->freq) s = l;
        if (r <= h->n && h->a[r]->freq < h->a[s]->freq) s = r;

        if (s != i) {
            heap_swap(&h->a[i], &h->a[s]);
            i = s;
        } else {
            swapped = false;
        }
    }
}

static HuffmanNode *heap_pop(MinHeap *h) {
    if (h->n == 0) return NULL;

    HuffmanNode *top = h->a[1];
    h->a[1] = h->a[h->n--];

    heap_shift_down(h, 1);

    return top;
}

static HuffmanNode *build_tree(const unsigned freq[ALPHABET]) {
    MinHeap *h = heap_new(256);
    for (int c = 0; c < ALPHABET; ++c) {
        if (freq[c] > 0)
            heap_push(h, node_new((unsigned char) c, freq[c], NULL, NULL));
    }

    if (h->n == 0) {
        free(h->a);
        free(h);
        return NULL;
    }

    while (h->n > 1) {
        HuffmanNode *a = heap_pop(h);
        HuffmanNode *b = heap_pop(h);
        HuffmanNode *p = node_new(0, a->freq + b->freq, a, b);
        heap_push(h, p);
    }

    HuffmanNode *root = heap_pop(h);
    free(h->a);
    free(h);
    return root;
}

static void build_codes_rec(const HuffmanNode *t, char **codes, char *buf, int depth) {
    if (!t) return;
    if (is_leaf(t)) {
        buf[depth] = '\0';
        if (depth == 0) {
            buf[0] = '0';
            buf[1] = '\0';
        }

        codes[t->ch] = strdup(buf);
        return;
    }

    buf[depth] = '0';
    build_codes_rec(t->left, codes, buf, depth + 1);
    buf[depth] = '1';
    build_codes_rec(t->right, codes, buf, depth + 1);
}

char *huffman_encode(const unsigned char *text, size_t len, HuffmanNode **out_root) {
    if (len == 0) {
        *out_root = NULL;
        return strdup("");
    }

    unsigned freq[ALPHABET] = {0};
    for (size_t i = 0; i < len; ++i)
        freq[text[i]]++;

    HuffmanNode *root = build_tree(freq);
    *out_root = root;

    char *codes[ALPHABET] = {0};
    char tmp[ALPHABET];
    build_codes_rec(root, codes, tmp, 0);

    size_t total = 0;
    for (size_t i = 0; i < len; ++i) total += strlen(codes[text[i]]);

    char *out = (char *) malloc(total + 1);
    if (!out) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    size_t p = 0;
    for (size_t i = 0; i < len; ++i) {
        const char *code = codes[text[i]];
        size_t k = strlen(code);
        memcpy(out + p, code, k);
        p += k;
    }
    out[p] = '\0';

    for (int c = 0; c < ALPHABET; ++c) {
        if (codes[c]) free(codes[c]);
    }

    return out;
}

unsigned char *huffman_decode(const char *bits, const HuffmanNode *root, size_t *out_len) {
    *out_len = 0;
    if (!root) return (unsigned char *) calloc(1, 1);

    size_t cap = 1024;
    unsigned char *out = (unsigned char *) malloc(cap);
    if (!out) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    if (is_leaf(root)) {
        size_t cnt = bits ? strlen(bits) : 0;

        if (cnt == 0) cnt = 1;
        for (size_t i = 0; i < cnt; ++i) {
            if (*out_len == cap) {
                cap *= 2;
                out = (unsigned char *) realloc(out, cap);
            }

            out[(*out_len)++] = root->ch;
        }

        return out;
    }

    const HuffmanNode *cur = root;
    for (const char *p = bits; *p; ++p) {
        cur = (*p == '0') ? cur->left : cur->right;

        if (is_leaf(cur)) {
            if (*out_len == cap) {
                cap *= 2;
                out = (unsigned char *) realloc(out, cap);
            }

            out[(*out_len)++] = cur->ch;
            cur = root;
        }
    }

    return out;
}
