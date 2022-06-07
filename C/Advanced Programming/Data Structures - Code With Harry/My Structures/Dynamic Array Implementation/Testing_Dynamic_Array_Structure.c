#include <stdio.h>
#include <string.h>
#include "Dynamic_Array_Structure.c"


int main()
{
    int_Array a;
    init(&a);
    a.append(&a, 6);
    a.append(&a, 5);
    a.append(&a, 4);
    a.append(&a, 3);
    a.append(&a, 2);
    a.append(&a, 1);
    a.repr(&a);
    printf("\nAfter Removal");
    a.remove(&a, 3);
    a.repr(&a);
    printf("\nAfter Popping");
    a.pop(&a, 40);
    a.repr(&a);
    printf("\nElement Found At Index %d In The Array.", a.search(&a, 3));
    printf("\nSort Type Of The Array: %d", a.__Sort_Type__);
    // getchar();
    // int x = 100;
    // for (int i = 0 - x; i <= x; i++)
    // {
    //     a.append(&a, i);
    //     printf("\rThe Element %d Is Added To The Array.", i);
    // }
    a.repr(&a);
    a.delete(&a);
    a.repr(&a);
    a.append(&a, 1);
    a.insert(&a, 1, 1);
    a.pop(&a, 1);
    a.remove(&a, 1);
    a.search(&a, 1);
    a.delete(&a);
    printf("\nDone!!!");
    return 0;
}