#include <stdlib.h>
#include <stdio.h>
#include "../interfaces/item.h"

void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i < hi; i++)
    {
        int index_min = i;

        for (int j = i + 1; j < hi; j++)
        {
            if (less(a[j], a[index_min]))
            {
                index_min = j;
            }
        }

        exch(a[i], a[index_min]);
    }
}