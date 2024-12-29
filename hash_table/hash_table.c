/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

struct HT_bucket_node_struct {
  type_t key;
  type_t value;
  struct HT_bucket_node_struct *prior;
  struct HT_bucket_node_struct *next;
}

struct HT_bucket_struct {
  size_t bucket_size;
  Bucket_Node_t front;
}

struct HT_struct {
  size_t buckets_capacity;
  size_t size;
  datatype_t key_type;
  datatype_t value_type;
  HashTable_Bucket_t buckets[HASH_TABLE_BUCKETS];
}

/* Private functions */
Bucket_Node_t _create_node(type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type);
unsigned int _hash_function(datatype_t key_type, type_t key);
unsigned int _hash_djb2(char *word);
//bool_t _search_bucket(Bucket_Node_t node, datatype_t key_type, type_t key);
bool_t _insert_into_bucket(HashTable_Bucket_t bucket,
                           type_t key, datatype_t k_type,
                           type_t value, datatype_t val_type);
void _print_bucket(HashTable_Bucket_t bucket);

Bucket_Node_t _create_node(type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type) {
  // Create new node
  Bucket_Node_t new_node = malloc(sizeof(struct HT_bucket_node_struct));
  memset(new_node, 0, sizeof(struct HT_bucket_node_struct));

  // Fill key
  new_node->key = malloc(GET_DATA_SIZE(k_type, key));
  memset(new_node->key, 0, GET_DATA_SIZE(k_type, key));
  memcpy(new_node->key, key, GET_COPY_DATA_SIZE(k_type, data));
  
  // Fill value
  new_node->value = malloc(GET_DATA_SIZE(v_type, value));
  memset(new_node->value, 0, GET_DATA_SIZE(v_type, value));
  memcpy(new_node->value, value, GET_COPY_DATA_SIZE(v_type, value));
  
  // Set neighbor nodes to NULL
  new_node->prior = NULL;
  new_node->next = NULL;

  return new_node;
}

unsigned int _hash_function(datatype_t key_type, type_t key)
{
  unsigned int hash = 0;

  // For hashing unsigned integer keys, we will use the modulo method.
  if (key_type == UNSIGNED_INTEGER)
    hash = VOID_PTR_2_UNSIGNED_INT(key) % HT_BUCKETS;

  // For hashing string keys, we will use dbj2 hashing method.
  else if (key_type == STRING)
  {
    hash = _hash_djb2(VOID_PTR_2_CHAR_PTR(key));
  }

  return hash;
}

bool_t _insert_into_bucket(HashTable_Bucket_t bucket,
                           type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type) {
  // Create new node
  Bucket_Node_t new_node = _create_node(key, k_type, value, v_type)

  // First case, bucket is empty, directly add the node to the front.
  if (bucket->size == 0) {
    bucket->front = new_node;
    bucket->size += 1;
  }
  // Second case, bucket is not empty and will add new node in the correct place
  // (all bucket elements are sorted).
  else {
    Bucket_Node_t current_node = bucket->front;
    for (int i = 0; i < bucket->size; i++) {
      if (COMPARE_TYPE_T(v_type, ))
    }
  }
}

void _print_bucket(HashTable_Bucket_t bucket)
{
  if (bucket->size <= 0)
  {
    printf("-");
  }
  else
  {
    size_t i = bucket->size;
    Bucket_Node_t temp = bucket->bucket_front;
    while (i > 0 && temp != NULL)
    {
      printf("%d:%d", *(int*)temp->key, *(int*)temp->value);
      i--;
      temp = temp->next;
      if (i > 0 && temp != NULL)
      {
        printf(" -> ")
      }
    }
    printf("\n");
  }
  return;
}

/*******/

HashTable_t hashtable_create(datatype_t k_type, datatype_t v_type)
{
  HashTable_t ht = calloc(1, sizeof(struct HT_struct));
  memset(ht, 0, sizeof(struct HT_struct));

  ht->key_type = k_type;
  ht->value_type = v_type;

  // Initialize all buckets. All buckets are initialized empty.
  for (int i = 0; i < HASH_TABLE_BUCKETS; i++)
  {
    ht->buckets[i] = calloc(1, sizeof(struct HT_bucket_struct));
    memset(ht->buckets[i], 0, sizeof(struct HT_bucket_struct));

    ht->buckets[i]->bucket_size = 0;
    ht->buckets[i]->bucket_front = NULL;
  } 

  ht->buckets_capacity = HT_BUCKETS_CAPACITY;
  ht->size = 0;

  return ht;
}

void hashtable_insert(HashTable_t ht, type_t key, type_t value)
{
  // If HT size is at limit, do not insert
  if (ht->size == HT_BUCKETS * HT_BUCKETS_CAPACITY)
  {
    // TODO return proper error code.
    return;
  }

  // Calculate bucket number and insert into bucket
  unsigned int bucket_idx = _hash_function(ht->key_type, key);
  _insert_into_bucket(ht->buckets[bucket_idx], key, value, ht->key_type);
}

size_t hashtable_size(Hashtable_t ht)
{
  return ht->size;
}

void hashtable_print(Hashtable_t ht)
{
  printf("Hash table has %d element(s)\n", ht->size);
  for (int i = 0; i < HASH_TABLE_BUCKETS; i++)
  {
    if (ht->buckets[i]->bucket_size != 0)
    {
      printf("bucket[%d]: ", i);
      _print_bucket(ht->buckets[i]);
    }
  } 
  
}
