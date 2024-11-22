#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST *bst_create();
BST *bst_put(BST *bst, int key);
void bst_destroy(BST *bst);

int bst_calculate_height(BST *root);
void print_node(BST *n);

void rec_preorder(BST *t, void (*visit)(BST *));
void rec_inorder(BST *t, void (*visit)(BST *));
void rec_postorder(BST *t, void (*visit)(BST *));

void preorder_iterative(BST *t);
void inorder_iterative(BST *t);
void postorder_iterative(BST *t);

void levelorder_iterative(BST *t);

#endif