/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/
#include <string.h>
#ifndef BASIC_DEFS_H_
#define BASIC_DEFS_H_

#define VOID_PTR_2_UNSIGNED_INT(x) (*(unsigned int*)x)
#define VOID_PTR_2_INT(x)          (*(int*)x)
#define VOID_PTR_2_CHAR_PTR(x)     ((char*)x)

#define GET_DATA_SIZE(t,d)  ((t==UINT)  ?sizeof(unsigned int)           :\
                             (t==INT)   ?sizeof(int)                    :\
                             (t==STRING)?(sizeof(char) * strlen(d)) + 1 : -1)
typedef void * type_t;

typedef enum {
  FALSE = 0,
  TRUE  = 1
} bool_t;

typedef enum {
  UINT,
  INT,
  STRING,
  MIXED,
} datatype_t;

#endif /* BASIC_DEFS_H_ */
