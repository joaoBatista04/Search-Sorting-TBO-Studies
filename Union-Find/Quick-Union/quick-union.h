#include <stdbool.h>

int *UF_init(int size);
void UF_union(int p, int q, int size, int *id);
int UF_find(int p, int *id);
bool UF_connected(int p, int q, int *id);