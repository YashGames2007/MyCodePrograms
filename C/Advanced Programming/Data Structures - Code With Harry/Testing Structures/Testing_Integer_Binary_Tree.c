#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Dynamic Tree Implementation\Dynamic Binary Tree Implementation\Dynamic_Integer_Bynary_Tree_Structure_Implementation.c"
#include <stdlib.h>


int main()
{
    int_Binary_Tree a;
    int_Binary_Tree_init(&a, 25);
    int index[5];
    index[0] = 0;

    a.add(&a, NULL, 0, 20);
    a.add(&a, NULL, 0, 36);
    a.add(&a, index, 1, 10);
    a.add(&a, index, 1, 22);
    index[0] = 1;
    a.add(&a, index, 1, 30);
    a.add(&a, index, 1, 40);
    index[0] = 0;
    index[1] = 0;
    a.add(&a, index, 2, 5);
    a.add(&a, index, 2, 12);
    index[1] = 1;
    a.add(&a, index, 2, 21);
    a.add(&a, index, 2, 23);
    index[0] = 1;
    index[1] = 0;
    a.add(&a, index, 2, 28);
    a.add(&a, index, 2, 35);
    index[1] = 1;
    index[1] = 1;
    a.add(&a, index, 2, 38);
    a.add(&a, index, 2, 48);
    // a.add(&a, index, 1, 12);
    // a.add(&a, index, 1, 30);
    // a.add(&a, index, 1, 40);
    // index[0] = 0;
    // index[1] = 1;
    // a.add(&a, index, 2, 100);
    printf("\nDone");

    
    
    a.repr(&a);
    // a.remove(&a, 10);
    a.repr(&a);
    printf("\nGot");
    printf("CheckPoint: %d", a.is_BST(&a));
    int path[a.height];
    int size  = a.search(&a, 100, path);
    
    printf("\n{%d", path[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", path[i]);
    }
    printf("}.\n");

    a.delete(&a);
    a.repr(&a);
    printf("\nDone");
    return 0;
}