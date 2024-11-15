#include <stdio.h>
#include "sieve.h"

int main()
{
    int limite;
    scanf("%d", &limite);

    Sieve *sieve = sieve_initialize(limite);

    sieve_mark_list(sieve);
    // sieve_print_primes(sieve);

    sieve_free(sieve);

    return 0;
}