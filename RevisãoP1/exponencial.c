#include <stdio.h>
#include <string.h>

//Exemplo de algoritmo com complexidade O(n2^n)
int main(void)
{
    char x[1000] = "TesteA";
    int length = strlen(x);

    for (int i = 0; i < length; i++)
    {
        strcat(x, x); //x -> n
                      //x -> 2n
                      //x -> 4n
                      //x -> 6n
    }
}