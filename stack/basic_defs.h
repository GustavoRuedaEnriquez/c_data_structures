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
