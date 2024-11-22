#ifndef STACK_H
#define STACK_H

#include "bst.h"
#include <stdbool.h>

typedef struct stack Stack;

Stack *stack_create();
Stack *stack_push(Stack *stack, BST *node);
Stack *stack_pop(Stack *stack);
BST *stack_top(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_destroy(Stack *stack);

#endif