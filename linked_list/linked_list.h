/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "basic_defs.h"
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/* Structure the represents a linked list node, it has 2 attributes:
 * - type_t data: Information that will be stored on the linked list node.
 * - Linked_List_Node_t next: Pointer to the next node.
 */
typedef struct Linked_List_node_str * Linked_List_Node_t;

/* Structure the represents a linked list, it has 4 attributes:
 * - datatype_T datatype: Enum that represents the datatype of the entries
 *                        stored on the linked list.
 * - Linked_List_Node_t front: Pointer to linked list first entry.
 * - Linked_List_Node_t back: Pointer to linked list last entry.
 * - size_t size: Current linked list size.
 */
typedef struct Linked_List_str * Linked_List_t;

Linked_List_t linked_list_create(datatype_t);
bool_t        linked_list_add(Linked_List_t, type_t);
bool_t        linked_list_add_front(Linked_List_t, type_t);
bool_t        linked_list_add_back(Linked_List_t, type_t);
bool_t        linked_list_set(Linked_List_t, unsigned int, type_t);
bool_t        linked_list_remove_index(Linked_List_t, unsigned int);
bool_t        linked_list_remove_front(Linked_List_t);
bool_t        linked_list_remove_back(Linked_List_t);
type_t        linked_list_get_index(Linked_List_t, unsigned int);
type_t        linked_list_get_front(Linked_List_t);
type_t        linked_list_get_back(Linked_List_t);
int           linked_list_index_of(Linked_List_t, type_t);
int           linked_list_size(Linked_List_t);
bool_t        linked_list_is_empty(Linked_List_t);
bool_t        linked_list_clear(Linked_List_t);
bool_t        linked_list_destroy(Linked_List_t);
bool_t        linked_list_print(Linked_List_t);

#endif /* LINKED_LIST_H_ */