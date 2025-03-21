#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(Data d) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL; // Fallo en la asignación de memoria
    }
    n->data = d;
    n->next = NULL;
    return n;
}

void delete_node(Node* n) {
    if (n == NULL || n->next != NULL) {
        return; 
    }
    free(n);
}

void print_node(Node* n) {
    if (n == NULL) {
        printf("Nodo inválido.\n");
    } else {
        printf("Nodo: data=%d, next=%p\n", n->data, (void*)n->next);
    }
}