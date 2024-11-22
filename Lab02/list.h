#ifndef LIST_H
#define LIST_H

#include "bst.h"

typedef struct list List;

List *list_create();
List *list_push_back(List *list, int n);
List *list_push_front(List *list, int n);
List *list_pop_front(List *list);
List *list_pop_back(List *list);
void list_print(List *list);
void list_free(List *list);

#endif