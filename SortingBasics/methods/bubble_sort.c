#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/item.h"

void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i < hi - 1; i++)
    {
        for (int j = lo; j < hi - 1; j++)
        {
            compexch(a[j], a[j + 1]);
        }
    }
}