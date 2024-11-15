#ifndef LISTA_H
#define LISTA_H

typedef struct node Node;
typedef struct list List;

List *list_init();

List *list_push(List *list, int index);

void list_pop(List *list, int index);

void list_free(List *list);

int list_get(List *list);

Node *list_get_head(List *list);

int list_get_size(List *list);

Node *node_get_next(Node *node);

int node_get_value(Node *node);

#endif