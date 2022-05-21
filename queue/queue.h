/*
Coded by Gustavo Adolfo Rueda Enríquez
May 19th 2022
*/

#ifndef QUEUE_H_
#define QUEUE_H_

typedef void * type_t;
typedef enum {FALSE, TRUE} bool_t;
typedef struct Node_str  * Node_t;
typedef struct Queue_str * Queue_t;

Queue_t queue_create();
int     queue_size(Queue_t);
bool_t  queue_isEmpty(Queue_t);
type_t  queue_peek(Queue_t);
void    queue_offer(Queue_t, type_t);
type_t  queue_poll(Queue_t);	
void    queue_destroy(Queue_t);

#endif /* QUEUE_H_ */
