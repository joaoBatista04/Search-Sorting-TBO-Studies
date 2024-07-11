#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B)  {Item t = key(A); key(A) = key(B); key(B) = t;}

void selection_sort(Item *a, int lo, int hi);

#endif