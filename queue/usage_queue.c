/*
Coded by Gustavo Adolfo Rueda Enrí?quez
May 19th 2022

Test for the queues's functions.
*/

#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    Queue_t queue_1 = queue_create();
    
    type_t element_1 = 100;
    type_t element_2 = 200;
    type_t element_3 = 300;
    type_t element_4 = 400;

    queue_offer(queue_1, element_1);
    queue_offer(queue_1, element_2);
    queue_offer(queue_1, element_3);
    queue_offer(queue_1, element_4);
    
    int size = queue_size(queue_1);
    printf("Queue's size: %d\n", size);

    type_t first = queue_peek(queue_1);
    printf("Peeking queue's first element: %d\n", first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n", size);

    first = queue_poll(queue_1);
    printf("Polling queue's first element: %d\n", first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n", size);

    first = queue_peek(queue_1);
    printf("Peeking queue's first element: %d\n", first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n", size);

    return 0;
}
