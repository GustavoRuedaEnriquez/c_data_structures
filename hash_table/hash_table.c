/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct HT_bucket_node_struct {
  type_t key;
  type_t value;
  struct HT_bucket_node_struct *prior;
  struct HT_bucket_node_struct *next;
};

struct HT_bucket_struct {
  size_t bucket_size;
  Bucket_Node_t bucket_front;
};

struct HT_struct {
  size_t buckets_capacity;
  size_t size;
  datatype_t key_type;
  datatype_t value_type;
  HashTable_Bucket_t buckets[HT_BUCKETS];
};

/* Private functions */
Bucket_Node_t _create_node(type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type);

unsigned int _hash_function(datatype_t key_type, type_t key);

unsigned int _hash_dbj2(char *word);

bool_t _insert_into_bucket(HashTable_Bucket_t bucket,
                           type_t key, datatype_t k_type,
                           type_t value, datatype_t val_type);

void _print_bucket(HashTable_Bucket_t bucket, datatype_t k_type,
                   datatype_t v_type);

void _print_keyval(type_t keyval, datatype_t kv_type);

Bucket_Node_t _create_node(type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type) {
  // Create new node
  Bucket_Node_t new_node = malloc(sizeof(struct HT_bucket_node_struct));
  memset(new_node, 0, sizeof(struct HT_bucket_node_struct));

  // Fill key
  new_node->key = malloc(GET_DATA_SIZE(k_type, key));
  memset(new_node->key, 0, GET_DATA_SIZE(k_type, key));
  memcpy(new_node->key, key, GET_COPY_DATA_SIZE(k_type, key));
  
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
  if (key_type == DATATYPE_UINT)
    hash = VOID_PTR_2_UNSIGNED_INT(key) % HT_BUCKETS;

  // For hashing string keys, we will use dbj2 hashing method.
  else if (key_type == DATATYPE_STRING)
  {
    hash = _hash_dbj2(VOID_PTR_2_CHAR_PTR(key));
  }

  return hash;
}

unsigned int _hash_dbj2(char *word) {
  unsigned int hash = 5381;
   int c;

  while (c = *word++) {
    if (isupper(c)) {
      c = c + 32;
    }

    hash = ((hash << 5) + hash) + c; // hash * 33 + c
  }

  return hash % HT_BUCKETS;
}



ht_err_code_t _insert_into_bucket(HashTable_Bucket_t bucket,
                           type_t key, datatype_t k_type,
                           type_t value, datatype_t v_type) {
  ht_err_code_t ret = HT_ERR_OK;

  // Create new node
  Bucket_Node_t new_node = _create_node(key, k_type, value, v_type);

  // First case, bucket is empty, directly add the node to the front.
  if (bucket->bucket_size == 0) {
    bucket->bucket_front = new_node;
    ret = HT_ERR_BUCKET_NODE_ADDED;
  }

  // Second case, bucket is not empty and will add new node in the correct place
  // (all bucket elements are sorted).
  else {
    Bucket_Node_t current_node = bucket->bucket_front;
    Bucket_Node_t prior_node = NULL;
    bool_t keep_processing = TRUE;

    while (keep_processing) {
      prior_node = current_node->prior;

      // If new node's key is lesser than current node's key, insert new
      // node before current node and exit loop.
      if (IS_DATA_LESS_THAN(k_type, key, current_node->key)) {
        new_node->next = current_node;
        // Change "next" pointer of prior's node.
        if (prior_node != NULL)
          prior_node->next = new_node;
        // Handle the case where new node will be the new bucket's front
        else
          bucket->bucket_front = new_node;
        
        current_node->prior = new_node;
        ret = HT_ERR_BUCKET_NODE_ADDED;
        keep_processing = FALSE;
        continue;
      }

      // If new node's key is equal than current node's key, we will replace
      // current node's with new one and exit loop
      else if (IS_DATA_EQUAL(k_type, key, current_node->key)) {
        // Change "next" pointer of prior's node.
        if (prior_node != NULL)
          prior_node->next = new_node;
        // Handle the case where new node will be the new bucket's front
        else
          bucket->bucket_front = new_node;
        
        new_node->next = current_node->next;
        
        // Free current node memory.
        free(current_node->key);
        free(current_node->value);
        free(current_node);

        ret = HT_ERR_BUCKET_NODE_REPLACED;
        keep_processing = FALSE;
        continue;
      }

      // If this is the last node, stop processing.
      if (current_node->next == NULL)
        keep_processing = FALSE;
      else
        current_node = current_node->next;
    }

    // If a new node was not added at this point, it means that the value was
    // the greatest of all elements of the bucket, so it needs to be added on
    // the end of the bucket.
    if (ret != HT_ERR_BUCKET_NODE_ADDED && ret != HT_ERR_BUCKET_NODE_REPLACED) {
      current_node->next = new_node;
      new_node->prior = current_node;
      ret = HT_ERR_BUCKET_NODE_ADDED;
    }

  }

  // Increase bucket's size
  if (ret == HT_ERR_BUCKET_NODE_ADDED)
    bucket->bucket_size += 1;

  return ret;
}

