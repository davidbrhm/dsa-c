//
// Created by Ábrahám Dávid on 2026. 05. 11..
//

#include "../../include/binary_tree.h"
#include "../../include/constants.h"

#include <stdio.h>
#include <stdlib.h>

BNode *bnode_create(int data) {
    BNode *new_node = (BNode *) calloc(1, sizeof(BNode));
    if (!new_node) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

BinaryTree * create_binary_tree() {
    BinaryTree *tree = (BinaryTree *) calloc(1, sizeof(BinaryTree));
    if (!tree) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    tree->root = NULL;
    return tree;
}

void bnode_destroy_recursive(BNode *node) {
    if (node == NULL) return;

    bnode_destroy_recursive(node->left);
    bnode_destroy_recursive(node->right);

    free(node);
}

void destroy_binary_tree(BinaryTree *tree) {
    if (tree == NULL) return;

    bnode_destroy_recursive(tree->root);
    tree->root = NULL;
    free(tree);
}

void display_binary_tree(BinaryTree *tree) {
    btree_preorder_traversal(tree->root);
}

BNode * btree_insert_left(BNode *parent, int data) {
    if (parent == NULL) return NULL;
    parent->left = bnode_create(data);
    return parent->left;
}

BNode * btree_insert_right(BNode *parent, int data) {
    if (parent == NULL) return NULL;
    parent->right = bnode_create(data);
    return parent->right;
}

// root left right
void btree_preorder_traversal(BNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    btree_preorder_traversal(root->left);
    btree_preorder_traversal(root->right);
}

// left - root - right
void btree_inorder_traversal(BNode *root) {
    if (root == NULL) return;
    btree_inorder_traversal(root->left);
    printf("%d ", root->data);
    btree_inorder_traversal(root->right);
}

// left - right - root
void btree_postorder_traversal(BNode *root) {
    if (root == NULL) return;
    btree_postorder_traversal(root->left);
    btree_postorder_traversal(root->right);
    printf("%d ", root->data);
}

int bnode_get_height(BNode *node) {
    if (node == NULL) return 0;

    int left_height = bnode_get_height(node->left);
    int right_height = bnode_get_height(node->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

int btree_get_height(BinaryTree *tree) {
    if (tree == NULL) return 0;

    return bnode_get_height(tree->root);
}
