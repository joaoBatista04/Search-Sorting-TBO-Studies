#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct Node
{
    struct Node *next;
    struct Node *previous;
    int key;
} Node;

Node *node_create(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->next = NULL;
    n->previous = NULL;
    n->key = key;

    return n;
}

void node_free(Node *n)
{
    if (n)
    {
        free(n);
    }
}

struct list
{
    Node *head;
    Node *tail;
    int size;
};

List *list_create()
{
    List *list = (List *)malloc(sizeof(List));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

List *list_push_back(List *list, int n)
{
    Node *new = node_create(n);

    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }

    else if (list->size == 1)
    {
        new->previous = list->head;
        list->head->next = new;
        list->tail = new;
    }

    else
    {
        new->previous = list->tail;
        list->tail->next = new;
        list->tail = new;
    }

    list->size++;

    return list;
}

List *list_push_front(List *list, int n)
{
    Node *new = node_create(n);

    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }

    else
    {
        list->head->previous = new;
        new->next = list->head;
        list->head = new;
    }

    list->size++;

    return list;
}

List *list_pop_front(List *list)
{
    if (list->size == 0)
    {
        return NULL;
    }

    else if (list->size == 1)
    {
        node_free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }

    else
    {
        Node *node_to_remove = list->head;
        list->head = list->head->next;
        list->head->previous = NULL;
        node_free(node_to_remove);
    }

    list->size--;

    return list;
}

List *list_pop_back(List *list)
{
    if (list->size == 0)
    {
        return NULL;
    }

    else if (list->size == 1)
    {
        node_free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }

    else
    {
        Node *node_to_remove = list->tail;
        list->tail = list->tail->previous;
        list->tail->next = NULL;
        node_free(node_to_remove);
    }

    list->size--;

    return list;
}

void list_print(List *list)
{
    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
}

void list_free(List *list)
{
    Node *temp = list->head;
    Node *next;

    while (temp != NULL)
    {
        next = temp->next;
        node_free(temp);
        temp = next;
    }

    free(list);
}