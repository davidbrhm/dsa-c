#include <stdio.h>

#include "../include/binary_search_tree.h"

int main(void) {
    BinarySearchTree *tree = create_bst();

    bst_insert(tree, 50);
    bst_insert(tree, 30);
    bst_insert(tree, 70);
    bst_insert(tree, 20);
    bst_insert(tree, 40);

    printf("Min: %d\n", bst_min_node(tree)->data);
    printf("Max: %d\n", bst_max_node(tree)->data);

    printf("\nInorder:\n");
    bst_inorder_traversal(tree->root);
    printf("\n");

    printf("\nPreorder:\n");
    bst_preorder_traversal(tree->root);
    printf("\n");

    printf("\nPostorder:\n");
    bst_postorder_traversal(tree->root);
    printf("\n");

    BSTNode *found = bst_search(tree, 30);
    if (found) {
        printf("\nFound: %d\n", found->data);
    }

    bst_delete(tree, 30);

    printf("\nInorder: (30 removed)\n");
    display_bst(tree);
    printf("\n");

    destroy_bst(tree);

    return 0;
}
