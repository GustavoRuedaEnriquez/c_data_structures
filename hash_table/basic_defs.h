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

#define GET_DATA_SIZE(t,d)  \
((t==DATATYPE_UINT)  ? sizeof(unsigned int)   :\
 (t==DATATYPE_INT)   ? sizeof(int)            :\
 (t==DATATYPE_ULONG) ? sizeof(unsigned long)  :\
 (t==DATATYPE_LONG)  ? sizeof(long)           :\
 (t==DATATYPE_FLOAT) ? sizeof(float)          :\
 (t==DATATYPE_DOUBLE)? sizeof(double)         :\
 (t==DATATYPE_STRING)? (sizeof(char) * strlen(d)) + 1 : -1)

#define GET_COPY_DATA_SIZE(t,d)  \
((t==DATATYPE_UINT)  ? sizeof(unsigned int)      :\
 (t==DATATYPE_INT)   ? sizeof(int)               :\
 (t==DATATYPE_ULONG) ? sizeof(unsigned long)     :\
 (t==DATATYPE_LONG)  ? sizeof(long)              :\
 (t==DATATYPE_FLOAT) ? sizeof(float)             :\
 (t==DATATYPE_DOUBLE)? sizeof(double)            :\
 (t==DATATYPE_STRING)? (sizeof(char) * strlen(d)): -1)

#define IS_DATA_EQUAL(t,x,y) \
((t==DATATYPE_UINT)  ? (VOID_PTR_2_UINT(x) == VOID_PTR_2_UINT(y))                  :\
 (t==DATATYPE_INT)   ? (VOID_PTR_2_INT(x) == VOID_PTR_2_INT(y))                    :\
 (t==DATATYPE_ULONG) ? (VOID_PTR_2_LONG(x) == VOID_PTR_2_LONG(y))                  :\
 (t==DATATYPE_LONG)  ? (VOID_PTR_2_ULONG(x) == VOID_PTR_2_ULONG(y))                :\
 (t==DATATYPE_FLOAT) ? (VOID_PTR_2_FLOAT(x) == VOID_PTR_2_FLOAT(y))                :\
 (t==DATATYPE_DOUBLE)? (VOID_PTR_2_DOUBLE(x) == VOID_PTR_2_DOUBLE(y))              :\
 (t==DATATYPE_STRING)? (strcmp(VOID_PTR_2_CHAR_PTR(x), VOID_PTR_2_CHAR_PTR(y))==0) :\
 -1)

#define COMPARE_TYPE_T(t,x,y) \
((t==DATATYPE_UINT)  ? (VOID_PTR_2_UINT(x) - VOID_PTR_2_UINT(y))                  :\
 (t==DATATYPE_INT)   ? (VOID_PTR_2_INT(x) - VOID_PTR_2_INT(y))                    :\
 (t==DATATYPE_ULONG) ? (VOID_PTR_2_LONG(x) - VOID_PTR_2_LONG(y))                  :\
 (t==DATATYPE_LONG)  ? (VOID_PTR_2_ULONG(x) - VOID_PTR_2_ULONG(y))                :\
 (t==DATATYPE_FLOAT) ? (VOID_PTR_2_FLOAT(x) - VOID_PTR_2_FLOAT(y))                :\
 (t==DATATYPE_DOUBLE)? (VOID_PTR_2_DOUBLE(x) - VOID_PTR_2_DOUBLE(y))              :\
 (t==DATATYPE_STRING)? (strcmp(VOID_PTR_2_CHAR_PTR(x), VOID_PTR_2_CHAR_PTR(y))) :\
 -1)
typedef void * type_t;

typedef enum {
  FALSE = 0,
  TRUE  = 1
} bool_t;

typedef enum {
  DATATYPE_UINT,
  DATATYPE_INT,
  DATATYPE_ULONG,
  DATATYPE_LONG,
  DATATYPE_FLOAT,
  DATATYPE_DOUBLE,
  DATATYPE_STRING,
  DATATYPE_MIXED,
} datatype_t;

#endif /* BASIC_DEFS_H_ */
