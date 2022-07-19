#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Custom_Headers.c"

#include Integer_Queue

int main()
{
    int_Queue a;
    int_Queue_init(&a);
    a.repr(&a);
    a.inQueue(&a, 1);
    a.repr(&a);
    a.inQueue(&a, 2);
    a.repr(&a);
    a.inQueue(&a, 3);
    a.repr(&a);
    a.inQueue(&a, 4);
    a.repr(&a);
    // a.delete(&a);
    int num = 5;
    printf("\nIndex of %d in Queue is %d.", num, a.peek(&a, num));
    a.deQueue(&a);
    a.repr(&a);
    a.deQueue(&a);
    a.repr(&a);
    a.deQueue(&a);
    a.repr(&a);
    a.deQueue(&a);
    a.repr(&a);
    printf("\nDone");
    return 0;
}