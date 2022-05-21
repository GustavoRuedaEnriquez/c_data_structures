/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Bin_tree_t tree = binary_tree_create();
  
    /* Add nodes */
    printf("---- ADDING NODES ----- \n");
    binary_tree_add(tree, 9);
    binary_tree_add(tree, 5);
    binary_tree_add(tree, 13);
    binary_tree_add(tree, 1);
    binary_tree_add(tree, 3);
    binary_tree_add(tree, 2);
    binary_tree_add(tree, 4);
    binary_tree_add(tree, 7);
    binary_tree_add(tree, 6);
    binary_tree_add(tree, 8);
    binary_tree_add(tree, 15);
    binary_tree_add(tree, 10);
    binary_tree_add(tree, 12);
    binary_tree_add(tree, 11);
    binary_tree_add(tree, 14);
    
    int h = binary_tree_get_height(tree);
    bool_t contains = binary_tree_contains(tree, 2);
    printf("Contains number 2: %d\n", contains);
    contains = binary_tree_contains(tree, 5);
    printf("Contains number 5: %d\n", contains);
    printf("Height: %d\n", h);
    printf("Inorder: ");
    binary_tree_traverse(tree, INORDER);
    printf("Preorder: ");
    binary_tree_traverse(tree, PREORDER);
    printf("Postorder: ");
    binary_tree_traverse(tree, POSTORDER);
    printf("\n\n\n");
    binary_tree_print(tree);
    
    printf("\n\n\n\n\n\n");
    
    /* Remove nodes */
    printf("---- REMOVING NODES ----- \n");
    binary_tree_remove(tree, 9);
    binary_tree_remove(tree, 2);
    binary_tree_remove(tree, 4);

    h = binary_tree_get_height(tree);
    contains = binary_tree_contains(tree, 2);
    printf("Contains number 2: %d\n", contains);
    contains = binary_tree_contains(tree, 5);
    printf("Contains number 5: %d\n", contains);
    printf("Height: %d\n", h);
    printf("Inorder: ");
    binary_tree_traverse(tree, INORDER);
    printf("Preorder: ");
    binary_tree_traverse(tree, PREORDER);
    printf("Postorder: ");
    binary_tree_traverse(tree, POSTORDER);
    binary_tree_print(tree);
}