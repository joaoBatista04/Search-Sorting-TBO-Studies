#include <stdio.h>
#include <stdlib.h>
#include "3sum.h"

int count(int *a, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (a[i] + a[j] == 0)
                count++;
    return count;
}
