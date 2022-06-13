#include <stdio.h>
#include "E:\Programming files\Code\C\Advanced Programming\Data Structures - Code With Harry\My Structures\Dynamic_Linked_List_Implementation\Circular_Linked_List_Structure\Singly_Circular_Linked_List_Structure\Dynamic_Singly_Circular_Linked_List_Structure.c"

int main()
{
    int_S_C_L_List a;
    init(&a);
    a.repr(&a);
    a.append(&a, 1);
    a.repr(&a);
    // a.append(&a, 20);
    // a.repr(&a);
    a.append(&a, 300);
    a.repr(&a);
    a.append(&a, 4000);
    a.repr(&a);
    a.append(&a, 50000);
    a.repr(&a);
    a.insert(&a, 1, 20000);
    a.repr(&a);
    a.remove(&a, 1);
    a.repr(&a);
    a.delete(&a);
    printf("\nDone!");
    return 0;
}