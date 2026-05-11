//
// Created by Ábrahám Dávid on 2026. 05. 11..
//

#ifndef DSA_C_BINARY_TREE_H
#define DSA_C_BINARY_TREE_H

typedef struct BNode {
    int data;
    struct BNode *left;
    struct BNode *right;
} BNode;

typedef struct BinaryTree {
    BNode *root;
} BinaryTree;

BinaryTree *create_binary_tree();
void destroy_binary_tree(BinaryTree *tree);
void display_binary_tree(BinaryTree *tree);

BNode *bnode_create(int data);

int btree_get_height(BinaryTree *tree);
BNode *btree_insert_left(BNode *parent, int data);
BNode *btree_insert_right(BNode *parent, int data);
void btree_preorder_traversal(BNode *root);
void btree_inorder_traversal(BNode *root);
void btree_postorder_traversal(BNode *root);


#endif //DSA_C_BINARY_TREE_H
