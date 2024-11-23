#include <stdio.h>
#include <stdlib.h>
#include "../interfaces/item.h"

void sort(Item *a, int lo, int hi)
{
    for (int i = lo; i <= hi / 2; i++)
    {
        for (int j = lo; j < hi - i - 1; j++)
        {
            compexch(a[j], a[j + 1]);
        }

        for (int j = hi - i - 2; j > i; j--)
        {
            compexch(a[j], a[j - 1]);
        }
    }
}