/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

typedef enum {FALSE, TRUE} bool_t;
typedef enum {INORDER, PREORDER, POSTORDER} traversal_t;
typedef struct BST_node_str  * BST_node_t;
typedef struct BST_str * BST_t;

BST_t      bst_create();
void       bst_destroy(BST_t);
void       bst_add(BST_t, int);
void       bst_remove(BST_t, int);
void       bst_print(BST_t);
void       bst_traverse(BST_t, traversal_t);
int        bst_get_height(BST_t);
bool_t     bst_contains(BST_t, int);

/* Recursive functions */
void       destroy_node(BST_node_t);
BST_node_t insert_node(BST_node_t, int);
BST_node_t remove_node(BST_node_t, int);
BST_node_t get_min_value_node(BST_node_t);
void       print_preorder_traversal(BST_node_t);
void       print_inorder_traversal(BST_node_t);
void       print_postorder_traversal(BST_node_t);
void       print_nodes(BST_node_t, int);
int        calculate_height(BST_node_t);
bool_t     search_node(BST_node_t, int value);

#endif
