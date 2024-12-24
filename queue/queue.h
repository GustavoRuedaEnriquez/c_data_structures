/*
Coded by Gustavo Adolfo Rueda Enríquez
May 19th 2022
*/

#include "basic_defs.h"
#ifndef QUEUE_H_
#define QUEUE_H_

/* Structure the represents a queue node, it has 2 attributes:
 * - type_t data: Information that will be stored on the queue node.
 * - Queue_Node_t next: Pointer to the next node.
 */
typedef struct Queue_node_struct * Queue_Node_t;

/* Structure the represents a queue, it has 4 attributes:
 * - Queue_Node_t first: Pointer to queue's first entry.
 * - Queue_Node_t last: Pointer to queue´s last entry.
 * - size_t size: Current queue's size.
 * - datatype_T datatype: Enum that represents the datatype of the entries
 *                        stored on the queue.
 */
typedef struct Queue_struct * Queue_t;

/* FUNCTION:
 * queue_create
 *
 * DESCRIPTION:
 * Function used to initialize a queue. Returned queue pointer will have a size
 * of 0 and it's first and last attributes will be equal to NULL.
 *
 * PARAMETERS:
 * datatype_t - Indicates the data type that will be stored on the queue.
 *
 * RETURNS:
 * Queue_t - Pointer to the recently created queue structure.
 */
Queue_t queue_create(datatype_t);

/* FUNCTION:
 * queue_offer
 *
 * DESCRIPTION:
 * Adds a new entry to the queue. This new entry will be added at the start of
 * queue or next to the last existing element, depending on the queue's size at
 * the momento of calling this function.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure which we want to add an entry.
 * datatype_t - Indicates the data type that will be stored on the queue.
 *
 * RETURNS:
 * Nothing
 */
void queue_offer(Queue_t, type_t);

/* FUNCTION:
 * queue_peek
 *
 * DESCRIPTION:
 * Returns data of queues's first element. This function DOES NOT revome the
 * first element.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure from which we want to obtain the first
 *           element.
 *
 * RETURNS:
 * type_t - Data stored at queue's first element.
 */
type_t queue_peek(Queue_t);

/* FUNCTION:
 * queue_poll
 *
 * DESCRIPTION:
 * Removes queue's first element and returns it's data stored.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure from which we want to obtain the first
 *           element.
 *
 * RETURNS:
 * type_t - Data stored at queue's first element.
 */
type_t queue_poll(Queue_t);

/* FUNCTION:
 * queue_size
 *
 * DESCRIPTION:
 * Returns current size of the queue.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure from which we want to obtain the size.
 *
 * RETURNS:
 * size_t - Current size of the queue.
 */
size_t queue_size(Queue_t);

/* FUNCTION:
 * queue_is_empty
 *
 * DESCRIPTION:
 * Tells if queue is empty or not.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure from which we want to know if it is
 *           empty.
 *
 * RETURNS:
 * bool_t - TRUE/FALSE depending if queue's empty or not.
 */
bool_t queue_is_empty(Queue_t);

/* FUNCTION:
 * queue_destroy
 *
 * DESCRIPTION:
 * Frees the memory used by a queue structure.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure to destroy. 
 *
 * RETURNS:
 * Nothing
 */
void queue_destroy(Queue_t);

/* FUNCTION:
 * queue_print
 *
 * DESCRIPTION:
 * Prints all the queue's entries.
 *
 * PARAMETERS:
 * Queue_t - Pointer to queue structure to print. 
 *
 * RETURNS:
 * Nothing
 */
void queue_print(Queue_t);

#endif /* QUEUE_H_ */
