#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct node Node;

struct node
{
    struct node *next;
    struct node *prev;
    int value;
};

struct list
{
    Node *head;
    Node *tail;
    int size;
};

List *list_init()
{
    List *list = (List *)malloc(sizeof(list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

List *list_push(List *list, int index)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->value = index;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        list->tail->next = new_node;
        new_node->prev = list->tail;
    }

    list->tail = new_node;
    list->size++;

    return list;
}

void list_pop(List *list, int index)
{
    Node *p = list->head;

    for (int i = 0; i < index; i++)
    {
        if (p->next == NULL)
            p = list->head;
        else
            p = p->next;
    }

    if (p == list->head && p->prev == NULL)
    {
        list->head = p->next;
        p->next->prev = NULL;
        list->size--;
        free(p);
    }

    else if (p->next == NULL)
    {
        list->tail = p->prev;
        p->prev->next = NULL;
        list->size--;
        free(p);
    }

    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        list->size--;
        free(p);
    }
}

void list_free(List *list)
{
    Node *p = list->head;
    Node *temp = NULL;

    while (p != NULL)
    {
        temp = p->next;
        free(p);
        p = temp;
    }

    free(list);
}

int list_get_size(List *list)
{
    return list->size;
}

int list_get(List *list)
{
    return list->head->value;
}

Node *list_get_head(List *list)
{
    return list->head;
}

Node *node_get_next(Node *node)
{
    return node->next;
}

int node_get_value(Node *node)
{
    return node->value;
}