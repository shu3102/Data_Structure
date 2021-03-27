#include <stdio.h>
#include <stdlib.h>
#include"tree.h"

int main() {
    printf("Hello shubham!\n");
    bst L;
    init(&L);

    InsertNode(&L, 100);
    InsertNode(&L, 50);
    InsertNode(&L, 200);
    InsertNode(&L, 25);
    InsertNode(&L, 300);
    InsertNode(&L, 75);
    InsertNode(&L, 12);
    inorder(L);
    remoov(&L, 100);
    printf("\n");

    postorder(L);

    return 0;
}
