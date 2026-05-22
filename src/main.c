#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/compression.h"

int main() {
    const char *tests[] = {"ABRACADABRA", "MISSISSIPPI"};
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        const char *input = tests[i];
        size_t input_len = strlen(input);

        printf("In:  %s\n", input);

        HuffmanNode *root = NULL;
        char *encoded_bits = huffman_encode((const unsigned char *) input, input_len, &root);

        if (!encoded_bits) {
            printf("Encoding failed.\n\n");
            continue;
        }

        size_t compressed_bits = strlen(encoded_bits);
        size_t original_bits = input_len * 8;
        float ratio = (float) compressed_bits / original_bits * 100.0f;

        printf("Bits: %s\n", encoded_bits);
        printf("Size: %zu bits -> %zu bits (%.2f%%)\n", original_bits, compressed_bits, ratio);

        size_t decoded_len = 0;
        unsigned char *decoded_text = huffman_decode(encoded_bits, root, &decoded_len);

        if (decoded_text && decoded_len == input_len && memcmp(input, decoded_text, input_len) == 0) {
            printf("Out: %.*s\n\n", (int) decoded_len, decoded_text);
        } else {
            printf("Decoding failed or mismatch.\n\n");
        }

        free(encoded_bits);
        free(decoded_text);
        huffman_tree_free(root);
    }

    return 0;
}
