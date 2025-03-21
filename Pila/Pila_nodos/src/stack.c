#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *stack_create() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = NULL;
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL) return;
    Node *n = new_node(d);
    if (n == NULL) return;

    n->next = s->top;
    s->top = n;
}

Data stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Error: La pila está vacía.\n");
        return -1;
    }

    Node *temp = s->top;
    Data data = temp->data;
    s->top = s->top->next;

    delete_node(temp);
    return data;
}

int stack_is_empty(Stack* s) {
    if (s == NULL) return -1;
    return s->top == NULL;
}

void stack_empty(Stack* s) {
    if (s == NULL) return;
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
}

void stack_delete(Stack *s) {
    if (s == NULL) return;
    stack_empty(s);
    free(s);
}

void stack_print(Stack *s) {
    if (s == NULL) {
        printf("Pila inválida.\n");
        return;
    }

    Node *current = s->top;
    printf("Elementos de la pila (de arriba hacia abajo):\n");
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
