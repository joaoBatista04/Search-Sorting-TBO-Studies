#include <stdio.h>
#include "insert_sort.h"

void selection_sort(Item *a, int lo, int hi)
{
    for (int i = lo; i <= hi; i++)
    {
        for (int j = i; j < lo; j--)
        {
            compexch(a[j - 1], a[j]);
        }
    }
}