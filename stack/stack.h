/*
Coded by Gustavo Adolfo Rueda Enríquez
May 16th 2022
*/

#ifndef STACK_H_
#define STACK_H_

typedef void * type_t;
typedef enum {FALSE, TRUE} bool_t;
typedef struct Node_str  * Node_t;
typedef struct Stack_str * Stack_t;

Stack_t stack_create();
int     stack_size(Stack_t);
bool_t  stack_isEmpty(Stack_t);
type_t  stack_top(Stack_t);
void    stack_push(Stack_t, type_t);
type_t  stack_pop(Stack_t);
void    stack_destroy(Stack_t);

#endif /* STACK_H_ */
