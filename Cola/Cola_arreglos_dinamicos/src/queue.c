#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

Queue queue_create(int len) {
    Queue q;
    q.data = (Data *)malloc(len * sizeof(Data)); // Asignar memoria dinámica
    if (q.data == NULL) {
       
        q.len = 0;
        q.head = -1;
        q.tail = -1;
    } else {
        q.len = len;
        q.head = 0;
        q.tail = 0;
    }
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if ((q->tail + 1) % q->len == q->head) {
        return; 
    }
    q->data[q->tail] = d;
    q->tail = (q->tail + 1) % q->len;
}

Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        return -1; 
    }
    Data front = q->data[q->head];
    q->head = (q->head + 1) % q->len;
    return front;
}

bool queue_is_empty(Queue* q) {
    return q->head == q->tail;
}

Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        return -1; 
    }
    return q->data[q->head];
}

void queue_empty(Queue* q) {
    q->head = 0;
    q->tail = 0;
}

void queue_delete(Queue* q) {
    free(q->data); // Liberar la memoria dinámica
    q->data = NULL; 
    q->head = -1;
    q->tail = -1;
    q->len = 0;
}
