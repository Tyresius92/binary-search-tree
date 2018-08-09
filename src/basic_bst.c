#include "basic_bst.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

typedef struct Node {
        void *value; 
        struct Node *parent; 
        struct Node *left; 
        struct Node *right; 
} Node; 

struct bs_tree {
        Node *root; 
        void *comparison_func; 
};

/*********************
 * Private functions *
 *********************/

void private_deallocate_all_tree_nodes(Node *n); 
Node *private_insert_value(Node *root, Node *new_node, 
                           void *comparison_func(void *val1, void *val2));
Node *construct_node(void *value);
Node *private_find_in_tree(BSTree_T tree, void *value, 
                           void *comparison_func(void *val1, void *val2));
void bst_transplant(BSTree_T tree, Node *u, Node *v); 
Node *private_bst_minimum(Node *x);
Node *private_bst_maximum(Node *x); 
void *private_bst_successor_of_value(BSTree_T tree, void *value, 
                                 void *comparison_func(void *val1, void *val2));
void *private_bst_predecessor_of_value(BSTree_T tree, void *value, 
                                   void *comparison_func(void *val1, void *val2));
void private_bst_map_inorder(Node *root, 
                             int depth, 
                             void func_to_apply(void *value, int depth, void *cl), 
                             void *cl);
void private_bst_map_preorder(Node *root, 
                              int depth, 
                              void func_to_apply(void *value, int depth, void *cl), 
                              void *cl);
void private_bst_map_postorder(Node *root, 
                               int depth, 
                               void func_to_apply(void *value, int depth, void *cl), 
                               void *cl);


/************************
 * function definitions *
 ************************/

BSTree_T bst_new(void *comparison_func)
{
        BSTree_T tree = malloc(sizeof(struct bs_tree)); 

        tree->root = NULL; 

        if (comparison_func == NULL) {
                tree->comparison_func = &strcmp; 
        } else {
                tree->comparison_func = comparison_func; 
        }

        return tree; 
}

void bst_free(BSTree_T tree)
{
        assert(tree != NULL);

        private_deallocate_all_tree_nodes(tree->root); 
        free(tree); 

        tree = NULL; 
}

void private_deallocate_all_tree_nodes(Node *n) {
        if (n == NULL)
                return; 

        if (n->left != NULL) 
                private_deallocate_all_tree_nodes(n->left);
        if (n->right != NULL)
                private_deallocate_all_tree_nodes(n->right); 

        free(n); 
}

bool bst_is_empty(BSTree_T tree)
{
        assert(tree != NULL); 

        return tree->root == NULL;
}

int bst_insert_value(BSTree_T tree, void *value)
{
        assert(tree != NULL && value != NULL); 

        Node *new_node = construct_node(value); 
        tree->root = private_insert_value(tree->root, new_node, tree->comparison_func); 

        return 0; 
}

Node *construct_node(void *value)
{
        Node *new_node = (Node *) malloc(sizeof(Node)); 

        new_node->parent = NULL;
        new_node->left = NULL; 
        new_node->right = NULL; 
        new_node->value = value; 

        return new_node; 
}

Node *private_insert_value(Node *root, Node *new_node, 
                           void *comparison_func(void *val1, void *val2)) 
{
        if (root == NULL) { 
                return new_node; 
        }

        if ((int)(intptr_t) comparison_func(new_node->value, root->value) < 0) {
                root->left = private_insert_value(root->left, new_node, comparison_func); 
                root->left->parent = root; 
        } else {
                root->right = private_insert_value(root->right, new_node, comparison_func); 
                root->right->parent = root; 
        }

        return root; 
}

void *bst_search(BSTree_T tree, void *value)
{
        Node *result = private_find_in_tree(tree, value, tree->comparison_func); 

        if (result != NULL) 
                return (void *) result->value; 

        return result; //AKA return NULL 
}

Node *private_find_in_tree(BSTree_T tree, void *value, 
                           void *comparison_func(void *val1, void *val2))
{
        bool found = false; 
        Node *curr = tree->root; 
        int c = 0; 

        while (!found && curr != NULL) {
                c = (int)(intptr_t) comparison_func(value, curr->value); 

                if (c == 0) {
                        found = true; 
                } else if (c < 0) {
                        curr = curr->left; 
                } else if (c > 0) {
                        curr = curr->right; 
                }
        }

        return curr; 
}

void bst_delete_value(BSTree_T tree, void *value)
{
        Node *z = private_find_in_tree(tree, value, tree->comparison_func);

        if (z == NULL)
                return; 

        if (z->left == NULL) {
                bst_transplant(tree, z, z->right); 
        } else if (z->right == NULL) {
                bst_transplant(tree, z, z->left);
        } else {
                Node *y = private_bst_minimum(z->right); 
                if (y->parent != z) {
                        bst_transplant(tree, y, y->right); 
                        y->right = z->right; 
                        y->right->parent = y; 
                }
                bst_transplant(tree, z, y); 
                y->left = z->left; 
                y->left->parent = y; 
        }
        
        free(z); 
}

