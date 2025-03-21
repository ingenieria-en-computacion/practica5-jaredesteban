#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue* queue_create() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (q == NULL) {
        return NULL; // Fallo en la asignación de memoria
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    if (q == NULL) return; // Validar cola
    Node *n = new_node(d);
    if (n == NULL) return; // Fallo en la creación del nodo

    if (queue_is_empty(q)) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
}

Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return -1; // Valor de error
    }
    Node *temp = q->head;
    Data data = temp->data;
    q->head = q->head->next;

    if (q->head == NULL) { // Si la cola queda vacía
        q->tail = NULL;
    }

    delete_node(temp);
    return data;
}

bool queue_is_empty(Queue* q) {
    return q->head == NULL;
}

Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Error: La cola está vacía.\n");
        return -1; // Valor de error
    }
    return q->head->data;
}

void queue_empty(Queue* q) {
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    if (q == NULL) return;
    queue_empty(q);
    free(q);
}
