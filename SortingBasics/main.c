#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./interfaces/item.h"

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);

    Item *arrayItens = (Item *)malloc(N * sizeof(Item));

    for (int i = 0; i < N; i++)
    {
        int aux;
        scanf("%d", &aux);

        arrayItens[i] = aux;
    }

    clock_t start = clock();
    sort(arrayItens, 0, N);
    clock_t end = clock();

    printf("ELAPSED SORTING TIME: %lf\n\n", (((double)end - start) / CLOCKS_PER_SEC));

    for (int i = 0; i < N; i++)
    {
        printf("%d ", arrayItens[i]);
    }
    printf("\n");

    free(arrayItens);

    return 0;
}