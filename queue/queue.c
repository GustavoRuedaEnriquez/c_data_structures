/*
Coded by Gustavo Adolfo Rueda Enríquez
May 19th 2022
*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Queue_node_str {
  type_t data;
  struct Queue_node_str* next;
};

struct Queue_str {
  Queue_Node_t first, last;
  int size;
  datatype_t datatype;
};


Queue_t queue_create(datatype_t datatype) {
  Queue_t q = calloc(1, sizeof(struct Queue_str));
  memset(q, 0, sizeof(struct Queue_str));
  q->datatype = datatype;
  return q;
}

void queue_destroy(Queue_t q) {
  Queue_Node_t temp;
  while (q->first != NULL) {
    temp = q->first->next;
    free(q->first);
    q->first = temp;
  }
  free(q);
}

void queue_offer(Queue_t q, type_t data) {
  Queue_Node_t new_node = calloc( 1, sizeof(struct Queue_node_str));
  memset(new_node, 0, sizeof(struct Queue_node_str));
  
  size_t data_size = GET_DATA_SIZE(q->datatype, data); 
  new_node->data = malloc(data_size);
  memset(new_node->data, 0, data_size);
  memcpy(new_node->data, data, data_size);

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
  return q->first->data;
}

type_t queue_poll(Queue_t q) {
  if (q == 0)
    return 0;
  else {
    Queue_Node_t temp = q->first;
    q->first = q->first->next;
    type_t data = temp->data;
    q->size--;
    free(temp);
    return data;
  }
}

int queue_size(Queue_t q) {
  return q->size;
}

bool_t queue_isEmpty(Queue_t q) {
  if( q == 0 )
    return TRUE;
  else
    return FALSE;
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

        if (q->datatype == UINT)
          printf("\t%u", VOID_PTR_2_UINT(temp->data));
        else if (q->datatype == INT)
          printf("\t%d", VOID_PTR_2_INT(temp->data));
        else if (q->datatype == ULONG)
          printf("\t%lu", VOID_PTR_2_ULONG(temp->data));
        else if (q->datatype == LONG)
          printf("\t%ld", VOID_PTR_2_LONG(temp->data));
        else if (q->datatype == FLOAT)
          printf("\t%.6f", VOID_PTR_2_FLOAT(temp->data));
        else if (q->datatype == DOUBLE)
          printf("\t%.6f", VOID_PTR_2_DOUBLE(temp->data));
        else if (q->datatype == STRING)
          printf("\t\t%s", temp->data);

        temp = temp->next;
      }
      printf("\n");
  }
}
