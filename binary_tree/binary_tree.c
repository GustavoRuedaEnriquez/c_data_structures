/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

#define SPACE 10

struct Bin_tree_node_str {
  int    data;
  struct Bin_tree_node_str* left;
  struct Bin_tree_node_str* right;
};

struct Bin_tree_str {
  Bin_tree_node_t root;
  int n_nodes;
};

Bin_tree_t binary_tree_create() {
  Bin_tree_t t = calloc( 1, sizeof ( struct Bin_tree_str ) );
  return t;
}

void binary_tree_destroy(Bin_tree_t t) {
  destroy_node(t->root);
  free(t);
}

void binary_tree_add(Bin_tree_t t, int value) {
  t->root = insert_node(t->root, value);
}

void binary_tree_remove(Bin_tree_t t, int value) {
  t->root = remove_node(t->root, value);
}

void binary_tree_print(Bin_tree_t t) {
  print_nodes(t->root, 0);
}

void binary_tree_traverse(Bin_tree_t t, traversal_t traversal_type) {
  switch(traversal_type) {
    case INORDER:
      print_inorder_traversal(t->root);
      break;
    case PREORDER:
      print_preorder_traversal(t->root);
      break;
    case POSTORDER:
      print_postorder_traversal(t->root);
      break;
  }
  printf("\n");
}

int binary_tree_get_height(Bin_tree_t t) {
  return calculate_height(t->root);
}

bool_t binary_tree_contains(Bin_tree_t t, int value) {
  return search_node(t->root, value);
}

void destroy_node(Bin_tree_node_t node) {
  if( node == NULL )
    return;
  destroy_node(node->left);
  destroy_node(node->right);
  free(node);
}

Bin_tree_node_t insert_node(Bin_tree_node_t node, int value) {
  if( node == NULL ) {
    Bin_tree_node_t new_node = calloc( 1, sizeof( struct Bin_tree_node_str ) );
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = value;
    return new_node;
  }
  if( value < node->data ) {
    node->left = insert_node(node->left, value);
  } 
  else if( value > node->data ) {
    node->right = insert_node(node->right, value);
  }
  return node;
}

Bin_tree_node_t remove_node(Bin_tree_node_t node, int value) {
  if( node == NULL ) {
    return node;
  }
  if( value < node->data ) {
    node->left = remove_node(node->left, value);
  } 
  else if( value > node->data ) {
    node->right = remove_node(node->right, value);
  }
  else {
    /* First case: Node with 1 or 0 children */
    if( node->left == NULL ) {
      Bin_tree_node_t temp = node->right;
      free(node);
      return temp;
    }
    else if( node->right == NULL ) {
      Bin_tree_node_t temp = node->left;
      free(node);
      return temp;
    }
    /* Second case: Node with 2 children */
    /* Need to get inorder successor. */
    Bin_tree_node_t temp = get_min_value_node(node->right);
    node->data = temp->data;
    node->right = remove_node(node->right, node->data);
  }
  return node;
}

Bin_tree_node_t get_min_value_node(Bin_tree_node_t node) {
  Bin_tree_node_t current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

void print_preorder_traversal(Bin_tree_node_t node) {
  if( node == NULL )
    return;
  printf(" %d ", node->data);
  print_preorder_traversal(node->left);
  print_preorder_traversal(node->right);
}

void print_inorder_traversal(Bin_tree_node_t node) {
  if( node == NULL )
    return;
  print_inorder_traversal(node->left);
  printf(" %d ", node->data);
  print_inorder_traversal(node->right);
}

void print_postorder_traversal(Bin_tree_node_t node) {
  if( node == NULL )
    return;
  print_postorder_traversal(node->left);
  print_postorder_traversal(node->right);
  printf(" %d ", node->data);
}

void print_nodes(Bin_tree_node_t node, int space) {
  if (node == NULL)
    return;
  space += SPACE;
  print_nodes(node->right, space);
  printf("\n");
  for (int i = SPACE; i < space; i++)
    printf(" ");
  printf("%d\n", node->data);
  print_nodes(node->left, space);
}

int calculate_height(Bin_tree_node_t node) {
  if( node == NULL )
    return -1;
  int left = calculate_height(node->left);
  int right = calculate_height(node->right);
  if( left >= right )
    return left + 1;
  else
    return right + 1;
}

bool_t search_node(Bin_tree_node_t node, int value) {
  bool_t result = FALSE;
  if(node == NULL) {
    return FALSE;
  }
  if(node->data == value) {
    return TRUE;
  }
  return search_node(node->left, value) | search_node(node->right, value);
}
