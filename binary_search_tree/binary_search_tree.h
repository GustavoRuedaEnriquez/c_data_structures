/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

typedef enum {
  FALSE,
  TRUE,
  VALUE_EXISTS,
  VALUE_DOESNT_EXISTS
} bool_t;

typedef enum {
  INORDER,
  PREORDER,
  POSTORDER
} traversal_t;

typedef struct BST_node_str  * BST_node_t;
typedef struct BST_str * BST_t;

BST_t  bst_create();
int    bst_destroy(BST_t);
int    bst_add(BST_t, int);
int    bst_remove(BST_t, int);
void   bst_print(BST_t);
void   bst_traverse(BST_t, traversal_t);
int    bst_get_height(BST_t);
bool_t bst_contains(BST_t, int);

#endif
