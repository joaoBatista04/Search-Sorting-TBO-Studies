#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sieve.h"

struct Sieve
{
    bool *listNumbers;
    int N;
};

void SetBit(int *bits, int k);
int TestBit(int *bits, int k);

Sieve *sieve_initialize(int N)
{
    Sieve *sieve = (Sieve *)malloc(sizeof(Sieve));
    sieve->listNumbers = (bool *)malloc(N * sizeof(bool));

    for (int i = 0; i < N; i++)
    {
        sieve->listNumbers[i] = false;
    }

    sieve->N = N;

    return sieve;
}

void sieve_mark_list(Sieve *sieve)
{
    for (int i = 2; i < sieve->N; i++)
    {
        if (sieve->listNumbers[i] != true)
        {
            for (int j = i * i; j < sieve->N; j += i)
            {
                sieve->listNumbers[j] = true;
            }
        }
    }
}

void sieve_print_primes(Sieve *sieve)
{
    for (int i = 2; i < sieve->N; i++)
    {
        if (sieve->listNumbers[i] == true)
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