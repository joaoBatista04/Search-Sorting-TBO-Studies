#include <stdio.h>
#include "list.h"
#include "josephus.h"

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    m -= 1;
    int index = 0;

    List *list = list_init();

    josephus_init(n, list);

    josephus_leader(m, index, list);

    // josephus_leader_faster(n, m + 1);

    list_free(list);

    return 0;
}