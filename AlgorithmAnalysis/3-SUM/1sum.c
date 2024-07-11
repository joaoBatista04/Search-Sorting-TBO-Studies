#include <stdio.h>
#include <stdlib.h>
#include "3sum.h"

int count(int *a, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == 0)
            count++;
    return count;
}
