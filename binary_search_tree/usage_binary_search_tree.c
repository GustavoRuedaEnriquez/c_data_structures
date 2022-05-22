/*
Coded by Gustavo Adolfo Rueda Enríquez
May 21th 2022
*/

#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    BST_t tree = bst_create();
  
    /* Adding nodes */
    printf("Adding 15 nodes: (9,15,13,1,3,2,4,7,6,8,15,10,12,11 and 14).\n");
    bst_add(tree, 9);
    bst_add(tree, 5);
    bst_add(tree, 13);
    bst_add(tree, 1);
    bst_add(tree, 3);
    bst_add(tree, 2);
    bst_add(tree, 4);
    bst_add(tree, 7);
    bst_add(tree, 6);
    bst_add(tree, 8);
    bst_add(tree, 15);
    bst_add(tree, 10);
    bst_add(tree, 12);
    bst_add(tree, 11);
    bst_add(tree, 14);
    printf("\tNodes successfully added.\n\n");

    /* Obtaining height */
    printf("Obtaining tree height.\n");
    int h = bst_get_height(tree);
    printf("\tHeight: %d\n\n", h);

    /* Verifying if a node exists
      FALSE -> 0
      TRUE -> 1
    */
    printf("Verifying if a node exists.\n");
    bool_t contains = bst_contains(tree, 2);
    printf("\tBST contains number 2: %d\n", contains);
    contains = bst_contains(tree, 5);
    printf("\tBST contains number 5: %d\n\n", contains);
    
    /* Printing different traversals */
    printf("Printing different traversals.\n");
    printf("\tInorder: ");
    bst_traverse(tree, INORDER);
    printf("\tPreorder: ");
    bst_traverse(tree, PREORDER);
    printf("\tPostorder: ");
    bst_traverse(tree, POSTORDER);    
    printf("\n");
    
    /* Remove node */
    printf("Removing nodes with number 2, 9 and 4.\n");
    bst_remove(tree, 9);
    bst_remove(tree, 2);
    bst_remove(tree, 4);
    printf("\tNodes successfully removed.\n\n");

    /* Verifying if a node exists
      FALSE -> 0
      TRUE -> 1
    */
    printf("Verifying if a node exists.\n");
    contains = bst_contains(tree, 2);
    printf("\tBST contains number 2: %d\n", contains);
    contains = bst_contains(tree, 5);
    printf("\tBST contains number 5: %d\n\n", contains);

    /* Printing resulting tree. */
    printf("Printing resulting tree.\n");
    bst_print(tree);
}