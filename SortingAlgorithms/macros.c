/*//Inteiros
typedef int Item
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t}
#define compexch (if(less(A, B)) exch(A, B))

//Strings
typedef char* Item
#define key(A) (A)
#define less(A, B) (strcmp(A, B) < 0)

//Structs
typedef struct{
    int src, tgt, dist;
} Edge;
#define key(A) (A.dist)
#define less(A, B) (key(A) < key(B))*/