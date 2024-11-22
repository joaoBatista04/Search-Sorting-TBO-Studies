#ifndef QUEUE_H
#define QUEUE_H

#include "bst.h"
#include <stdbool.h>

typedef struct queue Queue;

Queue *queue_create();
void queue_enqueue(Queue *queue, BST *t);
void queue_dequeue(Queue *queue);
bool queue_isEmpty(Queue *queue);
BST *queue_front(Queue *queue);
void queue_destroy(Queue *queue);

#endif