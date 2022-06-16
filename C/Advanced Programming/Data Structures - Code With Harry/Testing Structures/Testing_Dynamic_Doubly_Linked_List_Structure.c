#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Custom_Headers.c"
#include Integer_Doubly_Linked_List

int main()
{
    int_D_D_L_List a;
    int_D_D_L_List_init(&a);
    a.repr(&a);
    a.append(&a, 1);
    // a.repr(&a);
    a.append(&a, 2);
    a.repr(&a);
    a.append(&a, 3);
    a.repr(&a);
    a.append(&a, 4);
    a.repr(&a);
    a.append(&a, 5);
    a.repr(&a);
    a.insert(&a, 2, 200);
    a.repr(&a);
    a.remove(&a, 5);
    a.repr(&a);
    a.delete(&a);
    a.repr(&a);
    printf("\nDone");
    return 0;
}