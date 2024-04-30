#ifndef SIEVE_H
#define SIEVE_H

typedef struct Sieve Sieve;

Sieve *sieve_initialize(int N);
void sieve_mark_list(Sieve *sieve);
void sieve_print_primes(Sieve *sieve);
void sieve_free(Sieve *sieve);

#endif