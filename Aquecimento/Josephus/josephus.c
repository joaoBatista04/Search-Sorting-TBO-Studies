#include <stdio.h>
#include <stdlib.h>
#include "josephus.h"

void josephus_init(int Nsize, List *list)
{
    for (int i = 0; i < Nsize; i++)
    {
        list_push(list, i + 1);
    }
}

void josephus_leader(int k, int index, List *list)
{
    int size = list_get_size(list);

    if (size == 1)
    {
        Node *head = list_get_head(list);
        printf("The leader is: %d\n", node_get_value(head));
        return;
    }

    index = ((index + k) % size);

    list_pop(list, index);

    josephus_leader(k, index, list);
}

void josephus_leader_faster(int Nsize, int Msize)
{
    int i = 1;
    int leader = 0;

    while (i <= Nsize)
    {
        leader = (leader + Msize) % i;
        i++;
    }

    printf("(Faster) The leader is: %d\n", leader + 1);
}