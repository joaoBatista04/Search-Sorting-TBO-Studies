#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "list.h"

void print_time(clock_t start, clock_t end)
{
    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", seconds);
}

int main()
{
    srand(time(NULL));

    int N;
    scanf("%d", &N);

    BST *root = bst_create();

    for (int i = 0; i < N; i++)
    {
        int r = rand();
        root = bst_put(root, r);
    }

    int height = bst_calculate_height(root);
    printf("HEIGHT:%d\n", height);

    printf("PRE ORDER RECURSIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_rpo = clock();
    rec_preorder(root, print_node);
    clock_t end_rpo = clock();
    printf("\n");

    printf("IN ORDER RECURSIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_rio = clock();
    rec_inorder(root, print_node);
    clock_t end_rio = clock();
    printf("\n");

    printf("POST ORDER RECURSIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_rpost = clock();
    rec_postorder(root, print_node);
    clock_t end_rpost = clock();
    printf("\n");

    printf("PRE ORDER ITERATIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_ipo = clock();
    preorder_iterative(root);
    clock_t end_ipo = clock();
    printf("\n");

    printf("IN ORDER ITERATIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_iio = clock();
    inorder_iterative(root);
    clock_t end_iio = clock();
    printf("\n");

    printf("POST ORDER ITERATIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    clock_t start_ipost = clock();
    postorder_iterative(root);
    clock_t end_ipost = clock();
    printf("\n");

    printf("\nTIME TABLE:\n");

    printf("PRE ORDER RECURSIVE: ");
    print_time(start_rpo, end_rpo);

    printf("IN ORDER RECURSIVE: ");
    print_time(start_rio, end_rio);

    printf("POST ORDER RECURSIVE: ");
    print_time(start_rpost, end_rpost);

    printf("PRE ORDER ITERATIVE: ");
    print_time(start_ipo, end_ipo);

    printf("IN ORDER ITERATIVE: ");
    print_time(start_iio, end_iio);

    printf("POST ORDER ITERATIVE: ");
    print_time(start_ipost, end_ipost);

    printf("\nLEVEL ORDER ITERATIVE: (ENABLE PRINT BY REMOVING COMMENTS IN BST.C)");
    levelorder_iterative(root);
    printf("\n");

    bst_destroy(root);

    return 0;
}