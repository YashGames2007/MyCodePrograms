#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Dynamic Tree Implementation\Dynamic AVL Adelson-Velskii and Landis Tree Implementation\Dynamic_AVL_Adelson-Velskii_and_Landis_Tree_Structure_Implementation.c"

int main()
{
    int_AVL_Tree a;
    int_AVL_Tree_init(&a, 25);
    a.add(&a, 20);
    a.add(&a, 36);
    a.add(&a, 10);
    a.add(&a, 22);

    a.add(&a, 30);
    a.add(&a, 40);


    a.add(&a, 5);
    a.repr(&a);
    a.add(&a, 12);
    printf("\nOK");
    a.repr(&a);

    a.add(&a, 21);
    a.add(&a, 23);


    a.add(&a, 28);
    a.add(&a, 35);


    a.add(&a, 38);
    a.add(&a, 48);
    printf("\nDone");

    
    
    a.repr(&a);
    printf("\nOk");
    a.repr(&a);
    printf("\nGot");
    int si = a.height;
    int path[si + 1];
    int size = 2;
    printf("\nHeight: %d", a.height);
    size  = a.search(&a, 23, path);
    
    printf("\n{%d", path[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", path[i]);
    }
    printf("}.\n");
    printf("\nRepr:");
    a.repr(&a);

    a.delete(&a);
    printf("\nRepr:");
    a.repr(&a);
    printf("\nDone");
    
    return 0;
}