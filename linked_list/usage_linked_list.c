/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include"linked_list.h"
#include<stdio.h>
#include<stdlib.h>

void test_uint();
//void test_int();
//void test_ulong();
//void test_long();
//void test_float();
//void test_double();
//void test_string();

int main() {
  printf("====== Testing queue for unsigned integers ======\n");
  test_uint();

  printf("\n\n\n");
/*
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
*/
    return 0;
}

void test_uint() {
  Linked_List_t list_uint = linked_list_create(DATATYPE_UINT);

  printf("\n*** Adding 10 unsigned integers elements to the linked list ***\n");
  for(unsigned int i = 1; i <= 10; i++)
    linked_list_add(list_uint, (void *)&i);
  type_t front = linked_list_get_front(list_uint);
  type_t back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  printf("\n*** Changing the value of the 4th element ***\n");
  unsigned int value = 56;
  linked_list_set(list_uint, 4, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  printf("\n*** Adding a value to the front of the linked list ***\n");
  value = 128;
  linked_list_add_front(list_uint, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  printf("\n*** Adding a value to the back of the linked list ***\n");
  value = 63;
  linked_list_add_back(list_uint, (void *)&value);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);
  
  printf("\n*** Getting the 7th element of the list ***\n");
  type_t search = linked_list_get_index(list_uint, 7);
  printf("7th element contains: %u\n", *(unsigned int*)search);

  printf("\n*** Searching for the element that has value of 56 ***\n");
  value = 56;
  int index = linked_list_index_of(list_uint, (void *)&value);
  printf("Desired node (%u) is on index %d\n", value, index);

  printf("\n*** Deleting 1st element of the list ***\n");
  linked_list_print(list_uint);
  linked_list_remove_front(list_uint);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  printf("\n*** Deleting last element of the list ***\n");
  linked_list_print(list_uint);
  linked_list_remove_back(list_uint);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  printf("\n*** Deleting 6th element of the list ***\n");
  linked_list_print(list_uint);
  linked_list_remove_index(list_uint, 6);
  front = linked_list_get_front(list_uint);
  back = linked_list_get_back(list_uint);
  printf("Front: %u\tBack: %u\n", *(unsigned int*)front, *(unsigned int*)back);
  linked_list_print(list_uint);

  linked_list_destroy(list_uint);
}