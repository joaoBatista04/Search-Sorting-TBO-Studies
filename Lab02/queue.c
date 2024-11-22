#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue
{
    BST **vector;
    int size;
};

Queue *queue_create()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->vector = (BST **)malloc(10000000 * sizeof(BST *));
    queue->size = 0;

    return queue;
}

void queue_enqueue(Queue *queue, BST *t)
{
    queue->vector[queue->size] = t;
    queue->size++;
}

void queue_dequeue(Queue *queue)
{
    for (int i = 1; i < queue->size; i++)
    {
        queue->vector[i - 1] = queue->vector[i];
    }

    queue->size--;
}

bool queue_isEmpty(Queue *queue)
{
    if (queue->size == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

BST *queue_front(Queue *queue)
{
    return queue->vector[0];
}

void queue_destroy(Queue *queue)
{
    free(queue->vector);
    free(queue);
}