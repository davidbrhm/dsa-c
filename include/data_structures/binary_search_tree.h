//
// Created by Ábrahám Dávid on 2026. 05. 17..
//

#ifndef DSA_C_BINARY_SEARCH_TREE_H
#define DSA_C_BINARY_SEARCH_TREE_H
typedef struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct BinarySearchTree {
    BSTNode *root;
} BinarySearchTree;

BinarySearchTree *create_bst();
void destroy_bst(BinarySearchTree *tree);
void display_bst(BinarySearchTree *tree);

BSTNode *bst_search(BinarySearchTree *tree, int key);
void bst_insert(BinarySearchTree *tree, int data);
void bst_delete(BinarySearchTree *tree, int data);

BSTNode *bst_min_node(BinarySearchTree *tree);
BSTNode *bst_max_node(BinarySearchTree *tree);

void bst_inorder_traversal(BSTNode *root);
void bst_preorder_traversal(BSTNode *root);
void bst_postorder_traversal(BSTNode *root);

BSTNode *bst_node_create(int data);
BSTNode *bst_node_insert_recursive(BSTNode *node, int key);
BSTNode *bst_node_delete_recursive(BSTNode *node, int key);

BSTNode *bst_node_min_value(BSTNode *node);
BSTNode *bst_node_max_value(BSTNode *node);

void bst_node_destroy_recursive(BSTNode *node);
#endif //DSA_C_BINARY_SEARCH_TREE_H
