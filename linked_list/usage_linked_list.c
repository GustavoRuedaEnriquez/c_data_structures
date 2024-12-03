/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>

void test_uint();
void test_int();
void test_ulong();
//void test_long();
//void test_float();
//void test_double();
void test_string();

int main() {
  /*printf("====== Testing queue for unsigned integers ======\n");
  test_uint();

  printf("\n\n\n");

  printf("====== Testing queue for integers ======\n");
  test_int();

  printf("\n\n\n");*/

  printf("====== Testing queue for unsigned longs ======\n");
  test_ulong();

  printf("\n\n\n");

  /*printf("====== Testing queue for longs ======\n");
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

  printf("\n\n\n");*/

    return 0;
}

void test_uint() {
  Linked_List_t list_uint = linked_list_create(DATATYPE_UINT);

  printf("\n*** Adding 10 unsigned integers elements to the linked list ***\n");
  for(unsigned int i = 1; i <= 10; i++)
    linked_list_add(list_uint, (void *)&i);
  type_t front = linked_list_get_front(list_uint);
  type_t back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Changing the value of the 4th element ***\n");
  unsigned int value = 56;
  linked_list_set(list_uint, 4, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Adding a value to the front of the linked list ***\n");
  value = 128;
  linked_list_add_front(list_uint, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Adding a value to the back of the linked list ***\n");
  value = 63;
  linked_list_add_back(list_uint, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);
  
  printf("\n*** Getting the 7th element of the list ***\n");
  type_t search = linked_list_get_index(list_uint, 7);
  printf("7th element contains: %u\n", *(unsigned int *)search);

  printf("\n*** Searching for the element that has value of 56 ***\n");
  value = 56;
  int index = linked_list_index_of(list_uint, (void *)&value);
  printf("Desired node (%u) is on index %d\n", value, index);

  printf("\n*** Deleting 1st element of the list ***\n");
  linked_list_remove_front(list_uint);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Deleting last element of the list ***\n");
  linked_list_remove_back(list_uint);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Deleting 6th element of the list ***\n");
  linked_list_remove_index(list_uint, 6);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int *)front, *(unsigned int *)back);
  linked_list_print(list_uint);

  printf("\n*** Clearing the list ***\n");
  linked_list_clear(list_uint);
  linked_list_print(list_uint);

  linked_list_destroy(list_uint);
}

void test_int() {
  Linked_List_t list_int = linked_list_create(DATATYPE_INT);

  printf("\n*** Adding 10 integers elements to the linked list ***\n");
  for(int i = -5; i <= 5; i++)
    linked_list_add(list_int, (void *)&i);
  type_t front = linked_list_get_front(list_int);
  type_t back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Changing the value of the 4th element ***\n");
  int value = -96;
  linked_list_set(list_int, 4, (void *)&value);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Adding a value to the front of the linked list ***\n");
  value = -1024;
  linked_list_add_front(list_int, (void *)&value);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Adding a value to the back of the linked list ***\n");
  value = -8564;
  linked_list_add_back(list_int, (void *)&value);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);
  
  printf("\n*** Getting the 7th element of the list ***\n");
  type_t search = linked_list_get_index(list_int, 7);
  printf("7th element contains: %d\n", *(int *)search);

  printf("\n*** Searching for the element that has value of 56 ***\n");
  value = -8564;
  int index = linked_list_index_of(list_int, (void *)&value);
  printf("Desired node (%d) is on index %d\n", value, index);

  printf("\n*** Deleting 1st element of the list ***\n");
  linked_list_remove_front(list_int);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Deleting last element of the list ***\n");
  linked_list_remove_back(list_int);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Deleting 6th element of the list ***\n");
  linked_list_remove_index(list_int, 6);
  front = linked_list_get_front(list_int);
  back = linked_list_get_back(list_int);
  printf("Front: %d\tBack: %d\n", *(int *)front, *(int *)back);
  linked_list_print(list_int);

  printf("\n*** Clearing the list ***\n");
  linked_list_clear(list_int);
  linked_list_print(list_int);
  
  linked_list_destroy(list_int);
}

