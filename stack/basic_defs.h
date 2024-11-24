/*
Coded by Gustavo Adolfo Rueda Enríquez
Nov 23rd 2024
*/
#include <string.h>
#ifndef BASIC_DEFS_H_
#define BASIC_DEFS_H_

#define VOID_PTR_2_UINT(x)     (*(unsigned int*)x)
#define VOID_PTR_2_INT(x)      (*(int*)x)
#define VOID_PTR_2_ULONG(x)    (*(unsigned long*)x)
#define VOID_PTR_2_LONG(x)     (*(long*)x)
#define VOID_PTR_2_FLOAT(x)    (*(float*)x)
#define VOID_PTR_2_DOUBLE(x)   (*(double*)x)
#define VOID_PTR_2_CHAR_PTR(x) ((char*)x)

#define GET_DATA_SIZE(t,d)  ((t==UINT)  ?sizeof(unsigned int)   :\
                             (t==INT)   ?sizeof(int)            :\
                             (t==ULONG)  ?sizeof(unsigned long) :\
                             (t==LONG)  ?sizeof(long)           :\
                             (t==FLOAT) ?sizeof(float)          :\
                             (t==DOUBLE)?sizeof(double)         :\
                             (t==STRING)?(sizeof(char) * strlen(d)) + 1 : -1)

typedef void * type_t;

typedef enum {
  FALSE = 0,
  TRUE  = 1
} bool_t;

typedef enum {
  UINT,
  INT,
  ULONG,
  LONG,
  FLOAT,
  DOUBLE,
  STRING,
  MIXED,
} datatype_t;

#endif /* BASIC_DEFS_H_ */
