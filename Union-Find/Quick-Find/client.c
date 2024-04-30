#include <stdio.h>
#include <stdlib.h>
#include "quick-find.h"

int main(int argc, char *argv[])
{
    int p, q, N;
    scanf("%d\n", &N);

    int *id = UF_init(N);

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (!UF_connected(p, q, id))
        {
            UF_union(p, q, N, id);
            // printf("%d %d\n", p, q);
        }
    }
}
