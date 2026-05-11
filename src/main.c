#include <stdio.h>

#include "../include/binary_tree.h"

int main(void) {
    BinaryTree *tree = create_binary_tree();
    tree->root = bnode_create(1);

    /*
     * 1
     * /   \
     * 2     3
     * / \     \
     * 4   5     6
     */

    BNode *node2 = btree_insert_left(tree->root, 2);
    BNode *node3 = btree_insert_right(tree->root, 3);

    btree_insert_left(node2, 4);
    btree_insert_right(node2, 5);
    btree_insert_right(node3, 6);

    printf("Height: %d\n", btree_get_height(tree));

    printf("\nPreorder traversal (root-left-right):\n");
    btree_preorder_traversal(tree->root);
    printf("\n");

    printf("\nInorder traversal (left-root-right):\n");
    btree_inorder_traversal(tree->root);
    printf("\n");

    printf("\nPostorder traversal (left-right-root):\n");
    btree_postorder_traversal(tree->root);
    printf("\n");

    destroy_binary_tree(tree);
    return 0;
}
