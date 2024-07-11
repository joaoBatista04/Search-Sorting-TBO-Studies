#ifndef INSERT_SORT_H
#define INSERT_SORT_H

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    }
#define compexch    \
    if (less(A, B)) \
    exch(A, B)

void insert_sort(Item *a, int lo, int hi);

#endif