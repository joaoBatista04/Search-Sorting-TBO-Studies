#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "stack.h"
#include "list.h"
#include "queue.h"

struct bst
{
    int key;
    BST *l, *r;
};

BST *__node_create(int key)
{
    BST *new_node = (BST *)malloc(sizeof(BST));
    new_node->key = key;
    new_node->l = NULL;
    new_node->r = NULL;
    return new_node;
}

BST *__rec_put(BST *node, int key)
{
    if (node == NULL)
    {
        return __node_create(key);
    }

    int cmp = key - node->key;

    if (cmp < 0)
    {
        node->l = __rec_put(node->l, key);
    }

    else if (cmp > 0)
    {
        node->r = __rec_put(node->r, key);
    }

    else
    {
        node->key = key;
    }

    return node;
}

void __rec_destroy(BST *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->l != NULL)
    {
        __rec_destroy(node->l);
    }

    if (node->r != NULL)
    {
        __rec_destroy(node->r);
    }

    free(node);
}

BST *bst_create()
{
    BST *root = NULL;
    return root;
}

BST *bst_put(BST *bst, int key)
{
    bst = __rec_put(bst, key);
    return bst;
}

void bst_destroy(BST *bst)
{
    __rec_destroy(bst);
}

int bst_calculate_height(BST *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = bst_calculate_height(root->l);
    int right = bst_calculate_height(root->r);

    if (left > right)
    {
        return left + 1;
    }

    else
    {
        return right + 1;
    }
}

void rec_preorder(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        visit(t);
        rec_preorder(t->l, visit);
        rec_preorder(t->r, visit);
    }
}

void rec_inorder(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        rec_inorder(t->l, visit);
        visit(t);
        rec_inorder(t->r, visit);
    }
}

void rec_postorder(BST *t, void (*visit)(BST *))
{
    if (t)
    {
        rec_postorder(t->l, visit);
        rec_postorder(t->r, visit);
        visit(t);
    }
}

void preorder_iterative(BST *t)
{
    if (t == NULL)
    {
        return;
    }

    Stack *stack = stack_create();

    BST *curr = t;

    while (!stack_isEmpty(stack) || curr != NULL)
    {
        while (curr != NULL)
        {
            // print_node(curr);

            if (curr->r)
            {
                stack_push(stack, curr->r);
            }

            curr = curr->l;
        }

        if (stack_isEmpty(stack) == 0)
        {
            curr = stack_top(stack);
            stack_pop(stack);
        }
    }

    stack_destroy(stack);
}

void inorder_iterative(BST *root)
{
    List *list = list_create();
    Stack *stack = stack_create();
    BST *curr = root;

    while (curr != NULL || stack_isEmpty(stack) == 0)
    {
        while (curr != NULL)
        {
            stack_push(stack, curr);
            curr = curr->l;
        }

        curr = stack_top(stack);
        stack_pop(stack);

        list_push_back(list, curr->key);

        curr = curr->r;
    }

    // list_print(list);

    stack_destroy(stack);
    list_free(list);
}

void postorder_iterative(BST *t)
{
    List *list = list_create();

    if (t == NULL)
    {
        return;
    }

    Stack *stack1 = stack_create();
    Stack *stack2 = stack_create();

    stack_push(stack1, t);
    BST *curr;

    while (!stack_isEmpty(stack1))
    {
        curr = stack_top(stack1);
        stack_pop(stack1);
        stack_push(stack2, curr);

        if (curr->l)
        {
            stack_push(stack1, curr->l);
        }

        if (curr->r)
        {
            stack_push(stack1, curr->r);
        }
    }

    while (!stack_isEmpty(stack2))
    {
        curr = stack_top(stack2);
        stack_pop(stack2);
        list_push_back(list, curr->key);
    }

    // list_print(list);

    list_free(list);
    stack_destroy(stack1);
    stack_destroy(stack2);
}

void levelorder_iterative(BST *t)
{
    if (t == NULL)
    {
        return;
    }

    Queue *queue = queue_create();

    queue_enqueue(queue, t);

    while (queue_isEmpty(queue) == 0)
    {
        BST *node = queue_front(queue);
        print_node(node);
        queue_dequeue(queue);

        if (node->l != NULL)
        {
            queue_enqueue(queue, node->l);
        }

        if (node->r != NULL)
        {
            queue_enqueue(queue, node->r);
        }
    }

    queue_destroy(queue);
}

void print_node(BST *n)
{
    // printf("%d ", n->key);
}