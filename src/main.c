#include <stdio.h>

#include "../include/constants.h"
#include "../include/regular_queue.h"

int main(void) {
    Queue queue;

    create_queue(5, &queue);

    queue_enqueue(&queue, 10);
    queue_enqueue(&queue, 15);
    display_queue(&queue);
    queue_enqueue(&queue, 20);
    display_queue(&queue);
    queue_dequeue(&queue);
    display_queue(&queue);


    destroy_queue(&queue);
    return 0;
}
