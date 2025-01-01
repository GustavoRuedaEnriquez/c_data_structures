/*
Coded by Gustavo Adolfo Rueda Enríquez
Dec 29th 2024
*/

#include"hash_table.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
  /*
  HashTable_t ht = hashtable_create(DATATYPE_UINT, DATATYPE_UINT);
  unsigned int val = 7;
  int sign = 1;
  for (unsigned int i = 0; i < 25; i++) {
    sign = (i % 2 == 0) ? 1 : -1;
    val = i + ((i * 3) + (4 * sign));
    hashtable_insert(ht, ((void *)&i), (void *)&val);
    hashtable_print(ht);
    printf("\n");
  }
  */
  HashTable_t ht = hashtable_create(DATATYPE_STRING, DATATYPE_STRING);
  char *array[] = { "this is my key 1", "key_2", "key 3", "Key 4", "KEY 5", \
                    "key 6", "key_7", "key 8", "Key 9", "KEY 10", \
                    "key 11", "key_12", "key 13", "Key 14", "KEY15", \
                    "key 16", "key_17", "key l8", "Key 19", "KEY z0", };
  for (int i = 0; i < 20; i++) {
    hashtable_insert(ht,(void *)array[i], (void *)array[i]);
    //hashtable_print(ht);
    //printf("\n");
  }
  //hashtable_print(ht);

  // Getting one element
  char *key = "key 16";
  type_t value = hashtable_get(ht, (void *)key);
  printf("%s\n", (char *)value);
}