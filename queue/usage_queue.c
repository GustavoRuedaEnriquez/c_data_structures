/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 19th 2022

Test for the queues's functions.
*/

#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void test_uint();
void test_int();
void test_ulong();
void test_long();
void test_float();
void test_double();
void test_string();

int main() {
  printf("====== Testing queue for unsigned integers ======\n");
  test_uint();

  printf("\n\n\n");

  printf("====== Testing queue for integers ======\n");
  test_int();

  printf("\n\n\n");

  printf("====== Testing queue for unsigned longs ======\n");
  test_ulong();

  printf("\n\n\n");

  printf("====== Testing queue for longs ======\n");
  test_long();

  printf("\n\n\n");

  printf("====== Testing queue for floats ======\n");
  test_float();

  printf("\n\n\n");

  printf("====== Testing queue for doubles ======\n");
  test_double();

  printf("\n\n\n");

  printf("====== Testing queue for strings ======\n");
  test_string();

  printf("\n\n\n");

    return 0;
}

void test_uint()
{
  Queue_t queue_uint = queue_create(DATATYPE_UINT); 

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_uint);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 unsigned integers elements to the queue ***\n");
  for(unsigned int i = 1; i <= 10; i++)
    queue_offer(queue_uint, (void *)&i);

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_uint);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_uint);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_uint);
  printf("Peeking queue's first element: %u\n", *(unsigned int *) first);
  queue_print(queue_uint);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_uint);
  printf("Polling queue's first element: %u\n", *(unsigned int *) first);
  queue_print(queue_uint);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_uint);
  printf("Polling queue's first element: %u\n", *(unsigned int *) first);
  queue_print(queue_uint);

  queue_destroy(queue_uint);
}

void test_int() {
  Queue_t queue_int = queue_create(DATATYPE_INT); 

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_int);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 integers elements to the queue ***\n");
  for(int i = -5; i <= 5; i++)
    queue_offer(queue_int, (void *)&i);
  queue_print(queue_int);

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_int);

  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_int);
  printf("Peeking queue's first element: %d\n", *(int *) first);
  queue_print(queue_int);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_int);
  printf("Polling queue's first element: %d\n", *(int *) first);
  queue_print(queue_int);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_int);
  printf("Polling queue's first element: %d\n", *(int *) first);
  queue_print(queue_int);

  queue_destroy(queue_int);
}

void test_ulong()
{
  Queue_t queue_ulong = queue_create(DATATYPE_ULONG); 
  unsigned long n = 429496729;
  unsigned long temp = n;

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_ulong);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 unsigned long elements to the queue ***\n");
  for(unsigned long i = 1; i <= 10; i++) {
    temp = n * i;
    queue_offer(queue_ulong, (void *)&temp);
  }

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_ulong);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_ulong);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_ulong);
  printf("Peeking queue's first element: %lu\n", *(unsigned long *) first);
  queue_print(queue_ulong);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_ulong);
  printf("Polling queue's first element: %lu\n", *(unsigned long *) first);
  queue_print(queue_ulong);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_ulong);
  printf("Polling queue's first element: %lu\n", *(unsigned long *) first);
  queue_print(queue_ulong);

  queue_destroy(queue_ulong);
}

void test_long() {
  Queue_t queue_long = queue_create(DATATYPE_LONG); 
  long n = 42934729;
  long temp = n;
  int sign = 1;

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_long);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 long elements to the queue ***\n");
  for(long i = 1; i <= 10; i++) {
    sign = (i % 2) ? -1 : 1; 
    temp = n * i * sign;
    queue_offer(queue_long, (void *)&temp);
  }

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_long);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_long);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_long);
  printf("Peeking queue's first element: %ld\n", *(long *) first);
  queue_print(queue_long);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_long);
  printf("Polling queue's first element: %ld\n", *(long *) first);
  queue_print(queue_long);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_long);
  printf("Polling queue's first element: %ld\n", *(long *) first);
  queue_print(queue_long);

  queue_destroy(queue_long);
}

void test_float() {
  Queue_t queue_float = queue_create(DATATYPE_FLOAT); 
  float f = 1.476f;
  float temp = f;

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_float);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 float elements to the queue ***\n");
  for(int i = 1; i <= 10; i++) {
    temp = (i + f) * 1.5;
    queue_offer(queue_float, (void *)&temp);
  }

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_float);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_float);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_float);
  printf("Peeking queue's first element: %.6f\n", *(float *) first);
  queue_print(queue_float);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_float);
  printf("Polling queue's first element: %.6f\n", *(float *) first);
  queue_print(queue_float);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_float);
  printf("Polling queue's first element: %.6f\n", *(float *) first);
  queue_print(queue_float);

  queue_destroy(queue_float);
}

void test_double() {
  Queue_t queue_double = queue_create(DATATYPE_DOUBLE); 
  double f = 3.141592f;
  double temp = f;

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_double);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 double elements to the queue ***\n");
  for(int i = 1; i <= 10; i++) {
    temp = (i + f) * 7.4525;
    queue_offer(queue_double, (void *)&temp);
  }

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_double);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_double);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_double);
  printf("Peeking queue's first element: %.6f\n", *(double *) first);
  queue_print(queue_double);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_double);
  printf("Polling queue's first element: %.6f\n", *(double *) first);
  queue_print(queue_double);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_double);
  printf("Polling queue's first element: %.6f\n", *(double *) first);
  queue_print(queue_double);

  queue_destroy(queue_double);
}

void test_string() {
  Queue_t queue_string = queue_create(DATATYPE_STRING); 
  char *array[] = { "Testing", "my", "generic", "stack", "structure", \
                    "on", "C", "language", "How", "cool!" };

  printf("\n*** Checking if queue is empty ***\n");
  bool_t is_empty = queue_is_empty(queue_string);
  printf("Queue empty: %d\n", is_empty);

  printf("\n*** Adding 10 string elements to the queue ***\n");
  for(int i = 0; i < 10; i++)
    queue_offer(queue_string, (void *)array[i]);

  printf("\n*** Checking if queue is empty ***\n");
  is_empty = queue_is_empty(queue_string);
  printf("Queue empty: %d\n", is_empty);

  queue_print(queue_string);

  printf("\n*** Peeking queue's front ***\n");
  type_t first = queue_peek(queue_string);
  printf("Peeking queue's first element: %s\n", (char *) first);
  queue_print(queue_string);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_string);
  printf("Polling queue's first element: %s\n", (char *) first);
  queue_print(queue_string);

  printf("\n*** Polling one element of the queue ***\n");
  first = queue_poll(queue_string);
  printf("Polling queue's first element: %s\n", (char *) first);
  queue_print(queue_string);

  queue_destroy(queue_string);
}