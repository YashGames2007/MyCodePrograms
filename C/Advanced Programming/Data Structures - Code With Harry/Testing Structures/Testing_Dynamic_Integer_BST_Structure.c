#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Dynamic Tree Implementation\Dynamic Binary Search Tree Implementation\Dynamic_Integer_Binary_Search_Tree_Structure_Implementation.c"
#include <stdlib.h>
 


int main()
{
    int_B_S_Tree a;
    int_B_S_Tree_init(&a, 25);
    int index[5];
    index[0] = 0;

    a.add(&a, 20);
    a.add(&a, 36);
    a.add(&a, 10);
    a.add(&a, 22);

    a.add(&a, 30);
    a.add(&a, 40);


    a.add(&a, 5);
    a.add(&a, 12);

    a.add(&a, 21);
    a.add(&a, 23);


    a.add(&a, 28);
    a.add(&a, 35);


    a.add(&a, 38);
    a.add(&a, 48);
    // a.add(&a, index, 1, 12);
    // a.add(&a, index, 1, 30);
    // a.add(&a, index, 1, 40);
    // index[0] = 0;
    // index[1] = 1;
    // a.add(&a, index, 2, 100);
    printf("\nDone");

    
    
    a.repr(&a);
    a.remove(&a, 23);
    a.repr(&a);
    printf("\nGot");
    int path[a.height];
    int size  = a.search(&a, 23, path);
    
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