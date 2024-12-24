/*
Coded by Gustavo Adolfo Rueda Enríquez
May 19th 2022
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue_node_struct {
  type_t data;
  struct Queue_node_struct* next;
};

struct Queue_struct {
  Queue_Node_t first, last;
  size_t size;
  datatype_t datatype;
};


Queue_t queue_create(datatype_t datatype) {
  // Allocate memory for a new queue struct.
  Queue_t q = (Queue_t) malloc(sizeof(struct Queue_struct));
  memset(q, 0, sizeof(struct Queue_struct));

  // Fill queue's attributes
  q->datatype = datatype;
  q->size = 0;
  q->first = NULL;
  q->last = NULL;
  return q;
}


void queue_offer(Queue_t q, type_t data) {
  // Allocate memory for a new node.
  Queue_Node_t new_node = (Queue_Node_t) malloc(sizeof(struct Queue_node_struct));
  memset(new_node, 0, sizeof(struct Queue_node_struct));

  // Allocate memory for the data the new node will store.
  new_node->data = malloc(GET_DATA_SIZE(q->datatype, data));
  memset(new_node->data, 0, GET_DATA_SIZE(q->datatype, data));
  memcpy(new_node->data, data, GET_COPY_DATA_SIZE(q->datatype, data));
  new_node->next = NULL;

  // Link the new noe on the correct place.
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


type_t queue_peek(Queue_t q) {
  // If size == 0, return NULL.
  if(q->size != 0) {
    return q->first->data;
  }
  return NULL;
}


type_t queue_poll(Queue_t q) {
  // If queue is empty, return NULL.
  if (q->size == 0)
    return NULL;
  
  // Set new first element.
  Queue_Node_t temp = q->first;
  q->first = q->first->next;

  // Return data of node to be deleted.
  type_t data = temp->data;

  q->size--;
  free(temp);
  return data;
}


size_t queue_size(Queue_t q) {
  return q->size;
}


bool_t queue_is_empty(Queue_t q) {
  if( q->size == 0 )
    return TRUE;
  else
    return FALSE;
}


void queue_destroy(Queue_t q) {
  Queue_Node_t temp;

  // Free each of queue's nodes.
  while (q->first != NULL) {
    temp = q->first->next;
    free(q->first);
    q->first = temp;
  }

  // Finally, free the memory of the queue structure.
  free(q);
  return;
}


void queue_print(Queue_t q) {
  if (q->size == 0) {
    printf("The queue is empty\n");
  }
  else {
      Queue_Node_t temp = q->first;
      printf("Queue's size: %d\n", q->size);
      printf("Front:");
      while (temp != NULL) {

        if (q->datatype == DATATYPE_UINT)
          printf("\t%u", VOID_PTR_2_UINT(temp->data));
        else if (q->datatype == DATATYPE_INT)
          printf("\t%d", VOID_PTR_2_INT(temp->data));
        else if (q->datatype == DATATYPE_ULONG)
          printf("\t%lu", VOID_PTR_2_ULONG(temp->data));
        else if (q->datatype == DATATYPE_LONG)
          printf("\t%ld", VOID_PTR_2_LONG(temp->data));
        else if (q->datatype == DATATYPE_FLOAT)
          printf("\t%.6f", VOID_PTR_2_FLOAT(temp->data));
        else if (q->datatype == DATATYPE_DOUBLE)
          printf("\t%.6f", VOID_PTR_2_DOUBLE(temp->data));
        else if (q->datatype == DATATYPE_STRING)
          printf("\t\t%s", temp->data);

        temp = temp->next;
      }
      printf("\n");
  }
}
