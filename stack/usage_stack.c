/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 16th 2022

Test for the stack's functions.
*/

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void test_uint();
void test_int();
void test_ulong();
void test_long();
void test_float();
void test_double();
void test_string();

int main() {
  printf("====== Testing stack for unsigned integers ======\n");
  test_uint();

  printf("\n\n\n");

  printf("====== Testing stack for integers ======\n");
  test_int();

  printf("\n\n\n");

  ("====== Testing stack for unsigned longs ======\n");
  test_ulong();

  printf("\n\n\n");

  printf("====== Testing stack for longs ======\n");
  test_long();

  printf("\n\n\n");
  
  printf("====== Testing stack for floats ======\n");
  test_float();

  printf("\n\n\n"); 

  printf("====== Testing stack for doubles ======\n");
  test_double();

  printf("\n\n\n");

  printf("====== Testing stack for strings ======\n");
  test_string();

  return 0;
}

void test_uint() {
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
}
void test_int() {
  Stack_t stack_int = stack_create(INT);

  printf("\n*** Adding 10 integer elements to the stack ***\n");
  for(int i = -5; i <= 5; i++)
    stack_push(stack_int, (void *)&i);
  stack_print(stack_int);
  
  type_t top = stack_top(stack_int);
  printf("Stack's top: %d\n", *(int*)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_int);
  printf("Element popped: %d\n", *(int*)popped_element);
  stack_print(stack_int);
  stack_destroy(stack_int);

}

void test_ulong() {
  Stack_t stack_ulong = stack_create(ULONG);

  printf("\n*** Adding 10 unsigned long elements to the stack ***\n");
  unsigned long n = 429496729;
  unsigned long temp = n;
  for(unsigned long i = 1; i <= 10; i++)
  {
    temp = n * i;
    stack_push(stack_ulong, (void *)&temp);
  }
  stack_print(stack_ulong);
  
  type_t top = stack_top(stack_ulong);
  printf("Stack's top: %lu\n", *(unsigned long*)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_ulong);
  printf("Element popped: %lu\n", *(unsigned long*)popped_element);
  stack_print(stack_ulong);
  stack_destroy(stack_ulong);
}
void test_long() {
    Stack_t stack_long = stack_create(LONG);

  printf("\n*** Adding 10 long elements to the stack ***\n");
  long n = 42946729;
  long temp = n;
  int sign = 1;
  for(long i = 1; i <= 10; i++)
  {
    sign = (i % 2) ? -1 : 1; 
    temp = n * i * sign;
    stack_push(stack_long, (void *)&temp);
  }
  stack_print(stack_long);
  
  type_t top = stack_top(stack_long);
  printf("Stack's top: %ld\n", *(long*)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_long);
  printf("Element popped: %ld\n", *(long*)popped_element);
  stack_print(stack_long);
  stack_destroy(stack_long);
}

void test_float() {
  Stack_t stack_float = stack_create(FLOAT);
  float f = 1.476f;
  float temp = f;
  printf("\n*** Adding 10 float elements to the stack ***\n");
  for(int i = 0; i < 10; i++) {
    temp = (i + f) * 1.5;
    stack_push(stack_float, (void *)&temp);
  }
  stack_print(stack_float);
  
  type_t top = stack_top(stack_float);
  printf("Stack's top: %.6f\n", *(float *)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_float);
  printf("Element popped: %.6f\n", *(float*)popped_element);
  stack_print(stack_float);
  stack_destroy(stack_float);
}

void test_double() {
  Stack_t stack_double = stack_create(DOUBLE);
  double f = 3.141592f;
  double temp = f;
  printf("\n*** Adding 10 double elements to the stack ***\n");
  for(int i = 0; i < 10; i++) {
    temp = (i + f) * 7.4525;
    stack_push(stack_double, (void *)&temp);
  }
  stack_print(stack_double);
  
  type_t top = stack_top(stack_double);
  printf("Stack's top: %.6f\n", *(double *)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_double);
  printf("Element popped: %.6f\n", *(double *)popped_element);
  stack_print(stack_double);
  stack_destroy(stack_double);
}

void test_string() {
  Stack_t stack_string = stack_create(STRING);

  printf("\n*** Adding 10 string elements to the stack ***\n");
  char *array[] = { "Testing", "my", "generic", "stack", "structure", \
                    "on", "C", "language", "How", "cool!" };
  for(int i = 0; i < 10; i++)
    stack_push(stack_string, (void *)array[i]);
  stack_print(stack_string);
  
  type_t top = stack_top(stack_string);
  printf("Stack's top: %s\n", (char *)top);

  printf("\n*** Removing the top of the stack ***\n");
  type_t popped_element = stack_pop(stack_string);
  printf("Element popped: %s\n", (char*)popped_element);
  stack_print(stack_string);
  stack_destroy(stack_string);
}