void bst_transplant(BSTree_T tree, Node *u, Node *v)
{
        if (u->parent == NULL) {
                tree->root = v; 
        } else if (u == u->parent->left) {
                u->parent->left = v; 
        } else {
                u->parent->right = v; 
        }

        if (v != NULL)
                v->parent = u->parent; 
}

void *bst_tree_minimum(BSTree_T tree)
{
        Node *n = private_bst_minimum(tree->root); 

        if (n == NULL)
                return NULL; 
        else 
                return n->value;
}

void *bst_tree_maximum(BSTree_T tree)
{
        Node *n = private_bst_maximum(tree->root);  

        if (n == NULL)
                return NULL; 
        else 
                return n->value; 
}

Node *private_bst_minimum(Node *x) 
{
        while (x->left != NULL) {
                x = x->left; 
        }

        return x; 
}

Node *private_bst_maximum(Node *x) 
{
        while (x->right != NULL) {
                x = x->right; 
        }

        return x; 
}

void *bst_successor_of_value(BSTree_T tree, void *value)
{
        return private_bst_successor_of_value(tree, value, tree->comparison_func); 
}

void *bst_predecessor_of_value(BSTree_T tree, void *value)
{
        return private_bst_predecessor_of_value(tree, value, tree->comparison_func); 
} 

void *private_bst_successor_of_value(BSTree_T tree, void *value, 
                                 void *comparison_func(void *val1, void *val2))
{
        Node *curr_node = tree->root; 
        Node *successor = NULL; 
        int c; 

        while (curr_node != NULL) {
                c = (int)(intptr_t) comparison_func(value, curr_node->value);

                if (c < 0) {
                        successor = curr_node; 
                        curr_node = curr_node->left; 
                } else {
                        curr_node = curr_node->right; 
                }
        }

        if (successor == NULL) 
                return NULL; 
        else
                return successor->value; 
}

void *private_bst_predecessor_of_value(BSTree_T tree, void *value, 
                                   void *comparison_func(void *val1, void *val2))
{
        Node *curr_node = tree->root; 
        Node *successor = NULL; 
        int c; 

        while (curr_node != NULL) {
                c = (int)(intptr_t) comparison_func(value, curr_node->value);
                if (c > 0) {
                        successor = curr_node; 
                        curr_node = curr_node->right; 
                } else {
                        curr_node = curr_node->left; 
                }
        }

        if (successor == NULL) 
                return NULL; 
        else
                return successor->value; 
}

void bst_map_inorder(BSTree_T tree, 
                    void func_to_apply(void *value, int depth, void *cl), 
                    void *cl)
{
        int depth = 0; 
        private_bst_map_inorder(tree->root, depth, func_to_apply, cl); 
}

void private_bst_map_inorder(Node *root, 
                             int depth, 
                             void func_to_apply(void *value, int depth, void *cl), 
                             void *cl)
{
        if (root->left != NULL)
                private_bst_map_inorder(root->left, depth + 1, func_to_apply, cl); 

        func_to_apply(root->value, depth, cl); 

        if (root->right != NULL)
                private_bst_map_inorder(root->right, depth + 1, func_to_apply, cl); 
}

void bst_map_preorder(BSTree_T tree, 
                     void func_to_apply(void *value, int depth, void *cl), 
                     void *cl)
{
        int depth = 0; 
        private_bst_map_preorder(tree->root, depth, func_to_apply, cl); 
}

void private_bst_map_preorder(Node *root, 
                              int depth, 
                              void func_to_apply(void *value, int depth, void *cl), 
                              void *cl)
{
        func_to_apply(root->value, depth, cl); 

        if (root->left != NULL)
                private_bst_map_preorder(root->left, depth + 1, func_to_apply, cl); 

        if (root->right != NULL)
                private_bst_map_preorder(root->right, depth + 1, func_to_apply, cl); 
}

void bst_map_postorder(BSTree_T tree, 
                      void func_to_apply(void *value, int depth, void *cl), 
                      void *cl)
{
        int depth = 0; 
        private_bst_map_postorder(tree->root, depth, func_to_apply, cl); 
}

void private_bst_map_postorder(Node *root, 
                              int depth, 
                              void func_to_apply(void *value, int depth, void *cl), 
                              void *cl)
{
        if (root->left != NULL)
                private_bst_map_postorder(root->left, depth + 1, func_to_apply, cl); 

        if (root->right != NULL)
                private_bst_map_postorder(root->right, depth + 1, func_to_apply, cl); 

        func_to_apply(root->value, depth, cl); 
}
