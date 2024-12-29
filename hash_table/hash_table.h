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

typedef enum {
    OK = 0,
    UNEXPECTED_ERROR = 1,
    INVALID_VALUE_TYPE = 2
} error_code_t;

typedef enum {
    FALSE = 0,
    TRUE  = 1
} bool_t;

typedef void * type_t;
typedef struct HT_bucket_node_struct  *Bucket_Node_t;
typedef struct HT_bucket_struct *HashTable_Bucket_t;
typedef struct HT_struct *HashTable_t;

HashTable_t hashtable_create(datatype_t k_type, datatype_t v_type);
void hashtable_insert(HashTable_t ht, type_t key, type_t value);
error_code_t hashtable_delete(HashTable_t ht, type_t key);
error_code_t hashtable_get(HashTable_t ht, type_t key, type_t dest);
bool_t hashtable_search(HashTable_t ht, type_t key);
size_t hashtable_size(Hashtable_t ht);
void hashtable_print(Hashtable_t ht);

#endif /* HASH_TABLE_H_ */

