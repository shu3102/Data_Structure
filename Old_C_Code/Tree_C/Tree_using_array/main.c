#include <stdio.h>
#include <stdlib.h>
#include "arr.h"

int main() {

    ARR t;
    init(&t, 10);
    insert(&t, 25);
    insert(&t, 20);
    insert(&t, 22);
    insert(&t, 10);
    insert(&t, 25);
    insert(&t, 36);
    insert(&t, 30);
    insert(&t, 40);
    printf("%d number of nodes \n", count_node(t));
    //printf("%d %d ", t.A[0], t.A[2]);
    traverse(t);

    return 0;
}
