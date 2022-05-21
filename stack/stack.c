/*
Coded by Gustavo Adolfo Rueda Enríquez
May 16th 2022
*/

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

struct Node_str{
  type_t data;
  struct Node_str *prior;
};
struct Stack_str{
  Node_t top;
  int size;
};


Stack_t stack_create() {
  Stack_t s = (Stack_t) calloc( 1, sizeof( struct Stack_str ) );
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
  Node_t new_node = (Node_t) malloc( sizeof( struct Node_str ) );
  new_node->data = data;
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
  Node_t temp;
  while (s->top != NULL) {
    temp = s->top->prior;
    free(s->top);
    s->top = temp;
  }
  free(s);
}
