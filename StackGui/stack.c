#include "stack.h"

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int value) {
    if (isFull(s)) return 0;
    s->items[++(s->top)] = value;
    return 1;
}

int pop(Stack *s, int *value) {
    if (isEmpty(s)) return 0;
    *value = s->items[(s->top)--];
    return 1;
}

int peek(Stack *s, int *value) {
    if (isEmpty(s)) return 0;
    *value = s->items[s->top];
    return 1;
}