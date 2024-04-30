#include <stdio.h>
#include <stdlib.h>
#include "weightedQU.h"

int main(int argc, char *argv[])
{
    int p, q, N;
    scanf("%d\n", &N);

    int *id = UF_init(N);
    int *size = UF_init_sz(N);

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (!UF_connected(p, q, id))
        {
            UF_union(p, q, N, id, size);
            // printf("%d %d\n", p, q);
        }
    }
}
