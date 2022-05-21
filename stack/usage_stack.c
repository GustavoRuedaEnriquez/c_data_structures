/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 16th 2022

Test for the stack's functions.
*/

#include"stack.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
  Stack_t stack_1 = stack_create();
  type_t element_1 = 23;
  type_t element_2 = 4;
  type_t element_3 = 342;

  stack_push(stack_1, element_1);
  stack_push(stack_1, element_2);
  stack_push(stack_1, element_3);
    
  int size = stack_size(stack_1);
  printf("Stack's size: %d\n", size);

  type_t top = stack_top(stack_1);
  printf("Stack's top: %d\n", top);

  stack_pop(stack_1);

  size = stack_size(stack_1);
  printf("Stack's size: %d\n", size);

  top = stack_top(stack_1);
  printf("Stack's top: %d\n", top);
  
  return 0;
}