void test_ulong() {
  Linked_List_t list_ulong = linked_list_create(DATATYPE_ULONG);
  unsigned long r = 0;

  printf("\n*** Adding 10 unsigned longs elements to the linked list ***\n");
  for(int i = 0; i < 10; i++) {
    r = rand() % (40000000 - 0 + 1) + 0;
    linked_list_add(list_ulong, (void *)&r);
  }

  type_t front = linked_list_get_front(list_ulong);
  type_t back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Changing the value of the 4th element ***\n");
  unsigned long value = 5687634;
  linked_list_set(list_ulong, 4, (void *)&value);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Adding a value to the front of the linked list ***\n");
  value = 120988;
  linked_list_add_front(list_ulong, (void *)&value);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Adding a value to the back of the linked list ***\n");
  value = 63453;
  linked_list_add_back(list_ulong, (void *)&value);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);
  
  printf("\n*** Getting the 7th element of the list ***\n");
  type_t search = linked_list_get_index(list_ulong, 7);
  printf("7th element contains: %lu\n", *(unsigned long *)search);

  printf("\n*** Searching for the element that has value of 56 ***\n");
  value = 5687634;
  int index = linked_list_index_of(list_ulong, (void *)&value);
  printf("Desired node (%lu) is on index %d\n", value, index);

  printf("\n*** Deleting 1st element of the list ***\n");
  linked_list_remove_front(list_ulong);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Deleting last element of the list ***\n");
  linked_list_remove_back(list_ulong);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Deleting 6th element of the list ***\n");
  linked_list_remove_index(list_ulong, 6);
  front = linked_list_get_front(list_ulong);
  back = linked_list_get_back(list_ulong);
  printf("Front: %lu\tBack: %lu\n", *(unsigned long *)front, *(unsigned long *)back);
  linked_list_print(list_ulong);

  printf("\n*** Clearing the list ***\n");
  linked_list_clear(list_ulong);
  linked_list_print(list_ulong);

  linked_list_destroy(list_ulong);
}

void test_string() {
  Linked_List_t list_string = linked_list_create(DATATYPE_STRING);

  printf("\n*** Adding 10 string elements to the linked list ***\n");
  char *array[] = { "Testing", "my", "generic", "list", "structure", \
                    "on", "C", "language", "How", "cool!" };
  for(int i = 0; i < 10; i++)
    linked_list_add(list_string, (void *)array[i]);
  type_t front = linked_list_get_front(list_string);
  type_t back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Changing the value of the 4th element ***\n");
  char *value = "amazing";
  linked_list_set(list_string, 4, (void *)value);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Adding a value to the front of the linked list ***\n");
  value = "Look a this!";
  linked_list_add_front(list_string, (void *)value);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Adding a value to the back of the linked list ***\n");
  value = "This is the last element";
  linked_list_add_back(list_string, (void *)value);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);
  
  printf("\n*** Getting the 7th element of the list ***\n");
  type_t search = linked_list_get_index(list_string, 7);
  printf("7th element contains: %s\n", (char *)search);

  printf("\n*** Searching for the element that has value of \"amazing\" ***\n");
  value = "amazing";
  int index = linked_list_index_of(list_string, (void *)value);
  printf("Desired node (%s) is on index %i\n", value, index);

  printf("\n*** Deleting 1st element of the list ***\n");
  linked_list_remove_front(list_string);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Deleting last element of the list ***\n");
  linked_list_remove_back(list_string);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Deleting 6th element of the list ***\n");
  linked_list_remove_index(list_string, 6);
  front = linked_list_get_front(list_string);
  back = linked_list_get_back(list_string);
  printf("Front: %s\tBack: %s\n", (char *)front, (char *)back);
  linked_list_print(list_string);

  printf("\n*** Clearing the list ***\n");
  linked_list_clear(list_string);
  linked_list_print(list_string);
  
  linked_list_destroy(list_string);
}