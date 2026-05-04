#include "../include/circular_queue.h"

int main(void) {
    CircularQueue circular_queue;

    create_cqueue(3, &circular_queue);
    cqueue_enqueue(&circular_queue, 10);
    cqueue_enqueue(&circular_queue, 15);
    cqueue_enqueue(&circular_queue, 20);
    display_cqueue(&circular_queue);


    cqueue_dequeue(&circular_queue);
    display_cqueue(&circular_queue);




    destroy_cqueue(&circular_queue);
    return 0;
}
