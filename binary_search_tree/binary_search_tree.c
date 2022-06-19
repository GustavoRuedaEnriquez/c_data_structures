/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define SPACE 10

/* Private functions */
void       __destroy_node(BST_node_t);
BST_node_t __insert_node(BST_node_t, int);
BST_node_t __remove_node(BST_node_t, int);
BST_node_t __get_min_value_node(BST_node_t);
void       __print_preorder_traversal(BST_node_t);
void       __print_inorder_traversal(BST_node_t);
void       __print_postorder_traversal(BST_node_t);
void       __print_nodes(BST_node_t, int);
int        __calculate_height(BST_node_t);
bool_t     __search_node(BST_node_t, int value);

struct BST_node_str {
  int    data;
  struct BST_node_str* left;
  struct BST_node_str* right;
};

struct BST_str {
  BST_node_t root;
  int n_nodes;
};

BST_t bst_create() {
  BST_t t = calloc( 1, sizeof ( struct BST_str ) );
  return t;  
}

int bst_destroy(BST_t t) {
  __destroy_node(t->root);
  free(t);
  return TRUE;
}

int bst_add(BST_t t, int value) {
  if( bst_contains(t, value) == TRUE ) {
    return VALUE_EXISTS;
  }
  else {
    t->root = __insert_node(t->root, value);
    return TRUE;
  }
}

int bst_remove(BST_t t, int value) {
  if( bst_contains(t, value) == FALSE ) {
    return VALUE_DOESNT_EXISTS;
  }
  else {
    t->root = __remove_node(t->root, value);
    return TRUE;
  }
}

void bst_print(BST_t t) {
  __print_nodes(t->root, 0);
}

void bst_traverse(BST_t t, traversal_t traversal_type) {
  switch(traversal_type) {
    case INORDER:
      __print_inorder_traversal(t->root);
      break;
    case PREORDER:
      __print_preorder_traversal(t->root);
      break;
    case POSTORDER:
      __print_postorder_traversal(t->root);
      break;
  }
  printf("\n");
}

int bst_get_height(BST_t t) {
  return __calculate_height(t->root);
}

bool_t bst_contains(BST_t t, int value) {
  return __search_node(t->root, value);
}

/******************************************************************************/
//                                Private functions                           //
/******************************************************************************/

void __destroy_node(BST_node_t node) {
  if( node == NULL )
    return;
  __destroy_node(node->left);
  __destroy_node(node->right);
  free(node);
}

BST_node_t __insert_node(BST_node_t node, int value) {
  if( node == NULL ) {
    BST_node_t new_node = calloc( 1, sizeof( struct BST_node_str ) );
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = value;
    return new_node;
  }
  if( value < node->data ) {
    node->left = __insert_node(node->left, value);
  } 
  else if( value > node->data ) {
    node->right = __insert_node(node->right, value);
  }
  return node;
}

BST_node_t __remove_node(BST_node_t node, int value) {
  if( node == NULL ) {
    return node;
  }
  if( value < node->data ) {
    node->left = __remove_node(node->left, value);
  } 
  else if( value > node->data ) {
    node->right = __remove_node(node->right, value);
  }
  else {
    /* First case: Node with 1 or 0 children */
    if( node->left == NULL ) {
      BST_node_t temp = node->right;
      free(node);
      return temp;
    }
    else if( node->right == NULL ) {
      BST_node_t temp = node->left;
      free(node);
      return temp;
    }
    /* Second case: Node with 2 children */
    /* Need to get inorder successor. */
    BST_node_t temp = __get_min_value_node(node->right);
    node->data = temp->data;
    node->right = __remove_node(node->right, node->data);
  }
  return node;
}

BST_node_t __get_min_value_node(BST_node_t node) {
  BST_node_t current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

void __print_preorder_traversal(BST_node_t node) {
  if( node == NULL )
    return;
  printf(" %d ", node->data);
  __print_preorder_traversal(node->left);
  __print_preorder_traversal(node->right);
}

void __print_inorder_traversal(BST_node_t node) {
  if( node == NULL )
    return;
  __print_inorder_traversal(node->left);
  printf(" %d ", node->data);
  __print_inorder_traversal(node->right);
}

void __print_postorder_traversal(BST_node_t node) {
  if( node == NULL )
    return;
  __print_postorder_traversal(node->left);
  __print_postorder_traversal(node->right);
  printf(" %d ", node->data);
}

void __print_nodes(BST_node_t node, int space) {
  if (node == NULL)
    return;
  space += SPACE;
  __print_nodes(node->right, space);
  printf("\n");
  for (int i = SPACE; i < space; i++)
    printf(" ");
  printf("%d\n", node->data);
  __print_nodes(node->left, space);
}

int __calculate_height(BST_node_t node) {
  if( node == NULL )
    return -1;
  int left = __calculate_height(node->left);
  int right = __calculate_height(node->right);
  if( left >= right )
    return left + 1;
  else
    return right + 1;
}

bool_t __search_node(BST_node_t node, int value) {
  bool_t result = FALSE;
  if(node == NULL) {
    return FALSE;
  }
  if(node->data == value) {
    return TRUE;
  }
  return __search_node(node->left, value) | __search_node(node->right, value);
}
