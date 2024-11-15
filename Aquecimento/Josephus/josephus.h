#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "./list.h"

void josephus_init(int Nsize, List *list);
void josephus_leader(int Nsize, int Mskip, List *list);
void josephus_leader_faster(int Nsize, int Msize);

#endif