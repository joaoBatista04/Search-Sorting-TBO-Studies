#include <stdio.h>
#include <stdlib.h>
#include "quick-union.h"

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
    int i = UF_find(p, id);
    int j = UF_find(p, id);

    id[i] = j;
}

int UF_find(int i, int *id)
{
    while (i != id[i])
    {
        i = id[i];
    }

    return i;
}

bool UF_connected(int p, int q, int *id)
{
    return UF_find(p, id) == UF_find(q, id);
}