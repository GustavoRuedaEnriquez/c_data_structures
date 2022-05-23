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
    
    /* Adding elements */
    printf("Adding 7 elements.\n");
    float element_1 = 323.55;
    float element_2 = 103.52;
    float element_3 = 212.44;
    float element_4 = 484.73;
    float element_5 = 356.32;
    float element_6 = 214.63;
    float element_7 = 467.43;
    queue_offer(queue_1, &element_1);
    queue_offer(queue_1, &element_2);
    queue_offer(queue_1, &element_3);
    queue_offer(queue_1, &element_4);
    queue_offer(queue_1, &element_5);
    queue_offer(queue_1, &element_6);
    queue_offer(queue_1, &element_7);
    printf("Elements successfully added.\n");

    int size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);


    /* Peeking on a element */
    type_t first = queue_peek(queue_1);
    printf("Peeking queue's first element: %.2f\n", *(float *) first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);

    /* Polling one element */
    first = queue_poll(queue_1);
    printf("Polling queue's first element: %.2f\n", *(float *) first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);

    /* Polling one element */
    first = queue_poll(queue_1);
    printf("Polling queue's first element: %.2f\n", *(float *) first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);

    /* Polling one element */
    first = queue_poll(queue_1);
    printf("Polling queue's first element: %.2f\n", *(float *) first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);

    /* Polling one element */
    first = queue_poll(queue_1);
    printf("Polling queue's first element: %.2f\n", *(float *) first);
    size = queue_size(queue_1);
    printf("Queue's size: %d\n\n", size);

    return 0;
}
