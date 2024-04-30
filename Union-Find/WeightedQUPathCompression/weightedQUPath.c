#include <stdio.h>
#include <stdlib.h>
#include "weightedQUPath.h"

int *UF_init(int size)
{
    int *id = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        id[i] = i;
    }

    return id;
}

int *UF_init_sz(int size)
{
    int *sz = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        sz[i] = 0;
    }

    return sz;
}

void UF_union(int p, int q, int size, int *id, int *sz)
{
    int i = UF_find(p, id);
    int j = UF_find(p, id);

    if (i == j)
    {
        return;
    }

    if (sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }

    else
    {
        id[j] = id[i];
        sz[i] += sz[j];
    }
}

int UF_find(int i, int *id)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }

    return i;
}

bool UF_connected(int p, int q, int *id)
{
    return UF_find(p, id) == UF_find(q, id);
}