/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

struct Linked_List_node_str {
  type_t data;
  struct Linked_List_node_str* next;
};

struct Linked_List_str {
  datatype_t         datatype;
  Linked_List_Node_t front;
  Linked_List_Node_t back;
  int                size;
};

Linked_List_t linked_list_create(datatype_t datatype) {
  Linked_List_t list = malloc(sizeof(struct Linked_List_str));
  memset(list, 0, sizeof(struct Linked_List_str));
  list->datatype = datatype;
  list->size = 0;
  return list;
}

bool_t linked_list_destroy(Linked_List_t list) {
  if (!linked_list_clear(list))
    return FALSE;
  free(list);
  return TRUE;
}

bool_t linked_list_add(Linked_List_t list, type_t data) {
  bool_t res = linked_list_add_back(list, data);
  return res;
}

bool_t linked_list_add_front(Linked_List_t list, type_t data) {
  Linked_List_Node_t new_node = malloc(sizeof(struct Linked_List_node_str));
  memset(new_node, 0, sizeof(struct Linked_List_node_str));
  new_node->data = malloc(GET_DATA_SIZE(list->datatype, data));
  memcpy(new_node->data, data, GET_COPY_DATA_SIZE(list->datatype, data));

  if (list->size == 0) {
    list->front = new_node;
    list->back = new_node;
  }
  else {
    new_node->next = list->front;
    list->front = new_node;
  }

  list->size++;
  return TRUE; 
}

bool_t linked_list_add_back(Linked_List_t list, type_t data) {
  Linked_List_Node_t new_node = malloc(sizeof(struct Linked_List_node_str));
  memset(new_node, 0, sizeof(struct Linked_List_node_str));
  new_node->data = malloc(GET_DATA_SIZE(list->datatype, data));
  memcpy(new_node->data, data, GET_COPY_DATA_SIZE(list->datatype, data));

  if (list->size == 0) {
    list->front = new_node;
    list->back = new_node;
  }
  else {
    list->back->next = new_node;
    list->back = new_node;
  }

  list->size++;
  return TRUE;
}

bool_t linked_list_set(Linked_List_t list, unsigned int index, type_t data) {
  if (index > list->size)
    return FALSE;
  else {
    Linked_List_Node_t temp = list->front;   
    for (int i = 1; i < index; i++)
      temp = temp->next;
    free(temp->data);
    temp->data = malloc(GET_DATA_SIZE(list->datatype, data));
    memcpy(temp->data, data, GET_COPY_DATA_SIZE(list->datatype, data));
    return TRUE;
  }
}

type_t linked_list_get_index(Linked_List_t list, unsigned int index) {
  if (index > list->size)
    return NULL;
  else {
    Linked_List_Node_t temp = list->front;
    for (int i = 1; i < index; i++)
      temp = temp->next;
    return temp->data;
  }
}

type_t linked_list_get_front(Linked_List_t list) {
  if(list->size == 0)
    return NULL;
  else
    return list->front->data;
}

type_t linked_list_get_back(Linked_List_t list) {
  if(list->size == 0)
    return NULL;
  else
    return list->back->data;
}

int linked_list_index_of(Linked_List_t list, type_t data) {
  int index = -1;
  Linked_List_Node_t node = list->front;
  for(unsigned int i = 0; i < list->size; i++) {
    if (IS_DATA_EQUAL(list->datatype, node->data, data))
    {
      index = i;
      break;
    }
    node = node->next;
  }
  return index;
}

bool_t linked_list_remove_index(Linked_List_t list, unsigned int index) {
  if (index > list->size)
    return FALSE;
  else {
    Linked_List_Node_t node = list->front;
    // Deleting the first element on the linked list.
    if (index == 1) {
      list->front = node->next;
      free(node->data);
      free(node);
    }
    else {
      Linked_List_Node_t next_node = node->next;
      for (unsigned int i = 1; i < list->size; i++) {
        if (index == i + 1) {
          // Deleting the last element on the linked list.
          if (index == list->size) {
            node->next = NULL;
            list->back = node;
            break;
          }
          // Deleting any other element on the linked list.
          else {
            node->next = next_node->next;
            break;
          }
        }
        node = node->next;
        next_node = next_node->next;
      }
      free(next_node->data);
      free(next_node);
    }
    list->size--;
    return TRUE;
  }
}

bool_t linked_list_remove_front(Linked_List_t list) {
  return linked_list_remove_index(list, 1);
}

bool_t linked_list_remove_back(Linked_List_t list) {
  return linked_list_remove_index(list, list->size);
}

bool_t linked_list_clear(Linked_List_t list) {
  while (!linked_list_is_empty(list))
    linked_list_remove_front(list);
  return TRUE;
}

int linked_list_size(Linked_List_t list) {
  return list->size;
}

bool_t linked_list_is_empty(Linked_List_t list) {
  return (list->size == 0);
}

bool_t linked_list_print(Linked_List_t list) {
  if (list->size == 0) {
    printf("The linked list is empty\n");
  }
  else {
    Linked_List_Node_t temp = list->front;
    printf("Linked list size: %d\n", list->size);
    while (temp != NULL) {

      if (list->datatype == DATATYPE_UINT)
        printf("%u", VOID_PTR_2_UINT(temp->data));
      else if (list->datatype == DATATYPE_INT)
        printf("%d", VOID_PTR_2_INT(temp->data));
      else if (list->datatype == DATATYPE_ULONG)
        printf("%lu", VOID_PTR_2_ULONG(temp->data));
      else if (list->datatype == DATATYPE_LONG)
        printf("%ld", VOID_PTR_2_LONG(temp->data));
      else if (list->datatype == DATATYPE_FLOAT)
        printf("%.6f", VOID_PTR_2_FLOAT(temp->data));
      else if (list->datatype == DATATYPE_DOUBLE)
        printf("%.6f", VOID_PTR_2_DOUBLE(temp->data));
      else if (list->datatype == DATATYPE_STRING)
        printf("%s", temp->data);

      temp = temp->next;
      if (temp != NULL)
          printf("  ->  ");
    }
  }
  printf("\n");
}