/*
Coded by Gustavo Adolfo Rueda Enríquez
May 16th 2022
*/

#include "basic_defs.h"
#ifndef STACK_H_
#define STACK_H_

/* Structure the represents a stack node, it has 2 attributes:
 * - type_t data: Information that will be stored on the stack node.
 * - Stack_Node_t prior: Pointer to the previous node.
 */
typedef struct Stack_Node_struct * Stack_Node_t;

/* Structure the represents a stack, it has 3 attributes:
 * - Stack_Node_t top: Pointer to the stack's top entry.
 * - unsigned int size: Current stack's size.
 * - datatype_T datatype: Enum that represents the datatype of the entries
 *                        stored on the stack.
 */
typedef struct Stack_struct * Stack_t;

/* FUNCTION:
 * stack_create
 *
 * DESCRIPTION:
 * Function used to initialize a stack. Returned stack will have a size of 0
 * and it's top will equal to NULL.
 *
 * PARAMETERS:
 * datatype_t - Indicates the data type that will be stored on the stack.
 *
 * RETURNS:
 * Stack_t - Pointer to the recently created stack structure.
 */
Stack_t stack_create(datatype_t);


/* FUNCTION:
 * stack_push
 *
 * DESCRIPTION:
 * Adds new entry to the stack's top.
 *
 * PARAMETERS:
 * Stack_t - Stack structure which we want to add an entry.
 * type_t  - Data entry to add to the stack. 
 *
 * RETURNS:
 * Nothing
 */
void stack_push(Stack_t, type_t);


/* FUNCTION:
 * stack_top
 *
 * DESCRIPTION:
 * Returns the stack's top. This function DOES NOT remove the top element.
 *
 * PARAMETERS:
 * Stack_t - Stack structure from which we want to obtain the top element.
 *
 * RETURNS:
 * type_t - Entry at stack's top.
 */
type_t stack_top(Stack_t);


/* FUNCTION:
 * stack_pop
 *
 * DESCRIPTION:
 * Removes the stack's top and returns it.
 *
 * PARAMETERS:
 * Stack_t - Stack structure from which we want to remove the top element.
 *
 * RETURNS:
 * type_t - Entry at stack's top.
 */
type_t stack_pop(Stack_t);

/* FUNCTION:
 * stack_size
 *
 * DESCRIPTION:
 * Returns current size of the stack.
 *
 * PARAMETERS:
 * Stack_t - Stack structure from which we want to obtain the size.
 *
 * RETURNS:
 * unsigned int - Current size of the stack.
 */
unsigned int stack_size(Stack_t);


/* FUNCTION:
 * stack_is_empty
 *
 * DESCRIPTION:
 * Tells if stack is empty or not.
 *
 * PARAMETERS:
 * Stack_t - Stack structure from which we want to know if it is empty.
 *
 * RETURNS:
 * bool_t - TRUE/FALSE depending if stack's empty or not.
 */
bool_t stack_is_empty(Stack_t);


/* FUNCTION:
 * stack_destroy
 *
 * DESCRIPTION:
 * Frees the memory used by a stack structure.
 *
 * PARAMETERS:
 * Stack_t - Stack structure to destroy. 
 *
 * RETURNS:
 * Nothing
 */
void stack_destroy(Stack_t);


/* FUNCTION:
 * stack_print
 *
 * DESCRIPTION:
 * Prints all the stack's entries.
 *
 * PARAMETERS:
 * Stack_t - Stack structure to print. 
 *
 * RETURNS:
 * Nothing
 */
void stack_print(Stack_t);

#endif /* STACK_H_ */
