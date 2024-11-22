#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "stack.h"

struct stack
{
    BST **vector;
    int size;
};

Stack *stack_create()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->vector = (BST **)malloc(10000000 * sizeof(BST *));
    stack->size = 0;

    return stack;
}

Stack *stack_push(Stack *stack, BST *node)
{
    stack->vector[stack->size] = node;
    stack->size++;
    return stack;
}

Stack *stack_pop(Stack *stack)
{
    stack->vector[stack->size] = NULL;
    stack->size--;
    return stack;
}

BST *stack_top(Stack *stack)
{
    BST *node = stack->vector[stack->size - 1];
    return node;
}

bool stack_isEmpty(Stack *stack)
{
    if (stack->size == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void stack_destroy(Stack *stack)
{
    free(stack->vector);
    free(stack);
}