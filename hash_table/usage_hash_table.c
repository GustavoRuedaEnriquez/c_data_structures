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
  char *keys[] = { "key 1", "key 2", "key 3", "key 4", "key 5", \
                   "key 6", "key 7", "key 8", "Key 9", "key 10", \
                   "key 11", "key 12", "key 13", "key 14", "key 15", \
                   "key 16", "key 17", "key 18", "key 19", "key 20" };
  char *values[] = { "value 1", "value 2", "value 3", "value 4", "value 5", \
                     "value 6", "value 7", "value 8", "Key 9", "value 10", \
                     "value 11", "value 12", "value 13", "value 14", "value 15", \
                     "value 16", "value 17", "value 18", "value 19", "value 20" };

  for (int i = 0; i < 20; i++) {
    hashtable_insert(ht,(void *)keys[i], (void *)values[i]);
    //hashtable_print(ht);
    //printf("\n");
  }
  hashtable_print(ht);

  // Getting one element
  char *key = "key 5";
  type_t value = hashtable_get(ht, (void *)key);
  printf("%s\n", (char *)value);
}