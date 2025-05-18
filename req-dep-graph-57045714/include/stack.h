#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    char *filename;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *head;
} Stack;

Stack* create_stack();
int is_stack_empty(Stack *stack);
void push(Stack *stack, const char *filename);
char* pop(Stack *stack);
void free_stack(Stack *stack);

#endif