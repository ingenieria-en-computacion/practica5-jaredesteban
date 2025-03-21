#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack stack_create(int len) {
    Stack s;
    s.data = (Data *)malloc(len * sizeof(Data));
    if (s.data == NULL) {
        s.top = -1;
    } else {
        s.top = -1;
    }
    return s;
}

void stack_push(Stack* s, Data d) {
    if (s == NULL || s->data == NULL) return;
    s->data[++(s->top)] = d;
}

Data stack_pop(Stack* s) {
    if (stack_is_empty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

bool stack_is_empty(Stack* s) {
    if (s == NULL) return true;
    return s->top == -1;
}

void stack_empty(Stack* s) {
    if (s == NULL) return;
    s->top = -1;
}

void stack_delete(Stack *s) {
    if (s == NULL || s->data == NULL) return;
    free(s->data);
    s->data = NULL;
    s->top = -1;
}

void stack_print(Stack *s) {
    if (s == NULL || s->data == NULL) {
        printf("Pila inválida o no inicializada.\n");
        return;
    }
    if (stack_is_empty(s)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Elementos de la pila (de arriba hacia abajo):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}