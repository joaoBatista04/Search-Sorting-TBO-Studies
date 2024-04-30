#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char path[1000] = "./out";
    strcat(path, argv[1]);
    strcat(path, ".txt");

    FILE *fp = fopen(path, "w");

    if (!fp)
    {
        exit(1);
    }

    srand(time(NULL));
    int size = atoi(argv[1]);

    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%d %d\n", rand() % size, rand() % size);
    }
}