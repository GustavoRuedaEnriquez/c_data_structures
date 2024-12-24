/*
Coded by Gustavo Adolfo Rueda Enríquez
May 16th 2022
*/

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Stack_Node_struct {
  type_t data;
  struct Stack_Node_struct *prior;
};

struct Stack_struct {
  Stack_Node_t top;
  size_t size;
  datatype_t datatype;
};


Stack_t stack_create(datatype_t type) {
  // Allocate memory for a new stack struct.
  Stack_t s = (Stack_t) calloc(1, sizeof(struct Stack_struct));
  memset(s, 0, sizeof(struct Stack_struct));

  // Fill stack's attributes
  s->datatype = type;
  s->size = 0;
  s->top = NULL;
  return s;
}


void stack_push(Stack_t s, type_t data) {
  // Allocate memory for a new node.
  Stack_Node_t new_node = (Stack_Node_t) malloc(sizeof(struct Stack_struct));
  memset(new_node, 0, sizeof(struct Stack_struct));

  // Allocate memory for the data the new node will contain.
  new_node->data = malloc(GET_DATA_SIZE(s->datatype, data));
  memset(new_node->data, 0, GET_DATA_SIZE(s->datatype, data));
  memcpy(new_node->data, data, GET_COPY_DATA_SIZE(s->datatype, data));
  
  // Update stack's top.
  new_node->prior = s->top;
  s->top = new_node;
  s->size++;
}


type_t stack_top(Stack_t s) {
  // If top == NULL, return NULL.
  if (s->top != NULL) {
    return s->top->data;
  }
  return NULL;
}


type_t stack_pop(Stack_t s) {
  // If stack is empty, return NULL
  if (s->size == 0) {
    return NULL;
  }

  // Save top's data 
  type_t data;
  data = s->top->data;

  // Remove stack's top and set new top entry.
  s->size--;
  s->top = s->top->prior;
  return data;
}


size_t stack_size(Stack_t s) {
  return s->size;
}


bool_t stack_is_empty(Stack_t s) {
  return (s->size == 0);
}


void stack_destroy(Stack_t s) {
  Stack_Node_t temp;

  // Free each of the stack's nodes.
  while (s->top != NULL) {
    temp = s->top->prior;
    free(s->top->data);
    free(s->top);
    s->size--;
    s->top = temp;
  }

  // Finally, free the memory of the stack structure.
  free(s);
  return;
}


void stack_print(Stack_t s) {
  if (s->size == 0)
    printf("Stack is empty\n");
  else {
    if (s->datatype == DATATYPE_MIXED)
      printf("Stack's data is mixed, unable to fully print its contents\n");
    else {
      // Depending of the datatype of the stack, use the right print format.
      Stack_Node_t temp = s->top;
      printf("Stack's size: %d\n", s->size);
      while (temp != NULL) {
        if (s->datatype == DATATYPE_UINT)
          printf("%u\n", VOID_PTR_2_UINT(temp->data));
        else if (s->datatype == DATATYPE_INT)
          printf("%d\n", VOID_PTR_2_INT(temp->data));
        else if (s->datatype == DATATYPE_ULONG)
          printf("%lu\n", VOID_PTR_2_ULONG(temp->data));
        else if (s->datatype == DATATYPE_LONG)
          printf("%ld\n", VOID_PTR_2_LONG(temp->data));
        else if (s->datatype == DATATYPE_FLOAT)
          printf("%.6f\n", VOID_PTR_2_FLOAT(temp->data));
        else if (s->datatype == DATATYPE_DOUBLE)
          printf("%.6f\n", VOID_PTR_2_DOUBLE(temp->data));
        else if (s->datatype == DATATYPE_STRING)
          printf("%s\n", temp->data);
        temp = temp->prior;
      }
    }
  }
  return;
}
