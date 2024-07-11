#include <stdio.h>
#include <stdlib.h>

int binary_search(int *v, int sz, int key)
{
    int lo = 0, hi = sz - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (key < v[mid])
            hi = mid - 1;
        else if (key > v[mid])
            lo = mid + 1;
        else
            return mid;
    }

    return -1;
}