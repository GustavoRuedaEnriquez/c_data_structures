/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "basic_defs.h"
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct Linked_List_node_str * Linked_List_Node_t;
typedef struct Linked_List_str * Linked_List_t;

Linked_List_t linked_list_create(datatype_t);
bool_t        linked_list_destroy(Linked_List_t);

bool_t        linked_list_add(Linked_List_t, type_t);
bool_t        linked_list_add_front(Linked_List_t, type_t);
bool_t        linked_list_add_back(Linked_List_t, type_t);
//bool_t        linked_list_add_all(Linked_List_t, type_t*)
bool_t        linked_list_set(Linked_List_t, unsigned int, type_t);
type_t        linked_list_get_index(Linked_List_t, unsigned int);
type_t        linked_list_get_front(Linked_List_t);
type_t        linked_list_get_back(Linked_List_t);
int           linked_list_index_of(Linked_List_t, type_t);
//type_t*       linked_list_to_array(linked_list_t);
bool_t        linked_list_remove_index(Linked_List_t, unsigned int);
bool_t        linked_list_remove_front(Linked_List_t);
bool_t        linked_list_remove_back(Linked_List_t);
bool_t        linked_list_remove_element(Linked_List_t, type_t);
bool_t        linked_list_clear(Linked_List_t);
int           linked_list_size(Linked_List_t);
bool_t        linked_list_is_empty(Linked_List_t);
bool_t        linked_list_print(Linked_List_t);

#endif /* LINKED_LIST_H_ */