/*
Coded by Gustavo Adolfo Rueda Enríquez
May 19th 2022
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Node_str {
	type_t data;
	struct Node_str* next;
};

struct Queue_str {
	Node_t first, last;
	int size;
};


Queue_t queue_create() {
	Queue_t q = calloc( 1, sizeof( struct Queue_str ) );
	return q;
}

int queue_size(Queue_t q) {
	return q->size;
}

Boolean queue_isEmpty(Queue_t q) {
	if( q == 0 )
		return TRUE;
	else
		return FALSE;
}

type_t queue_peek(Queue_t q) {
	return q->first->data;
}

void queue_offer(Queue_t q, type_t data) {
	Node_t new_node = calloc( 1, sizeof( struct Node_str ) );
	new_node->data = data;
	if (q->size == 0) {
		q->first = new_node;
		q->last = new_node;
		q->size++;
	}
    else {
		q->last->next = new_node;
		q->last = new_node;
		q->size++;
	}
}

type_t queue_poll(Queue_t q) {
	if (q == 0)
		return 0;
	else {
		Node_t temp = q->first;
		q->first = q->first->next;
		type_t data = temp->data;
		q->size--;
		free(temp);
		return data;
	}
}

void queue_destroy(Queue_t q) {
    Node_t temp;
    while (q->first != NULL) {
        temp = q->first->next;
        free(q->first);
        q->first = temp;
    }
    free(q);
}
