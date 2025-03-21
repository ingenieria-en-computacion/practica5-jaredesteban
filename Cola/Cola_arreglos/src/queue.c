#include "queue.h"
#include <stdlib.h>

Queue queue_create() {
    Queue q;
    q.head = 0;
    q.tail = 0;
    q.len = 0;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q->len < TAM) {
        q->datos[q->tail] = d;
        q->tail = (q->tail + 1) % TAM;
        q->len++;
    } else {
       
    }
}

Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
       
        return -1; 
    }
    Data front = q->datos[q->head];
    q->head = (q->head + 1) % TAM;
    q->len--;
    return front;
}

bool queue_is_empty(Queue* q) {
    return q->len == 0;
}

Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        
        return -1;
    }
    return q->datos[q->head];
}

void queue_empty(Queue* q) {
    q->head = 0;
    q->tail = 0;
    q->len = 0;
}

void queue_delete(Queue* q) {
    queue_empty(q);
    
}

