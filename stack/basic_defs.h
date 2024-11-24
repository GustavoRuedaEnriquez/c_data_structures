/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/

#ifndef BASIC_DEFS_H_
#define BASIC_DEFS_H_

#define VOID_PTR_2_UNSIGNED_INT(x) (*(unsigned int*)x)
#define VOID_PTR_2_CHAR_PTR(x)     ((char*)x)

typedef void * type_t;

typedef enum {
  FALSE = 0,
  TRUE  = 1
} bool_t;

#endif /* BASIC_DEFS_H_ */
