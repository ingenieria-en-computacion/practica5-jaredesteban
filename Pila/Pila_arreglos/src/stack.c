#include "stack.h"
#include <stdio.h>

Stack stack_create() {
    Stack s;
    s.top = -1;
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s->top < TAM - 1) {
        s->data[++(s->top)] = d;
    } else {
        printf("Error: La pila está llena.\n");
    }
}

Data stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
    return s->data[(s->top)--];
}

bool stack_is_empty(Stack* s) {
    return s->top == -1;
}

void stack_empty(Stack* s) {
    s->top = -1;
}

void stack_print(Stack *s) {
    if (stack_is_empty(s)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Elementos de la pila (de arriba hacia abajo):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}