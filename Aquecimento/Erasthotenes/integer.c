#include <stdio.h>
#include <stdlib.h>
#include "sieve.h"

struct Sieve
{
    int *listNumbers;
    int N;
};

void SetBit(int *bits, int k);
int TestBit(int *bits, int k);

Sieve *sieve_initialize(int N)
{
    Sieve *sieve = (Sieve *)malloc(sizeof(Sieve));
    sieve->listNumbers = (int *)malloc((N + 1) * sizeof(int));

    for (int i = 0; i < N; i++)
    {
        sieve->listNumbers[i] = 0;
    }

    sieve->N = N;

    return sieve;
}

void sieve_mark_list(Sieve *sieve)
{
    for (int i = 2; i <= sieve->N; i++)
    {
        if (sieve->listNumbers[i] != 1)
        {
            for (int j = i * i; j <= sieve->N; j += i)
            {
                if (j > 0)
                {
                    sieve->listNumbers[j] = 1;
                }
            }
        }
    }
}

void sieve_print_primes(Sieve *sieve)
{
    for (int i = 2; i <= sieve->N; i++)
    {
        if (sieve->listNumbers[i] == 0)
        {
            printf("%d ", i);
        }
    }
}

void sieve_free(Sieve *sieve)
{
    free(sieve->listNumbers);
    free(sieve);
}

int TestBit(int *bits, int k)
{
    return ((bits[k / 32] & (1 << (k % 32))) != 0);
}

void SetBit(int *bits, int k)
{
    bits[k / 32] |= 1 << (k % 32);
}