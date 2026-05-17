//
// Created by Ábrahám Dávid on 2026. 05. 17..
//

#include "../../include/binary_search_tree.h"
#include "../../include/constants.h"

#include <stdio.h>
#include <stdlib.h>

BSTNode *bst_node_create(int data) {
    BSTNode *new_node = (BSTNode *) calloc(1, sizeof(BSTNode));
    if (!new_node) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

BSTNode *bst_node_insert_recursive(BSTNode *node, int key) {
    if (node == NULL) {
        return bst_node_create(key);
    }

    if (key < node->data) {
        node->left = bst_node_insert_recursive(node->left, key);
    } else {
        node->right = bst_node_insert_recursive(node->right, key);
    }

    return node;
}

BSTNode *bst_node_search_recursive(BSTNode *node, int key) {
    if (node == NULL) return NULL;
    if (node->data == key) return node;

    if (key > node->data)
        return bst_node_search_recursive(node->left, key);
    if (key < node->data)
        return bst_node_search_recursive(node->right, key);
}

BSTNode *bst_search(BinarySearchTree *tree, int key) {
    if (tree == NULL) return NULL;
    return bst_node_search_recursive(tree->root, key);
}

BSTNode *bst_node_delete_recursive(BSTNode *node, int key) {
    if (node == NULL) return NULL;

    if (key < node->data) {
        node->left = bst_node_delete_recursive(node->left, key);
    } else if (key > node->data) {
        node->right = bst_node_delete_recursive(node->right, key);
    } else {
        if (!node->left && !node->right) {
            free(node);
            return NULL;
        }


        if (node->left && !node->right) {
            BSTNode *temp = node->left;
            free(node);
            return temp;
        }
        if (node->right && !node->left) {
            BSTNode *temp = node->right;
            free(node);
            return temp;
        }


        BSTNode *right_min = bst_node_min_value(node->right);
        node->data = right_min->data;

        node->right = bst_node_delete_recursive(node->right, right_min->data);
    }

    return node;
}


BSTNode *bst_node_min_value_it(BSTNode *node) {
    if (node == NULL) return NULL;

    BSTNode *min = node;
    while (min->left != NULL) {
        min = min->left;
    }

    return min;
}

BSTNode *bst_node_max_value_it(BSTNode *node) {
    if (node == NULL) return NULL;

    BSTNode *max = node;
    while (max->right != NULL) {
        max = max->right;
    }

    return max;
}

BSTNode *bst_node_min_value(BSTNode *node) {
    if (node == NULL) return NULL;
    if (node->left == NULL) return node;

    return bst_node_min_value(node->left);
}

BSTNode *bst_node_max_value(BSTNode *node) {
    if (node == NULL) return NULL;
    if (node->right == NULL) return node;

    return bst_node_max_value(node->right);
}

void bst_node_destroy_recursive(BSTNode *node) {
    if (node == NULL) return;

    bst_node_destroy_recursive(node->left);
    bst_node_destroy_recursive(node->right);

    free(node);
}

BinarySearchTree *create_bst() {
    BinarySearchTree *new_bst = (BinarySearchTree *) calloc(1, sizeof(BinarySearchTree));
    if (!new_bst) {
        printf("%s", ERR_MSG_MEM_ALLOC);
        exit(ERR_CODE_MEM_ALLOC);
    }

    new_bst->root = NULL;
    return new_bst;
}

void destroy_bst(BinarySearchTree *tree) {
    bst_node_destroy_recursive(tree->root);

    free(tree);
    tree = NULL;
}

void display_bst(BinarySearchTree *tree) {
    bst_inorder_traversal(tree->root);
}

void bst_insert(BinarySearchTree *tree, int data) {
    if (tree == NULL) return;

    tree->root = bst_node_insert_recursive(tree->root, data);
}

void bst_delete(BinarySearchTree *tree, int data) {
    if (tree == NULL) return;
    tree->root = bst_node_delete_recursive(tree->root, data);
}

BSTNode *bst_min_node(BinarySearchTree *tree) {
    if (tree == NULL) return NULL;
    return bst_node_min_value(tree->root);
}

BSTNode *bst_max_node(BinarySearchTree *tree) {
    if (tree == NULL) return NULL;
    return bst_node_max_value(tree->root);
}

// left - root - right
void bst_inorder_traversal(BSTNode *root) {
    if (root == NULL) return;

    bst_inorder_traversal(root->left);
    printf("%d ", root->data);
    bst_inorder_traversal(root->right);
}

// root left right
void bst_preorder_traversal(BSTNode *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    bst_preorder_traversal(root->left);
    bst_preorder_traversal(root->right);
}

// left - right - root
void bst_postorder_traversal(BSTNode *root) {
    if (root == NULL) return;

    bst_postorder_traversal(root->left);
    bst_postorder_traversal(root->right);
    printf("%d ", root->data);
}
