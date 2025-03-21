#include "node.h"
#include <stdlib.h>
#include <stdio.h>

Node *new_node(Data d) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        return NULL;
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