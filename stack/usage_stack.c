/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 16th 2022

Test for the stack's functions.
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack_t stack_1 = stack_create();

  printf("\n\n*** Will push 3 elements into the stack: 23, 4 and 324 ***\n\n");
  stack_push(stack_1, 23);
  stack_push(stack_1, 4);
  stack_push(stack_1, 324);
  stack_print(stack_1);
  type_t top = stack_top(stack_1);
  printf("Stack's top: %d\n", top);

  printf("\n\n*** Will pop the top of the stack ***\n\n");
  stack_pop(stack_1);
  stack_print(stack_1);
  top = stack_top(stack_1);
  printf("Stack's top: %d\n", top);
  
  stack_destroy(stack_1);
  return 0;
}