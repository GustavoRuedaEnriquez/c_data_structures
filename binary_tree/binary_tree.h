/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef enum {FALSE, TRUE} bool_t;
typedef enum {INORDER, PREORDER, POSTORDER} traversal_t;
typedef struct Bin_tree_node_str  * Bin_tree_node_t;
typedef struct Bin_tree_str * Bin_tree_t;

Bin_tree_t      binary_tree_create();
void            binary_tree_destroy(Bin_tree_t);
void            binary_tree_add(Bin_tree_t, int);
void            binary_tree_remove(Bin_tree_t, int);
void            binary_tree_print(Bin_tree_t);
void            binary_tree_traverse(Bin_tree_t, traversal_t);
int             binary_tree_get_height(Bin_tree_t);
bool_t          binary_tree_contains(Bin_tree_t, int);

/* Recursive functions */
void            destroy_node(Bin_tree_node_t);
Bin_tree_node_t insert_node(Bin_tree_node_t, int);
Bin_tree_node_t remove_node(Bin_tree_node_t, int);
Bin_tree_node_t get_min_value_node(Bin_tree_node_t);
void            print_preorder_traversal(Bin_tree_node_t);
void            print_inorder_traversal(Bin_tree_node_t);
void            print_postorder_traversal(Bin_tree_node_t);
void            print_nodes(Bin_tree_node_t, int);
int             calculate_height(Bin_tree_node_t);
bool_t          search_node(Bin_tree_node_t, int value);

#endif
