#include <stdio.h>
#include <stdlib.h>
#include "selection_sort.h"

int main(void)
{
    int v[9] = {5, 6, 1, 3, 10, 2, 2, 6, 4};

    selection_sort(v, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", v[i]);
    }

    return 0;
}