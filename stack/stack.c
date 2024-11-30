/*
Coded by Gustavo Adolfo Rueda Enríquez
May 16th 2022
*/

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Stack_Node_str {
  type_t data;
  struct Stack_Node_str *prior;
};
struct Stack_str {
  Stack_Node_t top;
  int size;
  datatype_t datatype;
};

Stack_t stack_create(datatype_t type) {
  Stack_t s = (Stack_t) calloc(1, sizeof(struct Stack_str));
  memset(s, 0, sizeof(struct Stack_str));
  s->datatype = type;
  return s;
}

int stack_size(Stack_t s) {
  return s->size;
}

bool_t stack_isEmpty(Stack_t s) {
  if (s->top == 0) {
    return TRUE;
  }
  else{
    return FALSE;
  }
}

type_t stack_top(Stack_t s) {
  if (s->top != NULL) {
    return s->top->data;
  }
  return NULL;
}

void stack_push(Stack_t s, type_t data) {
  Stack_Node_t new_node = (Stack_Node_t) malloc(sizeof(struct Stack_Node_str));
  memset(new_node, 0, sizeof(struct Stack_Node_str));

  new_node->data = malloc(GET_DATA_SIZE(s->datatype, data));
  memset(new_node->data, 0, GET_DATA_SIZE(s->datatype, data));
  memcpy(new_node->data, data, GET_COPY_DATA_SIZE(s->datatype, data));
  
  new_node->next = NULL;

  new_node->prior = s->top;
  s->size++;
  s->top = new_node;
}

type_t stack_pop(Stack_t s) {
  type_t data;
  if (s->size == 0) {
    return NULL;
  }
  data = s->top->data;
  s->size--;
  s->top = s->top->prior;
  return data;
}

void stack_destroy(Stack_t s) {
  Stack_Node_t temp;
  while (s->top != NULL) {
    temp = s->top->prior;
    free(s->top);
    s->top = temp;
  }
  free(s);
  return;
}

void stack_print(Stack_t s) {
  if (s->size == 0)
    printf("The stack is empty\n");
  else {
    if (s->datatype == DATATYPE_MIXED)
      printf("Stack's data is mixed, unable to fully print its contents\n");
    else {
      Stack_Node_t temp = s->top;
      printf("Stack's size: %d\n", s->size);
      while (temp != NULL) {
        printf("---\n");
        if (s->datatype == DATATYPE_UINT)
          printf("|%u\n", VOID_PTR_2_UINT(temp->data));
        else if (s->datatype == DATATYPE_INT)
          printf("|%d\n", VOID_PTR_2_INT(temp->data));
        else if (s->datatype == DATATYPE_ULONG)
          printf("|%lu\n", VOID_PTR_2_ULONG(temp->data));
        else if (s->datatype == DATATYPE_LONG)
          printf("|%ld\n", VOID_PTR_2_LONG(temp->data));
        else if (s->datatype == DATATYPE_FLOAT)
          printf("|%.6f\n", VOID_PTR_2_FLOAT(temp->data));
        else if (s->datatype == DATATYPE_DOUBLE)
          printf("|%.6f\n", VOID_PTR_2_DOUBLE(temp->data));
        else if (s->datatype == DATATYPE_STRING)
          printf("|%s\n", temp->data);
        temp = temp->prior;
      }
      printf("---\n");
    }
  }
  return;
}
