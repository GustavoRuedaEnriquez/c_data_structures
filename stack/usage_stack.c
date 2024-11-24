/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 16th 2022

Test for the stack's functions.
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("====== Testing stack for unsigned integers ======\n");
  Stack_t stack_uint = stack_create(UINT);

  printf("\n*** Adding 10 unsigned integers elements to the stack ***\n");
  for(unsigned int i = 1; i <= 10; i++)
    stack_push(stack_uint, (void *)&i);
  stack_print(stack_uint);
  
  type_t top = stack_top(stack_uint);
  printf("Stack's top: %u\n", *(unsigned int*)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_uint);
  printf("Element popped: %u\n", *(unsigned int*)popped_element);
  stack_print(stack_uint);
  stack_destroy(stack_uint);

  printf("\n\n\n");

  printf("====== Testing stack for integers ======\n");
  Stack_t stack_int = stack_create(INT);

  printf("\n*** Adding 10 integer elements to the stack ***\n");
  for(int i = -5; i <= 5; i++)
    stack_push(stack_int, (void *)&i);
  stack_print(stack_int);
  
  top = stack_top(stack_int);
  printf("Stack's top: %d\n", *(int*)top);

  printf("\n*** Removing the top of the stack ***\n");
  popped_element = stack_pop(stack_int);
  printf("Element popped: %d\n", *(int*)popped_element);
  stack_print(stack_int);
  stack_destroy(stack_int);

  printf("\n\n\n");

  printf("====== Testing stack for strings ======\n");
  Stack_t stack_string = stack_create(STRING);

  printf("\n*** Adding 10 string elements to the stack ***\n");
  char *array[] = { "Testing", "my", "generic", "stack", "structure", \
                    "on", "C", "languaga", "How", "cool!" };
  for(int i = 0; i < 10; i++)
    stack_push(stack_string, (void *)array[i]);
  stack_print(stack_string);
  
  top = stack_top(stack_string);
  printf("Stack's top: %s\n", (char *)top);

  printf("\n*** Removing the top of the stack ***\n");
  popped_element = stack_pop(stack_string);
  printf("Element popped: %s\n", (char*)popped_element);
  stack_print(stack_string);
  stack_destroy(stack_string);
  return 0;
}