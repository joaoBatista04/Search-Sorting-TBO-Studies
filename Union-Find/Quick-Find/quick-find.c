#include <stdio.h>
#include <stdlib.h>
#include "quick-find.h"

int *UF_init(int size)
{
    int *id = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }

    return id;
}

void UF_union(int p, int q, int size, int *id)
{
    int pid = id[p];
    int qid = id[q];

    for (int i = 0; i < size; i++)
    {
        if (id[i] == pid)
        {
            id[i] = qid;
        }
    }
}

int UF_find(int p, int *id)
{
    return id[p];
}

bool UF_connected(int p, int q, int *id)
{
    return UF_find(p, id) == UF_find(q, id);
}