void _print_bucket(HashTable_Bucket_t bucket, datatype_t k_type,
                   datatype_t v_type) {
  if (bucket->bucket_size <= 0) {
    printf("-");
  }
  else {
    size_t i = bucket->bucket_size;
    Bucket_Node_t temp = bucket->bucket_front;
    while (i > 0 && temp != NULL) {
      _print_keyval(temp->key, k_type);
      printf(":");
      _print_keyval(temp->value, v_type);
      i--;
      temp = temp->next;
      if (i > 0 && temp != NULL) {
        printf(" -> ");
      }
    }
    printf("\n");
  }
  return;
}

void _print_keyval(type_t keyval, datatype_t kv_type) {
  if (kv_type == DATATYPE_UINT)
    printf("%u", VOID_PTR_2_UINT(keyval));
  else if (kv_type == DATATYPE_INT)
    printf("%d", VOID_PTR_2_INT(keyval));
  else if (kv_type == DATATYPE_ULONG)
    printf("%lu", VOID_PTR_2_ULONG(keyval));
  else if (kv_type == DATATYPE_LONG)
    printf("%ld", VOID_PTR_2_LONG(keyval));
  else if (kv_type == DATATYPE_FLOAT)
    printf("%.6f", VOID_PTR_2_FLOAT(keyval));
  else if (kv_type == DATATYPE_DOUBLE)
    printf("%.6f", VOID_PTR_2_DOUBLE(keyval));
  else if (kv_type == DATATYPE_STRING)
    printf("\"%s\"", keyval);
}

/*******/

HashTable_t hashtable_create(datatype_t k_type, datatype_t v_type)
{
  HashTable_t ht = calloc(1, sizeof(struct HT_struct));
  memset(ht, 0, sizeof(struct HT_struct));

  ht->key_type = k_type;
  ht->value_type = v_type;

  // Initialize all buckets. All buckets are initialized empty.
  for (int i = 0; i < HT_BUCKETS; i++)
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

ht_err_code_t hashtable_insert(HashTable_t ht, type_t key, type_t value)
{
  ht_err_code_t ret = HT_ERR_OK;

  // If HT size is at limit, do not insert
  if (ht->size == HT_BUCKETS * HT_BUCKETS_CAPACITY)
    return HT_ERR_HASHTABLE_FULL;

  // Calculate bucket number and insert into bucket
  unsigned int bucket_idx = _hash_function(ht->key_type, key);
  ret = _insert_into_bucket(ht->buckets[bucket_idx], key, ht->key_type, value,
                            ht->value_type);
  if (ret == HT_ERR_BUCKET_NODE_ADDED)
    ht->size += 1;

  return HT_ERR_OK;
}

size_t hashtable_size(HashTable_t ht)
{
  return ht->size;
}

void hashtable_print(HashTable_t ht)
{
  printf("Hash table has %d element(s)\n", ht->size);
  for (int i = 0; i < HT_BUCKETS; i++)
  {
    if (ht->buckets[i]->bucket_size != 0)
    {
      printf("bucket[%d]: ", i);
      _print_bucket(ht->buckets[i], ht->key_type, ht->value_type);
    }
  } 
  
}
