/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#include "basic_defs.h"

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#define VOID_PTR_2_UNSIGNED_INT(x) (*(unsigned int*)x)
#define VOID_PTR_2_CHAR_PTR(x)     ((char*)x)

#define HT_BUCKETS_CAPACITY 100
#define HT_BUCKETS 100

#define HT_ERR_CODE_BASE                                                   10000
#define HT_ERR_OK                                                              0
#define HT_ERR_BUCKET_NODE_ADDED                          (HT_ERR_CODE_BASE + 1)
#define HT_ERR_BUCKET_NODE_REPLACED                       (HT_ERR_CODE_BASE + 2)
#define HT_ERR_HASHTABLE_FULL                             (HT_ERR_CODE_BASE + 3)
#define HT_ERR_KEY_NOT_FOUND                              (HT_ERR_CODE_BASE + 4)

typedef void * type_t;
typedef struct HT_bucket_node_struct  *Bucket_Node_t;
typedef struct HT_bucket_struct *HashTable_Bucket_t;
typedef struct HT_struct *HashTable_t;
typedef unsigned int ht_err_code_t;

HashTable_t hashtable_create(datatype_t k_type, datatype_t v_type);
ht_err_code_t hashtable_insert(HashTable_t ht, type_t key, type_t value);
type_t hashtable_get(HashTable_t ht, type_t key);

//ht_err_code_t hashtable_update(HashTable_t ht, type_t key, type_t value);
//ht_err_code_t hashtable_delete(HashTable_t ht, type_t key);
//bool_t hashtable_contains(HashTable_t ht, type_t key);

size_t hashtable_size(HashTable_t ht);
void hashtable_print(HashTable_t ht);

#endif /* HASH_TABLE_H_ */

