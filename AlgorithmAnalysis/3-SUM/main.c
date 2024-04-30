#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "3sum.h"

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int *a = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    clock_t start, stop;
    start = clock();
    int c = count(a, N);
    stop = clock();
    double time_taken = ((double)stop - start) / CLOCKS_PER_SEC;

    printf("%d\n", c);
    printf("Elapsed time: %.3f\n", time_taken);
    free(a);
}
