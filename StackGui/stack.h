#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
int push(Stack *s, int value);
int pop(Stack *s, int *value);
int peek(Stack *s, int *value);

#endif